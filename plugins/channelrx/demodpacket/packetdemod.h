///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015-2018 Edouard Griffiths, F4EXB.                             //
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
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

#ifndef INCLUDE_PACKETDEMOD_H
#define INCLUDE_PACKETDEMOD_H

#include <vector>

#include <QNetworkRequest>
#include <QUdpSocket>
#include <QThread>

#include "dsp/basebandsamplesink.h"
#include "channel/channelapi.h"
#include "util/message.h"

#include "packetdemodbaseband.h"
#include "packetdemodsettings.h"

class QNetworkAccessManager;
class QNetworkReply;
class QThread;
class DeviceAPI;

class PacketDemod : public BasebandSampleSink, public ChannelAPI {
    Q_OBJECT
public:
    class MsgConfigurePacketDemod : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const PacketDemodSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigurePacketDemod* create(const PacketDemodSettings& settings, bool force)
        {
            return new MsgConfigurePacketDemod(settings, force);
        }

    private:
        PacketDemodSettings m_settings;
        bool m_force;

        MsgConfigurePacketDemod(const PacketDemodSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    PacketDemod(DeviceAPI *deviceAPI);
    virtual ~PacketDemod();
    virtual void destroy() { delete this; }

    using BasebandSampleSink::feed;
    virtual void feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool po);
    virtual void start();
    virtual void stop();
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) { id = objectName(); }
    virtual const QString& getURI() const { return getName(); }
    virtual void getTitle(QString& title) { title = m_settings.m_title; }
    virtual qint64 getCenterFrequency() const { return 0; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual int getNbSinkStreams() const { return 1; }
    virtual int getNbSourceStreams() const { return 0; }

    virtual qint64 getStreamCenterFrequency(int streamIndex, bool sinkElseSource) const
    {
        (void) streamIndex;
        (void) sinkElseSource;
        return 0;
    }

    virtual int webapiSettingsGet(
            SWGrpx-100::SWGChannelSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& channelSettingsKeys,
            SWGrpx-100::SWGChannelSettings& response,
            QString& errorMessage);

    static void webapiFormatChannelSettings(
            SWGrpx-100::SWGChannelSettings& response,
            const PacketDemodSettings& settings);

    static void webapiUpdateChannelSettings(
            PacketDemodSettings& settings,
            const QStringList& channelSettingsKeys,
            SWGrpx-100::SWGChannelSettings& response);

    double getMagSq() const { return m_basebandSink->getMagSq(); }

    void getMagSqLevels(double& avg, double& peak, int& nbSamples) {
        m_basebandSink->getMagSqLevels(avg, peak, nbSamples);
    }
/*    void setMessageQueueToGUI(MessageQueue* queue) override {
        ChannelAPI::setMessageQueueToGUI(queue);
        m_basebandSink->setMessageQueueToGUI(queue);
    }*/

    uint32_t getNumberOfDeviceStreams() const;

    static const char * const m_channelIdURI;
    static const char * const m_channelId;

private:
    DeviceAPI *m_deviceAPI;
    QThread m_thread;
    PacketDemodBaseband* m_basebandSink;
    PacketDemodSettings m_settings;
    int m_basebandSampleRate; //!< stored from device message used when starting baseband sink
    qint64 m_centerFrequency;
    QUdpSocket m_udpSocket;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void applySettings(const PacketDemodSettings& settings, bool force = false);
    void sendSampleRateToDemodAnalyzer();
    void webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const PacketDemodSettings& settings, bool force);
    void webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings *swgChannelSettings,
        const PacketDemodSettings& settings,
        bool force
    );

private slots:
    void networkManagerFinished(QNetworkReply *reply);
    void handleChannelMessages();

};

#endif // INCLUDE_PACKETDEMOD_H
