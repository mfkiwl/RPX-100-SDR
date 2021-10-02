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
            SWGrpx-100::SWGInstanceSummaryResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceConfigGet(
            SWGrpx-100::SWGInstanceConfigResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceConfigPutPatch(
            bool force, // PUT else PATCH
            SWGrpx-100::SWGInstanceConfigResponse& query,
            const ConfigKeys& configKeys,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDevices(
            int direction,
            SWGrpx-100::SWGInstanceDevicesResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceChannels(
            int direction,
            SWGrpx-100::SWGInstanceChannelsResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceFeatures(
            SWGrpx-100::SWGInstanceFeaturesResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLoggingGet(
            SWGrpx-100::SWGLoggingInfo& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLoggingPut(
            SWGrpx-100::SWGLoggingInfo& query,
            SWGrpx-100::SWGLoggingInfo& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioGet(
            SWGrpx-100::SWGAudioDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioInputPatch(
            SWGrpx-100::SWGAudioInputDevice& response,
            const QStringList& audioInputKeys,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioOutputPatch(
            SWGrpx-100::SWGAudioOutputDevice& response,
            const QStringList& audioOutputKeys,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioInputDelete(
            SWGrpx-100::SWGAudioInputDevice& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioOutputDelete(
            SWGrpx-100::SWGAudioOutputDevice& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioInputCleanupPatch(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAudioOutputCleanupPatch(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLocationGet(
            SWGrpx-100::SWGLocationInformation& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLocationPut(
            SWGrpx-100::SWGLocationInformation& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDVSerialGet(
            SWGrpx-100::SWGDVSerialDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDVSerialPatch(
            bool dvserial,
            SWGrpx-100::SWGDVSerialDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAMBESerialGet(
            SWGrpx-100::SWGDVSerialDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesGet(
            SWGrpx-100::SWGAMBEDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesPut(
            SWGrpx-100::SWGAMBEDevices& query,
            SWGrpx-100::SWGAMBEDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesPatch(
            SWGrpx-100::SWGAMBEDevices& query,
            SWGrpx-100::SWGAMBEDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceAMBEDevicesDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

#ifdef HAS_LIMERFEUSB
    virtual int instanceLimeRFESerialGet(
            SWGrpx-100::SWGLimeRFEDevices& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLimeRFEConfigGet(
            const QString& serial,
            SWGrpx-100::SWGLimeRFESettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLimeRFEConfigPut(
            SWGrpx-100::SWGLimeRFESettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLimeRFERunPut(
            SWGrpx-100::SWGLimeRFESettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceLimeRFEPowerGet(
            const QString& serial,
            SWGrpx-100::SWGLimeRFEPower& response,
            SWGrpx-100::SWGErrorResponse& error);
#endif

    virtual int instancePresetsGet(
            SWGrpx-100::SWGPresets& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instancePresetPatch(
            SWGrpx-100::SWGPresetTransfer& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instancePresetPut(
            SWGrpx-100::SWGPresetTransfer& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instancePresetPost(
            SWGrpx-100::SWGPresetTransfer& query,
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instancePresetDelete(
            SWGrpx-100::SWGPresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceFeaturePresetsGet(
            SWGrpx-100::SWGFeaturePresets& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceFeaturePresetDelete(
            SWGrpx-100::SWGFeaturePresetIdentifier& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDeviceSetsGet(
            SWGrpx-100::SWGDeviceSetList& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceFeatureSetsGet(
            SWGrpx-100::SWGFeatureSetList& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDeviceSetPost(
            int direction,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceDeviceSetDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceFeatureSetPost(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int instanceFeatureSetDelete(
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceSet& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetFocusPatch(
            int deviceSetIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetSpectrumSettingsGet(
            int deviceSetIndex,
            SWGrpx-100::SWGGLSpectrum& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetSpectrumSettingsPutPatch(
            int deviceSetIndex,
            bool force, //!< true to force settings = put else patch
            const QStringList& spectrumSettingsKeys,
            SWGrpx-100::SWGGLSpectrum& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetSpectrumServerGet(
            int deviceSetIndex,
            SWGrpx-100::SWGSpectrumServer& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetSpectrumServerPost(
            int deviceSetIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetSpectrumServerDelete(
            int deviceSetIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDevicePut(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceListItem& query,
            SWGrpx-100::SWGDeviceListItem& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceSettingsGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceSettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceActionsPost(
            int deviceSetIndex,
            const QStringList& deviceActionsKeys,
            SWGrpx-100::SWGDeviceActions& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceSettingsPutPatch(
            int deviceSetIndex,
            bool force,
            const QStringList& deviceSettingsKeys,
            SWGrpx-100::SWGDeviceSettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceRunGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceRunPost(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceRunDelete(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceSubsystemRunGet(
            int deviceSetIndex,
            int subsystemIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceSubsystemRunPost(
            int deviceSetIndex,
            int subsystemIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceSubsystemRunDelete(
            int deviceSetIndex,
            int subsystemIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetDeviceReportGet(
            int deviceSetIndex,
            SWGrpx-100::SWGDeviceReport& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelsReportGet(
            int deviceSetIndex,
            SWGrpx-100::SWGChannelsDetail& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelPost(
            int deviceSetIndex,
            SWGrpx-100::SWGChannelSettings& query,
			SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelDelete(
            int deviceSetIndex,
            int channelIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelSettingsGet(
            int deviceSetIndex,
            int channelIndex,
            SWGrpx-100::SWGChannelSettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelActionsPost(
            int deviceSetIndex,
            int channelIndex,
            const QStringList& channelActionsKeys,
            SWGrpx-100::SWGChannelActions& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelSettingsPutPatch(
            int deviceSetIndex,
            int channelIndex,
            bool force,
            const QStringList& channelSettingsKeys,
            SWGrpx-100::SWGChannelSettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int devicesetChannelReportGet(
            int deviceSetIndex,
            int channelIndex,
            SWGrpx-100::SWGChannelReport& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetGet(
            int deviceSetIndex,
            SWGrpx-100::SWGFeatureSet& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeaturePost(
            int featureSetIndex,
            SWGrpx-100::SWGFeatureSettings& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureDelete(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureRunGet(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureRunPost(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureRunDelete(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGDeviceState& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetPresetPatch(
            int featureSetIndex,
            SWGrpx-100::SWGFeaturePresetIdentifier& query,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetPresetPut(
            int featureSetIndex,
            SWGrpx-100::SWGFeaturePresetIdentifier& query,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetPresetPost(
            int featureSetIndex,
            SWGrpx-100::SWGFeaturePresetIdentifier& query,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureSettingsGet(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGFeatureSettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureSettingsPutPatch(
            int featureSetIndex,
            int featureIndex,
            bool force,
            const QStringList& featureSettingsKeys,
            SWGrpx-100::SWGFeatureSettings& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureReportGet(
            int featureSetIndex,
            int featureIndex,
            SWGrpx-100::SWGFeatureReport& response,
            SWGrpx-100::SWGErrorResponse& error);

    virtual int featuresetFeatureActionsPost(
            int featureSetIndex,
            int featureIndex,
            const QStringList& featureActionsKeys,
            SWGrpx-100::SWGFeatureActions& query,
            SWGrpx-100::SWGSuccessResponse& response,
            SWGrpx-100::SWGErrorResponse& error);

private:
    MainCore *m_mainCore;

    void getDeviceSetList(SWGrpx-100::SWGDeviceSetList* deviceSetList);
    void getDeviceSet(SWGrpx-100::SWGDeviceSet *swgDeviceSet, const DeviceSet* deviceSet, int deviceSetIndex);
    void getChannelsDetail(SWGrpx-100::SWGChannelsDetail *channelsDetail, const DeviceSet* deviceSet);
    void getFeatureSetList(SWGrpx-100::SWGFeatureSetList* featureSetList);
    void getFeatureSet(SWGrpx-100::SWGFeatureSet *swgFeatureSet, const FeatureSet* featureSet, int featureSetIndex);
    static QtMsgType getMsgTypeFromString(const QString& msgTypeString);
    static void getMsgTypeString(const QtMsgType& msgType, QString& level);
};

#endif /* SDRGUI_WEBAPI_WEBAPIADAPTERGUI_H_ */
