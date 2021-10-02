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


#include "SWGMapActions_find.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGMapActions_find::SWGMapActions_find(QString* json) {
    init();
    this->fromJson(*json);
}

SWGMapActions_find::SWGMapActions_find() {
    id = nullptr;
    m_id_isSet = false;
}

SWGMapActions_find::~SWGMapActions_find() {
    this->cleanup();
}

void
SWGMapActions_find::init() {
    id = new QString("");
    m_id_isSet = false;
}

void
SWGMapActions_find::cleanup() {
    if(id != nullptr) { 
        delete id;
    }
}

SWGMapActions_find*
SWGMapActions_find::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGMapActions_find::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&id, pJson["id"], "QString", "QString");
    
}

QString
SWGMapActions_find::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGMapActions_find::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(id != nullptr && *id != QString("")){
        toJsonValue(QString("id"), id, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGMapActions_find::getId() {
    return id;
}
void
SWGMapActions_find::setId(QString* id) {
    this->id = id;
    this->m_id_isSet = true;
}


bool
SWGMapActions_find::isSet(){
    bool isObjectUpdated = false;
    do{
        if(id && *id != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}
