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


#include "SWGRemoteOutputReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGRemoteOutputReport::SWGRemoteOutputReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRemoteOutputReport::SWGRemoteOutputReport() {
    buffer_rw_balance = 0.0f;
    m_buffer_rw_balance_isSet = false;
    sample_count = 0;
    m_sample_count_isSet = false;
}

SWGRemoteOutputReport::~SWGRemoteOutputReport() {
    this->cleanup();
}

void
SWGRemoteOutputReport::init() {
    buffer_rw_balance = 0.0f;
    m_buffer_rw_balance_isSet = false;
    sample_count = 0;
    m_sample_count_isSet = false;
}

void
SWGRemoteOutputReport::cleanup() {


}

SWGRemoteOutputReport*
SWGRemoteOutputReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRemoteOutputReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&buffer_rw_balance, pJson["bufferRWBalance"], "float", "");
    
    ::SWGRPX100::setValue(&sample_count, pJson["sampleCount"], "qint32", "");
    
}

QString
SWGRemoteOutputReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGRemoteOutputReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_buffer_rw_balance_isSet){
        obj->insert("bufferRWBalance", QJsonValue(buffer_rw_balance));
    }
    if(m_sample_count_isSet){
        obj->insert("sampleCount", QJsonValue(sample_count));
    }

    return obj;
}

float
SWGRemoteOutputReport::getBufferRwBalance() {
    return buffer_rw_balance;
}
void
SWGRemoteOutputReport::setBufferRwBalance(float buffer_rw_balance) {
    this->buffer_rw_balance = buffer_rw_balance;
    this->m_buffer_rw_balance_isSet = true;
}

qint32
SWGRemoteOutputReport::getSampleCount() {
    return sample_count;
}
void
SWGRemoteOutputReport::setSampleCount(qint32 sample_count) {
    this->sample_count = sample_count;
    this->m_sample_count_isSet = true;
}


bool
SWGRemoteOutputReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_buffer_rw_balance_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sample_count_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

