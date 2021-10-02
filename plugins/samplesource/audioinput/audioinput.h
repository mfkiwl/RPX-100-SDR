///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015-2018 Edouard Griffiths, F4EXB                              //
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

#ifndef INCLUDE_AUDIOINPUT_H
#define INCLUDE_AUDIOINPUT_H

#include <inttypes.h>

#include <QString>
#include <QByteArray>
#include <QNetworkRequest>
#include <QThread>

#include "dsp/devicesamplesource.h"
#include "audio/audioinputdevice.h"
#include "audio/audiofifo.h"

#include "audioinputsettings.h"

class QNetworkAccessManager;
class QNetworkReply;
class DeviceAPI;
class AudioInputWorker;

class AudioInput : public DeviceSampleSource {
    Q_OBJECT
public:
    class MsgConfigureAudioInput : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const AudioInputSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureAudioInput* create(const AudioInputSettings& settings, bool force)
        {
            return new MsgConfigureAudioInput(settings, force);
        }

    private:
        AudioInputSettings m_settings;
        bool m_force;

        MsgConfigureAudioInput(const AudioInputSettings& settings, bool force) :
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

    AudioInput(DeviceAPI *deviceAPI);
    virtual ~AudioInput();
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
    virtual void setCenterFrequency(qint64 centerFrequency) { (void) centerFrequency; }

    virtual bool handleMessage(const Message& message);

    virtual int webapiSettingsGet(
                SWGRPX100::SWGDeviceSettings& response,
                QString& errorMessage);

    virtual int webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGRPX100::SWGDeviceSettings& response, // query + response
                QString& errorMessage);

    virtual int webapiRunGet(
            SWGRPX100::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiRun(
            bool run,
            SWGRPX100::SWGDeviceState& response,
            QString& errorMessage);

    static void webapiFormatDeviceSettings(
            SWGRPX100::SWGDeviceSettings& response,
            const AudioInputSettings& settings);

    static void webapiUpdateDeviceSettings(
            AudioInputSettings& settings,
            const QStringList& deviceSettingsKeys,
            SWGRPX100::SWGDeviceSettings& response);

private:
    DeviceAPI *m_deviceAPI;
    AudioInputDevice m_audioInput;
    AudioFifo m_fifo;
    QMutex m_mutex;
    AudioInputSettings m_settings;
    AudioInputWorker* m_worker;
    QThread m_workerThread;
    QString m_deviceDescription;
    bool m_running;
    int m_sampleRate;
    qint64 m_centerFrequency;
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    bool openDevice();
    void closeDevice();
    bool openAudioDevice(QString deviceName, int sampleRate);
    void applySettings(const AudioInputSettings& settings, bool force, bool starting=false);

    void webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const AudioInputSettings& settings, bool force);
    void webapiReverseSendStartStop(bool start);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_AUDIOINPUT_H
