///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017, 2018 Edouard Griffiths, F4EXB                             //
// Copyright (C) 2017 Sergey Kostanbaev, Fairwaves Inc.                          //
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

#ifndef PLUGINS_SAMPLESOURCE_XTRXINPUT_XTRXINPUTGUI_H_
#define PLUGINS_SAMPLESOURCE_XTRXINPUT_XTRXINPUTGUI_H_

#include <device/devicegui.h>
#include <QTimer>
#include <QWidget>

#include "util/messagequeue.h"

#include "xtrxinput.h"

class DeviceUISet;

namespace Ui {
class XTRXInputGUI;
}

class XTRXInputGUI : public DeviceGUI {
    Q_OBJECT

public:
    explicit XTRXInputGUI(DeviceUISet *deviceUISet, QWidget* parent = 0);
    virtual ~XTRXInputGUI();
    virtual void destroy();

    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

private:
    Ui::XTRXInputGUI* ui;

    DeviceUISet* m_deviceUISet;
    XTRXInput* m_XTRXInput; //!< Same object as above but gives easy access to XTRXInput methods and attributes that are used intensively
    XTRXInputSettings m_settings;
    bool m_sampleRateMode; //!< true: device, false: base band sample rate update mode
    QTimer m_updateTimer;
    QTimer m_statusTimer;
    int m_sampleRate;
    quint64 m_deviceCenterFrequency; //!< Center frequency in device
    int m_lastEngineState;
    bool m_doApplySettings;
    bool m_forceSettings;
    int m_statusCounter;
    int m_deviceStatusCounter;
    MessageQueue m_inputMessageQueue;

    void displaySettings();
    void displaySampleRate();
    void setNCODisplay();
    void setCenterFrequencyDisplay();
    void setCenterFrequencySetting(uint64_t kHzValue);
    void sendSettings();
    void updateSampleRateAndFrequency();
    void updateADCRate();
    void blockApplySettings(bool block);
    bool handleMessage(const Message& message);

private slots:
    void handleInputMessages();
    void on_startStop_toggled(bool checked);
    void on_centerFrequency_changed(quint64 value);
    void on_ncoFrequency_changed(qint64 value);
    void on_ncoEnable_toggled(bool checked);
    void on_dcOffset_toggled(bool checked);
    void on_iqImbalance_toggled(bool checked);
    void on_sampleRate_changed(quint64 value);
    void on_hwDecim_currentIndexChanged(int index);
    void on_swDecim_currentIndexChanged(int index);
    void on_lpf_changed(quint64 value);
    void on_gainMode_currentIndexChanged(int index);
    void on_gain_valueChanged(int value);
    void on_lnaGain_valueChanged(int value);
    void on_tiaGain_currentIndexChanged(int index);
    void on_pgaGain_valueChanged(int value);
    void on_antenna_currentIndexChanged(int index);
    void on_extClock_clicked();
    void on_pwrmode_currentIndexChanged(int index);
    void on_sampleRateMode_toggled(bool checked);

    void updateHardware();
    void updateStatus();
    void openDeviceSettingsDialog(const QPoint& p);
};

#endif /* PLUGINS_SAMPLESOURCE_XTRXINPUT_XTRXINPUTGUI_H_ */
