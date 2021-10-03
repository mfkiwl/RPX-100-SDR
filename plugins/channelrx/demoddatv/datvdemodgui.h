///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 F4HKW                                                      //
// for oe3bia / RPX100                                                          //
// using LeanSDR Framework (C) 2016 F4DAV                                        //
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

#ifndef INCLUDE_DATVDEMODGUI_H
#define INCLUDE_DATVDEMODGUI_H

#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "dsp/movingaverage.h"

#include "datvdemod.h"

#include <QTimer>


class PluginAPI;
class DeviceUISet;
class BasebandSampleSink;

namespace Ui
{
    class DATVDemodGUI;
}

class DATVDemodGUI : public ChannelGUI
{
	Q_OBJECT

public:
    static DATVDemodGUI* create(PluginAPI* objPluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
    virtual void destroy();

	void resetToDefaults();
	QByteArray serialize() const;
    bool deserialize(const QByteArray& arrData);

    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

    static const char* const m_strChannelID;

private slots:
    void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

    void onWidgetRolled(QWidget* widget, bool rollDown);
	void onMenuDialogCalled(const QPoint& p);
    void handleInputMessages();
    void audioSelect();
    void ldpcToolSelect();
    void tick();

    void on_cmbStandard_currentIndexChanged(int index);
    void on_cmbModulation_currentIndexChanged(const QString &arg1);
    void on_cmbFEC_currentIndexChanged(const QString &arg1);
    void on_softLDPC_clicked();
    void on_maxBitflips_valueChanged(int value);
    void on_chkViterbi_clicked();
    void on_chkHardMetric_clicked();
    void on_resetDefaults_clicked();
    void on_spiSymbolRate_valueChanged(int arg1);
    void on_spiNotchFilters_valueChanged(int arg1);
    void on_chkAllowDrift_clicked();
    void on_fullScreen_clicked();
    void on_mouseEvent(QMouseEvent* obj);
    void on_StreamDataAvailable(int intBytes, int intPercent, qint64 intTotalReceived);
    void on_StreamMetaDataChanged(DataTSMetaData2 *objMetaData);
    void on_chkFastlock_clicked();
    void on_cmbFilter_currentIndexChanged(int index);
    void on_spiRollOff_valueChanged(int arg1);
    void on_spiExcursion_valueChanged(int arg1);
    void on_deltaFrequency_changed(qint64 value);
    void on_rfBandwidth_changed(qint64 value);
    void on_audioMute_toggled(bool checked);
    void on_audioVolume_valueChanged(int value);
    void on_videoMute_toggled(bool checked);
    void on_udpTS_clicked(bool checked);
    void on_udpTSAddress_editingFinished();
    void on_udpTSPort_editingFinished();
    void on_playerEnable_clicked();

private:
    Ui::DATVDemodGUI* ui;
    PluginAPI* m_objPluginAPI;
    DeviceUISet* m_deviceUISet;

    ChannelMarker m_objChannelMarker;
    DATVDemod* m_objDATVDemod;
    MessageQueue m_inputMessageQueue;
    DATVDemodSettings m_settings;

    QTimer m_objTimer;
    qint64 m_intPreviousDecodedData;
    qint64 m_intLastDecodedData;
    qint64 m_intLastSpeed;
    int m_intReadyDecodedData;

    bool m_blnBasicSettingsShown;
    bool m_blnDoApplySettings;
    bool m_blnButtonPlayClicked;
    int m_modcodModulationIndex;
    int m_modcodCodeRateIndex;
    bool m_cstlnSetByModcod;

    MovingAverageUtil<double, double, 4> m_objMagSqAverage;

    explicit DATVDemodGUI(PluginAPI* objPluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* objParent = 0);
    virtual ~DATVDemodGUI();

    void blockApplySettings(bool blnBlock);
	void applySettings(bool force = false);
    void displaySettings();
    void displaySystemConfiguration();
    void displayStreamIndex();
    QString formatBytes(qint64 intBytes);

    void displayRRCParameters(bool blnVisible);

	void leaveEvent(QEvent*);
	void enterEvent(QEvent*);
    bool handleMessage(const Message& objMessage);
};

#endif // INCLUDE_DATVDEMODGUI_H
