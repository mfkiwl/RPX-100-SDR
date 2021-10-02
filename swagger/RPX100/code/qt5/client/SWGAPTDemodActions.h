/**
 * RPX100
 * This is the web REST/JSON API of RPX100 SDR software. RPX100 is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In RPX100 GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /RPX100/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGAPTDemodActions.h
 *
 * APTDemod
 */

#ifndef SWGAPTDemodActions_H_
#define SWGAPTDemodActions_H_

#include <QJsonObject>


#include "SWGAPTDemodActions_aos.h"
#include "SWGAPTDemodActions_los.h"

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGAPTDemodActions: public SWGObject {
public:
    SWGAPTDemodActions();
    SWGAPTDemodActions(QString* json);
    virtual ~SWGAPTDemodActions();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGAPTDemodActions* fromJson(QString &jsonString) override;

    SWGAPTDemodActions_aos* getAos();
    void setAos(SWGAPTDemodActions_aos* aos);

    SWGAPTDemodActions_los* getLos();
    void setLos(SWGAPTDemodActions_los* los);


    virtual bool isSet() override;

private:
    SWGAPTDemodActions_aos* aos;
    bool m_aos_isSet;

    SWGAPTDemodActions_los* los;
    bool m_los_isSet;

};

}

#endif /* SWGAPTDemodActions_H_ */
