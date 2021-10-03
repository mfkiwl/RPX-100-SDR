///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Bernhard Isemann, oe3bia                                   //
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

#include <string.h>
#include <errno.h>

#include <QDebug>
#include <QNetworkReply>
#include <QBuffer>

#include "SWGDeviceSettings.h"
#include "SWGDeviceState.h"
#include "SWGDeviceReport.h"
#include "SWGSDRPlayReport.h"

#include "util/simpleserializer.h"
#include "dsp/dspcommands.h"
#include "dsp/dspengine.h"
#include "sdrplayinput.h"

#include <device/deviceapi.h>

#include "sdrplaythread.h"

MESSAGE_CLASS_DEFINITION(SDRPlayInput::MsgConfigureSDRPlay, Message)
MESSAGE_CLASS_DEFINITION(SDRPlayInput::MsgReportSDRPlayGains, Message)
MESSAGE_CLASS_DEFINITION(SDRPlayInput::MsgStartStop, Message)

SDRPlayInput::SDRPlayInput(DeviceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
    m_variant(SDRPlayUndef),
    m_settings(),
	m_dev(0),
    m_sdrPlayThread(nullptr),
    m_deviceDescription("SDRPlay"),
    m_devNumber(0),
    m_running(false)
{
    openDevice();
    m_deviceAPI->setNbSourceStreams(1);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

SDRPlayInput::~SDRPlayInput()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;

    if (m_running) {
        stop();
    }

    closeDevice();
}

void SDRPlayInput::destroy()
{
    delete this;
}

bool SDRPlayInput::openDevice()
{
    m_devNumber = m_deviceAPI->getSamplingDeviceSequence();

    if (m_dev != 0)
    {
        closeDevice();
    }

    int res;
    //int numberOfGains;

    if (!m_sampleFifo.setSize(96000 * 4))
    {
        qCritical("SDRPlayInput::openDevice: could not allocate SampleFifo");
        return false;
    }

    if ((res = mirisdr_open(&m_dev, MIRISDR_HW_SDRPLAY, m_devNumber)) < 0)
    {
        qCritical("SDRPlayInput::openDevice: could not open SDRPlay #%d: %s", m_devNumber, strerror(errno));
        return false;
    }

    char vendor[256];
    char product[256];
    char serial[256];

    vendor[0] = '\0';
    product[0] = '\0';
    serial[0] = '\0';

    if ((res = mirisdr_get_device_usb_strings(m_devNumber, vendor, product, serial)) < 0)
    {
        qCritical("SDRPlayInput::openDevice: error accessing USB device");
        stop();
        return false;
    }

    qWarning("SDRPlayInput::openDevice: %s %s, SN: %s", vendor, product, serial);
    m_deviceDescription = QString("%1 (SN %2)").arg(product).arg(serial);

    if (QString(product) == "RSP1A") {
        m_variant = SDRPlayRSP1A;
    } else if (QString(product) == "RSP2") {
        m_variant = SDRPlayRSP2;
    } else {
        m_variant = SDRPlayRSP1;
    }

    qDebug("SDRPlayInput::openDevice: m_variant: %d", (int) m_variant);

    return true;
}

bool SDRPlayInput::start()
{
//    QMutexLocker mutexLocker(&m_mutex);
    int res;

    if (!m_dev) {
        return false;
    }

    if (m_running) stop();

	char s12FormatString[] = "336_S16";

	if ((res = mirisdr_set_sample_format(m_dev, s12FormatString))) // sample format S12
	{
		qCritical("SDRPlayInput::start: could not set sample format: rc: %d", res);
		stop();
		return false;
	}

	int sampleRate = SDRPlaySampleRates::getRate(m_settings.m_devSampleRateIndex);

	if ((res = mirisdr_set_sample_rate(m_dev, sampleRate)))
    {
        qCritical("SDRPlayInput::start: could not set sample rate to %d: rc: %d", sampleRate, res);
        stop();
        return false;
    }

    char bulkFormatString[] = "BULK";

	if ((res = mirisdr_set_transfer(m_dev, bulkFormatString)) < 0)
	{
		qCritical("SDRPlayInput::start: could not set USB Bulk mode: rc: %d", res);
		stop();
		return false;
	}

	if ((res = mirisdr_reset_buffer(m_dev)) < 0)
	{
		qCritical("SDRPlayInput::start: could not reset USB EP buffers: %s", strerror(errno));
		stop();
		return false;
	}

	m_sdrPlayThread = new SDRPlayThread(m_dev, &m_sampleFifo);
    m_sdrPlayThread->setLog2Decimation(m_settings.m_log2Decim);
    m_sdrPlayThread->setFcPos((int) m_settings.m_fcPos);
    m_sdrPlayThread->setIQOrder(m_settings.m_iqOrder);
    m_sdrPlayThread->startWork();

//	mutexLocker.unlock();

	applySettings(m_settings, true, true);
	m_running = true;

	return true;
}

void SDRPlayInput::closeDevice()
{
    if (m_dev != 0)
    {
        mirisdr_close(m_dev);
        m_dev = 0;
    }

    m_deviceDescription.clear();
}

void SDRPlayInput::init()
{
    applySettings(m_settings, true, true);
}

void SDRPlayInput::stop()
{
//    QMutexLocker mutexLocker(&m_mutex);

    if(m_sdrPlayThread)
    {
        m_sdrPlayThread->stopWork();
        delete m_sdrPlayThread;
        m_sdrPlayThread = nullptr;
    }

    m_running = false;
}

QByteArray SDRPlayInput::serialize() const
{
    return m_settings.serialize();
}

bool SDRPlayInput::deserialize(const QByteArray& data)
{
    bool success = true;

    if (!m_settings.deserialize(data))
    {
        m_settings.resetToDefaults();
        success = false;
    }

    MsgConfigureSDRPlay* message = MsgConfigureSDRPlay::create(m_settings, true);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureSDRPlay* messageToGUI = MsgConfigureSDRPlay::create(m_settings, true);
        m_guiMessageQueue->push(messageToGUI);
    }

    return success;
}

const QString& SDRPlayInput::getDeviceDescription() const
{
    return m_deviceDescription;
}

int SDRPlayInput::getSampleRate() const
{
    int rate = SDRPlaySampleRates::getRate(m_settings.m_devSampleRateIndex);
    return rate / (1<<m_settings.m_log2Decim);
}

quint64 SDRPlayInput::getCenterFrequency() const
{
    return m_settings.m_centerFrequency;
}

void SDRPlayInput::setCenterFrequency(qint64 centerFrequency)
{
    SDRPlaySettings settings = m_settings;
    settings.m_centerFrequency = centerFrequency;

    MsgConfigureSDRPlay* message = MsgConfigureSDRPlay::create(settings, false);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureSDRPlay* messageToGUI = MsgConfigureSDRPlay::create(settings, false);
        m_guiMessageQueue->push(messageToGUI);
    }
}

bool SDRPlayInput::handleMessage(const Message& message)
{
    if (MsgConfigureSDRPlay::match(message))
    {
        MsgConfigureSDRPlay& conf = (MsgConfigureSDRPlay&) message;
        qDebug() << "SDRPlayInput::handleMessage: MsgConfigureSDRPlay";
        const SDRPlaySettings& settings = conf.getSettings();

        // change of sample rate needs full stop / start sequence that includes the standard apply settings
        // only if in started state (iff m_dev != 0)
        if ((m_dev != 0) && (m_settings.m_devSampleRateIndex != settings.m_devSampleRateIndex))
        {
            m_settings = settings;
            stop();
            start();
        }
        // standard changes
        else
        {
            if (!applySettings(settings, false, conf.getForce()))
            {
                qDebug("SDRPlayInput::handleMessage: config error");
            }
        }

        return true;
    }
    else if (MsgStartStop::match(message))
    {
        MsgStartStop& cmd = (MsgStartStop&) message;
        qDebug() << "SDRPlayInput::handleMessage: MsgStartStop: " << (cmd.getStartStop() ? "start" : "stop");

        if (cmd.getStartStop())
        {
            if (m_deviceAPI->initDeviceEngine())
            {
                m_deviceAPI->startDeviceEngine();
            }
        }
        else
        {
            m_deviceAPI->stopDeviceEngine();
        }

        if (m_settings.m_useReverseAPI) {
            webapiReverseSendStartStop(cmd.getStartStop());
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool SDRPlayInput::applySettings(const SDRPlaySettings& settings, bool forwardChange, bool force)
{
    bool forceGainSetting = false;
    QList<QString> reverseAPIKeys;
    QMutexLocker mutexLocker(&m_mutex);

    if ((m_settings.m_dcBlock != settings.m_dcBlock) || force)
    {
        reverseAPIKeys.append("dcBlock");
        m_deviceAPI->configureCorrections(settings.m_dcBlock, settings.m_iqCorrection);
    }

    if ((m_settings.m_iqCorrection != settings.m_iqCorrection) || force)
    {
        reverseAPIKeys.append("iqCorrection");
        m_deviceAPI->configureCorrections(settings.m_dcBlock, settings.m_iqCorrection);
    }

    // gains processing

    if ((m_settings.m_tunerGainMode != settings.m_tunerGainMode) || force)
    {
        reverseAPIKeys.append("tunerGainMode");
        forceGainSetting = true;
    }

    if ((m_settings.m_tunerGain != settings.m_tunerGain) || force) {
        reverseAPIKeys.append("tunerGain");
    }
    if ((m_settings.m_lnaOn != settings.m_lnaOn) || force) {
        reverseAPIKeys.append("lnaOn");
    }

    if (settings.m_tunerGainMode) // auto
    {
        if ((m_settings.m_tunerGain != settings.m_tunerGain) || forceGainSetting)
        {
            if(m_dev != 0)
            {
                int r = mirisdr_set_tuner_gain(m_dev, settings.m_tunerGain);

                if (r < 0)
                {
                    qDebug("SDRPlayInput::applySettings: could not set tuner gain");
                }
                else
                {
                    int lnaGain;

                    if (settings.m_frequencyBandIndex < 3) // bands using AM mode
                    {
                        lnaGain = mirisdr_get_mixbuffer_gain(m_dev);
                    }
                    else
                    {
                        lnaGain = mirisdr_get_lna_gain(m_dev);
                    }

                    MsgReportSDRPlayGains *message = MsgReportSDRPlayGains::create(
                            lnaGain,
                            mirisdr_get_mixer_gain(m_dev),
                            mirisdr_get_baseband_gain(m_dev),
                            mirisdr_get_tuner_gain(m_dev)
                    );

                    if (getMessageQueueToGUI()) {
                        getMessageQueueToGUI()->push(message);
                    }
                }
            }
        }
    }
    else // manual
    {
        bool anyChange = false;

        if ((m_settings.m_lnaOn != settings.m_lnaOn) || forceGainSetting)
        {
            if (m_dev != 0)
            {
                if (settings.m_frequencyBandIndex < 3) // bands using AM mode
                {
                    int r = mirisdr_set_mixbuffer_gain(m_dev, settings.m_lnaOn ? 0 : 1); // mirisdr_set_mixbuffer_gain takes gain reduction

                    if (r != 0) {
                        qDebug("SDRPlayInput::applySettings: could not set mixer buffer gain");
                    } else {
                        anyChange = true;
                    }
                }
                else
                {
                    int r = mirisdr_set_lna_gain(m_dev, settings.m_lnaOn ? 0 : 1); // mirisdr_set_lna_gain takes gain reduction

                    if (r != 0) {
                        qDebug("SDRPlayInput::applySettings: could not set LNA gain");
                    } else {
                        anyChange = true;
                    }
                }
            }
        }

        if ((m_settings.m_mixerAmpOn != settings.m_mixerAmpOn) || forceGainSetting)
        {
            reverseAPIKeys.append("mixerAmpOn");

            if (m_dev != 0)
            {
                int r = mirisdr_set_mixer_gain(m_dev, settings.m_mixerAmpOn ? 0 : 1); // mirisdr_set_lna_gain takes gain reduction

                if (r != 0) {
                    qDebug("SDRPlayInput::applySettings: could not set mixer gain");
                } else {
                    anyChange = true;
                }
            }
        }

        if ((m_settings.m_basebandGain != settings.m_basebandGain) || forceGainSetting)
        {
            reverseAPIKeys.append("basebandGain");

            if (m_dev != 0)
            {
                int r = mirisdr_set_baseband_gain(m_dev, settings.m_basebandGain);

                if (r != 0) {
                    qDebug("SDRPlayInput::applySettings: could not set mixer gain");
                } else {
                    anyChange = true;
                }
            }
        }

        if (anyChange)
        {
            int lnaGain;

            if (settings.m_frequencyBandIndex < 3) { // bands using AM mode
                lnaGain = mirisdr_get_mixbuffer_gain(m_dev);
            } else {
                lnaGain = mirisdr_get_lna_gain(m_dev);
            }

            MsgReportSDRPlayGains *message = MsgReportSDRPlayGains::create(
                    lnaGain,
                    mirisdr_get_mixer_gain(m_dev),
                    mirisdr_get_baseband_gain(m_dev),
                    mirisdr_get_tuner_gain(m_dev)
            );

            if (getMessageQueueToGUI()) {
                getMessageQueueToGUI()->push(message);
            }
        }
    }

    if ((m_settings.m_log2Decim != settings.m_log2Decim) || force)
    {
        reverseAPIKeys.append("log2Decim");

        if (m_sdrPlayThread)
        {
            m_sdrPlayThread->setLog2Decimation(settings.m_log2Decim);
            qDebug() << "SDRPlayInput::applySettings: set decimation to " << (1<<settings.m_log2Decim);
        }
    }

    if ((m_settings.m_fcPos != settings.m_fcPos) || force)
    {
        reverseAPIKeys.append("fcPos");

        if (m_sdrPlayThread)
        {
            m_sdrPlayThread->setFcPos((int) settings.m_fcPos);
            qDebug() << "SDRPlayInput: set fc pos (enum) to " << (int) settings.m_fcPos;
        }
    }

    if ((m_settings.m_iqOrder != settings.m_iqOrder) || force)
    {
        reverseAPIKeys.append("iqOrder");

        if (m_sdrPlayThread)
        {
            m_sdrPlayThread->setIQOrder((int) settings.m_iqOrder);
            qDebug() << "SDRPlayInput: set IQ order to " << (settings.m_iqOrder ? "IQ" : "QI");
        }
    }

    if ((m_settings.m_centerFrequency != settings.m_centerFrequency) || force) {
        reverseAPIKeys.append("centerFrequency");
    }
    if ((m_settings.m_LOppmTenths != settings.m_LOppmTenths) || force) {
        reverseAPIKeys.append("LOppmTenths");
    }

    if ((m_settings.m_centerFrequency != settings.m_centerFrequency)
        || (m_settings.m_LOppmTenths != settings.m_LOppmTenths)
        || (m_settings.m_fcPos != settings.m_fcPos)
        || (m_settings.m_log2Decim != settings.m_log2Decim) || force)
    {
        qint64 deviceCenterFrequency = DeviceSampleSource::calculateDeviceCenterFrequency(
                settings.m_centerFrequency,
                0,
                settings.m_log2Decim,
                (DeviceSampleSource::fcPos_t) settings.m_fcPos,
                SDRPlaySampleRates::getRate(settings.m_devSampleRateIndex),
                DeviceSampleSource::FrequencyShiftScheme::FSHIFT_STD,
                false);

        forwardChange = true;

        if(m_dev != 0)
        {
            if (setDeviceCenterFrequency(deviceCenterFrequency)) {
                qDebug() << "SDRPlayInput::applySettings: center freq: " << settings.m_centerFrequency << " Hz";
            }
        }
    }

    if ((m_settings.m_bandwidthIndex != settings.m_bandwidthIndex) || force)
    {
        reverseAPIKeys.append("bandwidthIndex");
        int bandwidth = SDRPlayBandwidths::getBandwidth(settings.m_bandwidthIndex);
        int r = mirisdr_set_bandwidth(m_dev, bandwidth);

        if (r < 0) {
            qCritical("SDRPlayInput::applySettings: set bandwidth %d failed: rc: %d", bandwidth, r);
        } else {
            qDebug("SDRPlayInput::applySettings: bandwidth set to %d", bandwidth);
        }
    }

    if ((m_settings.m_ifFrequencyIndex != settings.m_ifFrequencyIndex) || force)
    {
        reverseAPIKeys.append("ifFrequencyIndex");
        int iFFrequency = SDRPlayIF::getIF(settings.m_ifFrequencyIndex);
        int r = mirisdr_set_if_freq(m_dev, iFFrequency);

        if (r < 0) {
            qCritical("SDRPlayInput::applySettings: set IF frequency to %d failed: rc: %d", iFFrequency, r);
        } else {
            qDebug("SDRPlayInput::applySettings: IF frequency set to %d", iFFrequency);
        }
    }

    if (settings.m_useReverseAPI)
    {
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIDeviceIndex != settings.m_reverseAPIDeviceIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    m_settings = settings;

    if (forwardChange)
    {
        int sampleRate = getSampleRate();
        DSPSignalNotification *notif = new DSPSignalNotification(sampleRate, m_settings.m_centerFrequency);
        m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);
    }

    return true;
}

bool SDRPlayInput::setDeviceCenterFrequency(quint64 freq_hz)
{
    qint64 df = ((qint64)freq_hz * m_settings.m_LOppmTenths) / 10000000LL;
    freq_hz += df;

    int r = mirisdr_set_center_freq(m_dev, static_cast<uint32_t>(freq_hz));

    if (r != 0)
    {
        qWarning("SDRPlayInput::setDeviceCenterFrequency: could not frequency to %llu Hz", freq_hz);
        return false;
    }
    else
    {
        qWarning("SDRPlayInput::setDeviceCenterFrequency: frequency set to %llu Hz", freq_hz);
        return true;
    }
}

int SDRPlayInput::webapiRunGet(
        SWGRPX100::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    return 200;
}

int SDRPlayInput::webapiRun(
        bool run,
        SWGRPX100::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    MsgStartStop *message = MsgStartStop::create(run);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgStartStop *msgToGUI = MsgStartStop::create(run);
        m_guiMessageQueue->push(msgToGUI);
    }

    return 200;
}

int SDRPlayInput::webapiSettingsGet(
                SWGRPX100::SWGDeviceSettings& response,
                QString& errorMessage)
{
    (void) errorMessage;
    response.setSdrPlaySettings(new SWGRPX100::SWGSDRPlaySettings());
    response.getSdrPlaySettings()->init();
    webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int SDRPlayInput::webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGRPX100::SWGDeviceSettings& response, // query + response
                QString& errorMessage)
{
    (void) errorMessage;
    SDRPlaySettings settings = m_settings;
    webapiUpdateDeviceSettings(settings, deviceSettingsKeys, response);

    MsgConfigureSDRPlay *msg = MsgConfigureSDRPlay::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureSDRPlay *msgToGUI = MsgConfigureSDRPlay::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatDeviceSettings(response, settings);
    return 200;
}

void SDRPlayInput::webapiUpdateDeviceSettings(
        SDRPlaySettings& settings,
        const QStringList& deviceSettingsKeys,
        SWGRPX100::SWGDeviceSettings& response)
{
    if (deviceSettingsKeys.contains("centerFrequency")) {
        settings.m_centerFrequency = response.getSdrPlaySettings()->getCenterFrequency();
    }
    if (deviceSettingsKeys.contains("tunerGain")) {
        settings.m_tunerGain = response.getSdrPlaySettings()->getTunerGain();
    }
    if (deviceSettingsKeys.contains("LOppmTenths")) {
        settings.m_LOppmTenths = response.getSdrPlaySettings()->getLOppmTenths();
    }
    if (deviceSettingsKeys.contains("frequencyBandIndex")) {
        settings.m_frequencyBandIndex = response.getSdrPlaySettings()->getFrequencyBandIndex();
    }
    if (deviceSettingsKeys.contains("ifFrequencyIndex")) {
        settings.m_ifFrequencyIndex = response.getSdrPlaySettings()->getIfFrequencyIndex();
    }
    if (deviceSettingsKeys.contains("bandwidthIndex")) {
        settings.m_bandwidthIndex = response.getSdrPlaySettings()->getBandwidthIndex();
    }
    if (deviceSettingsKeys.contains("devSampleRateIndex")) {
        settings.m_devSampleRateIndex = response.getSdrPlaySettings()->getDevSampleRateIndex();
    }
    if (deviceSettingsKeys.contains("log2Decim")) {
        settings.m_log2Decim = response.getSdrPlaySettings()->getLog2Decim();
    }
    if (deviceSettingsKeys.contains("iqOrder")) {
        settings.m_iqOrder = response.getSdrPlaySettings()->getIqOrder() != 0;
    }
    if (deviceSettingsKeys.contains("fcPos"))
    {
        int fcPos = response.getSdrPlaySettings()->getFcPos();
        fcPos = fcPos < 0 ? 0 : fcPos > 2 ? 2 : fcPos;
        settings.m_fcPos = (SDRPlaySettings::fcPos_t) fcPos;
    }
    if (deviceSettingsKeys.contains("dcBlock")) {
        settings.m_dcBlock = response.getSdrPlaySettings()->getDcBlock() != 0;
    }
    if (deviceSettingsKeys.contains("iqCorrection")) {
        settings.m_iqCorrection = response.getSdrPlaySettings()->getIqCorrection() != 0;
    }
    if (deviceSettingsKeys.contains("tunerGainMode")) {
        settings.m_tunerGainMode = response.getSdrPlaySettings()->getTunerGainMode() != 0;
    }
    if (deviceSettingsKeys.contains("lnaOn")) {
        settings.m_lnaOn = response.getSdrPlaySettings()->getLnaOn() != 0;
    }
    if (deviceSettingsKeys.contains("mixerAmpOn")) {
        settings.m_mixerAmpOn = response.getSdrPlaySettings()->getMixerAmpOn() != 0;
    }
    if (deviceSettingsKeys.contains("basebandGain")) {
        settings.m_basebandGain = response.getSdrPlaySettings()->getBasebandGain();
    }
    if (deviceSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getSdrPlaySettings()->getUseReverseApi() != 0;
    }
    if (deviceSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getSdrPlaySettings()->getReverseApiAddress();
    }
    if (deviceSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getSdrPlaySettings()->getReverseApiPort();
    }
    if (deviceSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getSdrPlaySettings()->getReverseApiDeviceIndex();
    }
}

void SDRPlayInput::webapiFormatDeviceSettings(SWGRPX100::SWGDeviceSettings& response, const SDRPlaySettings& settings)
{
    response.getSdrPlaySettings()->setCenterFrequency(settings.m_centerFrequency);
    response.getSdrPlaySettings()->setTunerGain(settings.m_tunerGain);
    response.getSdrPlaySettings()->setLOppmTenths(settings.m_LOppmTenths);
    response.getSdrPlaySettings()->setFrequencyBandIndex(settings.m_frequencyBandIndex);
    response.getSdrPlaySettings()->setIfFrequencyIndex(settings.m_ifFrequencyIndex);
    response.getSdrPlaySettings()->setBandwidthIndex(settings.m_bandwidthIndex);
    response.getSdrPlaySettings()->setDevSampleRateIndex(settings.m_devSampleRateIndex);
    response.getSdrPlaySettings()->setLog2Decim(settings.m_log2Decim);
    response.getSdrPlaySettings()->setIqOrder(settings.m_iqOrder ? 1 : 0);
    response.getSdrPlaySettings()->setFcPos((int) settings.m_fcPos);
    response.getSdrPlaySettings()->setDcBlock(settings.m_dcBlock ? 1 : 0);
    response.getSdrPlaySettings()->setIqCorrection(settings.m_iqCorrection ? 1 : 0);
    response.getSdrPlaySettings()->setTunerGainMode((int) settings.m_tunerGainMode);
    response.getSdrPlaySettings()->setLnaOn(settings.m_lnaOn ? 1 : 0);
    response.getSdrPlaySettings()->setMixerAmpOn(settings.m_mixerAmpOn ? 1 : 0);
    response.getSdrPlaySettings()->setBasebandGain(settings.m_basebandGain);

    response.getSdrPlaySettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getSdrPlaySettings()->getReverseApiAddress()) {
        *response.getSdrPlaySettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getSdrPlaySettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getSdrPlaySettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getSdrPlaySettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
}

int SDRPlayInput::webapiReportGet(
        SWGRPX100::SWGDeviceReport& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setSdrPlayReport(new SWGRPX100::SWGSDRPlayReport());
    response.getSdrPlayReport()->init();
    webapiFormatDeviceReport(response);
    return 200;
}

void SDRPlayInput::webapiFormatDeviceReport(SWGRPX100::SWGDeviceReport& response)
{
    response.getSdrPlayReport()->setSampleRates(new QList<SWGRPX100::SWGSampleRate*>);

    for (unsigned int i = 0; i < SDRPlaySampleRates::getNbRates(); i++)
    {
        response.getSdrPlayReport()->getSampleRates()->append(new SWGRPX100::SWGSampleRate);
        response.getSdrPlayReport()->getSampleRates()->back()->setRate(SDRPlaySampleRates::getRate(i));
    }

    response.getSdrPlayReport()->setIntermediateFrequencies(new QList<SWGRPX100::SWGFrequency*>);

    for (unsigned int i = 0; i < SDRPlayIF::getNbIFs(); i++)
    {
        response.getSdrPlayReport()->getIntermediateFrequencies()->append(new SWGRPX100::SWGFrequency);
        response.getSdrPlayReport()->getIntermediateFrequencies()->back()->setFrequency(SDRPlayIF::getIF(i));
    }

    response.getSdrPlayReport()->setBandwidths(new QList<SWGRPX100::SWGBandwidth*>);

    for (unsigned int i = 0; i < SDRPlayBandwidths::getNbBandwidths(); i++)
    {
        response.getSdrPlayReport()->getBandwidths()->append(new SWGRPX100::SWGBandwidth);
        response.getSdrPlayReport()->getBandwidths()->back()->setBandwidth(SDRPlayBandwidths::getBandwidth(i));
    }

    response.getSdrPlayReport()->setFrequencyBands(new QList<SWGRPX100::SWGFrequencyBand*>);

    for (unsigned int i = 0; i < SDRPlayBands::getNbBands(); i++)
    {
        response.getSdrPlayReport()->getFrequencyBands()->append(new SWGRPX100::SWGFrequencyBand);
        response.getSdrPlayReport()->getFrequencyBands()->back()->setName(new QString(SDRPlayBands::getBandName(i)));
        response.getSdrPlayReport()->getFrequencyBands()->back()->setLowerBound(SDRPlayBands::getBandLow(i));
        response.getSdrPlayReport()->getFrequencyBands()->back()->setHigherBound(SDRPlayBands::getBandHigh(i));
    }
}

void SDRPlayInput::webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const SDRPlaySettings& settings, bool force)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("SDRplay1"));
    swgDeviceSettings->setSdrPlaySettings(new SWGRPX100::SWGSDRPlaySettings());
    SWGRPX100::SWGSDRPlaySettings *swgSDRPlaySettings = swgDeviceSettings->getSdrPlaySettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (deviceSettingsKeys.contains("centerFrequency") || force) {
        swgSDRPlaySettings->setCenterFrequency(settings.m_centerFrequency);
    }
    if (deviceSettingsKeys.contains("tunerGain") || force) {
        swgSDRPlaySettings->setTunerGain(settings.m_tunerGain);
    }
    if (deviceSettingsKeys.contains("LOppmTenths") || force) {
        swgSDRPlaySettings->setLOppmTenths(settings.m_LOppmTenths);
    }
    if (deviceSettingsKeys.contains("frequencyBandIndex") || force) {
        swgSDRPlaySettings->setFrequencyBandIndex(settings.m_frequencyBandIndex);
    }
    if (deviceSettingsKeys.contains("ifFrequencyIndex") || force) {
        swgSDRPlaySettings->setIfFrequencyIndex(settings.m_ifFrequencyIndex);
    }
    if (deviceSettingsKeys.contains("bandwidthIndex") || force) {
        swgSDRPlaySettings->setBandwidthIndex(settings.m_bandwidthIndex);
    }
    if (deviceSettingsKeys.contains("devSampleRateIndex") || force) {
        swgSDRPlaySettings->setDevSampleRateIndex(settings.m_devSampleRateIndex);
    }
    if (deviceSettingsKeys.contains("log2Decim") || force) {
        swgSDRPlaySettings->setLog2Decim(settings.m_log2Decim);
    }
    if (deviceSettingsKeys.contains("iqOrder") || force) {
        swgSDRPlaySettings->setIqOrder(settings.m_iqOrder);
    }
    if (deviceSettingsKeys.contains("fcPos") || force) {
        swgSDRPlaySettings->setFcPos((int) settings.m_fcPos);
    }
    if (deviceSettingsKeys.contains("dcBlock") || force) {
        swgSDRPlaySettings->setDcBlock(settings.m_dcBlock ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("iqCorrection") || force) {
        swgSDRPlaySettings->setIqCorrection(settings.m_iqCorrection ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("tunerGainMode") || force) {
        swgSDRPlaySettings->setTunerGainMode(settings.m_tunerGainMode ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("lnaOn") || force) {
        swgSDRPlaySettings->setLnaOn(settings.m_lnaOn ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("mixerAmpOn") || force) {
        swgSDRPlaySettings->setMixerAmpOn(settings.m_mixerAmpOn ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("basebandGain") || force) {
        swgSDRPlaySettings->setBasebandGain(settings.m_basebandGain);
    }

    QString deviceSettingsURL = QString("http://%1:%2/RPX100/deviceset/%3/device/settings")
            .arg(settings.m_reverseAPIAddress)
            .arg(settings.m_reverseAPIPort)
            .arg(settings.m_reverseAPIDeviceIndex);
    m_networkRequest.setUrl(QUrl(deviceSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgDeviceSettings->asJson().toUtf8());
    buffer->seek(0);

    // Always use PATCH to avoid passing reverse API settings
    QNetworkReply *reply = m_networkManager->sendCustomRequest(m_networkRequest, "PATCH", buffer);
    buffer->setParent(reply);

    delete swgDeviceSettings;
}

void SDRPlayInput::webapiReverseSendStartStop(bool start)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("SDRplay1"));

    QString deviceSettingsURL = QString("http://%1:%2/RPX100/deviceset/%3/device/run")
            .arg(m_settings.m_reverseAPIAddress)
            .arg(m_settings.m_reverseAPIPort)
            .arg(m_settings.m_reverseAPIDeviceIndex);
    m_networkRequest.setUrl(QUrl(deviceSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgDeviceSettings->asJson().toUtf8());
    buffer->seek(0);
    QNetworkReply *reply;

    if (start) {
        reply = m_networkManager->sendCustomRequest(m_networkRequest, "POST", buffer);
    } else {
        reply = m_networkManager->sendCustomRequest(m_networkRequest, "DELETE", buffer);
    }

    buffer->setParent(reply);
    delete swgDeviceSettings;
}

void SDRPlayInput::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "SDRPlayInput::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("SDRPlayInput::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

// ====================================================================

unsigned int SDRPlaySampleRates::m_rates[m_nb_rates] = {
        1536000,   // 0
        1792000,   // 1
        2000000,   // 2
        2048000,   // 3
        2304000,   // 4
        2400000,   // 5
        3072000,   // 6
        3200000,   // 7
        4000000,   // 8
        4096000,   // 9
        4608000,   // 10
        4800000,   // 11
        5000000,   // 12
        6000000,   // 13
        6144000,   // 14
        6400000,   // 15
        8000000,   // 16
        8192000,   // 17
};

unsigned int SDRPlaySampleRates::getRate(unsigned int rate_index)
{
    if (rate_index < m_nb_rates)
    {
        return m_rates[rate_index];
    }
    else
    {
        return m_rates[0];
    }
}

unsigned int SDRPlaySampleRates::getRateIndex(unsigned int rate)
{
    for (unsigned int i=0; i < m_nb_rates; i++)
    {
        if (rate == m_rates[i])
        {
            return i;
        }
    }

    return 0;
}

unsigned int SDRPlaySampleRates::getNbRates()
{
    return SDRPlaySampleRates::m_nb_rates;
}

// ====================================================================

unsigned int SDRPlayBandwidths::m_bw[m_nb_bw] = {
        200000,    // 0
        300000,    // 1
        600000,    // 2
        1536000,   // 3
        5000000,   // 4
        6000000,   // 5
        7000000,   // 6
        8000000,   // 7
};

unsigned int SDRPlayBandwidths::getBandwidth(unsigned int bandwidth_index)
{
    if (bandwidth_index < m_nb_bw)
    {
        return m_bw[bandwidth_index];
    }
    else
    {
        return m_bw[0];
    }
}

unsigned int SDRPlayBandwidths::getBandwidthIndex(unsigned int bandwidth)
{
    for (unsigned int i=0; i < m_nb_bw; i++)
    {
        if (bandwidth == m_bw[i])
        {
            return i;
        }
    }

    return 0;
}

unsigned int SDRPlayBandwidths::getNbBandwidths()
{
    return SDRPlayBandwidths::m_nb_bw;
}

// ====================================================================

unsigned int SDRPlayIF::m_if[m_nb_if] = {
        0,         // 0
        450000,    // 1
        1620000,   // 2
        2048000,   // 3
};

unsigned int SDRPlayIF::getIF(unsigned int if_index)
{
    if (if_index < m_nb_if)
    {
        return m_if[if_index];
    }
    else
    {
        return m_if[0];
    }
}

unsigned int SDRPlayIF::getIFIndex(unsigned int iff)
{
    for (unsigned int i=0; i < m_nb_if; i++)
    {
        if (iff == m_if[i])
        {
            return i;
        }
    }

    return 0;
}

unsigned int SDRPlayIF::getNbIFs()
{
    return SDRPlayIF::m_nb_if;
}

// ====================================================================

/** Lower frequency bound in kHz inclusive */
unsigned int SDRPlayBands::m_bandLow[m_nb_bands] = {
        10,       // 0
        12000,    // 1
        30000,    // 2
        50000,    // 3
        120000,   // 4
        250000,   // 5
        380000,   // 6
        1000000,  // 7
};

/** Lower frequency bound in kHz exclusive */
unsigned int SDRPlayBands::m_bandHigh[m_nb_bands] = {
        12000,    // 0
        30000,    // 1
        50000,    // 2
        120000,   // 3
        250000,   // 4
        380000,   // 5
        1000000,  // 6
        2000000,  // 7
};

const char* SDRPlayBands::m_bandName[m_nb_bands] = {
        "10k-12M",    // 0
        "12-30M",     // 1
        "30-50M",     // 2
        "50-120M",    // 3
        "120-250M",   // 4
        "250-380M",   // 5
        "380M-1G",    // 6
        "1-2G",       // 7
};

QString SDRPlayBands::getBandName(unsigned int band_index)
{
    if (band_index < m_nb_bands)
    {
        return QString(m_bandName[band_index]);
    }
    else
    {
        return QString(m_bandName[0]);
    }
}

unsigned int SDRPlayBands::getBandLow(unsigned int band_index)
{
    if (band_index < m_nb_bands)
    {
        return m_bandLow[band_index];
    }
    else
    {
        return m_bandLow[0];
    }
}

unsigned int SDRPlayBands::getBandHigh(unsigned int band_index)
{
    if (band_index < m_nb_bands)
    {
        return m_bandHigh[band_index];
    }
    else
    {
        return m_bandHigh[0];
    }
}


unsigned int SDRPlayBands::getNbBands()
{
    return SDRPlayBands::m_nb_bands;
}

