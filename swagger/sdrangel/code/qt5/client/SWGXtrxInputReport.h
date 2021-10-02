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
 * SWGXtrxInputReport.h
 *
 * XTRX
 */

#ifndef SWGXtrxInputReport_H_
#define SWGXtrxInputReport_H_

#include <QJsonObject>



#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGXtrxInputReport: public SWGObject {
public:
    SWGXtrxInputReport();
    SWGXtrxInputReport(QString* json);
    virtual ~SWGXtrxInputReport();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGXtrxInputReport* fromJson(QString &jsonString) override;

    qint32 getSuccess();
    void setSuccess(qint32 success);

    qint32 getFifoSize();
    void setFifoSize(qint32 fifo_size);

    qint32 getFifoFill();
    void setFifoFill(qint32 fifo_fill);

    float getTemperature();
    void setTemperature(float temperature);

    qint32 getGpsLock();
    void setGpsLock(qint32 gps_lock);


    virtual bool isSet() override;

private:
    qint32 success;
    bool m_success_isSet;

    qint32 fifo_size;
    bool m_fifo_size_isSet;

    qint32 fifo_fill;
    bool m_fifo_fill_isSet;

    float temperature;
    bool m_temperature_isSet;

    qint32 gps_lock;
    bool m_gps_lock_isSet;

};

}

#endif /* SWGXtrxInputReport_H_ */
