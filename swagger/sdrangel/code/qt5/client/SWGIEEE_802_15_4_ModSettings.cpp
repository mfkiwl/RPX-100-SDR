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


#include "SWGIEEE_802_15_4_ModSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGIEEE_802_15_4_ModSettings::SWGIEEE_802_15_4_ModSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGIEEE_802_15_4_ModSettings::SWGIEEE_802_15_4_ModSettings() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    phy = nullptr;
    m_phy_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    gain = 0.0f;
    m_gain_isSet = false;
    channel_mute = 0;
    m_channel_mute_isSet = false;
    repeat = 0;
    m_repeat_isSet = false;
    repeat_delay = 0.0f;
    m_repeat_delay_isSet = false;
    repeat_count = 0;
    m_repeat_count_isSet = false;
    udp_enabled = 0;
    m_udp_enabled_isSet = false;
    udp_address = nullptr;
    m_udp_address_isSet = false;
    udp_port = 0;
    m_udp_port_isSet = false;
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

SWGIEEE_802_15_4_ModSettings::~SWGIEEE_802_15_4_ModSettings() {
    this->cleanup();
}

void
SWGIEEE_802_15_4_ModSettings::init() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    phy = new QString("");
    m_phy_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    gain = 0.0f;
    m_gain_isSet = false;
    channel_mute = 0;
    m_channel_mute_isSet = false;
    repeat = 0;
    m_repeat_isSet = false;
    repeat_delay = 0.0f;
    m_repeat_delay_isSet = false;
    repeat_count = 0;
    m_repeat_count_isSet = false;
    udp_enabled = 0;
    m_udp_enabled_isSet = false;
    udp_address = new QString("");
    m_udp_address_isSet = false;
    udp_port = 0;
    m_udp_port_isSet = false;
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
SWGIEEE_802_15_4_ModSettings::cleanup() {

    if(phy != nullptr) { 
        delete phy;
    }







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

SWGIEEE_802_15_4_ModSettings*
SWGIEEE_802_15_4_ModSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGIEEE_802_15_4_ModSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint64", "");
    
    ::SWGrpx-100::setValue(&phy, pJson["phy"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&rf_bandwidth, pJson["rfBandwidth"], "float", "");
    
    ::SWGrpx-100::setValue(&gain, pJson["gain"], "float", "");
    
    ::SWGrpx-100::setValue(&channel_mute, pJson["channelMute"], "qint32", "");
    
    ::SWGrpx-100::setValue(&repeat, pJson["repeat"], "qint32", "");
    
    ::SWGrpx-100::setValue(&repeat_delay, pJson["repeatDelay"], "float", "");
    
    ::SWGrpx-100::setValue(&repeat_count, pJson["repeatCount"], "qint32", "");
    
    ::SWGrpx-100::setValue(&udp_enabled, pJson["udpEnabled"], "qint32", "");
    
    ::SWGrpx-100::setValue(&udp_address, pJson["udpAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&udp_port, pJson["udpPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGrpx-100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGIEEE_802_15_4_ModSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGIEEE_802_15_4_ModSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(phy != nullptr && *phy != QString("")){
        toJsonValue(QString("phy"), phy, obj, QString("QString"));
    }
    if(m_rf_bandwidth_isSet){
        obj->insert("rfBandwidth", QJsonValue(rf_bandwidth));
    }
    if(m_gain_isSet){
        obj->insert("gain", QJsonValue(gain));
    }
    if(m_channel_mute_isSet){
        obj->insert("channelMute", QJsonValue(channel_mute));
    }
    if(m_repeat_isSet){
        obj->insert("repeat", QJsonValue(repeat));
    }
    if(m_repeat_delay_isSet){
        obj->insert("repeatDelay", QJsonValue(repeat_delay));
    }
    if(m_repeat_count_isSet){
        obj->insert("repeatCount", QJsonValue(repeat_count));
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
SWGIEEE_802_15_4_ModSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGIEEE_802_15_4_ModSettings::setInputFrequencyOffset(qint64 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

QString*
SWGIEEE_802_15_4_ModSettings::getPhy() {
    return phy;
}
void
SWGIEEE_802_15_4_ModSettings::setPhy(QString* phy) {
    this->phy = phy;
    this->m_phy_isSet = true;
}

float
SWGIEEE_802_15_4_ModSettings::getRfBandwidth() {
    return rf_bandwidth;
}
void
SWGIEEE_802_15_4_ModSettings::setRfBandwidth(float rf_bandwidth) {
    this->rf_bandwidth = rf_bandwidth;
    this->m_rf_bandwidth_isSet = true;
}

float
SWGIEEE_802_15_4_ModSettings::getGain() {
    return gain;
}
void
SWGIEEE_802_15_4_ModSettings::setGain(float gain) {
    this->gain = gain;
    this->m_gain_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getChannelMute() {
    return channel_mute;
}
void
SWGIEEE_802_15_4_ModSettings::setChannelMute(qint32 channel_mute) {
    this->channel_mute = channel_mute;
    this->m_channel_mute_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getRepeat() {
    return repeat;
}
void
SWGIEEE_802_15_4_ModSettings::setRepeat(qint32 repeat) {
    this->repeat = repeat;
    this->m_repeat_isSet = true;
}

float
SWGIEEE_802_15_4_ModSettings::getRepeatDelay() {
    return repeat_delay;
}
void
SWGIEEE_802_15_4_ModSettings::setRepeatDelay(float repeat_delay) {
    this->repeat_delay = repeat_delay;
    this->m_repeat_delay_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getRepeatCount() {
    return repeat_count;
}
void
SWGIEEE_802_15_4_ModSettings::setRepeatCount(qint32 repeat_count) {
    this->repeat_count = repeat_count;
    this->m_repeat_count_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getUdpEnabled() {
    return udp_enabled;
}
void
SWGIEEE_802_15_4_ModSettings::setUdpEnabled(qint32 udp_enabled) {
    this->udp_enabled = udp_enabled;
    this->m_udp_enabled_isSet = true;
}

QString*
SWGIEEE_802_15_4_ModSettings::getUdpAddress() {
    return udp_address;
}
void
SWGIEEE_802_15_4_ModSettings::setUdpAddress(QString* udp_address) {
    this->udp_address = udp_address;
    this->m_udp_address_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getUdpPort() {
    return udp_port;
}
void
SWGIEEE_802_15_4_ModSettings::setUdpPort(qint32 udp_port) {
    this->udp_port = udp_port;
    this->m_udp_port_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getRgbColor() {
    return rgb_color;
}
void
SWGIEEE_802_15_4_ModSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGIEEE_802_15_4_ModSettings::getTitle() {
    return title;
}
void
SWGIEEE_802_15_4_ModSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getStreamIndex() {
    return stream_index;
}
void
SWGIEEE_802_15_4_ModSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGIEEE_802_15_4_ModSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGIEEE_802_15_4_ModSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGIEEE_802_15_4_ModSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGIEEE_802_15_4_ModSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGIEEE_802_15_4_ModSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGIEEE_802_15_4_ModSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGIEEE_802_15_4_ModSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGIEEE_802_15_4_ModSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(phy && *phy != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_rf_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_mute_isSet){
            isObjectUpdated = true; break;
        }
        if(m_repeat_isSet){
            isObjectUpdated = true; break;
        }
        if(m_repeat_delay_isSet){
            isObjectUpdated = true; break;
        }
        if(m_repeat_count_isSet){
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

