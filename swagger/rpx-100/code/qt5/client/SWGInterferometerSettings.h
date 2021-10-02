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
 * SWGInterferometerSettings.h
 *
 * Interferometer
 */

#ifndef SWGInterferometerSettings_H_
#define SWGInterferometerSettings_H_

#include <QJsonObject>


#include "SWGGLScope.h"
#include "SWGGLSpectrum.h"
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGInterferometerSettings: public SWGObject {
public:
    SWGInterferometerSettings();
    SWGInterferometerSettings(QString* json);
    virtual ~SWGInterferometerSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGInterferometerSettings* fromJson(QString &jsonString) override;

    qint32 getCorrelationType();
    void setCorrelationType(qint32 correlation_type);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    qint32 getLog2Decim();
    void setLog2Decim(qint32 log2_decim);

    qint32 getFilterChainHash();
    void setFilterChainHash(qint32 filter_chain_hash);

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

    SWGGLSpectrum* getSpectrumConfig();
    void setSpectrumConfig(SWGGLSpectrum* spectrum_config);

    SWGGLScope* getScopeConfig();
    void setScopeConfig(SWGGLScope* scope_config);


    virtual bool isSet() override;

private:
    qint32 correlation_type;
    bool m_correlation_type_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    qint32 log2_decim;
    bool m_log2_decim_isSet;

    qint32 filter_chain_hash;
    bool m_filter_chain_hash_isSet;

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

    SWGGLSpectrum* spectrum_config;
    bool m_spectrum_config_isSet;

    SWGGLScope* scope_config;
    bool m_scope_config_isSet;

};

}

#endif /* SWGInterferometerSettings_H_ */
