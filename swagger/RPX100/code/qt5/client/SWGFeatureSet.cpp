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


#include "SWGFeatureSet.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGFeatureSet::SWGFeatureSet(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFeatureSet::SWGFeatureSet() {
    index = 0;
    m_index_isSet = false;
    featurecount = 0;
    m_featurecount_isSet = false;
    features = nullptr;
    m_features_isSet = false;
}

SWGFeatureSet::~SWGFeatureSet() {
    this->cleanup();
}

void
SWGFeatureSet::init() {
    index = 0;
    m_index_isSet = false;
    featurecount = 0;
    m_featurecount_isSet = false;
    features = new QList<SWGFeature*>();
    m_features_isSet = false;
}

void
SWGFeatureSet::cleanup() {


    if(features != nullptr) { 
        auto arr = features;
        for(auto o: *arr) { 
            delete o;
        }
        delete features;
    }
}

SWGFeatureSet*
SWGFeatureSet::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFeatureSet::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&index, pJson["index"], "qint32", "");
    
    ::SWGRPX100::setValue(&featurecount, pJson["featurecount"], "qint32", "");
    
    
    ::SWGRPX100::setValue(&features, pJson["features"], "QList", "SWGFeature");
}

QString
SWGFeatureSet::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFeatureSet::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_index_isSet){
        obj->insert("index", QJsonValue(index));
    }
    if(m_featurecount_isSet){
        obj->insert("featurecount", QJsonValue(featurecount));
    }
    if(features && features->size() > 0){
        toJsonArray((QList<void*>*)features, obj, "features", "SWGFeature");
    }

    return obj;
}

qint32
SWGFeatureSet::getIndex() {
    return index;
}
void
SWGFeatureSet::setIndex(qint32 index) {
    this->index = index;
    this->m_index_isSet = true;
}

qint32
SWGFeatureSet::getFeaturecount() {
    return featurecount;
}
void
SWGFeatureSet::setFeaturecount(qint32 featurecount) {
    this->featurecount = featurecount;
    this->m_featurecount_isSet = true;
}

QList<SWGFeature*>*
SWGFeatureSet::getFeatures() {
    return features;
}
void
SWGFeatureSet::setFeatures(QList<SWGFeature*>* features) {
    this->features = features;
    this->m_features_isSet = true;
}


bool
SWGFeatureSet::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_featurecount_isSet){
            isObjectUpdated = true; break;
        }
        if(features && (features->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

