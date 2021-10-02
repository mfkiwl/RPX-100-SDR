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


#include "SWGFeatureActions.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGFeatureActions::SWGFeatureActions(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFeatureActions::SWGFeatureActions() {
    feature_type = nullptr;
    m_feature_type_isSet = false;
    originator_feature_set_index = 0;
    m_originator_feature_set_index_isSet = false;
    originator_feature_index = 0;
    m_originator_feature_index_isSet = false;
    afc_actions = nullptr;
    m_afc_actions_isSet = false;
    map_actions = nullptr;
    m_map_actions_isSet = false;
    per_tester_actions = nullptr;
    m_per_tester_actions_isSet = false;
    simple_ptt_actions = nullptr;
    m_simple_ptt_actions_isSet = false;
}

SWGFeatureActions::~SWGFeatureActions() {
    this->cleanup();
}

void
SWGFeatureActions::init() {
    feature_type = new QString("");
    m_feature_type_isSet = false;
    originator_feature_set_index = 0;
    m_originator_feature_set_index_isSet = false;
    originator_feature_index = 0;
    m_originator_feature_index_isSet = false;
    afc_actions = new SWGAFCActions();
    m_afc_actions_isSet = false;
    map_actions = new SWGMapActions();
    m_map_actions_isSet = false;
    per_tester_actions = new SWGPERTesterActions();
    m_per_tester_actions_isSet = false;
    simple_ptt_actions = new SWGSimplePTTActions();
    m_simple_ptt_actions_isSet = false;
}

void
SWGFeatureActions::cleanup() {
    if(feature_type != nullptr) { 
        delete feature_type;
    }


    if(afc_actions != nullptr) { 
        delete afc_actions;
    }
    if(map_actions != nullptr) { 
        delete map_actions;
    }
    if(per_tester_actions != nullptr) { 
        delete per_tester_actions;
    }
    if(simple_ptt_actions != nullptr) { 
        delete simple_ptt_actions;
    }
}

SWGFeatureActions*
SWGFeatureActions::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFeatureActions::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&feature_type, pJson["featureType"], "QString", "QString");
    
    ::SWGRPX100::setValue(&originator_feature_set_index, pJson["originatorFeatureSetIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&originator_feature_index, pJson["originatorFeatureIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&afc_actions, pJson["AFCActions"], "SWGAFCActions", "SWGAFCActions");
    
    ::SWGRPX100::setValue(&map_actions, pJson["MapActions"], "SWGMapActions", "SWGMapActions");
    
    ::SWGRPX100::setValue(&per_tester_actions, pJson["PERTesterActions"], "SWGPERTesterActions", "SWGPERTesterActions");
    
    ::SWGRPX100::setValue(&simple_ptt_actions, pJson["SimplePTTActions"], "SWGSimplePTTActions", "SWGSimplePTTActions");
    
}

QString
SWGFeatureActions::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFeatureActions::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(feature_type != nullptr && *feature_type != QString("")){
        toJsonValue(QString("featureType"), feature_type, obj, QString("QString"));
    }
    if(m_originator_feature_set_index_isSet){
        obj->insert("originatorFeatureSetIndex", QJsonValue(originator_feature_set_index));
    }
    if(m_originator_feature_index_isSet){
        obj->insert("originatorFeatureIndex", QJsonValue(originator_feature_index));
    }
    if((afc_actions != nullptr) && (afc_actions->isSet())){
        toJsonValue(QString("AFCActions"), afc_actions, obj, QString("SWGAFCActions"));
    }
    if((map_actions != nullptr) && (map_actions->isSet())){
        toJsonValue(QString("MapActions"), map_actions, obj, QString("SWGMapActions"));
    }
    if((per_tester_actions != nullptr) && (per_tester_actions->isSet())){
        toJsonValue(QString("PERTesterActions"), per_tester_actions, obj, QString("SWGPERTesterActions"));
    }
    if((simple_ptt_actions != nullptr) && (simple_ptt_actions->isSet())){
        toJsonValue(QString("SimplePTTActions"), simple_ptt_actions, obj, QString("SWGSimplePTTActions"));
    }

    return obj;
}

QString*
SWGFeatureActions::getFeatureType() {
    return feature_type;
}
void
SWGFeatureActions::setFeatureType(QString* feature_type) {
    this->feature_type = feature_type;
    this->m_feature_type_isSet = true;
}

qint32
SWGFeatureActions::getOriginatorFeatureSetIndex() {
    return originator_feature_set_index;
}
void
SWGFeatureActions::setOriginatorFeatureSetIndex(qint32 originator_feature_set_index) {
    this->originator_feature_set_index = originator_feature_set_index;
    this->m_originator_feature_set_index_isSet = true;
}

qint32
SWGFeatureActions::getOriginatorFeatureIndex() {
    return originator_feature_index;
}
void
SWGFeatureActions::setOriginatorFeatureIndex(qint32 originator_feature_index) {
    this->originator_feature_index = originator_feature_index;
    this->m_originator_feature_index_isSet = true;
}

SWGAFCActions*
SWGFeatureActions::getAfcActions() {
    return afc_actions;
}
void
SWGFeatureActions::setAfcActions(SWGAFCActions* afc_actions) {
    this->afc_actions = afc_actions;
    this->m_afc_actions_isSet = true;
}

SWGMapActions*
SWGFeatureActions::getMapActions() {
    return map_actions;
}
void
SWGFeatureActions::setMapActions(SWGMapActions* map_actions) {
    this->map_actions = map_actions;
    this->m_map_actions_isSet = true;
}

SWGPERTesterActions*
SWGFeatureActions::getPerTesterActions() {
    return per_tester_actions;
}
void
SWGFeatureActions::setPerTesterActions(SWGPERTesterActions* per_tester_actions) {
    this->per_tester_actions = per_tester_actions;
    this->m_per_tester_actions_isSet = true;
}

SWGSimplePTTActions*
SWGFeatureActions::getSimplePttActions() {
    return simple_ptt_actions;
}
void
SWGFeatureActions::setSimplePttActions(SWGSimplePTTActions* simple_ptt_actions) {
    this->simple_ptt_actions = simple_ptt_actions;
    this->m_simple_ptt_actions_isSet = true;
}


bool
SWGFeatureActions::isSet(){
    bool isObjectUpdated = false;
    do{
        if(feature_type && *feature_type != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_originator_feature_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_originator_feature_index_isSet){
            isObjectUpdated = true; break;
        }
        if(afc_actions && afc_actions->isSet()){
            isObjectUpdated = true; break;
        }
        if(map_actions && map_actions->isSet()){
            isObjectUpdated = true; break;
        }
        if(per_tester_actions && per_tester_actions->isSet()){
            isObjectUpdated = true; break;
        }
        if(simple_ptt_actions && simple_ptt_actions->isSet()){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

