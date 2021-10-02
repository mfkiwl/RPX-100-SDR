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

/*
 * SWGIEEE_802_15_4_ModActions_tx.h
 *
 * Transmit a frame 
 */

#ifndef SWGIEEE_802_15_4_ModActions_tx_H_
#define SWGIEEE_802_15_4_ModActions_tx_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGRPX100 {

class SWG_API SWGIEEE_802_15_4_ModActions_tx: public SWGObject {
public:
    SWGIEEE_802_15_4_ModActions_tx();
    SWGIEEE_802_15_4_ModActions_tx(QString* json);
    virtual ~SWGIEEE_802_15_4_ModActions_tx();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGIEEE_802_15_4_ModActions_tx* fromJson(QString &jsonString) override;

    QString* getData();
    void setData(QString* data);


    virtual bool isSet() override;

private:
    QString* data;
    bool m_data_isSet;

};

}

#endif /* SWGIEEE_802_15_4_ModActions_tx_H_ */
