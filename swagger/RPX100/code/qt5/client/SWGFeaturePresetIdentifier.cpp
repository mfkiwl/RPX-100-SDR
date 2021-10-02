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


#include "SWGFeaturePresetIdentifier.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGFeaturePresetIdentifier::SWGFeaturePresetIdentifier(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFeaturePresetIdentifier::SWGFeaturePresetIdentifier() {
    group_name = nullptr;
    m_group_name_isSet = false;
    description = nullptr;
    m_description_isSet = false;
}

SWGFeaturePresetIdentifier::~SWGFeaturePresetIdentifier() {
    this->cleanup();
}

void
SWGFeaturePresetIdentifier::init() {
    group_name = new QString("");
    m_group_name_isSet = false;
    description = new QString("");
    m_description_isSet = false;
}

void
SWGFeaturePresetIdentifier::cleanup() {
    if(group_name != nullptr) { 
        delete group_name;
    }
    if(description != nullptr) { 
        delete description;
    }
}

SWGFeaturePresetIdentifier*
SWGFeaturePresetIdentifier::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFeaturePresetIdentifier::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&group_name, pJson["groupName"], "QString", "QString");
    
    ::SWGRPX100::setValue(&description, pJson["description"], "QString", "QString");
    
}

QString
SWGFeaturePresetIdentifier::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFeaturePresetIdentifier::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(group_name != nullptr && *group_name != QString("")){
        toJsonValue(QString("groupName"), group_name, obj, QString("QString"));
    }
    if(description != nullptr && *description != QString("")){
        toJsonValue(QString("description"), description, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGFeaturePresetIdentifier::getGroupName() {
    return group_name;
}
void
SWGFeaturePresetIdentifier::setGroupName(QString* group_name) {
    this->group_name = group_name;
    this->m_group_name_isSet = true;
}

QString*
SWGFeaturePresetIdentifier::getDescription() {
    return description;
}
void
SWGFeaturePresetIdentifier::setDescription(QString* description) {
    this->description = description;
    this->m_description_isSet = true;
}


bool
SWGFeaturePresetIdentifier::isSet(){
    bool isObjectUpdated = false;
    do{
        if(group_name && *group_name != QString("")){
            isObjectUpdated = true; break;
        }
        if(description && *description != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}
