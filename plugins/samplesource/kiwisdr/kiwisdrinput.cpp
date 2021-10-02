///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Vort                                                       //
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

#include <string.h>
#include <errno.h>

#include <QDebug>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QBuffer>

#include "SWGDeviceSettings.h"
#include "SWGDeviceState.h"
#include "SWGDeviceReport.h"
#include "SWGKiwiSDRReport.h"

#include "kiwisdrinput.h"
#include "device/deviceapi.h"
#include "kiwisdrworker.h"
#include "dsp/dspcommands.h"
#include "dsp/dspengine.h"

MESSAGE_CLASS_DEFINITION(KiwiSDRInput::MsgConfigureKiwiSDR, Message)
MESSAGE_CLASS_DEFINITION(KiwiSDRInput::MsgStartStop, Message)
MESSAGE_CLASS_DEFINITION(KiwiSDRInput::MsgSetStatus, Message)


KiwiSDRInput::KiwiSDRInput(DeviceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
	m_settings(),
	m_kiwiSDRWorker(nullptr),
	m_deviceDescription(),
	m_running(false),
	m_masterTimer(deviceAPI->getMasterTimer())
{
	m_kiwiSDRWorkerThread.start();

    m_deviceAPI->setNbSourceStreams(1);

    if (!m_sampleFifo.setSize(getSampleRate() * 2)) {
        qCritical("KiwiSDRInput::KiwiSDRInput: Could not allocate SampleFifo");
    }

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

KiwiSDRInput::~KiwiSDRInput()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;

    if (m_running) {
        stop();
    }

	m_kiwiSDRWorkerThread.quit();
	m_kiwiSDRWorkerThread.wait();
}

void KiwiSDRInput::destroy()
{
    delete this;
}

void KiwiSDRInput::init()
{
    applySettings(m_settings, true);
}

bool KiwiSDRInput::start()
{
	QMutexLocker mutexLocker(&m_mutex);

    if (m_running) stop();

	m_kiwiSDRWorker = new KiwiSDRWorker(&m_sampleFifo);
	m_kiwiSDRWorker->moveToThread(&m_kiwiSDRWorkerThread);

	connect(this, &KiwiSDRInput::setWorkerCenterFrequency, m_kiwiSDRWorker, &KiwiSDRWorker::onCenterFrequencyChanged);
	connect(this, &KiwiSDRInput::setWorkerServerAddress, m_kiwiSDRWorker, &KiwiSDRWorker::onServerAddressChanged);
	connect(this, &KiwiSDRInput::setWorkerGain, m_kiwiSDRWorker, &KiwiSDRWorker::onGainChanged);
	connect(m_kiwiSDRWorker, &KiwiSDRWorker::updateStatus, this, &KiwiSDRInput::setWorkerStatus);

	mutexLocker.unlock();

	applySettings(m_settings, true);
	m_running = true;

	return true;
}

void KiwiSDRInput::stop()
{
	QMutexLocker mutexLocker(&m_mutex);

	setWorkerStatus(0);

	if (m_kiwiSDRWorker != 0)
	{
		m_kiwiSDRWorker->deleteLater();
		m_kiwiSDRWorker = 0;
	}

	m_running = false;
}

QByteArray KiwiSDRInput::serialize() const
{
    return m_settings.serialize();
}

bool KiwiSDRInput::deserialize(const QByteArray& data)
{
    bool success = true;

    if (!m_settings.deserialize(data))
    {
        m_settings.resetToDefaults();
        success = false;
    }

    MsgConfigureKiwiSDR* message = MsgConfigureKiwiSDR::create(m_settings, true);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureKiwiSDR* messageToGUI = MsgConfigureKiwiSDR::create(m_settings, true);
        m_guiMessageQueue->push(messageToGUI);
    }

    return success;
}

const QString& KiwiSDRInput::getDeviceDescription() const
{
	return m_deviceDescription;
}

int KiwiSDRInput::getSampleRate() const
{
	return 12000;
}

quint64 KiwiSDRInput::getCenterFrequency() const
{
	return m_settings.m_centerFrequency;
}

void KiwiSDRInput::setCenterFrequency(qint64 centerFrequency)
{
	KiwiSDRSettings settings = m_settings;
    settings.m_centerFrequency = centerFrequency;

    MsgConfigureKiwiSDR* message = MsgConfigureKiwiSDR::create(settings, false);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureKiwiSDR* messageToGUI = MsgConfigureKiwiSDR::create(settings, false);
        m_guiMessageQueue->push(messageToGUI);
    }
}

void KiwiSDRInput::setWorkerStatus(int status)
{
	if (m_guiMessageQueue) {
		m_guiMessageQueue->push(MsgSetStatus::create(status));
    }
}

bool KiwiSDRInput::handleMessage(const Message& message)
{
    if (MsgConfigureKiwiSDR::match(message))
    {
        MsgConfigureKiwiSDR& conf = (MsgConfigureKiwiSDR&) message;
        qDebug() << "KiwiSDRInput::handleMessage: MsgConfigureKiwiSDR";

        bool success = applySettings(conf.getSettings(), conf.getForce());

        if (!success)
        {
            qDebug("KiwiSDRInput::handleMessage: config error");
        }

        return true;
    }
    else if (MsgStartStop::match(message))
    {
        MsgStartStop& cmd = (MsgStartStop&) message;
        qDebug() << "KiwiSDRInput::handleMessage: MsgStartStop: " << (cmd.getStartStop() ? "start" : "stop");

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

int KiwiSDRInput::getStatus() const
{
    if (m_kiwiSDRWorker) {
        return m_kiwiSDRWorker->getStatus();
    } else {
        return 0;
    }
}

bool KiwiSDRInput::applySettings(const KiwiSDRSettings& settings, bool force)
{
	qDebug() << "KiwiSDRInput::applySettings: "
        << " m_serverAddress: " << settings.m_serverAddress
        << " m_centerFrequency: " << settings.m_centerFrequency
        << " m_gain: " << settings.m_gain
        << " m_useAGC: " << settings.m_useAGC
        << " m_useAGC: " << settings.m_useAGC
        << " m_useReverseAPI: " << settings.m_useReverseAPI
        << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
        << " m_reverseAPIPort: " << settings.m_reverseAPIPort
        << " m_reverseAPIDeviceIndex: " << settings.m_reverseAPIDeviceIndex;

    QList<QString> reverseAPIKeys;

	if (m_settings.m_serverAddress != settings.m_serverAddress || force)
    {
        reverseAPIKeys.append("serverAddress");
		emit setWorkerServerAddress(settings.m_serverAddress);
    }

	if (m_settings.m_gain != settings.m_gain || force) {
        reverseAPIKeys.append("gain");
    }
	if (m_settings.m_useAGC != settings.m_useAGC || force) {
        reverseAPIKeys.append("useAGC");
    }

	if (m_settings.m_gain != settings.m_gain ||
		m_settings.m_useAGC != settings.m_useAGC || force)
	{
		emit setWorkerGain(settings.m_gain, settings.m_useAGC);
	}

    if (m_settings.m_dcBlock != settings.m_dcBlock)
    {
        reverseAPIKeys.append("dcBlock");
        m_deviceAPI->configureCorrections(settings.m_dcBlock, false);
    }

    if (m_settings.m_centerFrequency != settings.m_centerFrequency || force)
    {
        reverseAPIKeys.append("centerFrequency");

        emit setWorkerCenterFrequency(settings.m_centerFrequency);

		DSPSignalNotification *notif = new DSPSignalNotification(
			getSampleRate(), settings.m_centerFrequency);
		m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);
	}

    if (settings.m_useReverseAPI)
    {
        qDebug("KiwiSDRInput::applySettings: call webapiReverseSendSettings");
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIDeviceIndex != settings.m_reverseAPIDeviceIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    m_settings = settings;
    return true;
}

int KiwiSDRInput::webapiRunGet(
        SWGRPX100::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    return 200;
}

int KiwiSDRInput::webapiRun(
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

int KiwiSDRInput::webapiSettingsGet(
                SWGRPX100::SWGDeviceSettings& response,
                QString& errorMessage)
{
    (void) errorMessage;
    response.setKiwiSdrSettings(new SWGRPX100::SWGKiwiSDRSettings());
    response.getKiwiSdrSettings()->init();
    webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int KiwiSDRInput::webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGRPX100::SWGDeviceSettings& response, // query + response
                QString& errorMessage)
{
    (void) errorMessage;
    KiwiSDRSettings settings = m_settings;
    webapiUpdateDeviceSettings(settings, deviceSettingsKeys, response);

    MsgConfigureKiwiSDR *msg = MsgConfigureKiwiSDR::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureKiwiSDR *msgToGUI = MsgConfigureKiwiSDR::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatDeviceSettings(response, settings);
    return 200;
}

void KiwiSDRInput::webapiUpdateDeviceSettings(
        KiwiSDRSettings& settings,
        const QStringList& deviceSettingsKeys,
        SWGRPX100::SWGDeviceSettings& response)
{
    if (deviceSettingsKeys.contains("gain")) {
        settings.m_gain = response.getKiwiSdrSettings()->getGain();
    }
    if (deviceSettingsKeys.contains("useAGC")) {
        settings.m_useAGC = response.getKiwiSdrSettings()->getUseAgc();
    }
    if (deviceSettingsKeys.contains("dcBlock")) {
        settings.m_dcBlock = response.getKiwiSdrSettings()->getDcBlock() != 0;
    }
    if (deviceSettingsKeys.contains("centerFrequency")) {
        settings.m_centerFrequency = response.getKiwiSdrSettings()->getCenterFrequency();
    }
    if (deviceSettingsKeys.contains("serverAddress")) {
        settings.m_serverAddress = *response.getKiwiSdrSettings()->getServerAddress();
    }
    if (deviceSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getKiwiSdrSettings()->getUseReverseApi() != 0;
    }
    if (deviceSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getKiwiSdrSettings()->getReverseApiAddress();
    }
    if (deviceSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getKiwiSdrSettings()->getReverseApiPort();
    }
    if (deviceSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getKiwiSdrSettings()->getReverseApiDeviceIndex();
    }
}

int KiwiSDRInput::webapiReportGet(
        SWGRPX100::SWGDeviceReport& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setKiwiSdrReport(new SWGRPX100::SWGKiwiSDRReport());
    response.getKiwiSdrReport()->init();
    webapiFormatDeviceReport(response);
    return 200;
}

void KiwiSDRInput::webapiFormatDeviceSettings(SWGRPX100::SWGDeviceSettings& response, const KiwiSDRSettings& settings)
{
    response.getKiwiSdrSettings()->setGain(settings.m_gain);
    response.getKiwiSdrSettings()->setUseAgc(settings.m_useAGC ? 1 : 0);
    response.getKiwiSdrSettings()->setDcBlock(settings.m_dcBlock ? 1 : 0);
    response.getKiwiSdrSettings()->setCenterFrequency(settings.m_centerFrequency);

    if (response.getKiwiSdrSettings()->getServerAddress()) {
        *response.getKiwiSdrSettings()->getServerAddress() = settings.m_serverAddress;
    } else {
        response.getKiwiSdrSettings()->setServerAddress(new QString(settings.m_serverAddress));
    }

    response.getKiwiSdrSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getKiwiSdrSettings()->getReverseApiAddress()) {
        *response.getKiwiSdrSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getKiwiSdrSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getKiwiSdrSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getKiwiSdrSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
}

void KiwiSDRInput::webapiFormatDeviceReport(SWGRPX100::SWGDeviceReport& response)
{
    response.getKiwiSdrReport()->setStatus(getStatus());
}

void KiwiSDRInput::webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const KiwiSDRSettings& settings, bool force)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("KiwiSDR"));
    swgDeviceSettings->setKiwiSdrSettings(new SWGRPX100::SWGKiwiSDRSettings());
    SWGRPX100::SWGKiwiSDRSettings *swgKiwiSDRSettings = swgDeviceSettings->getKiwiSdrSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (deviceSettingsKeys.contains("gain")) {
        swgKiwiSDRSettings->setGain(settings.m_gain);
    }
    if (deviceSettingsKeys.contains("useAGC")) {
        swgKiwiSDRSettings->setUseAgc(settings.m_useAGC ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("dcBlock") || force) {
        swgKiwiSDRSettings->setDcBlock(settings.m_dcBlock ? 1 : 0);
    }
    if (deviceSettingsKeys.contains("centerFrequency") || force) {
        swgKiwiSDRSettings->setCenterFrequency(settings.m_centerFrequency);
    }
    if (deviceSettingsKeys.contains("serverAddress") || force) {
        swgKiwiSDRSettings->setServerAddress(new QString(settings.m_serverAddress));
    }

    QString deviceSettingsURL = QString("http://%1:%2/rpx-100/deviceset/%3/device/settings")
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

void KiwiSDRInput::webapiReverseSendStartStop(bool start)
{
    SWGRPX100::SWGDeviceSettings *swgDeviceSettings = new SWGRPX100::SWGDeviceSettings();
    swgDeviceSettings->setDirection(0); // single Rx
    swgDeviceSettings->setOriginatorIndex(m_deviceAPI->getDeviceSetIndex());
    swgDeviceSettings->setDeviceHwType(new QString("KiwiSDR"));

    QString deviceSettingsURL = QString("http://%1:%2/rpx-100/deviceset/%3/device/run")
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

void KiwiSDRInput::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "KiwiSDRInput::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("KiwiSDRInput::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
