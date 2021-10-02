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


#include "SWGAISModSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGAISModSettings::SWGAISModSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAISModSettings::SWGAISModSettings() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    baud = 0;
    m_baud_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    fm_deviation = 0;
    m_fm_deviation_isSet = false;
    gain = 0.0f;
    m_gain_isSet = false;
    channel_mute = 0;
    m_channel_mute_isSet = false;
    repeat = 0;
    m_repeat_isSet = false;
    repeat_delay = 0.0f;
    m_repeat_delay_isSet = false;
    repeat_count = 0;
    m_repeat_count_isSet = false;
    ramp_up_bits = 0;
    m_ramp_up_bits_isSet = false;
    ramp_down_bits = 0;
    m_ramp_down_bits_isSet = false;
    ramp_range = 0;
    m_ramp_range_isSet = false;
    lpf_taps = 0;
    m_lpf_taps_isSet = false;
    rf_noise = 0;
    m_rf_noise_isSet = false;
    write_to_file = 0;
    m_write_to_file_isSet = false;
    spectrum_rate = 0;
    m_spectrum_rate_isSet = false;
    msg_id = 0;
    m_msg_id_isSet = false;
    mmsi = nullptr;
    m_mmsi_isSet = false;
    status = 0;
    m_status_isSet = false;
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    course = 0.0f;
    m_course_isSet = false;
    speed = 0.0f;
    m_speed_isSet = false;
    heading = 0;
    m_heading_isSet = false;
    data = nullptr;
    m_data_isSet = false;
    bt = 0.0f;
    m_bt_isSet = false;
    symbol_span = 0;
    m_symbol_span_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
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
    udp_enabled = 0;
    m_udp_enabled_isSet = false;
    udp_address = nullptr;
    m_udp_address_isSet = false;
    udp_port = 0;
    m_udp_port_isSet = false;
}

SWGAISModSettings::~SWGAISModSettings() {
    this->cleanup();
}

void
SWGAISModSettings::init() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    baud = 0;
    m_baud_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    fm_deviation = 0;
    m_fm_deviation_isSet = false;
    gain = 0.0f;
    m_gain_isSet = false;
    channel_mute = 0;
    m_channel_mute_isSet = false;
    repeat = 0;
    m_repeat_isSet = false;
    repeat_delay = 0.0f;
    m_repeat_delay_isSet = false;
    repeat_count = 0;
    m_repeat_count_isSet = false;
    ramp_up_bits = 0;
    m_ramp_up_bits_isSet = false;
    ramp_down_bits = 0;
    m_ramp_down_bits_isSet = false;
    ramp_range = 0;
    m_ramp_range_isSet = false;
    lpf_taps = 0;
    m_lpf_taps_isSet = false;
    rf_noise = 0;
    m_rf_noise_isSet = false;
    write_to_file = 0;
    m_write_to_file_isSet = false;
    spectrum_rate = 0;
    m_spectrum_rate_isSet = false;
    msg_id = 0;
    m_msg_id_isSet = false;
    mmsi = new QString("");
    m_mmsi_isSet = false;
    status = 0;
    m_status_isSet = false;
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    course = 0.0f;
    m_course_isSet = false;
    speed = 0.0f;
    m_speed_isSet = false;
    heading = 0;
    m_heading_isSet = false;
    data = new QString("");
    m_data_isSet = false;
    bt = 0.0f;
    m_bt_isSet = false;
    symbol_span = 0;
    m_symbol_span_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
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
    udp_enabled = 0;
    m_udp_enabled_isSet = false;
    udp_address = new QString("");
    m_udp_address_isSet = false;
    udp_port = 0;
    m_udp_port_isSet = false;
}

void
SWGAISModSettings::cleanup() {

















    if(mmsi != nullptr) { 
        delete mmsi;
    }






    if(data != nullptr) { 
        delete data;
    }



    if(title != nullptr) { 
        delete title;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }




    if(udp_address != nullptr) { 
        delete udp_address;
    }

}

SWGAISModSettings*
SWGAISModSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAISModSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint64", "");
    
    ::SWGrpx-100::setValue(&baud, pJson["baud"], "qint32", "");
    
    ::SWGrpx-100::setValue(&rf_bandwidth, pJson["rfBandwidth"], "float", "");
    
    ::SWGrpx-100::setValue(&fm_deviation, pJson["fmDeviation"], "qint32", "");
    
    ::SWGrpx-100::setValue(&gain, pJson["gain"], "float", "");
    
    ::SWGrpx-100::setValue(&channel_mute, pJson["channelMute"], "qint32", "");
    
    ::SWGrpx-100::setValue(&repeat, pJson["repeat"], "qint32", "");
    
    ::SWGrpx-100::setValue(&repeat_delay, pJson["repeatDelay"], "float", "");
    
    ::SWGrpx-100::setValue(&repeat_count, pJson["repeatCount"], "qint32", "");
    
    ::SWGrpx-100::setValue(&ramp_up_bits, pJson["rampUpBits"], "qint32", "");
    
    ::SWGrpx-100::setValue(&ramp_down_bits, pJson["rampDownBits"], "qint32", "");
    
    ::SWGrpx-100::setValue(&ramp_range, pJson["rampRange"], "qint32", "");
    
    ::SWGrpx-100::setValue(&lpf_taps, pJson["lpfTaps"], "qint32", "");
    
    ::SWGrpx-100::setValue(&rf_noise, pJson["rfNoise"], "qint32", "");
    
    ::SWGrpx-100::setValue(&write_to_file, pJson["writeToFile"], "qint32", "");
    
    ::SWGrpx-100::setValue(&spectrum_rate, pJson["spectrumRate"], "qint32", "");
    
    ::SWGrpx-100::setValue(&msg_id, pJson["msgId"], "qint32", "");
    
    ::SWGrpx-100::setValue(&mmsi, pJson["mmsi"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&status, pJson["status"], "qint32", "");
    
    ::SWGrpx-100::setValue(&latitude, pJson["latitude"], "float", "");
    
    ::SWGrpx-100::setValue(&longitude, pJson["longitude"], "float", "");
    
    ::SWGrpx-100::setValue(&course, pJson["course"], "float", "");
    
    ::SWGrpx-100::setValue(&speed, pJson["speed"], "float", "");
    
    ::SWGrpx-100::setValue(&heading, pJson["heading"], "qint32", "");
    
    ::SWGrpx-100::setValue(&data, pJson["data"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&bt, pJson["bt"], "float", "");
    
    ::SWGrpx-100::setValue(&symbol_span, pJson["symbolSpan"], "qint32", "");
    
    ::SWGrpx-100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGrpx-100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
    ::SWGrpx-100::setValue(&udp_enabled, pJson["udpEnabled"], "qint32", "");
    
    ::SWGrpx-100::setValue(&udp_address, pJson["udpAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&udp_port, pJson["udpPort"], "qint32", "");
    
}

QString
SWGAISModSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAISModSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(m_baud_isSet){
        obj->insert("baud", QJsonValue(baud));
    }
    if(m_rf_bandwidth_isSet){
        obj->insert("rfBandwidth", QJsonValue(rf_bandwidth));
    }
    if(m_fm_deviation_isSet){
        obj->insert("fmDeviation", QJsonValue(fm_deviation));
    }
    if(m_gain_isSet){
        obj->insert("gain", QJsonValue(gain));
    }
    if(m_channel_mute_isSet){
        obj->insert("channelMute", QJsonValue(channel_mute));
    }
    if(m_repeat_isSet){
        obj->insert("repeat", QJsonValue(repeat));
    }
    if(m_repeat_delay_isSet){
        obj->insert("repeatDelay", QJsonValue(repeat_delay));
    }
    if(m_repeat_count_isSet){
        obj->insert("repeatCount", QJsonValue(repeat_count));
    }
    if(m_ramp_up_bits_isSet){
        obj->insert("rampUpBits", QJsonValue(ramp_up_bits));
    }
    if(m_ramp_down_bits_isSet){
        obj->insert("rampDownBits", QJsonValue(ramp_down_bits));
    }
    if(m_ramp_range_isSet){
        obj->insert("rampRange", QJsonValue(ramp_range));
    }
    if(m_lpf_taps_isSet){
        obj->insert("lpfTaps", QJsonValue(lpf_taps));
    }
    if(m_rf_noise_isSet){
        obj->insert("rfNoise", QJsonValue(rf_noise));
    }
    if(m_write_to_file_isSet){
        obj->insert("writeToFile", QJsonValue(write_to_file));
    }
    if(m_spectrum_rate_isSet){
        obj->insert("spectrumRate", QJsonValue(spectrum_rate));
    }
    if(m_msg_id_isSet){
        obj->insert("msgId", QJsonValue(msg_id));
    }
    if(mmsi != nullptr && *mmsi != QString("")){
        toJsonValue(QString("mmsi"), mmsi, obj, QString("QString"));
    }
    if(m_status_isSet){
        obj->insert("status", QJsonValue(status));
    }
    if(m_latitude_isSet){
        obj->insert("latitude", QJsonValue(latitude));
    }
    if(m_longitude_isSet){
        obj->insert("longitude", QJsonValue(longitude));
    }
    if(m_course_isSet){
        obj->insert("course", QJsonValue(course));
    }
    if(m_speed_isSet){
        obj->insert("speed", QJsonValue(speed));
    }
    if(m_heading_isSet){
        obj->insert("heading", QJsonValue(heading));
    }
    if(data != nullptr && *data != QString("")){
        toJsonValue(QString("data"), data, obj, QString("QString"));
    }
    if(m_bt_isSet){
        obj->insert("bt", QJsonValue(bt));
    }
    if(m_symbol_span_isSet){
        obj->insert("symbolSpan", QJsonValue(symbol_span));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
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
    if(m_udp_enabled_isSet){
        obj->insert("udpEnabled", QJsonValue(udp_enabled));
    }
    if(udp_address != nullptr && *udp_address != QString("")){
        toJsonValue(QString("udpAddress"), udp_address, obj, QString("QString"));
    }
    if(m_udp_port_isSet){
        obj->insert("udpPort", QJsonValue(udp_port));
    }

    return obj;
}

qint64
SWGAISModSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGAISModSettings::setInputFrequencyOffset(qint64 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

qint32
SWGAISModSettings::getBaud() {
    return baud;
}
void
SWGAISModSettings::setBaud(qint32 baud) {
    this->baud = baud;
    this->m_baud_isSet = true;
}

float
SWGAISModSettings::getRfBandwidth() {
    return rf_bandwidth;
}
void
SWGAISModSettings::setRfBandwidth(float rf_bandwidth) {
    this->rf_bandwidth = rf_bandwidth;
    this->m_rf_bandwidth_isSet = true;
}

qint32
SWGAISModSettings::getFmDeviation() {
    return fm_deviation;
}
void
SWGAISModSettings::setFmDeviation(qint32 fm_deviation) {
    this->fm_deviation = fm_deviation;
    this->m_fm_deviation_isSet = true;
}

float
SWGAISModSettings::getGain() {
    return gain;
}
void
SWGAISModSettings::setGain(float gain) {
    this->gain = gain;
    this->m_gain_isSet = true;
}

qint32
SWGAISModSettings::getChannelMute() {
    return channel_mute;
}
void
SWGAISModSettings::setChannelMute(qint32 channel_mute) {
    this->channel_mute = channel_mute;
    this->m_channel_mute_isSet = true;
}

qint32
SWGAISModSettings::getRepeat() {
    return repeat;
}
void
SWGAISModSettings::setRepeat(qint32 repeat) {
    this->repeat = repeat;
    this->m_repeat_isSet = true;
}

float
SWGAISModSettings::getRepeatDelay() {
    return repeat_delay;
}
void
SWGAISModSettings::setRepeatDelay(float repeat_delay) {
    this->repeat_delay = repeat_delay;
    this->m_repeat_delay_isSet = true;
}

qint32
SWGAISModSettings::getRepeatCount() {
    return repeat_count;
}
void
SWGAISModSettings::setRepeatCount(qint32 repeat_count) {
    this->repeat_count = repeat_count;
    this->m_repeat_count_isSet = true;
}

qint32
SWGAISModSettings::getRampUpBits() {
    return ramp_up_bits;
}
void
SWGAISModSettings::setRampUpBits(qint32 ramp_up_bits) {
    this->ramp_up_bits = ramp_up_bits;
    this->m_ramp_up_bits_isSet = true;
}

qint32
SWGAISModSettings::getRampDownBits() {
    return ramp_down_bits;
}
void
SWGAISModSettings::setRampDownBits(qint32 ramp_down_bits) {
    this->ramp_down_bits = ramp_down_bits;
    this->m_ramp_down_bits_isSet = true;
}

qint32
SWGAISModSettings::getRampRange() {
    return ramp_range;
}
void
SWGAISModSettings::setRampRange(qint32 ramp_range) {
    this->ramp_range = ramp_range;
    this->m_ramp_range_isSet = true;
}

qint32
SWGAISModSettings::getLpfTaps() {
    return lpf_taps;
}
void
SWGAISModSettings::setLpfTaps(qint32 lpf_taps) {
    this->lpf_taps = lpf_taps;
    this->m_lpf_taps_isSet = true;
}

qint32
SWGAISModSettings::getRfNoise() {
    return rf_noise;
}
void
SWGAISModSettings::setRfNoise(qint32 rf_noise) {
    this->rf_noise = rf_noise;
    this->m_rf_noise_isSet = true;
}

qint32
SWGAISModSettings::getWriteToFile() {
    return write_to_file;
}
void
SWGAISModSettings::setWriteToFile(qint32 write_to_file) {
    this->write_to_file = write_to_file;
    this->m_write_to_file_isSet = true;
}

qint32
SWGAISModSettings::getSpectrumRate() {
    return spectrum_rate;
}
void
SWGAISModSettings::setSpectrumRate(qint32 spectrum_rate) {
    this->spectrum_rate = spectrum_rate;
    this->m_spectrum_rate_isSet = true;
}

qint32
SWGAISModSettings::getMsgId() {
    return msg_id;
}
void
SWGAISModSettings::setMsgId(qint32 msg_id) {
    this->msg_id = msg_id;
    this->m_msg_id_isSet = true;
}

QString*
SWGAISModSettings::getMmsi() {
    return mmsi;
}
void
SWGAISModSettings::setMmsi(QString* mmsi) {
    this->mmsi = mmsi;
    this->m_mmsi_isSet = true;
}

qint32
SWGAISModSettings::getStatus() {
    return status;
}
void
SWGAISModSettings::setStatus(qint32 status) {
    this->status = status;
    this->m_status_isSet = true;
}

float
SWGAISModSettings::getLatitude() {
    return latitude;
}
void
SWGAISModSettings::setLatitude(float latitude) {
    this->latitude = latitude;
    this->m_latitude_isSet = true;
}

float
SWGAISModSettings::getLongitude() {
    return longitude;
}
void
SWGAISModSettings::setLongitude(float longitude) {
    this->longitude = longitude;
    this->m_longitude_isSet = true;
}

float
SWGAISModSettings::getCourse() {
    return course;
}
void
SWGAISModSettings::setCourse(float course) {
    this->course = course;
    this->m_course_isSet = true;
}

float
SWGAISModSettings::getSpeed() {
    return speed;
}
void
SWGAISModSettings::setSpeed(float speed) {
    this->speed = speed;
    this->m_speed_isSet = true;
}

qint32
SWGAISModSettings::getHeading() {
    return heading;
}
void
SWGAISModSettings::setHeading(qint32 heading) {
    this->heading = heading;
    this->m_heading_isSet = true;
}

QString*
SWGAISModSettings::getData() {
    return data;
}
void
SWGAISModSettings::setData(QString* data) {
    this->data = data;
    this->m_data_isSet = true;
}

float
SWGAISModSettings::getBt() {
    return bt;
}
void
SWGAISModSettings::setBt(float bt) {
    this->bt = bt;
    this->m_bt_isSet = true;
}

qint32
SWGAISModSettings::getSymbolSpan() {
    return symbol_span;
}
void
SWGAISModSettings::setSymbolSpan(qint32 symbol_span) {
    this->symbol_span = symbol_span;
    this->m_symbol_span_isSet = true;
}

qint32
SWGAISModSettings::getRgbColor() {
    return rgb_color;
}
void
SWGAISModSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGAISModSettings::getTitle() {
    return title;
}
void
SWGAISModSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGAISModSettings::getStreamIndex() {
    return stream_index;
}
void
SWGAISModSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGAISModSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGAISModSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGAISModSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGAISModSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGAISModSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGAISModSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGAISModSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGAISModSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGAISModSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGAISModSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}

qint32
SWGAISModSettings::getUdpEnabled() {
    return udp_enabled;
}
void
SWGAISModSettings::setUdpEnabled(qint32 udp_enabled) {
    this->udp_enabled = udp_enabled;
    this->m_udp_enabled_isSet = true;
}

QString*
SWGAISModSettings::getUdpAddress() {
    return udp_address;
}
void
SWGAISModSettings::setUdpAddress(QString* udp_address) {
    this->udp_address = udp_address;
    this->m_udp_address_isSet = true;
}

qint32
SWGAISModSettings::getUdpPort() {
    return udp_port;
}
void
SWGAISModSettings::setUdpPort(qint32 udp_port) {
    this->udp_port = udp_port;
    this->m_udp_port_isSet = true;
}


bool
SWGAISModSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_baud_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rf_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fm_deviation_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_mute_isSet){
            isObjectUpdated = true; break;
        }
        if(m_repeat_isSet){
            isObjectUpdated = true; break;
        }
        if(m_repeat_delay_isSet){
            isObjectUpdated = true; break;
        }
        if(m_repeat_count_isSet){
            isObjectUpdated = true; break;
        }
        if(m_ramp_up_bits_isSet){
            isObjectUpdated = true; break;
        }
        if(m_ramp_down_bits_isSet){
            isObjectUpdated = true; break;
        }
        if(m_ramp_range_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_taps_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rf_noise_isSet){
            isObjectUpdated = true; break;
        }
        if(m_write_to_file_isSet){
            isObjectUpdated = true; break;
        }
        if(m_spectrum_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_msg_id_isSet){
            isObjectUpdated = true; break;
        }
        if(mmsi && *mmsi != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_status_isSet){
            isObjectUpdated = true; break;
        }
        if(m_latitude_isSet){
            isObjectUpdated = true; break;
        }
        if(m_longitude_isSet){
            isObjectUpdated = true; break;
        }
        if(m_course_isSet){
            isObjectUpdated = true; break;
        }
        if(m_speed_isSet){
            isObjectUpdated = true; break;
        }
        if(m_heading_isSet){
            isObjectUpdated = true; break;
        }
        if(data && *data != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_bt_isSet){
            isObjectUpdated = true; break;
        }
        if(m_symbol_span_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
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
        if(m_udp_enabled_isSet){
            isObjectUpdated = true; break;
        }
        if(udp_address && *udp_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_udp_port_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

