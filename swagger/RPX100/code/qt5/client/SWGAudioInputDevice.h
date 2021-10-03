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
 * SWGAudioInputDevice.h
 *
 * Audio input device
 */

#ifndef SWGAudioInputDevice_H_
#define SWGAudioInputDevice_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGAudioInputDevice: public SWGObject {
public:
    SWGAudioInputDevice();
    SWGAudioInputDevice(QString* json);
    virtual ~SWGAudioInputDevice();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGAudioInputDevice* fromJson(QString &jsonString) override;

    QString* getName();
    void setName(QString* name);

    qint32 getIndex();
    void setIndex(qint32 index);

    qint32 getSampleRate();
    void setSampleRate(qint32 sample_rate);

    qint32 getIsSystemDefault();
    void setIsSystemDefault(qint32 is_system_default);

    qint32 getDefaultUnregistered();
    void setDefaultUnregistered(qint32 default_unregistered);

    float getVolume();
    void setVolume(float volume);


    virtual bool isSet() override;

private:
    QString* name;
    bool m_name_isSet;

    qint32 index;
    bool m_index_isSet;

    qint32 sample_rate;
    bool m_sample_rate_isSet;

    qint32 is_system_default;
    bool m_is_system_default_isSet;

    qint32 default_unregistered;
    bool m_default_unregistered_isSet;

    float volume;
    bool m_volume_isSet;

};

}

#endif /* SWGAudioInputDevice_H_ */
