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


#include "SWGMapCoordinate.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGMapCoordinate::SWGMapCoordinate(QString* json) {
    init();
    this->fromJson(*json);
}

SWGMapCoordinate::SWGMapCoordinate() {
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    altitude = 0.0f;
    m_altitude_isSet = false;
}

SWGMapCoordinate::~SWGMapCoordinate() {
    this->cleanup();
}

void
SWGMapCoordinate::init() {
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    altitude = 0.0f;
    m_altitude_isSet = false;
}

void
SWGMapCoordinate::cleanup() {



}

SWGMapCoordinate*
SWGMapCoordinate::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGMapCoordinate::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&latitude, pJson["latitude"], "float", "");
    
    ::SWGRPX100::setValue(&longitude, pJson["longitude"], "float", "");
    
    ::SWGRPX100::setValue(&altitude, pJson["altitude"], "float", "");
    
}

QString
SWGMapCoordinate::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGMapCoordinate::asJsonObject() {
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
SWGMapCoordinate::getLatitude() {
    return latitude;
}
void
SWGMapCoordinate::setLatitude(float latitude) {
    this->latitude = latitude;
    this->m_latitude_isSet = true;
}

float
SWGMapCoordinate::getLongitude() {
    return longitude;
}
void
SWGMapCoordinate::setLongitude(float longitude) {
    this->longitude = longitude;
    this->m_longitude_isSet = true;
}

float
SWGMapCoordinate::getAltitude() {
    return altitude;
}
void
SWGMapCoordinate::setAltitude(float altitude) {
    this->altitude = altitude;
    this->m_altitude_isSet = true;
}


bool
SWGMapCoordinate::isSet(){
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

