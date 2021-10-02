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


#include "SWGRemoteInputSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGRemoteInputSettings::SWGRemoteInputSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRemoteInputSettings::SWGRemoteInputSettings() {
    api_address = nullptr;
    m_api_address_isSet = false;
    api_port = 0;
    m_api_port_isSet = false;
    data_address = nullptr;
    m_data_address_isSet = false;
    data_port = 0;
    m_data_port_isSet = false;
    multicast_address = nullptr;
    m_multicast_address_isSet = false;
    multicast_join = 0;
    m_multicast_join_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGRemoteInputSettings::~SWGRemoteInputSettings() {
    this->cleanup();
}

void
SWGRemoteInputSettings::init() {
    api_address = new QString("");
    m_api_address_isSet = false;
    api_port = 0;
    m_api_port_isSet = false;
    data_address = new QString("");
    m_data_address_isSet = false;
    data_port = 0;
    m_data_port_isSet = false;
    multicast_address = new QString("");
    m_multicast_address_isSet = false;
    multicast_join = 0;
    m_multicast_join_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
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
SWGRemoteInputSettings::cleanup() {
    if(api_address != nullptr) { 
        delete api_address;
    }

    if(data_address != nullptr) { 
        delete data_address;
    }

    if(multicast_address != nullptr) { 
        delete multicast_address;
    }




    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGRemoteInputSettings*
SWGRemoteInputSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRemoteInputSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&api_address, pJson["apiAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&api_port, pJson["apiPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&data_address, pJson["dataAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&data_port, pJson["dataPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&multicast_address, pJson["multicastAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&multicast_join, pJson["multicastJoin"], "qint32", "");
    
    ::SWGrpx-100::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGrpx-100::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGrpx-100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGRemoteInputSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGRemoteInputSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(api_address != nullptr && *api_address != QString("")){
        toJsonValue(QString("apiAddress"), api_address, obj, QString("QString"));
    }
    if(m_api_port_isSet){
        obj->insert("apiPort", QJsonValue(api_port));
    }
    if(data_address != nullptr && *data_address != QString("")){
        toJsonValue(QString("dataAddress"), data_address, obj, QString("QString"));
    }
    if(m_data_port_isSet){
        obj->insert("dataPort", QJsonValue(data_port));
    }
    if(multicast_address != nullptr && *multicast_address != QString("")){
        toJsonValue(QString("multicastAddress"), multicast_address, obj, QString("QString"));
    }
    if(m_multicast_join_isSet){
        obj->insert("multicastJoin", QJsonValue(multicast_join));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
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

QString*
SWGRemoteInputSettings::getApiAddress() {
    return api_address;
}
void
SWGRemoteInputSettings::setApiAddress(QString* api_address) {
    this->api_address = api_address;
    this->m_api_address_isSet = true;
}

qint32
SWGRemoteInputSettings::getApiPort() {
    return api_port;
}
void
SWGRemoteInputSettings::setApiPort(qint32 api_port) {
    this->api_port = api_port;
    this->m_api_port_isSet = true;
}

QString*
SWGRemoteInputSettings::getDataAddress() {
    return data_address;
}
void
SWGRemoteInputSettings::setDataAddress(QString* data_address) {
    this->data_address = data_address;
    this->m_data_address_isSet = true;
}

qint32
SWGRemoteInputSettings::getDataPort() {
    return data_port;
}
void
SWGRemoteInputSettings::setDataPort(qint32 data_port) {
    this->data_port = data_port;
    this->m_data_port_isSet = true;
}

QString*
SWGRemoteInputSettings::getMulticastAddress() {
    return multicast_address;
}
void
SWGRemoteInputSettings::setMulticastAddress(QString* multicast_address) {
    this->multicast_address = multicast_address;
    this->m_multicast_address_isSet = true;
}

qint32
SWGRemoteInputSettings::getMulticastJoin() {
    return multicast_join;
}
void
SWGRemoteInputSettings::setMulticastJoin(qint32 multicast_join) {
    this->multicast_join = multicast_join;
    this->m_multicast_join_isSet = true;
}

qint32
SWGRemoteInputSettings::getDcBlock() {
    return dc_block;
}
void
SWGRemoteInputSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGRemoteInputSettings::getIqCorrection() {
    return iq_correction;
}
void
SWGRemoteInputSettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGRemoteInputSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGRemoteInputSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGRemoteInputSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGRemoteInputSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGRemoteInputSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGRemoteInputSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGRemoteInputSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGRemoteInputSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGRemoteInputSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(api_address && *api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(data_address && *data_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_data_port_isSet){
            isObjectUpdated = true; break;
        }
        if(multicast_address && *multicast_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_multicast_join_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_correction_isSet){
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
