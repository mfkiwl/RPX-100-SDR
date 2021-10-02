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
 * SWGUDPSourceSettings.h
 *
 * UDPSource
 */

#ifndef SWGUDPSourceSettings_H_
#define SWGUDPSourceSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGUDPSourceSettings: public SWGObject {
public:
    SWGUDPSourceSettings();
    SWGUDPSourceSettings(QString* json);
    virtual ~SWGUDPSourceSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGUDPSourceSettings* fromJson(QString &jsonString) override;

    qint32 getSampleFormat();
    void setSampleFormat(qint32 sample_format);

    float getInputSampleRate();
    void setInputSampleRate(float input_sample_rate);

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getRfBandwidth();
    void setRfBandwidth(float rf_bandwidth);

    float getLowCutoff();
    void setLowCutoff(float low_cutoff);

    qint32 getFmDeviation();
    void setFmDeviation(qint32 fm_deviation);

    float getAmModFactor();
    void setAmModFactor(float am_mod_factor);

    qint32 getChannelMute();
    void setChannelMute(qint32 channel_mute);

    float getGainIn();
    void setGainIn(float gain_in);

    float getGainOut();
    void setGainOut(float gain_out);

    float getSquelch();
    void setSquelch(float squelch);

    float getSquelchGate();
    void setSquelchGate(float squelch_gate);

    qint32 getSquelchEnabled();
    void setSquelchEnabled(qint32 squelch_enabled);

    qint32 getAutoRwBalance();
    void setAutoRwBalance(qint32 auto_rw_balance);

    qint32 getStereoInput();
    void setStereoInput(qint32 stereo_input);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getUdpAddress();
    void setUdpAddress(QString* udp_address);

    qint32 getUdpPort();
    void setUdpPort(qint32 udp_port);

    QString* getMulticastAddress();
    void setMulticastAddress(QString* multicast_address);

    qint32 getMulticastJoin();
    void setMulticastJoin(qint32 multicast_join);

    QString* getTitle();
    void setTitle(QString* title);

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
    qint32 sample_format;
    bool m_sample_format_isSet;

    float input_sample_rate;
    bool m_input_sample_rate_isSet;

    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    float rf_bandwidth;
    bool m_rf_bandwidth_isSet;

    float low_cutoff;
    bool m_low_cutoff_isSet;

    qint32 fm_deviation;
    bool m_fm_deviation_isSet;

    float am_mod_factor;
    bool m_am_mod_factor_isSet;

    qint32 channel_mute;
    bool m_channel_mute_isSet;

    float gain_in;
    bool m_gain_in_isSet;

    float gain_out;
    bool m_gain_out_isSet;

    float squelch;
    bool m_squelch_isSet;

    float squelch_gate;
    bool m_squelch_gate_isSet;

    qint32 squelch_enabled;
    bool m_squelch_enabled_isSet;

    qint32 auto_rw_balance;
    bool m_auto_rw_balance_isSet;

    qint32 stereo_input;
    bool m_stereo_input_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* udp_address;
    bool m_udp_address_isSet;

    qint32 udp_port;
    bool m_udp_port_isSet;

    QString* multicast_address;
    bool m_multicast_address_isSet;

    qint32 multicast_join;
    bool m_multicast_join_isSet;

    QString* title;
    bool m_title_isSet;

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

#endif /* SWGUDPSourceSettings_H_ */
