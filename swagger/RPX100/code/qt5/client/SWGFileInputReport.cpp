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


#include "SWGFileInputReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGFileInputReport::SWGFileInputReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFileInputReport::SWGFileInputReport() {
    file_name = nullptr;
    m_file_name_isSet = false;
    sample_rate = 0;
    m_sample_rate_isSet = false;
    sample_size = 0;
    m_sample_size_isSet = false;
    absolute_time = nullptr;
    m_absolute_time_isSet = false;
    elapsed_time = nullptr;
    m_elapsed_time_isSet = false;
    duration_time = nullptr;
    m_duration_time_isSet = false;
}

SWGFileInputReport::~SWGFileInputReport() {
    this->cleanup();
}

void
SWGFileInputReport::init() {
    file_name = new QString("");
    m_file_name_isSet = false;
    sample_rate = 0;
    m_sample_rate_isSet = false;
    sample_size = 0;
    m_sample_size_isSet = false;
    absolute_time = new QString("");
    m_absolute_time_isSet = false;
    elapsed_time = new QString("");
    m_elapsed_time_isSet = false;
    duration_time = new QString("");
    m_duration_time_isSet = false;
}

void
SWGFileInputReport::cleanup() {
    if(file_name != nullptr) { 
        delete file_name;
    }


    if(absolute_time != nullptr) { 
        delete absolute_time;
    }
    if(elapsed_time != nullptr) { 
        delete elapsed_time;
    }
    if(duration_time != nullptr) { 
        delete duration_time;
    }
}

SWGFileInputReport*
SWGFileInputReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFileInputReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&file_name, pJson["fileName"], "QString", "QString");
    
    ::SWGRPX100::setValue(&sample_rate, pJson["sampleRate"], "qint32", "");
    
    ::SWGRPX100::setValue(&sample_size, pJson["sampleSize"], "qint32", "");
    
    ::SWGRPX100::setValue(&absolute_time, pJson["absoluteTime"], "QString", "QString");
    
    ::SWGRPX100::setValue(&elapsed_time, pJson["elapsedTime"], "QString", "QString");
    
    ::SWGRPX100::setValue(&duration_time, pJson["durationTime"], "QString", "QString");
    
}

QString
SWGFileInputReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFileInputReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(file_name != nullptr && *file_name != QString("")){
        toJsonValue(QString("fileName"), file_name, obj, QString("QString"));
    }
    if(m_sample_rate_isSet){
        obj->insert("sampleRate", QJsonValue(sample_rate));
    }
    if(m_sample_size_isSet){
        obj->insert("sampleSize", QJsonValue(sample_size));
    }
    if(absolute_time != nullptr && *absolute_time != QString("")){
        toJsonValue(QString("absoluteTime"), absolute_time, obj, QString("QString"));
    }
    if(elapsed_time != nullptr && *elapsed_time != QString("")){
        toJsonValue(QString("elapsedTime"), elapsed_time, obj, QString("QString"));
    }
    if(duration_time != nullptr && *duration_time != QString("")){
        toJsonValue(QString("durationTime"), duration_time, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGFileInputReport::getFileName() {
    return file_name;
}
void
SWGFileInputReport::setFileName(QString* file_name) {
    this->file_name = file_name;
    this->m_file_name_isSet = true;
}

qint32
SWGFileInputReport::getSampleRate() {
    return sample_rate;
}
void
SWGFileInputReport::setSampleRate(qint32 sample_rate) {
    this->sample_rate = sample_rate;
    this->m_sample_rate_isSet = true;
}

qint32
SWGFileInputReport::getSampleSize() {
    return sample_size;
}
void
SWGFileInputReport::setSampleSize(qint32 sample_size) {
    this->sample_size = sample_size;
    this->m_sample_size_isSet = true;
}

QString*
SWGFileInputReport::getAbsoluteTime() {
    return absolute_time;
}
void
SWGFileInputReport::setAbsoluteTime(QString* absolute_time) {
    this->absolute_time = absolute_time;
    this->m_absolute_time_isSet = true;
}

QString*
SWGFileInputReport::getElapsedTime() {
    return elapsed_time;
}
void
SWGFileInputReport::setElapsedTime(QString* elapsed_time) {
    this->elapsed_time = elapsed_time;
    this->m_elapsed_time_isSet = true;
}

QString*
SWGFileInputReport::getDurationTime() {
    return duration_time;
}
void
SWGFileInputReport::setDurationTime(QString* duration_time) {
    this->duration_time = duration_time;
    this->m_duration_time_isSet = true;
}


bool
SWGFileInputReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(file_name && *file_name != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sample_size_isSet){
            isObjectUpdated = true; break;
        }
        if(absolute_time && *absolute_time != QString("")){
            isObjectUpdated = true; break;
        }
        if(elapsed_time && *elapsed_time != QString("")){
            isObjectUpdated = true; break;
        }
        if(duration_time && *duration_time != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

