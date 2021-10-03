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

#ifndef SDRBASE_WEBAPI_WEBAPIADAPTERINTERFACE_H_
#define SDRBASE_WEBAPI_WEBAPIADAPTERINTERFACE_H_

#include <QString>
#include <QStringList>
#include <regex>

#include "SWGErrorResponse.h"

#include "export.h"

namespace SWGRPX100
{
    class SWGInstanceSummaryResponse;
    class SWGInstanceConfigResponse;
    class SWGInstanceDevicesResponse;
    class SWGInstanceChannelsResponse;
    class SWGInstanceFeaturesResponse;
    class SWGPreferences;
    class SWGLoggingInfo;
    class SWGAudioDevices;
    class SWGAudioInputDevice;
    class SWGAudioOutputDevice;
    class SWGLocationInformation;
    class SWGDVSerialDevices;
    class SWGAMBEDevices;
    class SWGLimeRFEDevices;
    class SWGLimeRFESettings;
    class SWGLimeRFEPower;
    class SWGPresets;
    class SWGPresetTransfer;
    class SWGPresetIdentifier;
    class SWGPresetImport;
    class SWGPresetExport;
    class SWGDeviceSetList;
    class SWGDeviceSet;
    class SWGDeviceListItem;
    class SWGDeviceSettings;
    class SWGDeviceState;
    class SWGDeviceReport;
    class SWGDeviceActions;
    class SWGChannelsDetail;
    class SWGChannelSettings;
    class SWGChannelReport;
    class SWGChannelActions;
    class SWGSuccessResponse;
    class SWGFeaturePresets;
    class SWGFeaturePresetIdentifier;
    class SWGFeaturePresetTransfer;
    class SWGFeatureSetList;
    class SWGFeatureSet;
    class SWGFeatureSettings;
    class SWGFeatureReport;
    class SWGFeatureActions;
    class SWGGLSpectrum;
    class SWGSpectrumServer;
}

class SDRBASE_API WebAPIAdapterInterface
{
public:
    struct ChannelKeys
    {
        QStringList m_keys;
        QStringList m_channelKeys;
    };
    struct DeviceKeys
    {
        QStringList m_keys;
        QStringList m_deviceKeys;
    };
    struct FeatureKeys
    {
        QStringList m_keys;
        QStringList m_featureKeys;
    };
    struct PresetKeys
    {
        QStringList m_keys;
        QStringList m_spectrumKeys;
        QList<ChannelKeys> m_channelsKeys;
        QList<DeviceKeys> m_devicesKeys;
    };
    struct FeatureSetPresetKeys
    {
        QStringList m_keys;
        QList<FeatureKeys> m_featureKeys;
        QList<DeviceKeys> m_devicesKeys;
    };
    struct CommandKeys
    {
        QStringList m_keys;
    };
    struct ConfigKeys
    {
        QStringList m_preferencesKeys;
        PresetKeys m_workingPresetKeys;
        FeatureSetPresetKeys m_workingFeatureSetPresetKeys;
        QList<PresetKeys> m_presetKeys;
        QList<FeatureSetPresetKeys> m_featureSetPresetKeys;
        QList<CommandKeys> m_commandKeys;
        void debug() const;
    };

    virtual ~WebAPIAdapterInterface() {}

    /**
     * Handler of /RPX100 (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceSummary(
            SWGRPX100::SWGInstanceSummaryResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100 (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/config (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceConfigGet(
            SWGRPX100::SWGInstanceConfigResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/config (PUT, PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceConfigPutPatch(
        bool force, // PUT else PATCH
        SWGRPX100::SWGInstanceConfigResponse& query,
        const ConfigKeys& configKeys,
        SWGRPX100::SWGSuccessResponse& response,
        SWGRPX100::SWGErrorResponse& error
    )
    {
        (void) force;
        (void) query;
        (void) configKeys;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/devices (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceDevices
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDevices(
            int direction,
            SWGRPX100::SWGInstanceDevicesResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) direction;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/channels (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceChannels(
            int direction,
            SWGRPX100::SWGInstanceChannelsResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) direction;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/features (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatures(
            SWGRPX100::SWGInstanceFeaturesResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/logging (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLoggingGet(
            SWGRPX100::SWGLoggingInfo& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/logging (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLoggingPut(
            SWGRPX100::SWGLoggingInfo& query,
            SWGRPX100::SWGLoggingInfo& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/audio (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioGet(
            SWGRPX100::SWGAudioDevices& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/audio/input/parameters (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioInputPatch(
            SWGRPX100::SWGAudioInputDevice& response,
            const QStringList& audioInputKeys,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        (void) audioInputKeys;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/audio/output/parameters (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioOutputPatch(
            SWGRPX100::SWGAudioOutputDevice& response,
            const QStringList& audioOutputKeys,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        (void) audioOutputKeys;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/audio/input/parameters (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioInputDelete(
            SWGRPX100::SWGAudioInputDevice& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/audio/output/paramaters (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioOutputDelete(
            SWGRPX100::SWGAudioOutputDevice& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/audio/input/cleanup (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioInputCleanupPatch(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/audio/output/cleanup (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioOutputCleanupPatch(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/location (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLocationGet(
            SWGRPX100::SWGLocationInformation& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/location (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLocationPut(
            SWGRPX100::SWGLocationInformation& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/ambe/serial (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBESerialGet(
            SWGRPX100::SWGDVSerialDevices& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/ambe/devices (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesGet(
            SWGRPX100::SWGAMBEDevices& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/ambe/devices (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesPut(
            SWGRPX100::SWGAMBEDevices& query,
            SWGRPX100::SWGAMBEDevices& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/ambe/devices (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesPatch(
            SWGRPX100::SWGAMBEDevices& query,
            SWGRPX100::SWGAMBEDevices& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/ambe/devices (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/limerfe/serial (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFESerialGet(
            SWGRPX100::SWGLimeRFEDevices& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/limerfe/config (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFEConfigGet(
            const QString& serial,
            SWGRPX100::SWGLimeRFESettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) serial;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/limerfe/config (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFEConfigPut(
            SWGRPX100::SWGLimeRFESettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/limerfe/run (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFERunPut(
            SWGRPX100::SWGLimeRFESettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/limerfe/power (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFEPowerGet(
            const QString& serial,
            SWGRPX100::SWGLimeRFEPower& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) serial;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/presets (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetsGet(
            SWGRPX100::SWGPresets& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/preset (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetPatch(
            SWGRPX100::SWGPresetTransfer& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/preset (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetPut(
            SWGRPX100::SWGPresetTransfer& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/preset (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetPost(
            SWGRPX100::SWGPresetTransfer& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/preset (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetDelete(
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/preset/file (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetFilePut(
            SWGRPX100::SWGPresetImport& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/preset/file (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetFilePost(
            SWGRPX100::SWGPresetExport& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featurepresets (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeaturePresetsGet(
            SWGRPX100::SWGFeaturePresets& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featurepreset (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeaturePresetDelete(
            SWGRPX100::SWGFeaturePresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/devicesets (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDeviceSetsGet(
            SWGRPX100::SWGDeviceSetList& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDeviceSetPost(
            int direction,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) direction;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDeviceSetDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featurets (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatureSetsGet(
            SWGRPX100::SWGFeatureSetList& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatureSetPost(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatureSetDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex} (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceSet& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/focus (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetFocusPatch(
            int deviceSetIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/spectrum/settings (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumSettingsGet(
            int deviceSetIndex,
            SWGRPX100::SWGGLSpectrum& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/spectrum/settings (PUT, PATCH)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumSettingsPutPatch(
            int deviceSetIndex,
            bool force, //!< true to force settings = put else patch
            const QStringList& spectrumSettingsKeys,
            SWGRPX100::SWGGLSpectrum& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) force;
        (void) spectrumSettingsKeys;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/spectrum/server (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumServerGet(
            int deviceSetIndex,
            SWGRPX100::SWGSpectrumServer& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/spectrum/server (POST)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumServerPost(
            int deviceSetIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/spectrum/server (DELETE)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumServerDelete(
            int deviceSetIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDevicePut(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceListItem& query,
            SWGRPX100::SWGDeviceListItem& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device/settings (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSettingsGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceSettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device/settings (PUT, PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSettingsPutPatch(
            int deviceSetIndex,
            bool force, //!< true to force settings = put else patch
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGDeviceSettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) force;
        (void) channelSettingsKeys;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device/run (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceRunGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/subdevice/{subsystemIndex}/run (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSubsystemRunGet(
            int deviceSetIndex,
            int subsystemIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) subsystemIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device/run (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceRunPost(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/subdevice/{subsystemIndex}/run (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSubsystemRunPost(
            int deviceSetIndex,
            int subsystemIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) subsystemIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device/run (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceRunDelete(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/subdevice/{subsystemIndex}/run (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSubsystemRunDelete(
            int deviceSetIndex,
            int subsystemIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) subsystemIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/device/report (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceReportGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceReport& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{devicesetIndex}/channels/report (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelsReportGet(
            int deviceSetIndex,
            SWGRPX100::SWGChannelsDetail& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/device/actions (POST)
     * post action(s) on device
     */
    virtual int devicesetDeviceActionsPost(
            int deviceSetIndex,
            const QStringList& deviceActionsKeys,
            SWGRPX100::SWGDeviceActions& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error
    )
    {
        (void) deviceSetIndex;
        (void) deviceActionsKeys;
        (void) query;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/channel (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelPost(
            int deviceSetIndex,
            SWGRPX100::SWGChannelSettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/channel/{channelIndex} (DELETE) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelDelete(
            int deviceSetIndex,
            int channelIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) response;
        (void) error;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelSettingsGet(
            int deviceSetIndex,
            int channelIndex,
            SWGRPX100::SWGChannelSettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings (PUT, PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelSettingsPutPatch(
            int deviceSetIndex,
            int channelIndex,
            bool force,
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGChannelSettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) force;
        (void) channelSettingsKeys;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }


    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings (GET) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelReportGet(
            int deviceSetIndex,
            int channelIndex,
            SWGRPX100::SWGChannelReport& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/deviceset/{deviceSetIndex}/channel/{channelIndex}/actions (POST)
     * posts an action on the channel (default 501: not implemented)
     */
    virtual int devicesetChannelActionsPost(
            int deviceSetIndex,
            int channelIndex,
            const QStringList& channelActionsKeys,
            SWGRPX100::SWGChannelActions& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) channelActionsKeys;
        (void) query;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex} (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetGet(
            int deviceSetIndex,
            SWGRPX100::SWGFeatureSet& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature (POST)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeaturePost(
            int featureSetIndex,
            SWGRPX100::SWGFeatureSettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/run (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureDelete(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        (void) error;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/run (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureRunGet(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        (void) error;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/run (POST)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureRunPost(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        (void) error;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/run (DELETE)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureRunDelete(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        (void) error;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/preset (PATCH) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetPresetPatch(
            int featureSetIndex,
            SWGRPX100::SWGFeaturePresetIdentifier& query,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/preset (PUT) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetPresetPut(
            int featureSetIndex,
            SWGRPX100::SWGFeaturePresetIdentifier& query,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/preset (POST) swagger/RPX100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetPresetPost(
            int featureSetIndex,
            SWGRPX100::SWGFeaturePresetIdentifier& query,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/settings (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureSettingsGet(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGFeatureSettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/settings (PUT, PATCH)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureSettingsPutPatch(
            int featureSetIndex,
            int featureIndex,
            bool force,
            const QStringList& featureSettingsKeys,
            SWGRPX100::SWGFeatureSettings& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) force;
        (void) featureSettingsKeys;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/report (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureReportGet(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGFeatureReport& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /RPX100/featureset/{featuresetIndex}/feature/{featureIndex}/actions (POST)
     * posts an action on the channel (default 501: not implemented)
     */
    virtual int featuresetFeatureActionsPost(
            int featureSetIndex,
            int featureIndex,
            const QStringList& featureActionsKeys,
            SWGRPX100::SWGFeatureActions& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) featureActionsKeys;
        (void) query;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    static QString instanceSummaryURL;
    static QString instanceConfigURL;
    static QString instanceDevicesURL;
    static QString instanceChannelsURL;
    static QString instanceFeaturesURL;
    static QString instanceLoggingURL;
    static QString instanceAudioURL;
    static QString instanceAudioInputParametersURL;
    static QString instanceAudioOutputParametersURL;
    static QString instanceAudioInputCleanupURL;
    static QString instanceAudioOutputCleanupURL;
    static QString instanceLocationURL;
    static QString instanceAMBESerialURL;
    static QString instanceAMBEDevicesURL;
    static QString instanceLimeRFESerialURL;
    static QString instanceLimeRFEConfigURL;
    static QString instanceLimeRFERunURL;
    static QString instanceLimeRFEPowerURL;
    static QString instancePresetsURL;
    static QString instancePresetURL;
    static QString instancePresetFileURL;
    static QString instanceFeaturePresetsURL;
    static QString instanceFeaturePresetURL;
    static QString instanceDeviceSetsURL;
    static QString instanceDeviceSetURL;
    static QString instanceFeatureSetsURL;
    static QString instanceFeatureSetURL;
    static std::regex devicesetURLRe;
    static std::regex devicesetFocusURLRe;
    static std::regex devicesetSpectrumSettingsURLRe;
    static std::regex devicesetSpectrumServerURLRe;
    static std::regex devicesetDeviceURLRe;
    static std::regex devicesetDeviceSettingsURLRe;
    static std::regex devicesetDeviceRunURLRe;
    static std::regex devicesetDeviceSubsystemRunURLRe;
    static std::regex devicesetDeviceReportURLRe;
    static std::regex devicesetDeviceActionsURLRe;
    static std::regex devicesetChannelURLRe;
    static std::regex devicesetChannelIndexURLRe;
    static std::regex devicesetChannelSettingsURLRe;
    static std::regex devicesetChannelReportURLRe;
    static std::regex devicesetChannelActionsURLRe;
    static std::regex devicesetChannelsReportURLRe;
    static std::regex featuresetURLRe;
    static std::regex featuresetFeatureURLRe;
    static std::regex featuresetPresetURLRe;
    static std::regex featuresetFeatureIndexURLRe;
    static std::regex featuresetFeatureRunURLRe;
    static std::regex featuresetFeatureSettingsURLRe;
    static std::regex featuresetFeatureReportURLRe;
    static std::regex featuresetFeatureActionsURLRe;
};



#endif /* SDRBASE_WEBAPI_WEBAPIADAPTERINTERFACE_H_ */
