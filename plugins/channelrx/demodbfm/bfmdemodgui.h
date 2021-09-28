///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
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

#ifndef INCLUDE_BFMDEMODGUI_H
#define INCLUDE_BFMDEMODGUI_H

#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "util/messagequeue.h"
#include "bfmdemodsettings.h"

class PluginAPI;
class DeviceUISet;
class RDSParser;

class SpectrumVis;
class BFMDemod;
class BasebandSampleSink;

namespace Ui {
	class BFMDemodGUI;
}

class BFMDemodGUI : public ChannelGUI {
	Q_OBJECT

public:
	static BFMDemodGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceAPI, BasebandSampleSink *rxChannel);
	virtual void destroy();

	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
	virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
    void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

private:
	Ui::BFMDemodGUI* ui;
	PluginAPI* m_pluginAPI;
	DeviceUISet* m_deviceUISet;
	ChannelMarker m_channelMarker;
	BFMDemodSettings m_settings;
	bool m_doApplySettings;
	int m_rdsTimerCount;

	SpectrumVis* m_spectrumVis;

	BFMDemod* m_bfmDemod;
	int m_rate;
	std::vector<unsigned int> m_g14ComboIndex;
	MessageQueue m_inputMessageQueue;

	explicit BFMDemodGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
	virtual ~BFMDemodGUI();

    void blockApplySettings(bool block);
	void applySettings(bool force = false);
    void displaySettings();
    void displayStreamIndex();
	void rdsUpdate(bool force);
	void rdsUpdateFixedFields();
	bool handleMessage(const Message& message);

	void leaveEvent(QEvent*);
	void enterEvent(QEvent*);

	void changeFrequency(qint64 f);

private slots:
	void on_deltaFrequency_changed(qint64 value);
	void on_rfBW_valueChanged(int value);
	void on_afBW_valueChanged(int value);
	void on_volume_valueChanged(int value);
	void on_squelch_valueChanged(int value);
	void on_audioStereo_toggled(bool stereo);
	void on_lsbStereo_toggled(bool lsb);
	void on_showPilot_clicked();
	void on_rds_clicked();
	void on_g14ProgServiceNames_currentIndexChanged(int index);
	void on_clearData_clicked(bool checked);
	void on_g00AltFrequenciesBox_activated(int index);
	void on_g14MappedFrequencies_activated(int index);
	void on_g14AltFrequencies_activated(int index);
	void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void handleInputMessages();
    void audioSelect();
	void tick();
};

#endif // INCLUDE_BFMDEMODGUI_H
