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


#include "SWGSSBDemodSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGSSBDemodSettings::SWGSSBDemodSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSSBDemodSettings::SWGSSBDemodSettings() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    low_cutoff = 0.0f;
    m_low_cutoff_isSet = false;
    volume = 0.0f;
    m_volume_isSet = false;
    span_log2 = 0;
    m_span_log2_isSet = false;
    audio_binaural = 0;
    m_audio_binaural_isSet = false;
    audio_flip_channels = 0;
    m_audio_flip_channels_isSet = false;
    dsb = 0;
    m_dsb_isSet = false;
    audio_mute = 0;
    m_audio_mute_isSet = false;
    agc = 0;
    m_agc_isSet = false;
    agc_clamping = 0;
    m_agc_clamping_isSet = false;
    agc_time_log2 = 0;
    m_agc_time_log2_isSet = false;
    agc_power_threshold = 0;
    m_agc_power_threshold_isSet = false;
    agc_threshold_gate = 0;
    m_agc_threshold_gate_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    audio_device_name = nullptr;
    m_audio_device_name_isSet = false;
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

SWGSSBDemodSettings::~SWGSSBDemodSettings() {
    this->cleanup();
}

void
SWGSSBDemodSettings::init() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    rf_bandwidth = 0.0f;
    m_rf_bandwidth_isSet = false;
    low_cutoff = 0.0f;
    m_low_cutoff_isSet = false;
    volume = 0.0f;
    m_volume_isSet = false;
    span_log2 = 0;
    m_span_log2_isSet = false;
    audio_binaural = 0;
    m_audio_binaural_isSet = false;
    audio_flip_channels = 0;
    m_audio_flip_channels_isSet = false;
    dsb = 0;
    m_dsb_isSet = false;
    audio_mute = 0;
    m_audio_mute_isSet = false;
    agc = 0;
    m_agc_isSet = false;
    agc_clamping = 0;
    m_agc_clamping_isSet = false;
    agc_time_log2 = 0;
    m_agc_time_log2_isSet = false;
    agc_power_threshold = 0;
    m_agc_power_threshold_isSet = false;
    agc_threshold_gate = 0;
    m_agc_threshold_gate_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    audio_device_name = new QString("");
    m_audio_device_name_isSet = false;
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
SWGSSBDemodSettings::cleanup() {















    if(title != nullptr) { 
        delete title;
    }
    if(audio_device_name != nullptr) { 
        delete audio_device_name;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGSSBDemodSettings*
SWGSSBDemodSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSSBDemodSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint64", "");
    
    ::SWGRPX100::setValue(&rf_bandwidth, pJson["rfBandwidth"], "float", "");
    
    ::SWGRPX100::setValue(&low_cutoff, pJson["lowCutoff"], "float", "");
    
    ::SWGRPX100::setValue(&volume, pJson["volume"], "float", "");
    
    ::SWGRPX100::setValue(&span_log2, pJson["spanLog2"], "qint32", "");
    
    ::SWGRPX100::setValue(&audio_binaural, pJson["audioBinaural"], "qint32", "");
    
    ::SWGRPX100::setValue(&audio_flip_channels, pJson["audioFlipChannels"], "qint32", "");
    
    ::SWGRPX100::setValue(&dsb, pJson["dsb"], "qint32", "");
    
    ::SWGRPX100::setValue(&audio_mute, pJson["audioMute"], "qint32", "");
    
    ::SWGRPX100::setValue(&agc, pJson["agc"], "qint32", "");
    
    ::SWGRPX100::setValue(&agc_clamping, pJson["agcClamping"], "qint32", "");
    
    ::SWGRPX100::setValue(&agc_time_log2, pJson["agcTimeLog2"], "qint32", "");
    
    ::SWGRPX100::setValue(&agc_power_threshold, pJson["agcPowerThreshold"], "qint32", "");
    
    ::SWGRPX100::setValue(&agc_threshold_gate, pJson["agcThresholdGate"], "qint32", "");
    
    ::SWGRPX100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGRPX100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGRPX100::setValue(&audio_device_name, pJson["audioDeviceName"], "QString", "QString");
    
    ::SWGRPX100::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGSSBDemodSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSSBDemodSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(m_rf_bandwidth_isSet){
        obj->insert("rfBandwidth", QJsonValue(rf_bandwidth));
    }
    if(m_low_cutoff_isSet){
        obj->insert("lowCutoff", QJsonValue(low_cutoff));
    }
    if(m_volume_isSet){
        obj->insert("volume", QJsonValue(volume));
    }
    if(m_span_log2_isSet){
        obj->insert("spanLog2", QJsonValue(span_log2));
    }
    if(m_audio_binaural_isSet){
        obj->insert("audioBinaural", QJsonValue(audio_binaural));
    }
    if(m_audio_flip_channels_isSet){
        obj->insert("audioFlipChannels", QJsonValue(audio_flip_channels));
    }
    if(m_dsb_isSet){
        obj->insert("dsb", QJsonValue(dsb));
    }
    if(m_audio_mute_isSet){
        obj->insert("audioMute", QJsonValue(audio_mute));
    }
    if(m_agc_isSet){
        obj->insert("agc", QJsonValue(agc));
    }
    if(m_agc_clamping_isSet){
        obj->insert("agcClamping", QJsonValue(agc_clamping));
    }
    if(m_agc_time_log2_isSet){
        obj->insert("agcTimeLog2", QJsonValue(agc_time_log2));
    }
    if(m_agc_power_threshold_isSet){
        obj->insert("agcPowerThreshold", QJsonValue(agc_power_threshold));
    }
    if(m_agc_threshold_gate_isSet){
        obj->insert("agcThresholdGate", QJsonValue(agc_threshold_gate));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(audio_device_name != nullptr && *audio_device_name != QString("")){
        toJsonValue(QString("audioDeviceName"), audio_device_name, obj, QString("QString"));
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

qint64
SWGSSBDemodSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGSSBDemodSettings::setInputFrequencyOffset(qint64 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

float
SWGSSBDemodSettings::getRfBandwidth() {
    return rf_bandwidth;
}
void
SWGSSBDemodSettings::setRfBandwidth(float rf_bandwidth) {
    this->rf_bandwidth = rf_bandwidth;
    this->m_rf_bandwidth_isSet = true;
}

float
SWGSSBDemodSettings::getLowCutoff() {
    return low_cutoff;
}
void
SWGSSBDemodSettings::setLowCutoff(float low_cutoff) {
    this->low_cutoff = low_cutoff;
    this->m_low_cutoff_isSet = true;
}

float
SWGSSBDemodSettings::getVolume() {
    return volume;
}
void
SWGSSBDemodSettings::setVolume(float volume) {
    this->volume = volume;
    this->m_volume_isSet = true;
}

qint32
SWGSSBDemodSettings::getSpanLog2() {
    return span_log2;
}
void
SWGSSBDemodSettings::setSpanLog2(qint32 span_log2) {
    this->span_log2 = span_log2;
    this->m_span_log2_isSet = true;
}

qint32
SWGSSBDemodSettings::getAudioBinaural() {
    return audio_binaural;
}
void
SWGSSBDemodSettings::setAudioBinaural(qint32 audio_binaural) {
    this->audio_binaural = audio_binaural;
    this->m_audio_binaural_isSet = true;
}

qint32
SWGSSBDemodSettings::getAudioFlipChannels() {
    return audio_flip_channels;
}
void
SWGSSBDemodSettings::setAudioFlipChannels(qint32 audio_flip_channels) {
    this->audio_flip_channels = audio_flip_channels;
    this->m_audio_flip_channels_isSet = true;
}

qint32
SWGSSBDemodSettings::getDsb() {
    return dsb;
}
void
SWGSSBDemodSettings::setDsb(qint32 dsb) {
    this->dsb = dsb;
    this->m_dsb_isSet = true;
}

qint32
SWGSSBDemodSettings::getAudioMute() {
    return audio_mute;
}
void
SWGSSBDemodSettings::setAudioMute(qint32 audio_mute) {
    this->audio_mute = audio_mute;
    this->m_audio_mute_isSet = true;
}

qint32
SWGSSBDemodSettings::getAgc() {
    return agc;
}
void
SWGSSBDemodSettings::setAgc(qint32 agc) {
    this->agc = agc;
    this->m_agc_isSet = true;
}

qint32
SWGSSBDemodSettings::getAgcClamping() {
    return agc_clamping;
}
void
SWGSSBDemodSettings::setAgcClamping(qint32 agc_clamping) {
    this->agc_clamping = agc_clamping;
    this->m_agc_clamping_isSet = true;
}

qint32
SWGSSBDemodSettings::getAgcTimeLog2() {
    return agc_time_log2;
}
void
SWGSSBDemodSettings::setAgcTimeLog2(qint32 agc_time_log2) {
    this->agc_time_log2 = agc_time_log2;
    this->m_agc_time_log2_isSet = true;
}

qint32
SWGSSBDemodSettings::getAgcPowerThreshold() {
    return agc_power_threshold;
}
void
SWGSSBDemodSettings::setAgcPowerThreshold(qint32 agc_power_threshold) {
    this->agc_power_threshold = agc_power_threshold;
    this->m_agc_power_threshold_isSet = true;
}

qint32
SWGSSBDemodSettings::getAgcThresholdGate() {
    return agc_threshold_gate;
}
void
SWGSSBDemodSettings::setAgcThresholdGate(qint32 agc_threshold_gate) {
    this->agc_threshold_gate = agc_threshold_gate;
    this->m_agc_threshold_gate_isSet = true;
}

qint32
SWGSSBDemodSettings::getRgbColor() {
    return rgb_color;
}
void
SWGSSBDemodSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGSSBDemodSettings::getTitle() {
    return title;
}
void
SWGSSBDemodSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

QString*
SWGSSBDemodSettings::getAudioDeviceName() {
    return audio_device_name;
}
void
SWGSSBDemodSettings::setAudioDeviceName(QString* audio_device_name) {
    this->audio_device_name = audio_device_name;
    this->m_audio_device_name_isSet = true;
}

qint32
SWGSSBDemodSettings::getStreamIndex() {
    return stream_index;
}
void
SWGSSBDemodSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGSSBDemodSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGSSBDemodSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGSSBDemodSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGSSBDemodSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGSSBDemodSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGSSBDemodSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGSSBDemodSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGSSBDemodSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGSSBDemodSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGSSBDemodSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGSSBDemodSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rf_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_low_cutoff_isSet){
            isObjectUpdated = true; break;
        }
        if(m_volume_isSet){
            isObjectUpdated = true; break;
        }
        if(m_span_log2_isSet){
            isObjectUpdated = true; break;
        }
        if(m_audio_binaural_isSet){
            isObjectUpdated = true; break;
        }
        if(m_audio_flip_channels_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dsb_isSet){
            isObjectUpdated = true; break;
        }
        if(m_audio_mute_isSet){
            isObjectUpdated = true; break;
        }
        if(m_agc_isSet){
            isObjectUpdated = true; break;
        }
        if(m_agc_clamping_isSet){
            isObjectUpdated = true; break;
        }
        if(m_agc_time_log2_isSet){
            isObjectUpdated = true; break;
        }
        if(m_agc_power_threshold_isSet){
            isObjectUpdated = true; break;
        }
        if(m_agc_threshold_gate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(audio_device_name && *audio_device_name != QString("")){
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

