///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015-2018 Edouard Griffiths, F4EXB.                             //
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

#include "amdemod.h"

#include <QTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QThread>

#include <stdio.h>
#include <complex.h>

#include "SWGChannelSettings.h"
#include "SWGAMDemodSettings.h"
#include "SWGChannelReport.h"
#include "SWGAMDemodReport.h"

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "device/deviceapi.h"
#include "feature/feature.h"
#include "util/db.h"
#include "maincore.h"

MESSAGE_CLASS_DEFINITION(AMDemod::MsgConfigureAMDemod, Message)

const char* const AMDemod::m_channelIdURI = "rpx-100.channel.amdemod";
const char* const AMDemod::m_channelId = "AMDemod";
const int AMDemod::m_udpBlockSize = 512;

AMDemod::AMDemod(DeviceAPI *deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_basebandSampleRate(0)
{
    setObjectName(m_channelId);

    m_basebandSink = new AMDemodBaseband();
    m_basebandSink->setChannel(this);
    m_basebandSink->moveToThread(&m_thread);

	applySettings(m_settings, true);

    m_deviceAPI->addChannelSink(this);
    m_deviceAPI->addChannelSinkAPI(this);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    connect(&m_channelMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleChannelMessages()));
}

AMDemod::~AMDemod()
{
    qDebug("AMDemod::~AMDemod");
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
	m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);

    if (m_basebandSink->isRunning()) {
        stop();
    }

    delete m_basebandSink;
}

uint32_t AMDemod::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void AMDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool firstOfBurst)
{
    (void) firstOfBurst;
    m_basebandSink->feed(begin, end);
}

void AMDemod::start()
{
	qDebug("AMDemod::start");

    m_basebandSink->reset();
    m_basebandSink->startWork();
    m_thread.start();

    DSPSignalNotification *dspMsg = new DSPSignalNotification(m_basebandSampleRate, m_centerFrequency);
    m_basebandSink->getInputMessageQueue()->push(dspMsg);

    AMDemodBaseband::MsgConfigureAMDemodBaseband *msg = AMDemodBaseband::MsgConfigureAMDemodBaseband::create(m_settings, true);
    m_basebandSink->getInputMessageQueue()->push(msg);
}

void AMDemod::stop()
{
    qDebug("AMDemod::stop");
	m_basebandSink->stopWork();
	m_thread.quit();
	m_thread.wait();
}

bool AMDemod::handleMessage(const Message& cmd)
{
	if (MsgConfigureAMDemod::match(cmd))
	{
        MsgConfigureAMDemod& cfg = (MsgConfigureAMDemod&) cmd;
        qDebug() << "AMDemod::handleMessage: MsgConfigureAMDemod";
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
        qDebug() << "AMDemod::handleMessage: DSPSignalNotification";
        m_basebandSink->getInputMessageQueue()->push(rep);

	    return true;
    }
    else if (MainCore::MsgChannelDemodQuery::match(cmd))
    {
        qDebug() << "AMDemod::handleMessage: MsgChannelDemodQuery";
        sendSampleRateToDemodAnalyzer();

        return true;
    }
	else
	{
		return false;
	}
}

void AMDemod::applySettings(const AMDemodSettings& settings, bool force)
{
    qDebug() << "AMDemod::applySettings:"
            << " m_inputFrequencyOffset: " << settings.m_inputFrequencyOffset
            << " m_rfBandwidth: " << settings.m_rfBandwidth
            << " m_volume: " << settings.m_volume
            << " m_squelch: " << settings.m_squelch
            << " m_audioMute: " << settings.m_audioMute
            << " m_bandpassEnable: " << settings.m_bandpassEnable
            << " m_audioDeviceName: " << settings.m_audioDeviceName
            << " m_pll: " << settings.m_pll
            << " m_syncAMOperation: " << (int) settings.m_syncAMOperation
            << " m_streamIndex: " << settings.m_streamIndex
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIDeviceIndex: " << settings.m_reverseAPIDeviceIndex
            << " m_reverseAPIChannelIndex: " << settings.m_reverseAPIChannelIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_rfBandwidth != settings.m_rfBandwidth) || force) {
        reverseAPIKeys.append("rfBandwidth");
    }
    if ((m_settings.m_bandpassEnable != settings.m_bandpassEnable) || force) {
        reverseAPIKeys.append("bandpassEnable");
    }
    if ((m_settings.m_squelch != settings.m_squelch) || force) {
        reverseAPIKeys.append("squelch");
    }
    if ((settings.m_audioDeviceName != m_settings.m_audioDeviceName) || force) {
        reverseAPIKeys.append("audioDeviceName");
    }

    if ((m_settings.m_pll != settings.m_pll) || force)
    {
        reverseAPIKeys.append("pll");
        reverseAPIKeys.append("syncAMOperation");
    }

    if ((m_settings.m_syncAMOperation != settings.m_syncAMOperation) || force)
    {
        reverseAPIKeys.append("pll");
        reverseAPIKeys.append("syncAMOperation");
    }

    if ((m_settings.m_inputFrequencyOffset != settings.m_inputFrequencyOffset) || force) {
        reverseAPIKeys.append("inputFrequencyOffset");
    }

    if ((m_settings.m_audioMute != settings.m_audioMute) || force) {
        reverseAPIKeys.append("audioMute");
    }

    if ((m_settings.m_volume != settings.m_volume) || force) {
        reverseAPIKeys.append("volume");
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

    AMDemodBaseband::MsgConfigureAMDemodBaseband *msg = AMDemodBaseband::MsgConfigureAMDemodBaseband::create(settings, force);
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

    QList<MessageQueue*> *messageQueues = MainCore::instance()->getMessagePipes().getMessageQueues(this, "settings");

    if (messageQueues) {
        sendChannelSettings(messageQueues, reverseAPIKeys, settings, force);
    }

    m_settings = settings;
}

QByteArray AMDemod::serialize() const
{
    return m_settings.serialize();
}

bool AMDemod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureAMDemod *msg = MsgConfigureAMDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureAMDemod *msg = MsgConfigureAMDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void AMDemod::sendSampleRateToDemodAnalyzer()
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

int AMDemod::webapiSettingsGet(
        SWGrpx-100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setAmDemodSettings(new SWGrpx-100::SWGAMDemodSettings());
    response.getAmDemodSettings()->init();
    webapiFormatChannelSettings(response, m_settings);
    return 200;
}

int AMDemod::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    AMDemodSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigureAMDemod *msg = MsgConfigureAMDemod::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("AMDemod::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureAMDemod *msgToGUI = MsgConfigureAMDemod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void AMDemod::webapiUpdateChannelSettings(
        AMDemodSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("audioMute")) {
        settings.m_audioMute = response.getAmDemodSettings()->getAudioMute() != 0;
    }
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getAmDemodSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("rfBandwidth")) {
        settings.m_rfBandwidth = response.getAmDemodSettings()->getRfBandwidth();
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getAmDemodSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("squelch")) {
        settings.m_squelch = response.getAmDemodSettings()->getSquelch();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getAmDemodSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("volume")) {
        settings.m_volume = response.getAmDemodSettings()->getVolume();
    }
    if (channelSettingsKeys.contains("bandpassEnable")) {
        settings.m_bandpassEnable = response.getAmDemodSettings()->getBandpassEnable() != 0;
    }
    if (channelSettingsKeys.contains("audioDeviceName")) {
        settings.m_audioDeviceName = *response.getAmDemodSettings()->getAudioDeviceName();
    }

    if (channelSettingsKeys.contains("pll")) {
        settings.m_pll = response.getAmDemodSettings()->getPll();
    }

    if (channelSettingsKeys.contains("syncAMOperation")) {
        qint32 syncAMOperationCode = response.getAmDemodSettings()->getSyncAmOperation();
        settings.m_syncAMOperation = syncAMOperationCode < 0 ?
                AMDemodSettings::SyncAMDSB : syncAMOperationCode > 2 ?
                        AMDemodSettings::SyncAMLSB : (AMDemodSettings::SyncAMOperation) syncAMOperationCode;
    }

    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getAmDemodSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getAmDemodSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getAmDemodSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getAmDemodSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getAmDemodSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getAmDemodSettings()->getReverseApiChannelIndex();
    }
}

int AMDemod::webapiReportGet(
        SWGrpx-100::SWGChannelReport& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setAmDemodReport(new SWGrpx-100::SWGAMDemodReport());
    response.getAmDemodReport()->init();
    webapiFormatChannelReport(response);
    return 200;
}

void AMDemod::webapiFormatChannelSettings(SWGrpx-100::SWGChannelSettings& response, const AMDemodSettings& settings)
{
    response.getAmDemodSettings()->setAudioMute(settings.m_audioMute ? 1 : 0);
    response.getAmDemodSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getAmDemodSettings()->setRfBandwidth(settings.m_rfBandwidth);
    response.getAmDemodSettings()->setRgbColor(settings.m_rgbColor);
    response.getAmDemodSettings()->setSquelch(settings.m_squelch);
    response.getAmDemodSettings()->setVolume(settings.m_volume);
    response.getAmDemodSettings()->setBandpassEnable(settings.m_bandpassEnable ? 1 : 0);

    if (response.getAmDemodSettings()->getTitle()) {
        *response.getAmDemodSettings()->getTitle() = settings.m_title;
    } else {
        response.getAmDemodSettings()->setTitle(new QString(settings.m_title));
    }

    if (response.getAmDemodSettings()->getAudioDeviceName()) {
        *response.getAmDemodSettings()->getAudioDeviceName() = settings.m_audioDeviceName;
    } else {
        response.getAmDemodSettings()->setAudioDeviceName(new QString(settings.m_audioDeviceName));
    }

    response.getAmDemodSettings()->setPll(settings.m_pll ? 1 : 0);
    response.getAmDemodSettings()->setSyncAmOperation((int) settings.m_syncAMOperation);
    response.getAmDemodSettings()->setStreamIndex(settings.m_streamIndex);
    response.getAmDemodSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getAmDemodSettings()->getReverseApiAddress()) {
        *response.getAmDemodSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getAmDemodSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getAmDemodSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getAmDemodSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getAmDemodSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void AMDemod::webapiFormatChannelReport(SWGrpx-100::SWGChannelReport& response)
{
    double magsqAvg, magsqPeak;
    int nbMagsqSamples;
    getMagSqLevels(magsqAvg, magsqPeak, nbMagsqSamples);

    response.getAmDemodReport()->setChannelPowerDb(CalcDb::dbPower(magsqAvg));
    response.getAmDemodReport()->setSquelch(m_basebandSink->getSquelchOpen() ? 1 : 0);
    response.getAmDemodReport()->setAudioSampleRate(m_basebandSink->getAudioSampleRate());
    response.getAmDemodReport()->setChannelSampleRate(m_basebandSink->getChannelSampleRate());
}

void AMDemod::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const AMDemodSettings& settings, bool force)
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

void AMDemod::sendChannelSettings(
    QList<MessageQueue*> *messageQueues,
    QList<QString>& channelSettingsKeys,
    const AMDemodSettings& settings,
    bool force)
{
    QList<MessageQueue*>::iterator it = messageQueues->begin();

    for (; it != messageQueues->end(); ++it)
    {
        SWGrpx-100::SWGChannelSettings *swgChannelSettings = new SWGrpx-100::SWGChannelSettings();
        webapiFormatChannelSettings(channelSettingsKeys, swgChannelSettings, settings, force);
        MainCore::MsgChannelSettings *msg = MainCore::MsgChannelSettings::create(
            this,
            channelSettingsKeys,
            swgChannelSettings,
            force
        );
        (*it)->push(msg);
    }
}

void AMDemod::webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings *swgChannelSettings,
        const AMDemodSettings& settings,
        bool force
)
{
    swgChannelSettings->setDirection(0); // Single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString("AMDemod"));
    swgChannelSettings->setAmDemodSettings(new SWGrpx-100::SWGAMDemodSettings());
    SWGrpx-100::SWGAMDemodSettings *swgAMDemodSettings = swgChannelSettings->getAmDemodSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("audioMute") || force) {
        swgAMDemodSettings->setAudioMute(settings.m_audioMute ? 1 : 0);
    }
    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgAMDemodSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("rfBandwidth") || force) {
        swgAMDemodSettings->setRfBandwidth(settings.m_rfBandwidth);
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgAMDemodSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("squelch") || force) {
        swgAMDemodSettings->setSquelch(settings.m_squelch);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgAMDemodSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("volume") || force) {
        swgAMDemodSettings->setVolume(settings.m_volume);
    }
    if (channelSettingsKeys.contains("bandpassEnable") || force) {
        swgAMDemodSettings->setBandpassEnable(settings.m_bandpassEnable ? 1 : 0);
    }
    if (channelSettingsKeys.contains("audioDeviceName") || force) {
        swgAMDemodSettings->setAudioDeviceName(new QString(settings.m_audioDeviceName));
    }
    if (channelSettingsKeys.contains("pll") || force) {
        swgAMDemodSettings->setPll(settings.m_pll);
    }
    if (channelSettingsKeys.contains("syncAMOperation") || force) {
        swgAMDemodSettings->setSyncAmOperation((int) settings.m_syncAMOperation);
    }
    if (channelSettingsKeys.contains("streamIndex") || force) {
        swgAMDemodSettings->setStreamIndex(settings.m_streamIndex);
    }
}

void AMDemod::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "AMDemod::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("AMDemod::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

void AMDemod::handleChannelMessages()
{
	Message* message;

	while ((message = m_channelMessageQueue.pop()) != nullptr)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}
