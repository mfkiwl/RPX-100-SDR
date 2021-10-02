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


#include "SWGGLScope.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGGLScope::SWGGLScope(QString* json) {
    init();
    this->fromJson(*json);
}

SWGGLScope::SWGGLScope() {
    display_mode = 0;
    m_display_mode_isSet = false;
    trace_intensity = 0;
    m_trace_intensity_isSet = false;
    grid_intensity = 0;
    m_grid_intensity_isSet = false;
    time = 0;
    m_time_isSet = false;
    time_ofs = 0;
    m_time_ofs_isSet = false;
    trace_len = 0;
    m_trace_len_isSet = false;
    trig_pre = 0;
    m_trig_pre_isSet = false;
    traces_data = nullptr;
    m_traces_data_isSet = false;
    triggers_data = nullptr;
    m_triggers_data_isSet = false;
}

SWGGLScope::~SWGGLScope() {
    this->cleanup();
}

void
SWGGLScope::init() {
    display_mode = 0;
    m_display_mode_isSet = false;
    trace_intensity = 0;
    m_trace_intensity_isSet = false;
    grid_intensity = 0;
    m_grid_intensity_isSet = false;
    time = 0;
    m_time_isSet = false;
    time_ofs = 0;
    m_time_ofs_isSet = false;
    trace_len = 0;
    m_trace_len_isSet = false;
    trig_pre = 0;
    m_trig_pre_isSet = false;
    traces_data = new QList<SWGTraceData*>();
    m_traces_data_isSet = false;
    triggers_data = new QList<SWGTriggerData*>();
    m_triggers_data_isSet = false;
}

void
SWGGLScope::cleanup() {







    if(traces_data != nullptr) { 
        auto arr = traces_data;
        for(auto o: *arr) { 
            delete o;
        }
        delete traces_data;
    }
    if(triggers_data != nullptr) { 
        auto arr = triggers_data;
        for(auto o: *arr) { 
            delete o;
        }
        delete triggers_data;
    }
}

SWGGLScope*
SWGGLScope::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGGLScope::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&display_mode, pJson["displayMode"], "qint32", "");
    
    ::SWGRPX100::setValue(&trace_intensity, pJson["traceIntensity"], "qint32", "");
    
    ::SWGRPX100::setValue(&grid_intensity, pJson["gridIntensity"], "qint32", "");
    
    ::SWGRPX100::setValue(&time, pJson["time"], "qint32", "");
    
    ::SWGRPX100::setValue(&time_ofs, pJson["timeOfs"], "qint32", "");
    
    ::SWGRPX100::setValue(&trace_len, pJson["traceLen"], "qint32", "");
    
    ::SWGRPX100::setValue(&trig_pre, pJson["trigPre"], "qint32", "");
    
    
    ::SWGRPX100::setValue(&traces_data, pJson["tracesData"], "QList", "SWGTraceData");
    
    ::SWGRPX100::setValue(&triggers_data, pJson["triggersData"], "QList", "SWGTriggerData");
}

QString
SWGGLScope::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGGLScope::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_display_mode_isSet){
        obj->insert("displayMode", QJsonValue(display_mode));
    }
    if(m_trace_intensity_isSet){
        obj->insert("traceIntensity", QJsonValue(trace_intensity));
    }
    if(m_grid_intensity_isSet){
        obj->insert("gridIntensity", QJsonValue(grid_intensity));
    }
    if(m_time_isSet){
        obj->insert("time", QJsonValue(time));
    }
    if(m_time_ofs_isSet){
        obj->insert("timeOfs", QJsonValue(time_ofs));
    }
    if(m_trace_len_isSet){
        obj->insert("traceLen", QJsonValue(trace_len));
    }
    if(m_trig_pre_isSet){
        obj->insert("trigPre", QJsonValue(trig_pre));
    }
    if(traces_data && traces_data->size() > 0){
        toJsonArray((QList<void*>*)traces_data, obj, "tracesData", "SWGTraceData");
    }
    if(triggers_data && triggers_data->size() > 0){
        toJsonArray((QList<void*>*)triggers_data, obj, "triggersData", "SWGTriggerData");
    }

    return obj;
}

qint32
SWGGLScope::getDisplayMode() {
    return display_mode;
}
void
SWGGLScope::setDisplayMode(qint32 display_mode) {
    this->display_mode = display_mode;
    this->m_display_mode_isSet = true;
}

qint32
SWGGLScope::getTraceIntensity() {
    return trace_intensity;
}
void
SWGGLScope::setTraceIntensity(qint32 trace_intensity) {
    this->trace_intensity = trace_intensity;
    this->m_trace_intensity_isSet = true;
}

qint32
SWGGLScope::getGridIntensity() {
    return grid_intensity;
}
void
SWGGLScope::setGridIntensity(qint32 grid_intensity) {
    this->grid_intensity = grid_intensity;
    this->m_grid_intensity_isSet = true;
}

qint32
SWGGLScope::getTime() {
    return time;
}
void
SWGGLScope::setTime(qint32 time) {
    this->time = time;
    this->m_time_isSet = true;
}

qint32
SWGGLScope::getTimeOfs() {
    return time_ofs;
}
void
SWGGLScope::setTimeOfs(qint32 time_ofs) {
    this->time_ofs = time_ofs;
    this->m_time_ofs_isSet = true;
}

qint32
SWGGLScope::getTraceLen() {
    return trace_len;
}
void
SWGGLScope::setTraceLen(qint32 trace_len) {
    this->trace_len = trace_len;
    this->m_trace_len_isSet = true;
}

qint32
SWGGLScope::getTrigPre() {
    return trig_pre;
}
void
SWGGLScope::setTrigPre(qint32 trig_pre) {
    this->trig_pre = trig_pre;
    this->m_trig_pre_isSet = true;
}

QList<SWGTraceData*>*
SWGGLScope::getTracesData() {
    return traces_data;
}
void
SWGGLScope::setTracesData(QList<SWGTraceData*>* traces_data) {
    this->traces_data = traces_data;
    this->m_traces_data_isSet = true;
}

QList<SWGTriggerData*>*
SWGGLScope::getTriggersData() {
    return triggers_data;
}
void
SWGGLScope::setTriggersData(QList<SWGTriggerData*>* triggers_data) {
    this->triggers_data = triggers_data;
    this->m_triggers_data_isSet = true;
}


bool
SWGGLScope::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_display_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trace_intensity_isSet){
            isObjectUpdated = true; break;
        }
        if(m_grid_intensity_isSet){
            isObjectUpdated = true; break;
        }
        if(m_time_isSet){
            isObjectUpdated = true; break;
        }
        if(m_time_ofs_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trace_len_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trig_pre_isSet){
            isObjectUpdated = true; break;
        }
        if(traces_data && (traces_data->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(triggers_data && (triggers_data->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

