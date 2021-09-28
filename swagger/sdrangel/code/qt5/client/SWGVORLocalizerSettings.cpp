/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGVORLocalizerSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGVORLocalizerSettings::SWGVORLocalizerSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGVORLocalizerSettings::SWGVORLocalizerSettings() {
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
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
    mag_dec_adjust = 0;
    m_mag_dec_adjust_isSet = false;
    rr_time = 0;
    m_rr_time_isSet = false;
    force_rr_averaging = 0;
    m_force_rr_averaging_isSet = false;
    center_shift = 0;
    m_center_shift_isSet = false;
}

SWGVORLocalizerSettings::~SWGVORLocalizerSettings() {
    this->cleanup();
}

void
SWGVORLocalizerSettings::init() {
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
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
    mag_dec_adjust = 0;
    m_mag_dec_adjust_isSet = false;
    rr_time = 0;
    m_rr_time_isSet = false;
    force_rr_averaging = 0;
    m_force_rr_averaging_isSet = false;
    center_shift = 0;
    m_center_shift_isSet = false;
}

void
SWGVORLocalizerSettings::cleanup() {

    if(title != nullptr) { 
        delete title;
    }

    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }







}

SWGVORLocalizerSettings*
SWGVORLocalizerSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGVORLocalizerSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGSDRangel::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_feature_set_index, pJson["reverseAPIFeatureSetIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_feature_index, pJson["reverseAPIFeatureIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&mag_dec_adjust, pJson["magDecAdjust"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rr_time, pJson["rrTime"], "qint32", "");
    
    ::SWGSDRangel::setValue(&force_rr_averaging, pJson["forceRRAveraging"], "qint32", "");
    
    ::SWGSDRangel::setValue(&center_shift, pJson["centerShift"], "qint32", "");
    
}

QString
SWGVORLocalizerSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGVORLocalizerSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
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
    if(m_mag_dec_adjust_isSet){
        obj->insert("magDecAdjust", QJsonValue(mag_dec_adjust));
    }
    if(m_rr_time_isSet){
        obj->insert("rrTime", QJsonValue(rr_time));
    }
    if(m_force_rr_averaging_isSet){
        obj->insert("forceRRAveraging", QJsonValue(force_rr_averaging));
    }
    if(m_center_shift_isSet){
        obj->insert("centerShift", QJsonValue(center_shift));
    }

    return obj;
}

qint32
SWGVORLocalizerSettings::getRgbColor() {
    return rgb_color;
}
void
SWGVORLocalizerSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGVORLocalizerSettings::getTitle() {
    return title;
}
void
SWGVORLocalizerSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGVORLocalizerSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGVORLocalizerSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGVORLocalizerSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGVORLocalizerSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGVORLocalizerSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGVORLocalizerSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGVORLocalizerSettings::getReverseApiFeatureSetIndex() {
    return reverse_api_feature_set_index;
}
void
SWGVORLocalizerSettings::setReverseApiFeatureSetIndex(qint32 reverse_api_feature_set_index) {
    this->reverse_api_feature_set_index = reverse_api_feature_set_index;
    this->m_reverse_api_feature_set_index_isSet = true;
}

qint32
SWGVORLocalizerSettings::getReverseApiFeatureIndex() {
    return reverse_api_feature_index;
}
void
SWGVORLocalizerSettings::setReverseApiFeatureIndex(qint32 reverse_api_feature_index) {
    this->reverse_api_feature_index = reverse_api_feature_index;
    this->m_reverse_api_feature_index_isSet = true;
}

qint32
SWGVORLocalizerSettings::getMagDecAdjust() {
    return mag_dec_adjust;
}
void
SWGVORLocalizerSettings::setMagDecAdjust(qint32 mag_dec_adjust) {
    this->mag_dec_adjust = mag_dec_adjust;
    this->m_mag_dec_adjust_isSet = true;
}

qint32
SWGVORLocalizerSettings::getRrTime() {
    return rr_time;
}
void
SWGVORLocalizerSettings::setRrTime(qint32 rr_time) {
    this->rr_time = rr_time;
    this->m_rr_time_isSet = true;
}

qint32
SWGVORLocalizerSettings::getForceRrAveraging() {
    return force_rr_averaging;
}
void
SWGVORLocalizerSettings::setForceRrAveraging(qint32 force_rr_averaging) {
    this->force_rr_averaging = force_rr_averaging;
    this->m_force_rr_averaging_isSet = true;
}

qint32
SWGVORLocalizerSettings::getCenterShift() {
    return center_shift;
}
void
SWGVORLocalizerSettings::setCenterShift(qint32 center_shift) {
    this->center_shift = center_shift;
    this->m_center_shift_isSet = true;
}


bool
SWGVORLocalizerSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
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
        if(m_mag_dec_adjust_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rr_time_isSet){
            isObjectUpdated = true; break;
        }
        if(m_force_rr_averaging_isSet){
            isObjectUpdated = true; break;
        }
        if(m_center_shift_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

