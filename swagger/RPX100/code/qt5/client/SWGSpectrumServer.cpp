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


#include "SWGSpectrumServer.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGRPX100 {

SWGSpectrumServer::SWGSpectrumServer(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSpectrumServer::SWGSpectrumServer() {
    run = 0;
    m_run_isSet = false;
    listening_address = nullptr;
    m_listening_address_isSet = false;
    listening_port = 0;
    m_listening_port_isSet = false;
    clients = nullptr;
    m_clients_isSet = false;
}

SWGSpectrumServer::~SWGSpectrumServer() {
    this->cleanup();
}

void
SWGSpectrumServer::init() {
    run = 0;
    m_run_isSet = false;
    listening_address = new QString("");
    m_listening_address_isSet = false;
    listening_port = 0;
    m_listening_port_isSet = false;
    clients = new QList<SWGSpectrumServer_clients*>();
    m_clients_isSet = false;
}

void
SWGSpectrumServer::cleanup() {

    if(listening_address != nullptr) { 
        delete listening_address;
    }

    if(clients != nullptr) { 
        auto arr = clients;
        for(auto o: *arr) { 
            delete o;
        }
        delete clients;
    }
}

SWGSpectrumServer*
SWGSpectrumServer::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSpectrumServer::fromJsonObject(QJsonObject &pJson) {
    ::SWGRPX100::setValue(&run, pJson["run"], "qint32", "");
    
    ::SWGRPX100::setValue(&listening_address, pJson["listeningAddress"], "QString", "QString");
    
    ::SWGRPX100::setValue(&listening_port, pJson["listeningPort"], "qint32", "");
    
    
    ::SWGRPX100::setValue(&clients, pJson["clients"], "QList", "SWGSpectrumServer_clients");
}

QString
SWGSpectrumServer::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSpectrumServer::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_run_isSet){
        obj->insert("run", QJsonValue(run));
    }
    if(listening_address != nullptr && *listening_address != QString("")){
        toJsonValue(QString("listeningAddress"), listening_address, obj, QString("QString"));
    }
    if(m_listening_port_isSet){
        obj->insert("listeningPort", QJsonValue(listening_port));
    }
    if(clients && clients->size() > 0){
        toJsonArray((QList<void*>*)clients, obj, "clients", "SWGSpectrumServer_clients");
    }

    return obj;
}

qint32
SWGSpectrumServer::getRun() {
    return run;
}
void
SWGSpectrumServer::setRun(qint32 run) {
    this->run = run;
    this->m_run_isSet = true;
}

QString*
SWGSpectrumServer::getListeningAddress() {
    return listening_address;
}
void
SWGSpectrumServer::setListeningAddress(QString* listening_address) {
    this->listening_address = listening_address;
    this->m_listening_address_isSet = true;
}

qint32
SWGSpectrumServer::getListeningPort() {
    return listening_port;
}
void
SWGSpectrumServer::setListeningPort(qint32 listening_port) {
    this->listening_port = listening_port;
    this->m_listening_port_isSet = true;
}

QList<SWGSpectrumServer_clients*>*
SWGSpectrumServer::getClients() {
    return clients;
}
void
SWGSpectrumServer::setClients(QList<SWGSpectrumServer_clients*>* clients) {
    this->clients = clients;
    this->m_clients_isSet = true;
}


bool
SWGSpectrumServer::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_run_isSet){
            isObjectUpdated = true; break;
        }
        if(listening_address && *listening_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_listening_port_isSet){
            isObjectUpdated = true; break;
        }
        if(clients && (clients->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

