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
 * SWGLimeSdrInputReport.h
 *
 * LimeSDR
 */

#ifndef SWGLimeSdrInputReport_H_
#define SWGLimeSdrInputReport_H_

#include <QJsonObject>



#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGLimeSdrInputReport: public SWGObject {
public:
    SWGLimeSdrInputReport();
    SWGLimeSdrInputReport(QString* json);
    virtual ~SWGLimeSdrInputReport();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGLimeSdrInputReport* fromJson(QString &jsonString) override;

    qint32 getSuccess();
    void setSuccess(qint32 success);

    qint32 getStreamActive();
    void setStreamActive(qint32 stream_active);

    qint32 getFifoSize();
    void setFifoSize(qint32 fifo_size);

    qint32 getFifoFill();
    void setFifoFill(qint32 fifo_fill);

    qint32 getUnderrunCount();
    void setUnderrunCount(qint32 underrun_count);

    qint32 getOverrunCount();
    void setOverrunCount(qint32 overrun_count);

    qint32 getDroppedPacketsCount();
    void setDroppedPacketsCount(qint32 dropped_packets_count);

    float getLinkRate();
    void setLinkRate(float link_rate);

    qint64 getHwTimestamp();
    void setHwTimestamp(qint64 hw_timestamp);

    float getTemperature();
    void setTemperature(float temperature);

    qint32 getGpioDir();
    void setGpioDir(qint32 gpio_dir);

    qint32 getGpioPins();
    void setGpioPins(qint32 gpio_pins);


    virtual bool isSet() override;

private:
    qint32 success;
    bool m_success_isSet;

    qint32 stream_active;
    bool m_stream_active_isSet;

    qint32 fifo_size;
    bool m_fifo_size_isSet;

    qint32 fifo_fill;
    bool m_fifo_fill_isSet;

    qint32 underrun_count;
    bool m_underrun_count_isSet;

    qint32 overrun_count;
    bool m_overrun_count_isSet;

    qint32 dropped_packets_count;
    bool m_dropped_packets_count_isSet;

    float link_rate;
    bool m_link_rate_isSet;

    qint64 hw_timestamp;
    bool m_hw_timestamp_isSet;

    float temperature;
    bool m_temperature_isSet;

    qint32 gpio_dir;
    bool m_gpio_dir_isSet;

    qint32 gpio_pins;
    bool m_gpio_pins_isSet;

};

}

#endif /* SWGLimeSdrInputReport_H_ */
