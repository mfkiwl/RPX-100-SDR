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


#include "SWGChannelConfig.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGChannelConfig::SWGChannelConfig(QString* json) {
    init();
    this->fromJson(*json);
}

SWGChannelConfig::SWGChannelConfig() {
    channel_id_uri = nullptr;
    m_channel_id_uri_isSet = false;
    config = nullptr;
    m_config_isSet = false;
}

SWGChannelConfig::~SWGChannelConfig() {
    this->cleanup();
}

void
SWGChannelConfig::init() {
    channel_id_uri = new QString("");
    m_channel_id_uri_isSet = false;
    config = new SWGChannelSettings();
    m_config_isSet = false;
}

void
SWGChannelConfig::cleanup() {
    if(channel_id_uri != nullptr) { 
        delete channel_id_uri;
    }
    if(config != nullptr) { 
        delete config;
    }
}

SWGChannelConfig*
SWGChannelConfig::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGChannelConfig::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&channel_id_uri, pJson["channelIdURI"], "QString", "QString");
    
    ::SWGRPX100::setValue(&config, pJson["config"], "SWGChannelSettings", "SWGChannelSettings");
    
}

QString
SWGChannelConfig::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGChannelConfig::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(channel_id_uri != nullptr && *channel_id_uri != QString("")){
        toJsonValue(QString("channelIdURI"), channel_id_uri, obj, QString("QString"));
    }
    if((config != nullptr) && (config->isSet())){
        toJsonValue(QString("config"), config, obj, QString("SWGChannelSettings"));
    }

    return obj;
}

QString*
SWGChannelConfig::getChannelIdUri() {
    return channel_id_uri;
}
void
SWGChannelConfig::setChannelIdUri(QString* channel_id_uri) {
    this->channel_id_uri = channel_id_uri;
    this->m_channel_id_uri_isSet = true;
}

SWGChannelSettings*
SWGChannelConfig::getConfig() {
    return config;
}
void
SWGChannelConfig::setConfig(SWGChannelSettings* config) {
    this->config = config;
    this->m_config_isSet = true;
}


bool
SWGChannelConfig::isSet(){
    bool isObjectUpdated = false;
    do{
        if(channel_id_uri && *channel_id_uri != QString("")){
            isObjectUpdated = true; break;
        }
        if(config && config->isSet()){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

