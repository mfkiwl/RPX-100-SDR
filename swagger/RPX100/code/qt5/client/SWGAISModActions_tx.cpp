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


#include "SWGAISModActions_tx.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGAISModActions_tx::SWGAISModActions_tx(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAISModActions_tx::SWGAISModActions_tx() {
    data = nullptr;
    m_data_isSet = false;
}

SWGAISModActions_tx::~SWGAISModActions_tx() {
    this->cleanup();
}

void
SWGAISModActions_tx::init() {
    data = new QString("");
    m_data_isSet = false;
}

void
SWGAISModActions_tx::cleanup() {
    if(data != nullptr) { 
        delete data;
    }
}

SWGAISModActions_tx*
SWGAISModActions_tx::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAISModActions_tx::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&data, pJson["data"], "QString", "QString");
    
}

QString
SWGAISModActions_tx::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAISModActions_tx::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(data != nullptr && *data != QString("")){
        toJsonValue(QString("data"), data, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGAISModActions_tx::getData() {
    return data;
}
void
SWGAISModActions_tx::setData(QString* data) {
    this->data = data;
    this->m_data_isSet = true;
}


bool
SWGAISModActions_tx::isSet(){
    bool isObjectUpdated = false;
    do{
        if(data && *data != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

