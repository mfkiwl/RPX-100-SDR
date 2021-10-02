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
 * SWGPresets.h
 *
 * Settings presets
 */

#ifndef SWGPresets_H_
#define SWGPresets_H_

#include <QJsonObject>


#include "SWGPresetGroup.h"
#include <QList>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGPresets: public SWGObject {
public:
    SWGPresets();
    SWGPresets(QString* json);
    virtual ~SWGPresets();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGPresets* fromJson(QString &jsonString) override;

    qint32 getNbGroups();
    void setNbGroups(qint32 nb_groups);

    QList<SWGPresetGroup*>* getGroups();
    void setGroups(QList<SWGPresetGroup*>* groups);


    virtual bool isSet() override;

private:
    qint32 nb_groups;
    bool m_nb_groups_isSet;

    QList<SWGPresetGroup*>* groups;
    bool m_groups_isSet;

};

}

#endif /* SWGPresets_H_ */
