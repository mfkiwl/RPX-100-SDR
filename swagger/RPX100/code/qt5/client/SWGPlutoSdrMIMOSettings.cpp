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


#include "SWGPlutoSdrMIMOSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGPlutoSdrMIMOSettings::SWGPlutoSdrMIMOSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlutoSdrMIMOSettings::SWGPlutoSdrMIMOSettings() {
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    rx_center_frequency = 0L;
    m_rx_center_frequency_isSet = false;
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
    fc_pos_rx = 0;
    m_fc_pos_rx_isSet = false;
    rx_transverter_mode = 0;
    m_rx_transverter_mode_isSet = false;
    rx_transverter_delta_frequency = 0L;
    m_rx_transverter_delta_frequency_isSet = false;
    iq_order = 0;
    m_iq_order_isSet = false;
    lpf_bw_rx = 0;
    m_lpf_bw_rx_isSet = false;
    lpf_rx_fir_enable = 0;
    m_lpf_rx_fir_enable_isSet = false;
    lpf_rx_firbw = 0;
    m_lpf_rx_firbw_isSet = false;
    lpf_rx_fi_rlog2_decim = 0;
    m_lpf_rx_fi_rlog2_decim_isSet = false;
    lpf_rx_fir_gain = 0;
    m_lpf_rx_fir_gain_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    rx0_gain = 0;
    m_rx0_gain_isSet = false;
    rx0_gain_mode = 0;
    m_rx0_gain_mode_isSet = false;
    rx0_antenna_path = 0;
    m_rx0_antenna_path_isSet = false;
    rx1_gain = 0;
    m_rx1_gain_isSet = false;
    rx1_gain_mode = 0;
    m_rx1_gain_mode_isSet = false;
    rx1_antenna_path = 0;
    m_rx1_antenna_path_isSet = false;
    tx_center_frequency = 0L;
    m_tx_center_frequency_isSet = false;
    fc_pos_tx = 0;
    m_fc_pos_tx_isSet = false;
    tx_transverter_mode = 0;
    m_tx_transverter_mode_isSet = false;
    tx_transverter_delta_frequency = 0L;
    m_tx_transverter_delta_frequency_isSet = false;
    lpf_bw_tx = 0;
    m_lpf_bw_tx_isSet = false;
    lpf_tx_fir_enable = 0;
    m_lpf_tx_fir_enable_isSet = false;
    lpf_tx_firbw = 0;
    m_lpf_tx_firbw_isSet = false;
    lpf_tx_fi_rlog2_interp = 0;
    m_lpf_tx_fi_rlog2_interp_isSet = false;
    lpf_tx_fir_gain = 0;
    m_lpf_tx_fir_gain_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    tx0_att = 0;
    m_tx0_att_isSet = false;
    tx0_antenna_path = 0;
    m_tx0_antenna_path_isSet = false;
    tx1_att = 0;
    m_tx1_att_isSet = false;
    tx1_antenna_path = 0;
    m_tx1_antenna_path_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGPlutoSdrMIMOSettings::~SWGPlutoSdrMIMOSettings() {
    this->cleanup();
}

void
SWGPlutoSdrMIMOSettings::init() {
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    rx_center_frequency = 0L;
    m_rx_center_frequency_isSet = false;
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
    fc_pos_rx = 0;
    m_fc_pos_rx_isSet = false;
    rx_transverter_mode = 0;
    m_rx_transverter_mode_isSet = false;
    rx_transverter_delta_frequency = 0L;
    m_rx_transverter_delta_frequency_isSet = false;
    iq_order = 0;
    m_iq_order_isSet = false;
    lpf_bw_rx = 0;
    m_lpf_bw_rx_isSet = false;
    lpf_rx_fir_enable = 0;
    m_lpf_rx_fir_enable_isSet = false;
    lpf_rx_firbw = 0;
    m_lpf_rx_firbw_isSet = false;
    lpf_rx_fi_rlog2_decim = 0;
    m_lpf_rx_fi_rlog2_decim_isSet = false;
    lpf_rx_fir_gain = 0;
    m_lpf_rx_fir_gain_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    rx0_gain = 0;
    m_rx0_gain_isSet = false;
    rx0_gain_mode = 0;
    m_rx0_gain_mode_isSet = false;
    rx0_antenna_path = 0;
    m_rx0_antenna_path_isSet = false;
    rx1_gain = 0;
    m_rx1_gain_isSet = false;
    rx1_gain_mode = 0;
    m_rx1_gain_mode_isSet = false;
    rx1_antenna_path = 0;
    m_rx1_antenna_path_isSet = false;
    tx_center_frequency = 0L;
    m_tx_center_frequency_isSet = false;
    fc_pos_tx = 0;
    m_fc_pos_tx_isSet = false;
    tx_transverter_mode = 0;
    m_tx_transverter_mode_isSet = false;
    tx_transverter_delta_frequency = 0L;
    m_tx_transverter_delta_frequency_isSet = false;
    lpf_bw_tx = 0;
    m_lpf_bw_tx_isSet = false;
    lpf_tx_fir_enable = 0;
    m_lpf_tx_fir_enable_isSet = false;
    lpf_tx_firbw = 0;
    m_lpf_tx_firbw_isSet = false;
    lpf_tx_fi_rlog2_interp = 0;
    m_lpf_tx_fi_rlog2_interp_isSet = false;
    lpf_tx_fir_gain = 0;
    m_lpf_tx_fir_gain_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    tx0_att = 0;
    m_tx0_att_isSet = false;
    tx0_antenna_path = 0;
    m_tx0_antenna_path_isSet = false;
    tx1_att = 0;
    m_tx1_att_isSet = false;
    tx1_antenna_path = 0;
    m_tx1_antenna_path_isSet = false;
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
SWGPlutoSdrMIMOSettings::cleanup() {







































    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGPlutoSdrMIMOSettings*
SWGPlutoSdrMIMOSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlutoSdrMIMOSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGRPX100::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx_center_frequency, pJson["rxCenterFrequency"], "qint64", "");
    
    ::SWGRPX100::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGRPX100::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGRPX100::setValue(&hw_bbdc_block, pJson["hwBBDCBlock"], "qint32", "");
    
    ::SWGRPX100::setValue(&hw_rfdc_block, pJson["hwRFDCBlock"], "qint32", "");
    
    ::SWGRPX100::setValue(&hw_iq_correction, pJson["hwIQCorrection"], "qint32", "");
    
    ::SWGRPX100::setValue(&fc_pos_rx, pJson["fcPosRx"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx_transverter_mode, pJson["rxTransverterMode"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx_transverter_delta_frequency, pJson["rxTransverterDeltaFrequency"], "qint64", "");
    
    ::SWGRPX100::setValue(&iq_order, pJson["iqOrder"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_bw_rx, pJson["lpfBWRx"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_rx_fir_enable, pJson["lpfRxFIREnable"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_rx_firbw, pJson["lpfRxFIRBW"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_rx_fi_rlog2_decim, pJson["lpfRxFIRlog2Decim"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_rx_fir_gain, pJson["lpfRxFIRGain"], "qint32", "");
    
    ::SWGRPX100::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx0_gain, pJson["rx0Gain"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx0_gain_mode, pJson["rx0GainMode"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx0_antenna_path, pJson["rx0AntennaPath"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx1_gain, pJson["rx1Gain"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx1_gain_mode, pJson["rx1GainMode"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx1_antenna_path, pJson["rx1AntennaPath"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx_center_frequency, pJson["txCenterFrequency"], "qint64", "");
    
    ::SWGRPX100::setValue(&fc_pos_tx, pJson["fcPosTx"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx_transverter_mode, pJson["txTransverterMode"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx_transverter_delta_frequency, pJson["txTransverterDeltaFrequency"], "qint64", "");
    
    ::SWGRPX100::setValue(&lpf_bw_tx, pJson["lpfBWTx"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_tx_fir_enable, pJson["lpfTxFIREnable"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_tx_firbw, pJson["lpfTxFIRBW"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_tx_fi_rlog2_interp, pJson["lpfTxFIRlog2Interp"], "qint32", "");
    
    ::SWGRPX100::setValue(&lpf_tx_fir_gain, pJson["lpfTxFIRGain"], "qint32", "");
    
    ::SWGRPX100::setValue(&log2_interp, pJson["log2Interp"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx0_att, pJson["tx0Att"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx0_antenna_path, pJson["tx0AntennaPath"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx1_att, pJson["tx1Att"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx1_antenna_path, pJson["tx1AntennaPath"], "qint32", "");
    
    ::SWGRPX100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGPlutoSdrMIMOSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPlutoSdrMIMOSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_rx_center_frequency_isSet){
        obj->insert("rxCenterFrequency", QJsonValue(rx_center_frequency));
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
    if(m_fc_pos_rx_isSet){
        obj->insert("fcPosRx", QJsonValue(fc_pos_rx));
    }
    if(m_rx_transverter_mode_isSet){
        obj->insert("rxTransverterMode", QJsonValue(rx_transverter_mode));
    }
    if(m_rx_transverter_delta_frequency_isSet){
        obj->insert("rxTransverterDeltaFrequency", QJsonValue(rx_transverter_delta_frequency));
    }
    if(m_iq_order_isSet){
        obj->insert("iqOrder", QJsonValue(iq_order));
    }
    if(m_lpf_bw_rx_isSet){
        obj->insert("lpfBWRx", QJsonValue(lpf_bw_rx));
    }
    if(m_lpf_rx_fir_enable_isSet){
        obj->insert("lpfRxFIREnable", QJsonValue(lpf_rx_fir_enable));
    }
    if(m_lpf_rx_firbw_isSet){
        obj->insert("lpfRxFIRBW", QJsonValue(lpf_rx_firbw));
    }
    if(m_lpf_rx_fi_rlog2_decim_isSet){
        obj->insert("lpfRxFIRlog2Decim", QJsonValue(lpf_rx_fi_rlog2_decim));
    }
    if(m_lpf_rx_fir_gain_isSet){
        obj->insert("lpfRxFIRGain", QJsonValue(lpf_rx_fir_gain));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_rx0_gain_isSet){
        obj->insert("rx0Gain", QJsonValue(rx0_gain));
    }
    if(m_rx0_gain_mode_isSet){
        obj->insert("rx0GainMode", QJsonValue(rx0_gain_mode));
    }
    if(m_rx0_antenna_path_isSet){
        obj->insert("rx0AntennaPath", QJsonValue(rx0_antenna_path));
    }
    if(m_rx1_gain_isSet){
        obj->insert("rx1Gain", QJsonValue(rx1_gain));
    }
    if(m_rx1_gain_mode_isSet){
        obj->insert("rx1GainMode", QJsonValue(rx1_gain_mode));
    }
    if(m_rx1_antenna_path_isSet){
        obj->insert("rx1AntennaPath", QJsonValue(rx1_antenna_path));
    }
    if(m_tx_center_frequency_isSet){
        obj->insert("txCenterFrequency", QJsonValue(tx_center_frequency));
    }
    if(m_fc_pos_tx_isSet){
        obj->insert("fcPosTx", QJsonValue(fc_pos_tx));
    }
    if(m_tx_transverter_mode_isSet){
        obj->insert("txTransverterMode", QJsonValue(tx_transverter_mode));
    }
    if(m_tx_transverter_delta_frequency_isSet){
        obj->insert("txTransverterDeltaFrequency", QJsonValue(tx_transverter_delta_frequency));
    }
    if(m_lpf_bw_tx_isSet){
        obj->insert("lpfBWTx", QJsonValue(lpf_bw_tx));
    }
    if(m_lpf_tx_fir_enable_isSet){
        obj->insert("lpfTxFIREnable", QJsonValue(lpf_tx_fir_enable));
    }
    if(m_lpf_tx_firbw_isSet){
        obj->insert("lpfTxFIRBW", QJsonValue(lpf_tx_firbw));
    }
    if(m_lpf_tx_fi_rlog2_interp_isSet){
        obj->insert("lpfTxFIRlog2Interp", QJsonValue(lpf_tx_fi_rlog2_interp));
    }
    if(m_lpf_tx_fir_gain_isSet){
        obj->insert("lpfTxFIRGain", QJsonValue(lpf_tx_fir_gain));
    }
    if(m_log2_interp_isSet){
        obj->insert("log2Interp", QJsonValue(log2_interp));
    }
    if(m_tx0_att_isSet){
        obj->insert("tx0Att", QJsonValue(tx0_att));
    }
    if(m_tx0_antenna_path_isSet){
        obj->insert("tx0AntennaPath", QJsonValue(tx0_antenna_path));
    }
    if(m_tx1_att_isSet){
        obj->insert("tx1Att", QJsonValue(tx1_att));
    }
    if(m_tx1_antenna_path_isSet){
        obj->insert("tx1AntennaPath", QJsonValue(tx1_antenna_path));
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

qint32
SWGPlutoSdrMIMOSettings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGPlutoSdrMIMOSettings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGPlutoSdrMIMOSettings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint64
SWGPlutoSdrMIMOSettings::getRxCenterFrequency() {
    return rx_center_frequency;
}
void
SWGPlutoSdrMIMOSettings::setRxCenterFrequency(qint64 rx_center_frequency) {
    this->rx_center_frequency = rx_center_frequency;
    this->m_rx_center_frequency_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getDcBlock() {
    return dc_block;
}
void
SWGPlutoSdrMIMOSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getIqCorrection() {
    return iq_correction;
}
void
SWGPlutoSdrMIMOSettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getHwBbdcBlock() {
    return hw_bbdc_block;
}
void
SWGPlutoSdrMIMOSettings::setHwBbdcBlock(qint32 hw_bbdc_block) {
    this->hw_bbdc_block = hw_bbdc_block;
    this->m_hw_bbdc_block_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getHwRfdcBlock() {
    return hw_rfdc_block;
}
void
SWGPlutoSdrMIMOSettings::setHwRfdcBlock(qint32 hw_rfdc_block) {
    this->hw_rfdc_block = hw_rfdc_block;
    this->m_hw_rfdc_block_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getHwIqCorrection() {
    return hw_iq_correction;
}
void
SWGPlutoSdrMIMOSettings::setHwIqCorrection(qint32 hw_iq_correction) {
    this->hw_iq_correction = hw_iq_correction;
    this->m_hw_iq_correction_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getFcPosRx() {
    return fc_pos_rx;
}
void
SWGPlutoSdrMIMOSettings::setFcPosRx(qint32 fc_pos_rx) {
    this->fc_pos_rx = fc_pos_rx;
    this->m_fc_pos_rx_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRxTransverterMode() {
    return rx_transverter_mode;
}
void
SWGPlutoSdrMIMOSettings::setRxTransverterMode(qint32 rx_transverter_mode) {
    this->rx_transverter_mode = rx_transverter_mode;
    this->m_rx_transverter_mode_isSet = true;
}

qint64
SWGPlutoSdrMIMOSettings::getRxTransverterDeltaFrequency() {
    return rx_transverter_delta_frequency;
}
void
SWGPlutoSdrMIMOSettings::setRxTransverterDeltaFrequency(qint64 rx_transverter_delta_frequency) {
    this->rx_transverter_delta_frequency = rx_transverter_delta_frequency;
    this->m_rx_transverter_delta_frequency_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getIqOrder() {
    return iq_order;
}
void
SWGPlutoSdrMIMOSettings::setIqOrder(qint32 iq_order) {
    this->iq_order = iq_order;
    this->m_iq_order_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfBwRx() {
    return lpf_bw_rx;
}
void
SWGPlutoSdrMIMOSettings::setLpfBwRx(qint32 lpf_bw_rx) {
    this->lpf_bw_rx = lpf_bw_rx;
    this->m_lpf_bw_rx_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfRxFirEnable() {
    return lpf_rx_fir_enable;
}
void
SWGPlutoSdrMIMOSettings::setLpfRxFirEnable(qint32 lpf_rx_fir_enable) {
    this->lpf_rx_fir_enable = lpf_rx_fir_enable;
    this->m_lpf_rx_fir_enable_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfRxFirbw() {
    return lpf_rx_firbw;
}
void
SWGPlutoSdrMIMOSettings::setLpfRxFirbw(qint32 lpf_rx_firbw) {
    this->lpf_rx_firbw = lpf_rx_firbw;
    this->m_lpf_rx_firbw_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfRxFiRlog2Decim() {
    return lpf_rx_fi_rlog2_decim;
}
void
SWGPlutoSdrMIMOSettings::setLpfRxFiRlog2Decim(qint32 lpf_rx_fi_rlog2_decim) {
    this->lpf_rx_fi_rlog2_decim = lpf_rx_fi_rlog2_decim;
    this->m_lpf_rx_fi_rlog2_decim_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfRxFirGain() {
    return lpf_rx_fir_gain;
}
void
SWGPlutoSdrMIMOSettings::setLpfRxFirGain(qint32 lpf_rx_fir_gain) {
    this->lpf_rx_fir_gain = lpf_rx_fir_gain;
    this->m_lpf_rx_fir_gain_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLog2Decim() {
    return log2_decim;
}
void
SWGPlutoSdrMIMOSettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRx0Gain() {
    return rx0_gain;
}
void
SWGPlutoSdrMIMOSettings::setRx0Gain(qint32 rx0_gain) {
    this->rx0_gain = rx0_gain;
    this->m_rx0_gain_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRx0GainMode() {
    return rx0_gain_mode;
}
void
SWGPlutoSdrMIMOSettings::setRx0GainMode(qint32 rx0_gain_mode) {
    this->rx0_gain_mode = rx0_gain_mode;
    this->m_rx0_gain_mode_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRx0AntennaPath() {
    return rx0_antenna_path;
}
void
SWGPlutoSdrMIMOSettings::setRx0AntennaPath(qint32 rx0_antenna_path) {
    this->rx0_antenna_path = rx0_antenna_path;
    this->m_rx0_antenna_path_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRx1Gain() {
    return rx1_gain;
}
void
SWGPlutoSdrMIMOSettings::setRx1Gain(qint32 rx1_gain) {
    this->rx1_gain = rx1_gain;
    this->m_rx1_gain_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRx1GainMode() {
    return rx1_gain_mode;
}
void
SWGPlutoSdrMIMOSettings::setRx1GainMode(qint32 rx1_gain_mode) {
    this->rx1_gain_mode = rx1_gain_mode;
    this->m_rx1_gain_mode_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getRx1AntennaPath() {
    return rx1_antenna_path;
}
void
SWGPlutoSdrMIMOSettings::setRx1AntennaPath(qint32 rx1_antenna_path) {
    this->rx1_antenna_path = rx1_antenna_path;
    this->m_rx1_antenna_path_isSet = true;
}

qint64
SWGPlutoSdrMIMOSettings::getTxCenterFrequency() {
    return tx_center_frequency;
}
void
SWGPlutoSdrMIMOSettings::setTxCenterFrequency(qint64 tx_center_frequency) {
    this->tx_center_frequency = tx_center_frequency;
    this->m_tx_center_frequency_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getFcPosTx() {
    return fc_pos_tx;
}
void
SWGPlutoSdrMIMOSettings::setFcPosTx(qint32 fc_pos_tx) {
    this->fc_pos_tx = fc_pos_tx;
    this->m_fc_pos_tx_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getTxTransverterMode() {
    return tx_transverter_mode;
}
void
SWGPlutoSdrMIMOSettings::setTxTransverterMode(qint32 tx_transverter_mode) {
    this->tx_transverter_mode = tx_transverter_mode;
    this->m_tx_transverter_mode_isSet = true;
}

qint64
SWGPlutoSdrMIMOSettings::getTxTransverterDeltaFrequency() {
    return tx_transverter_delta_frequency;
}
void
SWGPlutoSdrMIMOSettings::setTxTransverterDeltaFrequency(qint64 tx_transverter_delta_frequency) {
    this->tx_transverter_delta_frequency = tx_transverter_delta_frequency;
    this->m_tx_transverter_delta_frequency_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfBwTx() {
    return lpf_bw_tx;
}
void
SWGPlutoSdrMIMOSettings::setLpfBwTx(qint32 lpf_bw_tx) {
    this->lpf_bw_tx = lpf_bw_tx;
    this->m_lpf_bw_tx_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfTxFirEnable() {
    return lpf_tx_fir_enable;
}
void
SWGPlutoSdrMIMOSettings::setLpfTxFirEnable(qint32 lpf_tx_fir_enable) {
    this->lpf_tx_fir_enable = lpf_tx_fir_enable;
    this->m_lpf_tx_fir_enable_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfTxFirbw() {
    return lpf_tx_firbw;
}
void
SWGPlutoSdrMIMOSettings::setLpfTxFirbw(qint32 lpf_tx_firbw) {
    this->lpf_tx_firbw = lpf_tx_firbw;
    this->m_lpf_tx_firbw_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfTxFiRlog2Interp() {
    return lpf_tx_fi_rlog2_interp;
}
void
SWGPlutoSdrMIMOSettings::setLpfTxFiRlog2Interp(qint32 lpf_tx_fi_rlog2_interp) {
    this->lpf_tx_fi_rlog2_interp = lpf_tx_fi_rlog2_interp;
    this->m_lpf_tx_fi_rlog2_interp_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLpfTxFirGain() {
    return lpf_tx_fir_gain;
}
void
SWGPlutoSdrMIMOSettings::setLpfTxFirGain(qint32 lpf_tx_fir_gain) {
    this->lpf_tx_fir_gain = lpf_tx_fir_gain;
    this->m_lpf_tx_fir_gain_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getLog2Interp() {
    return log2_interp;
}
void
SWGPlutoSdrMIMOSettings::setLog2Interp(qint32 log2_interp) {
    this->log2_interp = log2_interp;
    this->m_log2_interp_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getTx0Att() {
    return tx0_att;
}
void
SWGPlutoSdrMIMOSettings::setTx0Att(qint32 tx0_att) {
    this->tx0_att = tx0_att;
    this->m_tx0_att_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getTx0AntennaPath() {
    return tx0_antenna_path;
}
void
SWGPlutoSdrMIMOSettings::setTx0AntennaPath(qint32 tx0_antenna_path) {
    this->tx0_antenna_path = tx0_antenna_path;
    this->m_tx0_antenna_path_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getTx1Att() {
    return tx1_att;
}
void
SWGPlutoSdrMIMOSettings::setTx1Att(qint32 tx1_att) {
    this->tx1_att = tx1_att;
    this->m_tx1_att_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getTx1AntennaPath() {
    return tx1_antenna_path;
}
void
SWGPlutoSdrMIMOSettings::setTx1AntennaPath(qint32 tx1_antenna_path) {
    this->tx1_antenna_path = tx1_antenna_path;
    this->m_tx1_antenna_path_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGPlutoSdrMIMOSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGPlutoSdrMIMOSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGPlutoSdrMIMOSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGPlutoSdrMIMOSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGPlutoSdrMIMOSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGPlutoSdrMIMOSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGPlutoSdrMIMOSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_dev_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_l_oppm_tenths_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_center_frequency_isSet){
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
        if(m_fc_pos_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_order_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_bw_rx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_rx_fir_enable_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_rx_firbw_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_rx_fi_rlog2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_rx_fir_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx0_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx0_gain_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx0_antenna_path_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx1_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx1_gain_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx1_antenna_path_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fc_pos_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_bw_tx_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_tx_fir_enable_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_tx_firbw_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_tx_fi_rlog2_interp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lpf_tx_fir_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_interp_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx0_att_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx0_antenna_path_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx1_att_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx1_antenna_path_isSet){
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

