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
 * SWGPreferences.h
 *
 * Repreents a Prefernce object
 */

#ifndef SWGPreferences_H_
#define SWGPreferences_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGPreferences: public SWGObject {
public:
    SWGPreferences();
    SWGPreferences(QString* json);
    virtual ~SWGPreferences();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGPreferences* fromJson(QString &jsonString) override;

    QString* getSourceDevice();
    void setSourceDevice(QString* source_device);

    qint32 getSourceIndex();
    void setSourceIndex(qint32 source_index);

    QString* getAudioType();
    void setAudioType(QString* audio_type);

    QString* getAudioDevice();
    void setAudioDevice(QString* audio_device);

    float getLatitude();
    void setLatitude(float latitude);

    float getLongitude();
    void setLongitude(float longitude);

    qint32 getConsoleMinLogLevel();
    void setConsoleMinLogLevel(qint32 console_min_log_level);

    qint32 getUseLogFile();
    void setUseLogFile(qint32 use_log_file);

    QString* getLogFileName();
    void setLogFileName(QString* log_file_name);

    qint32 getFileMinLogLevel();
    void setFileMinLogLevel(qint32 file_min_log_level);


    virtual bool isSet() override;

private:
    QString* source_device;
    bool m_source_device_isSet;

    qint32 source_index;
    bool m_source_index_isSet;

    QString* audio_type;
    bool m_audio_type_isSet;

    QString* audio_device;
    bool m_audio_device_isSet;

    float latitude;
    bool m_latitude_isSet;

    float longitude;
    bool m_longitude_isSet;

    qint32 console_min_log_level;
    bool m_console_min_log_level_isSet;

    qint32 use_log_file;
    bool m_use_log_file_isSet;

    QString* log_file_name;
    bool m_log_file_name_isSet;

    qint32 file_min_log_level;
    bool m_file_min_log_level_isSet;

};

}

#endif /* SWGPreferences_H_ */
