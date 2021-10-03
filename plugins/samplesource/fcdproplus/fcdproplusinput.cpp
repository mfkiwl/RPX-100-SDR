///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016-2018 Bernhard Isemann, oe3bia                              //
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

#include "dsp/dspcommands.h"
#include "dsp/dspengine.h"
#include "device/deviceapi.h"

#include "fcdproplusinput.h"
#include "fcdproplusthread.h"
#include "fcdtraits.h"
#include "fcdproplusconst.h"

MESSAGE_CLASS_DEFINITION(FCDProPlusInput::MsgConfigureFCDProPlus, Message)
MESSAGE_CLASS_DEFINITION(FCDProPlusInput::MsgStartStop, Message)

FCDProPlusInput::FCDProPlusInput(DeviceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
	m_dev(nullptr),
	m_settings(),
	m_FCDThread(nullptr),
	m_deviceDescription(fcd_traits<ProPlus>::displayedName),
	m_running(false)
{
    m_fcdFIFO.setSize(20*fcd_traits<ProPlus>::convBufSize);
    openDevice();
    m_deviceAPI->setNbSourceStreams(1);
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

FCDProPlusInput::~FCDProPlusInput()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;

    if (m_running) {
        stop();
    }

    closeDevice();
}

void FCDProPlusInput::destroy()
{
    delete this;
}

bool FCDProPlusInput::openDevice()
{
    if (m_dev != 0) {
        closeDevice();
    }

    int device = m_deviceAPI->getSamplingDeviceSequence();
    qDebug() << "FCDProPlusInput::openDevice with device #" << device;
    m_dev = fcdOpen(fcd_traits<ProPlus>::vendorId, fcd_traits<ProPlus>::productId, device);

    if (m_dev == 0)
    {
        qCritical("FCDProPlusInput::start: could not open FCD");
        return false;
    }

	if (!openFCDAudio(fcd_traits<ProPlus>::qtDeviceName))
	{
        qCritical("FCDProPlusInput::start: could not open FCD audio source");
        return false;
	}
    else
    {
        qDebug("FCDProPlusInput::start: FCD audio source opened");
    }

    return true;
}

void FCDProPlusInput::init()
{
    applySettings(m_settings, true);
}

bool FCDProPlusInput::start()
{
//	QMutexLocker mutexLocker(&m_mutex);

    if (!m_dev) {
        return false;
    }

    if (m_running) {
        stop();
    }

    qDebug() << "FCDProPlusInput::start";

	/* Apply settings before streaming to avoid bus contention;
	 * there is very little spare bandwidth on a full speed USB device.
	 * Failure is harmless if no device is found
	 * ... This is rubbish...*/

	//applySettings(m_settings, true);

	if (!m_sampleFifo.setSize(96000*4))
	{
		qCritical("FCDProPlusInput::start: could not allocate SampleFifo");
		return false;
	}

	m_FCDThread = new FCDProPlusThread(&m_sampleFifo, &m_fcdFIFO);
    m_FCDThread->setLog2Decimation(m_settings.m_log2Decim);
    m_FCDThread->setFcPos(m_settings.m_fcPos);
    m_FCDThread->setIQOrder(m_settings.m_iqOrder);
	m_FCDThread->startWork();

//	mutexLocker.unlock();
	applySettings(m_settings, true);

	qDebug("FCDProPlusInput::started");
	m_running = true;

	return true;
}

void FCDProPlusInput::closeDevice()
{
    if (m_dev == 0) { // was never open
        return;
    }

    fcdClose(m_dev);
    m_dev = 0;

   	closeFCDAudio();
}

bool FCDProPlusInput::openFCDAudio(const char* cardname)
{
    AudioDeviceManager *audioDeviceManager = DSPEngine::instance()->getAudioDeviceManager();
    const QList<QAudioDeviceInfo>& audioList = audioDeviceManager->getInputDevices();

    for (const auto &itAudio : audioList)
    {
        if (itAudio.deviceName().contains(QString(cardname)))
        {
            int fcdDeviceIndex = audioDeviceManager->getInputDeviceIndex(itAudio.deviceName());
            m_fcdAudioInput.start(fcdDeviceIndex, fcd_traits<ProPlus>::sampleRate);
            int fcdSampleRate = m_fcdAudioInput.getRate();
            qDebug("FCDProPlusInput::openFCDAudio: %s index %d at %d S/s",
                    itAudio.deviceName().toStdString().c_str(), fcdDeviceIndex, fcdSampleRate);
            m_fcdAudioInput.addFifo(&m_fcdFIFO);
            return true;
        }
    }

    qCritical("FCDProPlusInput::openFCDAudio: device with name %s not found", cardname);
    return false;
}

void FCDProPlusInput::closeFCDAudio()
{
    m_fcdAudioInput.removeFifo(&m_fcdFIFO);
    m_fcdAudioInput.stop();
}

void FCDProPlusInput::stop()
{
	QMutexLocker mutexLocker(&m_mutex);

	if (m_FCDThread)
	{
		m_FCDThread->stopWork();
		// wait for thread to quit ?
		delete m_FCDThread;
		m_FCDThread = nullptr;
	}

	m_running = false;
}

QByteArray FCDProPlusInput::serialize() const
{
    return m_settings.serialize();
}

bool FCDProPlusInput::deserialize(const QByteArray& data)
{
    bool success = true;

    if (!m_settings.deserialize(data))
    {
        m_settings.resetToDefaults();
        success = false;
    }

    MsgConfigureFCDProPlus* message = MsgConfigureFCDProPlus::create(m_settings, true);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureFCDProPlus* messageToGUI = MsgConfigureFCDProPlus::create(m_settings, true);
        m_guiMessageQueue->push(messageToGUI);
    }

    return success;
}

const QString& FCDProPlusInput::getDeviceDescription() const
{
	return m_deviceDescription;
}

int FCDProPlusInput::getSampleRate() const
{
	return fcd_traits<ProPlus>::sampleRate/(1<<m_settings.m_log2Decim);
}

quint64 FCDProPlusInput::getCenterFrequency() const
{
	return m_settings.m_centerFrequency;
}

void FCDProPlusInput::setCenterFrequency(qint64 centerFrequency)
{
    FCDProPlusSettings settings = m_settings;
    settings.m_centerFrequency = centerFrequency;

    MsgConfigureFCDProPlus* message = MsgConfigureFCDProPlus::create(settings, false);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureFCDProPlus* messageToGUI = MsgConfigureFCDProPlus::create(settings, false);
        m_guiMessageQueue->push(messageToGUI);
    }
}

bool FCDProPlusInput::handleMessage(const Message& message)
{
	if(MsgConfigureFCDProPlus::match(message))
	{
		qDebug() << "FCDProPlusInput::handleMessage: MsgConfigureFCD";
		MsgConfigureFCDProPlus& conf = (MsgConfigureFCDProPlus&) message;
		applySettings(conf.getSettings(), conf.getForce());
		return true;
	}
    else if (MsgStartStop::match(message))
    {
        MsgStartStop& cmd = (MsgStartStop&) message;
        qDebug() << "FCDProPlusInput::handleMessage: MsgStartStop: " << (cmd.getStartStop() ? "start" : "stop");

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

void FCDProPlusInput::applySettings(const FCDProPlusSettings& settings, bool force)
{
	bool forwardChange = false;
    QList<QString> reverseAPIKeys;

    if (force || (m_settings.m_centerFrequency != settings.m_centerFrequency)) {
        reverseAPIKeys.append("centerFrequency");
    }
    if (force || (m_settings.m_transverterMode != settings.m_transverterMode)) {
        reverseAPIKeys.append("transverterMode");
    }
    if (force || (m_settings.m_transverterDeltaFrequency != settings.m_transverterDeltaFrequency)) {
        reverseAPIKeys.append("transverterDeltaFrequency");
    }
	if ((m_settings.m_LOppmTenths != settings.m_LOppmTenths) || force) {
		reverseAPIKeys.append("LOppmTenths");
    }

	if (force || (m_settings.m_centerFrequency != settings.m_centerFrequency)
        || (m_settings.m_LOppmTenths != settings.m_LOppmTenths)
        || (m_settings.m_fcPos != settings.m_fcPos)
        || (m_settings.m_log2Decim != settings.m_log2Decim)
        || (m_settings.m_transverterMode != settings.m_transverterMode)
        || (m_settings.m_transverterDeltaFrequency != settings.m_transverterDeltaFrequency))
	{
        qint64 deviceCenterFrequency = DeviceSampleSource::calculateDeviceCenterFrequency(
                settings.m_centerFrequency,
                settings.m_transverterDeltaFrequency,
                settings.m_log2Decim,
                (DeviceSampleSource::fcPos_t) settings.m_fcPos,
                fcd_traits<ProPlus>::sampleRate,
                DeviceSampleSource::FrequencyShiftScheme::FSHIFT_STD,
                settings.m_transverterMode);

        if (m_dev != 0) {
            set_center_freq((double) deviceCenterFrequency);
        }

        qDebug() << "FCDProPlusInput::applySettings: center freq: " << settings.m_centerFrequency << " Hz"
                << " device center freq: " << deviceCenterFrequency << " Hz";

        forwardChange = (m_settings.m_centerFrequency != settings.m_centerFrequency) || force;

        m_settings.m_centerFrequency = settings.m_centerFrequency;
	}

	if ((m_settings.m_log2Decim != settings.m_log2Decim) || force)
	{
        reverseAPIKeys.append("log2Decim");
		forwardChange = true;

		if (m_FCDThread)
		{
		    m_FCDThread->setLog2Decimation(settings.m_log2Decim);
			qDebug() << "FCDProPlusInput::applySettings: set decimation to " << (1<<settings.m_log2Decim);
		}
	}

    if ((m_settings.m_fcPos != settings.m_fcPos) || force)
    {
        reverseAPIKeys.append("fcPos");

        if (m_FCDThread) {
            m_FCDThread->setFcPos((int) settings.m_fcPos);
        }

        qDebug() << "FCDProPlusInput::applySettings: set fc pos (enum) to " << (int) settings.m_fcPos;
    }

    if ((m_settings.m_iqOrder != settings.m_iqOrder) || force)
    {
        reverseAPIKeys.append("iqOrder");

        if (m_FCDThread) {
            m_FCDThread->setIQOrder((int) settings.m_iqOrder);
        }

        qDebug() << "FCDProPlusInput::applySettings: set IQ order to %s" << (settings.m_iqOrder ? "IQ" : "QI");
    }

	if ((m_settings.m_lnaGain != settings.m_lnaGain) || force)
	{
        reverseAPIKeys.append("lnaGain");

		if (m_dev != 0) {
			set_lna_gain(settings.m_lnaGain);
		}
	}

	if ((m_settings.m_biasT != settings.m_biasT) || force)
	{
        reverseAPIKeys.append("biasT");

		if (m_dev != 0) {
			set_bias_t(settings.m_biasT);
		}
	}

	if ((m_settings.m_mixGain != settings.m_mixGain) || force)
	{
        reverseAPIKeys.append("mixGain");

		if (m_dev != 0) {
			set_mixer_gain(settings.m_mixGain);
		}
	}

	if ((m_settings.m_ifGain != settings.m_ifGain) || force)
	{
        reverseAPIKeys.append("ifGain");

		if (m_dev != 0) {
			set_if_gain(settings.m_ifGain);
		}
	}

	if ((m_settings.m_ifFilterIndex != settings.m_ifFilterIndex) || force)
	{
        reverseAPIKeys.append("ifFilterIndex");

		if (m_dev != 0) {
			set_if_filter(settings.m_ifFilterIndex);
		}
	}

	if ((m_settings.m_rfFilterIndex != settings.m_rfFilterIndex) || force)
	{
        reverseAPIKeys.append("rfFilterIndex");

		if (m_dev != 0) {
			set_rf_filter(settings.m_rfFilterIndex);
		}
	}

	if ((m_settings.m_dcBlock != settings.m_dcBlock) || force)
	{
        reverseAPIKeys.append("dcBlock");
		m_deviceAPI->configureCorrections(settings.m_dcBlock, settings.m_iqImbalance);
	}

	if ((m_settings.m_iqImbalance != settings.m_iqImbalance) || force)
	{
        reverseAPIKeys.append("iqImbalance");
		m_deviceAPI->configureCorrections(settings.m_dcBlock, settings.m_iqImbalance);
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
		DSPSignalNotification *notif = new DSPSignalNotification(fcd_traits<ProPlus>::sampleRate/(1<<settings.m_log2Decim), m_settings.m_centerFrequency);
        m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);
    }
}

void FCDProPlusInput::set_center_freq(double freq)
{
	freq += freq*(((double) m_settings.m_LOppmTenths)/10000000.0);

	if (fcdAppSetFreq(m_dev, freq) == FCD_MODE_NONE)
	{
		qDebug("No FCD HID found for frquency change");
	}
}

void FCDProPlusInput::set_bias_t(bool on)
{
	quint8 cmd = on ? 1 : 0;

	fcdAppSetParam(m_dev, FCDPROPLUS_HID_CMD_SET_BIAS_TEE, &cmd, 1);
}

void FCDProPlusInput::set_lna_gain(bool on)
{
	quint8 cmd = on ? 1 : 0;

	fcdAppSetParam(m_dev, FCDPROPLUS_HID_CMD_SET_LNA_GAIN, &cmd, 1);
}

void FCDProPlusInput::set_mixer_gain(bool on)
{
	quint8 cmd = on ? 1 : 0;

	fcdAppSetParam(m_dev, FCDPROPLUS_HID_CMD_SET_MIXER_GAIN, &cmd, 1);
}

void FCDProPlusInput::set_if_gain(int gain)
{
	if (gain < 0)
	{
		return;
	}

	quint8 cmd_value = gain;

	if (fcdAppSetParam(m_dev, FCDPROPLUS_HID_CMD_SET_IF_GAIN, &cmd_value, 1) != FCD_MODE_APP)
	{
		qWarning() << "FCDProPlusInput::set_if_gain: failed to set at " << cmd_value;
	}
}

void FCDProPlusInput::set_if_filter(int filterIndex)
{
	if ((filterIndex < 0) || (filterIndex >= FCDProPlusConstants::fcdproplus_if_filter_nb_values()))
	{
		return;
	}

	quint8 cmd_value = FCDProPlusConstants::if_filters[filterIndex].value;

	if (fcdAppSetParam(m_dev, FCDPROPLUS_HID_CMD_SET_IF_FILTER, &cmd_value, 1) != FCD_MODE_APP)
	{
		qWarning() << "FCDProPlusInput::set_if_filter: failed to set at " << cmd_value;
	}
}


void FCDProPlusInput::set_rf_filter(int filterIndex)
{
	if ((filterIndex < 0) || (filterIndex >= FCDProPlusConstants::fcdproplus_rf_filter_nb_values()))
	{
		return;
	}

	quint8 cmd_value = FCDProPlusConstants::rf_filters[filterIndex].value;

	if (fcdAppSetParam(m_dev, FCDPROPLUS_HID_CMD_SET_RF_FILTER, &cmd_value, 1) != FCD_MODE_APP)
	{
		qWarning() << "FCDProPlusInput::set_rf_filter: failed to set at " << cmd_value;
	}
}

int FCDProPlusInput::webapiRunGet(
        SWGRPX100::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    return 200;
}

int FCDProPlusInput::webapiRun(
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

int FCDProPlusInput::webapiSettingsGet(
                SWGRPX100::SWGDeviceSettings& response,
                QString& errorMessage)
{
    (void) errorMessage;
    response.setFcdProPlusSettings(new SWGRPX100::SWGFCDProPlusSettings());
    response.getFcdProPlusSettings()->init();
    webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int FCDProPlusInput::webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGRPX100::SWGDeviceSettings& response, // query + response
                QString& errorMessage)
{
    (void) errorMessage;
    FCDProPlusSettings settings = m_settings;
    webapiUpdateDeviceSettings(settings, deviceSettingsKeys, response);

    MsgConfigureFCDProPlus *msg = MsgConfigureFCDProPlus::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureFCDProPlus *msgToGUI = MsgConfigureFCDProPlus::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatDeviceSettings(response, settings);
    return 200;
}

void FCDProPlusInput::webapiUpdateDeviceSettings(
        FCDProPlusSettings& settings,
        const QStringList& deviceSettingsKeys,
        SWGRPX100::SWGDeviceSettings& response)
{
    if (deviceSettingsKeys.contains("centerFrequency")) {
        settings.m_centerFrequency = response.getFcdProPlusSettings()->getCenterFrequency();
    }
    if (deviceSettingsKeys.contains("log2Decim")) {
        settings.m_log2Decim = response.getFcdProPlusSettings()->getLog2Decim();
    }
    if (deviceSettingsKeys.contains("iqOrder")) {
        settings.m_iqOrder = response.getFcdProPlusSettings()->getIqOrder() != 0;
    }
    if (deviceSettingsKeys.contains("fcPos")) {
        settings.m_fcPos = (FCDProPlusSettings::fcPos_t) response.getFcdProPlusSettings()->getFcPos();
    }
    if (deviceSettingsKeys.contains("rangeLow")) {
        settings.m_rangeLow = response.getFcdProPlusSettings()->getRangeLow() != 0;
    }
    if (deviceSettingsKeys.contains("lnaGain")) {
        settings.m_lnaGain = response.getFcdProPlusSettings()->getLnaGain() != 0;
    }
    if (deviceSettingsKeys.contains("mixGain")) {
        settings.m_mixGain = response.getFcdProPlusSettings()->getMixGain() != 0;
    }
    if (deviceSettingsKeys.contains("biasT")) {
        settings.m_biasT = response.getFcdProPlusSettings()->getBiasT() != 0;
    }
    if (deviceSettingsKeys.contains("ifGain")) {
        settings.m_ifGain = response.getFcdProPlusSettings()->getIfGain();
    }
    if (deviceSettingsKeys.contains("ifFilterIndex")) {
        settings.m_ifFilterIndex = response.getFcdProPlusSettings()->getIfFilterIndex();
    }
    if (deviceSettingsKeys.contains("rfFilterIndex")) {
        settings.m_rfFilterIndex = response.getFcdProPlusSettings()->getRfFilterIndex();
    }
    if (deviceSettingsKeys.contains("LOppmTenths")) {
        settings.m_LOppmTenths = response.getFcdProPlusSettings()->getLOppmTenths();
    }
    if (deviceSettingsKeys.contains("dcBlock")) {
        settings.m_dcBlock = response.getFcdProPlusSettings()->getDcBlock() != 0;
    }
    if (deviceSettingsKeys.contains("iqImbalance")) {
        settings.m_iqImbalance = response.getFcdProPlusSettings()->getIqImbalance() != 0;
    }
    if (deviceSettingsKeys.contains("transverterDeltaFrequency")) {
        settings.m_transverterDeltaFrequency = response.getFcdProPlusSettings()->getTransverterDeltaFrequency();
    }
    if (deviceSettingsKeys.contains("transverterMode")) {
        settings.m_transverterMode = response.getFcdProPlusSettings()->getTransverterMode() != 0;
    }
    if (deviceSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getFcdProPlusSettings()->getUseReverseApi() != 0;
    }
    if (deviceSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getFcdProPlusSettings()->getReverseApiAddress();
    }
    if (deviceSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getFcdProPlusSettings()->getReverseApiPort();
    }
    if (deviceSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getFcdProPlusSettings()->getReverseApiDeviceIndex();
    }
}

void FCDProPlusInput::webapiFormatDeviceSettings(SWGRPX100::SWGDeviceSettings& response, const FCDProPlusSettings& settings)
{
    response.getFcdProPlusSettings()->setCenterFrequency(settings.m_centerFrequency);
    response.getFcdProPlusSettings()->setLog2Decim(settings.m_log2Decim);
    response.getFcdProPlusSettings()->setIqOrder(settings.m_iqOrder ? 1 : 0);
    response.getFcdProPlusSettings()->setFcPos((int) settings.m_fcPos);
    response.getFcdProPlusSettings()->setRangeLow(settings.m_rangeLow ? 1 : 0);
    response.getFcdProPlusSettings()->setLnaGain(settings.m_lnaGain ? 1 : 0);
    response.getFcdProPlusSettings()->setMixGain(settings.m_mixGain ? 1 : 0);
    response.getFcdProPlusSettings()->setBiasT(settings.m_biasT ? 1 : 0);
    response.getFcdProPlusSettings()->setIfGain(settings.m_ifGain);
    response.getFcdProPlusSettings()->setIfFilterIndex(settings.m_ifFilterIndex);
    response.getFcdProPlusSettings()->setRfFilterIndex(settings.m_rfFilterIndex);
    response.getFcdProPlusSettings()->setLOppmTenths(settings.m_LOppmTenths);
    response.getFcdProPlusSettings()->setDcBlock(settings.m_dcBlock ? 1 : 0);
    response.getFcdProPlusSettings()->setIqImbalance(settings.m_iqImbalance ? 1 : 0);
    response.getFcdProPlusSettings()->setTransverterDeltaFrequency(settings.m_transverterDeltaFrequency);
    response.getFcdProPlusSettings()->setTransverterMode(settings.m_transverterMode ? 1 : 0);

    response.getFcdProPlusSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getFcdProPlusSettings()->getReverseApiAddress()) {
        *response.getFcdProPlusSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getFcdProPlusSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getFcdProPlusSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getFcdProPlusSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
}

void FCDProPlusInput::webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const FCDProPlusSettings& settings, bool force)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("FCDPro+"));
    swgDeviceSettings->setFcdProPlusSettings(new SWGRPX100::SWGFCDProPlusSettings());
    SWGRPX100::SWGFCDProPlusSettings *swgFCDProPlusSettings = swgDeviceSettings->getFcdProPlusSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (deviceSettingsKeys.contains("centerFrequency") || force) {
        swgFCDProPlusSettings->setCenterFrequency(settings.m_centerFrequency);
    }
    if (deviceSettingsKeys.contains("log2Decim") || force) {
        swgFCDProPlusSettings->setLog2Decim(settings.m_log2Decim);
    }
    if (deviceSettingsKeys.contains("iqOrder") || force) {
        swgFCDProPlusSettings->setIqOrder(settings.m_iqOrder ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("fcPos") || force) {
        swgFCDProPlusSettings->setFcPos((int) settings.m_fcPos);
    }
    if (deviceSettingsKeys.contains("rangeLow") || force) {
        swgFCDProPlusSettings->setRangeLow(settings.m_rangeLow ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("lnaGain") || force) {
        swgFCDProPlusSettings->setLnaGain(settings.m_lnaGain ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("mixGain") || force) {
        swgFCDProPlusSettings->setMixGain(settings.m_mixGain ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("biasT") || force) {
        swgFCDProPlusSettings->setBiasT(settings.m_biasT ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("ifGain") || force) {
        swgFCDProPlusSettings->setIfGain(settings.m_ifGain);
    }
    if (deviceSettingsKeys.contains("ifFilterIndex") || force) {
        swgFCDProPlusSettings->setIfFilterIndex(settings.m_ifFilterIndex);
    }
    if (deviceSettingsKeys.contains("rfFilterIndex") || force) {
        swgFCDProPlusSettings->setRfFilterIndex(settings.m_rfFilterIndex);
    }
    if (deviceSettingsKeys.contains("LOppmTenths") || force) {
        swgFCDProPlusSettings->setLOppmTenths(settings.m_LOppmTenths);
    }
    if (deviceSettingsKeys.contains("dcBlock") || force) {
        swgFCDProPlusSettings->setDcBlock(settings.m_dcBlock ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("iqImbalance") || force) {
        swgFCDProPlusSettings->setIqImbalance(settings.m_iqImbalance ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("transverterDeltaFrequency") || force) {
        swgFCDProPlusSettings->setTransverterDeltaFrequency(settings.m_transverterDeltaFrequency);
    }
    if (deviceSettingsKeys.contains("transverterMode") || force) {
        swgFCDProPlusSettings->setTransverterMode(settings.m_transverterMode ? 1 : 0);
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

void FCDProPlusInput::webapiReverseSendStartStop(bool start)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("FCDPro+"));

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

void FCDProPlusInput::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "FCDProPlusInput::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("FCDProPlusInput::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
