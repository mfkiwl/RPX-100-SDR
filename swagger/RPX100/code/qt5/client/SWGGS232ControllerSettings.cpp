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


#include "SWGGS232ControllerSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGGS232ControllerSettings::SWGGS232ControllerSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGGS232ControllerSettings::SWGGS232ControllerSettings() {
    azimuth = 0.0f;
    m_azimuth_isSet = false;
    elevation = 0.0f;
    m_elevation_isSet = false;
    serial_port = nullptr;
    m_serial_port_isSet = false;
    baud_rate = 0;
    m_baud_rate_isSet = false;
    track = 0;
    m_track_isSet = false;
    target = nullptr;
    m_target_isSet = false;
    azimuth_offset = 0;
    m_azimuth_offset_isSet = false;
    elevation_offset = 0;
    m_elevation_offset_isSet = false;
    azimuth_min = 0;
    m_azimuth_min_isSet = false;
    azimuth_max = 0;
    m_azimuth_max_isSet = false;
    elevation_min = 0;
    m_elevation_min_isSet = false;
    elevation_max = 0;
    m_elevation_max_isSet = false;
    tolerance = 0;
    m_tolerance_isSet = false;
    protocol = 0;
    m_protocol_isSet = false;
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

SWGGS232ControllerSettings::~SWGGS232ControllerSettings() {
    this->cleanup();
}

void
SWGGS232ControllerSettings::init() {
    azimuth = 0.0f;
    m_azimuth_isSet = false;
    elevation = 0.0f;
    m_elevation_isSet = false;
    serial_port = new QString("");
    m_serial_port_isSet = false;
    baud_rate = 0;
    m_baud_rate_isSet = false;
    track = 0;
    m_track_isSet = false;
    target = new QString("");
    m_target_isSet = false;
    azimuth_offset = 0;
    m_azimuth_offset_isSet = false;
    elevation_offset = 0;
    m_elevation_offset_isSet = false;
    azimuth_min = 0;
    m_azimuth_min_isSet = false;
    azimuth_max = 0;
    m_azimuth_max_isSet = false;
    elevation_min = 0;
    m_elevation_min_isSet = false;
    elevation_max = 0;
    m_elevation_max_isSet = false;
    tolerance = 0;
    m_tolerance_isSet = false;
    protocol = 0;
    m_protocol_isSet = false;
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
SWGGS232ControllerSettings::cleanup() {


    if(serial_port != nullptr) { 
        delete serial_port;
    }


    if(target != nullptr) { 
        delete target;
    }








    if(title != nullptr) { 
        delete title;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGGS232ControllerSettings*
SWGGS232ControllerSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGGS232ControllerSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&azimuth, pJson["azimuth"], "float", "");
    
    ::SWGRPX100::setValue(&elevation, pJson["elevation"], "float", "");
    
    ::SWGRPX100::setValue(&serial_port, pJson["serialPort"], "QString", "QString");
    
    ::SWGRPX100::setValue(&baud_rate, pJson["baudRate"], "qint32", "");
    
    ::SWGRPX100::setValue(&track, pJson["track"], "qint32", "");
    
    ::SWGRPX100::setValue(&target, pJson["target"], "QString", "QString");
    
    ::SWGRPX100::setValue(&azimuth_offset, pJson["azimuthOffset"], "qint32", "");
    
    ::SWGRPX100::setValue(&elevation_offset, pJson["elevationOffset"], "qint32", "");
    
    ::SWGRPX100::setValue(&azimuth_min, pJson["azimuthMin"], "qint32", "");
    
    ::SWGRPX100::setValue(&azimuth_max, pJson["azimuthMax"], "qint32", "");
    
    ::SWGRPX100::setValue(&elevation_min, pJson["elevationMin"], "qint32", "");
    
    ::SWGRPX100::setValue(&elevation_max, pJson["elevationMax"], "qint32", "");
    
    ::SWGRPX100::setValue(&tolerance, pJson["tolerance"], "qint32", "");
    
    ::SWGRPX100::setValue(&protocol, pJson["protocol"], "qint32", "");
    
    ::SWGRPX100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGRPX100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGRPX100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_feature_set_index, pJson["reverseAPIFeatureSetIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_feature_index, pJson["reverseAPIFeatureIndex"], "qint32", "");
    
}

QString
SWGGS232ControllerSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGGS232ControllerSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_azimuth_isSet){
        obj->insert("azimuth", QJsonValue(azimuth));
    }
    if(m_elevation_isSet){
        obj->insert("elevation", QJsonValue(elevation));
    }
    if(serial_port != nullptr && *serial_port != QString("")){
        toJsonValue(QString("serialPort"), serial_port, obj, QString("QString"));
    }
    if(m_baud_rate_isSet){
        obj->insert("baudRate", QJsonValue(baud_rate));
    }
    if(m_track_isSet){
        obj->insert("track", QJsonValue(track));
    }
    if(target != nullptr && *target != QString("")){
        toJsonValue(QString("target"), target, obj, QString("QString"));
    }
    if(m_azimuth_offset_isSet){
        obj->insert("azimuthOffset", QJsonValue(azimuth_offset));
    }
    if(m_elevation_offset_isSet){
        obj->insert("elevationOffset", QJsonValue(elevation_offset));
    }
    if(m_azimuth_min_isSet){
        obj->insert("azimuthMin", QJsonValue(azimuth_min));
    }
    if(m_azimuth_max_isSet){
        obj->insert("azimuthMax", QJsonValue(azimuth_max));
    }
    if(m_elevation_min_isSet){
        obj->insert("elevationMin", QJsonValue(elevation_min));
    }
    if(m_elevation_max_isSet){
        obj->insert("elevationMax", QJsonValue(elevation_max));
    }
    if(m_tolerance_isSet){
        obj->insert("tolerance", QJsonValue(tolerance));
    }
    if(m_protocol_isSet){
        obj->insert("protocol", QJsonValue(protocol));
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

float
SWGGS232ControllerSettings::getAzimuth() {
    return azimuth;
}
void
SWGGS232ControllerSettings::setAzimuth(float azimuth) {
    this->azimuth = azimuth;
    this->m_azimuth_isSet = true;
}

float
SWGGS232ControllerSettings::getElevation() {
    return elevation;
}
void
SWGGS232ControllerSettings::setElevation(float elevation) {
    this->elevation = elevation;
    this->m_elevation_isSet = true;
}

QString*
SWGGS232ControllerSettings::getSerialPort() {
    return serial_port;
}
void
SWGGS232ControllerSettings::setSerialPort(QString* serial_port) {
    this->serial_port = serial_port;
    this->m_serial_port_isSet = true;
}

qint32
SWGGS232ControllerSettings::getBaudRate() {
    return baud_rate;
}
void
SWGGS232ControllerSettings::setBaudRate(qint32 baud_rate) {
    this->baud_rate = baud_rate;
    this->m_baud_rate_isSet = true;
}

qint32
SWGGS232ControllerSettings::getTrack() {
    return track;
}
void
SWGGS232ControllerSettings::setTrack(qint32 track) {
    this->track = track;
    this->m_track_isSet = true;
}

QString*
SWGGS232ControllerSettings::getTarget() {
    return target;
}
void
SWGGS232ControllerSettings::setTarget(QString* target) {
    this->target = target;
    this->m_target_isSet = true;
}

qint32
SWGGS232ControllerSettings::getAzimuthOffset() {
    return azimuth_offset;
}
void
SWGGS232ControllerSettings::setAzimuthOffset(qint32 azimuth_offset) {
    this->azimuth_offset = azimuth_offset;
    this->m_azimuth_offset_isSet = true;
}

qint32
SWGGS232ControllerSettings::getElevationOffset() {
    return elevation_offset;
}
void
SWGGS232ControllerSettings::setElevationOffset(qint32 elevation_offset) {
    this->elevation_offset = elevation_offset;
    this->m_elevation_offset_isSet = true;
}

qint32
SWGGS232ControllerSettings::getAzimuthMin() {
    return azimuth_min;
}
void
SWGGS232ControllerSettings::setAzimuthMin(qint32 azimuth_min) {
    this->azimuth_min = azimuth_min;
    this->m_azimuth_min_isSet = true;
}

qint32
SWGGS232ControllerSettings::getAzimuthMax() {
    return azimuth_max;
}
void
SWGGS232ControllerSettings::setAzimuthMax(qint32 azimuth_max) {
    this->azimuth_max = azimuth_max;
    this->m_azimuth_max_isSet = true;
}

qint32
SWGGS232ControllerSettings::getElevationMin() {
    return elevation_min;
}
void
SWGGS232ControllerSettings::setElevationMin(qint32 elevation_min) {
    this->elevation_min = elevation_min;
    this->m_elevation_min_isSet = true;
}

qint32
SWGGS232ControllerSettings::getElevationMax() {
    return elevation_max;
}
void
SWGGS232ControllerSettings::setElevationMax(qint32 elevation_max) {
    this->elevation_max = elevation_max;
    this->m_elevation_max_isSet = true;
}

qint32
SWGGS232ControllerSettings::getTolerance() {
    return tolerance;
}
void
SWGGS232ControllerSettings::setTolerance(qint32 tolerance) {
    this->tolerance = tolerance;
    this->m_tolerance_isSet = true;
}

qint32
SWGGS232ControllerSettings::getProtocol() {
    return protocol;
}
void
SWGGS232ControllerSettings::setProtocol(qint32 protocol) {
    this->protocol = protocol;
    this->m_protocol_isSet = true;
}

QString*
SWGGS232ControllerSettings::getTitle() {
    return title;
}
void
SWGGS232ControllerSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGGS232ControllerSettings::getRgbColor() {
    return rgb_color;
}
void
SWGGS232ControllerSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

qint32
SWGGS232ControllerSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGGS232ControllerSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGGS232ControllerSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGGS232ControllerSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGGS232ControllerSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGGS232ControllerSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGGS232ControllerSettings::getReverseApiFeatureSetIndex() {
    return reverse_api_feature_set_index;
}
void
SWGGS232ControllerSettings::setReverseApiFeatureSetIndex(qint32 reverse_api_feature_set_index) {
    this->reverse_api_feature_set_index = reverse_api_feature_set_index;
    this->m_reverse_api_feature_set_index_isSet = true;
}

qint32
SWGGS232ControllerSettings::getReverseApiFeatureIndex() {
    return reverse_api_feature_index;
}
void
SWGGS232ControllerSettings::setReverseApiFeatureIndex(qint32 reverse_api_feature_index) {
    this->reverse_api_feature_index = reverse_api_feature_index;
    this->m_reverse_api_feature_index_isSet = true;
}


bool
SWGGS232ControllerSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_azimuth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_elevation_isSet){
            isObjectUpdated = true; break;
        }
        if(serial_port && *serial_port != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_baud_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_track_isSet){
            isObjectUpdated = true; break;
        }
        if(target && *target != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_azimuth_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_elevation_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_azimuth_min_isSet){
            isObjectUpdated = true; break;
        }
        if(m_azimuth_max_isSet){
            isObjectUpdated = true; break;
        }
        if(m_elevation_min_isSet){
            isObjectUpdated = true; break;
        }
        if(m_elevation_max_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tolerance_isSet){
            isObjectUpdated = true; break;
        }
        if(m_protocol_isSet){
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

