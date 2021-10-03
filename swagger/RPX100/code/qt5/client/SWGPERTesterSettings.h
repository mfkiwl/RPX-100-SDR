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

/*
 * SWGPERTesterSettings.h
 *
 * PER Tester settings
 */

#ifndef SWGPERTesterSettings_H_
#define SWGPERTesterSettings_H_

#include <QJsonObject>


#include <QList>
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGPERTesterSettings: public SWGObject {
public:
    SWGPERTesterSettings();
    SWGPERTesterSettings(QString* json);
    virtual ~SWGPERTesterSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGPERTesterSettings* fromJson(QString &jsonString) override;

    qint32 getPacketCount();
    void setPacketCount(qint32 packet_count);

    float getInterval();
    void setInterval(float interval);

    qint32 getStart();
    void setStart(qint32 start);

    QList<QString*>* getSatellites();
    void setSatellites(QList<QString*>* satellites);

    QString* getPacket();
    void setPacket(QString* packet);

    qint32 getIgnoreLeadingBytes();
    void setIgnoreLeadingBytes(qint32 ignore_leading_bytes);

    qint32 getIgnoreTrailingBytes();
    void setIgnoreTrailingBytes(qint32 ignore_trailing_bytes);

    QString* getTxUdpAddress();
    void setTxUdpAddress(QString* tx_udp_address);

    qint32 getTxUdpPort();
    void setTxUdpPort(qint32 tx_udp_port);

    QString* getRxUdpAddress();
    void setRxUdpAddress(QString* rx_udp_address);

    qint32 getRxUdpPort();
    void setRxUdpPort(qint32 rx_udp_port);

    QString* getTitle();
    void setTitle(QString* title);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiFeatureSetIndex();
    void setReverseApiFeatureSetIndex(qint32 reverse_api_feature_set_index);

    qint32 getReverseApiFeatureIndex();
    void setReverseApiFeatureIndex(qint32 reverse_api_feature_index);


    virtual bool isSet() override;

private:
    qint32 packet_count;
    bool m_packet_count_isSet;

    float interval;
    bool m_interval_isSet;

    qint32 start;
    bool m_start_isSet;

    QList<QString*>* satellites;
    bool m_satellites_isSet;

    QString* packet;
    bool m_packet_isSet;

    qint32 ignore_leading_bytes;
    bool m_ignore_leading_bytes_isSet;

    qint32 ignore_trailing_bytes;
    bool m_ignore_trailing_bytes_isSet;

    QString* tx_udp_address;
    bool m_tx_udp_address_isSet;

    qint32 tx_udp_port;
    bool m_tx_udp_port_isSet;

    QString* rx_udp_address;
    bool m_rx_udp_address_isSet;

    qint32 rx_udp_port;
    bool m_rx_udp_port_isSet;

    QString* title;
    bool m_title_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_feature_set_index;
    bool m_reverse_api_feature_set_index_isSet;

    qint32 reverse_api_feature_index;
    bool m_reverse_api_feature_index_isSet;

};

}

#endif /* SWGPERTesterSettings_H_ */
