///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015-2018 Edouard Griffiths, F4EXB.                             //
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "aisdemod.h"

#include <QTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QThread>

#include <stdio.h>
#include <complex.h>

#include "SWGChannelSettings.h"
#include "SWGChannelReport.h"

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "device/deviceapi.h"
#include "feature/feature.h"
#include "util/ais.h"
#include "util/db.h"
#include "maincore.h"

MESSAGE_CLASS_DEFINITION(AISDemod::MsgConfigureAISDemod, Message)
MESSAGE_CLASS_DEFINITION(AISDemod::MsgMessage, Message)

const char * const AISDemod::m_channelIdURI = "rpx-100.channel.aisdemod";
const char * const AISDemod::m_channelId = "AISDemod";

AISDemod::AISDemod(DeviceAPI *deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_basebandSampleRate(0)
{
    setObjectName(m_channelId);

    m_basebandSink = new AISDemodBaseband(this);
    m_basebandSink->setMessageQueueToChannel(getInputMessageQueue());
    m_basebandSink->setChannel(this);
    m_basebandSink->moveToThread(&m_thread);

    applySettings(m_settings, true);

    m_deviceAPI->addChannelSink(this);
    m_deviceAPI->addChannelSinkAPI(this);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    connect(&m_channelMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleChannelMessages()));
}

AISDemod::~AISDemod()
{
    qDebug("AISDemod::~AISDemod");
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
    m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);

    if (m_basebandSink->isRunning()) {
        stop();
    }

    delete m_basebandSink;
}

uint32_t AISDemod::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void AISDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool firstOfBurst)
{
    (void) firstOfBurst;
    m_basebandSink->feed(begin, end);
}

void AISDemod::start()
{
    qDebug("AISDemod::start");

    m_basebandSink->reset();
    m_basebandSink->startWork();
    m_thread.start();

    DSPSignalNotification *dspMsg = new DSPSignalNotification(m_basebandSampleRate, m_centerFrequency);
    m_basebandSink->getInputMessageQueue()->push(dspMsg);

    AISDemodBaseband::MsgConfigureAISDemodBaseband *msg = AISDemodBaseband::MsgConfigureAISDemodBaseband::create(m_settings, true);
    m_basebandSink->getInputMessageQueue()->push(msg);
}

void AISDemod::stop()
{
    qDebug("AISDemod::stop");
    m_basebandSink->stopWork();
    m_thread.quit();
    m_thread.wait();
}

bool AISDemod::handleMessage(const Message& cmd)
{
    if (MsgConfigureAISDemod::match(cmd))
    {
        MsgConfigureAISDemod& cfg = (MsgConfigureAISDemod&) cmd;
        qDebug() << "AISDemod::handleMessage: MsgConfigureAISDemod";
        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else if (DSPSignalNotification::match(cmd))
    {
        DSPSignalNotification& notif = (DSPSignalNotification&) cmd;
        m_basebandSampleRate = notif.getSampleRate();
        m_centerFrequency = notif.getCenterFrequency();
        // Forward to the sink
        DSPSignalNotification* rep = new DSPSignalNotification(notif); // make a copy
        qDebug() << "AISDemod::handleMessage: DSPSignalNotification";
        m_basebandSink->getInputMessageQueue()->push(rep);

        return true;
    }
    else if (MsgMessage::match(cmd))
    {
        // Forward to GUI
        MsgMessage& report = (MsgMessage&)cmd;
        if (getMessageQueueToGUI())
        {
            MsgMessage *msg = new MsgMessage(report);
            getMessageQueueToGUI()->push(msg);
        }

        MessagePipes& messagePipes = MainCore::instance()->getMessagePipes();

        // Forward to AIS feature
        QList<MessageQueue*> *aisMessageQueues = messagePipes.getMessageQueues(this, "ais");
        if (aisMessageQueues)
        {
            QList<MessageQueue*>::iterator it = aisMessageQueues->begin();
            for (; it != aisMessageQueues->end(); ++it)
            {
                MainCore::MsgPacket *msg = MainCore::MsgPacket::create(this, report.getMessage(), report.getDateTime());
                (*it)->push(msg);
            }
        }

        // Forward via UDP
        if (m_settings.m_udpEnabled)
        {
            if (m_settings.m_udpFormat == AISDemodSettings::Binary)
            {
                m_udpSocket.writeDatagram(report.getMessage().data(), report.getMessage().size(),
                                          QHostAddress(m_settings.m_udpAddress), m_settings.m_udpPort);
            }
            else
            {
                QString nmea = AISMessage::toNMEA(report.getMessage());
                QByteArray bytes = nmea.toLatin1();
                m_udpSocket.writeDatagram(bytes.data(), bytes.size(),
                                          QHostAddress(m_settings.m_udpAddress), m_settings.m_udpPort);
            }
        }

        return true;
    }
    else if (MainCore::MsgChannelDemodQuery::match(cmd))
    {
        qDebug() << "AISDemod::handleMessage: MsgChannelDemodQuery";
        sendSampleRateToDemodAnalyzer();

        return true;
    }
    else
    {
        return false;
    }
}

ScopeVis *AISDemod::getScopeSink()
{
    return m_basebandSink->getScopeSink();
}

void AISDemod::applySettings(const AISDemodSettings& settings, bool force)
{
    qDebug() << "AISDemod::applySettings:"
            << " m_streamIndex: " << settings.m_streamIndex
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIDeviceIndex: " << settings.m_reverseAPIDeviceIndex
            << " m_reverseAPIChannelIndex: " << settings.m_reverseAPIChannelIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((settings.m_inputFrequencyOffset != m_settings.m_inputFrequencyOffset) || force) {
        reverseAPIKeys.append("inputFrequencyOffset");
    }
    if ((settings.m_rfBandwidth != m_settings.m_rfBandwidth) || force) {
        reverseAPIKeys.append("rfBandwidth");
    }
    if ((settings.m_fmDeviation != m_settings.m_fmDeviation) || force) {
        reverseAPIKeys.append("fmDeviation");
    }
    if ((settings.m_correlationThreshold != m_settings.m_correlationThreshold) || force) {
        reverseAPIKeys.append("correlationThreshold");
    }
    if ((settings.m_udpEnabled != m_settings.m_udpEnabled) || force) {
        reverseAPIKeys.append("udpEnabled");
    }
    if ((settings.m_udpAddress != m_settings.m_udpAddress) || force) {
        reverseAPIKeys.append("udpAddress");
    }
    if ((settings.m_udpPort != m_settings.m_udpPort) || force) {
        reverseAPIKeys.append("udpPort");
    }
    if ((settings.m_udpFormat != m_settings.m_udpFormat) || force) {
        reverseAPIKeys.append("udpFormat");
    }
    if (m_settings.m_streamIndex != settings.m_streamIndex)
    {
        if (m_deviceAPI->getSampleMIMO()) // change of stream is possible for MIMO devices only
        {
            m_deviceAPI->removeChannelSinkAPI(this);
            m_deviceAPI->removeChannelSink(this, m_settings.m_streamIndex);
            m_deviceAPI->addChannelSink(this, settings.m_streamIndex);
            m_deviceAPI->addChannelSinkAPI(this);
        }

        reverseAPIKeys.append("streamIndex");
    }

    AISDemodBaseband::MsgConfigureAISDemodBaseband *msg = AISDemodBaseband::MsgConfigureAISDemodBaseband::create(settings, force);
    m_basebandSink->getInputMessageQueue()->push(msg);

    if (settings.m_useReverseAPI)
    {
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIDeviceIndex != settings.m_reverseAPIDeviceIndex) ||
                (m_settings.m_reverseAPIChannelIndex != settings.m_reverseAPIChannelIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    m_settings = settings;
}

QByteArray AISDemod::serialize() const
{
    return m_settings.serialize();
}

bool AISDemod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureAISDemod *msg = MsgConfigureAISDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureAISDemod *msg = MsgConfigureAISDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void AISDemod::sendSampleRateToDemodAnalyzer()
{
    QList<MessageQueue*> *messageQueues = MainCore::instance()->getMessagePipes().getMessageQueues(this, "reportdemod");

    if (messageQueues)
    {
        QList<MessageQueue*>::iterator it = messageQueues->begin();

        for (; it != messageQueues->end(); ++it)
        {
            MainCore::MsgChannelDemodReport *msg = MainCore::MsgChannelDemodReport::create(
                this,
                AISDemodSettings::AISDEMOD_CHANNEL_SAMPLE_RATE
            );
            (*it)->push(msg);
        }
    }
}

int AISDemod::webapiSettingsGet(
        SWGrpx-100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setAisDemodSettings(new SWGrpx-100::SWGAISDemodSettings());
    response.getAisDemodSettings()->init();
    webapiFormatChannelSettings(response, m_settings);
    return 200;
}

int AISDemod::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    AISDemodSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigureAISDemod *msg = MsgConfigureAISDemod::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("AISDemod::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureAISDemod *msgToGUI = MsgConfigureAISDemod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void AISDemod::webapiUpdateChannelSettings(
        AISDemodSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getAisDemodSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("rfBandwidth")) {
        settings.m_rfBandwidth = response.getAisDemodSettings()->getRfBandwidth();
    }
    if (channelSettingsKeys.contains("fmDeviation")) {
        settings.m_fmDeviation = response.getAisDemodSettings()->getFmDeviation();
    }
    if (channelSettingsKeys.contains("correlationThreshold")) {
        settings.m_correlationThreshold = response.getAisDemodSettings()->getCorrelationThreshold();
    }
    if (channelSettingsKeys.contains("udpEnabled")) {
        settings.m_udpEnabled = response.getAisDemodSettings()->getUdpEnabled();
    }
    if (channelSettingsKeys.contains("udpAddress")) {
        settings.m_udpAddress = *response.getAisDemodSettings()->getUdpAddress();
    }
    if (channelSettingsKeys.contains("udpPort")) {
        settings.m_udpPort = response.getAisDemodSettings()->getUdpPort();
    }
    if (channelSettingsKeys.contains("udpFormat")) {
        settings.m_udpFormat = (AISDemodSettings::UDPFormat)response.getAisDemodSettings()->getUdpFormat();
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getAisDemodSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getAisDemodSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getAisDemodSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getAisDemodSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getAisDemodSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getAisDemodSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getAisDemodSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getAisDemodSettings()->getReverseApiChannelIndex();
    }
}

void AISDemod::webapiFormatChannelSettings(SWGrpx-100::SWGChannelSettings& response, const AISDemodSettings& settings)
{
    response.getAisDemodSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getAisDemodSettings()->setRfBandwidth(settings.m_rfBandwidth);
    response.getAisDemodSettings()->setFmDeviation(settings.m_fmDeviation);
    response.getAisDemodSettings()->setCorrelationThreshold(settings.m_correlationThreshold);
    response.getAisDemodSettings()->setUdpEnabled(settings.m_udpEnabled);
    response.getAisDemodSettings()->setUdpAddress(new QString(settings.m_udpAddress));
    response.getAisDemodSettings()->setUdpPort(settings.m_udpPort);
    response.getAisDemodSettings()->setUdpFormat((int)settings.m_udpFormat);

    response.getAisDemodSettings()->setRgbColor(settings.m_rgbColor);
    if (response.getAisDemodSettings()->getTitle()) {
        *response.getAisDemodSettings()->getTitle() = settings.m_title;
    } else {
        response.getAisDemodSettings()->setTitle(new QString(settings.m_title));
    }

    response.getAisDemodSettings()->setStreamIndex(settings.m_streamIndex);
    response.getAisDemodSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getAisDemodSettings()->getReverseApiAddress()) {
        *response.getAisDemodSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getAisDemodSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getAisDemodSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getAisDemodSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getAisDemodSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void AISDemod::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const AISDemodSettings& settings, bool force)
{
    SWGrpx-100::SWGChannelSettings *swgChannelSettings = new SWGrpx-100::SWGChannelSettings();
    webapiFormatChannelSettings(channelSettingsKeys, swgChannelSettings, settings, force);

    QString channelSettingsURL = QString("http://%1:%2/rpx-100/deviceset/%3/channel/%4/settings")
            .arg(settings.m_reverseAPIAddress)
            .arg(settings.m_reverseAPIPort)
            .arg(settings.m_reverseAPIDeviceIndex)
            .arg(settings.m_reverseAPIChannelIndex);
    m_networkRequest.setUrl(QUrl(channelSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgChannelSettings->asJson().toUtf8());
    buffer->seek(0);

    // Always use PATCH to avoid passing reverse API settings
    QNetworkReply *reply = m_networkManager->sendCustomRequest(m_networkRequest, "PATCH", buffer);
    buffer->setParent(reply);

    delete swgChannelSettings;
}

void AISDemod::webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings *swgChannelSettings,
        const AISDemodSettings& settings,
        bool force
)
{
    swgChannelSettings->setDirection(0); // Single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString("AISDemod"));
    swgChannelSettings->setAisDemodSettings(new SWGrpx-100::SWGAISDemodSettings());
    SWGrpx-100::SWGAISDemodSettings *swgAISDemodSettings = swgChannelSettings->getAisDemodSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("fmDeviation") || force) {
        swgAISDemodSettings->setFmDeviation(settings.m_fmDeviation);
    }
    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgAISDemodSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("rfBandwidth") || force) {
        swgAISDemodSettings->setRfBandwidth(settings.m_rfBandwidth);
    }
    if (channelSettingsKeys.contains("correlationThreshold") || force) {
        swgAISDemodSettings->setCorrelationThreshold(settings.m_correlationThreshold);
    }
    if (channelSettingsKeys.contains("udpEnabled") || force) {
        swgAISDemodSettings->setUdpEnabled(settings.m_udpEnabled);
    }
    if (channelSettingsKeys.contains("udpAddress") || force) {
        swgAISDemodSettings->setUdpAddress(new QString(settings.m_udpAddress));
    }
    if (channelSettingsKeys.contains("udpPort") || force) {
        swgAISDemodSettings->setUdpPort(settings.m_udpPort);
    }
    if (channelSettingsKeys.contains("udpFormat") || force) {
        swgAISDemodSettings->setUdpPort((int)settings.m_udpFormat);
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgAISDemodSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgAISDemodSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("streamIndex") || force) {
        swgAISDemodSettings->setStreamIndex(settings.m_streamIndex);
    }
}

void AISDemod::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "AISDemod::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("AISDemod::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

void AISDemod::handleChannelMessages()
{
	Message* message;

	while ((message = m_channelMessageQueue.pop()) != nullptr)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}
