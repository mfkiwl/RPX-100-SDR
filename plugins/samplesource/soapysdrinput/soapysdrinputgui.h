///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
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

#ifndef PLUGINS_SAMPLESOURCE_SOAPYSDRINPUT_SOAPYSDRINPUTGUI_H_
#define PLUGINS_SAMPLESOURCE_SOAPYSDRINPUT_SOAPYSDRINPUTGUI_H_

#include <QTimer>
#include <QWidget>

#include "device/devicegui.h"
#include "util/messagequeue.h"

#include "soapysdrinput.h"

class DeviceUISet;
class ItemSettingGUI;
class StringRangeGUI;
class DynamicItemSettingGUI;
class DynamicArgSettingGUI;
class IntervalSliderGUI;
class QCheckBox;
class ComplexFactorGUI;

namespace Ui {
    class SoapySDRInputGui;
}

class SoapySDRInputGui : public DeviceGUI {
    Q_OBJECT

public:
    explicit SoapySDRInputGui(DeviceUISet *deviceUISet, QWidget* parent = 0);
    virtual ~SoapySDRInputGui();
    virtual void destroy();

    virtual void resetToDefaults();
    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);
    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

private:
    void createRangesControl(
            ItemSettingGUI **settingGUI,
            const SoapySDR::RangeList& rangeList,
            const QString& text,
            const QString& unit);
    void createAntennasControl(const std::vector<std::string>& antennaList);
    void createTunableElementsControl(const std::vector<DeviceSoapySDRParams::FrequencySetting>& tunableElementsList);
    void createGlobalGainControl();
    void createIndividualGainsControl(const std::vector<DeviceSoapySDRParams::GainSetting>& individualGainsList);
    void createCorrectionsControl();
    void createArgumentsControl(const SoapySDR::ArgInfoList& argInfoList, bool deviceArguments);

    Ui::SoapySDRInputGui* ui;

    DeviceUISet* m_deviceUISet;
    bool m_forceSettings;
    bool m_doApplySettings;
    SoapySDRInputSettings m_settings;
    QTimer m_updateTimer;
    QTimer m_statusTimer;
    SoapySDRInput* m_sampleSource;
    int m_sampleRate;
    quint64 m_deviceCenterFrequency; //!< Center frequency in device
    int m_lastEngineState;
    MessageQueue m_inputMessageQueue;

    StringRangeGUI *m_antennas;
    ItemSettingGUI *m_sampleRateGUI;
    ItemSettingGUI *m_bandwidthGUI;
    std::vector<DynamicItemSettingGUI*> m_tunableElementsGUIs;
    IntervalSliderGUI *m_gainSliderGUI;
    std::vector<DynamicItemSettingGUI*> m_individualGainsGUIs;
    QCheckBox *m_autoGain;
    ComplexFactorGUI *m_dcCorrectionGUI;
    ComplexFactorGUI *m_iqCorrectionGUI;
    QCheckBox *m_autoDCCorrection;
    QCheckBox *m_autoIQCorrection;
    std::vector<DynamicArgSettingGUI*> m_streamArgsGUIs;
    std::vector<DynamicArgSettingGUI*> m_deviceArgsGUIs;

    void displaySettings();
    void displayTunableElementsControlSettings();
    void displayIndividualGainsControlSettings();
    void displayCorrectionsSettings();
    void displayStreamArgsSettings();
    void displayDeviceArgsSettings();
    void sendSettings();
    void updateSampleRateAndFrequency();
    void updateFrequencyLimits();
    void setCenterFrequencySetting(uint64_t kHzValue);
    void blockApplySettings(bool block);
    bool handleMessage(const Message& message);

private slots:
    void handleInputMessages();
    void antennasChanged();
    void sampleRateChanged(double sampleRate);
    void bandwidthChanged(double bandwidth);
    void tunableElementChanged(QString name, double value);
    void globalGainChanged(double gain);
    void autoGainChanged(bool set);
    void individualGainChanged(QString name, double value);
    void autoDCCorrectionChanged(bool set);
    void autoIQCorrectionChanged(bool set);
    void dcCorrectionModuleChanged(double value);
    void dcCorrectionArgumentChanged(double value);
    void iqCorrectionModuleChanged(double value);
    void iqCorrectionArgumentChanged(double value);
    void streamArgChanged(QString itemName, QVariant value);
    void deviceArgChanged(QString itemName, QVariant value);

    void on_centerFrequency_changed(quint64 value);
    void on_LOppm_valueChanged(int value);
    void on_dcOffset_toggled(bool checked);
    void on_iqImbalance_toggled(bool checked);
    void on_decim_currentIndexChanged(int index);
    void on_fcPos_currentIndexChanged(int index);
    void on_transverter_clicked();
    void on_startStop_toggled(bool checked);
    void updateHardware();
    void updateStatus();
    void openDeviceSettingsDialog(const QPoint& p);
};



#endif /* PLUGINS_SAMPLESOURCE_SOAPYSDRINPUT_SOAPYSDRINPUTGUI_H_ */
