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
 * SWGDATVModSettings.h
 *
 * DATVMod
 */

#ifndef SWGDATVModSettings_H_
#define SWGDATVModSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGDATVModSettings: public SWGObject {
public:
    SWGDATVModSettings();
    SWGDATVModSettings(QString* json);
    virtual ~SWGDATVModSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGDATVModSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getRfBandwidth();
    void setRfBandwidth(float rf_bandwidth);

    qint32 getStandard();
    void setStandard(qint32 standard);

    qint32 getModulation();
    void setModulation(qint32 modulation);

    qint32 getFec();
    void setFec(qint32 fec);

    qint32 getSymbolRate();
    void setSymbolRate(qint32 symbol_rate);

    float getRollOff();
    void setRollOff(float roll_off);

    qint32 getTsSource();
    void setTsSource(qint32 ts_source);

    QString* getTsFileName();
    void setTsFileName(QString* ts_file_name);

    qint32 getTsFilePlayLoop();
    void setTsFilePlayLoop(qint32 ts_file_play_loop);

    qint32 getTsFilePlay();
    void setTsFilePlay(qint32 ts_file_play);

    QString* getUdpAddress();
    void setUdpAddress(QString* udp_address);

    qint32 getUdpPort();
    void setUdpPort(qint32 udp_port);

    qint32 getChannelMute();
    void setChannelMute(qint32 channel_mute);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

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
    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    float rf_bandwidth;
    bool m_rf_bandwidth_isSet;

    qint32 standard;
    bool m_standard_isSet;

    qint32 modulation;
    bool m_modulation_isSet;

    qint32 fec;
    bool m_fec_isSet;

    qint32 symbol_rate;
    bool m_symbol_rate_isSet;

    float roll_off;
    bool m_roll_off_isSet;

    qint32 ts_source;
    bool m_ts_source_isSet;

    QString* ts_file_name;
    bool m_ts_file_name_isSet;

    qint32 ts_file_play_loop;
    bool m_ts_file_play_loop_isSet;

    qint32 ts_file_play;
    bool m_ts_file_play_isSet;

    QString* udp_address;
    bool m_udp_address_isSet;

    qint32 udp_port;
    bool m_udp_port_isSet;

    qint32 channel_mute;
    bool m_channel_mute_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

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

#endif /* SWGDATVModSettings_H_ */
