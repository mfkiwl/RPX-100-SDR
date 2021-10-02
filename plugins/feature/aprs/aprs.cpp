///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
// Copyright (C) 2020 Edouard Griffiths, F4EXB                                   //
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

#include "device/deviceset.h"
#include "channel/channelapi.h"
#include "maincore.h"
#include "aprsworker.h"
#include "aprs.h"

MESSAGE_CLASS_DEFINITION(APRS::MsgConfigureAPRS, Message)
MESSAGE_CLASS_DEFINITION(APRS::MsgReportWorker, Message)

const char* const APRS::m_featureIdURI = "rpx-100.feature.aprs";
const char* const APRS::m_featureId = "APRS";

APRS::APRS(WebAPIAdapterInterface *webAPIAdapterInterface) :
    Feature(m_featureIdURI, webAPIAdapterInterface)
{
    qDebug("APRS::APRS: webAPIAdapterInterface: %p", webAPIAdapterInterface);
    setObjectName(m_featureId);
    m_worker = new APRSWorker(this, webAPIAdapterInterface);
    m_state = StIdle;
    m_errorMessage = "APRS error";
    connect(&m_updatePipesTimer, SIGNAL(timeout()), this, SLOT(updatePipes()));
    m_updatePipesTimer.start(1000);
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

APRS::~APRS()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
    if (m_worker->isRunning()) {
        stop();
    }

    delete m_worker;
}

void APRS::start()
{
    qDebug("APRS::start");
    m_worker->reset();
    m_worker->setMessageQueueToFeature(getInputMessageQueue());
    m_worker->setMessageQueueToGUI(getMessageQueueToGUI());
    bool ok = m_worker->startWork();
    m_state = ok ? StIdle : StError;
    m_thread.start();

    APRSWorker::MsgConfigureAPRSWorker *msg = APRSWorker::MsgConfigureAPRSWorker::create(m_settings, true);
    m_worker->getInputMessageQueue()->push(msg);
}

void APRS::stop()
{
    qDebug("APRS::stop");
    m_worker->stopWork();
    m_state = StIdle;
    m_thread.quit();
    m_thread.wait();
}

bool APRS::handleMessage(const Message& cmd)
{
    if (MsgConfigureAPRS::match(cmd))
    {
        MsgConfigureAPRS& cfg = (MsgConfigureAPRS&) cmd;
        qDebug() << "APRS::handleMessage: MsgConfigureAPRS";
        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else if (MsgReportWorker::match(cmd))
    {
        MsgReportWorker& report = (MsgReportWorker&) cmd;
        if (report.getMessage() == "Connected")
            m_state = StRunning;
        else if (report.getMessage() == "Disconnected")
            m_state = StIdle;
        else
        {
            m_state = StError;
            m_errorMessage = report.getMessage();
        }
        return true;
    }
    else if (MainCore::MsgPacket::match(cmd))
    {
        MainCore::MsgPacket& report = (MainCore::MsgPacket&) cmd;
        if (getMessageQueueToGUI())
        {
            MainCore::MsgPacket *copy = new MainCore::MsgPacket(report);
            getMessageQueueToGUI()->push(copy);
        }
        if (m_state == StRunning)
        {
            MainCore::MsgPacket *copy = new MainCore::MsgPacket(report);
            m_worker->getInputMessageQueue()->push(copy);
        }
        return true;
    }
    else
    {
        return false;
    }
}

void APRS::updatePipes()
{
    QList<AvailablePipeSource> availablePipes = updateAvailablePipeSources("packets", APRSSettings::m_pipeTypes, APRSSettings::m_pipeURIs, this);

    if (availablePipes != m_availablePipes)
    {
        m_availablePipes = availablePipes;
        if (getMessageQueueToGUI())
        {
            MsgReportPipes *msgToGUI = MsgReportPipes::create();
            QList<AvailablePipeSource>& msgAvailablePipes = msgToGUI->getAvailablePipes();
            msgAvailablePipes.append(availablePipes);
            getMessageQueueToGUI()->push(msgToGUI);
        }
    }
}

QByteArray APRS::serialize() const
{
    return m_settings.serialize();
}

bool APRS::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureAPRS *msg = MsgConfigureAPRS::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureAPRS *msg = MsgConfigureAPRS::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void APRS::applySettings(const APRSSettings& settings, bool force)
{
    qDebug() << "APRS::applySettings:"
            << " m_igateEnabled: " << settings.m_igateEnabled
            << " m_title: " << settings.m_title
            << " m_rgbColor: " << settings.m_rgbColor
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIFeatureSetIndex: " << settings.m_reverseAPIFeatureSetIndex
            << " m_reverseAPIFeatureIndex: " << settings.m_reverseAPIFeatureIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_igateEnabled != settings.m_igateEnabled) || force)
    {
        if (settings.m_igateEnabled)
            start();
        else
            stop();
        reverseAPIKeys.append("igateEnabled");
    }

    if ((m_settings.m_title != settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((m_settings.m_rgbColor != settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }

    APRSWorker::MsgConfigureAPRSWorker *msg = APRSWorker::MsgConfigureAPRSWorker::create(
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

int APRS::webapiRun(bool run,
    SWGRPX100::SWGDeviceState& response,
    QString& errorMessage)
{
    (void) run;
    (void) response;
    (void) errorMessage;
    //getFeatureStateStr(*response.getState());
    //MsgStartStopIGate *msg = MsgStartStopIGate::create(run);
    //getInputMessageQueue()->push(msg);
    return 202;
}

int APRS::webapiSettingsGet(
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setAprsSettings(new SWGRPX100::SWGAPRSSettings());
    response.getAprsSettings()->init();
    webapiFormatFeatureSettings(response, m_settings);
    return 200;
}

int APRS::webapiSettingsPutPatch(
    bool force,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    APRSSettings settings = m_settings;
    webapiUpdateFeatureSettings(settings, featureSettingsKeys, response);

    MsgConfigureAPRS *msg = MsgConfigureAPRS::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("APRS::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureAPRS *msgToGUI = MsgConfigureAPRS::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatFeatureSettings(response, settings);

    return 200;
}

void APRS::webapiFormatFeatureSettings(
    SWGRPX100::SWGFeatureSettings& response,
    const APRSSettings& settings)
{
    response.getAprsSettings()->setIgateServer(new QString(settings.m_igateServer));
    response.getAprsSettings()->setIgatePort(settings.m_igatePort);
    response.getAprsSettings()->setIgateCallsign(new QString(settings.m_igateCallsign));
    response.getAprsSettings()->setIgatePasscode(new QString(settings.m_igatePasscode));
    response.getAprsSettings()->setIgateFilter(new QString(settings.m_igateFilter));
    response.getAprsSettings()->setIgateEnabled(settings.m_igateEnabled ? 1 : 0);

    if (response.getAprsSettings()->getTitle()) {
        *response.getAprsSettings()->getTitle() = settings.m_title;
    } else {
        response.getAprsSettings()->setTitle(new QString(settings.m_title));
    }

    response.getAprsSettings()->setRgbColor(settings.m_rgbColor);
    response.getAprsSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getAprsSettings()->getReverseApiAddress()) {
        *response.getAprsSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getAprsSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getAprsSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getAprsSettings()->setReverseApiFeatureSetIndex(settings.m_reverseAPIFeatureSetIndex);
    response.getAprsSettings()->setReverseApiFeatureIndex(settings.m_reverseAPIFeatureIndex);
}

void APRS::webapiUpdateFeatureSettings(
    APRSSettings& settings,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response)
{
    if (featureSettingsKeys.contains("igateServer")) {
        settings.m_igateServer = *response.getAprsSettings()->getIgateServer();
    }
    if (featureSettingsKeys.contains("igatePort")) {
        settings.m_igatePort = response.getAprsSettings()->getIgatePort();
    }
    if (featureSettingsKeys.contains("igateCallsign")) {
        settings.m_igateCallsign = *response.getAprsSettings()->getIgateCallsign();
    }
    if (featureSettingsKeys.contains("igatePasscode")) {
        settings.m_igatePasscode = *response.getAprsSettings()->getIgatePasscode();
    }
    if (featureSettingsKeys.contains("igateFilter")) {
        settings.m_igateFilter = *response.getAprsSettings()->getIgateFilter();
    }
    if (featureSettingsKeys.contains("title")) {
        settings.m_title = *response.getAprsSettings()->getTitle();
    }
    if (featureSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getAprsSettings()->getRgbColor();
    }
    if (featureSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getAprsSettings()->getUseReverseApi() != 0;
    }
    if (featureSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getAprsSettings()->getReverseApiAddress();
    }
    if (featureSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getAprsSettings()->getReverseApiPort();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureSetIndex")) {
        settings.m_reverseAPIFeatureSetIndex = response.getAprsSettings()->getReverseApiFeatureSetIndex();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureIndex")) {
        settings.m_reverseAPIFeatureIndex = response.getAprsSettings()->getReverseApiFeatureIndex();
    }
}

void APRS::webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const APRSSettings& settings, bool force)
{
    SWGRPX100::SWGFeatureSettings *swgFeatureSettings = new SWGRPX100::SWGFeatureSettings();
    // swgFeatureSettings->setOriginatorFeatureIndex(getIndexInDeviceSet());
    // swgFeatureSettings->setOriginatorFeatureSetIndex(getDeviceSetIndex());
    swgFeatureSettings->setFeatureType(new QString("APRS"));
    swgFeatureSettings->setAprsSettings(new SWGRPX100::SWGAPRSSettings());
    SWGRPX100::SWGAPRSSettings *swgAPRSSettings = swgFeatureSettings->getAprsSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (featureSettingsKeys.contains("igateServer") || force) {
        swgAPRSSettings->setIgateServer(new QString(settings.m_igateServer));
    }
    if (featureSettingsKeys.contains("igatePort") || force) {
        swgAPRSSettings->setIgatePort(settings.m_igatePort);
    }
    if (featureSettingsKeys.contains("igateCallsign") || force) {
        swgAPRSSettings->setIgateCallsign(new QString(settings.m_igateCallsign));
    }
    if (featureSettingsKeys.contains("igatePasscode") || force) {
        swgAPRSSettings->setIgatePasscode(new QString(settings.m_igatePasscode));
    }
    if (featureSettingsKeys.contains("igateFilter") || force) {
        swgAPRSSettings->setIgateFilter(new QString(settings.m_igateFilter));
    }
    if (featureSettingsKeys.contains("title") || force) {
        swgAPRSSettings->setTitle(new QString(settings.m_title));
    }
    if (featureSettingsKeys.contains("rgbColor") || force) {
        swgAPRSSettings->setRgbColor(settings.m_rgbColor);
    }

    QString channelSettingsURL = QString("http://%1:%2/rpx-100/featureset/%3/feature/%4/settings")
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

void APRS::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "APRS::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("APRS::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
