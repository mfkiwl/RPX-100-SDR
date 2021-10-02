///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017-2020 Edouard Griffiths, F4EXB.                             //
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

#ifndef SDRBASE_WEBAPI_WEBAPIADAPTER_H_
#define SDRBASE_WEBAPI_WEBAPIADAPTER_H_

#include <QtGlobal>

#include "webapi/webapiadapterinterface.h"
#include "export.h"

class MainCore;
class DeviceSet;
class FeatureSet;

class SDRBASE_API WebAPIAdapter: public WebAPIAdapterInterface
{
public:
    WebAPIAdapter();
    virtual ~WebAPIAdapter();

    virtual int instanceSummary(
            SWGRPX100::SWGInstanceSummaryResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceConfigGet(
            SWGRPX100::SWGInstanceConfigResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceConfigPutPatch(
            bool force, // PUT else PATCH
            SWGRPX100::SWGInstanceConfigResponse& query,
            const ConfigKeys& configKeys,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDevices(
            int direction,
            SWGRPX100::SWGInstanceDevicesResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceChannels(
            int direction,
            SWGRPX100::SWGInstanceChannelsResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceFeatures(
            SWGRPX100::SWGInstanceFeaturesResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLoggingGet(
            SWGRPX100::SWGLoggingInfo& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLoggingPut(
            SWGRPX100::SWGLoggingInfo& query,
            SWGRPX100::SWGLoggingInfo& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioGet(
            SWGRPX100::SWGAudioDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioInputPatch(
            SWGRPX100::SWGAudioInputDevice& response,
            const QStringList& audioInputKeys,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioOutputPatch(
            SWGRPX100::SWGAudioOutputDevice& response,
            const QStringList& audioOutputKeys,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioInputDelete(
            SWGRPX100::SWGAudioInputDevice& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioOutputDelete(
            SWGRPX100::SWGAudioOutputDevice& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioInputCleanupPatch(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAudioOutputCleanupPatch(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLocationGet(
            SWGRPX100::SWGLocationInformation& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLocationPut(
            SWGRPX100::SWGLocationInformation& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDVSerialGet(
            SWGRPX100::SWGDVSerialDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDVSerialPatch(
            bool dvserial,
            SWGRPX100::SWGDVSerialDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAMBESerialGet(
            SWGRPX100::SWGDVSerialDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesGet(
            SWGRPX100::SWGAMBEDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesPut(
            SWGRPX100::SWGAMBEDevices& query,
            SWGRPX100::SWGAMBEDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesPatch(
            SWGRPX100::SWGAMBEDevices& query,
            SWGRPX100::SWGAMBEDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

#ifdef HAS_LIMERFEUSB
    virtual int instanceLimeRFESerialGet(
            SWGRPX100::SWGLimeRFEDevices& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLimeRFEConfigGet(
            const QString& serial,
            SWGRPX100::SWGLimeRFESettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLimeRFEConfigPut(
            SWGRPX100::SWGLimeRFESettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLimeRFERunPut(
            SWGRPX100::SWGLimeRFESettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceLimeRFEPowerGet(
            const QString& serial,
            SWGRPX100::SWGLimeRFEPower& response,
            SWGRPX100::SWGErrorResponse& error);
#endif

    virtual int instancePresetsGet(
            SWGRPX100::SWGPresets& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instancePresetPatch(
            SWGRPX100::SWGPresetTransfer& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instancePresetPut(
            SWGRPX100::SWGPresetTransfer& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instancePresetPost(
            SWGRPX100::SWGPresetTransfer& query,
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instancePresetDelete(
            SWGRPX100::SWGPresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceFeaturePresetsGet(
            SWGRPX100::SWGFeaturePresets& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceFeaturePresetDelete(
            SWGRPX100::SWGFeaturePresetIdentifier& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDeviceSetsGet(
            SWGRPX100::SWGDeviceSetList& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceFeatureSetsGet(
            SWGRPX100::SWGFeatureSetList& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDeviceSetPost(
            int direction,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceDeviceSetDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceFeatureSetPost(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int instanceFeatureSetDelete(
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceSet& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetFocusPatch(
            int deviceSetIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetSpectrumSettingsGet(
            int deviceSetIndex,
            SWGRPX100::SWGGLSpectrum& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetSpectrumSettingsPutPatch(
            int deviceSetIndex,
            bool force, //!< true to force settings = put else patch
            const QStringList& spectrumSettingsKeys,
            SWGRPX100::SWGGLSpectrum& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetSpectrumServerGet(
            int deviceSetIndex,
            SWGRPX100::SWGSpectrumServer& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetSpectrumServerPost(
            int deviceSetIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetSpectrumServerDelete(
            int deviceSetIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDevicePut(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceListItem& query,
            SWGRPX100::SWGDeviceListItem& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceSettingsGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceSettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceActionsPost(
            int deviceSetIndex,
            const QStringList& deviceActionsKeys,
            SWGRPX100::SWGDeviceActions& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceSettingsPutPatch(
            int deviceSetIndex,
            bool force,
            const QStringList& deviceSettingsKeys,
            SWGRPX100::SWGDeviceSettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceRunGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceRunPost(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceRunDelete(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceSubsystemRunGet(
            int deviceSetIndex,
            int subsystemIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceSubsystemRunPost(
            int deviceSetIndex,
            int subsystemIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceSubsystemRunDelete(
            int deviceSetIndex,
            int subsystemIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetDeviceReportGet(
            int deviceSetIndex,
            SWGRPX100::SWGDeviceReport& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelsReportGet(
            int deviceSetIndex,
            SWGRPX100::SWGChannelsDetail& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelPost(
            int deviceSetIndex,
            SWGRPX100::SWGChannelSettings& query,
			SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelDelete(
            int deviceSetIndex,
            int channelIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelSettingsGet(
            int deviceSetIndex,
            int channelIndex,
            SWGRPX100::SWGChannelSettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelActionsPost(
            int deviceSetIndex,
            int channelIndex,
            const QStringList& channelActionsKeys,
            SWGRPX100::SWGChannelActions& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelSettingsPutPatch(
            int deviceSetIndex,
            int channelIndex,
            bool force,
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGChannelSettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int devicesetChannelReportGet(
            int deviceSetIndex,
            int channelIndex,
            SWGRPX100::SWGChannelReport& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetGet(
            int deviceSetIndex,
            SWGRPX100::SWGFeatureSet& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeaturePost(
            int featureSetIndex,
            SWGRPX100::SWGFeatureSettings& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureDelete(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureRunGet(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureRunPost(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureRunDelete(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGDeviceState& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetPresetPatch(
            int featureSetIndex,
            SWGRPX100::SWGFeaturePresetIdentifier& query,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetPresetPut(
            int featureSetIndex,
            SWGRPX100::SWGFeaturePresetIdentifier& query,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetPresetPost(
            int featureSetIndex,
            SWGRPX100::SWGFeaturePresetIdentifier& query,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureSettingsGet(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGFeatureSettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureSettingsPutPatch(
            int featureSetIndex,
            int featureIndex,
            bool force,
            const QStringList& featureSettingsKeys,
            SWGRPX100::SWGFeatureSettings& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureReportGet(
            int featureSetIndex,
            int featureIndex,
            SWGRPX100::SWGFeatureReport& response,
            SWGRPX100::SWGErrorResponse& error);

    virtual int featuresetFeatureActionsPost(
            int featureSetIndex,
            int featureIndex,
            const QStringList& featureActionsKeys,
            SWGRPX100::SWGFeatureActions& query,
            SWGRPX100::SWGSuccessResponse& response,
            SWGRPX100::SWGErrorResponse& error);

private:
    MainCore *m_mainCore;

    void getDeviceSetList(SWGRPX100::SWGDeviceSetList* deviceSetList);
    void getDeviceSet(SWGRPX100::SWGDeviceSet *swgDeviceSet, const DeviceSet* deviceSet, int deviceSetIndex);
    void getChannelsDetail(SWGRPX100::SWGChannelsDetail *channelsDetail, const DeviceSet* deviceSet);
    void getFeatureSetList(SWGRPX100::SWGFeatureSetList* featureSetList);
    void getFeatureSet(SWGRPX100::SWGFeatureSet *swgFeatureSet, const FeatureSet* featureSet, int featureSetIndex);
    static QtMsgType getMsgTypeFromString(const QString& msgTypeString);
    static void getMsgTypeString(const QtMsgType& msgType, QString& level);
};

#endif /* SDRGUI_WEBAPI_WEBAPIADAPTERGUI_H_ */
