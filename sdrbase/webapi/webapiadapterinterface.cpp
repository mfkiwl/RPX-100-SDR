///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB.                                  //
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

#include "webapiadapterinterface.h"

QString WebAPIAdapterInterface::instanceSummaryURL = "/rpx-100";
QString WebAPIAdapterInterface::instanceConfigURL = "/rpx-100/config";
QString WebAPIAdapterInterface::instanceDevicesURL = "/rpx-100/devices";
QString WebAPIAdapterInterface::instanceChannelsURL = "/rpx-100/channels";
QString WebAPIAdapterInterface::instanceFeaturesURL = "/rpx-100/features";
QString WebAPIAdapterInterface::instanceLoggingURL = "/rpx-100/logging";
QString WebAPIAdapterInterface::instanceAudioURL = "/rpx-100/audio";
QString WebAPIAdapterInterface::instanceAudioInputParametersURL = "/rpx-100/audio/input/parameters";
QString WebAPIAdapterInterface::instanceAudioOutputParametersURL = "/rpx-100/audio/output/parameters";
QString WebAPIAdapterInterface::instanceAudioInputCleanupURL = "/rpx-100/audio/input/cleanup";
QString WebAPIAdapterInterface::instanceAudioOutputCleanupURL = "/rpx-100/audio/output/cleanup";
QString WebAPIAdapterInterface::instanceLocationURL = "/rpx-100/location";
QString WebAPIAdapterInterface::instanceAMBESerialURL = "/rpx-100/ambe/serial";
QString WebAPIAdapterInterface::instanceAMBEDevicesURL = "/rpx-100/ambe/devices";
QString WebAPIAdapterInterface::instanceLimeRFESerialURL = "/rpx-100/limerfe/serial";
QString WebAPIAdapterInterface::instanceLimeRFEConfigURL = "/rpx-100/limerfe/config";
QString WebAPIAdapterInterface::instanceLimeRFERunURL = "/rpx-100/limerfe/run";
QString WebAPIAdapterInterface::instanceLimeRFEPowerURL = "/rpx-100/limerfe/power";
QString WebAPIAdapterInterface::instancePresetsURL = "/rpx-100/presets";
QString WebAPIAdapterInterface::instancePresetURL = "/rpx-100/preset";
QString WebAPIAdapterInterface::instancePresetFileURL = "/rpx-100/preset/file";
QString WebAPIAdapterInterface::instanceFeaturePresetsURL = "/rpx-100/featurepresets";
QString WebAPIAdapterInterface::instanceFeaturePresetURL = "/rpx-100/featurepreset";
QString WebAPIAdapterInterface::instanceDeviceSetsURL = "/rpx-100/devicesets";
QString WebAPIAdapterInterface::instanceDeviceSetURL = "/rpx-100/deviceset";
QString WebAPIAdapterInterface::instanceFeatureSetsURL = "/rpx-100/featuresets";
QString WebAPIAdapterInterface::instanceFeatureSetURL = "/rpx-100/featureset";

std::regex WebAPIAdapterInterface::devicesetURLRe("^/rpx-100/deviceset/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::devicesetFocusURLRe("^/rpx-100/deviceset/([0-9]{1,2})/focus$");
std::regex WebAPIAdapterInterface::devicesetSpectrumSettingsURLRe("^/rpx-100/deviceset/([0-9]{1,2})/spectrum/settings$");
std::regex WebAPIAdapterInterface::devicesetSpectrumServerURLRe("^/rpx-100/deviceset/([0-9]{1,2})/spectrum/server$");
std::regex WebAPIAdapterInterface::devicesetDeviceURLRe("^/rpx-100/deviceset/([0-9]{1,2})/device$");
std::regex WebAPIAdapterInterface::devicesetDeviceSettingsURLRe("^/rpx-100/deviceset/([0-9]{1,2})/device/settings$");
std::regex WebAPIAdapterInterface::devicesetDeviceRunURLRe("^/rpx-100/deviceset/([0-9]{1,2})/device/run$");
std::regex WebAPIAdapterInterface::devicesetDeviceSubsystemRunURLRe("^/rpx-100/deviceset/([0-9]{1,2})/subdevice/([0-9]{1,2})/run$");
std::regex WebAPIAdapterInterface::devicesetDeviceReportURLRe("^/rpx-100/deviceset/([0-9]{1,2})/device/report$");
std::regex WebAPIAdapterInterface::devicesetDeviceActionsURLRe("^/rpx-100/deviceset/([0-9]{1,2})/device/actions$");
std::regex WebAPIAdapterInterface::devicesetChannelsReportURLRe("^/rpx-100/deviceset/([0-9]{1,2})/channels/report$");
std::regex WebAPIAdapterInterface::devicesetChannelURLRe("^/rpx-100/deviceset/([0-9]{1,2})/channel$");
std::regex WebAPIAdapterInterface::devicesetChannelIndexURLRe("^/rpx-100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::devicesetChannelSettingsURLRe("^/rpx-100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})/settings$");
std::regex WebAPIAdapterInterface::devicesetChannelReportURLRe("^/rpx-100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})/report");
std::regex WebAPIAdapterInterface::devicesetChannelActionsURLRe("^/rpx-100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})/actions");

std::regex WebAPIAdapterInterface::featuresetURLRe("^/rpx-100/featureset/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::featuresetFeatureURLRe("^/rpx-100/featureset/([0-9]{1,2})/feature$");
std::regex WebAPIAdapterInterface::featuresetPresetURLRe("^/rpx-100/featureset/([0-9]{1,2})/preset");
std::regex WebAPIAdapterInterface::featuresetFeatureIndexURLRe("^/rpx-100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::featuresetFeatureRunURLRe("^/rpx-100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/run$");
std::regex WebAPIAdapterInterface::featuresetFeatureSettingsURLRe("^/rpx-100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/settings$");
std::regex WebAPIAdapterInterface::featuresetFeatureReportURLRe("^/rpx-100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/report");
std::regex WebAPIAdapterInterface::featuresetFeatureActionsURLRe("^/rpx-100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/actions");

void WebAPIAdapterInterface::ConfigKeys::debug() const
{
    qDebug("WebAPIAdapterInterface::ConfigKeys::debug");

    qDebug("preferences:");
    foreach(QString preferenceKey, m_preferencesKeys) {
        qDebug("  %s", qPrintable(preferenceKey));
    }

    qDebug("commands:");
    foreach(CommandKeys commandKeys, m_commandKeys)
    {
        qDebug("  {");
        foreach(QString commandKey, commandKeys.m_keys) {
            qDebug("    %s", qPrintable(commandKey));
        }
        qDebug("  }");
    }

    qDebug("presets:");
    foreach(PresetKeys presetKeys, m_presetKeys)
    {
        qDebug("  {");
        foreach(QString presetKey, presetKeys.m_keys) {
            qDebug("    %s", qPrintable(presetKey));
        }
        qDebug("    spectrumConfig:");
        foreach(QString spectrumKey, presetKeys.m_spectrumKeys) {
            qDebug("      %s", qPrintable(spectrumKey));
        }
        qDebug("    deviceConfigs:");
        foreach(DeviceKeys deviceKeys, presetKeys.m_devicesKeys)
        {
            qDebug("      {");
            qDebug("        config:");
            foreach(QString deviceKey, deviceKeys.m_deviceKeys) {
                qDebug("          %s", qPrintable(deviceKey));
            }
            qDebug("      }");
        }
        qDebug("    channelConfigs");
        foreach(ChannelKeys channelKeys, presetKeys.m_channelsKeys)
        {
            qDebug("      {");
            qDebug("        config:");
            foreach(QString channelKey, channelKeys.m_channelKeys) {
                qDebug("          %s", qPrintable(channelKey));
            }
            qDebug("      }");
        }
        qDebug("  }");
    }

    qDebug("featuresets:");
    foreach(FeatureSetPresetKeys presetKeys, m_featureSetPresetKeys)
    {
        qDebug("  {");
        foreach(QString presetKey, presetKeys.m_keys) {
            qDebug("    %s", qPrintable(presetKey));
        }
        qDebug("    featureConfigs");
        foreach(FeatureKeys featureKeys, presetKeys.m_featureKeys)
        {
            qDebug("      {");
            qDebug("        config:");
            foreach(QString featureKey, featureKeys.m_featureKeys) {
                qDebug("          %s", qPrintable(featureKey));
            }
            qDebug("      }");
        }
        qDebug("  }");
    }

    qDebug("workingPreset:");
    foreach(QString presetKey, m_workingPresetKeys.m_keys) {
        qDebug("  %s", qPrintable(presetKey));
    }
    qDebug("workingFeatureSetPreset:");
    foreach(QString presetKey, m_workingFeatureSetPresetKeys.m_keys) {
        qDebug("  %s", qPrintable(presetKey));
    }
    qDebug("  spectrumConfig:");
    foreach(QString spectrumKey, m_workingPresetKeys.m_spectrumKeys) {
        qDebug("    %s", qPrintable(spectrumKey));
    }
    qDebug("  deviceConfigs:");
    foreach(DeviceKeys deviceKeys, m_workingPresetKeys.m_devicesKeys)
    {
        qDebug("    {");
        qDebug("      config:");
        foreach(QString deviceKey, deviceKeys.m_deviceKeys) {
            qDebug("        %s", qPrintable(deviceKey));
        }
        qDebug("    }");
    }
    qDebug("  channelConfigs:");
    foreach(ChannelKeys channelKeys, m_workingPresetKeys.m_channelsKeys)
    {
        qDebug("    {");
        qDebug("      config:");
        foreach(QString channelKey, channelKeys.m_channelKeys) {
            qDebug("        %s", qPrintable(channelKey));
        }
        qDebug("    }");
    }
}
