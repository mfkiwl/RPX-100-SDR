/**
 * rpx-100
 * This is the web REST/JSON API of rpx-100 SDR software. rpx-100 is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In rpx-100 GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /rpx-100/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGSigMFFileSinkSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGSigMFFileSinkSettings::SWGSigMFFileSinkSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSigMFFileSinkSettings::SWGSigMFFileSinkSettings() {
    input_frequency_offset = 0;
    m_input_frequency_offset_isSet = false;
    file_record_name = nullptr;
    m_file_record_name_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    spectrum_squelch_mode = 0;
    m_spectrum_squelch_mode_isSet = false;
    spectrum_squelch = 0.0f;
    m_spectrum_squelch_isSet = false;
    pre_record_time = 0;
    m_pre_record_time_isSet = false;
    squelch_post_record_time = 0;
    m_squelch_post_record_time_isSet = false;
    squelch_recording_enable = 0;
    m_squelch_recording_enable_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

SWGSigMFFileSinkSettings::~SWGSigMFFileSinkSettings() {
    this->cleanup();
}

void
SWGSigMFFileSinkSettings::init() {
    input_frequency_offset = 0;
    m_input_frequency_offset_isSet = false;
    file_record_name = new QString("");
    m_file_record_name_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    spectrum_squelch_mode = 0;
    m_spectrum_squelch_mode_isSet = false;
    spectrum_squelch = 0.0f;
    m_spectrum_squelch_isSet = false;
    pre_record_time = 0;
    m_pre_record_time_isSet = false;
    squelch_post_record_time = 0;
    m_squelch_post_record_time_isSet = false;
    squelch_recording_enable = 0;
    m_squelch_recording_enable_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

void
SWGSigMFFileSinkSettings::cleanup() {

    if(file_record_name != nullptr) { 
        delete file_record_name;
    }

    if(title != nullptr) { 
        delete title;
    }








    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGSigMFFileSinkSettings*
SWGSigMFFileSinkSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSigMFFileSinkSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint32", "");
    
    ::SWGrpx-100::setValue(&file_record_name, pJson["fileRecordName"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGrpx-100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGrpx-100::setValue(&spectrum_squelch_mode, pJson["spectrumSquelchMode"], "qint32", "");
    
    ::SWGrpx-100::setValue(&spectrum_squelch, pJson["spectrumSquelch"], "float", "");
    
    ::SWGrpx-100::setValue(&pre_record_time, pJson["preRecordTime"], "qint32", "");
    
    ::SWGrpx-100::setValue(&squelch_post_record_time, pJson["squelchPostRecordTime"], "qint32", "");
    
    ::SWGrpx-100::setValue(&squelch_recording_enable, pJson["squelchRecordingEnable"], "qint32", "");
    
    ::SWGrpx-100::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGSigMFFileSinkSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSigMFFileSinkSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(file_record_name != nullptr && *file_record_name != QString("")){
        toJsonValue(QString("fileRecordName"), file_record_name, obj, QString("QString"));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_spectrum_squelch_mode_isSet){
        obj->insert("spectrumSquelchMode", QJsonValue(spectrum_squelch_mode));
    }
    if(m_spectrum_squelch_isSet){
        obj->insert("spectrumSquelch", QJsonValue(spectrum_squelch));
    }
    if(m_pre_record_time_isSet){
        obj->insert("preRecordTime", QJsonValue(pre_record_time));
    }
    if(m_squelch_post_record_time_isSet){
        obj->insert("squelchPostRecordTime", QJsonValue(squelch_post_record_time));
    }
    if(m_squelch_recording_enable_isSet){
        obj->insert("squelchRecordingEnable", QJsonValue(squelch_recording_enable));
    }
    if(m_stream_index_isSet){
        obj->insert("streamIndex", QJsonValue(stream_index));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }
    if(m_reverse_api_channel_index_isSet){
        obj->insert("reverseAPIChannelIndex", QJsonValue(reverse_api_channel_index));
    }

    return obj;
}

qint32
SWGSigMFFileSinkSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGSigMFFileSinkSettings::setInputFrequencyOffset(qint32 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

QString*
SWGSigMFFileSinkSettings::getFileRecordName() {
    return file_record_name;
}
void
SWGSigMFFileSinkSettings::setFileRecordName(QString* file_record_name) {
    this->file_record_name = file_record_name;
    this->m_file_record_name_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getRgbColor() {
    return rgb_color;
}
void
SWGSigMFFileSinkSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGSigMFFileSinkSettings::getTitle() {
    return title;
}
void
SWGSigMFFileSinkSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGSigMFFileSinkSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getSpectrumSquelchMode() {
    return spectrum_squelch_mode;
}
void
SWGSigMFFileSinkSettings::setSpectrumSquelchMode(qint32 spectrum_squelch_mode) {
    this->spectrum_squelch_mode = spectrum_squelch_mode;
    this->m_spectrum_squelch_mode_isSet = true;
}

float
SWGSigMFFileSinkSettings::getSpectrumSquelch() {
    return spectrum_squelch;
}
void
SWGSigMFFileSinkSettings::setSpectrumSquelch(float spectrum_squelch) {
    this->spectrum_squelch = spectrum_squelch;
    this->m_spectrum_squelch_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getPreRecordTime() {
    return pre_record_time;
}
void
SWGSigMFFileSinkSettings::setPreRecordTime(qint32 pre_record_time) {
    this->pre_record_time = pre_record_time;
    this->m_pre_record_time_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getSquelchPostRecordTime() {
    return squelch_post_record_time;
}
void
SWGSigMFFileSinkSettings::setSquelchPostRecordTime(qint32 squelch_post_record_time) {
    this->squelch_post_record_time = squelch_post_record_time;
    this->m_squelch_post_record_time_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getSquelchRecordingEnable() {
    return squelch_recording_enable;
}
void
SWGSigMFFileSinkSettings::setSquelchRecordingEnable(qint32 squelch_recording_enable) {
    this->squelch_recording_enable = squelch_recording_enable;
    this->m_squelch_recording_enable_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getStreamIndex() {
    return stream_index;
}
void
SWGSigMFFileSinkSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGSigMFFileSinkSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGSigMFFileSinkSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGSigMFFileSinkSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGSigMFFileSinkSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGSigMFFileSinkSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGSigMFFileSinkSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGSigMFFileSinkSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGSigMFFileSinkSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(file_record_name && *file_record_name != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_spectrum_squelch_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_spectrum_squelch_isSet){
            isObjectUpdated = true; break;
        }
        if(m_pre_record_time_isSet){
            isObjectUpdated = true; break;
        }
        if(m_squelch_post_record_time_isSet){
            isObjectUpdated = true; break;
        }
        if(m_squelch_recording_enable_isSet){
            isObjectUpdated = true; break;
        }
        if(m_stream_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_channel_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

