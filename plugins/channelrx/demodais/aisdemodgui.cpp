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

#include <limits>
#include <ctype.h>
#include <QDockWidget>
#include <QMainWindow>
#include <QDebug>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAction>
#include <QRegExp>
#include <QClipboard>

#include "aisdemodgui.h"

#include "device/deviceuiset.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "ui_aisdemodgui.h"
#include "plugin/pluginapi.h"
#include "util/simpleserializer.h"
#include "util/ais.h"
#include "util/db.h"
#include "gui/basicchannelsettingsdialog.h"
#include "gui/devicestreamselectiondialog.h"
#include "dsp/dspengine.h"
#include "dsp/glscopesettings.h"
#include "gui/crightclickenabler.h"
#include "channel/channelwebapiutils.h"
#include "maincore.h"
#include "feature/featurewebapiutils.h"

#include "aisdemod.h"
#include "aisdemodsink.h"

#include "SWGMapItem.h"

void AISDemodGUI::resizeTable()
{
    // Fill table with a row of dummy data that will size the columns nicely
    // Trailing spaces are for sort arrow
    int row = ui->messages->rowCount();
    ui->messages->setRowCount(row + 1);
    ui->messages->setItem(row, MESSAGE_COL_DATE, new QTableWidgetItem("Fri Apr 15 2016-"));
    ui->messages->setItem(row, MESSAGE_COL_TIME, new QTableWidgetItem("10:17:00"));
    ui->messages->setItem(row, MESSAGE_COL_MMSI, new QTableWidgetItem("123456789"));
    ui->messages->setItem(row, MESSAGE_COL_TYPE, new QTableWidgetItem("Position report"));
    ui->messages->setItem(row, MESSAGE_COL_DATA, new QTableWidgetItem("ABCEDGHIJKLMNOPQRSTUVWXYZ"));
    ui->messages->setItem(row, MESSAGE_COL_NMEA, new QTableWidgetItem("!AIVDM,1,1,,A,AAAAAAAAAAAAAAAAAAAAAAAAAAAA,0*00"));
    ui->messages->setItem(row, MESSAGE_COL_HEX, new QTableWidgetItem("04058804002000069a0760728d9e00000040000000"));
    ui->messages->resizeColumnsToContents();
    ui->messages->removeRow(row);
}

// Columns in table reordered
void AISDemodGUI::messages_sectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex)
{
    (void) oldVisualIndex;

    m_settings.m_messageColumnIndexes[logicalIndex] = newVisualIndex;
}

// Column in table resized (when hidden size is 0)
void AISDemodGUI::messages_sectionResized(int logicalIndex, int oldSize, int newSize)
{
    (void) oldSize;

    m_settings.m_messageColumnSizes[logicalIndex] = newSize;
}

// Right click in table header - show column select menu
void AISDemodGUI::messagesColumnSelectMenu(QPoint pos)
{
    messagesMenu->popup(ui->messages->horizontalHeader()->viewport()->mapToGlobal(pos));
}

// Hide/show column when menu selected
void AISDemodGUI::messagesColumnSelectMenuChecked(bool checked)
{
    (void) checked;

    QAction* action = qobject_cast<QAction*>(sender());
    if (action != nullptr)
    {
        int idx = action->data().toInt(nullptr);
        ui->messages->setColumnHidden(idx, !action->isChecked());
    }
}

// Create column select menu item
QAction *AISDemodGUI::createCheckableItem(QString &text, int idx, bool checked, const char *slot)
{
    QAction *action = new QAction(text, this);
    action->setCheckable(true);
    action->setChecked(checked);
    action->setData(QVariant(idx));
    connect(action, SIGNAL(triggered()), this, slot);
    return action;
}

AISDemodGUI* AISDemodGUI::create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel)
{
    AISDemodGUI* gui = new AISDemodGUI(pluginAPI, deviceUISet, rxChannel);
    return gui;
}

void AISDemodGUI::destroy()
{
    delete this;
}

void AISDemodGUI::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    applySettings(true);
}

QByteArray AISDemodGUI::serialize() const
{
    return m_settings.serialize();
}

bool AISDemodGUI::deserialize(const QByteArray& data)
{
    if(m_settings.deserialize(data)) {
        displaySettings();
        applySettings(true);
        return true;
    } else {
        resetToDefaults();
        return false;
    }
}

// Add row to table
void AISDemodGUI::messageReceived(const AISDemod::MsgMessage& message)
{
    AISMessage *ais;

    // Decode the message
    ais = AISMessage::decode(message.getMessage());

    // Add to messages table
    ui->messages->setSortingEnabled(false);
    int row = ui->messages->rowCount();
    ui->messages->setRowCount(row + 1);

    QTableWidgetItem *dateItem = new QTableWidgetItem();
    QTableWidgetItem *timeItem = new QTableWidgetItem();
    QTableWidgetItem *mmsiItem = new QTableWidgetItem();
    QTableWidgetItem *typeItem = new QTableWidgetItem();
    QTableWidgetItem *dataItem = new QTableWidgetItem();
    QTableWidgetItem *nmeaItem = new QTableWidgetItem();
    QTableWidgetItem *hexItem = new QTableWidgetItem();
    ui->messages->setItem(row, MESSAGE_COL_DATE, dateItem);
    ui->messages->setItem(row, MESSAGE_COL_TIME, timeItem);
    ui->messages->setItem(row, MESSAGE_COL_MMSI, mmsiItem);
    ui->messages->setItem(row, MESSAGE_COL_TYPE, typeItem);
    ui->messages->setItem(row, MESSAGE_COL_DATA, dataItem);
    ui->messages->setItem(row, MESSAGE_COL_NMEA, nmeaItem);
    ui->messages->setItem(row, MESSAGE_COL_HEX, hexItem);
    dateItem->setText(message.getDateTime().date().toString());
    timeItem->setText(message.getDateTime().time().toString());
    mmsiItem->setText(QString("%1").arg(ais->m_mmsi, 9, 10, QChar('0')));
    typeItem->setText(ais->getType());
    dataItem->setText(ais->toString());
    nmeaItem->setText(ais->toNMEA());
    hexItem->setText(ais->toHex());
    ui->messages->setSortingEnabled(true);
    ui->messages->scrollToItem(dateItem); // Will only scroll if not hidden
    filterRow(row);
}

bool AISDemodGUI::handleMessage(const Message& message)
{
    if (AISDemod::MsgConfigureAISDemod::match(message))
    {
        qDebug("AISDemodGUI::handleMessage: AISDemod::MsgConfigureAISDemod");
        const AISDemod::MsgConfigureAISDemod& cfg = (AISDemod::MsgConfigureAISDemod&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (AISDemod::MsgMessage::match(message))
    {
        AISDemod::MsgMessage& report = (AISDemod::MsgMessage&) message;
        messageReceived(report);
        return true;
    }

    return false;
}

void AISDemodGUI::handleInputMessages()
{
    Message* message;

    while ((message = getInputMessageQueue()->pop()) != 0)
    {
        if (handleMessage(*message))
        {
            delete message;
        }
    }
}

void AISDemodGUI::channelMarkerChangedByCursor()
{
    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());
    m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
    applySettings();
}

void AISDemodGUI::channelMarkerHighlightedByCursor()
{
    setHighlighted(m_channelMarker.getHighlighted());
}

void AISDemodGUI::on_deltaFrequency_changed(qint64 value)
{
    m_channelMarker.setCenterFrequency(value);
    m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
    applySettings();
}

void AISDemodGUI::on_rfBW_valueChanged(int value)
{
    float bw = value * 100.0f;
    ui->rfBWText->setText(QString("%1k").arg(value / 10.0, 0, 'f', 1));
    m_channelMarker.setBandwidth(bw);
    m_settings.m_rfBandwidth = bw;
    applySettings();
}

void AISDemodGUI::on_fmDev_valueChanged(int value)
{
    ui->fmDevText->setText(QString("%1k").arg(value / 10.0, 0, 'f', 1));
    m_settings.m_fmDeviation = value * 100.0;
    applySettings();
}

void AISDemodGUI::on_threshold_valueChanged(int value)
{
    ui->thresholdText->setText(QString("%1").arg(value));
    m_settings.m_correlationThreshold = value;
    applySettings();
}

void AISDemodGUI::on_filterMMSI_editingFinished()
{
    m_settings.m_filterMMSI = ui->filterMMSI->text();
    filter();
    applySettings();
}

void AISDemodGUI::on_clearTable_clicked()
{
    ui->messages->setRowCount(0);
}

void AISDemodGUI::on_udpEnabled_clicked(bool checked)
{
    m_settings.m_udpEnabled = checked;
    applySettings();
}

void AISDemodGUI::on_udpAddress_editingFinished()
{
    m_settings.m_udpAddress = ui->udpAddress->text();
    applySettings();
}

void AISDemodGUI::on_udpPort_editingFinished()
{
    m_settings.m_udpPort = ui->udpPort->text().toInt();
    applySettings();
}

void AISDemodGUI::on_udpFormat_currentIndexChanged(int value)
{
    m_settings.m_udpFormat = (AISDemodSettings::UDPFormat)value;
    applySettings();
}

void AISDemodGUI::on_channel1_currentIndexChanged(int index)
{
    m_settings.m_scopeCh1 = index;
    applySettings();
}

void AISDemodGUI::on_channel2_currentIndexChanged(int index)
{
    m_settings.m_scopeCh2 = index;
    applySettings();
}

void AISDemodGUI::on_messages_cellDoubleClicked(int row, int column)
{
    // Get MMSI of message in row double clicked
    QString mmsi = ui->messages->item(row, MESSAGE_COL_MMSI)->text();
    if (column == MESSAGE_COL_MMSI)
    {
        // Search for MMSI on www.vesselfinder.com
        QDesktopServices::openUrl(QUrl(QString("https://www.vesselfinder.com/vessels?name=%1").arg(mmsi)));
    }
}

void AISDemodGUI::filterRow(int row)
{
    bool hidden = false;
    if (m_settings.m_filterMMSI != "")
    {
        QRegExp re(m_settings.m_filterMMSI);
        QTableWidgetItem *fromItem = ui->messages->item(row, MESSAGE_COL_MMSI);
        if (!re.exactMatch(fromItem->text()))
            hidden = true;
    }
    ui->messages->setRowHidden(row, hidden);
}

void AISDemodGUI::filter()
{
    for (int i = 0; i < ui->messages->rowCount(); i++)
    {
        filterRow(i);
    }
}

void AISDemodGUI::onWidgetRolled(QWidget* widget, bool rollDown)
{
    if (widget == ui->scopeContainer)
    {
        if (rollDown)
        {
            // Make wide enough for scope controls
            setMinimumWidth(716);
        }
        else
        {
            setMinimumWidth(352);
        }
    }
}

void AISDemodGUI::onMenuDialogCalled(const QPoint &p)
{
    if (m_contextMenuType == ContextMenuChannelSettings)
    {
        BasicChannelSettingsDialog dialog(&m_channelMarker, this);
        dialog.setUseReverseAPI(m_settings.m_useReverseAPI);
        dialog.setReverseAPIAddress(m_settings.m_reverseAPIAddress);
        dialog.setReverseAPIPort(m_settings.m_reverseAPIPort);
        dialog.setReverseAPIDeviceIndex(m_settings.m_reverseAPIDeviceIndex);
        dialog.setReverseAPIChannelIndex(m_settings.m_reverseAPIChannelIndex);
        dialog.move(p);
        dialog.exec();

        m_settings.m_rgbColor = m_channelMarker.getColor().rgb();
        m_settings.m_title = m_channelMarker.getTitle();
        m_settings.m_useReverseAPI = dialog.useReverseAPI();
        m_settings.m_reverseAPIAddress = dialog.getReverseAPIAddress();
        m_settings.m_reverseAPIPort = dialog.getReverseAPIPort();
        m_settings.m_reverseAPIDeviceIndex = dialog.getReverseAPIDeviceIndex();
        m_settings.m_reverseAPIChannelIndex = dialog.getReverseAPIChannelIndex();

        setWindowTitle(m_settings.m_title);
        setTitleColor(m_settings.m_rgbColor);

        applySettings();
    }
    else if ((m_contextMenuType == ContextMenuStreamSettings) && (m_deviceUISet->m_deviceMIMOEngine))
    {
        DeviceStreamSelectionDialog dialog(this);
        dialog.setNumberOfStreams(m_aisDemod->getNumberOfDeviceStreams());
        dialog.setStreamIndex(m_settings.m_streamIndex);
        dialog.move(p);
        dialog.exec();

        m_settings.m_streamIndex = dialog.getSelectedStreamIndex();
        m_channelMarker.clearStreamIndexes();
        m_channelMarker.addStreamIndex(m_settings.m_streamIndex);
        displayStreamIndex();
        applySettings();
    }

    resetContextMenuType();
}

AISDemodGUI::AISDemodGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent) :
    ChannelGUI(parent),
    ui(new Ui::AISDemodGUI),
    m_pluginAPI(pluginAPI),
    m_deviceUISet(deviceUISet),
    m_channelMarker(this),
    m_doApplySettings(true),
    m_tickCount(0)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose, true);
    connect(this, SIGNAL(widgetRolled(QWidget*,bool)), this, SLOT(onWidgetRolled(QWidget*,bool)));
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onMenuDialogCalled(const QPoint &)));

    m_aisDemod = reinterpret_cast<AISDemod*>(rxChannel);
    m_aisDemod->setMessageQueueToGUI(getInputMessageQueue());

    connect(&MainCore::instance()->getMasterTimer(), SIGNAL(timeout()), this, SLOT(tick())); // 50 ms

    m_scopeVis = m_aisDemod->getScopeSink();
    m_scopeVis->setGLScope(ui->glScope);
    ui->glScope->connectTimer(MainCore::instance()->getMasterTimer());
    ui->scopeGUI->setBuddies(m_scopeVis->getInputMessageQueue(), m_scopeVis, ui->glScope);

    // Scope settings to display the IQ waveforms
    ui->scopeGUI->setPreTrigger(1);
    GLScopeSettings::TraceData traceDataI, traceDataQ;
    traceDataI.m_projectionType = Projector::ProjectionReal;
    traceDataI.m_amp = 1.0;      // for -1 to +1
    traceDataI.m_ofs = 0.0;      // vertical offset
    traceDataQ.m_projectionType = Projector::ProjectionImag;
    traceDataQ.m_amp = 1.0;
    traceDataQ.m_ofs = 0.0;
    ui->scopeGUI->changeTrace(0, traceDataI);
    ui->scopeGUI->addTrace(traceDataQ);
    ui->scopeGUI->setDisplayMode(GLScopeSettings::DisplayXYV);
    ui->scopeGUI->focusOnTrace(0); // re-focus to take changes into account in the GUI

    GLScopeSettings::TriggerData triggerData;
    triggerData.m_triggerLevel = 0.1;
    triggerData.m_triggerLevelCoarse = 10;
    triggerData.m_triggerPositiveEdge = true;
    ui->scopeGUI->changeTrigger(0, triggerData);
    ui->scopeGUI->focusOnTrigger(0); // re-focus to take changes into account in the GUI

    m_scopeVis->setLiveRate(9600*6);
    //m_scopeVis->setFreeRun(false); // FIXME: add method rather than call m_scopeVis->configure()

    ui->deltaFrequencyLabel->setText(QString("%1f").arg(QChar(0x94, 0x03)));
    ui->deltaFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->deltaFrequency->setValueRange(false, 7, -9999999, 9999999);
    ui->channelPowerMeter->setColorTheme(LevelMeterSignalDB::ColorGreenAndBlue);

    m_channelMarker.blockSignals(true);
    m_channelMarker.setColor(Qt::yellow);
    m_channelMarker.setBandwidth(m_settings.m_rfBandwidth);
    m_channelMarker.setCenterFrequency(m_settings.m_inputFrequencyOffset);
    m_channelMarker.setTitle("AIS Demodulator");
    m_channelMarker.blockSignals(false);
    m_channelMarker.setVisible(true); // activate signal on the last setting only

    setTitleColor(m_channelMarker.getColor());
    m_settings.setChannelMarker(&m_channelMarker);
    m_settings.setScopeGUI(ui->scopeGUI);

    m_deviceUISet->addChannelMarker(&m_channelMarker);
    m_deviceUISet->addRollupWidget(this);

    connect(&m_channelMarker, SIGNAL(changedByCursor()), this, SLOT(channelMarkerChangedByCursor()));
    connect(&m_channelMarker, SIGNAL(highlightedByCursor()), this, SLOT(channelMarkerHighlightedByCursor()));
    connect(getInputMessageQueue(), SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));

    // Resize the table using dummy data
    resizeTable();
    // Allow user to reorder columns
    ui->messages->horizontalHeader()->setSectionsMovable(true);
    // Allow user to sort table by clicking on headers
    ui->messages->setSortingEnabled(true);
    // Add context menu to allow hiding/showing of columns
    messagesMenu = new QMenu(ui->messages);
    for (int i = 0; i < ui->messages->horizontalHeader()->count(); i++)
    {
        QString text = ui->messages->horizontalHeaderItem(i)->text();
        messagesMenu->addAction(createCheckableItem(text, i, true, SLOT(messagesColumnSelectMenuChecked())));
    }
    ui->messages->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->messages->horizontalHeader(), SIGNAL(customContextMenuRequested(QPoint)), SLOT(messagesColumnSelectMenu(QPoint)));
    // Get signals when columns change
    connect(ui->messages->horizontalHeader(), SIGNAL(sectionMoved(int, int, int)), SLOT(messages_sectionMoved(int, int, int)));
    connect(ui->messages->horizontalHeader(), SIGNAL(sectionResized(int, int, int)), SLOT(messages_sectionResized(int, int, int)));
    ui->messages->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->messages, SIGNAL(customContextMenuRequested(QPoint)), SLOT(customContextMenuRequested(QPoint)));

    ui->scopeContainer->setVisible(false);

    displaySettings();
    applySettings(true);
}

void AISDemodGUI::customContextMenuRequested(QPoint pos)
{
    QTableWidgetItem *item =  ui->messages->itemAt(pos);
    if (item)
    {
        QMenu* tableContextMenu = new QMenu(ui->messages);
        connect(tableContextMenu, &QMenu::aboutToHide, tableContextMenu, &QMenu::deleteLater);
        QAction* copyAction = new QAction("Copy", tableContextMenu);
        const QString text = item->text();
        connect(copyAction, &QAction::triggered, this, [text]()->void {
            QClipboard *clipboard = QGuiApplication::clipboard();
            clipboard->setText(text);
        });
        tableContextMenu->addAction(copyAction);
        tableContextMenu->popup(ui->messages->viewport()->mapToGlobal(pos));
    }
}

AISDemodGUI::~AISDemodGUI()
{
    delete ui;
}

void AISDemodGUI::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void AISDemodGUI::applySettings(bool force)
{
    if (m_doApplySettings)
    {
        AISDemod::MsgConfigureAISDemod* message = AISDemod::MsgConfigureAISDemod::create( m_settings, force);
        m_aisDemod->getInputMessageQueue()->push(message);
    }
}

void AISDemodGUI::displaySettings()
{
    m_channelMarker.blockSignals(true);
    m_channelMarker.setBandwidth(m_settings.m_rfBandwidth);
    m_channelMarker.setCenterFrequency(m_settings.m_inputFrequencyOffset);
    m_channelMarker.setTitle(m_settings.m_title);
    m_channelMarker.blockSignals(false);
    m_channelMarker.setColor(m_settings.m_rgbColor); // activate signal on the last setting only

    setTitleColor(m_settings.m_rgbColor);
    setWindowTitle(m_channelMarker.getTitle());

    blockApplySettings(true);

    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());

    ui->rfBWText->setText(QString("%1k").arg(m_settings.m_rfBandwidth / 1000.0, 0, 'f', 1));
    ui->rfBW->setValue(m_settings.m_rfBandwidth / 100.0);

    ui->fmDevText->setText(QString("%1k").arg(m_settings.m_fmDeviation / 1000.0, 0, 'f', 1));
    ui->fmDev->setValue(m_settings.m_fmDeviation / 100.0);

    ui->thresholdText->setText(QString("%1").arg(m_settings.m_correlationThreshold));
    ui->threshold->setValue(m_settings.m_correlationThreshold);

    displayStreamIndex();

    ui->filterMMSI->setText(m_settings.m_filterMMSI);

    ui->udpEnabled->setChecked(m_settings.m_udpEnabled);
    ui->udpAddress->setText(m_settings.m_udpAddress);
    ui->udpPort->setText(QString::number(m_settings.m_udpPort));
    ui->udpFormat->setCurrentIndex((int)m_settings.m_udpFormat);

    ui->channel1->setCurrentIndex(m_settings.m_scopeCh1);
    ui->channel2->setCurrentIndex(m_settings.m_scopeCh2);

    // Order and size columns
    QHeaderView *header = ui->messages->horizontalHeader();
    for (int i = 0; i < AISDEMOD_MESSAGE_COLUMNS; i++)
    {
        bool hidden = m_settings.m_messageColumnSizes[i] == 0;
        header->setSectionHidden(i, hidden);
        messagesMenu->actions().at(i)->setChecked(!hidden);
        if (m_settings.m_messageColumnSizes[i] > 0)
            ui->messages->setColumnWidth(i, m_settings.m_messageColumnSizes[i]);
        header->moveSection(header->visualIndex(i), m_settings.m_messageColumnIndexes[i]);
    }
    filter();

    blockApplySettings(false);
}

void AISDemodGUI::displayStreamIndex()
{
    if (m_deviceUISet->m_deviceMIMOEngine) {
        setStreamIndicator(tr("%1").arg(m_settings.m_streamIndex));
    } else {
        setStreamIndicator("S"); // single channel indicator
    }
}

void AISDemodGUI::leaveEvent(QEvent*)
{
    m_channelMarker.setHighlighted(false);
}

void AISDemodGUI::enterEvent(QEvent*)
{
    m_channelMarker.setHighlighted(true);
}

void AISDemodGUI::tick()
{
    double magsqAvg, magsqPeak;
    int nbMagsqSamples;
    m_aisDemod->getMagSqLevels(magsqAvg, magsqPeak, nbMagsqSamples);
    double powDbAvg = CalcDb::dbPower(magsqAvg);
    double powDbPeak = CalcDb::dbPower(magsqPeak);

    ui->channelPowerMeter->levelChanged(
            (100.0f + powDbAvg) / 100.0f,
            (100.0f + powDbPeak) / 100.0f,
            nbMagsqSamples);

    if (m_tickCount % 4 == 0) {
        ui->channelPower->setText(QString::number(powDbAvg, 'f', 1));
    }

    m_tickCount++;
}
