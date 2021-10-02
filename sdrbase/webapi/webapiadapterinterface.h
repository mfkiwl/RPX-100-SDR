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

#ifndef SDRBASE_WEBAPI_WEBAPIADAPTERINTERFACE_H_
#define SDRBASE_WEBAPI_WEBAPIADAPTERINTERFACE_H_

#include <QString>
#include <QStringList>
#include <regex>

#include "SWGErrorResponse.h"

#include "export.h"

namespace SWGrpx-100
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
     * Handler of /rpx-100 (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceSummary(
            SWGrpx-100::SWGInstanceSummaryResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100 (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/config (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceConfigGet(
            SWGrpx-100::SWGInstanceConfigResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/config (PUT, PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceSummary
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceConfigPutPatch(
        bool force, // PUT else PATCH
        SWGrpx-100::SWGInstanceConfigResponse& query,
        const ConfigKeys& configKeys,
        SWGrpx-100::SWGSuccessResponse& response,
        SWGrpx-100::SWGErrorResponse& error
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
     * Handler of /rpx-100/devices (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceDevices
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDevices(
            int direction,
            SWGrpx-100::SWGInstanceDevicesResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) direction;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/channels (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceChannels(
            int direction,
            SWGrpx-100::SWGInstanceChannelsResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) direction;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/features (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatures(
            SWGrpx-100::SWGInstanceFeaturesResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/logging (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLoggingGet(
            SWGrpx-100::SWGLoggingInfo& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/logging (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLoggingPut(
            SWGrpx-100::SWGLoggingInfo& query,
            SWGrpx-100::SWGLoggingInfo& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/audio (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioGet(
            SWGrpx-100::SWGAudioDevices& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/audio/input/parameters (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioInputPatch(
            SWGrpx-100::SWGAudioInputDevice& response,
            const QStringList& audioInputKeys,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        (void) audioInputKeys;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/audio/output/parameters (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioOutputPatch(
            SWGrpx-100::SWGAudioOutputDevice& response,
            const QStringList& audioOutputKeys,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        (void) audioOutputKeys;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/audio/input/parameters (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioInputDelete(
            SWGrpx-100::SWGAudioInputDevice& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/audio/output/paramaters (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioOutputDelete(
            SWGrpx-100::SWGAudioOutputDevice& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/audio/input/cleanup (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioInputCleanupPatch(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/audio/output/cleanup (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAudioOutputCleanupPatch(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/location (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLocationGet(
            SWGrpx-100::SWGLocationInformation& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/location (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLocationPut(
            SWGrpx-100::SWGLocationInformation& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/ambe/serial (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBESerialGet(
            SWGrpx-100::SWGDVSerialDevices& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/ambe/devices (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesGet(
            SWGrpx-100::SWGAMBEDevices& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/ambe/devices (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesPut(
            SWGrpx-100::SWGAMBEDevices& query,
            SWGrpx-100::SWGAMBEDevices& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/ambe/devices (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesPatch(
            SWGrpx-100::SWGAMBEDevices& query,
            SWGrpx-100::SWGAMBEDevices& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/ambe/devices (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceAMBEDevicesDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/limerfe/serial (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFESerialGet(
            SWGrpx-100::SWGLimeRFEDevices& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/limerfe/config (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFEConfigGet(
            const QString& serial,
            SWGrpx-100::SWGLimeRFESettings& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) serial;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/limerfe/config (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFEConfigPut(
            SWGrpx-100::SWGLimeRFESettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/limerfe/run (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFERunPut(
            SWGrpx-100::SWGLimeRFESettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/limerfe/power (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceLimeRFEPowerGet(
            const QString& serial,
            SWGrpx-100::SWGLimeRFEPower& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) serial;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/presets (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetsGet(
            SWGrpx-100::SWGPresets& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/preset (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetPatch(
            SWGrpx-100::SWGPresetTransfer& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/preset (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetPut(
            SWGrpx-100::SWGPresetTransfer& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/preset (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetPost(
            SWGrpx-100::SWGPresetTransfer& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/preset (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetDelete(
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/preset/file (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetFilePut(
            SWGrpx-100::SWGPresetImport& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/preset/file (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instancePresetFilePost(
            SWGrpx-100::SWGPresetExport& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featurepresets (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeaturePresetsGet(
            SWGrpx-100::SWGFeaturePresets& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featurepreset (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeaturePresetDelete(
            SWGrpx-100::SWGFeaturePresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/devicesets (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDeviceSetsGet(
            SWGrpx-100::SWGDeviceSetList& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDeviceSetPost(
            int direction,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) direction;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceDeviceSetDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featurets (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatureSetsGet(
            SWGrpx-100::SWGFeatureSetList& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatureSetPost(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int instanceFeatureSetDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex} (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceSet& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/focus (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetFocusPatch(
            int deviceSetIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/spectrum/settings (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumSettingsGet(
            int deviceSetIndex,
            SWGrpx-100::SWGGLSpectrum& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/spectrum/settings (PUT, PATCH)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumSettingsPutPatch(
            int deviceSetIndex,
            bool force, //!< true to force settings = put else patch
            const QStringList& spectrumSettingsKeys,
            SWGrpx-100::SWGGLSpectrum& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/deviceset/{devicesetIndex}/spectrum/server (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumServerGet(
            int deviceSetIndex,
            SWGrpx-100::SWGSpectrumServer& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/spectrum/server (POST)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumServerPost(
            int deviceSetIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/spectrum/server (DELETE)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetSpectrumServerDelete(
            int deviceSetIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDevicePut(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceListItem& query,
            SWGrpx-100::SWGDeviceListItem& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) query;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device/settings (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSettingsGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceSettings& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device/settings (PUT, PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSettingsPutPatch(
            int deviceSetIndex,
            bool force, //!< true to force settings = put else patch
            const QStringList& channelSettingsKeys,
            SWGrpx-100::SWGDeviceSettings& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device/run (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceRunGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/subdevice/{subsystemIndex}/run (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSubsystemRunGet(
            int deviceSetIndex,
            int subsystemIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) subsystemIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device/run (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceRunPost(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/subdevice/{subsystemIndex}/run (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSubsystemRunPost(
            int deviceSetIndex,
            int subsystemIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) subsystemIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device/run (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceRunDelete(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/subdevice/{subsystemIndex}/run (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceSubsystemRunDelete(
            int deviceSetIndex,
            int subsystemIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) subsystemIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/device/report (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetDeviceReportGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceReport& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{devicesetIndex}/channels/report (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelsReportGet(
            int deviceSetIndex,
            SWGrpx-100::SWGChannelsDetail& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/device/actions (POST)
     * post action(s) on device
     */
    virtual int devicesetDeviceActionsPost(
            int deviceSetIndex,
            const QStringList& deviceActionsKeys,
            SWGrpx-100::SWGDeviceActions& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error
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
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/channel (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelPost(
            int deviceSetIndex,
            SWGrpx-100::SWGChannelSettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/channel/{channelIndex} (DELETE) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelDelete(
            int deviceSetIndex,
            int channelIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelSettingsGet(
            int deviceSetIndex,
            int channelIndex,
            SWGrpx-100::SWGChannelSettings& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings (PUT, PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelSettingsPutPatch(
            int deviceSetIndex,
            int channelIndex,
            bool force,
            const QStringList& channelSettingsKeys,
            SWGrpx-100::SWGChannelSettings& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/channel/{channelIndex}/settings (GET) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int devicesetChannelReportGet(
            int deviceSetIndex,
            int channelIndex,
            SWGrpx-100::SWGChannelReport& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) channelIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/deviceset/{deviceSetIndex}/channel/{channelIndex}/actions (POST)
     * posts an action on the channel (default 501: not implemented)
     */
    virtual int devicesetChannelActionsPost(
            int deviceSetIndex,
            int channelIndex,
            const QStringList& channelActionsKeys,
            SWGrpx-100::SWGChannelActions& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/featureset/{featuresetIndex} (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetGet(
            int deviceSetIndex,
            SWGrpx-100::SWGFeatureSet& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) deviceSetIndex;
        (void) response;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature (POST)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeaturePost(
            int featureSetIndex,
            SWGrpx-100::SWGFeatureSettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/run (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureDelete(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/run (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureRunGet(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/run (POST)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureRunPost(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/run (DELETE)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureRunDelete(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/featureset/{featuresetIndex}/preset (PATCH) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetPresetPatch(
            int featureSetIndex,
            SWGrpx-100::SWGFeaturePresetIdentifier& query,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/preset (PUT) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetPresetPut(
            int featureSetIndex,
            SWGrpx-100::SWGFeaturePresetIdentifier& query,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/preset (POST) swagger/rpx-100/code/html2/index.html#api-Default-instanceChannels
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetPresetPost(
            int featureSetIndex,
            SWGrpx-100::SWGFeaturePresetIdentifier& query,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) query;
    	error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/settings (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureSettingsGet(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGFeatureSettings& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        error.init();
    	*error.getMessage() = QString("Function not implemented");
    	return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/settings (PUT, PATCH)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureSettingsPutPatch(
            int featureSetIndex,
            int featureIndex,
            bool force,
            const QStringList& featureSettingsKeys,
            SWGrpx-100::SWGFeatureSettings& response,
            SWGrpx-100::SWGErrorResponse& error)
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
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/report (GET)
     * returns the Http status code (default 501: not implemented)
     */
    virtual int featuresetFeatureReportGet(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGFeatureReport& response,
            SWGrpx-100::SWGErrorResponse& error)
    {
        (void) featureSetIndex;
        (void) featureIndex;
        (void) response;
        error.init();
        *error.getMessage() = QString("Function not implemented");
        return 501;
    }

    /**
     * Handler of /rpx-100/featureset/{featuresetIndex}/feature/{featureIndex}/actions (POST)
     * posts an action on the channel (default 501: not implemented)
     */
    virtual int featuresetFeatureActionsPost(
            int featureSetIndex,
            int featureIndex,
            const QStringList& featureActionsKeys,
            SWGrpx-100::SWGFeatureActions& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error)
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
