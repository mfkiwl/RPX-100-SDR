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


#include "SWGADSBDemodReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGADSBDemodReport::SWGADSBDemodReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGADSBDemodReport::SWGADSBDemodReport() {
    channel_power_db = 0.0f;
    m_channel_power_db_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
    target_azimuth = 0.0f;
    m_target_azimuth_isSet = false;
    target_elevation = 0.0f;
    m_target_elevation_isSet = false;
}

SWGADSBDemodReport::~SWGADSBDemodReport() {
    this->cleanup();
}

void
SWGADSBDemodReport::init() {
    channel_power_db = 0.0f;
    m_channel_power_db_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
    target_azimuth = 0.0f;
    m_target_azimuth_isSet = false;
    target_elevation = 0.0f;
    m_target_elevation_isSet = false;
}

void
SWGADSBDemodReport::cleanup() {




}

SWGADSBDemodReport*
SWGADSBDemodReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGADSBDemodReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&channel_power_db, pJson["channelPowerDB"], "float", "");
    
    ::SWGRPX100::setValue(&channel_sample_rate, pJson["channelSampleRate"], "qint32", "");
    
    ::SWGRPX100::setValue(&target_azimuth, pJson["targetAzimuth"], "float", "");
    
    ::SWGRPX100::setValue(&target_elevation, pJson["targetElevation"], "float", "");
    
}

QString
SWGADSBDemodReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGADSBDemodReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_channel_power_db_isSet){
        obj->insert("channelPowerDB", QJsonValue(channel_power_db));
    }
    if(m_channel_sample_rate_isSet){
        obj->insert("channelSampleRate", QJsonValue(channel_sample_rate));
    }
    if(m_target_azimuth_isSet){
        obj->insert("targetAzimuth", QJsonValue(target_azimuth));
    }
    if(m_target_elevation_isSet){
        obj->insert("targetElevation", QJsonValue(target_elevation));
    }

    return obj;
}

float
SWGADSBDemodReport::getChannelPowerDb() {
    return channel_power_db;
}
void
SWGADSBDemodReport::setChannelPowerDb(float channel_power_db) {
    this->channel_power_db = channel_power_db;
    this->m_channel_power_db_isSet = true;
}

qint32
SWGADSBDemodReport::getChannelSampleRate() {
    return channel_sample_rate;
}
void
SWGADSBDemodReport::setChannelSampleRate(qint32 channel_sample_rate) {
    this->channel_sample_rate = channel_sample_rate;
    this->m_channel_sample_rate_isSet = true;
}

float
SWGADSBDemodReport::getTargetAzimuth() {
    return target_azimuth;
}
void
SWGADSBDemodReport::setTargetAzimuth(float target_azimuth) {
    this->target_azimuth = target_azimuth;
    this->m_target_azimuth_isSet = true;
}

float
SWGADSBDemodReport::getTargetElevation() {
    return target_elevation;
}
void
SWGADSBDemodReport::setTargetElevation(float target_elevation) {
    this->target_elevation = target_elevation;
    this->m_target_elevation_isSet = true;
}


bool
SWGADSBDemodReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_channel_power_db_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_target_azimuth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_target_elevation_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

