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


#include "SWGLocationInformation.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGLocationInformation::SWGLocationInformation(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLocationInformation::SWGLocationInformation() {
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
}

SWGLocationInformation::~SWGLocationInformation() {
    this->cleanup();
}

void
SWGLocationInformation::init() {
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
}

void
SWGLocationInformation::cleanup() {


}

SWGLocationInformation*
SWGLocationInformation::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLocationInformation::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&latitude, pJson["latitude"], "float", "");
    
    ::SWGrpx-100::setValue(&longitude, pJson["longitude"], "float", "");
    
}

QString
SWGLocationInformation::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGLocationInformation::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_latitude_isSet){
        obj->insert("latitude", QJsonValue(latitude));
    }
    if(m_longitude_isSet){
        obj->insert("longitude", QJsonValue(longitude));
    }

    return obj;
}

float
SWGLocationInformation::getLatitude() {
    return latitude;
}
void
SWGLocationInformation::setLatitude(float latitude) {
    this->latitude = latitude;
    this->m_latitude_isSet = true;
}

float
SWGLocationInformation::getLongitude() {
    return longitude;
}
void
SWGLocationInformation::setLongitude(float longitude) {
    this->longitude = longitude;
    this->m_longitude_isSet = true;
}


bool
SWGLocationInformation::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_latitude_isSet){
            isObjectUpdated = true; break;
        }
        if(m_longitude_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

