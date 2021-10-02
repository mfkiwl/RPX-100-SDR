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

#include "dabdemod.h"

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QThread>

#include <stdio.h>
#include <complex.h>

#include "SWGChannelSettings.h"
#include "SWGDABDemodSettings.h"
#include "SWGChannelReport.h"
#include "SWGMapItem.h"

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "device/deviceapi.h"
#include "feature/feature.h"
#include "util/db.h"
#include "maincore.h"

MESSAGE_CLASS_DEFINITION(DABDemod::MsgConfigureDABDemod, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABEnsembleName, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABProgramName, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABProgramData, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABSystemData, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABProgramQuality, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABFIBQuality, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABSampleRate, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABData, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABMOTData, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABReset, Message)
MESSAGE_CLASS_DEFINITION(DABDemod::MsgDABResetService, Message)

const char * const DABDemod::m_channelIdURI = "RPX100.channel.dabdemod";
const char * const DABDemod::m_channelId = "DABDemod";

DABDemod::DABDemod(DeviceAPI *deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_basebandSampleRate(0)
{
    setObjectName(m_channelId);

    m_basebandSink = new DABDemodBaseband(this);
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

DABDemod::~DABDemod()
{
    qDebug("DABDemod::~DABDemod");
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
    m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);

    if (m_basebandSink->isRunning()) {
        stop();
    }

    delete m_basebandSink;
}

uint32_t DABDemod::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void DABDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool firstOfBurst)
{
    (void) firstOfBurst;
    m_basebandSink->feed(begin, end);
}

void DABDemod::start()
{
    qDebug("DABDemod::start");

    m_basebandSink->reset();
    m_basebandSink->startWork();
    m_thread.start();

    DSPSignalNotification *dspMsg = new DSPSignalNotification(m_basebandSampleRate, m_centerFrequency);
    m_basebandSink->getInputMessageQueue()->push(dspMsg);

    DABDemodBaseband::MsgConfigureDABDemodBaseband *msg = DABDemodBaseband::MsgConfigureDABDemodBaseband::create(m_settings, true);
    m_basebandSink->getInputMessageQueue()->push(msg);
}

void DABDemod::stop()
{
    qDebug("DABDemod::stop");
    m_basebandSink->stopWork();
    m_thread.quit();
    m_thread.wait();
}

bool DABDemod::handleMessage(const Message& cmd)
{
    if (MsgConfigureDABDemod::match(cmd))
    {
        MsgConfigureDABDemod& cfg = (MsgConfigureDABDemod&) cmd;
        qDebug() << "DABDemod::handleMessage: MsgConfigureDABDemod";
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
        qDebug() << "DABDemod::handleMessage: DSPSignalNotification";
        m_basebandSink->getInputMessageQueue()->push(rep);
        // Forward to GUI if any
        if (m_guiMessageQueue)
        {
            rep = new DSPSignalNotification(notif);
            m_guiMessageQueue->push(rep);
        }

        return true;
    }
    else if (MsgDABSystemData::match(cmd))
    {
        MsgDABSystemData& report = (MsgDABSystemData&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABSystemData(report));
        }

        return true;
    }
    else if (MsgDABProgramQuality::match(cmd))
    {
        MsgDABProgramQuality& report = (MsgDABProgramQuality&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABProgramQuality(report));
        }

        return true;
    }
    else if (MsgDABFIBQuality::match(cmd))
    {
        MsgDABFIBQuality& report = (MsgDABFIBQuality&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABFIBQuality(report));
        }

        return true;
    }
    else if (MsgDABSampleRate::match(cmd))
    {
        MsgDABSampleRate& report = (MsgDABSampleRate&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABSampleRate(report));
        }

        return true;
    }
    else if (MsgDABEnsembleName::match(cmd))
    {
        MsgDABEnsembleName& report = (MsgDABEnsembleName&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABEnsembleName(report));
        }

        return true;
    }
    else if (MsgDABProgramName::match(cmd))
    {
        MsgDABProgramName& report = (MsgDABProgramName&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABProgramName(report));
        }

        return true;
    }
    else if (MsgDABProgramData::match(cmd))
    {
        MsgDABProgramData& report = (MsgDABProgramData&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABProgramData(report));
        }

        return true;
    }
    else if (MsgDABData::match(cmd))
    {
        MsgDABData& report = (MsgDABData&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABData(report));
        }

        return true;
    }
    else if (MsgDABMOTData::match(cmd))
    {
        MsgDABMOTData& report = (MsgDABMOTData&)cmd;
        if (getMessageQueueToGUI())
        {
            getMessageQueueToGUI()->push(new MsgDABMOTData(report));
        }

        return true;
    }
    else if (MsgDABReset::match(cmd))
    {
        MsgDABReset& report = (MsgDABReset&)cmd;
        m_basebandSink->getInputMessageQueue()->push(new MsgDABReset(report));

        return true;
    }
    else if (MsgDABResetService::match(cmd))
    {
        MsgDABResetService& report = (MsgDABResetService&)cmd;
        m_basebandSink->getInputMessageQueue()->push(new MsgDABResetService(report));

        return true;
    }
    else if (MainCore::MsgChannelDemodQuery::match(cmd))
    {
        qDebug() << "DABDemod::handleMessage: MsgChannelDemodQuery";
        sendSampleRateToDemodAnalyzer();

        return true;
    }
    else
    {
        return false;
    }
}

void DABDemod::applySettings(const DABDemodSettings& settings, bool force)
{
    qDebug() << "DABDemod::applySettings:"
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
    if ((settings.m_program != m_settings.m_program) || force) {
        reverseAPIKeys.append("program");
    }
    if ((settings.m_volume != m_settings.m_volume) || force) {
        reverseAPIKeys.append("volume");
    }
    if ((settings.m_audioMute != m_settings.m_audioMute) || force) {
        reverseAPIKeys.append("audioMute");
    }
    if ((settings.m_audioDeviceName != m_settings.m_audioDeviceName) || force) {
        reverseAPIKeys.append("audioDeviceName");
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

    DABDemodBaseband::MsgConfigureDABDemodBaseband *msg = DABDemodBaseband::MsgConfigureDABDemodBaseband::create(settings, force);
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

QByteArray DABDemod::serialize() const
{
    return m_settings.serialize();
}

bool DABDemod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureDABDemod *msg = MsgConfigureDABDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureDABDemod *msg = MsgConfigureDABDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void DABDemod::sendSampleRateToDemodAnalyzer()
{
    QList<MessageQueue*> *messageQueues = MainCore::instance()->getMessagePipes().getMessageQueues(this, "reportdemod");

    if (messageQueues)
    {
        QList<MessageQueue*>::iterator it = messageQueues->begin();

        for (; it != messageQueues->end(); ++it)
        {
            MainCore::MsgChannelDemodReport *msg = MainCore::MsgChannelDemodReport::create(
                this,
                getAudioSampleRate()
            );
            (*it)->push(msg);
        }
    }
}

int DABDemod::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setDabDemodSettings(new SWGRPX100::SWGDABDemodSettings());
    response.getDabDemodSettings()->init();
    webapiFormatChannelSettings(response, m_settings);
    return 200;
}

int DABDemod::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    DABDemodSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigureDABDemod *msg = MsgConfigureDABDemod::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("DABDemod::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureDABDemod *msgToGUI = MsgConfigureDABDemod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void DABDemod::webapiUpdateChannelSettings(
        DABDemodSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getDabDemodSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("rfBandwidth")) {
        settings.m_rfBandwidth = response.getDabDemodSettings()->getRfBandwidth();
    }
    if (channelSettingsKeys.contains("program")) {
        settings.m_program = *response.getDabDemodSettings()->getProgram();
    }
    if (channelSettingsKeys.contains("m_volume")) {
        settings.m_volume = response.getDabDemodSettings()->getVolume();
    }
    if (channelSettingsKeys.contains("audioMute")) {
        settings.m_audioMute = response.getDabDemodSettings()->getAudioMute();
    }
    if (channelSettingsKeys.contains("audioDeviceName")) {
        settings.m_audioDeviceName = *response.getDabDemodSettings()->getAudioDeviceName();
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getDabDemodSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getDabDemodSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getDabDemodSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getDabDemodSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getDabDemodSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getDabDemodSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getDabDemodSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getDabDemodSettings()->getReverseApiChannelIndex();
    }
}

void DABDemod::webapiFormatChannelSettings(SWGRPX100::SWGChannelSettings& response, const DABDemodSettings& settings)
{
    response.getDabDemodSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getDabDemodSettings()->setRfBandwidth(settings.m_rfBandwidth);
    response.getDabDemodSettings()->setProgram(new QString(settings.m_program));
    response.getDabDemodSettings()->setVolume(settings.m_volume);
    response.getDabDemodSettings()->setAudioMute(settings.m_audioMute);
    response.getDabDemodSettings()->setAudioDeviceName(new QString(settings.m_audioDeviceName));

    response.getDabDemodSettings()->setRgbColor(settings.m_rgbColor);
    if (response.getDabDemodSettings()->getTitle()) {
        *response.getDabDemodSettings()->getTitle() = settings.m_title;
    } else {
        response.getDabDemodSettings()->setTitle(new QString(settings.m_title));
    }

    response.getDabDemodSettings()->setStreamIndex(settings.m_streamIndex);
    response.getDabDemodSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getDabDemodSettings()->getReverseApiAddress()) {
        *response.getDabDemodSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getDabDemodSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getDabDemodSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getDabDemodSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getDabDemodSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void DABDemod::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const DABDemodSettings& settings, bool force)
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

void DABDemod::webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings *swgChannelSettings,
        const DABDemodSettings& settings,
        bool force
)
{
    swgChannelSettings->setDirection(0); // Single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString("DABDemod"));
    swgChannelSettings->setDabDemodSettings(new SWGRPX100::SWGDABDemodSettings());
    SWGRPX100::SWGDABDemodSettings *swgDABDemodSettings = swgChannelSettings->getDabDemodSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgDABDemodSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("rfBandwidth") || force) {
        swgDABDemodSettings->setRfBandwidth(settings.m_rfBandwidth);
    }
    if (channelSettingsKeys.contains("program") || force) {
        swgDABDemodSettings->setProgram(new QString(settings.m_program));
    }
    if (channelSettingsKeys.contains("volume") || force) {
        swgDABDemodSettings->setVolume(settings.m_volume);
    }
    if (channelSettingsKeys.contains("audioMute") || force) {
        swgDABDemodSettings->setAudioMute(settings.m_audioMute);
    }
    if (channelSettingsKeys.contains("audioDeviceName") || force) {
        swgDABDemodSettings->setAudioDeviceName(new QString(settings.m_audioDeviceName));
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgDABDemodSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgDABDemodSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("streamIndex") || force) {
        swgDABDemodSettings->setStreamIndex(settings.m_streamIndex);
    }
}

void DABDemod::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "DABDemod::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("DABDemod::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

void DABDemod::handleChannelMessages()
{
	Message* message;

	while ((message = m_channelMessageQueue.pop()) != nullptr)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}
