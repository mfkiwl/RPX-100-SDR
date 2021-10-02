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


#include "SWGGain.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGGain::SWGGain(QString* json) {
    init();
    this->fromJson(*json);
}

SWGGain::SWGGain() {
    gain_cb = 0;
    m_gain_cb_isSet = false;
}

SWGGain::~SWGGain() {
    this->cleanup();
}

void
SWGGain::init() {
    gain_cb = 0;
    m_gain_cb_isSet = false;
}

void
SWGGain::cleanup() {

}

SWGGain*
SWGGain::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGGain::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&gain_cb, pJson["gainCB"], "qint32", "");
    
}

QString
SWGGain::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGGain::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_gain_cb_isSet){
        obj->insert("gainCB", QJsonValue(gain_cb));
    }

    return obj;
}

qint32
SWGGain::getGainCb() {
    return gain_cb;
}
void
SWGGain::setGainCb(qint32 gain_cb) {
    this->gain_cb = gain_cb;
    this->m_gain_cb_isSet = true;
}


bool
SWGGain::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_gain_cb_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}
