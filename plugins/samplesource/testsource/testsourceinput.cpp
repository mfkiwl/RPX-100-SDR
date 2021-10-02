///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
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
#include <QNetworkAccessManager>
#include <QBuffer>

#include "SWGDeviceSettings.h"
#include "SWGDeviceState.h"

#include "testsourceinput.h"
#include "device/deviceapi.h"
#include "testsourceworker.h"
#include "dsp/dspcommands.h"
#include "dsp/dspengine.h"

MESSAGE_CLASS_DEFINITION(TestSourceInput::MsgConfigureTestSource, Message)
MESSAGE_CLASS_DEFINITION(TestSourceInput::MsgStartStop, Message)


TestSourceInput::TestSourceInput(DeviceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
	m_settings(),
	m_testSourceWorker(nullptr),
	m_deviceDescription(),
	m_running(false),
	m_masterTimer(deviceAPI->getMasterTimer())
{
    m_deviceAPI->setNbSourceStreams(1);

    if (!m_sampleFifo.setSize(96000 * 4)) {
        qCritical("TestSourceInput::TestSourceInput: Could not allocate SampleFifo");
    }

    m_testSourceWorker = new TestSourceWorker(&m_sampleFifo);
    m_testSourceWorker->moveToThread(&m_testSourceWorkerThread);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

TestSourceInput::~TestSourceInput()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;

    if (m_running) {
        stop();
    }

    m_testSourceWorker->deleteLater();
}

void TestSourceInput::destroy()
{
    delete this;
}

void TestSourceInput::init()
{
    applySettings(m_settings, true);
}

bool TestSourceInput::start()
{
	QMutexLocker mutexLocker(&m_mutex);

    if (m_running) {
        stop();
    }

	m_testSourceWorker->setSamplerate(m_settings.m_sampleRate);
	startWorker();

	mutexLocker.unlock();

	applySettings(m_settings, true);
	m_running = true;

	return true;
}

void TestSourceInput::stop()
{
	QMutexLocker mutexLocker(&m_mutex);
    stopWorker();
	m_running = false;
}

void TestSourceInput::startWorker()
{
    m_testSourceWorker->startWork();
    m_testSourceWorkerThread.start();
}

void TestSourceInput::stopWorker()
{
	m_testSourceWorker->stopWork();
	m_testSourceWorkerThread.quit();
	m_testSourceWorkerThread.wait();
}


QByteArray TestSourceInput::serialize() const
{
    return m_settings.serialize();
}

bool TestSourceInput::deserialize(const QByteArray& data)
{
    bool success = true;

    if (!m_settings.deserialize(data))
    {
        m_settings.resetToDefaults();
        success = false;
    }

    MsgConfigureTestSource* message = MsgConfigureTestSource::create(m_settings, true);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureTestSource* messageToGUI = MsgConfigureTestSource::create(m_settings, true);
        m_guiMessageQueue->push(messageToGUI);
    }

    return success;
}

const QString& TestSourceInput::getDeviceDescription() const
{
	return m_deviceDescription;
}

int TestSourceInput::getSampleRate() const
{
	return m_settings.m_sampleRate/(1<<m_settings.m_log2Decim);
}

quint64 TestSourceInput::getCenterFrequency() const
{
	return m_settings.m_centerFrequency;
}

void TestSourceInput::setCenterFrequency(qint64 centerFrequency)
{
    TestSourceSettings settings = m_settings;
    settings.m_centerFrequency = centerFrequency;

    MsgConfigureTestSource* message = MsgConfigureTestSource::create(settings, false);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureTestSource* messageToGUI = MsgConfigureTestSource::create(settings, false);
        m_guiMessageQueue->push(messageToGUI);
    }
}

bool TestSourceInput::handleMessage(const Message& message)
{
    if (MsgConfigureTestSource::match(message))
    {
        MsgConfigureTestSource& conf = (MsgConfigureTestSource&) message;
        qDebug() << "TestSourceInput::handleMessage: MsgConfigureTestSource";

        bool success = applySettings(conf.getSettings(), conf.getForce());

        if (!success)
        {
            qDebug("TestSourceInput::handleMessage: config error");
        }

        return true;
    }
    else if (MsgStartStop::match(message))
    {
        MsgStartStop& cmd = (MsgStartStop&) message;
        qDebug() << "TestSourceInput::handleMessage: MsgStartStop: " << (cmd.getStartStop() ? "start" : "stop");

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

bool TestSourceInput::applySettings(const TestSourceSettings& settings, bool force)
{
    QList<QString> reverseAPIKeys;

    if ((m_settings.m_autoCorrOptions != settings.m_autoCorrOptions) || force)
    {
        reverseAPIKeys.append("autoCorrOptions");

        switch(settings.m_autoCorrOptions)
        {
        case TestSourceSettings::AutoCorrDC:
            m_deviceAPI->configureCorrections(true, false);
            break;
        case TestSourceSettings::AutoCorrDCAndIQ:
            m_deviceAPI->configureCorrections(true, true);
            break;
        case TestSourceSettings::AutoCorrNone:
        default:
            m_deviceAPI->configureCorrections(false, false);
            break;
        }
    }

    if ((m_settings.m_sampleRate != settings.m_sampleRate) || force)
    {
        reverseAPIKeys.append("sampleRate");

        if (m_testSourceWorker != 0)
        {
            m_testSourceWorker->setSamplerate(settings.m_sampleRate);
            qDebug("TestSourceInput::applySettings: sample rate set to %d", settings.m_sampleRate);
        }
    }

    if ((m_settings.m_log2Decim != settings.m_log2Decim) || force)
    {
        reverseAPIKeys.append("log2Decim");

        if (m_testSourceWorker != 0)
        {
            m_testSourceWorker->setLog2Decimation(settings.m_log2Decim);
            qDebug() << "TestSourceInput::applySettings: set decimation to " << (1<<settings.m_log2Decim);
        }
    }

    if ((m_settings.m_centerFrequency != settings.m_centerFrequency)
        || (m_settings.m_fcPos != settings.m_fcPos)
        || (m_settings.m_frequencyShift != settings.m_frequencyShift)
        || (m_settings.m_sampleRate != settings.m_sampleRate)
        || (m_settings.m_log2Decim != settings.m_log2Decim) || force)
    {
        reverseAPIKeys.append("centerFrequency");
        reverseAPIKeys.append("fcPos");
        reverseAPIKeys.append("frequencyShift");

        qint64 deviceCenterFrequency = DeviceSampleSource::calculateDeviceCenterFrequency(
                settings.m_centerFrequency,
                0, // no transverter mode
                settings.m_log2Decim,
                (DeviceSampleSource::fcPos_t) settings.m_fcPos,
                settings.m_sampleRate,
                DeviceSampleSource::FrequencyShiftScheme::FSHIFT_STD,
                false);

        int frequencyShift = settings.m_frequencyShift;
        quint32 devSampleRate = settings.m_sampleRate;

        if (settings.m_log2Decim != 0)
        {
            frequencyShift += DeviceSampleSource::calculateFrequencyShift(
                    settings.m_log2Decim,
                    (DeviceSampleSource::fcPos_t) settings.m_fcPos,
                    settings.m_sampleRate,
                    DeviceSampleSource::FSHIFT_STD);
        }

        if (m_testSourceWorker != 0)
        {
            m_testSourceWorker->setFcPos((int) settings.m_fcPos);
            m_testSourceWorker->setFrequencyShift(frequencyShift);
            qDebug() << "TestSourceInput::applySettings:"
                    << " center freq: " << settings.m_centerFrequency << " Hz"
                    << " device center freq: " << deviceCenterFrequency << " Hz"
                    << " device sample rate: " << devSampleRate << "Hz"
                    << " Actual sample rate: " << devSampleRate/(1<<m_settings.m_log2Decim) << "Hz"
                    << " f shift: " << settings.m_frequencyShift;
        }
    }

    if ((m_settings.m_amplitudeBits != settings.m_amplitudeBits) || force)
    {
        reverseAPIKeys.append("amplitudeBits");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setAmplitudeBits(settings.m_amplitudeBits);
        }
    }

    if ((m_settings.m_dcFactor != settings.m_dcFactor) || force)
    {
        reverseAPIKeys.append("dcFactor");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setDCFactor(settings.m_dcFactor);
        }
    }

    if ((m_settings.m_iFactor != settings.m_iFactor) || force)
    {
        reverseAPIKeys.append("iFactor");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setIFactor(settings.m_iFactor);
        }
    }

    if ((m_settings.m_qFactor != settings.m_qFactor) || force)
    {
        reverseAPIKeys.append("qFactor");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setQFactor(settings.m_qFactor);
        }
    }

    if ((m_settings.m_phaseImbalance != settings.m_phaseImbalance) || force)
    {
        reverseAPIKeys.append("phaseImbalance");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setPhaseImbalance(settings.m_phaseImbalance);
        }
    }

    if ((m_settings.m_sampleSizeIndex != settings.m_sampleSizeIndex) || force)
    {
        reverseAPIKeys.append("sampleSizeIndex");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setBitSize(settings.m_sampleSizeIndex);
        }
    }

    if ((m_settings.m_sampleRate != settings.m_sampleRate)
        || (m_settings.m_centerFrequency != settings.m_centerFrequency)
        || (m_settings.m_log2Decim != settings.m_log2Decim)
        || (m_settings.m_fcPos != settings.m_fcPos) || force)
    {
        int sampleRate = settings.m_sampleRate/(1<<settings.m_log2Decim);
        DSPSignalNotification *notif = new DSPSignalNotification(sampleRate, settings.m_centerFrequency);
        m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);
    }

    if ((m_settings.m_modulationTone != settings.m_modulationTone) || force)
    {
        reverseAPIKeys.append("modulationTone");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setToneFrequency(settings.m_modulationTone * 10);
        }
    }

    if ((m_settings.m_modulation != settings.m_modulation) || force)
    {
        reverseAPIKeys.append("modulation");

        if (m_testSourceWorker != 0)
        {
            m_testSourceWorker->setModulation(settings.m_modulation);

            if (settings.m_modulation == TestSourceSettings::ModulationPattern0) {
                m_testSourceWorker->setPattern0();
            } else if (settings.m_modulation == TestSourceSettings::ModulationPattern1) {
                m_testSourceWorker->setPattern1();
            } else if (settings.m_modulation == TestSourceSettings::ModulationPattern2) {
                m_testSourceWorker->setPattern2();
            }
        }
    }

    if ((m_settings.m_amModulation != settings.m_amModulation) || force)
    {
        reverseAPIKeys.append("amModulation");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setAMModulation(settings.m_amModulation / 100.0f);
        }
    }

    if ((m_settings.m_fmDeviation != settings.m_fmDeviation) || force)
    {
        reverseAPIKeys.append("fmDeviation");

        if (m_testSourceWorker != 0) {
            m_testSourceWorker->setFMDeviation(settings.m_fmDeviation * 100.0f);
        }
    }

    if (settings.m_useReverseAPI)
    {
        qDebug("TestSourceInput::applySettings: call webapiReverseSendSettings");
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIDeviceIndex != settings.m_reverseAPIDeviceIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    m_settings = settings;
    return true;
}

int TestSourceInput::webapiRunGet(
        SWGRPX100::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    return 200;
}

int TestSourceInput::webapiRun(
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

int TestSourceInput::webapiSettingsGet(
                SWGRPX100::SWGDeviceSettings& response,
                QString& errorMessage)
{
    (void) errorMessage;
    response.setTestSourceSettings(new SWGRPX100::SWGTestSourceSettings());
    response.getTestSourceSettings()->init();
    webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int TestSourceInput::webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGRPX100::SWGDeviceSettings& response, // query + response
                QString& errorMessage)
{
    (void) errorMessage;
    TestSourceSettings settings = m_settings;
    webapiUpdateDeviceSettings(settings, deviceSettingsKeys, response);

    MsgConfigureTestSource *msg = MsgConfigureTestSource::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureTestSource *msgToGUI = MsgConfigureTestSource::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatDeviceSettings(response, settings);
    return 200;
}

void TestSourceInput::webapiUpdateDeviceSettings(
    TestSourceSettings& settings,
    const QStringList& deviceSettingsKeys,
    SWGRPX100::SWGDeviceSettings& response)
{
    if (deviceSettingsKeys.contains("centerFrequency")) {
        settings.m_centerFrequency = response.getTestSourceSettings()->getCenterFrequency();
    }
    if (deviceSettingsKeys.contains("frequencyShift")) {
        settings.m_frequencyShift = response.getTestSourceSettings()->getFrequencyShift();
    }
    if (deviceSettingsKeys.contains("sampleRate")) {
        settings.m_sampleRate = response.getTestSourceSettings()->getSampleRate();
    }
    if (deviceSettingsKeys.contains("log2Decim")) {
        settings.m_log2Decim = response.getTestSourceSettings()->getLog2Decim();
    }
    if (deviceSettingsKeys.contains("fcPos")) {
        int fcPos = response.getTestSourceSettings()->getFcPos();
        fcPos = fcPos < 0 ? 0 : fcPos > 2 ? 2 : fcPos;
        settings.m_fcPos = (TestSourceSettings::fcPos_t) fcPos;
    }
    if (deviceSettingsKeys.contains("sampleSizeIndex")) {
        int sampleSizeIndex = response.getTestSourceSettings()->getSampleSizeIndex();
        sampleSizeIndex = sampleSizeIndex < 0 ? 0 : sampleSizeIndex > 1 ? 2 : sampleSizeIndex;
        settings.m_sampleSizeIndex = sampleSizeIndex;
    }
    if (deviceSettingsKeys.contains("amplitudeBits")) {
        settings.m_amplitudeBits = response.getTestSourceSettings()->getAmplitudeBits();
    }
    if (deviceSettingsKeys.contains("autoCorrOptions")) {
        int autoCorrOptions = response.getTestSourceSettings()->getAutoCorrOptions();
        autoCorrOptions = autoCorrOptions < 0 ? 0 : autoCorrOptions >= TestSourceSettings::AutoCorrLast ? TestSourceSettings::AutoCorrLast-1 : autoCorrOptions;
        settings.m_sampleSizeIndex = (TestSourceSettings::AutoCorrOptions) autoCorrOptions;
    }
    if (deviceSettingsKeys.contains("modulation")) {
        int modulation = response.getTestSourceSettings()->getModulation();
        modulation = modulation < 0 ? 0 : modulation >= TestSourceSettings::ModulationLast ? TestSourceSettings::ModulationLast-1 : modulation;
        settings.m_modulation = (TestSourceSettings::Modulation) modulation;
    }
    if (deviceSettingsKeys.contains("modulationTone")) {
        settings.m_modulationTone = response.getTestSourceSettings()->getModulationTone();
    }
    if (deviceSettingsKeys.contains("amModulation")) {
        settings.m_amModulation = response.getTestSourceSettings()->getAmModulation();
    };
    if (deviceSettingsKeys.contains("fmDeviation")) {
        settings.m_fmDeviation = response.getTestSourceSettings()->getFmDeviation();
    };
    if (deviceSettingsKeys.contains("dcFactor")) {
        settings.m_dcFactor = response.getTestSourceSettings()->getDcFactor();
    };
    if (deviceSettingsKeys.contains("iFactor")) {
        settings.m_iFactor = response.getTestSourceSettings()->getIFactor();
    };
    if (deviceSettingsKeys.contains("qFactor")) {
        settings.m_qFactor = response.getTestSourceSettings()->getQFactor();
    };
    if (deviceSettingsKeys.contains("phaseImbalance")) {
        settings.m_phaseImbalance = response.getTestSourceSettings()->getPhaseImbalance();
    };
    if (deviceSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getTestSourceSettings()->getUseReverseApi() != 0;
    }
    if (deviceSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getTestSourceSettings()->getReverseApiAddress();
    }
    if (deviceSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getTestSourceSettings()->getReverseApiPort();
    }
    if (deviceSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getTestSourceSettings()->getReverseApiDeviceIndex();
    }
}

void TestSourceInput::webapiFormatDeviceSettings(SWGRPX100::SWGDeviceSettings& response, const TestSourceSettings& settings)
{
    response.getTestSourceSettings()->setCenterFrequency(settings.m_centerFrequency);
    response.getTestSourceSettings()->setFrequencyShift(settings.m_frequencyShift);
    response.getTestSourceSettings()->setSampleRate(settings.m_sampleRate);
    response.getTestSourceSettings()->setLog2Decim(settings.m_log2Decim);
    response.getTestSourceSettings()->setFcPos((int) settings.m_fcPos);
    response.getTestSourceSettings()->setSampleSizeIndex((int) settings.m_sampleSizeIndex);
    response.getTestSourceSettings()->setAmplitudeBits(settings.m_amplitudeBits);
    response.getTestSourceSettings()->setAutoCorrOptions((int) settings.m_autoCorrOptions);
    response.getTestSourceSettings()->setModulation((int) settings.m_modulation);
    response.getTestSourceSettings()->setModulationTone(settings.m_modulationTone);
    response.getTestSourceSettings()->setAmModulation(settings.m_amModulation);
    response.getTestSourceSettings()->setFmDeviation(settings.m_fmDeviation);
    response.getTestSourceSettings()->setDcFactor(settings.m_dcFactor);
    response.getTestSourceSettings()->setIFactor(settings.m_iFactor);
    response.getTestSourceSettings()->setQFactor(settings.m_qFactor);
    response.getTestSourceSettings()->setPhaseImbalance(settings.m_phaseImbalance);

    response.getTestSourceSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getTestSourceSettings()->getReverseApiAddress()) {
        *response.getTestSourceSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getTestSourceSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getTestSourceSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getTestSourceSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
}

void TestSourceInput::webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const TestSourceSettings& settings, bool force)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("TestSource"));
    swgDeviceSettings->setTestSourceSettings(new SWGRPX100::SWGTestSourceSettings());
    SWGRPX100::SWGTestSourceSettings *swgTestSourceSettings = swgDeviceSettings->getTestSourceSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (deviceSettingsKeys.contains("centerFrequency") || force) {
        swgTestSourceSettings->setCenterFrequency(settings.m_centerFrequency);
    }
    if (deviceSettingsKeys.contains("frequencyShift") || force) {
        swgTestSourceSettings->setFrequencyShift(settings.m_frequencyShift);
    }
    if (deviceSettingsKeys.contains("sampleRate") || force) {
        swgTestSourceSettings->setSampleRate(settings.m_sampleRate);
    }
    if (deviceSettingsKeys.contains("log2Decim") || force) {
        swgTestSourceSettings->setLog2Decim(settings.m_log2Decim);
    }
    if (deviceSettingsKeys.contains("fcPos") || force) {
        swgTestSourceSettings->setFcPos((int) settings.m_fcPos);
    }
    if (deviceSettingsKeys.contains("sampleSizeIndex") || force) {
        swgTestSourceSettings->setSampleSizeIndex(settings.m_sampleSizeIndex);
    }
    if (deviceSettingsKeys.contains("amplitudeBits") || force) {
        swgTestSourceSettings->setAmplitudeBits(settings.m_amplitudeBits);
    }
    if (deviceSettingsKeys.contains("autoCorrOptions") || force) {
        swgTestSourceSettings->setAutoCorrOptions((int) settings.m_sampleSizeIndex);
    }
    if (deviceSettingsKeys.contains("modulation") || force) {
        swgTestSourceSettings->setModulation((int) settings.m_modulation);
    }
    if (deviceSettingsKeys.contains("modulationTone")) {
        swgTestSourceSettings->setModulationTone(settings.m_modulationTone);
    }
    if (deviceSettingsKeys.contains("amModulation") || force) {
        swgTestSourceSettings->setAmModulation(settings.m_amModulation);
    };
    if (deviceSettingsKeys.contains("fmDeviation") || force) {
        swgTestSourceSettings->setFmDeviation(settings.m_fmDeviation);
    };
    if (deviceSettingsKeys.contains("dcFactor") || force) {
        swgTestSourceSettings->setDcFactor(settings.m_dcFactor);
    };
    if (deviceSettingsKeys.contains("iFactor") || force) {
        swgTestSourceSettings->setIFactor(settings.m_iFactor);
    };
    if (deviceSettingsKeys.contains("qFactor") || force) {
        swgTestSourceSettings->setQFactor(settings.m_qFactor);
    };
    if (deviceSettingsKeys.contains("phaseImbalance") || force) {
        swgTestSourceSettings->setPhaseImbalance(settings.m_phaseImbalance);
    };

    QString channelSettingsURL = QString("http://%1:%2/RPX100/deviceset/%3/device/settings")
            .arg(settings.m_reverseAPIAddress)
            .arg(settings.m_reverseAPIPort)
            .arg(settings.m_reverseAPIDeviceIndex);
    m_networkRequest.setUrl(QUrl(channelSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgDeviceSettings->asJson().toUtf8());
    buffer->seek(0);
//    qDebug("TestSourceInput::webapiReverseSendSettings: %s", channelSettingsURL.toStdString().c_str());
//    qDebug("TestSourceInput::webapiReverseSendSettings: query:\n%s", swgDeviceSettings->asJson().toStdString().c_str());

    // Always use PATCH to avoid passing reverse API settings
    QNetworkReply *reply = m_networkManager->sendCustomRequest(m_networkRequest, "PATCH", buffer);
    buffer->setParent(reply);

    delete swgDeviceSettings;
}

void TestSourceInput::webapiReverseSendStartStop(bool start)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("TestSource"));

    QString channelSettingsURL = QString("http://%1:%2/RPX100/deviceset/%3/device/run")
            .arg(m_settings.m_reverseAPIAddress)
            .arg(m_settings.m_reverseAPIPort)
            .arg(m_settings.m_reverseAPIDeviceIndex);
    m_networkRequest.setUrl(QUrl(channelSettingsURL));
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

void TestSourceInput::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "TestSourceInput::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("TestSourceInput::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
