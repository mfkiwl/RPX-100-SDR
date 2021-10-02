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

#include "packetdemod.h"

#include <QTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QThread>

#include <stdio.h>
#include <complex.h>

#include "SWGChannelSettings.h"
#include "SWGPacketDemodSettings.h"
#include "SWGChannelReport.h"
#include "SWGMapItem.h"

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "device/deviceapi.h"
#include "feature/feature.h"
#include "util/db.h"
#include "maincore.h"

MESSAGE_CLASS_DEFINITION(PacketDemod::MsgConfigurePacketDemod, Message)

const char * const PacketDemod::m_channelIdURI = "RPX100.channel.packetdemod";
const char * const PacketDemod::m_channelId = "PacketDemod";

PacketDemod::PacketDemod(DeviceAPI *deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_basebandSampleRate(0)
{
    setObjectName(m_channelId);

    m_basebandSink = new PacketDemodBaseband(this);
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

PacketDemod::~PacketDemod()
{
    qDebug("PacketDemod::~PacketDemod");
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
    m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);

    if (m_basebandSink->isRunning()) {
        stop();
    }

    delete m_basebandSink;
}

uint32_t PacketDemod::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void PacketDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool firstOfBurst)
{
    (void) firstOfBurst;
    m_basebandSink->feed(begin, end);
}

void PacketDemod::start()
{
    qDebug("PacketDemod::start");

    m_basebandSink->reset();
    m_basebandSink->startWork();
    m_thread.start();

    DSPSignalNotification *dspMsg = new DSPSignalNotification(m_basebandSampleRate, m_centerFrequency);
    m_basebandSink->getInputMessageQueue()->push(dspMsg);

    PacketDemodBaseband::MsgConfigurePacketDemodBaseband *msg = PacketDemodBaseband::MsgConfigurePacketDemodBaseband::create(m_settings, true);
    m_basebandSink->getInputMessageQueue()->push(msg);
}

void PacketDemod::stop()
{
    qDebug("PacketDemod::stop");
    m_basebandSink->stopWork();
    m_thread.quit();
    m_thread.wait();
}

bool PacketDemod::handleMessage(const Message& cmd)
{
    if (MsgConfigurePacketDemod::match(cmd))
    {
        MsgConfigurePacketDemod& cfg = (MsgConfigurePacketDemod&) cmd;
        qDebug() << "PacketDemod::handleMessage: MsgConfigurePacketDemod";
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
        qDebug() << "PacketDemod::handleMessage: DSPSignalNotification";
        m_basebandSink->getInputMessageQueue()->push(rep);
        // Forward to GUI if any
        if (m_guiMessageQueue)
        {
            rep = new DSPSignalNotification(notif);
            m_guiMessageQueue->push(rep);
        }

        return true;
    }
    else if (MainCore::MsgPacket::match(cmd))
    {
        // Forward to GUI
        MainCore::MsgPacket& report = (MainCore::MsgPacket&)cmd;
        if (getMessageQueueToGUI())
        {
            MainCore::MsgPacket *msg = new MainCore::MsgPacket(report);
            getMessageQueueToGUI()->push(msg);
        }

        MessagePipes& messagePipes = MainCore::instance()->getMessagePipes();

        // Forward to APRS and other packet features
        QList<MessageQueue*> *packetMessageQueues = messagePipes.getMessageQueues(this, "packets");
        if (packetMessageQueues)
        {
            QList<MessageQueue*>::iterator it = packetMessageQueues->begin();
            for (; it != packetMessageQueues->end(); ++it)
            {
                MainCore::MsgPacket *msg = new MainCore::MsgPacket(report);
                (*it)->push(msg);
            }
        }

        // Forward via UDP
        if (m_settings.m_udpEnabled)
        {
            qDebug() << "Forwarding to " << m_settings.m_udpAddress << ":" << m_settings.m_udpPort;
            m_udpSocket.writeDatagram(report.getPacket().data(), report.getPacket().size(),
                                      QHostAddress(m_settings.m_udpAddress), m_settings.m_udpPort);
        }

        return true;
    }
    else if (MainCore::MsgChannelDemodQuery::match(cmd))
    {
        qDebug() << "PacketDemod::handleMessage: MsgChannelDemodQuery";
        sendSampleRateToDemodAnalyzer();

        return true;
    }
    else
    {
        return false;
    }
}

void PacketDemod::applySettings(const PacketDemodSettings& settings, bool force)
{
    qDebug() << "PacketDemod::applySettings:"
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
    if ((settings.m_udpEnabled != m_settings.m_udpEnabled) || force) {
        reverseAPIKeys.append("udpEnabled");
    }
    if ((settings.m_udpAddress != m_settings.m_udpAddress) || force) {
        reverseAPIKeys.append("udpAddress");
    }
    if ((settings.m_udpPort != m_settings.m_udpPort) || force) {
        reverseAPIKeys.append("udpPort");
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

    PacketDemodBaseband::MsgConfigurePacketDemodBaseband *msg = PacketDemodBaseband::MsgConfigurePacketDemodBaseband::create(settings, force);
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

void PacketDemod::sendSampleRateToDemodAnalyzer()
{
    QList<MessageQueue*> *messageQueues = MainCore::instance()->getMessagePipes().getMessageQueues(this, "reportdemod");

    if (messageQueues)
    {
        QList<MessageQueue*>::iterator it = messageQueues->begin();

        for (; it != messageQueues->end(); ++it)
        {
            MainCore::MsgChannelDemodReport *msg = MainCore::MsgChannelDemodReport::create(
                this,
                PacketDemodSettings::PACKETDEMOD_CHANNEL_SAMPLE_RATE
            );
            (*it)->push(msg);
        }
    }
}

QByteArray PacketDemod::serialize() const
{
    return m_settings.serialize();
}

bool PacketDemod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigurePacketDemod *msg = MsgConfigurePacketDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigurePacketDemod *msg = MsgConfigurePacketDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

int PacketDemod::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setPacketDemodSettings(new SWGRPX100::SWGPacketDemodSettings());
    response.getPacketDemodSettings()->init();
    webapiFormatChannelSettings(response, m_settings);
    return 200;
}

int PacketDemod::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    PacketDemodSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigurePacketDemod *msg = MsgConfigurePacketDemod::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("PacketDemod::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigurePacketDemod *msgToGUI = MsgConfigurePacketDemod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void PacketDemod::webapiUpdateChannelSettings(
        PacketDemodSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getPacketDemodSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("fmDeviation")) {
        settings.m_fmDeviation = response.getPacketDemodSettings()->getFmDeviation();
    }
    if (channelSettingsKeys.contains("rfBandwidth")) {
        settings.m_rfBandwidth = response.getPacketDemodSettings()->getRfBandwidth();
    }
    if (channelSettingsKeys.contains("udpEnabled")) {
        settings.m_udpEnabled = response.getPacketDemodSettings()->getUdpEnabled();
    }
    if (channelSettingsKeys.contains("udpAddress")) {
        settings.m_udpAddress = *response.getPacketDemodSettings()->getUdpAddress();
    }
    if (channelSettingsKeys.contains("udpPort")) {
        settings.m_udpPort = response.getPacketDemodSettings()->getUdpPort();
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getPacketDemodSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getPacketDemodSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getPacketDemodSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getPacketDemodSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getPacketDemodSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getPacketDemodSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getPacketDemodSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getPacketDemodSettings()->getReverseApiChannelIndex();
    }
}

void PacketDemod::webapiFormatChannelSettings(SWGRPX100::SWGChannelSettings& response, const PacketDemodSettings& settings)
{
    response.getPacketDemodSettings()->setFmDeviation(settings.m_fmDeviation);
    response.getPacketDemodSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getPacketDemodSettings()->setRfBandwidth(settings.m_rfBandwidth);
    response.getPacketDemodSettings()->setUdpEnabled(settings.m_udpEnabled);
    response.getPacketDemodSettings()->setUdpAddress(new QString(settings.m_udpAddress));
    response.getPacketDemodSettings()->setUdpPort(settings.m_udpPort);

    response.getPacketDemodSettings()->setRgbColor(settings.m_rgbColor);
    if (response.getPacketDemodSettings()->getTitle()) {
        *response.getPacketDemodSettings()->getTitle() = settings.m_title;
    } else {
        response.getPacketDemodSettings()->setTitle(new QString(settings.m_title));
    }

    response.getPacketDemodSettings()->setStreamIndex(settings.m_streamIndex);
    response.getPacketDemodSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getPacketDemodSettings()->getReverseApiAddress()) {
        *response.getPacketDemodSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getPacketDemodSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getPacketDemodSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getPacketDemodSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getPacketDemodSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void PacketDemod::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const PacketDemodSettings& settings, bool force)
{
    SWGRPX100::SWGChannelSettings *swgChannelSettings = new SWGRPX100::SWGChannelSettings();
    webapiFormatChannelSettings(channelSettingsKeys, swgChannelSettings, settings, force);

    QString channelSettingsURL = QString("http://%1:%2/RPX100/deviceset/%3/channel/%4/settings")
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

void PacketDemod::webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings *swgChannelSettings,
        const PacketDemodSettings& settings,
        bool force
)
{
    swgChannelSettings->setDirection(0); // Single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString("PacketDemod"));
    swgChannelSettings->setPacketDemodSettings(new SWGRPX100::SWGPacketDemodSettings());
    SWGRPX100::SWGPacketDemodSettings *swgPacketDemodSettings = swgChannelSettings->getPacketDemodSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("fmDeviation") || force) {
        swgPacketDemodSettings->setFmDeviation(settings.m_fmDeviation);
    }
    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgPacketDemodSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("rfBandwidth") || force) {
        swgPacketDemodSettings->setRfBandwidth(settings.m_rfBandwidth);
    }
    if (channelSettingsKeys.contains("udpEnabled") || force) {
        swgPacketDemodSettings->setUdpEnabled(settings.m_udpEnabled);
    }
    if (channelSettingsKeys.contains("udpAddress") || force) {
        swgPacketDemodSettings->setUdpAddress(new QString(settings.m_udpAddress));
    }
    if (channelSettingsKeys.contains("udpPort") || force) {
        swgPacketDemodSettings->setUdpPort(settings.m_udpPort);
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgPacketDemodSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgPacketDemodSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("streamIndex") || force) {
        swgPacketDemodSettings->setStreamIndex(settings.m_streamIndex);
    }
}

void PacketDemod::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "PacketDemod::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("PacketDemod::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

void PacketDemod::handleChannelMessages()
{
	Message* message;

	while ((message = m_channelMessageQueue.pop()) != nullptr)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}
