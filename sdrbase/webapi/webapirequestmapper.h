///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Bernhard Isemann, oe3bia.                                  //
//                                                                               //
// Swagger server adapter interface                                              //
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

#ifndef SDRBASE_WEBAPI_WEBAPIREQUESTMAPPER_H_
#define SDRBASE_WEBAPI_WEBAPIREQUESTMAPPER_H_

#include <QJsonParseError>

#include "httprequesthandler.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "staticfilecontroller.h"
#include "webapiadapterinterface.h"

#include "export.h"

namespace SWGRPX100
{
    class SWGPresetTransfer;
    class SWGPresetIdentifier;
    class SWGPreset;
    class SWGChannelConfig;
    class SWGDeviceConfig;
    class SWGFeatureConfig;
    class SWGFeatureActions;
    class SWGFeatureSetPreset;
}

class SDRBASE_API WebAPIRequestMapper : public qtwebapp::HttpRequestHandler {
    Q_OBJECT
public:
    WebAPIRequestMapper(QObject* parent=0);
    ~WebAPIRequestMapper();
    void service(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void setAdapter(WebAPIAdapterInterface *adapter) { m_adapter = adapter; }

private:
    WebAPIAdapterInterface *m_adapter;
    qtwebapp::StaticFileController *m_staticFileController;

    void instanceSummaryService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceConfigService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceDevicesService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceChannelsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceFeaturesService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceLoggingService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAudioService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAudioInputParametersService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAudioOutputParametersService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAudioInputCleanupService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAudioOutputCleanupService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceLocationService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceDVSerialService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAMBESerialService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceAMBEDevicesService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceLimeRFESerialService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceLimeRFEConfigService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceLimeRFERunService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceLimeRFEPowerService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instancePresetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instancePresetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instancePresetFileService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceFeaturePresetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceFeaturePresetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceDeviceSetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceDeviceSetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceFeatureSetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void instanceFeatureSetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);

    void devicesetService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetFocusService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetSpectrumSettingsService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetSpectrumServerService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetDeviceService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetDeviceSettingsService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetDeviceRunService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetDeviceSubsystemRunService(const std::string& indexStr, const std::string& subsystemIndexStr,qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetDeviceReportService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetDeviceActionsService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetChannelsReportService(const std::string& deviceSetIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetChannelService(const std::string& deviceSetIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetChannelIndexService(const std::string& deviceSetIndexStr, const std::string& channelIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetChannelSettingsService(const std::string& deviceSetIndexStr, const std::string& channelIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetChannelReportService(const std::string& deviceSetIndexStr, const std::string& channelIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void devicesetChannelActionsService(const std::string& deviceSetIndexStr, const std::string& channelIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);

    void featuresetService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetFeatureService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetPresetService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetFeatureIndexService(const std::string& featureSetIndexStr, const std::string& featureIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetFeatureRunService(const std::string& featureSetIndexStr, const std::string& featureIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetFeatureSettingsService(const std::string& featureSetIndexStr, const std::string& featureIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetFeatureReportService(const std::string& featureSetIndexStr, const std::string& featureIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);
    void featuresetFeatureActionsService(const std::string& featureSetIndexStr, const std::string& featureIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response);

    bool validatePresetTransfer(SWGRPX100::SWGPresetTransfer& presetTransfer);
    bool validatePresetIdentifer(SWGRPX100::SWGPresetIdentifier& presetIdentifier);
    bool validatePresetExport(SWGRPX100::SWGPresetExport& presetExport);
    bool validateSpectrumSettings(SWGRPX100::SWGGLSpectrum& spectrumSettings, QJsonObject& jsonObject, QStringList& spectrumSettingsKeys);
    bool validateDeviceListItem(SWGRPX100::SWGDeviceListItem& deviceListItem, QJsonObject& jsonObject);
    bool validateDeviceSettings(SWGRPX100::SWGDeviceSettings& deviceSettings, QJsonObject& jsonObject, QStringList& deviceSettingsKeys);
    bool validateDeviceActions(SWGRPX100::SWGDeviceActions& deviceActions, QJsonObject& jsonObject, QStringList& deviceActionsKeys);
    bool validateChannelSettings(SWGRPX100::SWGChannelSettings& channelSettings, QJsonObject& jsonObject, QStringList& channelSettingsKeys);
    bool validateChannelActions(SWGRPX100::SWGChannelActions& channelActions, QJsonObject& jsonObject, QStringList& channelActionsKeys);
    bool validateFeaturePresetTransfer(SWGRPX100::SWGFeaturePresetTransfer& presetTransfer);
    bool validateFeaturePresetIdentifer(SWGRPX100::SWGFeaturePresetIdentifier& presetIdentifier);
    bool validateFeatureSettings(SWGRPX100::SWGFeatureSettings& featureSettings, QJsonObject& jsonObject, QStringList& featureSettingsKeys);
    bool validateFeatureActions(SWGRPX100::SWGFeatureActions& featureActions, QJsonObject& jsonObject, QStringList& featureActionsKeys);
    bool validateAudioInputDevice(SWGRPX100::SWGAudioInputDevice& audioInputDevice, QJsonObject& jsonObject, QStringList& audioInputDeviceKeys);
    bool validateAudioOutputDevice(SWGRPX100::SWGAudioOutputDevice& audioOutputDevice, QJsonObject& jsonObject, QStringList& audioOutputDeviceKeys);
    bool validateAMBEDevices(SWGRPX100::SWGAMBEDevices& ambeDevices, QJsonObject& jsonObject);
    bool validateLimeRFEConfig(SWGRPX100::SWGLimeRFESettings& limeRFESettings, QJsonObject& jsonObject, QStringList& limeRFESettingsKeys);
    bool validateConfig(SWGRPX100::SWGInstanceConfigResponse& config, QJsonObject& jsonObject, WebAPIAdapterInterface::ConfigKeys& configKeys);

    bool appendFeatureSetPresetKeys(
        SWGRPX100::SWGFeatureSetPreset *preset,
        const QJsonObject& presetJson,
        WebAPIAdapterInterface::FeatureSetPresetKeys& featureSetPresetKeys
    );

    bool appendPresetKeys(
            SWGRPX100::SWGPreset *preset,
            const QJsonObject& presetJson,
            WebAPIAdapterInterface::PresetKeys& presetKeys);

    bool appendPresetFeatureKeys(
        SWGRPX100::SWGFeatureConfig *feature,
        const QJsonObject& featureSettingsJson,
        WebAPIAdapterInterface::FeatureKeys& featureKeys
    );

    bool appendPresetChannelKeys(
            SWGRPX100::SWGChannelConfig *channel,
            const QJsonObject& channelSettngsJson,
            WebAPIAdapterInterface::ChannelKeys& channelKeys
    );

    bool getChannelSettings(
        const QString& channelSettingsKey,
        SWGRPX100::SWGChannelSettings *channelSettings,
        const QJsonObject& channelSettingsJson,
        QStringList& channelSettingsKeys
    );

    bool getChannelActions(
        const QString& channelActionsKey,
        SWGRPX100::SWGChannelActions *channelActions,
        const QJsonObject& channelActionsJson,
        QStringList& channelSettingsKeys
    );

    bool appendPresetDeviceKeys(
            SWGRPX100::SWGDeviceConfig *device,
            const QJsonObject& deviceSettngsJson,
            WebAPIAdapterInterface::DeviceKeys& devicelKeys
    );

    bool getDeviceSettings(
        const QString& deviceSettingsKey,
        SWGRPX100::SWGDeviceSettings *deviceSettings,
        const QJsonObject& deviceSettingsJson,
        QStringList& deviceActionsKeys
    );

    bool getDeviceActions(
        const QString& deviceActionsKey,
        SWGRPX100::SWGDeviceActions *deviceActions,
        const QJsonObject& deviceActionsJson,
        QStringList& deviceActionsKeys
    );

    void appendSettingsSubKeys(
            const QJsonObject& parentSettingsJsonObject,
            QJsonObject& childSettingsJsonObject,
            const QString& parentKey,
            QStringList& keyList);

    void appendSettingsArrayKeys(
            const QJsonObject& parentSettingsJsonObject,
            const QString& parentKey,
            QStringList& keyList);

    bool getFeatureSettings(
        const QString& featureSettingsKey,
        SWGRPX100::SWGFeatureSettings *featureSettings,
        const QJsonObject& featureSettingsJson,
        QStringList& featureSettingsKeys
    );

    bool getFeatureActions(
        const QString& featureActionsKey,
        SWGRPX100::SWGFeatureActions *featureActions,
        const QJsonObject& featureActionsJson,
        QStringList& featureSettingsKeys
    );

    bool parseJsonBody(QString& jsonStr, QJsonObject& jsonObject, qtwebapp::HttpResponse& response);

    void resetSpectrumSettings(SWGRPX100::SWGGLSpectrum& spectrumSettings);
    void resetDeviceSettings(SWGRPX100::SWGDeviceSettings& deviceSettings);
    void resetDeviceReport(SWGRPX100::SWGDeviceReport& deviceReport);
    void resetDeviceActions(SWGRPX100::SWGDeviceActions& deviceActions);
    void resetChannelSettings(SWGRPX100::SWGChannelSettings& deviceSettings);
    void resetChannelReport(SWGRPX100::SWGChannelReport& channelReport);
    void resetChannelActions(SWGRPX100::SWGChannelActions& channelActions);
    void resetAudioInputDevice(SWGRPX100::SWGAudioInputDevice& audioInputDevice);
    void resetAudioOutputDevice(SWGRPX100::SWGAudioOutputDevice& audioOutputDevice);
    void resetFeatureSettings(SWGRPX100::SWGFeatureSettings& deviceSettings);
    void resetFeatureReport(SWGRPX100::SWGFeatureReport& featureReport);
    void resetFeatureActions(SWGRPX100::SWGFeatureActions& featureActions);

    void processChannelAnalyzerSettings(
        SWGRPX100::SWGChannelSettings *channelSettings,
        const QJsonObject& channelSettingsJson,
        QStringList& channelSettingsKeys
    );

    void processSoapySDRSettings(
        SWGRPX100::SWGDeviceSettings *deviceSettings,
        QJsonObject& deviceSettingsJson,
        QStringList& deviceSettingsKeys,
        bool inputElseOutput
    );

    static const QMap<QString, QString> m_channelURIToSettingsKey;
    static const QMap<QString, QString> m_deviceIdToSettingsKey;
    static const QMap<QString, QString> m_channelTypeToSettingsKey;
    static const QMap<QString, QString> m_sourceDeviceHwIdToSettingsKey;
    static const QMap<QString, QString> m_sinkDeviceHwIdToSettingsKey;
    static const QMap<QString, QString> m_mimoDeviceHwIdToSettingsKey;
    static const QMap<QString, QString> m_channelTypeToActionsKey;
    static const QMap<QString, QString> m_sourceDeviceHwIdToActionsKey;
    static const QMap<QString, QString> m_sinkDeviceHwIdToActionsKey;
    static const QMap<QString, QString> m_mimoDeviceHwIdToActionsKey;
    static const QMap<QString, QString> m_featureTypeToSettingsKey;
    static const QMap<QString, QString> m_featureTypeToActionsKey;
    static const QMap<QString, QString> m_featureURIToSettingsKey;
};

#endif /* SDRBASE_WEBAPI_WEBAPIREQUESTMAPPER_H_ */
