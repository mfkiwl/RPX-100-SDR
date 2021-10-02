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


#include "SWGPagerDemodSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGPagerDemodSettings::SWGPagerDemodSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPagerDemodSettings::SWGPagerDemodSettings() {
    baud = 0;
    m_baud_isSet = false;
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    fm_deviation = 0.0f;
    m_fm_deviation_isSet = false;
    correlation_threshold = 0.0f;
    m_correlation_threshold_isSet = false;
    udp_enabled = 0;
    m_udp_enabled_isSet = false;
    udp_address = nullptr;
    m_udp_address_isSet = false;
    udp_port = 0;
    m_udp_port_isSet = false;
    udp_format = 0;
    m_udp_format_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

SWGPagerDemodSettings::~SWGPagerDemodSettings() {
    this->cleanup();
}

void
SWGPagerDemodSettings::init() {
    baud = 0;
    m_baud_isSet = false;
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    fm_deviation = 0.0f;
    m_fm_deviation_isSet = false;
    correlation_threshold = 0.0f;
    m_correlation_threshold_isSet = false;
    udp_enabled = 0;
    m_udp_enabled_isSet = false;
    udp_address = new QString("");
    m_udp_address_isSet = false;
    udp_port = 0;
    m_udp_port_isSet = false;
    udp_format = 0;
    m_udp_format_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

void
SWGPagerDemodSettings::cleanup() {






    if(udp_address != nullptr) { 
        delete udp_address;
    }



    if(title != nullptr) { 
        delete title;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGPagerDemodSettings*
SWGPagerDemodSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPagerDemodSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&baud, pJson["baud"], "qint32", "");
    
    ::SWGRPX100::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint64", "");
    
    ::SWGRPX100::setValue(&rf_bandwidth, pJson["rfBandwidth"], "float", "");
    
    ::SWGRPX100::setValue(&fm_deviation, pJson["fmDeviation"], "float", "");
    
    ::SWGRPX100::setValue(&correlation_threshold, pJson["correlationThreshold"], "float", "");
    
    ::SWGRPX100::setValue(&udp_enabled, pJson["udpEnabled"], "qint32", "");
    
    ::SWGRPX100::setValue(&udp_address, pJson["udpAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&udp_port, pJson["udpPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&udp_format, pJson["udpFormat"], "qint32", "");
    
    ::SWGRPX100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGRPX100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGRPX100::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGPagerDemodSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPagerDemodSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_baud_isSet){
        obj->insert("baud", QJsonValue(baud));
    }
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(m_rf_bandwidth_isSet){
        obj->insert("rfBandwidth", QJsonValue(rf_bandwidth));
    }
    if(m_fm_deviation_isSet){
        obj->insert("fmDeviation", QJsonValue(fm_deviation));
    }
    if(m_correlation_threshold_isSet){
        obj->insert("correlationThreshold", QJsonValue(correlation_threshold));
    }
    if(m_udp_enabled_isSet){
        obj->insert("udpEnabled", QJsonValue(udp_enabled));
    }
    if(udp_address != nullptr && *udp_address != QString("")){
        toJsonValue(QString("udpAddress"), udp_address, obj, QString("QString"));
    }
    if(m_udp_port_isSet){
        obj->insert("udpPort", QJsonValue(udp_port));
    }
    if(m_udp_format_isSet){
        obj->insert("udpFormat", QJsonValue(udp_format));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_stream_index_isSet){
        obj->insert("streamIndex", QJsonValue(stream_index));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }
    if(m_reverse_api_channel_index_isSet){
        obj->insert("reverseAPIChannelIndex", QJsonValue(reverse_api_channel_index));
    }

    return obj;
}

qint32
SWGPagerDemodSettings::getBaud() {
    return baud;
}
void
SWGPagerDemodSettings::setBaud(qint32 baud) {
    this->baud = baud;
    this->m_baud_isSet = true;
}

qint64
SWGPagerDemodSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGPagerDemodSettings::setInputFrequencyOffset(qint64 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

float
SWGPagerDemodSettings::getRfBandwidth() {
    return rf_bandwidth;
}
void
SWGPagerDemodSettings::setRfBandwidth(float rf_bandwidth) {
    this->rf_bandwidth = rf_bandwidth;
    this->m_rf_bandwidth_isSet = true;
}

float
SWGPagerDemodSettings::getFmDeviation() {
    return fm_deviation;
}
void
SWGPagerDemodSettings::setFmDeviation(float fm_deviation) {
    this->fm_deviation = fm_deviation;
    this->m_fm_deviation_isSet = true;
}

float
SWGPagerDemodSettings::getCorrelationThreshold() {
    return correlation_threshold;
}
void
SWGPagerDemodSettings::setCorrelationThreshold(float correlation_threshold) {
    this->correlation_threshold = correlation_threshold;
    this->m_correlation_threshold_isSet = true;
}

qint32
SWGPagerDemodSettings::getUdpEnabled() {
    return udp_enabled;
}
void
SWGPagerDemodSettings::setUdpEnabled(qint32 udp_enabled) {
    this->udp_enabled = udp_enabled;
    this->m_udp_enabled_isSet = true;
}

QString*
SWGPagerDemodSettings::getUdpAddress() {
    return udp_address;
}
void
SWGPagerDemodSettings::setUdpAddress(QString* udp_address) {
    this->udp_address = udp_address;
    this->m_udp_address_isSet = true;
}

qint32
SWGPagerDemodSettings::getUdpPort() {
    return udp_port;
}
void
SWGPagerDemodSettings::setUdpPort(qint32 udp_port) {
    this->udp_port = udp_port;
    this->m_udp_port_isSet = true;
}

qint32
SWGPagerDemodSettings::getUdpFormat() {
    return udp_format;
}
void
SWGPagerDemodSettings::setUdpFormat(qint32 udp_format) {
    this->udp_format = udp_format;
    this->m_udp_format_isSet = true;
}

qint32
SWGPagerDemodSettings::getRgbColor() {
    return rgb_color;
}
void
SWGPagerDemodSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGPagerDemodSettings::getTitle() {
    return title;
}
void
SWGPagerDemodSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGPagerDemodSettings::getStreamIndex() {
    return stream_index;
}
void
SWGPagerDemodSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGPagerDemodSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGPagerDemodSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGPagerDemodSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGPagerDemodSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGPagerDemodSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGPagerDemodSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGPagerDemodSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGPagerDemodSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGPagerDemodSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGPagerDemodSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGPagerDemodSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_baud_isSet){
            isObjectUpdated = true; break;
        }
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rf_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fm_deviation_isSet){
            isObjectUpdated = true; break;
        }
        if(m_correlation_threshold_isSet){
            isObjectUpdated = true; break;
        }
        if(m_udp_enabled_isSet){
            isObjectUpdated = true; break;
        }
        if(udp_address && *udp_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_udp_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_udp_format_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_stream_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_channel_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

