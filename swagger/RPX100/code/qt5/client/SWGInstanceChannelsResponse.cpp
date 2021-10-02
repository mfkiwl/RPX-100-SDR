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


#include "SWGInstanceChannelsResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGInstanceChannelsResponse::SWGInstanceChannelsResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGInstanceChannelsResponse::SWGInstanceChannelsResponse() {
    channelcount = 0;
    m_channelcount_isSet = false;
    channels = nullptr;
    m_channels_isSet = false;
}

SWGInstanceChannelsResponse::~SWGInstanceChannelsResponse() {
    this->cleanup();
}

void
SWGInstanceChannelsResponse::init() {
    channelcount = 0;
    m_channelcount_isSet = false;
    channels = new QList<SWGChannelListItem*>();
    m_channels_isSet = false;
}

void
SWGInstanceChannelsResponse::cleanup() {

    if(channels != nullptr) { 
        auto arr = channels;
        for(auto o: *arr) { 
            delete o;
        }
        delete channels;
    }
}

SWGInstanceChannelsResponse*
SWGInstanceChannelsResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGInstanceChannelsResponse::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&channelcount, pJson["channelcount"], "qint32", "");
    
    
    ::SWGRPX100::setValue(&channels, pJson["channels"], "QList", "SWGChannelListItem");
}

QString
SWGInstanceChannelsResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGInstanceChannelsResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_channelcount_isSet){
        obj->insert("channelcount", QJsonValue(channelcount));
    }
    if(channels && channels->size() > 0){
        toJsonArray((QList<void*>*)channels, obj, "channels", "SWGChannelListItem");
    }

    return obj;
}

qint32
SWGInstanceChannelsResponse::getChannelcount() {
    return channelcount;
}
void
SWGInstanceChannelsResponse::setChannelcount(qint32 channelcount) {
    this->channelcount = channelcount;
    this->m_channelcount_isSet = true;
}

QList<SWGChannelListItem*>*
SWGInstanceChannelsResponse::getChannels() {
    return channels;
}
void
SWGInstanceChannelsResponse::setChannels(QList<SWGChannelListItem*>* channels) {
    this->channels = channels;
    this->m_channels_isSet = true;
}


bool
SWGInstanceChannelsResponse::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_channelcount_isSet){
            isObjectUpdated = true; break;
        }
        if(channels && (channels->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

