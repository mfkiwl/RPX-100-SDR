///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 oe3bia                                                      //
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

#ifndef INCLUDE_DSDDEMODGUI_H
#define INCLUDE_DSDDEMODGUI_H

#include <QMenu>

#include "channel/channelgui.h"
#include "dsp/dsptypes.h"
#include "dsp/channelmarker.h"
#include "dsp/movingaverage.h"
#include "util/messagequeue.h"

#include "dsddemodsettings.h"
#include "dsdstatustextdialog.h"

class PluginAPI;
class DeviceUISet;
class BasebandSampleSink;
class ScopeVisXY;
class DSDDemod;

namespace Ui {
	class DSDDemodGUI;
}

class DSDDemodGUI : public ChannelGUI {
	Q_OBJECT

public:
	static DSDDemodGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
	virtual void destroy();

	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
	virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
	void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

private:
//	typedef enum
//	{
//	    signalFormatNone,
//	    signalFormatDMR,
//	    signalFormatDStar,
//	    signalFormatDPMR,
//		signalFormatYSF
//	} SignalFormat;

	Ui::DSDDemodGUI* ui;
	PluginAPI* m_pluginAPI;
	DeviceUISet* m_deviceUISet;
	ChannelMarker m_channelMarker;
	DSDDemodSettings m_settings;
	bool m_doApplySettings;

    ScopeVisXY* m_scopeVisXY;

	DSDDemod* m_dsdDemod;
	bool m_enableCosineFiltering;
	bool m_syncOrConstellation;
	bool m_slot1On;
    bool m_slot2On;
    bool m_tdmaStereo;
    bool m_audioMute;
	bool m_squelchOpen;
    int  m_audioSampleRate;
	uint32_t m_tickCount;

	float m_myLatitude;
	float m_myLongitude;

	MessageQueue m_inputMessageQueue;

	DSDStatusTextDialog m_dsdStatusTextDialog;

	explicit DSDDemodGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
	virtual ~DSDDemodGUI();

	void blockApplySettings(bool block);
	void applySettings(bool force = false);
    void displaySettings();
    void displayStreamIndex();
	void updateMyPosition();
	bool handleMessage(const Message& message);

	void leaveEvent(QEvent*);
	void enterEvent(QEvent*);

private slots:
    void on_deltaFrequency_changed(qint64 value);
    void on_rfBW_valueChanged(int index);
    void on_demodGain_valueChanged(int value);
    void on_volume_valueChanged(int value);
    void on_baudRate_currentIndexChanged(int index);
    void on_enableCosineFiltering_toggled(bool enable);
    void on_syncOrConstellation_toggled(bool checked);
	void on_traceLength_valueChanged(int value);
    void on_traceStroke_valueChanged(int value);
    void on_traceDecay_valueChanged(int value);
    void on_slot1On_toggled(bool checked);
    void on_slot2On_toggled(bool checked);
    void on_tdmaStereoSplit_toggled(bool checked);
    void on_fmDeviation_valueChanged(int value);
    void on_squelchGate_valueChanged(int value);
    void on_squelch_valueChanged(int value);
    void on_highPassFilter_toggled(bool checked);
    void on_audioMute_toggled(bool checked);
    void on_symbolPLLLock_toggled(bool checked);
    void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void on_viewStatusLog_clicked();
    void handleInputMessages();
    void audioSelect();
    void tick();
};

#endif // INCLUDE_DSDDEMODGUI_H
