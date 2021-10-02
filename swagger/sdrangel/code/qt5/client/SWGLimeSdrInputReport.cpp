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


#include "SWGLimeSdrInputReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGLimeSdrInputReport::SWGLimeSdrInputReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLimeSdrInputReport::SWGLimeSdrInputReport() {
    success = 0;
    m_success_isSet = false;
    stream_active = 0;
    m_stream_active_isSet = false;
    fifo_size = 0;
    m_fifo_size_isSet = false;
    fifo_fill = 0;
    m_fifo_fill_isSet = false;
    underrun_count = 0;
    m_underrun_count_isSet = false;
    overrun_count = 0;
    m_overrun_count_isSet = false;
    dropped_packets_count = 0;
    m_dropped_packets_count_isSet = false;
    link_rate = 0.0f;
    m_link_rate_isSet = false;
    hw_timestamp = 0L;
    m_hw_timestamp_isSet = false;
    temperature = 0.0f;
    m_temperature_isSet = false;
    gpio_dir = 0;
    m_gpio_dir_isSet = false;
    gpio_pins = 0;
    m_gpio_pins_isSet = false;
}

SWGLimeSdrInputReport::~SWGLimeSdrInputReport() {
    this->cleanup();
}

void
SWGLimeSdrInputReport::init() {
    success = 0;
    m_success_isSet = false;
    stream_active = 0;
    m_stream_active_isSet = false;
    fifo_size = 0;
    m_fifo_size_isSet = false;
    fifo_fill = 0;
    m_fifo_fill_isSet = false;
    underrun_count = 0;
    m_underrun_count_isSet = false;
    overrun_count = 0;
    m_overrun_count_isSet = false;
    dropped_packets_count = 0;
    m_dropped_packets_count_isSet = false;
    link_rate = 0.0f;
    m_link_rate_isSet = false;
    hw_timestamp = 0L;
    m_hw_timestamp_isSet = false;
    temperature = 0.0f;
    m_temperature_isSet = false;
    gpio_dir = 0;
    m_gpio_dir_isSet = false;
    gpio_pins = 0;
    m_gpio_pins_isSet = false;
}

void
SWGLimeSdrInputReport::cleanup() {












}

SWGLimeSdrInputReport*
SWGLimeSdrInputReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLimeSdrInputReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&success, pJson["success"], "qint32", "");
    
    ::SWGrpx-100::setValue(&stream_active, pJson["streamActive"], "qint32", "");
    
    ::SWGrpx-100::setValue(&fifo_size, pJson["fifoSize"], "qint32", "");
    
    ::SWGrpx-100::setValue(&fifo_fill, pJson["fifoFill"], "qint32", "");
    
    ::SWGrpx-100::setValue(&underrun_count, pJson["underrunCount"], "qint32", "");
    
    ::SWGrpx-100::setValue(&overrun_count, pJson["overrunCount"], "qint32", "");
    
    ::SWGrpx-100::setValue(&dropped_packets_count, pJson["droppedPacketsCount"], "qint32", "");
    
    ::SWGrpx-100::setValue(&link_rate, pJson["linkRate"], "float", "");
    
    ::SWGrpx-100::setValue(&hw_timestamp, pJson["hwTimestamp"], "qint64", "");
    
    ::SWGrpx-100::setValue(&temperature, pJson["temperature"], "float", "");
    
    ::SWGrpx-100::setValue(&gpio_dir, pJson["gpioDir"], "qint32", "");
    
    ::SWGrpx-100::setValue(&gpio_pins, pJson["gpioPins"], "qint32", "");
    
}

QString
SWGLimeSdrInputReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGLimeSdrInputReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_success_isSet){
        obj->insert("success", QJsonValue(success));
    }
    if(m_stream_active_isSet){
        obj->insert("streamActive", QJsonValue(stream_active));
    }
    if(m_fifo_size_isSet){
        obj->insert("fifoSize", QJsonValue(fifo_size));
    }
    if(m_fifo_fill_isSet){
        obj->insert("fifoFill", QJsonValue(fifo_fill));
    }
    if(m_underrun_count_isSet){
        obj->insert("underrunCount", QJsonValue(underrun_count));
    }
    if(m_overrun_count_isSet){
        obj->insert("overrunCount", QJsonValue(overrun_count));
    }
    if(m_dropped_packets_count_isSet){
        obj->insert("droppedPacketsCount", QJsonValue(dropped_packets_count));
    }
    if(m_link_rate_isSet){
        obj->insert("linkRate", QJsonValue(link_rate));
    }
    if(m_hw_timestamp_isSet){
        obj->insert("hwTimestamp", QJsonValue(hw_timestamp));
    }
    if(m_temperature_isSet){
        obj->insert("temperature", QJsonValue(temperature));
    }
    if(m_gpio_dir_isSet){
        obj->insert("gpioDir", QJsonValue(gpio_dir));
    }
    if(m_gpio_pins_isSet){
        obj->insert("gpioPins", QJsonValue(gpio_pins));
    }

    return obj;
}

qint32
SWGLimeSdrInputReport::getSuccess() {
    return success;
}
void
SWGLimeSdrInputReport::setSuccess(qint32 success) {
    this->success = success;
    this->m_success_isSet = true;
}

qint32
SWGLimeSdrInputReport::getStreamActive() {
    return stream_active;
}
void
SWGLimeSdrInputReport::setStreamActive(qint32 stream_active) {
    this->stream_active = stream_active;
    this->m_stream_active_isSet = true;
}

qint32
SWGLimeSdrInputReport::getFifoSize() {
    return fifo_size;
}
void
SWGLimeSdrInputReport::setFifoSize(qint32 fifo_size) {
    this->fifo_size = fifo_size;
    this->m_fifo_size_isSet = true;
}

qint32
SWGLimeSdrInputReport::getFifoFill() {
    return fifo_fill;
}
void
SWGLimeSdrInputReport::setFifoFill(qint32 fifo_fill) {
    this->fifo_fill = fifo_fill;
    this->m_fifo_fill_isSet = true;
}

qint32
SWGLimeSdrInputReport::getUnderrunCount() {
    return underrun_count;
}
void
SWGLimeSdrInputReport::setUnderrunCount(qint32 underrun_count) {
    this->underrun_count = underrun_count;
    this->m_underrun_count_isSet = true;
}

qint32
SWGLimeSdrInputReport::getOverrunCount() {
    return overrun_count;
}
void
SWGLimeSdrInputReport::setOverrunCount(qint32 overrun_count) {
    this->overrun_count = overrun_count;
    this->m_overrun_count_isSet = true;
}

qint32
SWGLimeSdrInputReport::getDroppedPacketsCount() {
    return dropped_packets_count;
}
void
SWGLimeSdrInputReport::setDroppedPacketsCount(qint32 dropped_packets_count) {
    this->dropped_packets_count = dropped_packets_count;
    this->m_dropped_packets_count_isSet = true;
}

float
SWGLimeSdrInputReport::getLinkRate() {
    return link_rate;
}
void
SWGLimeSdrInputReport::setLinkRate(float link_rate) {
    this->link_rate = link_rate;
    this->m_link_rate_isSet = true;
}

qint64
SWGLimeSdrInputReport::getHwTimestamp() {
    return hw_timestamp;
}
void
SWGLimeSdrInputReport::setHwTimestamp(qint64 hw_timestamp) {
    this->hw_timestamp = hw_timestamp;
    this->m_hw_timestamp_isSet = true;
}

float
SWGLimeSdrInputReport::getTemperature() {
    return temperature;
}
void
SWGLimeSdrInputReport::setTemperature(float temperature) {
    this->temperature = temperature;
    this->m_temperature_isSet = true;
}

qint32
SWGLimeSdrInputReport::getGpioDir() {
    return gpio_dir;
}
void
SWGLimeSdrInputReport::setGpioDir(qint32 gpio_dir) {
    this->gpio_dir = gpio_dir;
    this->m_gpio_dir_isSet = true;
}

qint32
SWGLimeSdrInputReport::getGpioPins() {
    return gpio_pins;
}
void
SWGLimeSdrInputReport::setGpioPins(qint32 gpio_pins) {
    this->gpio_pins = gpio_pins;
    this->m_gpio_pins_isSet = true;
}


bool
SWGLimeSdrInputReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_success_isSet){
            isObjectUpdated = true; break;
        }
        if(m_stream_active_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fifo_size_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fifo_fill_isSet){
            isObjectUpdated = true; break;
        }
        if(m_underrun_count_isSet){
            isObjectUpdated = true; break;
        }
        if(m_overrun_count_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dropped_packets_count_isSet){
            isObjectUpdated = true; break;
        }
        if(m_link_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_hw_timestamp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_temperature_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gpio_dir_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gpio_pins_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

