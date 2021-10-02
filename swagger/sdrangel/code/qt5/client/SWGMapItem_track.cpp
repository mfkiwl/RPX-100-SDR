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


#include "SWGMapItem_track.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGMapItem_track::SWGMapItem_track(QString* json) {
    init();
    this->fromJson(*json);
}

SWGMapItem_track::SWGMapItem_track() {
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    altitude = 0.0f;
    m_altitude_isSet = false;
}

SWGMapItem_track::~SWGMapItem_track() {
    this->cleanup();
}

void
SWGMapItem_track::init() {
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    altitude = 0.0f;
    m_altitude_isSet = false;
}

void
SWGMapItem_track::cleanup() {



}

SWGMapItem_track*
SWGMapItem_track::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGMapItem_track::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&latitude, pJson["latitude"], "float", "");
    
    ::SWGrpx-100::setValue(&longitude, pJson["longitude"], "float", "");
    
    ::SWGrpx-100::setValue(&altitude, pJson["altitude"], "float", "");
    
}

QString
SWGMapItem_track::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGMapItem_track::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_latitude_isSet){
        obj->insert("latitude", QJsonValue(latitude));
    }
    if(m_longitude_isSet){
        obj->insert("longitude", QJsonValue(longitude));
    }
    if(m_altitude_isSet){
        obj->insert("altitude", QJsonValue(altitude));
    }

    return obj;
}

float
SWGMapItem_track::getLatitude() {
    return latitude;
}
void
SWGMapItem_track::setLatitude(float latitude) {
    this->latitude = latitude;
    this->m_latitude_isSet = true;
}

float
SWGMapItem_track::getLongitude() {
    return longitude;
}
void
SWGMapItem_track::setLongitude(float longitude) {
    this->longitude = longitude;
    this->m_longitude_isSet = true;
}

float
SWGMapItem_track::getAltitude() {
    return altitude;
}
void
SWGMapItem_track::setAltitude(float altitude) {
    this->altitude = altitude;
    this->m_altitude_isSet = true;
}


bool
SWGMapItem_track::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_latitude_isSet){
            isObjectUpdated = true; break;
        }
        if(m_longitude_isSet){
            isObjectUpdated = true; break;
        }
        if(m_altitude_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

