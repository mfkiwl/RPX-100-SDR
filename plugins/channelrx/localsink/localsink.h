///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB.                                  //
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

#ifndef INCLUDE_LOCALSINK_H_
#define INCLUDE_LOCALSINK_H_

#include <QObject>
#include <QMutex>
#include <QNetworkRequest>

#include "dsp/basebandsamplesink.h"
#include "channel/channelapi.h"
#include "util/message.h"

#include "localsinksettings.h"

class QNetworkAccessManager;
class QNetworkReply;
class QThread;

class DeviceAPI;
class DeviceSampleSource;
class LocalSinkBaseband;

class LocalSink : public BasebandSampleSink, public ChannelAPI {
    Q_OBJECT
public:
    class MsgConfigureLocalSink : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const LocalSinkSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureLocalSink* create(const LocalSinkSettings& settings, bool force)
        {
            return new MsgConfigureLocalSink(settings, force);
        }

    private:
        LocalSinkSettings m_settings;
        bool m_force;

        MsgConfigureLocalSink(const LocalSinkSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    class MsgBasebandSampleRateNotification : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        static MsgBasebandSampleRateNotification* create(int sampleRate) {
            return new MsgBasebandSampleRateNotification(sampleRate);
        }

        int getSampleRate() const { return m_sampleRate; }

    private:

        MsgBasebandSampleRateNotification(int sampleRate) :
            Message(),
            m_sampleRate(sampleRate)
        { }

        int m_sampleRate;
    };

    LocalSink(DeviceAPI *deviceAPI);
    virtual ~LocalSink();
    virtual void destroy() { delete this; }

    using BasebandSampleSink::feed;
    virtual void feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool po);
    virtual void start();
    virtual void stop();
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) { id = objectName(); }
    virtual void getTitle(QString& title) { title = "Local Sink"; }
    virtual qint64 getCenterFrequency() const { return m_frequencyOffset; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual int getNbSinkStreams() const { return 1; }
    virtual int getNbSourceStreams() const { return 0; }

    virtual qint64 getStreamCenterFrequency(int streamIndex, bool sinkElseSource) const
    {
        (void) streamIndex;
        (void) sinkElseSource;
        return m_frequencyOffset;
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
        const LocalSinkSettings& settings);

    static void webapiUpdateChannelSettings(
            LocalSinkSettings& settings,
            const QStringList& channelSettingsKeys,
            SWGrpx-100::SWGChannelSettings& response);

    void getLocalDevices(std::vector<uint32_t>& indexes);
    uint32_t getNumberOfDeviceStreams() const;

    static const char* const m_channelIdURI;
    static const char* const m_channelId;

private:
    DeviceAPI *m_deviceAPI;
    QThread *m_thread;
    LocalSinkBaseband *m_basebandSink;
    LocalSinkSettings m_settings;

    uint64_t m_centerFrequency;
    int64_t m_frequencyOffset;
    uint32_t m_basebandSampleRate;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void applySettings(const LocalSinkSettings& settings, bool force = false);
    void propagateSampleRateAndFrequency(uint32_t index, uint32_t log2Decim);
    static void validateFilterChainHash(LocalSinkSettings& settings);
    void calculateFrequencyOffset(uint32_t log2Decim, uint32_t filterChainHash);
    DeviceSampleSource *getLocalDevice(uint32_t index);

    void webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const LocalSinkSettings& settings, bool force);
    void sendChannelSettings(
        QList<MessageQueue*> *messageQueues,
        QList<QString>& channelSettingsKeys,
        const LocalSinkSettings& settings,
        bool force
    );
    void webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings *swgChannelSettings,
        const LocalSinkSettings& settings,
        bool force
    );

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif /* INCLUDE_LOCALSINK_H_ */
