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


#include "SWGIEEE_802_15_4_ModActions.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGIEEE_802_15_4_ModActions::SWGIEEE_802_15_4_ModActions(QString* json) {
    init();
    this->fromJson(*json);
}

SWGIEEE_802_15_4_ModActions::SWGIEEE_802_15_4_ModActions() {
    tx = nullptr;
    m_tx_isSet = false;
}

SWGIEEE_802_15_4_ModActions::~SWGIEEE_802_15_4_ModActions() {
    this->cleanup();
}

void
SWGIEEE_802_15_4_ModActions::init() {
    tx = new SWGIEEE_802_15_4_ModActions_tx();
    m_tx_isSet = false;
}

void
SWGIEEE_802_15_4_ModActions::cleanup() {
    if(tx != nullptr) { 
        delete tx;
    }
}

SWGIEEE_802_15_4_ModActions*
SWGIEEE_802_15_4_ModActions::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGIEEE_802_15_4_ModActions::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&tx, pJson["tx"], "SWGIEEE_802_15_4_ModActions_tx", "SWGIEEE_802_15_4_ModActions_tx");
    
}

QString
SWGIEEE_802_15_4_ModActions::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGIEEE_802_15_4_ModActions::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if((tx != nullptr) && (tx->isSet())){
        toJsonValue(QString("tx"), tx, obj, QString("SWGIEEE_802_15_4_ModActions_tx"));
    }

    return obj;
}

SWGIEEE_802_15_4_ModActions_tx*
SWGIEEE_802_15_4_ModActions::getTx() {
    return tx;
}
void
SWGIEEE_802_15_4_ModActions::setTx(SWGIEEE_802_15_4_ModActions_tx* tx) {
    this->tx = tx;
    this->m_tx_isSet = true;
}


bool
SWGIEEE_802_15_4_ModActions::isSet(){
    bool isObjectUpdated = false;
    do{
        if(tx && tx->isSet()){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

