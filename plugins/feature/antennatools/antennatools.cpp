///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
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
#include "SWGDeviceState.h"

#include "dsp/dspengine.h"

#include "device/deviceset.h"
#include "channel/channelapi.h"
#include "feature/featureset.h"
#include "maincore.h"
#include "antennatools.h"

MESSAGE_CLASS_DEFINITION(AntennaTools::MsgConfigureAntennaTools, Message)

const char* const AntennaTools::m_featureIdURI = "RPX100.feature.antennatools";
const char* const AntennaTools::m_featureId = "AntennaTools";

AntennaTools::AntennaTools(WebAPIAdapterInterface *webAPIAdapterInterface) :
    Feature(m_featureIdURI, webAPIAdapterInterface)
{
    qDebug("AntennaTools::AntennaTools: webAPIAdapterInterface: %p", webAPIAdapterInterface);
    setObjectName(m_featureId);
    m_state = StIdle;
    m_errorMessage = "AntennaTools error";
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
}

AntennaTools::~AntennaTools()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
}

bool AntennaTools::handleMessage(const Message& cmd)
{
    if (MsgConfigureAntennaTools::match(cmd))
    {
        MsgConfigureAntennaTools& cfg = (MsgConfigureAntennaTools&) cmd;
        qDebug() << "AntennaTools::handleMessage: MsgConfigureAntennaTools";
        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else
    {
        return false;
    }
}

QByteArray AntennaTools::serialize() const
{
    return m_settings.serialize();
}

bool AntennaTools::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureAntennaTools *msg = MsgConfigureAntennaTools::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureAntennaTools *msg = MsgConfigureAntennaTools::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void AntennaTools::applySettings(const AntennaToolsSettings& settings, bool force)
{
    qDebug() << "AntennaTools::applySettings:"
            << " m_title: " << settings.m_title
            << " m_rgbColor: " << settings.m_rgbColor
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIFeatureSetIndex: " << settings.m_reverseAPIFeatureSetIndex
            << " m_reverseAPIFeatureIndex: " << settings.m_reverseAPIFeatureIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_dipoleFrequencyMHz != settings.m_dipoleFrequencyMHz) || force) {
        reverseAPIKeys.append("dipoleFrequencyMHz");
    }
    if ((m_settings.m_dipoleEndEffectFactor != settings.m_dipoleEndEffectFactor) || force) {
        reverseAPIKeys.append("dipoleEndEffectFactor");
    }
    if ((m_settings.m_dishFrequencyMHz != settings.m_dishFrequencyMHz) || force) {
        reverseAPIKeys.append("dishFrequencyMHz");
    }
    if ((m_settings.m_dishDiameter != settings.m_dishDiameter) || force) {
        reverseAPIKeys.append("dishDiameter");
    }
    if ((m_settings.m_dishDepth != settings.m_dishDepth) || force) {
        reverseAPIKeys.append("dishDepth");
    }
    if ((m_settings.m_dishEfficiency != settings.m_dishEfficiency) || force) {
        reverseAPIKeys.append("dishEfficiency");
    }
    if ((m_settings.m_title != settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((m_settings.m_rgbColor != settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }

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

int AntennaTools::webapiSettingsGet(
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setAntennaToolsSettings(new SWGRPX100::SWGAntennaToolsSettings());
    response.getAntennaToolsSettings()->init();
    webapiFormatFeatureSettings(response, m_settings);
    return 200;
}

int AntennaTools::webapiSettingsPutPatch(
    bool force,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    AntennaToolsSettings settings = m_settings;
    webapiUpdateFeatureSettings(settings, featureSettingsKeys, response);

    MsgConfigureAntennaTools *msg = MsgConfigureAntennaTools::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureAntennaTools *msgToGUI = MsgConfigureAntennaTools::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatFeatureSettings(response, settings);

    return 200;
}

void AntennaTools::webapiFormatFeatureSettings(
    SWGRPX100::SWGFeatureSettings& response,
    const AntennaToolsSettings& settings)
{
    response.getAntennaToolsSettings()->setDipoleFrequencyMHz(settings.m_dipoleFrequencyMHz);
    response.getAntennaToolsSettings()->setDipoleEndEffectFactor(settings.m_dipoleEndEffectFactor);
    response.getAntennaToolsSettings()->setDishFrequencyMHz(settings.m_dishFrequencyMHz);
    response.getAntennaToolsSettings()->setDishDiameter(settings.m_dishDiameter);
    response.getAntennaToolsSettings()->setDishDepth(settings.m_dishDepth);
    response.getAntennaToolsSettings()->setDishEfficiency(settings.m_dishEfficiency);
    if (response.getAntennaToolsSettings()->getTitle()) {
        *response.getAntennaToolsSettings()->getTitle() = settings.m_title;
    } else {
        response.getAntennaToolsSettings()->setTitle(new QString(settings.m_title));
    }

    response.getAntennaToolsSettings()->setRgbColor(settings.m_rgbColor);
    response.getAntennaToolsSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getAntennaToolsSettings()->getReverseApiAddress()) {
        *response.getAntennaToolsSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getAntennaToolsSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getAntennaToolsSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getAntennaToolsSettings()->setReverseApiFeatureSetIndex(settings.m_reverseAPIFeatureSetIndex);
    response.getAntennaToolsSettings()->setReverseApiFeatureIndex(settings.m_reverseAPIFeatureIndex);
}

void AntennaTools::webapiUpdateFeatureSettings(
    AntennaToolsSettings& settings,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response)
{
    if (featureSettingsKeys.contains("dipoleFrequencyMHz")) {
        settings.m_dipoleFrequencyMHz = response.getAntennaToolsSettings()->getDipoleFrequencyMHz();
    }
    if (featureSettingsKeys.contains("dipoleEndEffectFactor")) {
        settings.m_dipoleEndEffectFactor = response.getAntennaToolsSettings()->getDipoleEndEffectFactor();
    }
    if (featureSettingsKeys.contains("dishFrequencyMHz")) {
        settings.m_dishFrequencyMHz = response.getAntennaToolsSettings()->getDishFrequencyMHz();
    }
    if (featureSettingsKeys.contains("dishDiameter")) {
        settings.m_dishDiameter = response.getAntennaToolsSettings()->getDishDiameter();
    }
    if (featureSettingsKeys.contains("dishDepth")) {
        settings.m_dishDepth = response.getAntennaToolsSettings()->getDishDepth();
    }
    if (featureSettingsKeys.contains("dishEfficiency")) {
        settings.m_dishEfficiency = response.getAntennaToolsSettings()->getDishEfficiency();
    }
    if (featureSettingsKeys.contains("title")) {
        settings.m_title = *response.getAntennaToolsSettings()->getTitle();
    }
    if (featureSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getAntennaToolsSettings()->getRgbColor();
    }
    if (featureSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getAntennaToolsSettings()->getUseReverseApi() != 0;
    }
    if (featureSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getAntennaToolsSettings()->getReverseApiAddress();
    }
    if (featureSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getAntennaToolsSettings()->getReverseApiPort();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureSetIndex")) {
        settings.m_reverseAPIFeatureSetIndex = response.getAntennaToolsSettings()->getReverseApiFeatureSetIndex();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureIndex")) {
        settings.m_reverseAPIFeatureIndex = response.getAntennaToolsSettings()->getReverseApiFeatureIndex();
    }
}

void AntennaTools::webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const AntennaToolsSettings& settings, bool force)
{
    SWGRPX100::SWGFeatureSettings *swgFeatureSettings = new SWGRPX100::SWGFeatureSettings();
    // swgFeatureSettings->setOriginatorFeatureIndex(getIndexInDeviceSet());
    // swgFeatureSettings->setOriginatorFeatureSetIndex(getDeviceSetIndex());
    swgFeatureSettings->setFeatureType(new QString("AntennaTools"));
    swgFeatureSettings->setAntennaToolsSettings(new SWGRPX100::SWGAntennaToolsSettings());
    SWGRPX100::SWGAntennaToolsSettings *swgAntennaToolsSettings = swgFeatureSettings->getAntennaToolsSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (featureSettingsKeys.contains("dipoleFrequencyMHz") || force) {
        swgAntennaToolsSettings->setDipoleFrequencyMHz(settings.m_dipoleFrequencyMHz);
    }
    if (featureSettingsKeys.contains("dipoleEndEffectFactor") || force) {
        swgAntennaToolsSettings->setDipoleEndEffectFactor(settings.m_dipoleEndEffectFactor);
    }
    if (featureSettingsKeys.contains("dishFrequencyMHz") || force) {
        swgAntennaToolsSettings->setDishFrequencyMHz(settings.m_dishFrequencyMHz);
    }
    if (featureSettingsKeys.contains("dishDiameter") || force) {
        swgAntennaToolsSettings->setDishDiameter(settings.m_dishDiameter);
    }
    if (featureSettingsKeys.contains("dishDepth") || force) {
        swgAntennaToolsSettings->setDishDepth(settings.m_dishDepth);
    }
    if (featureSettingsKeys.contains("dishEfficiency") || force) {
        swgAntennaToolsSettings->setDishEfficiency(settings.m_dishEfficiency);
    }
    if (featureSettingsKeys.contains("title") || force) {
        swgAntennaToolsSettings->setTitle(new QString(settings.m_title));
    }
    if (featureSettingsKeys.contains("rgbColor") || force) {
        swgAntennaToolsSettings->setRgbColor(settings.m_rgbColor);
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

void AntennaTools::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "AntennaTools::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("AntennaTools::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}
