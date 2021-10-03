///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
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

#ifndef INCLUDE_FREEDVDEMODGUI_H
#define INCLUDE_FREEDVDEMODGUI_H

#include <QIcon>

#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "dsp/movingaverage.h"
#include "util/messagequeue.h"
#include "freedvdemodsettings.h"

class PluginAPI;
class DeviceUISet;

class AudioFifo;
class FreeDVDemod;
class SpectrumVis;
class BasebandSampleSink;

namespace Ui {
	class FreeDVDemodGUI;
}

class FreeDVDemodGUI : public ChannelGUI {
	Q_OBJECT

public:
	static FreeDVDemodGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
	virtual void destroy();

	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
	virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
	void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

private:
	Ui::FreeDVDemodGUI* ui;
	PluginAPI* m_pluginAPI;
	DeviceUISet* m_deviceUISet;
	ChannelMarker m_channelMarker;
	FreeDVDemodSettings m_settings;
	bool m_doApplySettings;
    int m_spectrumRate;
	bool m_audioBinaural;
	bool m_audioFlipChannels;
	bool m_audioMute;
	bool m_squelchOpen;
    int m_audioSampleRate;
	uint32_t m_tickCount;

	FreeDVDemod* m_freeDVDemod;
	SpectrumVis* m_spectrumVis;
	MessageQueue m_inputMessageQueue;

	QIcon m_iconDSBUSB;
	QIcon m_iconDSBLSB;

	explicit FreeDVDemodGUI(PluginAPI* pluginAPI, DeviceUISet* deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
	virtual ~FreeDVDemodGUI();

    bool blockApplySettings(bool block);
	void applySettings(bool force = false);
	void applyBandwidths(int spanLog2, bool force = false);
	void displayBandwidths(int spanLog2);
	void displaySettings();
    void displayStreamIndex();
	bool handleMessage(const Message& message);

	void leaveEvent(QEvent*);
	void enterEvent(QEvent*);

private slots:
	void on_deltaFrequency_changed(qint64 value);
	void on_reSync_clicked(bool checked);
    void on_freeDVMode_currentIndexChanged(int index);
	void on_volume_valueChanged(int value);
	void on_volumeIn_valueChanged(int value);
	void on_agc_toggled(bool checked);
	void on_audioMute_toggled(bool checked);
	void on_spanLog2_valueChanged(int value);
	void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void handleInputMessages();
    void audioSelect();
	void tick();
};

#endif // INCLUDE_FREEDVDEMODGUI_H
