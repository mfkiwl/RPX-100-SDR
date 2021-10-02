///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
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

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QThread>

#include "SWGChannelSettings.h"
#include "SWGFreeDVDemodSettings.h"
#include "SWGChannelReport.h"
#include "SWGFreeDVDemodReport.h"

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "dsp/devicesamplemimo.h"
#include "device/deviceapi.h"
#include "feature/feature.h"
#include "util/db.h"
#include "maincore.h"

#include "freedvdemod.h"

MESSAGE_CLASS_DEFINITION(FreeDVDemod::MsgConfigureFreeDVDemod, Message)
MESSAGE_CLASS_DEFINITION(FreeDVDemod::MsgResyncFreeDVDemod, Message)

const char* const FreeDVDemod::m_channelIdURI = "rpx-100.channel.freedvdemod";
const char* const FreeDVDemod::m_channelId = "FreeDVDemod";

FreeDVDemod::FreeDVDemod(DeviceAPI *deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_spectrumVis(SDR_RX_SCALEF)
{
	setObjectName(m_channelId);

    m_thread = new QThread(this);
    m_basebandSink = new FreeDVDemodBaseband();
    m_basebandSink->setSpectrumSink(&m_spectrumVis);
    m_basebandSink->moveToThread(m_thread);

    applySettings(m_settings, true);

    m_deviceAPI->addChannelSink(this);
    m_deviceAPI->addChannelSinkAPI(this);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

FreeDVDemod::~FreeDVDemod()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
	m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);
    delete m_basebandSink;
    delete m_thread;
}

uint32_t FreeDVDemod::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void FreeDVDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool positiveOnly)
{
    (void) positiveOnly;
    m_basebandSink->feed(begin, end);
}

void FreeDVDemod::start()
{
    qDebug() << "FreeDVDemod::start";

    if (m_basebandSampleRate != 0) {
        m_basebandSink->setBasebandSampleRate(m_basebandSampleRate);
    }

    m_basebandSink->reset();
    m_thread->start();

    SpectrumSettings spectrumSettings = m_spectrumVis.getSettings();
    spectrumSettings.m_ssb = true;
    SpectrumVis::MsgConfigureSpectrumVis *msg = SpectrumVis::MsgConfigureSpectrumVis::create(spectrumSettings, false);
    m_spectrumVis.getInputMessageQueue()->push(msg);
}

void FreeDVDemod::stop()
{
    qDebug() << "FreeDVDemod::stop";
	m_thread->exit();
	m_thread->wait();
}

bool FreeDVDemod::handleMessage(const Message& cmd)
{
    if (MsgConfigureFreeDVDemod::match(cmd))
    {
        MsgConfigureFreeDVDemod& cfg = (MsgConfigureFreeDVDemod&) cmd;
        qDebug("FreeDVDemod::handleMessage: MsgConfigureFreeDVDemod");

        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else if (MsgResyncFreeDVDemod::match(cmd))
    {
        qDebug("FreeDVDemod::handleMessage: MsgResyncFreeDVDemod");
        FreeDVDemodBaseband::MsgResyncFreeDVDemod *msg = FreeDVDemodBaseband::MsgResyncFreeDVDemod::create();
        m_basebandSink->getInputMessageQueue()->push(msg);

        return true;
    }
    else if (DSPSignalNotification::match(cmd))
    {
        DSPSignalNotification& notif = (DSPSignalNotification&) cmd;
        m_basebandSampleRate = notif.getSampleRate();
        // Forward to the sink
        DSPSignalNotification* rep = new DSPSignalNotification(notif); // make a copy
        qDebug() << "FreeDVDemod::handleMessage: DSPSignalNotification";
        m_basebandSink->getInputMessageQueue()->push(rep);

        return true;
    }
	else
	{
		return false;
	}
}


void FreeDVDemod::applySettings(const FreeDVDemodSettings& settings, bool force)
{
    qDebug() << "FreeDVDemod::applySettings:"
            << " m_inputFrequencyOffset: " << settings.m_inputFrequencyOffset
            << " m_freeDVMode: " << (int) settings.m_freeDVMode
            << " m_volume: " << settings.m_volume
            << " m_volumeIn: " << settings.m_volumeIn
            << " m_spanLog2: " << settings.m_spanLog2
            << " m_audioMute: " << settings.m_audioMute
            << " m_agcActive: " << settings.m_agc
            << " m_audioDeviceName: " << settings.m_audioDeviceName
            << " m_streamIndex: " << settings.m_streamIndex
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIDeviceIndex: " << settings.m_reverseAPIDeviceIndex
            << " m_reverseAPIChannelIndex: " << settings.m_reverseAPIChannelIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if((m_settings.m_inputFrequencyOffset != settings.m_inputFrequencyOffset) || force) {
        reverseAPIKeys.append("inputFrequencyOffset");
    }
    if ((m_settings.m_volume != settings.m_volume) || force) {
        reverseAPIKeys.append("volume");
    }
    if ((m_settings.m_volumeIn != settings.m_volumeIn) || force) {
        reverseAPIKeys.append("volumeIn");
    }
    if ((settings.m_audioDeviceName != m_settings.m_audioDeviceName) || force) {
        reverseAPIKeys.append("audioDeviceName");
    }
    if ((m_settings.m_spanLog2 != settings.m_spanLog2) || force) {
        reverseAPIKeys.append("spanLog2");
    }
    if ((m_settings.m_audioMute != settings.m_audioMute) || force) {
        reverseAPIKeys.append("audioMute");
    }
    if ((m_settings.m_agc != settings.m_agc) || force) {
        reverseAPIKeys.append("agc");
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

    if ((settings.m_freeDVMode != m_settings.m_freeDVMode)
     || (settings.m_spanLog2 != m_settings.m_spanLog2) || force)
    {
        DSPSignalNotification *msg = new DSPSignalNotification(
            FreeDVDemodSettings::getModSampleRate(settings.m_freeDVMode)/(1<<settings.m_spanLog2),
            0);
        m_spectrumVis.getInputMessageQueue()->push(msg);
    }

    FreeDVDemodBaseband::MsgConfigureFreeDVDemodBaseband *msg = FreeDVDemodBaseband::MsgConfigureFreeDVDemodBaseband::create(settings, force);
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

QByteArray FreeDVDemod::serialize() const
{
    return m_settings.serialize();
}

bool FreeDVDemod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureFreeDVDemod *msg = MsgConfigureFreeDVDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureFreeDVDemod *msg = MsgConfigureFreeDVDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

int FreeDVDemod::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setFreeDvDemodSettings(new SWGRPX100::SWGFreeDVDemodSettings());
    response.getFreeDvDemodSettings()->init();
    webapiFormatChannelSettings(response, m_settings);
    return 200;
}

int FreeDVDemod::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    FreeDVDemodSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigureFreeDVDemod *msg = MsgConfigureFreeDVDemod::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("FreeDVDemod::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureFreeDVDemod *msgToGUI = MsgConfigureFreeDVDemod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void FreeDVDemod::webapiUpdateChannelSettings(
        FreeDVDemodSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getFreeDvDemodSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("freeDVMode")) {
        settings.m_freeDVMode = (FreeDVDemodSettings::FreeDVMode) response.getFreeDvDemodSettings()->getFreeDvMode();
    }
    if (channelSettingsKeys.contains("volume")) {
        settings.m_volume = response.getFreeDvDemodSettings()->getVolume();
    }
    if (channelSettingsKeys.contains("volumeIn")) {
        settings.m_volumeIn = response.getFreeDvDemodSettings()->getVolumeIn();
    }
    if (channelSettingsKeys.contains("spanLog2")) {
        settings.m_spanLog2 = response.getFreeDvDemodSettings()->getSpanLog2();
    }
    if (channelSettingsKeys.contains("audioMute")) {
        settings.m_audioMute = response.getFreeDvDemodSettings()->getAudioMute() != 0;
    }
    if (channelSettingsKeys.contains("agc")) {
        settings.m_agc = response.getFreeDvDemodSettings()->getAgc() != 0;
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getFreeDvDemodSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getFreeDvDemodSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("audioDeviceName")) {
        settings.m_audioDeviceName = *response.getFreeDvDemodSettings()->getAudioDeviceName();
    }
    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getFreeDvDemodSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getFreeDvDemodSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getFreeDvDemodSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getFreeDvDemodSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getFreeDvDemodSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getFreeDvDemodSettings()->getReverseApiChannelIndex();
    }
}

int FreeDVDemod::webapiReportGet(
        SWGRPX100::SWGChannelReport& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setFreeDvDemodReport(new SWGRPX100::SWGFreeDVDemodReport());
    response.getFreeDvDemodReport()->init();
    webapiFormatChannelReport(response);
    return 200;
}

void FreeDVDemod::webapiFormatChannelSettings(SWGRPX100::SWGChannelSettings& response, const FreeDVDemodSettings& settings)
{
    response.getFreeDvDemodSettings()->setAudioMute(settings.m_audioMute ? 1 : 0);
    response.getFreeDvDemodSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getFreeDvDemodSettings()->setVolume(settings.m_volume);
    response.getFreeDvDemodSettings()->setVolumeIn(settings.m_volumeIn);
    response.getFreeDvDemodSettings()->setSpanLog2(settings.m_spanLog2);
    response.getFreeDvDemodSettings()->setAudioMute(settings.m_audioMute ? 1 : 0);
    response.getFreeDvDemodSettings()->setAgc(settings.m_agc ? 1 : 0);
    response.getFreeDvDemodSettings()->setRgbColor(settings.m_rgbColor);
    response.getFreeDvDemodSettings()->setFreeDvMode((int) settings.m_freeDVMode);

    if (response.getFreeDvDemodSettings()->getTitle()) {
        *response.getFreeDvDemodSettings()->getTitle() = settings.m_title;
    } else {
        response.getFreeDvDemodSettings()->setTitle(new QString(settings.m_title));
    }

    if (response.getFreeDvDemodSettings()->getAudioDeviceName()) {
        *response.getFreeDvDemodSettings()->getAudioDeviceName() = settings.m_audioDeviceName;
    } else {
        response.getFreeDvDemodSettings()->setAudioDeviceName(new QString(settings.m_audioDeviceName));
    }

    response.getFreeDvDemodSettings()->setStreamIndex(settings.m_streamIndex);
    response.getFreeDvDemodSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getFreeDvDemodSettings()->getReverseApiAddress()) {
        *response.getFreeDvDemodSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getFreeDvDemodSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getFreeDvDemodSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getFreeDvDemodSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getFreeDvDemodSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void FreeDVDemod::webapiFormatChannelReport(SWGRPX100::SWGChannelReport& response)
{
    double magsqAvg, magsqPeak;
    int nbMagsqSamples;
    getMagSqLevels(magsqAvg, magsqPeak, nbMagsqSamples);

    response.getFreeDvDemodReport()->setChannelPowerDb(CalcDb::dbPower(magsqAvg));
    response.getFreeDvDemodReport()->setSquelch(getAudioActive() ? 1 : 0);
    response.getFreeDvDemodReport()->setAudioSampleRate(getAudioSampleRate());
    response.getFreeDvDemodReport()->setChannelSampleRate(m_basebandSink->getChannelSampleRate());
}

void FreeDVDemod::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const FreeDVDemodSettings& settings, bool force)
{
    SWGRPX100::SWGChannelSettings *swgChannelSettings = new SWGRPX100::SWGChannelSettings();
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

void FreeDVDemod::sendChannelSettings(
    QList<MessageQueue*> *messageQueues,
    QList<QString>& channelSettingsKeys,
    const FreeDVDemodSettings& settings,
    bool force)
{
    QList<MessageQueue*>::iterator it = messageQueues->begin();

    for (; it != messageQueues->end(); ++it)
    {
        SWGRPX100::SWGChannelSettings *swgChannelSettings = new SWGRPX100::SWGChannelSettings();
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

void FreeDVDemod::webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings *swgChannelSettings,
        const FreeDVDemodSettings& settings,
        bool force
)
{
    swgChannelSettings->setDirection(0); // Single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString(m_channelId));
    swgChannelSettings->setFreeDvDemodSettings(new SWGRPX100::SWGFreeDVDemodSettings());
    SWGRPX100::SWGFreeDVDemodSettings *swgFreeDVDemodSettings = swgChannelSettings->getFreeDvDemodSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgFreeDVDemodSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("freeDVMode") || force) {
        swgFreeDVDemodSettings->setFreeDvMode((int) settings.m_freeDVMode);
    }
    if (channelSettingsKeys.contains("volume") || force) {
        swgFreeDVDemodSettings->setVolume(settings.m_volume);
    }
    if (channelSettingsKeys.contains("volumeIn") || force) {
        swgFreeDVDemodSettings->setVolumeIn(settings.m_volumeIn);
    }
    if (channelSettingsKeys.contains("spanLog2") || force) {
        swgFreeDVDemodSettings->setSpanLog2(settings.m_spanLog2);
    }
    if (channelSettingsKeys.contains("audioMute") || force) {
        swgFreeDVDemodSettings->setAudioMute(settings.m_audioMute ? 1 : 0);
    }
    if (channelSettingsKeys.contains("agc") || force) {
        swgFreeDVDemodSettings->setAgc(settings.m_agc ? 1 : 0);
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgFreeDVDemodSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgFreeDVDemodSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("audioDeviceName") || force) {
        swgFreeDVDemodSettings->setAudioDeviceName(new QString(settings.m_audioDeviceName));
    }
    if (channelSettingsKeys.contains("streamIndex") || force) {
        swgFreeDVDemodSettings->setStreamIndex(settings.m_streamIndex);
    }
}

void FreeDVDemod::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "FreeDVDemod::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("FreeDVDemod::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

void FreeDVDemod::setLevelMeter(QObject *levelMeter)
{
    connect(m_basebandSink, SIGNAL(levelChanged(qreal, qreal, int)), levelMeter, SLOT(levelChanged(qreal, qreal, int)));
}
