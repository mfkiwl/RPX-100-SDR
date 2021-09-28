///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Edouard Griffiths, F4EXB                                   //
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

#ifndef INCLUDE_NOISEFIGUREGUI_H
#define INCLUDE_NOISEFIGUREGUI_H

#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QMenu>
#include <QtCharts>

#include "channel/channelgui.h"
#include "dsp/channelmarker.h"
#include "util/messagequeue.h"

#include "noisefiguresettings.h"
#include "noisefigure.h"

class PluginAPI;
class DeviceUISet;
class BasebandSampleSink;
class NoiseFigure;
class NoiseFigureGUI;

namespace Ui {
    class NoiseFigureGUI;
}

using namespace QtCharts;

class NoiseFigureGUI : public ChannelGUI {
    Q_OBJECT

public:
    static NoiseFigureGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel);
    virtual void destroy();

    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }

public slots:
    void channelMarkerChangedByCursor();
    void channelMarkerHighlightedByCursor();

private:
    Ui::NoiseFigureGUI* ui;
    PluginAPI* m_pluginAPI;
    DeviceUISet* m_deviceUISet;
    ChannelMarker m_channelMarker;
    NoiseFigureSettings m_settings;
    bool m_doApplySettings;

    NoiseFigure* m_noiseFigure;
    int m_basebandSampleRate;
    uint32_t m_tickCount;
    bool m_runningTest;
    MessageQueue m_inputMessageQueue;

    QMenu *resultsMenu;                        //<! Column select context menu
    QMenu *copyMenu;                           //<! Copy menu

    QChart *m_chart;

    QString m_refFilename;                      //<! Reference data to plot on chart
    QVector<double> m_refData;
    int m_refCols;

    explicit NoiseFigureGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent = 0);
    virtual ~NoiseFigureGUI();

    void blockApplySettings(bool block);
    void applySettings(bool force = false);
    void displaySettings();
    void displayStreamIndex();
    bool handleMessage(const Message& message);

    void leaveEvent(QEvent*);
    void enterEvent(QEvent*);

    void resizeTable();
    QAction *createCheckableItem(QString& text, int idx, bool checked, const char *slot);
    void updateBW();
    void updateFreqWidgets();
    void measurementReceived(NoiseFigure::MsgNFMeasurement& report);
    void plotChart();

    enum MessageCol {
        RESULTS_COL_FREQ,
        RESULTS_COL_NF,
        RESULTS_COL_TEMP,
        RESULTS_COL_Y,
        RESULTS_COL_ENR,
        RESULTS_COL_FLOOR
    };

private slots:
    void on_deltaFrequency_changed(qint64 value);
    void on_fftCount_valueChanged(int value);
    void on_frequencySpec_currentIndexChanged(int index);
    void on_start_valueChanged(double value);
    void on_stop_valueChanged(double value);
    void on_steps_valueChanged(int value);
    void on_step_valueChanged(double value);
    void on_frequencies_editingFinished();
    void on_fftSize_currentIndexChanged(int index);
    void on_startStop_clicked();
    void on_saveResults_clicked();
    void on_clearResults_clicked();
    void on_enr_clicked();
    void on_control_clicked();
    void on_chartSelect_currentIndexChanged(int index);
    void on_openReference_clicked();
    void on_clearReference_clicked();
    void results_sectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex);
    void results_sectionResized(int logicalIndex, int oldSize, int newSize);
    void resultsColumnSelectMenu(QPoint pos);
    void resultsColumnSelectMenuChecked(bool checked = false);
    void customContextMenuRequested(QPoint point);
    void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void handleInputMessages();
    void tick();
};

#endif // INCLUDE_NOISEFIGUREGUI_H
