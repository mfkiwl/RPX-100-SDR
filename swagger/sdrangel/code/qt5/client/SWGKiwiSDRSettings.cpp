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


#include "SWGKiwiSDRSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGKiwiSDRSettings::SWGKiwiSDRSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGKiwiSDRSettings::SWGKiwiSDRSettings() {
    gain = 0;
    m_gain_isSet = false;
    use_agc = 0;
    m_use_agc_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    server_address = nullptr;
    m_server_address_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGKiwiSDRSettings::~SWGKiwiSDRSettings() {
    this->cleanup();
}

void
SWGKiwiSDRSettings::init() {
    gain = 0;
    m_gain_isSet = false;
    use_agc = 0;
    m_use_agc_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    server_address = new QString("");
    m_server_address_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGKiwiSDRSettings::cleanup() {




    if(server_address != nullptr) { 
        delete server_address;
    }

    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGKiwiSDRSettings*
SWGKiwiSDRSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGKiwiSDRSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&gain, pJson["gain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_agc, pJson["useAGC"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&server_address, pJson["serverAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGKiwiSDRSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGKiwiSDRSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_gain_isSet){
        obj->insert("gain", QJsonValue(gain));
    }
    if(m_use_agc_isSet){
        obj->insert("useAGC", QJsonValue(use_agc));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(server_address != nullptr && *server_address != QString("")){
        toJsonValue(QString("serverAddress"), server_address, obj, QString("QString"));
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
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }

    return obj;
}

qint32
SWGKiwiSDRSettings::getGain() {
    return gain;
}
void
SWGKiwiSDRSettings::setGain(qint32 gain) {
    this->gain = gain;
    this->m_gain_isSet = true;
}

qint32
SWGKiwiSDRSettings::getUseAgc() {
    return use_agc;
}
void
SWGKiwiSDRSettings::setUseAgc(qint32 use_agc) {
    this->use_agc = use_agc;
    this->m_use_agc_isSet = true;
}

qint32
SWGKiwiSDRSettings::getDcBlock() {
    return dc_block;
}
void
SWGKiwiSDRSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint64
SWGKiwiSDRSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGKiwiSDRSettings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

QString*
SWGKiwiSDRSettings::getServerAddress() {
    return server_address;
}
void
SWGKiwiSDRSettings::setServerAddress(QString* server_address) {
    this->server_address = server_address;
    this->m_server_address_isSet = true;
}

qint32
SWGKiwiSDRSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGKiwiSDRSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGKiwiSDRSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGKiwiSDRSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGKiwiSDRSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGKiwiSDRSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGKiwiSDRSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGKiwiSDRSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGKiwiSDRSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_agc_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(server_address && *server_address != QString("")){
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
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}
