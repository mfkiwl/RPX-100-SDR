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


#include "SWGRigCtlServerSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGRigCtlServerSettings::SWGRigCtlServerSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRigCtlServerSettings::SWGRigCtlServerSettings() {
    enabled = 0;
    m_enabled_isSet = false;
    rig_ctl_port = 0;
    m_rig_ctl_port_isSet = false;
    max_frequency_offset = 0;
    m_max_frequency_offset_isSet = false;
    device_index = 0;
    m_device_index_isSet = false;
    channel_index = 0;
    m_channel_index_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_feature_set_index = 0;
    m_reverse_api_feature_set_index_isSet = false;
    reverse_api_feature_index = 0;
    m_reverse_api_feature_index_isSet = false;
}

SWGRigCtlServerSettings::~SWGRigCtlServerSettings() {
    this->cleanup();
}

void
SWGRigCtlServerSettings::init() {
    enabled = 0;
    m_enabled_isSet = false;
    rig_ctl_port = 0;
    m_rig_ctl_port_isSet = false;
    max_frequency_offset = 0;
    m_max_frequency_offset_isSet = false;
    device_index = 0;
    m_device_index_isSet = false;
    channel_index = 0;
    m_channel_index_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_feature_set_index = 0;
    m_reverse_api_feature_set_index_isSet = false;
    reverse_api_feature_index = 0;
    m_reverse_api_feature_index_isSet = false;
}

void
SWGRigCtlServerSettings::cleanup() {





    if(title != nullptr) { 
        delete title;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGRigCtlServerSettings*
SWGRigCtlServerSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRigCtlServerSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&enabled, pJson["enabled"], "qint32", "");
    
    ::SWGRPX100::setValue(&rig_ctl_port, pJson["rigCtlPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&max_frequency_offset, pJson["maxFrequencyOffset"], "qint32", "");
    
    ::SWGRPX100::setValue(&device_index, pJson["deviceIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&channel_index, pJson["channelIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGRPX100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGRPX100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_feature_set_index, pJson["reverseAPIFeatureSetIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_feature_index, pJson["reverseAPIFeatureIndex"], "qint32", "");
    
}

QString
SWGRigCtlServerSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGRigCtlServerSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_enabled_isSet){
        obj->insert("enabled", QJsonValue(enabled));
    }
    if(m_rig_ctl_port_isSet){
        obj->insert("rigCtlPort", QJsonValue(rig_ctl_port));
    }
    if(m_max_frequency_offset_isSet){
        obj->insert("maxFrequencyOffset", QJsonValue(max_frequency_offset));
    }
    if(m_device_index_isSet){
        obj->insert("deviceIndex", QJsonValue(device_index));
    }
    if(m_channel_index_isSet){
        obj->insert("channelIndex", QJsonValue(channel_index));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
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
    if(m_reverse_api_feature_set_index_isSet){
        obj->insert("reverseAPIFeatureSetIndex", QJsonValue(reverse_api_feature_set_index));
    }
    if(m_reverse_api_feature_index_isSet){
        obj->insert("reverseAPIFeatureIndex", QJsonValue(reverse_api_feature_index));
    }

    return obj;
}

qint32
SWGRigCtlServerSettings::getEnabled() {
    return enabled;
}
void
SWGRigCtlServerSettings::setEnabled(qint32 enabled) {
    this->enabled = enabled;
    this->m_enabled_isSet = true;
}

qint32
SWGRigCtlServerSettings::getRigCtlPort() {
    return rig_ctl_port;
}
void
SWGRigCtlServerSettings::setRigCtlPort(qint32 rig_ctl_port) {
    this->rig_ctl_port = rig_ctl_port;
    this->m_rig_ctl_port_isSet = true;
}

qint32
SWGRigCtlServerSettings::getMaxFrequencyOffset() {
    return max_frequency_offset;
}
void
SWGRigCtlServerSettings::setMaxFrequencyOffset(qint32 max_frequency_offset) {
    this->max_frequency_offset = max_frequency_offset;
    this->m_max_frequency_offset_isSet = true;
}

qint32
SWGRigCtlServerSettings::getDeviceIndex() {
    return device_index;
}
void
SWGRigCtlServerSettings::setDeviceIndex(qint32 device_index) {
    this->device_index = device_index;
    this->m_device_index_isSet = true;
}

qint32
SWGRigCtlServerSettings::getChannelIndex() {
    return channel_index;
}
void
SWGRigCtlServerSettings::setChannelIndex(qint32 channel_index) {
    this->channel_index = channel_index;
    this->m_channel_index_isSet = true;
}

QString*
SWGRigCtlServerSettings::getTitle() {
    return title;
}
void
SWGRigCtlServerSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGRigCtlServerSettings::getRgbColor() {
    return rgb_color;
}
void
SWGRigCtlServerSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

qint32
SWGRigCtlServerSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGRigCtlServerSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGRigCtlServerSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGRigCtlServerSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGRigCtlServerSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGRigCtlServerSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGRigCtlServerSettings::getReverseApiFeatureSetIndex() {
    return reverse_api_feature_set_index;
}
void
SWGRigCtlServerSettings::setReverseApiFeatureSetIndex(qint32 reverse_api_feature_set_index) {
    this->reverse_api_feature_set_index = reverse_api_feature_set_index;
    this->m_reverse_api_feature_set_index_isSet = true;
}

qint32
SWGRigCtlServerSettings::getReverseApiFeatureIndex() {
    return reverse_api_feature_index;
}
void
SWGRigCtlServerSettings::setReverseApiFeatureIndex(qint32 reverse_api_feature_index) {
    this->reverse_api_feature_index = reverse_api_feature_index;
    this->m_reverse_api_feature_index_isSet = true;
}


bool
SWGRigCtlServerSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_enabled_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rig_ctl_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_max_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_device_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_index_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
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
        if(m_reverse_api_feature_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_feature_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

