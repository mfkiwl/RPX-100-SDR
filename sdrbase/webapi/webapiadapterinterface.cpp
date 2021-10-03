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

#include "webapiadapterinterface.h"

QString WebAPIAdapterInterface::instanceSummaryURL = "/RPX100";
QString WebAPIAdapterInterface::instanceConfigURL = "/RPX100/config";
QString WebAPIAdapterInterface::instanceDevicesURL = "/RPX100/devices";
QString WebAPIAdapterInterface::instanceChannelsURL = "/RPX100/channels";
QString WebAPIAdapterInterface::instanceFeaturesURL = "/RPX100/features";
QString WebAPIAdapterInterface::instanceLoggingURL = "/RPX100/logging";
QString WebAPIAdapterInterface::instanceAudioURL = "/RPX100/audio";
QString WebAPIAdapterInterface::instanceAudioInputParametersURL = "/RPX100/audio/input/parameters";
QString WebAPIAdapterInterface::instanceAudioOutputParametersURL = "/RPX100/audio/output/parameters";
QString WebAPIAdapterInterface::instanceAudioInputCleanupURL = "/RPX100/audio/input/cleanup";
QString WebAPIAdapterInterface::instanceAudioOutputCleanupURL = "/RPX100/audio/output/cleanup";
QString WebAPIAdapterInterface::instanceLocationURL = "/RPX100/location";
QString WebAPIAdapterInterface::instanceAMBESerialURL = "/RPX100/ambe/serial";
QString WebAPIAdapterInterface::instanceAMBEDevicesURL = "/RPX100/ambe/devices";
QString WebAPIAdapterInterface::instanceLimeRFESerialURL = "/RPX100/limerfe/serial";
QString WebAPIAdapterInterface::instanceLimeRFEConfigURL = "/RPX100/limerfe/config";
QString WebAPIAdapterInterface::instanceLimeRFERunURL = "/RPX100/limerfe/run";
QString WebAPIAdapterInterface::instanceLimeRFEPowerURL = "/RPX100/limerfe/power";
QString WebAPIAdapterInterface::instancePresetsURL = "/RPX100/presets";
QString WebAPIAdapterInterface::instancePresetURL = "/RPX100/preset";
QString WebAPIAdapterInterface::instancePresetFileURL = "/RPX100/preset/file";
QString WebAPIAdapterInterface::instanceFeaturePresetsURL = "/RPX100/featurepresets";
QString WebAPIAdapterInterface::instanceFeaturePresetURL = "/RPX100/featurepreset";
QString WebAPIAdapterInterface::instanceDeviceSetsURL = "/RPX100/devicesets";
QString WebAPIAdapterInterface::instanceDeviceSetURL = "/RPX100/deviceset";
QString WebAPIAdapterInterface::instanceFeatureSetsURL = "/RPX100/featuresets";
QString WebAPIAdapterInterface::instanceFeatureSetURL = "/RPX100/featureset";

std::regex WebAPIAdapterInterface::devicesetURLRe("^/RPX100/deviceset/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::devicesetFocusURLRe("^/RPX100/deviceset/([0-9]{1,2})/focus$");
std::regex WebAPIAdapterInterface::devicesetSpectrumSettingsURLRe("^/RPX100/deviceset/([0-9]{1,2})/spectrum/settings$");
std::regex WebAPIAdapterInterface::devicesetSpectrumServerURLRe("^/RPX100/deviceset/([0-9]{1,2})/spectrum/server$");
std::regex WebAPIAdapterInterface::devicesetDeviceURLRe("^/RPX100/deviceset/([0-9]{1,2})/device$");
std::regex WebAPIAdapterInterface::devicesetDeviceSettingsURLRe("^/RPX100/deviceset/([0-9]{1,2})/device/settings$");
std::regex WebAPIAdapterInterface::devicesetDeviceRunURLRe("^/RPX100/deviceset/([0-9]{1,2})/device/run$");
std::regex WebAPIAdapterInterface::devicesetDeviceSubsystemRunURLRe("^/RPX100/deviceset/([0-9]{1,2})/subdevice/([0-9]{1,2})/run$");
std::regex WebAPIAdapterInterface::devicesetDeviceReportURLRe("^/RPX100/deviceset/([0-9]{1,2})/device/report$");
std::regex WebAPIAdapterInterface::devicesetDeviceActionsURLRe("^/RPX100/deviceset/([0-9]{1,2})/device/actions$");
std::regex WebAPIAdapterInterface::devicesetChannelsReportURLRe("^/RPX100/deviceset/([0-9]{1,2})/channels/report$");
std::regex WebAPIAdapterInterface::devicesetChannelURLRe("^/RPX100/deviceset/([0-9]{1,2})/channel$");
std::regex WebAPIAdapterInterface::devicesetChannelIndexURLRe("^/RPX100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::devicesetChannelSettingsURLRe("^/RPX100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})/settings$");
std::regex WebAPIAdapterInterface::devicesetChannelReportURLRe("^/RPX100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})/report");
std::regex WebAPIAdapterInterface::devicesetChannelActionsURLRe("^/RPX100/deviceset/([0-9]{1,2})/channel/([0-9]{1,2})/actions");

std::regex WebAPIAdapterInterface::featuresetURLRe("^/RPX100/featureset/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::featuresetFeatureURLRe("^/RPX100/featureset/([0-9]{1,2})/feature$");
std::regex WebAPIAdapterInterface::featuresetPresetURLRe("^/RPX100/featureset/([0-9]{1,2})/preset");
std::regex WebAPIAdapterInterface::featuresetFeatureIndexURLRe("^/RPX100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})$");
std::regex WebAPIAdapterInterface::featuresetFeatureRunURLRe("^/RPX100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/run$");
std::regex WebAPIAdapterInterface::featuresetFeatureSettingsURLRe("^/RPX100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/settings$");
std::regex WebAPIAdapterInterface::featuresetFeatureReportURLRe("^/RPX100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/report");
std::regex WebAPIAdapterInterface::featuresetFeatureActionsURLRe("^/RPX100/featureset/([0-9]{1,2})/feature/([0-9]{1,2})/actions");

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
