///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
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

#ifndef INCLUDE_RTLSDRINPUT_H
#define INCLUDE_RTLSDRINPUT_H

#include <QString>
#include <QByteArray>
#include <QNetworkRequest>

#include "dsp/devicesamplesource.h"
#include "rtlsdrsettings.h"
#include <rtl-sdr.h>

class DeviceAPI;
class RTLSDRThread;
class QNetworkAccessManager;
class QNetworkReply;

class RTLSDRInput : public DeviceSampleSource {
    Q_OBJECT
public:
	class MsgConfigureRTLSDR : public Message {
		MESSAGE_CLASS_DECLARATION

	public:
		const RTLSDRSettings& getSettings() const { return m_settings; }
		bool getForce() const { return m_force; }

		static MsgConfigureRTLSDR* create(const RTLSDRSettings& settings, bool force)
		{
			return new MsgConfigureRTLSDR(settings, force);
		}

	private:
		RTLSDRSettings m_settings;
		bool m_force;

		MsgConfigureRTLSDR(const RTLSDRSettings& settings, bool force) :
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

	RTLSDRInput(DeviceAPI *deviceAPI);
	virtual ~RTLSDRInput();
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

    virtual int webapiReportGet(
            SWGrpx-100::SWGDeviceReport& response,
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
            const RTLSDRSettings& settings);

    static void webapiUpdateDeviceSettings(
            RTLSDRSettings& settings,
            const QStringList& deviceSettingsKeys,
            SWGrpx-100::SWGDeviceSettings& response);

	const std::vector<int>& getGains() const { return m_gains; }
	void set_ds_mode(int on);

	static const quint64 frequencyLowRangeMin;
	static const quint64 frequencyLowRangeMax;
    static const quint64 frequencyHighRangeMin;
    static const quint64 frequencyHighRangeMax;
	static const int sampleRateLowRangeMin;
    static const int sampleRateLowRangeMax;
    static const int sampleRateHighRangeMin;
    static const int sampleRateHighRangeMax;

private:
	DeviceAPI *m_deviceAPI;
	QMutex m_mutex;
	RTLSDRSettings m_settings;
	rtlsdr_dev_t* m_dev;
	RTLSDRThread* m_rtlSDRThread;
	QString m_deviceDescription;
	std::vector<int> m_gains;
	bool m_running;
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

	bool openDevice();
	void closeDevice();
	bool applySettings(const RTLSDRSettings& settings, bool force);
    void webapiFormatDeviceReport(SWGrpx-100::SWGDeviceReport& response);
    void webapiReverseSendSettings(QList<QString>& deviceSettingsKeys, const RTLSDRSettings& settings, bool force);
    void webapiReverseSendStartStop(bool start);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_RTLSDRINPUT_H
