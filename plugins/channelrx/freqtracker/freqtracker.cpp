///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB.                                  //
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

#include "freqtracker.h"

#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QThread>

#include <stdio.h>
#include <complex.h>

#include "SWGChannelSettings.h"
#include "SWGFreqTrackerSettings.h"
#include "SWGChannelReport.h"
#include "SWGFreqTrackerReport.h"

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "dsp/fftfilt.h"
#include "dsp/devicesamplemimo.h"
#include "device/deviceapi.h"
#include "util/db.h"
#include "util/stepfunctions.h"
#include "feature/feature.h"
#include "maincore.h"

#include "freqtrackerreport.h"

MESSAGE_CLASS_DEFINITION(FreqTracker::MsgConfigureFreqTracker, Message)

const char* const FreqTracker::m_channelIdURI = "rpx-100.channel.freqtracker";
const char* const FreqTracker::m_channelId = "FreqTracker";
const int FreqTracker::m_udpBlockSize = 512;

FreqTracker::FreqTracker(DeviceAPI *deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_spectrumVis(SDR_RX_SCALEF),
        m_basebandSampleRate(0)
{
    setObjectName(m_channelId);

    m_thread = new QThread(this);
    m_basebandSink = new FreqTrackerBaseband();
    m_basebandSink->setSpectrumSink(&m_spectrumVis);
    propagateMessageQueue(getInputMessageQueue());
    m_basebandSink->moveToThread(m_thread);

	applySettings(m_settings, true);

    m_deviceAPI->addChannelSink(this);
    m_deviceAPI->addChannelSinkAPI(this);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

FreqTracker::~FreqTracker()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;

    m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);
    delete m_basebandSink;
    delete m_thread;
}

uint32_t FreqTracker::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void FreqTracker::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool firstOfBurst)
{
    (void) firstOfBurst;
    m_basebandSink->feed(begin, end);
}

void FreqTracker::start()
{
	qDebug("FreqTracker::start");

    if (m_basebandSampleRate != 0) {
        m_basebandSink->setBasebandSampleRate(m_basebandSampleRate);
    }

    m_basebandSink->reset();
    m_thread->start();
}

void FreqTracker::stop()
{
    qDebug("FreqTracker::stop");
	m_thread->exit();
	m_thread->wait();
}

bool FreqTracker::handleMessage(const Message& cmd)
{
    if (DSPSignalNotification::match(cmd))
    {
        DSPSignalNotification& notif = (DSPSignalNotification&) cmd;
        m_basebandSampleRate = notif.getSampleRate();
        // Forward to the sink
        DSPSignalNotification* rep = new DSPSignalNotification(notif); // make a copy
        qDebug() << "FreqTracker::handleMessage: DSPSignalNotification";
        m_basebandSink->getInputMessageQueue()->push(rep);

        if (getMessageQueueToGUI())
        {
            DSPSignalNotification *msg = new DSPSignalNotification(notif);
            getMessageQueueToGUI()->push(msg);
        }

        return true;
    }
	else if (MsgConfigureFreqTracker::match(cmd))
	{
        MsgConfigureFreqTracker& cfg = (MsgConfigureFreqTracker&) cmd;
        qDebug() << "FreqTracker::handleMessage: MsgConfigureFreqTracker";
        applySettings(cfg.getSettings(), cfg.getForce());

		return true;
	}
    else if (FreqTrackerReport::MsgSinkFrequencyOffsetNotification::match(cmd))
    {
        FreqTrackerReport::MsgSinkFrequencyOffsetNotification& cfg = (FreqTrackerReport::MsgSinkFrequencyOffsetNotification&) cmd;
        FreqTrackerSettings settings = m_settings;
        settings.m_inputFrequencyOffset = cfg.getFrequencyOffset();
        applySettings(settings, false);

        if (getMessageQueueToGUI())
        {
            FreqTrackerReport::MsgSinkFrequencyOffsetNotification *msg = new FreqTrackerReport::MsgSinkFrequencyOffsetNotification(cfg);
            getMessageQueueToGUI()->push(msg);
        }

        return true;
    }
	else
	{
		return false;
	}
}

void FreqTracker::applySettings(const FreqTrackerSettings& settings, bool force)
{
    if (!settings.m_tracking)
    {
        qDebug() << "FreqTracker::applySettings:"
                << " m_inputFrequencyOffset: " << settings.m_inputFrequencyOffset
                << " m_rfBandwidth: " << settings.m_rfBandwidth
                << " m_log2Decim: " << settings.m_log2Decim
                << " m_squelch: " << settings.m_squelch
                << " m_rgbColor: " << settings.m_rgbColor
                << " m_title: " << settings.m_title
                << " m_alphaEMA: " << settings.m_alphaEMA
                << " m_tracking: " << settings.m_tracking
                << " m_trackerType: " << settings.m_trackerType
                << " m_pllPskOrder: " << settings.m_pllPskOrder
                << " m_rrc: " << settings.m_rrc
                << " m_rrcRolloff: " << settings.m_rrcRolloff
                << " m_streamIndex: " << settings.m_streamIndex
                << " m_spanLog2: " << settings.m_spanLog2
                << " m_useReverseAPI: " << settings.m_useReverseAPI
                << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
                << " m_reverseAPIPort: " << settings.m_reverseAPIPort
                << " m_reverseAPIDeviceIndex: " << settings.m_reverseAPIDeviceIndex
                << " m_reverseAPIChannelIndex: " << settings.m_reverseAPIChannelIndex
                << " force: " << force;
    }

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_inputFrequencyOffset != settings.m_inputFrequencyOffset) || force) {
        reverseAPIKeys.append("inputFrequencyOffset");
    }
    if ((m_settings.m_log2Decim != settings.m_log2Decim) || force) {
        reverseAPIKeys.append("log2Decim");
    }
    if ((m_settings.m_rfBandwidth != settings.m_rfBandwidth) || force) {
        reverseAPIKeys.append("rfBandwidth");
    }
    if ((m_settings.m_squelch != settings.m_squelch) || force) {
        reverseAPIKeys.append("squelch");
    }
    if ((m_settings.m_rgbColor != settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }
    if ((m_settings.m_title != settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((m_settings.m_alphaEMA != settings.m_alphaEMA) || force) {
        reverseAPIKeys.append("alphaEMA");
    }
    if ((m_settings.m_spanLog2 != settings.m_spanLog2) || force) {
        reverseAPIKeys.append("spanLog2");
    }
    if ((m_settings.m_tracking != settings.m_tracking) || force) {
        reverseAPIKeys.append("tracking");
    }
    if ((m_settings.m_trackerType != settings.m_trackerType) || force) {
        reverseAPIKeys.append("trackerType");
    }
    if ((m_settings.m_pllPskOrder != settings.m_pllPskOrder) || force) {
        reverseAPIKeys.append("pllPskOrder");
    }
    if ((m_settings.m_rrc != settings.m_rrc) || force) {
        reverseAPIKeys.append("rrc");
    }
    if ((m_settings.m_rrcRolloff != settings.m_rrcRolloff) || force) {
        reverseAPIKeys.append("rrcRolloff");
    }
    if ((m_settings.m_squelchGate != settings.m_squelchGate) || force) {
        reverseAPIKeys.append("squelchGate");
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

    FreqTrackerBaseband::MsgConfigureFreqTrackerBaseband *msg = FreqTrackerBaseband::MsgConfigureFreqTrackerBaseband::create(settings, force);
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


QByteArray FreqTracker::serialize() const
{
    return m_settings.serialize();
}

bool FreqTracker::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureFreqTracker *msg = MsgConfigureFreqTracker::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureFreqTracker *msg = MsgConfigureFreqTracker::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

int FreqTracker::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setFreqTrackerSettings(new SWGRPX100::SWGFreqTrackerSettings());
    response.getFreqTrackerSettings()->init();
    webapiFormatChannelSettings(response, m_settings);
    return 200;
}

int FreqTracker::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    FreqTrackerSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigureFreqTracker *msg = MsgConfigureFreqTracker::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("FreqTracker::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureFreqTracker *msgToGUI = MsgConfigureFreqTracker::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void FreqTracker::webapiUpdateChannelSettings(
        FreqTrackerSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getFreqTrackerSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("rfBandwidth")) {
        settings.m_rfBandwidth = response.getFreqTrackerSettings()->getRfBandwidth();
    }
    if (channelSettingsKeys.contains("log2Decim")) {
        settings.m_log2Decim = response.getFreqTrackerSettings()->getLog2Decim();
    }
    if (channelSettingsKeys.contains("squelch")) {
        settings.m_squelch = response.getFreqTrackerSettings()->getSquelch();
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getFreqTrackerSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getFreqTrackerSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("spanLog2")) {
        settings.m_spanLog2 = response.getFreqTrackerSettings()->getSpanLog2();
    }
    if (channelSettingsKeys.contains("alphaEMA")) {
        float alphaEMA =  response.getFreqTrackerSettings()->getAlphaEma();
        settings.m_alphaEMA = alphaEMA < 0.01 ? 0.01 : alphaEMA > 1.0 ? 1.0 : alphaEMA;
    }
    if (channelSettingsKeys.contains("tracking")) {
        settings.m_tracking = response.getFreqTrackerSettings()->getTracking() ? 1 : 0;
    }
    if (channelSettingsKeys.contains("trackerType"))
    {
        int32_t trackerTypeCode = response.getFreqTrackerSettings()->getTrackerType();
        settings.m_trackerType = trackerTypeCode < 0 ?
            FreqTrackerSettings::TrackerFLL : trackerTypeCode > 1 ?
                FreqTrackerSettings::TrackerPLL : (FreqTrackerSettings::TrackerType) trackerTypeCode;
    }
    if (channelSettingsKeys.contains("pllPskOrder")) {
        settings.m_pllPskOrder = response.getFreqTrackerSettings()->getPllPskOrder();
    }
    if (channelSettingsKeys.contains("rrc")) {
        settings.m_rrc = response.getFreqTrackerSettings()->getRrc() ? 1 : 0;
    }
    if (channelSettingsKeys.contains("rrcRolloff")) {
        settings.m_rrcRolloff = response.getFreqTrackerSettings()->getRrcRolloff();
    }
    if (channelSettingsKeys.contains("squelchGate")) {
        settings.m_squelchGate = response.getFreqTrackerSettings()->getSquelchGate();
    }
    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getFreqTrackerSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getFreqTrackerSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getFreqTrackerSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getFreqTrackerSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getFreqTrackerSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getFreqTrackerSettings()->getReverseApiChannelIndex();
    }
}

int FreqTracker::webapiReportGet(
        SWGRPX100::SWGChannelReport& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setFreqTrackerReport(new SWGRPX100::SWGFreqTrackerReport());
    response.getFreqTrackerReport()->init();
    webapiFormatChannelReport(response);
    return 200;
}

void FreqTracker::webapiFormatChannelSettings(SWGRPX100::SWGChannelSettings& response, const FreqTrackerSettings& settings)
{
    response.getFreqTrackerSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getFreqTrackerSettings()->setRfBandwidth(settings.m_rfBandwidth);
    response.getFreqTrackerSettings()->setLog2Decim(settings.m_log2Decim);
    response.getFreqTrackerSettings()->setSquelch(settings.m_squelch);
    response.getFreqTrackerSettings()->setRgbColor(settings.m_rgbColor);

    if (response.getFreqTrackerSettings()->getTitle()) {
        *response.getFreqTrackerSettings()->getTitle() = settings.m_title;
    } else {
        response.getFreqTrackerSettings()->setTitle(new QString(settings.m_title));
    }

    response.getFreqTrackerSettings()->setSpanLog2(settings.m_spanLog2);
    response.getFreqTrackerSettings()->setAlphaEma(settings.m_alphaEMA);
    response.getFreqTrackerSettings()->setTracking(settings.m_tracking ? 1 : 0);
    response.getFreqTrackerSettings()->setTrackerType((int) settings.m_trackerType);
    response.getFreqTrackerSettings()->setPllPskOrder(settings.m_pllPskOrder);
    response.getFreqTrackerSettings()->setRrc(settings.m_rrc ? 1 : 0);
    response.getFreqTrackerSettings()->setRrcRolloff(settings.m_rrcRolloff);
    response.getFreqTrackerSettings()->setSquelchGate(settings.m_squelchGate);
    response.getFreqTrackerSettings()->setStreamIndex(settings.m_streamIndex);
    response.getFreqTrackerSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getFreqTrackerSettings()->getReverseApiAddress()) {
        *response.getFreqTrackerSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getFreqTrackerSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getFreqTrackerSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getFreqTrackerSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getFreqTrackerSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void FreqTracker::webapiFormatChannelReport(SWGRPX100::SWGChannelReport& response)
{
    double magsqAvg, magsqPeak;
    int nbMagsqSamples;
    getMagSqLevels(magsqAvg, magsqPeak, nbMagsqSamples);

    response.getFreqTrackerReport()->setChannelPowerDb(CalcDb::dbPower(magsqAvg));
    response.getFreqTrackerReport()->setSquelch(m_basebandSink->getSquelchOpen() ? 1 : 0);
    response.getFreqTrackerReport()->setSampleRate(m_basebandSink->getSampleRate());
    response.getFreqTrackerReport()->setChannelSampleRate(m_basebandSink->getChannelSampleRate());
    response.getFreqTrackerReport()->setTrackingDeltaFrequency(getAvgDeltaFreq());
}

void FreqTracker::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const FreqTrackerSettings& settings, bool force)
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

void FreqTracker::sendChannelSettings(
    QList<MessageQueue*> *messageQueues,
    QList<QString>& channelSettingsKeys,
    const FreqTrackerSettings& settings,
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

void FreqTracker::webapiFormatChannelSettings(
    QList<QString>& channelSettingsKeys,
    SWGRPX100::SWGChannelSettings *swgChannelSettings,
    const FreqTrackerSettings& settings,
    bool force)
{
    swgChannelSettings->setDirection(0); // single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString("FreqTracker"));
    swgChannelSettings->setFreqTrackerSettings(new SWGRPX100::SWGFreqTrackerSettings());
    SWGRPX100::SWGFreqTrackerSettings *swgFreqTrackerSettings = swgChannelSettings->getFreqTrackerSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgFreqTrackerSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("rfBandwidth") || force) {
        swgFreqTrackerSettings->setRfBandwidth(settings.m_rfBandwidth);
    }
    if (channelSettingsKeys.contains("log2Decim") || force) {
        swgFreqTrackerSettings->setLog2Decim(settings.m_log2Decim);
    }
    if (channelSettingsKeys.contains("squelch") || force) {
        swgFreqTrackerSettings->setSquelch(settings.m_squelch);
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgFreqTrackerSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgFreqTrackerSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("spanLog2") || force) {
        swgFreqTrackerSettings->setSpanLog2(settings.m_spanLog2);
    }
    if (channelSettingsKeys.contains("alphaEMA") || force) {
        swgFreqTrackerSettings->setAlphaEma(settings.m_alphaEMA);
    }
    if (channelSettingsKeys.contains("tracking") || force) {
        swgFreqTrackerSettings->setTracking(settings.m_tracking ? 1 : 0);
    }
    if (channelSettingsKeys.contains("trackerType") || force) {
        swgFreqTrackerSettings->setTrackerType((int) settings.m_trackerType);
    }
    if (channelSettingsKeys.contains("pllPskOrder") || force) {
        swgFreqTrackerSettings->setPllPskOrder(settings.m_pllPskOrder);
    }
    if (channelSettingsKeys.contains("rrc") || force) {
        swgFreqTrackerSettings->setRrc(settings.m_rrc ? 1 : 0);
    }
    if (channelSettingsKeys.contains("rrcRolloff") || force) {
        swgFreqTrackerSettings->setRrcRolloff(settings.m_rrcRolloff);
    }
    if (channelSettingsKeys.contains("squelchGate") || force) {
        swgFreqTrackerSettings->setSquelchGate(settings.m_squelchGate);
    }
    if (channelSettingsKeys.contains("streamIndex") || force) {
        swgFreqTrackerSettings->setStreamIndex(settings.m_streamIndex);
    }
}

void FreqTracker::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "FreqTracker::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("FreqTracker::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
