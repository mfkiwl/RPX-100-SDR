/**
 * rpx-100
 * This is the web REST/JSON API of rpx-100 SDR software. rpx-100 is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In rpx-100 GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /rpx-100/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGFreqTrackerSettings.h
 *
 * FreqTracker
 */

#ifndef SWGFreqTrackerSettings_H_
#define SWGFreqTrackerSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGFreqTrackerSettings: public SWGObject {
public:
    SWGFreqTrackerSettings();
    SWGFreqTrackerSettings(QString* json);
    virtual ~SWGFreqTrackerSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGFreqTrackerSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getRfBandwidth();
    void setRfBandwidth(float rf_bandwidth);

    qint32 getLog2Decim();
    void setLog2Decim(qint32 log2_decim);

    float getSquelch();
    void setSquelch(float squelch);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    qint32 getSpanLog2();
    void setSpanLog2(qint32 span_log2);

    float getAlphaEma();
    void setAlphaEma(float alpha_ema);

    qint32 getTracking();
    void setTracking(qint32 tracking);

    qint32 getTrackerType();
    void setTrackerType(qint32 tracker_type);

    qint32 getPllPskOrder();
    void setPllPskOrder(qint32 pll_psk_order);

    qint32 getRrc();
    void setRrc(qint32 rrc);

    qint32 getRrcRolloff();
    void setRrcRolloff(qint32 rrc_rolloff);

    qint32 getSquelchGate();
    void setSquelchGate(qint32 squelch_gate);

    qint32 getStreamIndex();
    void setStreamIndex(qint32 stream_index);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);

    qint32 getReverseApiChannelIndex();
    void setReverseApiChannelIndex(qint32 reverse_api_channel_index);


    virtual bool isSet() override;

private:
    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    float rf_bandwidth;
    bool m_rf_bandwidth_isSet;

    qint32 log2_decim;
    bool m_log2_decim_isSet;

    float squelch;
    bool m_squelch_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    qint32 span_log2;
    bool m_span_log2_isSet;

    float alpha_ema;
    bool m_alpha_ema_isSet;

    qint32 tracking;
    bool m_tracking_isSet;

    qint32 tracker_type;
    bool m_tracker_type_isSet;

    qint32 pll_psk_order;
    bool m_pll_psk_order_isSet;

    qint32 rrc;
    bool m_rrc_isSet;

    qint32 rrc_rolloff;
    bool m_rrc_rolloff_isSet;

    qint32 squelch_gate;
    bool m_squelch_gate_isSet;

    qint32 stream_index;
    bool m_stream_index_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

    qint32 reverse_api_channel_index;
    bool m_reverse_api_channel_index_isSet;

};

}

#endif /* SWGFreqTrackerSettings_H_ */
