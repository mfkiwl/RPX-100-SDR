///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Bernhard Isemann, oe3bia                                   //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#ifndef PLUGINS_SAMPLESOURCE_USRPINPUT_USRPINPUTGUI_H_
#define PLUGINS_SAMPLESOURCE_USRPINPUT_USRPINPUTGUI_H_

#include <device/devicegui.h>
#include <QTimer>
#include <QWidget>

#include "util/messagequeue.h"

#include "usrpinput.h"

class DeviceUISet;

namespace Ui {
    class USRPInputGUI;
}

class USRPInputGUI : public DeviceGUI {
    Q_OBJECT

public:
    explicit USRPInputGUI(DeviceUISet *deviceUISet, QWidget* parent = 0);
    virtual ~USRPInputGUI();
    virtual void destroy();

    void setName(const QString& name);
    QString getName() const;

    void resetToDefaults();
    virtual qint64 getCenterFrequency() const;
    virtual void setCenterFrequency(qint64 centerFrequency);
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }
    virtual bool handleMessage(const Message& message);

private:
    Ui::USRPInputGUI* ui;

    DeviceUISet* m_deviceUISet;
    USRPInput* m_usrpInput; //!< Same object as above but gives easy access to USRPInput methods and attributes that are used intensively
    USRPInputSettings m_settings;
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
    void setCenterFrequencyDisplay();
    void setCenterFrequencySetting(uint64_t kHzValue);
    void sendSettings();
    void updateSampleRateAndFrequency();
    void updateSampleRate();
    void updateFrequencyLimits();
    void blockApplySettings(bool block);

private slots:
    void handleInputMessages();
    void on_startStop_toggled(bool checked);
    void on_centerFrequency_changed(quint64 value);
    void on_dcOffset_toggled(bool checked);
    void on_iqImbalance_toggled(bool checked);
    void on_sampleRate_changed(quint64 value);
    void on_swDecim_currentIndexChanged(int index);
    void on_lpf_changed(quint64 value);
    void on_loOffset_changed(qint64 value);
    void on_gainMode_currentIndexChanged(int index);
    void on_gain_valueChanged(int value);
    void on_antenna_currentIndexChanged(int index);
    void on_clockSource_currentIndexChanged(int index);
    void on_transverter_clicked();
    void on_sampleRateMode_toggled(bool checked);
    void openDeviceSettingsDialog(const QPoint& p);

    void updateHardware();
    void updateStatus();
};

#endif /* PLUGINS_SAMPLESOURCE_USRPINPUT_USRPINPUTGUI_H_ */
