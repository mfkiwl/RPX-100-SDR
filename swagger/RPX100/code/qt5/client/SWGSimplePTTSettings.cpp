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


#include "SWGSimplePTTSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGSimplePTTSettings::SWGSimplePTTSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSimplePTTSettings::SWGSimplePTTSettings() {
    title = nullptr;
    m_title_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    rx_device_set_index = 0;
    m_rx_device_set_index_isSet = false;
    tx_device_set_index = 0;
    m_tx_device_set_index_isSet = false;
    rx2_tx_delay_ms = 0;
    m_rx2_tx_delay_ms_isSet = false;
    tx2_rx_delay_ms = 0;
    m_tx2_rx_delay_ms_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_feature_set_index = 0;
    m_reverse_api_feature_set_index_isSet = false;
    reverse_api_feature_index = 0;
    m_reverse_api_feature_index_isSet = false;
}

SWGSimplePTTSettings::~SWGSimplePTTSettings() {
    this->cleanup();
}

void
SWGSimplePTTSettings::init() {
    title = new QString("");
    m_title_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    rx_device_set_index = 0;
    m_rx_device_set_index_isSet = false;
    tx_device_set_index = 0;
    m_tx_device_set_index_isSet = false;
    rx2_tx_delay_ms = 0;
    m_rx2_tx_delay_ms_isSet = false;
    tx2_rx_delay_ms = 0;
    m_tx2_rx_delay_ms_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_feature_set_index = 0;
    m_reverse_api_feature_set_index_isSet = false;
    reverse_api_feature_index = 0;
    m_reverse_api_feature_index_isSet = false;
}

void
SWGSimplePTTSettings::cleanup() {
    if(title != nullptr) { 
        delete title;
    }






    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGSimplePTTSettings*
SWGSimplePTTSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSimplePTTSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGRPX100::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx_device_set_index, pJson["rxDeviceSetIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx_device_set_index, pJson["txDeviceSetIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&rx2_tx_delay_ms, pJson["rx2TxDelayMs"], "qint32", "");
    
    ::SWGRPX100::setValue(&tx2_rx_delay_ms, pJson["tx2RxDelayMs"], "qint32", "");
    
    ::SWGRPX100::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_feature_set_index, pJson["reverseAPIFeatureSetIndex"], "qint32", "");
    
    ::SWGRPX100::setValue(&reverse_api_feature_index, pJson["reverseAPIFeatureIndex"], "qint32", "");
    
}

QString
SWGSimplePTTSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSimplePTTSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(m_rx_device_set_index_isSet){
        obj->insert("rxDeviceSetIndex", QJsonValue(rx_device_set_index));
    }
    if(m_tx_device_set_index_isSet){
        obj->insert("txDeviceSetIndex", QJsonValue(tx_device_set_index));
    }
    if(m_rx2_tx_delay_ms_isSet){
        obj->insert("rx2TxDelayMs", QJsonValue(rx2_tx_delay_ms));
    }
    if(m_tx2_rx_delay_ms_isSet){
        obj->insert("tx2RxDelayMs", QJsonValue(tx2_rx_delay_ms));
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
    if(m_reverse_api_feature_set_index_isSet){
        obj->insert("reverseAPIFeatureSetIndex", QJsonValue(reverse_api_feature_set_index));
    }
    if(m_reverse_api_feature_index_isSet){
        obj->insert("reverseAPIFeatureIndex", QJsonValue(reverse_api_feature_index));
    }

    return obj;
}

QString*
SWGSimplePTTSettings::getTitle() {
    return title;
}
void
SWGSimplePTTSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGSimplePTTSettings::getRgbColor() {
    return rgb_color;
}
void
SWGSimplePTTSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

qint32
SWGSimplePTTSettings::getRxDeviceSetIndex() {
    return rx_device_set_index;
}
void
SWGSimplePTTSettings::setRxDeviceSetIndex(qint32 rx_device_set_index) {
    this->rx_device_set_index = rx_device_set_index;
    this->m_rx_device_set_index_isSet = true;
}

qint32
SWGSimplePTTSettings::getTxDeviceSetIndex() {
    return tx_device_set_index;
}
void
SWGSimplePTTSettings::setTxDeviceSetIndex(qint32 tx_device_set_index) {
    this->tx_device_set_index = tx_device_set_index;
    this->m_tx_device_set_index_isSet = true;
}

qint32
SWGSimplePTTSettings::getRx2TxDelayMs() {
    return rx2_tx_delay_ms;
}
void
SWGSimplePTTSettings::setRx2TxDelayMs(qint32 rx2_tx_delay_ms) {
    this->rx2_tx_delay_ms = rx2_tx_delay_ms;
    this->m_rx2_tx_delay_ms_isSet = true;
}

qint32
SWGSimplePTTSettings::getTx2RxDelayMs() {
    return tx2_rx_delay_ms;
}
void
SWGSimplePTTSettings::setTx2RxDelayMs(qint32 tx2_rx_delay_ms) {
    this->tx2_rx_delay_ms = tx2_rx_delay_ms;
    this->m_tx2_rx_delay_ms_isSet = true;
}

qint32
SWGSimplePTTSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGSimplePTTSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGSimplePTTSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGSimplePTTSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGSimplePTTSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGSimplePTTSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGSimplePTTSettings::getReverseApiFeatureSetIndex() {
    return reverse_api_feature_set_index;
}
void
SWGSimplePTTSettings::setReverseApiFeatureSetIndex(qint32 reverse_api_feature_set_index) {
    this->reverse_api_feature_set_index = reverse_api_feature_set_index;
    this->m_reverse_api_feature_set_index_isSet = true;
}

qint32
SWGSimplePTTSettings::getReverseApiFeatureIndex() {
    return reverse_api_feature_index;
}
void
SWGSimplePTTSettings::setReverseApiFeatureIndex(qint32 reverse_api_feature_index) {
    this->reverse_api_feature_index = reverse_api_feature_index;
    this->m_reverse_api_feature_index_isSet = true;
}


bool
SWGSimplePTTSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx_device_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx_device_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rx2_tx_delay_ms_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tx2_rx_delay_ms_isSet){
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
        if(m_reverse_api_feature_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_feature_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

