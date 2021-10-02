///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015-2018 Edouard Griffiths, F4EXB                              //
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

#ifndef INCLUDE_FCDPROINPUT_H
#define INCLUDE_FCDPROINPUT_H

#include <inttypes.h>

#include <QString>
#include <QByteArray>
#include <QNetworkRequest>

#include "dsp/devicesamplesource.h"
#include "audio/audioinputdevice.h"
#include "audio/audiofifo.h"

#include "fcdprosettings.h"
#include "fcdhid.h"

struct fcd_buffer {
	void *start;
	std::size_t length;
};

class QNetworkAccessManager;
class QNetworkReply;
class DeviceAPI;
class FCDProThread;

class FCDProInput : public DeviceSampleSource {
    Q_OBJECT
public:
	class MsgConfigureFCDPro : public Message {
		MESSAGE_CLASS_DECLARATION

	public:
		const FCDProSettings& getSettings() const { return m_settings; }
		bool getForce() const { return m_force; }

		static MsgConfigureFCDPro* create(const FCDProSettings& settings, bool force)
		{
			return new MsgConfigureFCDPro(settings, force);
		}

	private:
		FCDProSettings m_settings;
		bool m_force;

		MsgConfigureFCDPro(const FCDProSettings& settings, bool force) :
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

	FCDProInput(DeviceAPI *deviceAPI);
	virtual ~FCDProInput();
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
                SWGrpx-100::SWGDeviceSettings& response,
                QString& errorMessage);

    virtual int webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGrpx-100::SWGDeviceSettings& response, // query + response
                QString& errorMessage);

    virtual int webapiRunGet(
            SWGrpx-100::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiRun(
            bool run,
            SWGrpx-100::SWGDeviceState& response,
            QString& errorMessage);

    static void webapiFormatDeviceSettings(
            SWGrpx-100::SWGDeviceSettings& response,
            const FCDProSettings& settings);

    static void webapiUpdateDeviceSettings(
            FCDProSettings& settings,
            const QStringList& deviceSettingsKeys,
            SWGrpx-100::SWGDeviceSettings& response);

    void set_center_freq(double freq);
	void set_bias_t(bool on);
	void set_lnaGain(int index);
	void set_rfFilter(int index);
	void set_lnaEnhance(int index);
	void set_band(int index);
	void set_mixerGain(int index);
	void set_mixerFilter(int index);
	void set_biasCurrent(int index);
	void set_mode(int index);
	void set_gain1(int index);
	void set_rcFilter(int index);
	void set_gain2(int index);
	void set_gain3(int index);
	void set_gain4(int index);
	void set_ifFilter(int index);
	void set_gain5(int index);
	void set_gain6(int index);

private:
	DeviceAPI *m_deviceAPI;
	hid_device *m_dev;
    AudioInputDevice m_fcdAudioInput;
    AudioFifo m_fcdFIFO;
	QMutex m_mutex;
	FCDProSettings m_settings;
	FCDProThread* m_FCDThread;
	QString m_deviceDescription;
	bool m_running;
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    bool openDevice();
    void closeDevice();
    bool openFCDAudio(const char *filename);
    void closeFCDAudio();
	void applySettings(const FCDProSettings& settings, bool force);

    void webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const FCDProSettings& settings, bool force);
    void webapiReverseSendStartStop(bool start);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_FCDPROINPUT_H
