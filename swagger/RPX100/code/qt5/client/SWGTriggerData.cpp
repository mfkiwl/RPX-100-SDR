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


#include "SWGTriggerData.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGTriggerData::SWGTriggerData(QString* json) {
    init();
    this->fromJson(*json);
}

SWGTriggerData::SWGTriggerData() {
    stream_index = 0;
    m_stream_index_isSet = false;
    projection_type = 0;
    m_projection_type_isSet = false;
    input_index = 0;
    m_input_index_isSet = false;
    trigger_level = 0.0f;
    m_trigger_level_isSet = false;
    trigger_level_coarse = 0;
    m_trigger_level_coarse_isSet = false;
    trigger_level_fine = 0;
    m_trigger_level_fine_isSet = false;
    trigger_positive_edge = 0;
    m_trigger_positive_edge_isSet = false;
    trigger_both_edges = 0;
    m_trigger_both_edges_isSet = false;
    trigger_holdoff = 0;
    m_trigger_holdoff_isSet = false;
    trigger_delay = 0;
    m_trigger_delay_isSet = false;
    trigger_delay_mult = 0.0f;
    m_trigger_delay_mult_isSet = false;
    trigger_delay_coarse = 0;
    m_trigger_delay_coarse_isSet = false;
    trigger_delay_fine = 0;
    m_trigger_delay_fine_isSet = false;
    trigger_repeat = 0;
    m_trigger_repeat_isSet = false;
    trigger_color = 0;
    m_trigger_color_isSet = false;
    trigger_color_r = 0.0f;
    m_trigger_color_r_isSet = false;
    trigger_color_g = 0.0f;
    m_trigger_color_g_isSet = false;
    trigger_color_b = 0.0f;
    m_trigger_color_b_isSet = false;
}

SWGTriggerData::~SWGTriggerData() {
    this->cleanup();
}

void
SWGTriggerData::init() {
    stream_index = 0;
    m_stream_index_isSet = false;
    projection_type = 0;
    m_projection_type_isSet = false;
    input_index = 0;
    m_input_index_isSet = false;
    trigger_level = 0.0f;
    m_trigger_level_isSet = false;
    trigger_level_coarse = 0;
    m_trigger_level_coarse_isSet = false;
    trigger_level_fine = 0;
    m_trigger_level_fine_isSet = false;
    trigger_positive_edge = 0;
    m_trigger_positive_edge_isSet = false;
    trigger_both_edges = 0;
    m_trigger_both_edges_isSet = false;
    trigger_holdoff = 0;
    m_trigger_holdoff_isSet = false;
    trigger_delay = 0;
    m_trigger_delay_isSet = false;
    trigger_delay_mult = 0.0f;
    m_trigger_delay_mult_isSet = false;
    trigger_delay_coarse = 0;
    m_trigger_delay_coarse_isSet = false;
    trigger_delay_fine = 0;
    m_trigger_delay_fine_isSet = false;
    trigger_repeat = 0;
    m_trigger_repeat_isSet = false;
    trigger_color = 0;
    m_trigger_color_isSet = false;
    trigger_color_r = 0.0f;
    m_trigger_color_r_isSet = false;
    trigger_color_g = 0.0f;
    m_trigger_color_g_isSet = false;
    trigger_color_b = 0.0f;
    m_trigger_color_b_isSet = false;
}

void
SWGTriggerData::cleanup() {


















}

SWGTriggerData*
SWGTriggerData::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGTriggerData::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&projection_type, pJson["projectionType"], "qint32", "");
    
    ::SWGRPX100::setValue(&input_index, pJson["inputIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_level, pJson["triggerLevel"], "float", "");
    
    ::SWGRPX100::setValue(&trigger_level_coarse, pJson["triggerLevelCoarse"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_level_fine, pJson["triggerLevelFine"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_positive_edge, pJson["triggerPositiveEdge"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_both_edges, pJson["triggerBothEdges"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_holdoff, pJson["triggerHoldoff"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_delay, pJson["triggerDelay"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_delay_mult, pJson["triggerDelayMult"], "float", "");
    
    ::SWGRPX100::setValue(&trigger_delay_coarse, pJson["triggerDelayCoarse"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_delay_fine, pJson["triggerDelayFine"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_repeat, pJson["triggerRepeat"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_color, pJson["triggerColor"], "qint32", "");
    
    ::SWGRPX100::setValue(&trigger_color_r, pJson["triggerColorR"], "float", "");
    
    ::SWGRPX100::setValue(&trigger_color_g, pJson["triggerColorG"], "float", "");
    
    ::SWGRPX100::setValue(&trigger_color_b, pJson["triggerColorB"], "float", "");
    
}

QString
SWGTriggerData::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGTriggerData::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_stream_index_isSet){
        obj->insert("streamIndex", QJsonValue(stream_index));
    }
    if(m_projection_type_isSet){
        obj->insert("projectionType", QJsonValue(projection_type));
    }
    if(m_input_index_isSet){
        obj->insert("inputIndex", QJsonValue(input_index));
    }
    if(m_trigger_level_isSet){
        obj->insert("triggerLevel", QJsonValue(trigger_level));
    }
    if(m_trigger_level_coarse_isSet){
        obj->insert("triggerLevelCoarse", QJsonValue(trigger_level_coarse));
    }
    if(m_trigger_level_fine_isSet){
        obj->insert("triggerLevelFine", QJsonValue(trigger_level_fine));
    }
    if(m_trigger_positive_edge_isSet){
        obj->insert("triggerPositiveEdge", QJsonValue(trigger_positive_edge));
    }
    if(m_trigger_both_edges_isSet){
        obj->insert("triggerBothEdges", QJsonValue(trigger_both_edges));
    }
    if(m_trigger_holdoff_isSet){
        obj->insert("triggerHoldoff", QJsonValue(trigger_holdoff));
    }
    if(m_trigger_delay_isSet){
        obj->insert("triggerDelay", QJsonValue(trigger_delay));
    }
    if(m_trigger_delay_mult_isSet){
        obj->insert("triggerDelayMult", QJsonValue(trigger_delay_mult));
    }
    if(m_trigger_delay_coarse_isSet){
        obj->insert("triggerDelayCoarse", QJsonValue(trigger_delay_coarse));
    }
    if(m_trigger_delay_fine_isSet){
        obj->insert("triggerDelayFine", QJsonValue(trigger_delay_fine));
    }
    if(m_trigger_repeat_isSet){
        obj->insert("triggerRepeat", QJsonValue(trigger_repeat));
    }
    if(m_trigger_color_isSet){
        obj->insert("triggerColor", QJsonValue(trigger_color));
    }
    if(m_trigger_color_r_isSet){
        obj->insert("triggerColorR", QJsonValue(trigger_color_r));
    }
    if(m_trigger_color_g_isSet){
        obj->insert("triggerColorG", QJsonValue(trigger_color_g));
    }
    if(m_trigger_color_b_isSet){
        obj->insert("triggerColorB", QJsonValue(trigger_color_b));
    }

    return obj;
}

qint32
SWGTriggerData::getStreamIndex() {
    return stream_index;
}
void
SWGTriggerData::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGTriggerData::getProjectionType() {
    return projection_type;
}
void
SWGTriggerData::setProjectionType(qint32 projection_type) {
    this->projection_type = projection_type;
    this->m_projection_type_isSet = true;
}

qint32
SWGTriggerData::getInputIndex() {
    return input_index;
}
void
SWGTriggerData::setInputIndex(qint32 input_index) {
    this->input_index = input_index;
    this->m_input_index_isSet = true;
}

float
SWGTriggerData::getTriggerLevel() {
    return trigger_level;
}
void
SWGTriggerData::setTriggerLevel(float trigger_level) {
    this->trigger_level = trigger_level;
    this->m_trigger_level_isSet = true;
}

qint32
SWGTriggerData::getTriggerLevelCoarse() {
    return trigger_level_coarse;
}
void
SWGTriggerData::setTriggerLevelCoarse(qint32 trigger_level_coarse) {
    this->trigger_level_coarse = trigger_level_coarse;
    this->m_trigger_level_coarse_isSet = true;
}

qint32
SWGTriggerData::getTriggerLevelFine() {
    return trigger_level_fine;
}
void
SWGTriggerData::setTriggerLevelFine(qint32 trigger_level_fine) {
    this->trigger_level_fine = trigger_level_fine;
    this->m_trigger_level_fine_isSet = true;
}

qint32
SWGTriggerData::getTriggerPositiveEdge() {
    return trigger_positive_edge;
}
void
SWGTriggerData::setTriggerPositiveEdge(qint32 trigger_positive_edge) {
    this->trigger_positive_edge = trigger_positive_edge;
    this->m_trigger_positive_edge_isSet = true;
}

qint32
SWGTriggerData::getTriggerBothEdges() {
    return trigger_both_edges;
}
void
SWGTriggerData::setTriggerBothEdges(qint32 trigger_both_edges) {
    this->trigger_both_edges = trigger_both_edges;
    this->m_trigger_both_edges_isSet = true;
}

qint32
SWGTriggerData::getTriggerHoldoff() {
    return trigger_holdoff;
}
void
SWGTriggerData::setTriggerHoldoff(qint32 trigger_holdoff) {
    this->trigger_holdoff = trigger_holdoff;
    this->m_trigger_holdoff_isSet = true;
}

qint32
SWGTriggerData::getTriggerDelay() {
    return trigger_delay;
}
void
SWGTriggerData::setTriggerDelay(qint32 trigger_delay) {
    this->trigger_delay = trigger_delay;
    this->m_trigger_delay_isSet = true;
}

float
SWGTriggerData::getTriggerDelayMult() {
    return trigger_delay_mult;
}
void
SWGTriggerData::setTriggerDelayMult(float trigger_delay_mult) {
    this->trigger_delay_mult = trigger_delay_mult;
    this->m_trigger_delay_mult_isSet = true;
}

qint32
SWGTriggerData::getTriggerDelayCoarse() {
    return trigger_delay_coarse;
}
void
SWGTriggerData::setTriggerDelayCoarse(qint32 trigger_delay_coarse) {
    this->trigger_delay_coarse = trigger_delay_coarse;
    this->m_trigger_delay_coarse_isSet = true;
}

qint32
SWGTriggerData::getTriggerDelayFine() {
    return trigger_delay_fine;
}
void
SWGTriggerData::setTriggerDelayFine(qint32 trigger_delay_fine) {
    this->trigger_delay_fine = trigger_delay_fine;
    this->m_trigger_delay_fine_isSet = true;
}

qint32
SWGTriggerData::getTriggerRepeat() {
    return trigger_repeat;
}
void
SWGTriggerData::setTriggerRepeat(qint32 trigger_repeat) {
    this->trigger_repeat = trigger_repeat;
    this->m_trigger_repeat_isSet = true;
}

qint32
SWGTriggerData::getTriggerColor() {
    return trigger_color;
}
void
SWGTriggerData::setTriggerColor(qint32 trigger_color) {
    this->trigger_color = trigger_color;
    this->m_trigger_color_isSet = true;
}

float
SWGTriggerData::getTriggerColorR() {
    return trigger_color_r;
}
void
SWGTriggerData::setTriggerColorR(float trigger_color_r) {
    this->trigger_color_r = trigger_color_r;
    this->m_trigger_color_r_isSet = true;
}

float
SWGTriggerData::getTriggerColorG() {
    return trigger_color_g;
}
void
SWGTriggerData::setTriggerColorG(float trigger_color_g) {
    this->trigger_color_g = trigger_color_g;
    this->m_trigger_color_g_isSet = true;
}

float
SWGTriggerData::getTriggerColorB() {
    return trigger_color_b;
}
void
SWGTriggerData::setTriggerColorB(float trigger_color_b) {
    this->trigger_color_b = trigger_color_b;
    this->m_trigger_color_b_isSet = true;
}


bool
SWGTriggerData::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_stream_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_projection_type_isSet){
            isObjectUpdated = true; break;
        }
        if(m_input_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_level_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_level_coarse_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_level_fine_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_positive_edge_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_both_edges_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_holdoff_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_delay_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_delay_mult_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_delay_coarse_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_delay_fine_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_repeat_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_color_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_color_r_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_color_g_isSet){
            isObjectUpdated = true; break;
        }
        if(m_trigger_color_b_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

