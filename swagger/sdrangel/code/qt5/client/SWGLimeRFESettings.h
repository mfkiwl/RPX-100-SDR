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
 * SWGLimeRFESettings.h
 *
 * LimeRFE
 */

#ifndef SWGLimeRFESettings_H_
#define SWGLimeRFESettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGLimeRFESettings: public SWGObject {
public:
    SWGLimeRFESettings();
    SWGLimeRFESettings(QString* json);
    virtual ~SWGLimeRFESettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGLimeRFESettings* fromJson(QString &jsonString) override;

    QString* getDevicePath();
    void setDevicePath(QString* device_path);

    qint32 getRxChannels();
    void setRxChannels(qint32 rx_channels);

    qint32 getRxWidebandChannel();
    void setRxWidebandChannel(qint32 rx_wideband_channel);

    qint32 getRxHamChannel();
    void setRxHamChannel(qint32 rx_ham_channel);

    qint32 getRxCellularChannel();
    void setRxCellularChannel(qint32 rx_cellular_channel);

    qint32 getRxPort();
    void setRxPort(qint32 rx_port);

    qint32 getAttenuationFactor();
    void setAttenuationFactor(qint32 attenuation_factor);

    qint32 getAmfmNotch();
    void setAmfmNotch(qint32 amfm_notch);

    qint32 getTxChannels();
    void setTxChannels(qint32 tx_channels);

    qint32 getTxWidebandChannel();
    void setTxWidebandChannel(qint32 tx_wideband_channel);

    qint32 getTxHamChannel();
    void setTxHamChannel(qint32 tx_ham_channel);

    qint32 getTxCellularChannel();
    void setTxCellularChannel(qint32 tx_cellular_channel);

    qint32 getTxPort();
    void setTxPort(qint32 tx_port);

    qint32 getSwrEnable();
    void setSwrEnable(qint32 swr_enable);

    qint32 getSwrSource();
    void setSwrSource(qint32 swr_source);

    qint32 getRxOn();
    void setRxOn(qint32 rx_on);

    qint32 getTxOn();
    void setTxOn(qint32 tx_on);


    virtual bool isSet() override;

private:
    QString* device_path;
    bool m_device_path_isSet;

    qint32 rx_channels;
    bool m_rx_channels_isSet;

    qint32 rx_wideband_channel;
    bool m_rx_wideband_channel_isSet;

    qint32 rx_ham_channel;
    bool m_rx_ham_channel_isSet;

    qint32 rx_cellular_channel;
    bool m_rx_cellular_channel_isSet;

    qint32 rx_port;
    bool m_rx_port_isSet;

    qint32 attenuation_factor;
    bool m_attenuation_factor_isSet;

    qint32 amfm_notch;
    bool m_amfm_notch_isSet;

    qint32 tx_channels;
    bool m_tx_channels_isSet;

    qint32 tx_wideband_channel;
    bool m_tx_wideband_channel_isSet;

    qint32 tx_ham_channel;
    bool m_tx_ham_channel_isSet;

    qint32 tx_cellular_channel;
    bool m_tx_cellular_channel_isSet;

    qint32 tx_port;
    bool m_tx_port_isSet;

    qint32 swr_enable;
    bool m_swr_enable_isSet;

    qint32 swr_source;
    bool m_swr_source_isSet;

    qint32 rx_on;
    bool m_rx_on_isSet;

    qint32 tx_on;
    bool m_tx_on_isSet;

};

}

#endif /* SWGLimeRFESettings_H_ */
