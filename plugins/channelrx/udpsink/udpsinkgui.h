///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 oe3bia                                                      //
// written by Bernhard Isemann                                                  //
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

#ifndef INCLUDE_UDPSRCGUI_H
#define INCLUDE_UDPSRCGUI_H

#include <QHostAddress>
#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "dsp/movingaverage.h"
#include "util/messagequeue.h"

#include "udpsink.h"
#include "udpsinksettings.h"

class PluginAPI;
class DeviceUISet;
class UDPSink;
class SpectrumVis;

namespace Ui {
	class UDPSinkGUI;
}

class UDPSinkGUI : public ChannelGUI {
	Q_OBJECT

public:
	static UDPSinkGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
	virtual void destroy();

	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
	virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
	void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

private:
	Ui::UDPSinkGUI* ui;
	PluginAPI* m_pluginAPI;
	DeviceUISet* m_deviceUISet;
	UDPSink* m_udpSink;
	UDPSinkSettings m_settings;
	ChannelMarker m_channelMarker;
	MovingAverage<double> m_channelPowerAvg;
    MovingAverage<double> m_inPowerAvg;
	uint32_t m_tickCount;

	// settings
	bool m_doApplySettings;
	bool m_rfBandwidthChanged;
	MessageQueue m_inputMessageQueue;

	// RF path
	SpectrumVis* m_spectrumVis;

	explicit UDPSinkGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
	virtual ~UDPSinkGUI();

    void blockApplySettings(bool block);
	void applySettings(bool force = false);
	void applySettingsImmediate(bool force = false);
	void displaySettings();
    void displayStreamIndex();
	void setSampleFormat(int index);
	void setSampleFormatIndex(const UDPSinkSettings::SampleFormat& sampleFormat);
	bool handleMessage(const Message& message);

	void leaveEvent(QEvent*);
	void enterEvent(QEvent*);

private slots:
    void handleSourceMessages();
	void on_deltaFrequency_changed(qint64 value);
	void on_sampleFormat_currentIndexChanged(int index);
	void on_outputUDPAddress_editingFinished();
	void on_outputUDPPort_editingFinished();
	void on_inputUDPAudioPort_editingFinished();
	void on_sampleRate_textEdited(const QString& arg1);
	void on_rfBandwidth_textEdited(const QString& arg1);
	void on_fmDeviation_textEdited(const QString& arg1);
	void on_audioActive_toggled(bool active);
	void on_audioStereo_toggled(bool stereo);
	void on_applyBtn_clicked();
	void onWidgetRolled(QWidget* widget, bool rollDown);
	void onMenuDialogCalled(const QPoint& p);
	void on_gain_valueChanged(int value);
	void on_volume_valueChanged(int value);
	void on_squelch_valueChanged(int value);
    void on_squelchGate_valueChanged(int value);
	void on_agc_toggled(bool agc);
	void tick();
};

#endif // INCLUDE_UDPSRCGUI_H
