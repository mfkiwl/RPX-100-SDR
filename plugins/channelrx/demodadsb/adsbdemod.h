///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#ifndef INCLUDE_ADSBDEMOD_H
#define INCLUDE_ADSBDEMOD_H

#include <vector>

#include <QNetworkRequest>

#include "dsp/basebandsamplesink.h"
#include "channel/channelapi.h"
#include "util/message.h"

#include "adsbdemodbaseband.h"
#include "adsbdemodsettings.h"

class QNetworkAccessManager;
class QNetworkReply;
class QThread;
class DeviceAPI;
class ADSBDemodWorker;

class ADSBDemod : public BasebandSampleSink, public ChannelAPI {
    Q_OBJECT
public:
    class MsgConfigureADSBDemod : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const ADSBDemodSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureADSBDemod* create(const ADSBDemodSettings& settings, bool force)
        {
            return new MsgConfigureADSBDemod(settings, force);
        }

    private:
        ADSBDemodSettings m_settings;
        bool m_force;

        MsgConfigureADSBDemod(const ADSBDemodSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    ADSBDemod(DeviceAPI *deviceAPI);
    virtual ~ADSBDemod();
    virtual void destroy() { delete this; }

    using BasebandSampleSink::feed;
    virtual void feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool po);
    virtual void start();
    virtual void stop();
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) { id = objectName(); }
    virtual void getTitle(QString& title) { title = m_settings.m_title; }
    virtual qint64 getCenterFrequency() const { return m_settings.m_inputFrequencyOffset; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual int getNbSinkStreams() const { return 1; }
    virtual int getNbSourceStreams() const { return 0; }

    virtual qint64 getStreamCenterFrequency(int streamIndex, bool sinkElseSource) const
    {
        (void) streamIndex;
        (void) sinkElseSource;
        return m_settings.m_inputFrequencyOffset;
    }

    virtual int webapiSettingsGet(
            SWGRPX100::SWGChannelSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGChannelSettings& response,
            QString& errorMessage);

    virtual int webapiReportGet(
            SWGRPX100::SWGChannelReport& response,
            QString& errorMessage);

    static void webapiFormatChannelSettings(
        SWGRPX100::SWGChannelSettings& response,
        const ADSBDemodSettings& settings);

    static void webapiUpdateChannelSettings(
            ADSBDemodSettings& settings,
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGChannelSettings& response);

    void getMagSqLevels(double& avg, double& peak, int& nbSamples) { m_basebandSink->getMagSqLevels(avg, peak, nbSamples); }
    void setMessageQueueToGUI(MessageQueue* queue) override {
        ChannelAPI::setMessageQueueToGUI(queue);
        m_basebandSink->setMessageQueueToGUI(queue);
    }

    void setTarget(const QString& name, float targetAzimuth, float targetElevation);
    void clearTarget() { m_targetAzElValid = false; }

    uint32_t getNumberOfDeviceStreams() const;

    static const char* const m_channelIdURI;
    static const char* const m_channelId;

private:
    DeviceAPI* m_deviceAPI;
    QThread *m_thread;
    ADSBDemodWorker *m_worker;
    ADSBDemodBaseband* m_basebandSink;
    ADSBDemodSettings m_settings;
    int m_basebandSampleRate; //!< stored from device message used when starting baseband sink

    bool m_targetAzElValid;
    float m_targetAzimuth;
    float m_targetElevation;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void applySettings(const ADSBDemodSettings& settings, bool force = false);
    void webapiFormatChannelReport(SWGRPX100::SWGChannelReport& response);
    void webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const ADSBDemodSettings& settings, bool force);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_ADSBDEMOD_H
