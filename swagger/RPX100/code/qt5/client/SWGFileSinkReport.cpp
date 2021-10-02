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


#include "SWGFileSinkReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGFileSinkReport::SWGFileSinkReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFileSinkReport::SWGFileSinkReport() {
    spectrum_squelch = 0;
    m_spectrum_squelch_isSet = false;
    spectrum_max = 0.0f;
    m_spectrum_max_isSet = false;
    sink_sample_rate = 0;
    m_sink_sample_rate_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
    recording = 0;
    m_recording_isSet = false;
    record_time_ms = 0;
    m_record_time_ms_isSet = false;
    record_size = 0L;
    m_record_size_isSet = false;
    record_captures = 0;
    m_record_captures_isSet = false;
}

SWGFileSinkReport::~SWGFileSinkReport() {
    this->cleanup();
}

void
SWGFileSinkReport::init() {
    spectrum_squelch = 0;
    m_spectrum_squelch_isSet = false;
    spectrum_max = 0.0f;
    m_spectrum_max_isSet = false;
    sink_sample_rate = 0;
    m_sink_sample_rate_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
    recording = 0;
    m_recording_isSet = false;
    record_time_ms = 0;
    m_record_time_ms_isSet = false;
    record_size = 0L;
    m_record_size_isSet = false;
    record_captures = 0;
    m_record_captures_isSet = false;
}

void
SWGFileSinkReport::cleanup() {








}

SWGFileSinkReport*
SWGFileSinkReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFileSinkReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&spectrum_squelch, pJson["spectrumSquelch"], "qint32", "");
    
    ::SWGRPX100::setValue(&spectrum_max, pJson["spectrumMax"], "float", "");
    
    ::SWGRPX100::setValue(&sink_sample_rate, pJson["sinkSampleRate"], "qint32", "");
    
    ::SWGRPX100::setValue(&channel_sample_rate, pJson["channelSampleRate"], "qint32", "");
    
    ::SWGRPX100::setValue(&recording, pJson["recording"], "qint32", "");
    
    ::SWGRPX100::setValue(&record_time_ms, pJson["recordTimeMs"], "qint32", "");
    
    ::SWGRPX100::setValue(&record_size, pJson["recordSize"], "qint64", "");
    
    ::SWGRPX100::setValue(&record_captures, pJson["recordCaptures"], "qint32", "");
    
}

QString
SWGFileSinkReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFileSinkReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_spectrum_squelch_isSet){
        obj->insert("spectrumSquelch", QJsonValue(spectrum_squelch));
    }
    if(m_spectrum_max_isSet){
        obj->insert("spectrumMax", QJsonValue(spectrum_max));
    }
    if(m_sink_sample_rate_isSet){
        obj->insert("sinkSampleRate", QJsonValue(sink_sample_rate));
    }
    if(m_channel_sample_rate_isSet){
        obj->insert("channelSampleRate", QJsonValue(channel_sample_rate));
    }
    if(m_recording_isSet){
        obj->insert("recording", QJsonValue(recording));
    }
    if(m_record_time_ms_isSet){
        obj->insert("recordTimeMs", QJsonValue(record_time_ms));
    }
    if(m_record_size_isSet){
        obj->insert("recordSize", QJsonValue(record_size));
    }
    if(m_record_captures_isSet){
        obj->insert("recordCaptures", QJsonValue(record_captures));
    }

    return obj;
}

qint32
SWGFileSinkReport::getSpectrumSquelch() {
    return spectrum_squelch;
}
void
SWGFileSinkReport::setSpectrumSquelch(qint32 spectrum_squelch) {
    this->spectrum_squelch = spectrum_squelch;
    this->m_spectrum_squelch_isSet = true;
}

float
SWGFileSinkReport::getSpectrumMax() {
    return spectrum_max;
}
void
SWGFileSinkReport::setSpectrumMax(float spectrum_max) {
    this->spectrum_max = spectrum_max;
    this->m_spectrum_max_isSet = true;
}

qint32
SWGFileSinkReport::getSinkSampleRate() {
    return sink_sample_rate;
}
void
SWGFileSinkReport::setSinkSampleRate(qint32 sink_sample_rate) {
    this->sink_sample_rate = sink_sample_rate;
    this->m_sink_sample_rate_isSet = true;
}

qint32
SWGFileSinkReport::getChannelSampleRate() {
    return channel_sample_rate;
}
void
SWGFileSinkReport::setChannelSampleRate(qint32 channel_sample_rate) {
    this->channel_sample_rate = channel_sample_rate;
    this->m_channel_sample_rate_isSet = true;
}

qint32
SWGFileSinkReport::getRecording() {
    return recording;
}
void
SWGFileSinkReport::setRecording(qint32 recording) {
    this->recording = recording;
    this->m_recording_isSet = true;
}

qint32
SWGFileSinkReport::getRecordTimeMs() {
    return record_time_ms;
}
void
SWGFileSinkReport::setRecordTimeMs(qint32 record_time_ms) {
    this->record_time_ms = record_time_ms;
    this->m_record_time_ms_isSet = true;
}

qint64
SWGFileSinkReport::getRecordSize() {
    return record_size;
}
void
SWGFileSinkReport::setRecordSize(qint64 record_size) {
    this->record_size = record_size;
    this->m_record_size_isSet = true;
}

qint32
SWGFileSinkReport::getRecordCaptures() {
    return record_captures;
}
void
SWGFileSinkReport::setRecordCaptures(qint32 record_captures) {
    this->record_captures = record_captures;
    this->m_record_captures_isSet = true;
}


bool
SWGFileSinkReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_spectrum_squelch_isSet){
            isObjectUpdated = true; break;
        }
        if(m_spectrum_max_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sink_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_recording_isSet){
            isObjectUpdated = true; break;
        }
        if(m_record_time_ms_isSet){
            isObjectUpdated = true; break;
        }
        if(m_record_size_isSet){
            isObjectUpdated = true; break;
        }
        if(m_record_captures_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

