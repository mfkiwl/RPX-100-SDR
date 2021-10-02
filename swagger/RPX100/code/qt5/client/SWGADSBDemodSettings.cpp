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


#include "SWGADSBDemodSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGADSBDemodSettings::SWGADSBDemodSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGADSBDemodSettings::SWGADSBDemodSettings() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    correlation_threshold = 0.0f;
    m_correlation_threshold_isSet = false;
    samples_per_bit = 0;
    m_samples_per_bit_isSet = false;
    remove_timeout = 0;
    m_remove_timeout_isSet = false;
    beast_enabled = 0;
    m_beast_enabled_isSet = false;
    beast_host = nullptr;
    m_beast_host_isSet = false;
    beast_port = 0;
    m_beast_port_isSet = false;
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

SWGADSBDemodSettings::~SWGADSBDemodSettings() {
    this->cleanup();
}

void
SWGADSBDemodSettings::init() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    correlation_threshold = 0.0f;
    m_correlation_threshold_isSet = false;
    samples_per_bit = 0;
    m_samples_per_bit_isSet = false;
    remove_timeout = 0;
    m_remove_timeout_isSet = false;
    beast_enabled = 0;
    m_beast_enabled_isSet = false;
    beast_host = new QString("");
    m_beast_host_isSet = false;
    beast_port = 0;
    m_beast_port_isSet = false;
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
SWGADSBDemodSettings::cleanup() {






    if(beast_host != nullptr) { 
        delete beast_host;
    }


    if(title != nullptr) { 
        delete title;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGADSBDemodSettings*
SWGADSBDemodSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGADSBDemodSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint64", "");
    
    ::SWGRPX100::setValue(&rf_bandwidth, pJson["rfBandwidth"], "float", "");
    
    ::SWGRPX100::setValue(&correlation_threshold, pJson["correlationThreshold"], "float", "");
    
    ::SWGRPX100::setValue(&samples_per_bit, pJson["samplesPerBit"], "qint32", "");
    
    ::SWGRPX100::setValue(&remove_timeout, pJson["removeTimeout"], "qint32", "");
    
    ::SWGRPX100::setValue(&beast_enabled, pJson["beastEnabled"], "qint32", "");
    
    ::SWGRPX100::setValue(&beast_host, pJson["beastHost"], "QString", "QString");
    
    ::SWGRPX100::setValue(&beast_port, pJson["beastPort"], "qint32", "");
    
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
SWGADSBDemodSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGADSBDemodSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(m_rf_bandwidth_isSet){
        obj->insert("rfBandwidth", QJsonValue(rf_bandwidth));
    }
    if(m_correlation_threshold_isSet){
        obj->insert("correlationThreshold", QJsonValue(correlation_threshold));
    }
    if(m_samples_per_bit_isSet){
        obj->insert("samplesPerBit", QJsonValue(samples_per_bit));
    }
    if(m_remove_timeout_isSet){
        obj->insert("removeTimeout", QJsonValue(remove_timeout));
    }
    if(m_beast_enabled_isSet){
        obj->insert("beastEnabled", QJsonValue(beast_enabled));
    }
    if(beast_host != nullptr && *beast_host != QString("")){
        toJsonValue(QString("beastHost"), beast_host, obj, QString("QString"));
    }
    if(m_beast_port_isSet){
        obj->insert("beastPort", QJsonValue(beast_port));
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

qint64
SWGADSBDemodSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGADSBDemodSettings::setInputFrequencyOffset(qint64 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

float
SWGADSBDemodSettings::getRfBandwidth() {
    return rf_bandwidth;
}
void
SWGADSBDemodSettings::setRfBandwidth(float rf_bandwidth) {
    this->rf_bandwidth = rf_bandwidth;
    this->m_rf_bandwidth_isSet = true;
}

float
SWGADSBDemodSettings::getCorrelationThreshold() {
    return correlation_threshold;
}
void
SWGADSBDemodSettings::setCorrelationThreshold(float correlation_threshold) {
    this->correlation_threshold = correlation_threshold;
    this->m_correlation_threshold_isSet = true;
}

qint32
SWGADSBDemodSettings::getSamplesPerBit() {
    return samples_per_bit;
}
void
SWGADSBDemodSettings::setSamplesPerBit(qint32 samples_per_bit) {
    this->samples_per_bit = samples_per_bit;
    this->m_samples_per_bit_isSet = true;
}

qint32
SWGADSBDemodSettings::getRemoveTimeout() {
    return remove_timeout;
}
void
SWGADSBDemodSettings::setRemoveTimeout(qint32 remove_timeout) {
    this->remove_timeout = remove_timeout;
    this->m_remove_timeout_isSet = true;
}

qint32
SWGADSBDemodSettings::getBeastEnabled() {
    return beast_enabled;
}
void
SWGADSBDemodSettings::setBeastEnabled(qint32 beast_enabled) {
    this->beast_enabled = beast_enabled;
    this->m_beast_enabled_isSet = true;
}

QString*
SWGADSBDemodSettings::getBeastHost() {
    return beast_host;
}
void
SWGADSBDemodSettings::setBeastHost(QString* beast_host) {
    this->beast_host = beast_host;
    this->m_beast_host_isSet = true;
}

qint32
SWGADSBDemodSettings::getBeastPort() {
    return beast_port;
}
void
SWGADSBDemodSettings::setBeastPort(qint32 beast_port) {
    this->beast_port = beast_port;
    this->m_beast_port_isSet = true;
}

qint32
SWGADSBDemodSettings::getRgbColor() {
    return rgb_color;
}
void
SWGADSBDemodSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGADSBDemodSettings::getTitle() {
    return title;
}
void
SWGADSBDemodSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGADSBDemodSettings::getStreamIndex() {
    return stream_index;
}
void
SWGADSBDemodSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGADSBDemodSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGADSBDemodSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGADSBDemodSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGADSBDemodSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGADSBDemodSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGADSBDemodSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGADSBDemodSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGADSBDemodSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGADSBDemodSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGADSBDemodSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGADSBDemodSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rf_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_correlation_threshold_isSet){
            isObjectUpdated = true; break;
        }
        if(m_samples_per_bit_isSet){
            isObjectUpdated = true; break;
        }
        if(m_remove_timeout_isSet){
            isObjectUpdated = true; break;
        }
        if(m_beast_enabled_isSet){
            isObjectUpdated = true; break;
        }
        if(beast_host && *beast_host != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_beast_port_isSet){
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

