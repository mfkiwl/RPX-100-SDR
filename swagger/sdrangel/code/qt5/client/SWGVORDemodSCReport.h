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
 * SWGVORDemodSCReport.h
 *
 * VORDemodSC
 */

#ifndef SWGVORDemodSCReport_H_
#define SWGVORDemodSCReport_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGVORDemodSCReport: public SWGObject {
public:
    SWGVORDemodSCReport();
    SWGVORDemodSCReport(QString* json);
    virtual ~SWGVORDemodSCReport();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGVORDemodSCReport* fromJson(QString &jsonString) override;

    float getChannelPowerDb();
    void setChannelPowerDb(float channel_power_db);

    qint32 getSquelch();
    void setSquelch(qint32 squelch);

    qint32 getAudioSampleRate();
    void setAudioSampleRate(qint32 audio_sample_rate);

    float getVolume();
    void setVolume(float volume);

    qint32 getNavId();
    void setNavId(qint32 nav_id);

    float getRadial();
    void setRadial(float radial);

    float getRefMag();
    void setRefMag(float ref_mag);

    float getVarMag();
    void setVarMag(float var_mag);

    qint32 getValidRadial();
    void setValidRadial(qint32 valid_radial);

    qint32 getValidRefMag();
    void setValidRefMag(qint32 valid_ref_mag);

    qint32 getValidVarMag();
    void setValidVarMag(qint32 valid_var_mag);

    QString* getMorseIdent();
    void setMorseIdent(QString* morse_ident);


    virtual bool isSet() override;

private:
    float channel_power_db;
    bool m_channel_power_db_isSet;

    qint32 squelch;
    bool m_squelch_isSet;

    qint32 audio_sample_rate;
    bool m_audio_sample_rate_isSet;

    float volume;
    bool m_volume_isSet;

    qint32 nav_id;
    bool m_nav_id_isSet;

    float radial;
    bool m_radial_isSet;

    float ref_mag;
    bool m_ref_mag_isSet;

    float var_mag;
    bool m_var_mag_isSet;

    qint32 valid_radial;
    bool m_valid_radial_isSet;

    qint32 valid_ref_mag;
    bool m_valid_ref_mag_isSet;

    qint32 valid_var_mag;
    bool m_valid_var_mag_isSet;

    QString* morse_ident;
    bool m_morse_ident_isSet;

};

}

#endif /* SWGVORDemodSCReport_H_ */
