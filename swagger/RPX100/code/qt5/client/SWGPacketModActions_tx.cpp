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


#include "SWGPacketModActions_tx.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGPacketModActions_tx::SWGPacketModActions_tx(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPacketModActions_tx::SWGPacketModActions_tx() {
    callsign = nullptr;
    m_callsign_isSet = false;
    to = nullptr;
    m_to_isSet = false;
    via = nullptr;
    m_via_isSet = false;
    data = nullptr;
    m_data_isSet = false;
}

SWGPacketModActions_tx::~SWGPacketModActions_tx() {
    this->cleanup();
}

void
SWGPacketModActions_tx::init() {
    callsign = new QString("");
    m_callsign_isSet = false;
    to = new QString("");
    m_to_isSet = false;
    via = new QString("");
    m_via_isSet = false;
    data = new QString("");
    m_data_isSet = false;
}

void
SWGPacketModActions_tx::cleanup() {
    if(callsign != nullptr) { 
        delete callsign;
    }
    if(to != nullptr) { 
        delete to;
    }
    if(via != nullptr) { 
        delete via;
    }
    if(data != nullptr) { 
        delete data;
    }
}

SWGPacketModActions_tx*
SWGPacketModActions_tx::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPacketModActions_tx::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&callsign, pJson["callsign"], "QString", "QString");
    
    ::SWGRPX100::setValue(&to, pJson["to"], "QString", "QString");
    
    ::SWGRPX100::setValue(&via, pJson["via"], "QString", "QString");
    
    ::SWGRPX100::setValue(&data, pJson["data"], "QString", "QString");
    
}

QString
SWGPacketModActions_tx::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPacketModActions_tx::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(callsign != nullptr && *callsign != QString("")){
        toJsonValue(QString("callsign"), callsign, obj, QString("QString"));
    }
    if(to != nullptr && *to != QString("")){
        toJsonValue(QString("to"), to, obj, QString("QString"));
    }
    if(via != nullptr && *via != QString("")){
        toJsonValue(QString("via"), via, obj, QString("QString"));
    }
    if(data != nullptr && *data != QString("")){
        toJsonValue(QString("data"), data, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGPacketModActions_tx::getCallsign() {
    return callsign;
}
void
SWGPacketModActions_tx::setCallsign(QString* callsign) {
    this->callsign = callsign;
    this->m_callsign_isSet = true;
}

QString*
SWGPacketModActions_tx::getTo() {
    return to;
}
void
SWGPacketModActions_tx::setTo(QString* to) {
    this->to = to;
    this->m_to_isSet = true;
}

QString*
SWGPacketModActions_tx::getVia() {
    return via;
}
void
SWGPacketModActions_tx::setVia(QString* via) {
    this->via = via;
    this->m_via_isSet = true;
}

QString*
SWGPacketModActions_tx::getData() {
    return data;
}
void
SWGPacketModActions_tx::setData(QString* data) {
    this->data = data;
    this->m_data_isSet = true;
}


bool
SWGPacketModActions_tx::isSet(){
    bool isObjectUpdated = false;
    do{
        if(callsign && *callsign != QString("")){
            isObjectUpdated = true; break;
        }
        if(to && *to != QString("")){
            isObjectUpdated = true; break;
        }
        if(via && *via != QString("")){
            isObjectUpdated = true; break;
        }
        if(data && *data != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

