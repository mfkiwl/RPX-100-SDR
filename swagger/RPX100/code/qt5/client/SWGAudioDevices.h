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
 * SWGAudioDevices.h
 *
 * List of audio devices available in the system
 */

#ifndef SWGAudioDevices_H_
#define SWGAudioDevices_H_

#include <QJsonObject>


#include "SWGAudioInputDevice.h"
#include "SWGAudioOutputDevice.h"
#include <QList>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGAudioDevices: public SWGObject {
public:
    SWGAudioDevices();
    SWGAudioDevices(QString* json);
    virtual ~SWGAudioDevices();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGAudioDevices* fromJson(QString &jsonString) override;

    qint32 getNbInputDevices();
    void setNbInputDevices(qint32 nb_input_devices);

    QList<SWGAudioInputDevice*>* getInputDevices();
    void setInputDevices(QList<SWGAudioInputDevice*>* input_devices);

    qint32 getNbOutputDevices();
    void setNbOutputDevices(qint32 nb_output_devices);

    QList<SWGAudioOutputDevice*>* getOutputDevices();
    void setOutputDevices(QList<SWGAudioOutputDevice*>* output_devices);


    virtual bool isSet() override;

private:
    qint32 nb_input_devices;
    bool m_nb_input_devices_isSet;

    QList<SWGAudioInputDevice*>* input_devices;
    bool m_input_devices_isSet;

    qint32 nb_output_devices;
    bool m_nb_output_devices_isSet;

    QList<SWGAudioOutputDevice*>* output_devices;
    bool m_output_devices_isSet;

};

}

#endif /* SWGAudioDevices_H_ */
