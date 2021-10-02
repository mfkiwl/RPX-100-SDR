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


#include "SWGPlutoSdrInputSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGrpx-100 {

SWGPlutoSdrInputSettings::SWGPlutoSdrInputSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlutoSdrInputSettings::SWGPlutoSdrInputSettings() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    lpf_fir_enable = 0;
    m_lpf_fir_enable_isSet = false;
    lpf_firbw = 0;
    m_lpf_firbw_isSet = false;
    lpf_fi_rlog2_decim = 0;
    m_lpf_fi_rlog2_decim_isSet = false;
    lpf_fir_gain = 0;
    m_lpf_fir_gain_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    hw_bbdc_block = 0;
    m_hw_bbdc_block_isSet = false;
    hw_rfdc_block = 0;
    m_hw_rfdc_block_isSet = false;
    hw_iq_correction = 0;
    m_hw_iq_correction_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    lpf_bw = 0;
    m_lpf_bw_isSet = false;
    gain = 0;
    m_gain_isSet = false;
    antenna_path = 0;
    m_antenna_path_isSet = false;
    gain_mode = 0;
    m_gain_mode_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    iq_order = 0;
    m_iq_order_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGPlutoSdrInputSettings::~SWGPlutoSdrInputSettings() {
    this->cleanup();
}

void
SWGPlutoSdrInputSettings::init() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    lpf_fir_enable = 0;
    m_lpf_fir_enable_isSet = false;
    lpf_firbw = 0;
    m_lpf_firbw_isSet = false;
    lpf_fi_rlog2_decim = 0;
    m_lpf_fi_rlog2_decim_isSet = false;
    lpf_fir_gain = 0;
    m_lpf_fir_gain_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    hw_bbdc_block = 0;
    m_hw_bbdc_block_isSet = false;
    hw_rfdc_block = 0;
    m_hw_rfdc_block_isSet = false;
    hw_iq_correction = 0;
    m_hw_iq_correction_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    lpf_bw = 0;
    m_lpf_bw_isSet = false;
    gain = 0;
    m_gain_isSet = false;
    antenna_path = 0;
    m_antenna_path_isSet = false;
    gain_mode = 0;
    m_gain_mode_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    iq_order = 0;
    m_iq_order_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGPlutoSdrInputSettings::cleanup() {






















    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGPlutoSdrInputSettings*
SWGPlutoSdrInputSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlutoSdrInputSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGrpx-100::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGrpx-100::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGrpx-100::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGrpx-100::setValue(&lpf_fir_enable, pJson["lpfFIREnable"], "qint32", "");
    
    ::SWGrpx-100::setValue(&lpf_firbw, pJson["lpfFIRBW"], "qint32", "");
    
    ::SWGrpx-100::setValue(&lpf_fi_rlog2_decim, pJson["lpfFIRlog2Decim"], "qint32", "");
    
    ::SWGrpx-100::setValue(&lpf_fir_gain, pJson["lpfFIRGain"], "qint32", "");
    
    ::SWGrpx-100::setValue(&fc_pos, pJson["fcPos"], "qint32", "");
    
    ::SWGrpx-100::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGrpx-100::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGrpx-100::setValue(&hw_bbdc_block, pJson["hwBBDCBlock"], "qint32", "");
    
    ::SWGrpx-100::setValue(&hw_rfdc_block, pJson["hwRFDCBlock"], "qint32", "");
    
    ::SWGrpx-100::setValue(&hw_iq_correction, pJson["hwIQCorrection"], "qint32", "");
    
    ::SWGrpx-100::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGrpx-100::setValue(&lpf_bw, pJson["lpfBW"], "qint32", "");
    
    ::SWGrpx-100::setValue(&gain, pJson["gain"], "qint32", "");
    
    ::SWGrpx-100::setValue(&antenna_path, pJson["antennaPath"], "qint32", "");
    
    ::SWGrpx-100::setValue(&gain_mode, pJson["gainMode"], "qint32", "");
    
    ::SWGrpx-100::setValue(&transverter_mode, pJson["transverterMode"], "qint32", "");
    
    ::SWGrpx-100::setValue(&transverter_delta_frequency, pJson["transverterDeltaFrequency"], "qint64", "");
    
    ::SWGrpx-100::setValue(&iq_order, pJson["iqOrder"], "qint32", "");
    
    ::SWGrpx-100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGrpx-100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGrpx-100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGPlutoSdrInputSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPlutoSdrInputSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_lpf_fir_enable_isSet){
        obj->insert("lpfFIREnable", QJsonValue(lpf_fir_enable));
    }
    if(m_lpf_firbw_isSet){
        obj->insert("lpfFIRBW", QJsonValue(lpf_firbw));
    }
    if(m_lpf_fi_rlog2_decim_isSet){
        obj->insert("lpfFIRlog2Decim", QJsonValue(lpf_fi_rlog2_decim));
    }
    if(m_lpf_fir_gain_isSet){
        obj->insert("lpfFIRGain", QJsonValue(lpf_fir_gain));
    }
    if(m_fc_pos_isSet){
        obj->insert("fcPos", QJsonValue(fc_pos));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
    }
    if(m_hw_bbdc_block_isSet){
        obj->insert("hwBBDCBlock", QJsonValue(hw_bbdc_block));
    }
    if(m_hw_rfdc_block_isSet){
        obj->insert("hwRFDCBlock", QJsonValue(hw_rfdc_block));
    }
    if(m_hw_iq_correction_isSet){
        obj->insert("hwIQCorrection", QJsonValue(hw_iq_correction));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_lpf_bw_isSet){
        obj->insert("lpfBW", QJsonValue(lpf_bw));
    }
    if(m_gain_isSet){
        obj->insert("gain", QJsonValue(gain));
    }
    if(m_antenna_path_isSet){
        obj->insert("antennaPath", QJsonValue(antenna_path));
    }
    if(m_gain_mode_isSet){
        obj->insert("gainMode", QJsonValue(gain_mode));
    }
    if(m_transverter_mode_isSet){
        obj->insert("transverterMode", QJsonValue(transverter_mode));
    }
    if(m_transverter_delta_frequency_isSet){
        obj->insert("transverterDeltaFrequency", QJsonValue(transverter_delta_frequency));
    }
    if(m_iq_order_isSet){
        obj->insert("iqOrder", QJsonValue(iq_order));
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

    return obj;
}

qint64
SWGPlutoSdrInputSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGPlutoSdrInputSettings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGPlutoSdrInputSettings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGPlutoSdrInputSettings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLpfFirEnable() {
    return lpf_fir_enable;
}
void
SWGPlutoSdrInputSettings::setLpfFirEnable(qint32 lpf_fir_enable) {
    this->lpf_fir_enable = lpf_fir_enable;
    this->m_lpf_fir_enable_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLpfFirbw() {
    return lpf_firbw;
}
void
SWGPlutoSdrInputSettings::setLpfFirbw(qint32 lpf_firbw) {
    this->lpf_firbw = lpf_firbw;
    this->m_lpf_firbw_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLpfFiRlog2Decim() {
    return lpf_fi_rlog2_decim;
}
void
SWGPlutoSdrInputSettings::setLpfFiRlog2Decim(qint32 lpf_fi_rlog2_decim) {
    this->lpf_fi_rlog2_decim = lpf_fi_rlog2_decim;
    this->m_lpf_fi_rlog2_decim_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLpfFirGain() {
    return lpf_fir_gain;
}
void
SWGPlutoSdrInputSettings::setLpfFirGain(qint32 lpf_fir_gain) {
    this->lpf_fir_gain = lpf_fir_gain;
    this->m_lpf_fir_gain_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getFcPos() {
    return fc_pos;
}
void
SWGPlutoSdrInputSettings::setFcPos(qint32 fc_pos) {
    this->fc_pos = fc_pos;
    this->m_fc_pos_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getDcBlock() {
    return dc_block;
}
void
SWGPlutoSdrInputSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getIqCorrection() {
    return iq_correction;
}
void
SWGPlutoSdrInputSettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getHwBbdcBlock() {
    return hw_bbdc_block;
}
void
SWGPlutoSdrInputSettings::setHwBbdcBlock(qint32 hw_bbdc_block) {
    this->hw_bbdc_block = hw_bbdc_block;
    this->m_hw_bbdc_block_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getHwRfdcBlock() {
    return hw_rfdc_block;
}
void
SWGPlutoSdrInputSettings::setHwRfdcBlock(qint32 hw_rfdc_block) {
    this->hw_rfdc_block = hw_rfdc_block;
    this->m_hw_rfdc_block_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getHwIqCorrection() {
    return hw_iq_correction;
}
void
SWGPlutoSdrInputSettings::setHwIqCorrection(qint32 hw_iq_correction) {
    this->hw_iq_correction = hw_iq_correction;
    this->m_hw_iq_correction_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGPlutoSdrInputSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getLpfBw() {
    return lpf_bw;
}
void
SWGPlutoSdrInputSettings::setLpfBw(qint32 lpf_bw) {
    this->lpf_bw = lpf_bw;
    this->m_lpf_bw_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getGain() {
    return gain;
}
void
SWGPlutoSdrInputSettings::setGain(qint32 gain) {
    this->gain = gain;
    this->m_gain_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getAntennaPath() {
    return antenna_path;
}
void
SWGPlutoSdrInputSettings::setAntennaPath(qint32 antenna_path) {
    this->antenna_path = antenna_path;
    this->m_antenna_path_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getGainMode() {
    return gain_mode;
}
void
SWGPlutoSdrInputSettings::setGainMode(qint32 gain_mode) {
    this->gain_mode = gain_mode;
    this->m_gain_mode_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getTransverterMode() {
    return transverter_mode;
}
void
SWGPlutoSdrInputSettings::setTransverterMode(qint32 transverter_mode) {
    this->transverter_mode = transverter_mode;
    this->m_transverter_mode_isSet = true;
}

qint64
SWGPlutoSdrInputSettings::getTransverterDeltaFrequency() {
    return transverter_delta_frequency;
}
void
SWGPlutoSdrInputSettings::setTransverterDeltaFrequency(qint64 transverter_delta_frequency) {
    this->transverter_delta_frequency = transverter_delta_frequency;
    this->m_transverter_delta_frequency_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getIqOrder() {
    return iq_order;
}
void
SWGPlutoSdrInputSettings::setIqOrder(qint32 iq_order) {
    this->iq_order = iq_order;
    this->m_iq_order_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGPlutoSdrInputSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGPlutoSdrInputSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGPlutoSdrInputSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGPlutoSdrInputSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGPlutoSdrInputSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGPlutoSdrInputSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGPlutoSdrInputSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dev_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_l_oppm_tenths_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_fir_enable_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_firbw_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_fi_rlog2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_fir_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fc_pos_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_correction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_hw_bbdc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_hw_rfdc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_hw_iq_correction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_bw_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_antenna_path_isSet){
            isObjectUpdated = true; break;
        }
        if(m_gain_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_order_isSet){
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
    }while(false);
    return isObjectUpdated;
}
}

