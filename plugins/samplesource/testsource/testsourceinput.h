///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
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

#ifndef _TESTSOURCE_TESTSOURCEINPUT_H_
#define _TESTSOURCE_TESTSOURCEINPUT_H_

#include <QString>
#include <QByteArray>
#include <QTimer>
#include <QNetworkRequest>
#include <QThread>

#include <dsp/devicesamplesource.h>
#include "testsourcesettings.h"

class DeviceAPI;
class TestSourceWorker;
class QNetworkAccessManager;
class QNetworkReply;

class TestSourceInput : public DeviceSampleSource {
    Q_OBJECT
public:
	class MsgConfigureTestSource : public Message {
		MESSAGE_CLASS_DECLARATION

	public:
		const TestSourceSettings& getSettings() const { return m_settings; }
		bool getForce() const { return m_force; }

		static MsgConfigureTestSource* create(const TestSourceSettings& settings, bool force)
		{
			return new MsgConfigureTestSource(settings, force);
		}

	private:
		TestSourceSettings m_settings;
		bool m_force;

		MsgConfigureTestSource(const TestSourceSettings& settings, bool force) :
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

    TestSourceInput(DeviceAPI *deviceAPI);
	virtual ~TestSourceInput();
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
            const TestSourceSettings& settings);

    static void webapiUpdateDeviceSettings(
            TestSourceSettings& settings,
            const QStringList& deviceSettingsKeys,
            SWGRPX100::SWGDeviceSettings& response);

private:
	DeviceAPI *m_deviceAPI;
	QMutex m_mutex;
	TestSourceSettings m_settings;
	TestSourceWorker* m_testSourceWorker;
    QThread m_testSourceWorkerThread;
	QString m_deviceDescription;
	bool m_running;
    const QTimer& m_masterTimer;
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

	void startWorker();
	void stopWorker();
	bool applySettings(const TestSourceSettings& settings, bool force);
    void webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const TestSourceSettings& settings, bool force);
    void webapiReverseSendStartStop(bool start);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // _TESTSOURCE_TESTSOURCEINPUT_H_
