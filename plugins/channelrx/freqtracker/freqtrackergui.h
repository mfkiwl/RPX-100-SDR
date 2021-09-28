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

#ifndef INCLUDE_FREQTRACKERGUI_H
#define INCLUDE_FREQTRACKERGUI_H

#include <QIcon>

#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "dsp/movingaverage.h"
#include "util/messagequeue.h"
#include "freqtrackersettings.h"

class PluginAPI;
class DeviceUISet;
class FreqTracker;
class BasebandSampleSink;
class SpectrumVis;

namespace Ui {
	class FreqTrackerGUI;
}

class FreqTrackerGUI : public ChannelGUI {
	Q_OBJECT

public:
	static FreqTrackerGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
	virtual void destroy();

	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
	virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
	void channelMarkerChangedByCursor();
	void channelMarkerHighlightedByCursor();

private:
	Ui::FreqTrackerGUI* ui;
	PluginAPI* m_pluginAPI;
	DeviceUISet* m_deviceUISet;
	ChannelMarker m_channelMarker;
	ChannelMarker m_pllChannelMarker;
	FreqTrackerSettings m_settings;
	int m_basebandSampleRate;
	bool m_doApplySettings;

	FreqTracker* m_freqTracker;
	SpectrumVis* m_spectrumVis;
	bool m_squelchOpen;
	uint32_t m_tickCount;
	MessageQueue m_inputMessageQueue;

	explicit FreqTrackerGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
	virtual ~FreqTrackerGUI();

    void blockApplySettings(bool block);
	void applySettings(bool force = false);
	void applySpectrumBandwidth(int spanLog2, bool force = false);
	void displaySettings();
	void displaySpectrumBandwidth(int spanLog2);
    void displayStreamIndex();
	bool handleMessage(const Message& message);

	void leaveEvent(QEvent*);
	void enterEvent(QEvent*);

private slots:
	void on_deltaFrequency_changed(qint64 value);
    void on_log2Decim_currentIndexChanged(int index);
	void on_rfBW_valueChanged(int value);
	void on_tracking_toggled(bool checked);
	void on_alphaEMA_valueChanged(int value);
    void on_trackerType_currentIndexChanged(int index);
    void on_pllPskOrder_currentIndexChanged(int index);
    void on_rrc_toggled(bool checked);
	void on_rrcRolloff_valueChanged(int value);
	void on_squelch_valueChanged(int value);
    void on_squelchGate_valueChanged(int value);
	void on_spanLog2_valueChanged(int value);
	void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void handleInputMessages();
	void tick();
};

#endif // INCLUDE_FREQTRACKERGUI_H
