///////////////////////////////////////////////////////////////////////////////////
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
#include "SWGSimplePTTReport.h"
#include "SWGDeviceState.h"

#include "dsp/dspengine.h"

#include "simplepttworker.h"
#include "simpleptt.h"

MESSAGE_CLASS_DEFINITION(SimplePTT::MsgConfigureSimplePTT, Message)
MESSAGE_CLASS_DEFINITION(SimplePTT::MsgPTT, Message)
MESSAGE_CLASS_DEFINITION(SimplePTT::MsgStartStop, Message)

const char* const SimplePTT::m_featureIdURI = "rpx-100.feature.simpleptt";
const char* const SimplePTT::m_featureId = "SimplePTT";

SimplePTT::SimplePTT(WebAPIAdapterInterface *webAPIAdapterInterface) :
    Feature(m_featureIdURI, webAPIAdapterInterface),
    m_ptt(false)
{
    setObjectName(m_featureId);
    m_worker = new SimplePTTWorker(webAPIAdapterInterface);
    m_state = StIdle;
    m_errorMessage = "SimplePTT error";
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

SimplePTT::~SimplePTT()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
    if (m_worker->isRunning()) {
        stop();
    }

    delete m_worker;
}

void SimplePTT::start()
{
	qDebug("SimplePTT::start");

    m_worker->reset();
    m_worker->setMessageQueueToGUI(getMessageQueueToGUI());
    bool ok = m_worker->startWork();
    m_state = ok ? StRunning : StError;
    m_thread.start();

    SimplePTTWorker::MsgConfigureSimplePTTWorker *msg = SimplePTTWorker::MsgConfigureSimplePTTWorker::create(m_settings, true);
    m_worker->getInputMessageQueue()->push(msg);
}

void SimplePTT::stop()
{
    qDebug("SimplePTT::stop");
	m_worker->stopWork();
    m_state = StIdle;
	m_thread.quit();
	m_thread.wait();
}

bool SimplePTT::handleMessage(const Message& cmd)
{
	if (MsgConfigureSimplePTT::match(cmd))
	{
        MsgConfigureSimplePTT& cfg = (MsgConfigureSimplePTT&) cmd;
        qDebug() << "SimplePTT::handleMessage: MsgConfigureSimplePTT";
        applySettings(cfg.getSettings(), cfg.getForce());

		return true;
	}
    else if (MsgPTT::match(cmd))
    {
        MsgPTT& cfg = (MsgPTT&) cmd;
        m_ptt = cfg.getTx();
        qDebug() << "SimplePTT::handleMessage: MsgPTT: tx:" << m_ptt;

        SimplePTTWorker::MsgPTT *msg = SimplePTTWorker::MsgPTT::create(m_ptt);
        m_worker->getInputMessageQueue()->push(msg);

        return true;
    }
    else if (MsgStartStop::match(cmd))
    {
        MsgStartStop& cfg = (MsgStartStop&) cmd;
        qDebug() << "SimplePTT::handleMessage: MsgStartStop: start:" << cfg.getStartStop();

        if (cfg.getStartStop()) {
            start();
        } else {
            stop();
        }

        return true;
    }
	else
	{
		return false;
	}
}

QByteArray SimplePTT::serialize() const
{
    return m_settings.serialize();
}

bool SimplePTT::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureSimplePTT *msg = MsgConfigureSimplePTT::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureSimplePTT *msg = MsgConfigureSimplePTT::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void SimplePTT::applySettings(const SimplePTTSettings& settings, bool force)
{
    qDebug() << "SimplePTT::applySettings:"
            << " m_title: " << settings.m_title
            << " m_rgbColor: " << settings.m_rgbColor
            << " m_rxDeviceSetIndex: " << settings.m_rxDeviceSetIndex
            << " m_txDeviceSetIndex: " << settings.m_txDeviceSetIndex
            << " m_rx2TxDelayMs: " << settings.m_rx2TxDelayMs
            << " m_tx2RxDelayMs: " << settings.m_tx2RxDelayMs
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_title != settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((m_settings.m_rgbColor != settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }
    if ((m_settings.m_rxDeviceSetIndex != settings.m_rxDeviceSetIndex) || force) {
        reverseAPIKeys.append("rxDeviceSetIndex");
    }
    if ((m_settings.m_txDeviceSetIndex != settings.m_txDeviceSetIndex) || force) {
        reverseAPIKeys.append("txDeviceSetIndex");
    }
    if ((m_settings.m_rx2TxDelayMs != settings.m_rx2TxDelayMs) || force) {
        reverseAPIKeys.append("rx2TxDelayMs");
    }
    if ((m_settings.m_tx2RxDelayMs != settings.m_tx2RxDelayMs) || force) {
        reverseAPIKeys.append("tx2RxDelayMs");
    }

    SimplePTTWorker::MsgConfigureSimplePTTWorker *msg = SimplePTTWorker::MsgConfigureSimplePTTWorker::create(
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

int SimplePTT::webapiRun(bool run,
    SWGrpx-100::SWGDeviceState& response,
    QString& errorMessage)
{
    (void) errorMessage;
    getFeatureStateStr(*response.getState());
    MsgStartStop *msg = MsgStartStop::create(run);
    getInputMessageQueue()->push(msg);
    return 202;
}

int SimplePTT::webapiSettingsGet(
    SWGrpx-100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setSimplePttSettings(new SWGrpx-100::SWGSimplePTTSettings());
    response.getSimplePttSettings()->init();
    webapiFormatFeatureSettings(response, m_settings);
    return 200;
}

int SimplePTT::webapiSettingsPutPatch(
    bool force,
    const QStringList& featureSettingsKeys,
    SWGrpx-100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    SimplePTTSettings settings = m_settings;
    webapiUpdateFeatureSettings(settings, featureSettingsKeys, response);

    MsgConfigureSimplePTT *msg = MsgConfigureSimplePTT::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("SimplePTT::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureSimplePTT *msgToGUI = MsgConfigureSimplePTT::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatFeatureSettings(response, settings);

    return 200;
}

int SimplePTT::webapiReportGet(
    SWGrpx-100::SWGFeatureReport& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setSimplePttReport(new SWGrpx-100::SWGSimplePTTReport());
    response.getSimplePttReport()->init();
    webapiFormatFeatureReport(response);
    return 200;
}

int SimplePTT::webapiActionsPost(
    const QStringList& featureActionsKeys,
    SWGrpx-100::SWGFeatureActions& query,
    QString& errorMessage)
{
    SWGrpx-100::SWGSimplePTTActions *swgSimplePTTActions = query.getSimplePttActions();

    if (swgSimplePTTActions)
    {
        if (featureActionsKeys.contains("ptt"))
        {
            bool ptt = swgSimplePTTActions->getPtt() != 0;

            MsgPTT *msg = MsgPTT::create(ptt);
            getInputMessageQueue()->push(msg);

            if (getMessageQueueToGUI())
            {
                MsgPTT *msgToGUI = MsgPTT::create(ptt);
                getMessageQueueToGUI()->push(msgToGUI);
            }
        }

        return 202;
    }
    else
    {
        errorMessage = "Missing SimplePTTActions in query";
        return 400;
    }
}

void SimplePTT::webapiFormatFeatureSettings(
    SWGrpx-100::SWGFeatureSettings& response,
    const SimplePTTSettings& settings)
{
    if (response.getSimplePttSettings()->getTitle()) {
        *response.getSimplePttSettings()->getTitle() = settings.m_title;
    } else {
        response.getSimplePttSettings()->setTitle(new QString(settings.m_title));
    }

    response.getSimplePttSettings()->setRgbColor(settings.m_rgbColor);
    response.getSimplePttSettings()->setRxDeviceSetIndex(settings.m_rxDeviceSetIndex);
    response.getSimplePttSettings()->setTxDeviceSetIndex(settings.m_txDeviceSetIndex);
    response.getSimplePttSettings()->setRx2TxDelayMs(settings.m_rx2TxDelayMs);
    response.getSimplePttSettings()->setTx2RxDelayMs(settings.m_tx2RxDelayMs);

    response.getSimplePttSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getSimplePttSettings()->getReverseApiAddress()) {
        *response.getSimplePttSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getSimplePttSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getSimplePttSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getSimplePttSettings()->setReverseApiFeatureSetIndex(settings.m_reverseAPIFeatureSetIndex);
    response.getSimplePttSettings()->setReverseApiFeatureIndex(settings.m_reverseAPIFeatureIndex);
}

void SimplePTT::webapiUpdateFeatureSettings(
    SimplePTTSettings& settings,
    const QStringList& featureSettingsKeys,
    SWGrpx-100::SWGFeatureSettings& response)
{
    if (featureSettingsKeys.contains("title")) {
        settings.m_title = *response.getSimplePttSettings()->getTitle();
    }
    if (featureSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getSimplePttSettings()->getRgbColor();
    }
    if (featureSettingsKeys.contains("rxDeviceSetIndex")) {
        settings.m_rxDeviceSetIndex = response.getSimplePttSettings()->getRxDeviceSetIndex();
    }
    if (featureSettingsKeys.contains("txDeviceSetIndex")) {
        settings.m_txDeviceSetIndex = response.getSimplePttSettings()->getTxDeviceSetIndex();
    }
    if (featureSettingsKeys.contains("rx2TxDelayMs")) {
        settings.m_rx2TxDelayMs = response.getSimplePttSettings()->getRx2TxDelayMs();
    }
    if (featureSettingsKeys.contains("tx2RxDelayMs")) {
        settings.m_tx2RxDelayMs = response.getSimplePttSettings()->getTx2RxDelayMs();
    }
    if (featureSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getSimplePttSettings()->getUseReverseApi() != 0;
    }
    if (featureSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getSimplePttSettings()->getReverseApiAddress();
    }
    if (featureSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getSimplePttSettings()->getReverseApiPort();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureSetIndex")) {
        settings.m_reverseAPIFeatureSetIndex = response.getSimplePttSettings()->getReverseApiFeatureSetIndex();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureIndex")) {
        settings.m_reverseAPIFeatureIndex = response.getSimplePttSettings()->getReverseApiFeatureIndex();
    }
}

void SimplePTT::webapiFormatFeatureReport(SWGrpx-100::SWGFeatureReport& response)
{
    response.getSimplePttReport()->setPtt(m_ptt ? 1 : 0);
}

void SimplePTT::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const SimplePTTSettings& settings, bool force)
{
    SWGrpx-100::SWGFeatureSettings *swgFeatureSettings = new SWGrpx-100::SWGFeatureSettings();
    // swgFeatureSettings->setOriginatorFeatureIndex(getIndexInDeviceSet());
    // swgFeatureSettings->setOriginatorFeatureSetIndex(getDeviceSetIndex());
    swgFeatureSettings->setFeatureType(new QString("SimplePTT"));
    swgFeatureSettings->setSimplePttSettings(new SWGrpx-100::SWGSimplePTTSettings());
    SWGrpx-100::SWGSimplePTTSettings *swgSimplePTTSettings = swgFeatureSettings->getSimplePttSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("title") || force) {
        swgSimplePTTSettings->setTitle(new QString(settings.m_title));
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgSimplePTTSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("rxDeviceSetIndex") || force) {
        swgSimplePTTSettings->setRxDeviceSetIndex(settings.m_rxDeviceSetIndex);
    }
    if (channelSettingsKeys.contains("txDeviceSetIndex") || force) {
        swgSimplePTTSettings->setTxDeviceSetIndex(settings.m_txDeviceSetIndex);
    }
    if (channelSettingsKeys.contains("rx2TxDelayMs") || force) {
        swgSimplePTTSettings->setRx2TxDelayMs(settings.m_rx2TxDelayMs);
    }
    if (channelSettingsKeys.contains("tx2RxDelayMs") || force) {
        swgSimplePTTSettings->setTx2RxDelayMs(settings.m_tx2RxDelayMs);
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

void SimplePTT::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "SimplePTT::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("SimplePTT::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
