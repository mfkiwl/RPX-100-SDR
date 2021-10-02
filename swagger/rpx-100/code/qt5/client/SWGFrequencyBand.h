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
 * SWGFrequencyBand.h
 *
 * A band of frequencies given its boudaries in Hertz (Hz)
 */

#ifndef SWGFrequencyBand_H_
#define SWGFrequencyBand_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGFrequencyBand: public SWGObject {
public:
    SWGFrequencyBand();
    SWGFrequencyBand(QString* json);
    virtual ~SWGFrequencyBand();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGFrequencyBand* fromJson(QString &jsonString) override;

    QString* getName();
    void setName(QString* name);

    qint32 getLowerBound();
    void setLowerBound(qint32 lower_bound);

    qint32 getHigherBound();
    void setHigherBound(qint32 higher_bound);


    virtual bool isSet() override;

private:
    QString* name;
    bool m_name_isSet;

    qint32 lower_bound;
    bool m_lower_bound_isSet;

    qint32 higher_bound;
    bool m_higher_bound_isSet;

};

}

#endif /* SWGFrequencyBand_H_ */
