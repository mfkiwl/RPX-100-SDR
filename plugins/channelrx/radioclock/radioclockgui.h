///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Bernhard Isemann, oe3bia                                   //
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
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

#ifndef INCLUDE_RADIOCLOCKGUI_H
#define INCLUDE_RADIOCLOCKGUI_H

#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "util/messagequeue.h"

#include "radioclocksettings.h"
#include "radioclock.h"

class PluginAPI;
class DeviceUISet;
class BasebandSampleSink;
class ScopeVis;
class ScopeVisXY;
class RadioClock;
class RadioClockGUI;

namespace Ui {
    class RadioClockGUI;
}
class RadioClockGUI;

class RadioClockGUI : public ChannelGUI {
    Q_OBJECT

public:
    static RadioClockGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
    virtual void destroy();

    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
    void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

private:
    Ui::RadioClockGUI* ui;
    PluginAPI* m_pluginAPI;
    DeviceUISet* m_deviceUISet;
    ChannelMarker m_channelMarker;
    RadioClockSettings m_settings;
    bool m_doApplySettings;
    ScopeVis* m_scopeVis;

    RadioClock* m_radioClock;
    uint32_t m_tickCount;
    MessageQueue m_inputMessageQueue;

    QDateTime m_dateTime;

    explicit RadioClockGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
    virtual ~RadioClockGUI();

    void blockApplySettings(bool block);
    void applySettings(bool force = false);
    void displaySettings();
    void displayStreamIndex();
    bool handleMessage(const Message& message);
    void displayDateTime();

    void leaveEvent(QEvent*);
    void enterEvent(QEvent*);

private slots:
    void on_deltaFrequency_changed(qint64 value);
    void on_rfBW_valueChanged(int index);
    void on_threshold_valueChanged(int value);
    void on_modulation_currentIndexChanged(int index);
    void on_timezone_currentIndexChanged(int index);
    void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void handleInputMessages();
    void tick();
};

#endif // INCLUDE_RADIOCLOCKGUI_H
