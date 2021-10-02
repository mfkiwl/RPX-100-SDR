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


#include "SWGAFCReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGAFCReport::SWGAFCReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAFCReport::SWGAFCReport() {
    tracker_channel_index = 0;
    m_tracker_channel_index_isSet = false;
    tracker_device_frequency = 0L;
    m_tracker_device_frequency_isSet = false;
    tracker_channel_offset = 0;
    m_tracker_channel_offset_isSet = false;
}

SWGAFCReport::~SWGAFCReport() {
    this->cleanup();
}

void
SWGAFCReport::init() {
    tracker_channel_index = 0;
    m_tracker_channel_index_isSet = false;
    tracker_device_frequency = 0L;
    m_tracker_device_frequency_isSet = false;
    tracker_channel_offset = 0;
    m_tracker_channel_offset_isSet = false;
}

void
SWGAFCReport::cleanup() {



}

SWGAFCReport*
SWGAFCReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAFCReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&tracker_channel_index, pJson["trackerChannelIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&tracker_device_frequency, pJson["trackerDeviceFrequency"], "qint64", "");
    
    ::SWGRPX100::setValue(&tracker_channel_offset, pJson["trackerChannelOffset"], "qint32", "");
    
}

QString
SWGAFCReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAFCReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_tracker_channel_index_isSet){
        obj->insert("trackerChannelIndex", QJsonValue(tracker_channel_index));
    }
    if(m_tracker_device_frequency_isSet){
        obj->insert("trackerDeviceFrequency", QJsonValue(tracker_device_frequency));
    }
    if(m_tracker_channel_offset_isSet){
        obj->insert("trackerChannelOffset", QJsonValue(tracker_channel_offset));
    }

    return obj;
}

qint32
SWGAFCReport::getTrackerChannelIndex() {
    return tracker_channel_index;
}
void
SWGAFCReport::setTrackerChannelIndex(qint32 tracker_channel_index) {
    this->tracker_channel_index = tracker_channel_index;
    this->m_tracker_channel_index_isSet = true;
}

qint64
SWGAFCReport::getTrackerDeviceFrequency() {
    return tracker_device_frequency;
}
void
SWGAFCReport::setTrackerDeviceFrequency(qint64 tracker_device_frequency) {
    this->tracker_device_frequency = tracker_device_frequency;
    this->m_tracker_device_frequency_isSet = true;
}

qint32
SWGAFCReport::getTrackerChannelOffset() {
    return tracker_channel_offset;
}
void
SWGAFCReport::setTrackerChannelOffset(qint32 tracker_channel_offset) {
    this->tracker_channel_offset = tracker_channel_offset;
    this->m_tracker_channel_offset_isSet = true;
}


bool
SWGAFCReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_tracker_channel_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tracker_device_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tracker_channel_offset_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

