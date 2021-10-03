/**
 * RPX100
 * This is the web REST/JSON API of RPX100 SDR software. RPX100 is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In RPX100 GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /RPX100/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: oe3biabernhard@isemann.at
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGLRPTDemodSettings.h
 *
 * LRPTDemod
 */

#ifndef SWGLRPTDemodSettings_H_
#define SWGLRPTDemodSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGLRPTDemodSettings: public SWGObject {
public:
    SWGLRPTDemodSettings();
    SWGLRPTDemodSettings(QString* json);
    virtual ~SWGLRPTDemodSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGLRPTDemodSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getRfBandwidth();
    void setRfBandwidth(float rf_bandwidth);

    qint32 getFmDeviation();
    void setFmDeviation(qint32 fm_deviation);

    qint32 getCropNoise();
    void setCropNoise(qint32 crop_noise);

    qint32 getDenoise();
    void setDenoise(qint32 denoise);

    qint32 getLinearEqualise();
    void setLinearEqualise(qint32 linear_equalise);

    qint32 getHistogramEqualise();
    void setHistogramEqualise(qint32 histogram_equalise);

    qint32 getPrecipitationOverlay();
    void setPrecipitationOverlay(qint32 precipitation_overlay);

    qint32 getFlip();
    void setFlip(qint32 flip);

    qint32 getChannels();
    void setChannels(qint32 channels);

    qint32 getDecodeEnabled();
    void setDecodeEnabled(qint32 decode_enabled);

    qint32 getAutoSave();
    void setAutoSave(qint32 auto_save);

    QString* getAutoSavePath();
    void setAutoSavePath(QString* auto_save_path);

    qint32 getAutoSaveMinScanLines();
    void setAutoSaveMinScanLines(qint32 auto_save_min_scan_lines);

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

    qint32 fm_deviation;
    bool m_fm_deviation_isSet;

    qint32 crop_noise;
    bool m_crop_noise_isSet;

    qint32 denoise;
    bool m_denoise_isSet;

    qint32 linear_equalise;
    bool m_linear_equalise_isSet;

    qint32 histogram_equalise;
    bool m_histogram_equalise_isSet;

    qint32 precipitation_overlay;
    bool m_precipitation_overlay_isSet;

    qint32 flip;
    bool m_flip_isSet;

    qint32 channels;
    bool m_channels_isSet;

    qint32 decode_enabled;
    bool m_decode_enabled_isSet;

    qint32 auto_save;
    bool m_auto_save_isSet;

    QString* auto_save_path;
    bool m_auto_save_path_isSet;

    qint32 auto_save_min_scan_lines;
    bool m_auto_save_min_scan_lines_isSet;

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

#endif /* SWGLRPTDemodSettings_H_ */
