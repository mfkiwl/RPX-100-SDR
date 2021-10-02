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
 * SWGLimeSdrMIMOReport.h
 *
 * LimeSDR
 */

#ifndef SWGLimeSdrMIMOReport_H_
#define SWGLimeSdrMIMOReport_H_

#include <QJsonObject>



#include "SWGObject.h"
#include "export.h"

namespace SWGrpx-100 {

class SWG_API SWGLimeSdrMIMOReport: public SWGObject {
public:
    SWGLimeSdrMIMOReport();
    SWGLimeSdrMIMOReport(QString* json);
    virtual ~SWGLimeSdrMIMOReport();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGLimeSdrMIMOReport* fromJson(QString &jsonString) override;

    qint64 getHwTimestamp();
    void setHwTimestamp(qint64 hw_timestamp);

    float getTemperature();
    void setTemperature(float temperature);

    qint32 getGpioDir();
    void setGpioDir(qint32 gpio_dir);

    qint32 getGpioPins();
    void setGpioPins(qint32 gpio_pins);

    qint32 getSuccessRx();
    void setSuccessRx(qint32 success_rx);

    qint32 getStreamActiveRx();
    void setStreamActiveRx(qint32 stream_active_rx);

    qint32 getFifoSizeRx();
    void setFifoSizeRx(qint32 fifo_size_rx);

    qint32 getFifoFillRx();
    void setFifoFillRx(qint32 fifo_fill_rx);

    qint32 getUnderrunCountRx();
    void setUnderrunCountRx(qint32 underrun_count_rx);

    qint32 getOverrunCountRx();
    void setOverrunCountRx(qint32 overrun_count_rx);

    qint32 getDroppedPacketsCountRx();
    void setDroppedPacketsCountRx(qint32 dropped_packets_count_rx);

    float getLinkRateRx();
    void setLinkRateRx(float link_rate_rx);

    qint32 getSuccessTx();
    void setSuccessTx(qint32 success_tx);

    qint32 getStreamActiveTx();
    void setStreamActiveTx(qint32 stream_active_tx);

    qint32 getFifoSizeTx();
    void setFifoSizeTx(qint32 fifo_size_tx);

    qint32 getFifoFillTx();
    void setFifoFillTx(qint32 fifo_fill_tx);

    qint32 getUnderrunCountTx();
    void setUnderrunCountTx(qint32 underrun_count_tx);

    qint32 getOverrunCountTx();
    void setOverrunCountTx(qint32 overrun_count_tx);

    qint32 getDroppedPacketsCountTx();
    void setDroppedPacketsCountTx(qint32 dropped_packets_count_tx);

    float getLinkRateTx();
    void setLinkRateTx(float link_rate_tx);


    virtual bool isSet() override;

private:
    qint64 hw_timestamp;
    bool m_hw_timestamp_isSet;

    float temperature;
    bool m_temperature_isSet;

    qint32 gpio_dir;
    bool m_gpio_dir_isSet;

    qint32 gpio_pins;
    bool m_gpio_pins_isSet;

    qint32 success_rx;
    bool m_success_rx_isSet;

    qint32 stream_active_rx;
    bool m_stream_active_rx_isSet;

    qint32 fifo_size_rx;
    bool m_fifo_size_rx_isSet;

    qint32 fifo_fill_rx;
    bool m_fifo_fill_rx_isSet;

    qint32 underrun_count_rx;
    bool m_underrun_count_rx_isSet;

    qint32 overrun_count_rx;
    bool m_overrun_count_rx_isSet;

    qint32 dropped_packets_count_rx;
    bool m_dropped_packets_count_rx_isSet;

    float link_rate_rx;
    bool m_link_rate_rx_isSet;

    qint32 success_tx;
    bool m_success_tx_isSet;

    qint32 stream_active_tx;
    bool m_stream_active_tx_isSet;

    qint32 fifo_size_tx;
    bool m_fifo_size_tx_isSet;

    qint32 fifo_fill_tx;
    bool m_fifo_fill_tx_isSet;

    qint32 underrun_count_tx;
    bool m_underrun_count_tx_isSet;

    qint32 overrun_count_tx;
    bool m_overrun_count_tx_isSet;

    qint32 dropped_packets_count_tx;
    bool m_dropped_packets_count_tx_isSet;

    float link_rate_tx;
    bool m_link_rate_tx_isSet;

};

}

#endif /* SWGLimeSdrMIMOReport_H_ */
