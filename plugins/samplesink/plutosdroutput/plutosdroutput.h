///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef PLUGINS_SAMPLESOURCE_PLUTOSDROUTPUT_PLUTOSDRINPUT_H_
#define PLUGINS_SAMPLESOURCE_PLUTOSDROUTPUT_PLUTOSDRINPUT_H_

#include <QString>
#include <QNetworkRequest>

#include "iio.h"
#include "dsp/devicesamplesink.h"
#include "util/message.h"
#include "plutosdr/deviceplutosdrshared.h"
#include "plutosdr/deviceplutosdrbox.h"
#include "plutosdroutputsettings.h"

class QNetworkAccessManager;
class QNetworkReply;
class DeviceAPI;
class PlutoSDROutputThread;

class PlutoSDROutput : public DeviceSampleSink {
    Q_OBJECT
public:
    class MsgConfigurePlutoSDR : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const PlutoSDROutputSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigurePlutoSDR* create(const PlutoSDROutputSettings& settings, bool force)
        {
            return new MsgConfigurePlutoSDR(settings, force);
        }

    private:
        PlutoSDROutputSettings m_settings;
        bool m_force;

        MsgConfigurePlutoSDR(const PlutoSDROutputSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    class MsgStartStop : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        bool getStartStop() const { return m_startStop; }

        static MsgStartStop* create(bool startStop) {
            return new MsgStartStop(startStop);
        }

    protected:
        bool m_startStop;

        MsgStartStop(bool startStop) :
            Message(),
            m_startStop(startStop)
        { }
    };

    PlutoSDROutput(DeviceAPI *deviceAPI);
    ~PlutoSDROutput();
    virtual void destroy();

    virtual void init();
    virtual bool start();
    virtual void stop();

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual void setMessageQueueToGUI(MessageQueue *queue) { m_guiMessageQueue = queue; }
    virtual const QString& getDeviceDescription() const;
    virtual int getSampleRate() const;
    virtual void setSampleRate(int sampleRate) { (void) sampleRate; }
    virtual quint64 getCenterFrequency() const;
    virtual void setCenterFrequency(qint64 centerFrequency);

    virtual bool handleMessage(const Message& message);

    virtual int webapiSettingsGet(
                SWGSDRangel::SWGDeviceSettings& response,
                QString& errorMessage);

    virtual int webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGSDRangel::SWGDeviceSettings& response, // query + response
                QString& errorMessage);

    virtual int webapiReportGet(
            SWGSDRangel::SWGDeviceReport& response,
            QString& errorMessage);

    virtual int webapiRunGet(
            SWGSDRangel::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiRun(
            bool run,
            SWGSDRangel::SWGDeviceState& response,
            QString& errorMessage);

    static void webapiFormatDeviceSettings(
            SWGSDRangel::SWGDeviceSettings& response,
            const PlutoSDROutputSettings& settings);

    static void webapiUpdateDeviceSettings(
            PlutoSDROutputSettings& settings,
            const QStringList& deviceSettingsKeys,
            SWGSDRangel::SWGDeviceSettings& response);

    uint32_t getDACSampleRate() const { return m_deviceSampleRates.m_addaConnvRate; }
    uint32_t getFIRSampleRate() const { return m_deviceSampleRates.m_hb1Rate; }
    void getRSSI(std::string& rssiStr);
    void getLORange(qint64& minLimit, qint64& maxLimit);
    void getbbLPRange(quint32& minLimit, quint32& maxLimit);
    bool fetchTemperature();
    float getTemperature();

 private:
    DeviceAPI *m_deviceAPI;
    bool m_open;
    QString m_deviceDescription;
    PlutoSDROutputSettings m_settings;
    bool m_running;
    DevicePlutoSDRShared m_deviceShared;
    struct iio_buffer *m_plutoTxBuffer;
    PlutoSDROutputThread *m_plutoSDROutputThread;
    DevicePlutoSDRBox::SampleRates m_deviceSampleRates;
    QMutex m_mutex;
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    bool openDevice();
    void closeDevice();
    void suspendBuddies();
    void resumeBuddies();
    bool applySettings(const PlutoSDROutputSettings& settings, bool force = false);
    void webapiFormatDeviceReport(SWGSDRangel::SWGDeviceReport& response);
    void webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const PlutoSDROutputSettings& settings, bool force);
    void webapiReverseSendStartStop(bool start);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};


#endif /* PLUGINS_SAMPLESOURCE_PLUTOSDROUTPUT_PLUTOSDRINPUT_H_ */
