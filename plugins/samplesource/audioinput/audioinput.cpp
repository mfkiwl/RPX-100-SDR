///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015-2018 Bernhard Isemann, oe3bia                              //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#include "audioinput.h"
#include "audioinputworker.h"

MESSAGE_CLASS_DEFINITION(AudioInput::MsgConfigureAudioInput, Message)
MESSAGE_CLASS_DEFINITION(AudioInput::MsgStartStop, Message)

AudioInput::AudioInput(DeviceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
    m_settings(),
    m_worker(nullptr),
    m_deviceDescription("AudioInput"),
    m_running(false),
    m_centerFrequency(0)
{
    m_fifo.setSize(20*AudioInputWorker::m_convBufSamples);
    openDevice();
    m_deviceAPI->setNbSourceStreams(1);
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

AudioInput::~AudioInput()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;

    if (m_running) {
        stop();
    }

    closeDevice();
}

void AudioInput::destroy()
{
    delete this;
}

bool AudioInput::openDevice()
{
    if (!openAudioDevice(m_settings.m_deviceName, m_settings.m_sampleRate))
    {
        qCritical("AudioInput::openDevice: could not open audio source");
        return false;
    }
    else
        return true;
}

bool AudioInput::openAudioDevice(QString deviceName, qint32 sampleRate)
{
    AudioDeviceManager *audioDeviceManager = DSPEngine::instance()->getAudioDeviceManager();
    const QList<QAudioDeviceInfo>& audioList = audioDeviceManager->getInputDevices();

    for (const auto &itAudio : audioList)
    {
        if (AudioInputSettings::getFullDeviceName(itAudio) == deviceName)
        {
            // FIXME: getInputDeviceIndex needs a realm parameter (itAudio.realm())
            int deviceIndex = audioDeviceManager->getInputDeviceIndex(itAudio.deviceName());
            m_audioInput.start(deviceIndex, sampleRate);
            m_audioInput.addFifo(&m_fifo);
            return true;
        }
    }
    return false;
}

void AudioInput::init()
{
    applySettings(m_settings, true);
}

bool AudioInput::start()
{
    qDebug() << "AudioInput::start";

    if (m_running) {
        stop();
    }

    if(!m_sampleFifo.setSize(96000*4))
    {
        qCritical("Could not allocate SampleFifo");
        return false;
    }

    applySettings(m_settings, true, true);

    m_worker = new AudioInputWorker(&m_sampleFifo, &m_fifo);
    m_worker->moveToThread(&m_workerThread);
    m_worker->setLog2Decimation(m_settings.m_log2Decim);
    m_worker->setIQMapping(m_settings.m_iqMapping);
    m_worker->startWork();
    m_workerThread.start();

    qDebug("AudioInput::started");
    m_running = true;

    return true;
}

void AudioInput::closeDevice()
{
    m_audioInput.removeFifo(&m_fifo);
    m_audioInput.stop();
}

void AudioInput::stop()
{
    if (m_worker)
    {
        m_worker->stopWork();
        m_workerThread.quit();
        m_workerThread.wait();
        delete m_worker;
        m_worker = nullptr;
    }

    m_running = false;
}

QByteArray AudioInput::serialize() const
{
    return m_settings.serialize();
}

bool AudioInput::deserialize(const QByteArray& data)
{
    bool success = true;

    if (!m_settings.deserialize(data))
    {
        m_settings.resetToDefaults();
        success = false;
    }

    MsgConfigureAudioInput* message = MsgConfigureAudioInput::create(m_settings, true);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureAudioInput* messageToGUI = MsgConfigureAudioInput::create(m_settings, true);
        m_guiMessageQueue->push(messageToGUI);
    }

    return success;
}

const QString& AudioInput::getDeviceDescription() const
{
    return m_deviceDescription;
}

int AudioInput::getSampleRate() const
{
    return m_settings.m_sampleRate/(1<<m_settings.m_log2Decim);
}

quint64 AudioInput::getCenterFrequency() const
{
    return m_centerFrequency;
}

bool AudioInput::handleMessage(const Message& message)
{
    if(MsgConfigureAudioInput::match(message))
    {
        qDebug() << "AudioInput::handleMessage: MsgConfigureAudioInput";
        MsgConfigureAudioInput& conf = (MsgConfigureAudioInput&) message;
        applySettings(conf.getSettings(), conf.getForce());
        return true;
    }
    else if (MsgStartStop::match(message))
    {
        MsgStartStop& cmd = (MsgStartStop&) message;
        qDebug() << "AudioInput::handleMessage: MsgStartStop: " << (cmd.getStartStop() ? "start" : "stop");

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

void AudioInput::applySettings(const AudioInputSettings& settings, bool force, bool starting)
{
    bool forwardChange = false;
    QList<QString> reverseAPIKeys;

    if ((m_settings.m_deviceName != settings.m_deviceName)
        || (m_settings.m_sampleRate != settings.m_sampleRate) || force)
    {
        // Don't call openAudioDevice if called from start(), otherwise ::AudioInput
        // will be created on wrong thread and we'll crash after ::AudioInput::stop calls delete
        if (!starting)
        {
            closeDevice();
            if (openAudioDevice(settings.m_deviceName, settings.m_sampleRate))
                qDebug() << "AudioInput::applySettings: opened device " << settings.m_deviceName << " with sample rate " << m_audioInput.getRate();
            else
                qCritical() << "AudioInput::applySettings: failed to open device " << settings.m_deviceName;
            }
    }

    if ((m_settings.m_deviceName != settings.m_deviceName) || force)
    {
        reverseAPIKeys.append("device");
    }

    if ((m_settings.m_sampleRate != settings.m_sampleRate) || force)
    {
        reverseAPIKeys.append("sampleRate");
        forwardChange = true;
    }

    if ((m_settings.m_volume != settings.m_volume) || force)
    {
        reverseAPIKeys.append("volume");
        m_audioInput.setVolume(settings.m_volume);
        qDebug() << "AudioInput::applySettings: set volume to " << settings.m_volume;
    }

    if ((m_settings.m_log2Decim != settings.m_log2Decim) || force)
    {
        reverseAPIKeys.append("log2Decim");
        forwardChange = true;

        if (m_worker)
        {
            m_worker->setLog2Decimation(settings.m_log2Decim);
            qDebug() << "AudioInput::applySettings: set decimation to " << (1<<settings.m_log2Decim);
        }
    }

    if ((m_settings.m_iqMapping != settings.m_iqMapping) || force)
    {
        reverseAPIKeys.append("iqMapping");
        forwardChange = true;

        if (m_worker) {
            m_worker->setIQMapping(settings.m_iqMapping);
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
        qint64 dF =
            ((m_settings.m_iqMapping == AudioInputSettings::IQMapping::L) ||
            (m_settings.m_iqMapping == AudioInputSettings::IQMapping::R)) ?
                m_settings.m_sampleRate / 4 : 0;
        DSPSignalNotification *notif = new DSPSignalNotification(m_settings.m_sampleRate/(1<<m_settings.m_log2Decim), dF);
        m_sampleRate = notif->getSampleRate();
        m_centerFrequency = notif->getCenterFrequency();
        m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);
    }
}

int AudioInput::webapiRunGet(
        SWGRPX100::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    return 200;
}

int AudioInput::webapiRun(
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

int AudioInput::webapiSettingsGet(
                SWGRPX100::SWGDeviceSettings& response,
                QString& errorMessage)
{
    (void) errorMessage;
    response.setAudioInputSettings(new SWGRPX100::SWGAudioInputSettings());
    response.getAudioInputSettings()->init();
    webapiFormatDeviceSettings(response, m_settings);

    return 200;
}

int AudioInput::webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGRPX100::SWGDeviceSettings& response, // query + response
                QString& errorMessage)
{
    (void) errorMessage;
    AudioInputSettings settings = m_settings;
    webapiUpdateDeviceSettings(settings, deviceSettingsKeys, response);

    MsgConfigureAudioInput *msg = MsgConfigureAudioInput::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureAudioInput *msgToGUI = MsgConfigureAudioInput::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatDeviceSettings(response, settings);
    return 200;
}

void AudioInput::webapiUpdateDeviceSettings(
        AudioInputSettings& settings,
        const QStringList& deviceSettingsKeys,
        SWGRPX100::SWGDeviceSettings& response)
{
    if (deviceSettingsKeys.contains("device")) {
        settings.m_deviceName = *response.getAudioInputSettings()->getDevice();
    }
    if (deviceSettingsKeys.contains("devSampleRate")) {
        settings.m_sampleRate = response.getAudioInputSettings()->getDevSampleRate();
    }
    if (deviceSettingsKeys.contains("volume")) {
        settings.m_volume = response.getAudioInputSettings()->getVolume();
    }
    if (deviceSettingsKeys.contains("log2Decim")) {
        settings.m_log2Decim = response.getAudioInputSettings()->getLog2Decim();
    }
    if (deviceSettingsKeys.contains("iqMapping")) {
        settings.m_iqMapping = (AudioInputSettings::IQMapping)response.getAudioInputSettings()->getIqMapping();
    }
    if (deviceSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getAudioInputSettings()->getUseReverseApi() != 0;
    }
    if (deviceSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getAudioInputSettings()->getReverseApiAddress();
    }
    if (deviceSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getAudioInputSettings()->getReverseApiPort();
    }
    if (deviceSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getAudioInputSettings()->getReverseApiDeviceIndex();
    }
}

void AudioInput::webapiFormatDeviceSettings(SWGRPX100::SWGDeviceSettings& response, const AudioInputSettings& settings)
{
    response.getAudioInputSettings()->setDevice(new QString(settings.m_deviceName));
    response.getAudioInputSettings()->setDevSampleRate(settings.m_sampleRate);
    response.getAudioInputSettings()->setVolume(settings.m_volume);
    response.getAudioInputSettings()->setLog2Decim(settings.m_log2Decim);
    response.getAudioInputSettings()->setIqMapping((int)settings.m_iqMapping);

    response.getAudioInputSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getAudioInputSettings()->getReverseApiAddress()) {
        *response.getAudioInputSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getAudioInputSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getAudioInputSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getAudioInputSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
}

void AudioInput::webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const AudioInputSettings& settings, bool force)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("AudioInput"));
    swgDeviceSettings->setAudioInputSettings(new SWGRPX100::SWGAudioInputSettings());
    SWGRPX100::SWGAudioInputSettings *swgAudioInputSettings = swgDeviceSettings->getAudioInputSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (deviceSettingsKeys.contains("device") || force) {
        swgAudioInputSettings->setDevice(new QString(settings.m_deviceName));
    }
    if (deviceSettingsKeys.contains("devSampleRate") || force) {
        swgAudioInputSettings->setDevSampleRate(settings.m_sampleRate);
    }
    if (deviceSettingsKeys.contains("volume") || force) {
        swgAudioInputSettings->setVolume(settings.m_volume);
    }
    if (deviceSettingsKeys.contains("log2Decim") || force) {
        swgAudioInputSettings->setLog2Decim(settings.m_log2Decim);
    }
    if (deviceSettingsKeys.contains("iqMapping") || force) {
        swgAudioInputSettings->setIqMapping(settings.m_iqMapping);
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

void AudioInput::webapiReverseSendStartStop(bool start)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("AudioInput"));

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

void AudioInput::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "AudioInput::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("AudioInput::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
