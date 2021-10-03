///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
// Copyright (C) 2020 Bernhard Isemann, oe3bia                                   //
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

#include "SWGFeatureSettings.h"
#include "SWGFeatureReport.h"
#include "SWGFeatureActions.h"
#include "SWGDeviceState.h"

#include "dsp/dspengine.h"

#include "rigctlserverworker.h"
#include "rigctlserver.h"

MESSAGE_CLASS_DEFINITION(RigCtlServer::MsgConfigureRigCtlServer, Message)
MESSAGE_CLASS_DEFINITION(RigCtlServer::MsgStartStop, Message)

const char* const RigCtlServer::m_featureIdURI = "RPX100.feature.rigctlserver";
const char* const RigCtlServer::m_featureId = "RigCtlServer";

RigCtlServer::RigCtlServer(WebAPIAdapterInterface *webAPIAdapterInterface) :
    Feature(m_featureIdURI, webAPIAdapterInterface)
{
    qDebug("RigCtlServer::RigCtlServer: webAPIAdapterInterface: %p", webAPIAdapterInterface);
    setObjectName(m_featureId);
    m_worker = new RigCtlServerWorker(webAPIAdapterInterface);
    m_state = StIdle;
    m_errorMessage = "RigCtlServer error";
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

RigCtlServer::~RigCtlServer()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
    if (m_worker->isRunning()) {
        stop();
    }

    delete m_worker;
}

void RigCtlServer::start()
{
	qDebug("RigCtlServer::start");

    m_worker->reset();
    m_worker->setMessageQueueToFeature(getInputMessageQueue());
    bool ok = m_worker->startWork();
    m_state = ok ? StRunning : StError;
    m_thread.start();

    RigCtlServerWorker::MsgConfigureRigCtlServerWorker *msg = RigCtlServerWorker::MsgConfigureRigCtlServerWorker::create(m_settings, true);
    m_worker->getInputMessageQueue()->push(msg);
}

void RigCtlServer::stop()
{
    qDebug("RigCtlServer::stop");
	m_worker->stopWork();
    m_state = StIdle;
	m_thread.quit();
	m_thread.wait();
}

bool RigCtlServer::handleMessage(const Message& cmd)
{
	if (MsgConfigureRigCtlServer::match(cmd))
	{
        MsgConfigureRigCtlServer& cfg = (MsgConfigureRigCtlServer&) cmd;
        qDebug() << "RigCtlServer::handleMessage: MsgConfigureRigCtlServer";
        applySettings(cfg.getSettings(), cfg.getForce());

		return true;
	}
    else if (MsgStartStop::match(cmd))
    {
        MsgStartStop& cfg = (MsgStartStop&) cmd;
        qDebug() << "RigCtlServer::handleMessage: MsgStartStop: start:" << cfg.getStartStop();

        if (cfg.getStartStop()) {
            start();
        } else {
            stop();
        }

        return true;
    }
    else if (RigCtlServerSettings::MsgChannelIndexChange::match(cmd))
    {
        RigCtlServerSettings::MsgChannelIndexChange& cfg = (RigCtlServerSettings::MsgChannelIndexChange&) cmd;
        int newChannelIndex = cfg.getIndex();
        qDebug() << "RigCtlServer::handleMessage: MsgChannelIndexChange: " << newChannelIndex;
        RigCtlServerSettings settings = m_settings;
        settings.m_channelIndex = newChannelIndex;
        applySettings(settings, false);

        if (getMessageQueueToGUI())
        {
            RigCtlServerSettings::MsgChannelIndexChange *msg = new RigCtlServerSettings::MsgChannelIndexChange(cfg);
            getMessageQueueToGUI()->push(msg);
        }

        return true;
    }
	else
	{
		return false;
	}
}

QByteArray RigCtlServer::serialize() const
{
    return m_settings.serialize();
}

bool RigCtlServer::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureRigCtlServer *msg = MsgConfigureRigCtlServer::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureRigCtlServer *msg = MsgConfigureRigCtlServer::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void RigCtlServer::applySettings(const RigCtlServerSettings& settings, bool force)
{
    qDebug() << "RigCtlServer::applySettings:"
            << " m_enabled: " << settings.m_enabled
            << " m_deviceIndex: " << settings.m_deviceIndex
            << " m_channelIndex: " << settings.m_channelIndex
            << " m_rigCtlPort: " << settings.m_rigCtlPort
            << " m_maxFrequencyOffset: " << settings.m_maxFrequencyOffset
            << " m_title: " << settings.m_title
            << " m_rgbColor: " << settings.m_rgbColor
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIFeatureSetIndex: " << settings.m_reverseAPIFeatureSetIndex
            << " m_reverseAPIFeatureIndex: " << settings.m_reverseAPIFeatureIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_enabled != settings.m_enabled) || force) {
        reverseAPIKeys.append("enabled");
    }
    if ((m_settings.m_deviceIndex != settings.m_deviceIndex) || force) {
        reverseAPIKeys.append("deviceIndex");
    }
    if ((m_settings.m_channelIndex != settings.m_channelIndex) || force) {
        reverseAPIKeys.append("channelIndex");
    }
    if ((m_settings.m_rigCtlPort != settings.m_rigCtlPort) || force) {
        reverseAPIKeys.append("rigCtlPort");
    }
    if ((m_settings.m_maxFrequencyOffset != settings.m_maxFrequencyOffset) || force) {
        reverseAPIKeys.append("maxFrequencyOffset");
    }
    if ((m_settings.m_title != settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((m_settings.m_rgbColor != settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }

    RigCtlServerWorker::MsgConfigureRigCtlServerWorker *msg = RigCtlServerWorker::MsgConfigureRigCtlServerWorker::create(
        settings, force
    );
    m_worker->getInputMessageQueue()->push(msg);

    if (settings.m_useReverseAPI)
    {
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIFeatureSetIndex != settings.m_reverseAPIFeatureSetIndex) ||
                (m_settings.m_reverseAPIFeatureIndex != settings.m_reverseAPIFeatureIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    m_settings = settings;
}

int RigCtlServer::webapiRun(bool run,
    SWGRPX100::SWGDeviceState& response,
    QString& errorMessage)
{
    (void) errorMessage;
    getFeatureStateStr(*response.getState());
    MsgStartStop *msg = MsgStartStop::create(run);
    getInputMessageQueue()->push(msg);
    return 202;
}

int RigCtlServer::webapiSettingsGet(
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setRigCtlServerSettings(new SWGRPX100::SWGRigCtlServerSettings());
    response.getRigCtlServerSettings()->init();
    webapiFormatFeatureSettings(response, m_settings);
    return 200;
}

int RigCtlServer::webapiSettingsPutPatch(
    bool force,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    RigCtlServerSettings settings = m_settings;
    webapiUpdateFeatureSettings(settings, featureSettingsKeys, response);

    MsgConfigureRigCtlServer *msg = MsgConfigureRigCtlServer::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("RigCtlServer::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureRigCtlServer *msgToGUI = MsgConfigureRigCtlServer::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatFeatureSettings(response, settings);

    return 200;
}

void RigCtlServer::webapiFormatFeatureSettings(
    SWGRPX100::SWGFeatureSettings& response,
    const RigCtlServerSettings& settings)
{
    response.getRigCtlServerSettings()->setEnabled(settings.m_enabled ? 1 : 0);
    response.getRigCtlServerSettings()->setDeviceIndex(settings.m_deviceIndex);
    response.getRigCtlServerSettings()->setChannelIndex(settings.m_channelIndex);
    response.getRigCtlServerSettings()->setRigCtlPort(settings.m_rigCtlPort);
    response.getRigCtlServerSettings()->setMaxFrequencyOffset(settings.m_maxFrequencyOffset);

    if (response.getRigCtlServerSettings()->getTitle()) {
        *response.getRigCtlServerSettings()->getTitle() = settings.m_title;
    } else {
        response.getRigCtlServerSettings()->setTitle(new QString(settings.m_title));
    }

    response.getRigCtlServerSettings()->setRgbColor(settings.m_rgbColor);
    response.getRigCtlServerSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getRigCtlServerSettings()->getReverseApiAddress()) {
        *response.getRigCtlServerSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getRigCtlServerSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getRigCtlServerSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getRigCtlServerSettings()->setReverseApiFeatureSetIndex(settings.m_reverseAPIFeatureSetIndex);
    response.getRigCtlServerSettings()->setReverseApiFeatureIndex(settings.m_reverseAPIFeatureIndex);
}

void RigCtlServer::webapiUpdateFeatureSettings(
    RigCtlServerSettings& settings,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response)
{
    if (featureSettingsKeys.contains("enabled")) {
        settings.m_enabled = response.getRigCtlServerSettings()->getEnabled();
    }
    if (featureSettingsKeys.contains("deviceIndex")) {
        settings.m_deviceIndex = response.getRigCtlServerSettings()->getDeviceIndex();
    }
    if (featureSettingsKeys.contains("channelIndex")) {
        settings.m_channelIndex = response.getRigCtlServerSettings()->getChannelIndex();
    }
    if (featureSettingsKeys.contains("rigCtlPort")) {
        settings.m_rigCtlPort = response.getRigCtlServerSettings()->getRigCtlPort();
    }
    if (featureSettingsKeys.contains("maxFrequencyOffset")) {
        settings.m_maxFrequencyOffset = response.getRigCtlServerSettings()->getMaxFrequencyOffset();
    }
    if (featureSettingsKeys.contains("title")) {
        settings.m_title = *response.getRigCtlServerSettings()->getTitle();
    }
    if (featureSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getRigCtlServerSettings()->getRgbColor();
    }
    if (featureSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getRigCtlServerSettings()->getUseReverseApi() != 0;
    }
    if (featureSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getRigCtlServerSettings()->getReverseApiAddress();
    }
    if (featureSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getRigCtlServerSettings()->getReverseApiPort();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureSetIndex")) {
        settings.m_reverseAPIFeatureSetIndex = response.getRigCtlServerSettings()->getReverseApiFeatureSetIndex();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureIndex")) {
        settings.m_reverseAPIFeatureIndex = response.getRigCtlServerSettings()->getReverseApiFeatureIndex();
    }
}

void RigCtlServer::webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const RigCtlServerSettings& settings, bool force)
{
    SWGRPX100::SWGFeatureSettings *swgFeatureSettings = new SWGRPX100::SWGFeatureSettings();
    // swgFeatureSettings->setOriginatorFeatureIndex(getIndexInDeviceSet());
    // swgFeatureSettings->setOriginatorFeatureSetIndex(getDeviceSetIndex());
    swgFeatureSettings->setFeatureType(new QString("RigCtlServer"));
    swgFeatureSettings->setRigCtlServerSettings(new SWGRPX100::SWGRigCtlServerSettings());
    SWGRPX100::SWGRigCtlServerSettings *swgRigCtlServerSettings = swgFeatureSettings->getRigCtlServerSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (featureSettingsKeys.contains("enabled") || force) {
        swgRigCtlServerSettings->setEnabled(settings.m_enabled ? 1 : 0);
    }
    if (featureSettingsKeys.contains("deviceIndex") || force) {
        swgRigCtlServerSettings->setDeviceIndex(settings.m_deviceIndex);
    }
    if (featureSettingsKeys.contains("channelIndex") || force) {
        swgRigCtlServerSettings->setChannelIndex(settings.m_channelIndex);
    }
    if (featureSettingsKeys.contains("rigCtlPort") || force) {
        swgRigCtlServerSettings->setRigCtlPort(settings.m_rigCtlPort);
    }
    if (featureSettingsKeys.contains("maxFrequencyOffset") || force) {
        swgRigCtlServerSettings->setMaxFrequencyOffset(settings.m_maxFrequencyOffset);
    }
    if (featureSettingsKeys.contains("title") || force) {
        swgRigCtlServerSettings->setTitle(new QString(settings.m_title));
    }
    if (featureSettingsKeys.contains("rgbColor") || force) {
        swgRigCtlServerSettings->setRgbColor(settings.m_rgbColor);
    }

    QString channelSettingsURL = QString("http://%1:%2/RPX100/featureset/%3/feature/%4/settings")
            .arg(settings.m_reverseAPIAddress)
            .arg(settings.m_reverseAPIPort)
            .arg(settings.m_reverseAPIFeatureSetIndex)
            .arg(settings.m_reverseAPIFeatureIndex);
    m_networkRequest.setUrl(QUrl(channelSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgFeatureSettings->asJson().toUtf8());
    buffer->seek(0);

    // Always use PATCH to avoid passing reverse API settings
    QNetworkReply *reply = m_networkManager->sendCustomRequest(m_networkRequest, "PATCH", buffer);
    buffer->setParent(reply);

    delete swgFeatureSettings;
}

void RigCtlServer::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "RigCtlServer::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("RigCtlServer::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
