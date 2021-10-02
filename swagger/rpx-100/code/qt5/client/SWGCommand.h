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
 * SWGCommand.h
 *
 * Represents a Command object
 */

#ifndef SWGCommand_H_
#define SWGCommand_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGCommand: public SWGObject {
public:
    SWGCommand();
    SWGCommand(QString* json);
    virtual ~SWGCommand();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGCommand* fromJson(QString &jsonString) override;

    QString* getGroup();
    void setGroup(QString* group);

    QString* getDescription();
    void setDescription(QString* description);

    QString* getCommand();
    void setCommand(QString* command);

    QString* getArgString();
    void setArgString(QString* arg_string);

    qint32 getKey();
    void setKey(qint32 key);

    qint32 getKeyModifiers();
    void setKeyModifiers(qint32 key_modifiers);

    qint32 getAssociateKey();
    void setAssociateKey(qint32 associate_key);

    qint32 getRelease();
    void setRelease(qint32 release);


    virtual bool isSet() override;

private:
    QString* group;
    bool m_group_isSet;

    QString* description;
    bool m_description_isSet;

    QString* command;
    bool m_command_isSet;

    QString* arg_string;
    bool m_arg_string_isSet;

    qint32 key;
    bool m_key_isSet;

    qint32 key_modifiers;
    bool m_key_modifiers_isSet;

    qint32 associate_key;
    bool m_associate_key_isSet;

    qint32 release;
    bool m_release_isSet;

};

}

#endif /* SWGCommand_H_ */
