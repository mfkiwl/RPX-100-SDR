/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGDeviceReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGDeviceReport::SWGDeviceReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDeviceReport::SWGDeviceReport() {
    device_hw_type = nullptr;
    m_device_hw_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    airspy_report = nullptr;
    m_airspy_report_isSet = false;
    airspy_hf_report = nullptr;
    m_airspy_hf_report_isSet = false;
    blade_rf2_input_report = nullptr;
    m_blade_rf2_input_report_isSet = false;
    blade_rf2_output_report = nullptr;
    m_blade_rf2_output_report_isSet = false;
    blade_rf2_mimo_report = nullptr;
    m_blade_rf2_mimo_report_isSet = false;
    file_input_report = nullptr;
    m_file_input_report_isSet = false;
    kiwi_sdr_report = nullptr;
    m_kiwi_sdr_report_isSet = false;
    lime_sdr_input_report = nullptr;
    m_lime_sdr_input_report_isSet = false;
    lime_sdr_output_report = nullptr;
    m_lime_sdr_output_report_isSet = false;
    lime_sdr_mimo_report = nullptr;
    m_lime_sdr_mimo_report_isSet = false;
    local_input_report = nullptr;
    m_local_input_report_isSet = false;
    local_output_report = nullptr;
    m_local_output_report_isSet = false;
    perseus_report = nullptr;
    m_perseus_report_isSet = false;
    pluto_sdr_input_report = nullptr;
    m_pluto_sdr_input_report_isSet = false;
    pluto_sdr_output_report = nullptr;
    m_pluto_sdr_output_report_isSet = false;
    pluto_sdr_mimo_report = nullptr;
    m_pluto_sdr_mimo_report_isSet = false;
    rtl_sdr_report = nullptr;
    m_rtl_sdr_report_isSet = false;
    remote_output_report = nullptr;
    m_remote_output_report_isSet = false;
    remote_input_report = nullptr;
    m_remote_input_report_isSet = false;
    sdr_play_report = nullptr;
    m_sdr_play_report_isSet = false;
    sdr_play_v3_report = nullptr;
    m_sdr_play_v3_report_isSet = false;
    sig_mf_file_input_report = nullptr;
    m_sig_mf_file_input_report_isSet = false;
    soapy_sdr_input_report = nullptr;
    m_soapy_sdr_input_report_isSet = false;
    soapy_sdr_output_report = nullptr;
    m_soapy_sdr_output_report_isSet = false;
    usrp_input_report = nullptr;
    m_usrp_input_report_isSet = false;
    usrp_output_report = nullptr;
    m_usrp_output_report_isSet = false;
    xtrx_input_report = nullptr;
    m_xtrx_input_report_isSet = false;
    xtrx_output_report = nullptr;
    m_xtrx_output_report_isSet = false;
    xtrx_mimo_report = nullptr;
    m_xtrx_mimo_report_isSet = false;
}

SWGDeviceReport::~SWGDeviceReport() {
    this->cleanup();
}

void
SWGDeviceReport::init() {
    device_hw_type = new QString("");
    m_device_hw_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    airspy_report = new SWGAirspyReport();
    m_airspy_report_isSet = false;
    airspy_hf_report = new SWGAirspyHFReport();
    m_airspy_hf_report_isSet = false;
    blade_rf2_input_report = new SWGBladeRF2InputReport();
    m_blade_rf2_input_report_isSet = false;
    blade_rf2_output_report = new SWGBladeRF2OutputReport();
    m_blade_rf2_output_report_isSet = false;
    blade_rf2_mimo_report = new SWGBladeRF2MIMOReport();
    m_blade_rf2_mimo_report_isSet = false;
    file_input_report = new SWGFileInputReport();
    m_file_input_report_isSet = false;
    kiwi_sdr_report = new SWGKiwiSDRReport();
    m_kiwi_sdr_report_isSet = false;
    lime_sdr_input_report = new SWGLimeSdrInputReport();
    m_lime_sdr_input_report_isSet = false;
    lime_sdr_output_report = new SWGLimeSdrOutputReport();
    m_lime_sdr_output_report_isSet = false;
    lime_sdr_mimo_report = new SWGLimeSdrMIMOReport();
    m_lime_sdr_mimo_report_isSet = false;
    local_input_report = new SWGLocalInputReport();
    m_local_input_report_isSet = false;
    local_output_report = new SWGLocalOutputReport();
    m_local_output_report_isSet = false;
    perseus_report = new SWGPerseusReport();
    m_perseus_report_isSet = false;
    pluto_sdr_input_report = new SWGPlutoSdrInputReport();
    m_pluto_sdr_input_report_isSet = false;
    pluto_sdr_output_report = new SWGPlutoSdrOutputReport();
    m_pluto_sdr_output_report_isSet = false;
    pluto_sdr_mimo_report = new SWGPlutoSdrMIMOReport();
    m_pluto_sdr_mimo_report_isSet = false;
    rtl_sdr_report = new SWGRtlSdrReport();
    m_rtl_sdr_report_isSet = false;
    remote_output_report = new SWGRemoteOutputReport();
    m_remote_output_report_isSet = false;
    remote_input_report = new SWGRemoteInputReport();
    m_remote_input_report_isSet = false;
    sdr_play_report = new SWGSDRPlayReport();
    m_sdr_play_report_isSet = false;
    sdr_play_v3_report = new SWGSDRPlayV3Report();
    m_sdr_play_v3_report_isSet = false;
    sig_mf_file_input_report = new SWGSigMFFileInputReport();
    m_sig_mf_file_input_report_isSet = false;
    soapy_sdr_input_report = new SWGSoapySDRReport();
    m_soapy_sdr_input_report_isSet = false;
    soapy_sdr_output_report = new SWGSoapySDRReport();
    m_soapy_sdr_output_report_isSet = false;
    usrp_input_report = new SWGUSRPInputReport();
    m_usrp_input_report_isSet = false;
    usrp_output_report = new SWGUSRPOutputReport();
    m_usrp_output_report_isSet = false;
    xtrx_input_report = new SWGXtrxInputReport();
    m_xtrx_input_report_isSet = false;
    xtrx_output_report = new SWGXtrxOutputReport();
    m_xtrx_output_report_isSet = false;
    xtrx_mimo_report = new SWGXtrxMIMOReport();
    m_xtrx_mimo_report_isSet = false;
}

void
SWGDeviceReport::cleanup() {
    if(device_hw_type != nullptr) { 
        delete device_hw_type;
    }

    if(airspy_report != nullptr) { 
        delete airspy_report;
    }
    if(airspy_hf_report != nullptr) { 
        delete airspy_hf_report;
    }
    if(blade_rf2_input_report != nullptr) { 
        delete blade_rf2_input_report;
    }
    if(blade_rf2_output_report != nullptr) { 
        delete blade_rf2_output_report;
    }
    if(blade_rf2_mimo_report != nullptr) { 
        delete blade_rf2_mimo_report;
    }
    if(file_input_report != nullptr) { 
        delete file_input_report;
    }
    if(kiwi_sdr_report != nullptr) { 
        delete kiwi_sdr_report;
    }
    if(lime_sdr_input_report != nullptr) { 
        delete lime_sdr_input_report;
    }
    if(lime_sdr_output_report != nullptr) { 
        delete lime_sdr_output_report;
    }
    if(lime_sdr_mimo_report != nullptr) { 
        delete lime_sdr_mimo_report;
    }
    if(local_input_report != nullptr) { 
        delete local_input_report;
    }
    if(local_output_report != nullptr) { 
        delete local_output_report;
    }
    if(perseus_report != nullptr) { 
        delete perseus_report;
    }
    if(pluto_sdr_input_report != nullptr) { 
        delete pluto_sdr_input_report;
    }
    if(pluto_sdr_output_report != nullptr) { 
        delete pluto_sdr_output_report;
    }
    if(pluto_sdr_mimo_report != nullptr) { 
        delete pluto_sdr_mimo_report;
    }
    if(rtl_sdr_report != nullptr) { 
        delete rtl_sdr_report;
    }
    if(remote_output_report != nullptr) { 
        delete remote_output_report;
    }
    if(remote_input_report != nullptr) { 
        delete remote_input_report;
    }
    if(sdr_play_report != nullptr) { 
        delete sdr_play_report;
    }
    if(sdr_play_v3_report != nullptr) { 
        delete sdr_play_v3_report;
    }
    if(sig_mf_file_input_report != nullptr) { 
        delete sig_mf_file_input_report;
    }
    if(soapy_sdr_input_report != nullptr) { 
        delete soapy_sdr_input_report;
    }
    if(soapy_sdr_output_report != nullptr) { 
        delete soapy_sdr_output_report;
    }
    if(usrp_input_report != nullptr) { 
        delete usrp_input_report;
    }
    if(usrp_output_report != nullptr) { 
        delete usrp_output_report;
    }
    if(xtrx_input_report != nullptr) { 
        delete xtrx_input_report;
    }
    if(xtrx_output_report != nullptr) { 
        delete xtrx_output_report;
    }
    if(xtrx_mimo_report != nullptr) { 
        delete xtrx_mimo_report;
    }
}

SWGDeviceReport*
SWGDeviceReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDeviceReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&device_hw_type, pJson["deviceHwType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&direction, pJson["direction"], "qint32", "");
    
    ::SWGSDRangel::setValue(&airspy_report, pJson["airspyReport"], "SWGAirspyReport", "SWGAirspyReport");
    
    ::SWGSDRangel::setValue(&airspy_hf_report, pJson["airspyHFReport"], "SWGAirspyHFReport", "SWGAirspyHFReport");
    
    ::SWGSDRangel::setValue(&blade_rf2_input_report, pJson["bladeRF2InputReport"], "SWGBladeRF2InputReport", "SWGBladeRF2InputReport");
    
    ::SWGSDRangel::setValue(&blade_rf2_output_report, pJson["bladeRF2OutputReport"], "SWGBladeRF2OutputReport", "SWGBladeRF2OutputReport");
    
    ::SWGSDRangel::setValue(&blade_rf2_mimo_report, pJson["bladeRF2MIMOReport"], "SWGBladeRF2MIMOReport", "SWGBladeRF2MIMOReport");
    
    ::SWGSDRangel::setValue(&file_input_report, pJson["fileInputReport"], "SWGFileInputReport", "SWGFileInputReport");
    
    ::SWGSDRangel::setValue(&kiwi_sdr_report, pJson["kiwiSDRReport"], "SWGKiwiSDRReport", "SWGKiwiSDRReport");
    
    ::SWGSDRangel::setValue(&lime_sdr_input_report, pJson["limeSdrInputReport"], "SWGLimeSdrInputReport", "SWGLimeSdrInputReport");
    
    ::SWGSDRangel::setValue(&lime_sdr_output_report, pJson["limeSdrOutputReport"], "SWGLimeSdrOutputReport", "SWGLimeSdrOutputReport");
    
    ::SWGSDRangel::setValue(&lime_sdr_mimo_report, pJson["limeSdrMIMOReport"], "SWGLimeSdrMIMOReport", "SWGLimeSdrMIMOReport");
    
    ::SWGSDRangel::setValue(&local_input_report, pJson["localInputReport"], "SWGLocalInputReport", "SWGLocalInputReport");
    
    ::SWGSDRangel::setValue(&local_output_report, pJson["localOutputReport"], "SWGLocalOutputReport", "SWGLocalOutputReport");
    
    ::SWGSDRangel::setValue(&perseus_report, pJson["perseusReport"], "SWGPerseusReport", "SWGPerseusReport");
    
    ::SWGSDRangel::setValue(&pluto_sdr_input_report, pJson["plutoSdrInputReport"], "SWGPlutoSdrInputReport", "SWGPlutoSdrInputReport");
    
    ::SWGSDRangel::setValue(&pluto_sdr_output_report, pJson["plutoSdrOutputReport"], "SWGPlutoSdrOutputReport", "SWGPlutoSdrOutputReport");
    
    ::SWGSDRangel::setValue(&pluto_sdr_mimo_report, pJson["plutoSdrMIMOReport"], "SWGPlutoSdrMIMOReport", "SWGPlutoSdrMIMOReport");
    
    ::SWGSDRangel::setValue(&rtl_sdr_report, pJson["rtlSdrReport"], "SWGRtlSdrReport", "SWGRtlSdrReport");
    
    ::SWGSDRangel::setValue(&remote_output_report, pJson["remoteOutputReport"], "SWGRemoteOutputReport", "SWGRemoteOutputReport");
    
    ::SWGSDRangel::setValue(&remote_input_report, pJson["remoteInputReport"], "SWGRemoteInputReport", "SWGRemoteInputReport");
    
    ::SWGSDRangel::setValue(&sdr_play_report, pJson["sdrPlayReport"], "SWGSDRPlayReport", "SWGSDRPlayReport");
    
    ::SWGSDRangel::setValue(&sdr_play_v3_report, pJson["sdrPlayV3Report"], "SWGSDRPlayV3Report", "SWGSDRPlayV3Report");
    
    ::SWGSDRangel::setValue(&sig_mf_file_input_report, pJson["sigMFFileInputReport"], "SWGSigMFFileInputReport", "SWGSigMFFileInputReport");
    
    ::SWGSDRangel::setValue(&soapy_sdr_input_report, pJson["soapySDRInputReport"], "SWGSoapySDRReport", "SWGSoapySDRReport");
    
    ::SWGSDRangel::setValue(&soapy_sdr_output_report, pJson["soapySDROutputReport"], "SWGSoapySDRReport", "SWGSoapySDRReport");
    
    ::SWGSDRangel::setValue(&usrp_input_report, pJson["usrpInputReport"], "SWGUSRPInputReport", "SWGUSRPInputReport");
    
    ::SWGSDRangel::setValue(&usrp_output_report, pJson["usrpOutputReport"], "SWGUSRPOutputReport", "SWGUSRPOutputReport");
    
    ::SWGSDRangel::setValue(&xtrx_input_report, pJson["xtrxInputReport"], "SWGXtrxInputReport", "SWGXtrxInputReport");
    
    ::SWGSDRangel::setValue(&xtrx_output_report, pJson["xtrxOutputReport"], "SWGXtrxOutputReport", "SWGXtrxOutputReport");
    
    ::SWGSDRangel::setValue(&xtrx_mimo_report, pJson["xtrxMIMOReport"], "SWGXtrxMIMOReport", "SWGXtrxMIMOReport");
    
}

QString
SWGDeviceReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGDeviceReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(device_hw_type != nullptr && *device_hw_type != QString("")){
        toJsonValue(QString("deviceHwType"), device_hw_type, obj, QString("QString"));
    }
    if(m_direction_isSet){
        obj->insert("direction", QJsonValue(direction));
    }
    if((airspy_report != nullptr) && (airspy_report->isSet())){
        toJsonValue(QString("airspyReport"), airspy_report, obj, QString("SWGAirspyReport"));
    }
    if((airspy_hf_report != nullptr) && (airspy_hf_report->isSet())){
        toJsonValue(QString("airspyHFReport"), airspy_hf_report, obj, QString("SWGAirspyHFReport"));
    }
    if((blade_rf2_input_report != nullptr) && (blade_rf2_input_report->isSet())){
        toJsonValue(QString("bladeRF2InputReport"), blade_rf2_input_report, obj, QString("SWGBladeRF2InputReport"));
    }
    if((blade_rf2_output_report != nullptr) && (blade_rf2_output_report->isSet())){
        toJsonValue(QString("bladeRF2OutputReport"), blade_rf2_output_report, obj, QString("SWGBladeRF2OutputReport"));
    }
    if((blade_rf2_mimo_report != nullptr) && (blade_rf2_mimo_report->isSet())){
        toJsonValue(QString("bladeRF2MIMOReport"), blade_rf2_mimo_report, obj, QString("SWGBladeRF2MIMOReport"));
    }
    if((file_input_report != nullptr) && (file_input_report->isSet())){
        toJsonValue(QString("fileInputReport"), file_input_report, obj, QString("SWGFileInputReport"));
    }
    if((kiwi_sdr_report != nullptr) && (kiwi_sdr_report->isSet())){
        toJsonValue(QString("kiwiSDRReport"), kiwi_sdr_report, obj, QString("SWGKiwiSDRReport"));
    }
    if((lime_sdr_input_report != nullptr) && (lime_sdr_input_report->isSet())){
        toJsonValue(QString("limeSdrInputReport"), lime_sdr_input_report, obj, QString("SWGLimeSdrInputReport"));
    }
    if((lime_sdr_output_report != nullptr) && (lime_sdr_output_report->isSet())){
        toJsonValue(QString("limeSdrOutputReport"), lime_sdr_output_report, obj, QString("SWGLimeSdrOutputReport"));
    }
    if((lime_sdr_mimo_report != nullptr) && (lime_sdr_mimo_report->isSet())){
        toJsonValue(QString("limeSdrMIMOReport"), lime_sdr_mimo_report, obj, QString("SWGLimeSdrMIMOReport"));
    }
    if((local_input_report != nullptr) && (local_input_report->isSet())){
        toJsonValue(QString("localInputReport"), local_input_report, obj, QString("SWGLocalInputReport"));
    }
    if((local_output_report != nullptr) && (local_output_report->isSet())){
        toJsonValue(QString("localOutputReport"), local_output_report, obj, QString("SWGLocalOutputReport"));
    }
    if((perseus_report != nullptr) && (perseus_report->isSet())){
        toJsonValue(QString("perseusReport"), perseus_report, obj, QString("SWGPerseusReport"));
    }
    if((pluto_sdr_input_report != nullptr) && (pluto_sdr_input_report->isSet())){
        toJsonValue(QString("plutoSdrInputReport"), pluto_sdr_input_report, obj, QString("SWGPlutoSdrInputReport"));
    }
    if((pluto_sdr_output_report != nullptr) && (pluto_sdr_output_report->isSet())){
        toJsonValue(QString("plutoSdrOutputReport"), pluto_sdr_output_report, obj, QString("SWGPlutoSdrOutputReport"));
    }
    if((pluto_sdr_mimo_report != nullptr) && (pluto_sdr_mimo_report->isSet())){
        toJsonValue(QString("plutoSdrMIMOReport"), pluto_sdr_mimo_report, obj, QString("SWGPlutoSdrMIMOReport"));
    }
    if((rtl_sdr_report != nullptr) && (rtl_sdr_report->isSet())){
        toJsonValue(QString("rtlSdrReport"), rtl_sdr_report, obj, QString("SWGRtlSdrReport"));
    }
    if((remote_output_report != nullptr) && (remote_output_report->isSet())){
        toJsonValue(QString("remoteOutputReport"), remote_output_report, obj, QString("SWGRemoteOutputReport"));
    }
    if((remote_input_report != nullptr) && (remote_input_report->isSet())){
        toJsonValue(QString("remoteInputReport"), remote_input_report, obj, QString("SWGRemoteInputReport"));
    }
    if((sdr_play_report != nullptr) && (sdr_play_report->isSet())){
        toJsonValue(QString("sdrPlayReport"), sdr_play_report, obj, QString("SWGSDRPlayReport"));
    }
    if((sdr_play_v3_report != nullptr) && (sdr_play_v3_report->isSet())){
        toJsonValue(QString("sdrPlayV3Report"), sdr_play_v3_report, obj, QString("SWGSDRPlayV3Report"));
    }
    if((sig_mf_file_input_report != nullptr) && (sig_mf_file_input_report->isSet())){
        toJsonValue(QString("sigMFFileInputReport"), sig_mf_file_input_report, obj, QString("SWGSigMFFileInputReport"));
    }
    if((soapy_sdr_input_report != nullptr) && (soapy_sdr_input_report->isSet())){
        toJsonValue(QString("soapySDRInputReport"), soapy_sdr_input_report, obj, QString("SWGSoapySDRReport"));
    }
    if((soapy_sdr_output_report != nullptr) && (soapy_sdr_output_report->isSet())){
        toJsonValue(QString("soapySDROutputReport"), soapy_sdr_output_report, obj, QString("SWGSoapySDRReport"));
    }
    if((usrp_input_report != nullptr) && (usrp_input_report->isSet())){
        toJsonValue(QString("usrpInputReport"), usrp_input_report, obj, QString("SWGUSRPInputReport"));
    }
    if((usrp_output_report != nullptr) && (usrp_output_report->isSet())){
        toJsonValue(QString("usrpOutputReport"), usrp_output_report, obj, QString("SWGUSRPOutputReport"));
    }
    if((xtrx_input_report != nullptr) && (xtrx_input_report->isSet())){
        toJsonValue(QString("xtrxInputReport"), xtrx_input_report, obj, QString("SWGXtrxInputReport"));
    }
    if((xtrx_output_report != nullptr) && (xtrx_output_report->isSet())){
        toJsonValue(QString("xtrxOutputReport"), xtrx_output_report, obj, QString("SWGXtrxOutputReport"));
    }
    if((xtrx_mimo_report != nullptr) && (xtrx_mimo_report->isSet())){
        toJsonValue(QString("xtrxMIMOReport"), xtrx_mimo_report, obj, QString("SWGXtrxMIMOReport"));
    }

    return obj;
}

QString*
SWGDeviceReport::getDeviceHwType() {
    return device_hw_type;
}
void
SWGDeviceReport::setDeviceHwType(QString* device_hw_type) {
    this->device_hw_type = device_hw_type;
    this->m_device_hw_type_isSet = true;
}

qint32
SWGDeviceReport::getDirection() {
    return direction;
}
void
SWGDeviceReport::setDirection(qint32 direction) {
    this->direction = direction;
    this->m_direction_isSet = true;
}

SWGAirspyReport*
SWGDeviceReport::getAirspyReport() {
    return airspy_report;
}
void
SWGDeviceReport::setAirspyReport(SWGAirspyReport* airspy_report) {
    this->airspy_report = airspy_report;
    this->m_airspy_report_isSet = true;
}

SWGAirspyHFReport*
SWGDeviceReport::getAirspyHfReport() {
    return airspy_hf_report;
}
void
SWGDeviceReport::setAirspyHfReport(SWGAirspyHFReport* airspy_hf_report) {
    this->airspy_hf_report = airspy_hf_report;
    this->m_airspy_hf_report_isSet = true;
}

SWGBladeRF2InputReport*
SWGDeviceReport::getBladeRf2InputReport() {
    return blade_rf2_input_report;
}
void
SWGDeviceReport::setBladeRf2InputReport(SWGBladeRF2InputReport* blade_rf2_input_report) {
    this->blade_rf2_input_report = blade_rf2_input_report;
    this->m_blade_rf2_input_report_isSet = true;
}

SWGBladeRF2OutputReport*
SWGDeviceReport::getBladeRf2OutputReport() {
    return blade_rf2_output_report;
}
void
SWGDeviceReport::setBladeRf2OutputReport(SWGBladeRF2OutputReport* blade_rf2_output_report) {
    this->blade_rf2_output_report = blade_rf2_output_report;
    this->m_blade_rf2_output_report_isSet = true;
}

SWGBladeRF2MIMOReport*
SWGDeviceReport::getBladeRf2MimoReport() {
    return blade_rf2_mimo_report;
}
void
SWGDeviceReport::setBladeRf2MimoReport(SWGBladeRF2MIMOReport* blade_rf2_mimo_report) {
    this->blade_rf2_mimo_report = blade_rf2_mimo_report;
    this->m_blade_rf2_mimo_report_isSet = true;
}

SWGFileInputReport*
SWGDeviceReport::getFileInputReport() {
    return file_input_report;
}
void
SWGDeviceReport::setFileInputReport(SWGFileInputReport* file_input_report) {
    this->file_input_report = file_input_report;
    this->m_file_input_report_isSet = true;
}

SWGKiwiSDRReport*
SWGDeviceReport::getKiwiSdrReport() {
    return kiwi_sdr_report;
}
void
SWGDeviceReport::setKiwiSdrReport(SWGKiwiSDRReport* kiwi_sdr_report) {
    this->kiwi_sdr_report = kiwi_sdr_report;
    this->m_kiwi_sdr_report_isSet = true;
}

SWGLimeSdrInputReport*
SWGDeviceReport::getLimeSdrInputReport() {
    return lime_sdr_input_report;
}
void
SWGDeviceReport::setLimeSdrInputReport(SWGLimeSdrInputReport* lime_sdr_input_report) {
    this->lime_sdr_input_report = lime_sdr_input_report;
    this->m_lime_sdr_input_report_isSet = true;
}

SWGLimeSdrOutputReport*
SWGDeviceReport::getLimeSdrOutputReport() {
    return lime_sdr_output_report;
}
void
SWGDeviceReport::setLimeSdrOutputReport(SWGLimeSdrOutputReport* lime_sdr_output_report) {
    this->lime_sdr_output_report = lime_sdr_output_report;
    this->m_lime_sdr_output_report_isSet = true;
}

SWGLimeSdrMIMOReport*
SWGDeviceReport::getLimeSdrMimoReport() {
    return lime_sdr_mimo_report;
}
void
SWGDeviceReport::setLimeSdrMimoReport(SWGLimeSdrMIMOReport* lime_sdr_mimo_report) {
    this->lime_sdr_mimo_report = lime_sdr_mimo_report;
    this->m_lime_sdr_mimo_report_isSet = true;
}

SWGLocalInputReport*
SWGDeviceReport::getLocalInputReport() {
    return local_input_report;
}
void
SWGDeviceReport::setLocalInputReport(SWGLocalInputReport* local_input_report) {
    this->local_input_report = local_input_report;
    this->m_local_input_report_isSet = true;
}

SWGLocalOutputReport*
SWGDeviceReport::getLocalOutputReport() {
    return local_output_report;
}
void
SWGDeviceReport::setLocalOutputReport(SWGLocalOutputReport* local_output_report) {
    this->local_output_report = local_output_report;
    this->m_local_output_report_isSet = true;
}

SWGPerseusReport*
SWGDeviceReport::getPerseusReport() {
    return perseus_report;
}
void
SWGDeviceReport::setPerseusReport(SWGPerseusReport* perseus_report) {
    this->perseus_report = perseus_report;
    this->m_perseus_report_isSet = true;
}

SWGPlutoSdrInputReport*
SWGDeviceReport::getPlutoSdrInputReport() {
    return pluto_sdr_input_report;
}
void
SWGDeviceReport::setPlutoSdrInputReport(SWGPlutoSdrInputReport* pluto_sdr_input_report) {
    this->pluto_sdr_input_report = pluto_sdr_input_report;
    this->m_pluto_sdr_input_report_isSet = true;
}

SWGPlutoSdrOutputReport*
SWGDeviceReport::getPlutoSdrOutputReport() {
    return pluto_sdr_output_report;
}
void
SWGDeviceReport::setPlutoSdrOutputReport(SWGPlutoSdrOutputReport* pluto_sdr_output_report) {
    this->pluto_sdr_output_report = pluto_sdr_output_report;
    this->m_pluto_sdr_output_report_isSet = true;
}

SWGPlutoSdrMIMOReport*
SWGDeviceReport::getPlutoSdrMimoReport() {
    return pluto_sdr_mimo_report;
}
void
SWGDeviceReport::setPlutoSdrMimoReport(SWGPlutoSdrMIMOReport* pluto_sdr_mimo_report) {
    this->pluto_sdr_mimo_report = pluto_sdr_mimo_report;
    this->m_pluto_sdr_mimo_report_isSet = true;
}

SWGRtlSdrReport*
SWGDeviceReport::getRtlSdrReport() {
    return rtl_sdr_report;
}
void
SWGDeviceReport::setRtlSdrReport(SWGRtlSdrReport* rtl_sdr_report) {
    this->rtl_sdr_report = rtl_sdr_report;
    this->m_rtl_sdr_report_isSet = true;
}

SWGRemoteOutputReport*
SWGDeviceReport::getRemoteOutputReport() {
    return remote_output_report;
}
void
SWGDeviceReport::setRemoteOutputReport(SWGRemoteOutputReport* remote_output_report) {
    this->remote_output_report = remote_output_report;
    this->m_remote_output_report_isSet = true;
}

SWGRemoteInputReport*
SWGDeviceReport::getRemoteInputReport() {
    return remote_input_report;
}
void
SWGDeviceReport::setRemoteInputReport(SWGRemoteInputReport* remote_input_report) {
    this->remote_input_report = remote_input_report;
    this->m_remote_input_report_isSet = true;
}

SWGSDRPlayReport*
SWGDeviceReport::getSdrPlayReport() {
    return sdr_play_report;
}
void
SWGDeviceReport::setSdrPlayReport(SWGSDRPlayReport* sdr_play_report) {
    this->sdr_play_report = sdr_play_report;
    this->m_sdr_play_report_isSet = true;
}

SWGSDRPlayV3Report*
SWGDeviceReport::getSdrPlayV3Report() {
    return sdr_play_v3_report;
}
void
SWGDeviceReport::setSdrPlayV3Report(SWGSDRPlayV3Report* sdr_play_v3_report) {
    this->sdr_play_v3_report = sdr_play_v3_report;
    this->m_sdr_play_v3_report_isSet = true;
}

SWGSigMFFileInputReport*
SWGDeviceReport::getSigMfFileInputReport() {
    return sig_mf_file_input_report;
}
void
SWGDeviceReport::setSigMfFileInputReport(SWGSigMFFileInputReport* sig_mf_file_input_report) {
    this->sig_mf_file_input_report = sig_mf_file_input_report;
    this->m_sig_mf_file_input_report_isSet = true;
}

SWGSoapySDRReport*
SWGDeviceReport::getSoapySdrInputReport() {
    return soapy_sdr_input_report;
}
void
SWGDeviceReport::setSoapySdrInputReport(SWGSoapySDRReport* soapy_sdr_input_report) {
    this->soapy_sdr_input_report = soapy_sdr_input_report;
    this->m_soapy_sdr_input_report_isSet = true;
}

SWGSoapySDRReport*
SWGDeviceReport::getSoapySdrOutputReport() {
    return soapy_sdr_output_report;
}
void
SWGDeviceReport::setSoapySdrOutputReport(SWGSoapySDRReport* soapy_sdr_output_report) {
    this->soapy_sdr_output_report = soapy_sdr_output_report;
    this->m_soapy_sdr_output_report_isSet = true;
}

SWGUSRPInputReport*
SWGDeviceReport::getUsrpInputReport() {
    return usrp_input_report;
}
void
SWGDeviceReport::setUsrpInputReport(SWGUSRPInputReport* usrp_input_report) {
    this->usrp_input_report = usrp_input_report;
    this->m_usrp_input_report_isSet = true;
}

SWGUSRPOutputReport*
SWGDeviceReport::getUsrpOutputReport() {
    return usrp_output_report;
}
void
SWGDeviceReport::setUsrpOutputReport(SWGUSRPOutputReport* usrp_output_report) {
    this->usrp_output_report = usrp_output_report;
    this->m_usrp_output_report_isSet = true;
}

SWGXtrxInputReport*
SWGDeviceReport::getXtrxInputReport() {
    return xtrx_input_report;
}
void
SWGDeviceReport::setXtrxInputReport(SWGXtrxInputReport* xtrx_input_report) {
    this->xtrx_input_report = xtrx_input_report;
    this->m_xtrx_input_report_isSet = true;
}

SWGXtrxOutputReport*
SWGDeviceReport::getXtrxOutputReport() {
    return xtrx_output_report;
}
void
SWGDeviceReport::setXtrxOutputReport(SWGXtrxOutputReport* xtrx_output_report) {
    this->xtrx_output_report = xtrx_output_report;
    this->m_xtrx_output_report_isSet = true;
}

SWGXtrxMIMOReport*
SWGDeviceReport::getXtrxMimoReport() {
    return xtrx_mimo_report;
}
void
SWGDeviceReport::setXtrxMimoReport(SWGXtrxMIMOReport* xtrx_mimo_report) {
    this->xtrx_mimo_report = xtrx_mimo_report;
    this->m_xtrx_mimo_report_isSet = true;
}


bool
SWGDeviceReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(device_hw_type && *device_hw_type != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_direction_isSet){
            isObjectUpdated = true; break;
        }
        if(airspy_report && airspy_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(airspy_hf_report && airspy_hf_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(blade_rf2_input_report && blade_rf2_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(blade_rf2_output_report && blade_rf2_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(blade_rf2_mimo_report && blade_rf2_mimo_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(file_input_report && file_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(kiwi_sdr_report && kiwi_sdr_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(lime_sdr_input_report && lime_sdr_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(lime_sdr_output_report && lime_sdr_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(lime_sdr_mimo_report && lime_sdr_mimo_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(local_input_report && local_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(local_output_report && local_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(perseus_report && perseus_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(pluto_sdr_input_report && pluto_sdr_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(pluto_sdr_output_report && pluto_sdr_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(pluto_sdr_mimo_report && pluto_sdr_mimo_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(rtl_sdr_report && rtl_sdr_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(remote_output_report && remote_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(remote_input_report && remote_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(sdr_play_report && sdr_play_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(sdr_play_v3_report && sdr_play_v3_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(sig_mf_file_input_report && sig_mf_file_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(soapy_sdr_input_report && soapy_sdr_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(soapy_sdr_output_report && soapy_sdr_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(usrp_input_report && usrp_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(usrp_output_report && usrp_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(xtrx_input_report && xtrx_input_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(xtrx_output_report && xtrx_output_report->isSet()){
            isObjectUpdated = true; break;
        }
        if(xtrx_mimo_report && xtrx_mimo_report->isSet()){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}
