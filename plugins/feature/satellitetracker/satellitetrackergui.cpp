///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
// Copyright (C) 2020 Bernhard Isemann, oe3bia                                   //
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

#include <cmath>
#include <QMessageBox>
#include <QLineEdit>
#include <QRegExp>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

#include "feature/featureuiset.h"
#include "feature/featurewebapiutils.h"
#include "gui/basicfeaturesettingsdialog.h"
#include "mainwindow.h"
#include "device/deviceuiset.h"
#include "util/units.h"
#include "util/astronomy.h"

#include "ui_satellitetrackergui.h"
#include "satellitetracker.h"
#include "satellitetrackergui.h"
#include "satellitetrackerreport.h"
#include "satellitetrackersettingsdialog.h"
#include "satelliteselectiondialog.h"
#include "satelliteradiocontroldialog.h"
#include "satellitetrackersgp4.h"

SatelliteTrackerGUI* SatelliteTrackerGUI::create(PluginAPI* pluginAPI, FeatureUISet *featureUISet, Feature *feature)
{
    SatelliteTrackerGUI* gui = new SatelliteTrackerGUI(pluginAPI, featureUISet, feature);
    return gui;
}

void SatelliteTrackerGUI::destroy()
{
    delete this;
}

void SatelliteTrackerGUI::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    applySettings(true);
}

QByteArray SatelliteTrackerGUI::serialize() const
{
    return m_settings.serialize();
}

bool SatelliteTrackerGUI::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        updateSelectedSats();
        displaySettings();
        qDebug() << " deserialize " << m_settings.m_satellites;
        applySettings(true);
        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

QString SatelliteTrackerGUI::convertDegreesToText(double degrees)
{
    if (m_settings.m_azElUnits == SatelliteTrackerSettings::DMS)
        return Units::decimalDegreesToDegreeMinutesAndSeconds(degrees);
    else if (m_settings.m_azElUnits == SatelliteTrackerSettings::DM)
        return Units::decimalDegreesToDegreesAndMinutes(degrees);
    else if (m_settings.m_azElUnits == SatelliteTrackerSettings::D)
        return Units::decimalDegreesToDegrees(degrees);
    else
        return QString("%1").arg(degrees, 0, 'f', 2);
}

bool SatelliteTrackerGUI::handleMessage(const Message& message)
{
    if (SatelliteTracker::MsgConfigureSatelliteTracker::match(message))
    {
        qDebug("SatelliteTrackerGUI::handleMessage: SatelliteTracker::MsgConfigureSatelliteTracker");
        const SatelliteTracker::MsgConfigureSatelliteTracker& cfg = (SatelliteTracker::MsgConfigureSatelliteTracker&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);

        return true;
    }
    else if (SatelliteTrackerReport::MsgReportSat::match(message))
    {
        SatelliteTrackerReport::MsgReportSat& satReport = (SatelliteTrackerReport::MsgReportSat&) message;
        SatelliteState *satState = satReport.getSatelliteState();
        if (satState->m_name == m_settings.m_target)
        {
            delete m_targetSatState;
            m_targetSatState = satState;

            ui->azimuth->setText(convertDegreesToText(satState->m_azimuth));
            ui->elevation->setText(convertDegreesToText(satState->m_elevation));
            if (satState->m_passes.size() > 0)
            {
                SatellitePass *pass = satState->m_passes[0];
                bool geostationary = !pass->m_aos.isValid() && !pass->m_los.isValid();
                if ((m_nextTargetAOS != pass->m_aos) || (m_nextTargetLOS != pass->m_los) || (geostationary != m_geostationarySatVisible))
                {
                    m_nextTargetAOS = pass->m_aos;
                    m_nextTargetLOS = pass->m_los;
                    m_geostationarySatVisible = geostationary;
                    plotChart();
                    updateTimeToAOS();
                }
            }
        }
        updateTable(satState);
        if (satState->m_name != m_settings.m_target)
            delete satState;
        return true;
    }
    else if (SatelliteTrackerReport::MsgReportAOS::match(message))
    {
        SatelliteTrackerReport::MsgReportAOS& aosReport = (SatelliteTrackerReport::MsgReportAOS&) message;
        aos(aosReport.getName(), aosReport.getDuration(), aosReport.getMaxElevation());
        return true;
    }
    else if (SatelliteTrackerReport::MsgReportTarget::match(message))
    {
        SatelliteTrackerReport::MsgReportTarget& targetReport = (SatelliteTrackerReport::MsgReportTarget&) message;
        setTarget(targetReport.getName());
        return true;
    }
    else if (SatelliteTrackerReport::MsgReportLOS::match(message))
    {
        SatelliteTrackerReport::MsgReportLOS& losReport = (SatelliteTrackerReport::MsgReportLOS&) message;
        los(losReport.getName());
        return true;
    }
    else if (SatelliteTracker::MsgSatData::match(message))
    {
        SatelliteTracker::MsgSatData& satData = (SatelliteTracker::MsgSatData&) message;
        m_satellites = satData.getSatellites();
        // Remove satellites that no longer exist
        QMutableListIterator<QString> itr(m_settings.m_satellites);
        while (itr.hasNext())
        {
            QString satellite = itr.next();
            if (!m_satellites.contains(satellite))
                itr.remove();
        }
        if (!m_satellites.contains(m_settings.m_target))
            setTarget("");
        // Update GUI
        updateSelectedSats();
        return true;
    }

    return false;
}

// Call when m_settings.m_satellites changes
void SatelliteTrackerGUI::updateSelectedSats()
{
    // Remove unselects sats from target combo and table
    for (int i = 0; i < ui->target->count(); )
    {
        QString name = ui->target->itemText(i);
        int idx = m_settings.m_satellites.indexOf(name);
        if (idx == -1)
        {
            ui->target->removeItem(i);
            QList<QTableWidgetItem *> matches = ui->satTable->findItems(name, Qt::MatchExactly);
            for (int j = 0; j < matches.length(); j++)
                ui->satTable->removeRow(ui->satTable->row(matches[j]));
        }
        else
            i++;
    }
    // Add new satellites to target combo
    for (int i = 0; i < m_settings.m_satellites.size(); i++)
    {
        if (ui->target->findText(m_settings.m_satellites[i], Qt::MatchExactly) == -1)
            ui->target->addItem(m_settings.m_satellites[i]);
    }
    // Select current target, if it still exists
    int idx = ui->target->findText(m_settings.m_target);
    if (idx != -1)
        ui->target->setCurrentIndex(idx);
    else
        setTarget("");
}

void SatelliteTrackerGUI::handleInputMessages()
{
    Message* message;

    while ((message = getInputMessageQueue()->pop()))
    {
        if (handleMessage(*message)) {
            delete message;
        }
    }
}

void SatelliteTrackerGUI::onWidgetRolled(QWidget* widget, bool rollDown)
{
    (void) widget;
    (void) rollDown;
}

SatelliteTrackerGUI::SatelliteTrackerGUI(PluginAPI* pluginAPI, FeatureUISet *featureUISet, Feature *feature, QWidget* parent) :
    FeatureGUI(parent),
    ui(new Ui::SatelliteTrackerGUI),
    m_pluginAPI(pluginAPI),
    m_featureUISet(featureUISet),
    m_doApplySettings(true),
    m_lastFeatureState(0),
    m_lastUpdatingSatData(false),
    m_targetSatState(nullptr),
    m_plotPass(0),
    m_lineChart(nullptr),
    m_polarChart(nullptr),
    m_geostationarySatVisible(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    setChannelWidget(false);
    connect(this, SIGNAL(widgetRolled(QWidget*,bool)), this, SLOT(onWidgetRolled(QWidget*,bool)));
    m_satelliteTracker = reinterpret_cast<SatelliteTracker*>(feature);
    m_satelliteTracker->setMessageQueueToGUI(&m_inputMessageQueue);

    m_featureUISet->addRollupWidget(this);

    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onMenuDialogCalled(const QPoint &)));
    connect(getInputMessageQueue(), SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));

    connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    m_statusTimer.start(1000);

    // Intialise charts
    m_emptyChart.layout()->setContentsMargins(0, 0, 0, 0);
    m_emptyChart.setMargins(QMargins(1, 1, 1, 1));
    ui->passChart->setChart(&m_emptyChart);
    ui->passChart->setRenderHint(QPainter::Antialiasing);

    ui->dateTime->setDateTime(SatelliteTracker::currentDateTime());

    // Use My Position from preferences, if none set
    if ((m_settings.m_latitude == 0.0) && (m_settings.m_longitude == 0.0))
        on_useMyPosition_clicked();

    resizeTable();
    // Allow user to reorder columns
    ui->satTable->horizontalHeader()->setSectionsMovable(true);
    // Allow user to sort table by clicking on headers
    ui->satTable->setSortingEnabled(true);
    // Add context menu to allow hiding/showing of columns
    menu = new QMenu(ui->satTable);
    for (int i = 0; i < ui->satTable->horizontalHeader()->count(); i++)
    {
        QString text = ui->satTable->horizontalHeaderItem(i)->text();
        menu->addAction(createCheckableItem(text, i, true));
    }
    ui->satTable->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->satTable->horizontalHeader(), SIGNAL(customContextMenuRequested(QPoint)), SLOT(columnSelectMenu(QPoint)));
    // Get signals when columns change
    connect(ui->satTable->horizontalHeader(), SIGNAL(sectionMoved(int, int, int)), SLOT(satTable_sectionMoved(int, int, int)));
    connect(ui->satTable->horizontalHeader(), SIGNAL(sectionResized(int, int, int)), SLOT(satTable_sectionResized(int, int, int)));

    m_speech = new QTextToSpeech(this);

    displaySettings();
    applySettings(true);

    // Get initial list of satellites
    on_updateSatData_clicked();
}

SatelliteTrackerGUI::~SatelliteTrackerGUI()
{
    delete ui;
}

void SatelliteTrackerGUI::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void SatelliteTrackerGUI::displaySettings()
{
    setTitleColor(m_settings.m_rgbColor);
    setWindowTitle(m_settings.m_title);
    blockApplySettings(true);
    ui->latitude->setValue(m_settings.m_latitude);
    ui->longitude->setValue(m_settings.m_longitude);
    ui->target->clear();

    for (const QString& s : m_settings.m_satellites) {
        ui->target->addItem(s);
    }

    ui->target->setCurrentIndex(ui->target->findText(m_settings.m_target));
    if (m_settings.m_dateTime == "")
    {
        ui->dateTimeSelect->setCurrentIndex(0);
        ui->dateTime->setVisible(false);
    }
    else
    {
        ui->dateTime->setDateTime(QDateTime::fromString(m_settings.m_dateTime, Qt::ISODateWithMs));
        ui->dateTime->setVisible(true);
        ui->dateTimeSelect->setCurrentIndex(1);
    }
    ui->autoTarget->setChecked(m_settings.m_autoTarget);
    ui->darkTheme->setChecked(m_settings.m_chartsDarkTheme);
    plotChart();
    blockApplySettings(false);
}

void SatelliteTrackerGUI::leaveEvent(QEvent*)
{
}

void SatelliteTrackerGUI::enterEvent(QEvent*)
{
}

void SatelliteTrackerGUI::onMenuDialogCalled(const QPoint &p)
{
    if (m_contextMenuType == ContextMenuChannelSettings)
    {
        BasicFeatureSettingsDialog dialog(this);
        dialog.setTitle(m_settings.m_title);
        dialog.setColor(m_settings.m_rgbColor);
        dialog.setUseReverseAPI(m_settings.m_useReverseAPI);
        dialog.setReverseAPIAddress(m_settings.m_reverseAPIAddress);
        dialog.setReverseAPIPort(m_settings.m_reverseAPIPort);
        dialog.setReverseAPIFeatureSetIndex(m_settings.m_reverseAPIFeatureSetIndex);
        dialog.setReverseAPIFeatureIndex(m_settings.m_reverseAPIFeatureIndex);

        dialog.move(p);
        dialog.exec();

        m_settings.m_rgbColor = dialog.getColor().rgb();
        m_settings.m_title = dialog.getTitle();
        m_settings.m_useReverseAPI = dialog.useReverseAPI();
        m_settings.m_reverseAPIAddress = dialog.getReverseAPIAddress();
        m_settings.m_reverseAPIPort = dialog.getReverseAPIPort();
        m_settings.m_reverseAPIFeatureSetIndex = dialog.getReverseAPIFeatureSetIndex();
        m_settings.m_reverseAPIFeatureIndex = dialog.getReverseAPIFeatureIndex();

        setWindowTitle(m_settings.m_title);
        setTitleColor(m_settings.m_rgbColor);

        applySettings();
    }

    resetContextMenuType();
}

void SatelliteTrackerGUI::aos(const QString& name, int duration, int maxElevation)
{
    // Give speech notification of pass
    QString speech = m_settings.m_aosSpeech.trimmed();
    if (!speech.isEmpty())
    {
        speech = speech.replace("${name}", name);
        speech = speech.replace("${duration}", QString::number(duration));
        speech = speech.replace("${elevation}", QString::number(maxElevation));
        m_speech->say(speech);
    }
}

void SatelliteTrackerGUI::los(const QString& name)
{
    // Give speech notification of end of pass
    QString speech = m_settings.m_losSpeech.trimmed();
    if (!speech.isEmpty())
    {
        speech = speech.replace("${name}", name);
        m_speech->say(speech);
    }
}

void SatelliteTrackerGUI::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        SatelliteTracker::MsgStartStop *message = SatelliteTracker::MsgStartStop::create(checked);
        m_satelliteTracker->getInputMessageQueue()->push(message);
    }
}

void SatelliteTrackerGUI::on_latitude_valueChanged(double value)
{
    m_settings.m_latitude = value;
    applySettings();
    plotChart();
}

void SatelliteTrackerGUI::on_longitude_valueChanged(double value)
{
    m_settings.m_longitude = value;
    applySettings();
    plotChart();
}

void SatelliteTrackerGUI::setTarget(const QString& target)
{
    if (target != m_settings.m_target)
    {
        m_settings.m_target = target;
        ui->azimuth->setText("");
        ui->elevation->setText("");
        ui->aos->setText("");
        ui->target->setCurrentIndex(ui->target->findText(m_settings.m_target));
        m_nextTargetAOS = QDateTime();
        m_nextTargetLOS = QDateTime();
        m_geostationarySatVisible = false;
        applySettings();
        delete m_targetSatState;
        m_targetSatState = nullptr;
        m_plotPass = 0;
        ui->passLabel->setText(QString("%1").arg(m_plotPass));
        plotChart();
    }
}

void SatelliteTrackerGUI::on_target_currentTextChanged(const QString &text)
{
    setTarget(text);
}

void SatelliteTrackerGUI::on_useMyPosition_clicked(bool checked)
{
    (void) checked;
    double stationLatitude = MainCore::instance()->getSettings().getLatitude();
    double stationLongitude = MainCore::instance()->getSettings().getLongitude();
    double stationAltitude = MainCore::instance()->getSettings().getAltitude();

    ui->latitude->setValue(stationLatitude);
    ui->longitude->setValue(stationLongitude);
    m_settings.m_heightAboveSeaLevel = stationAltitude;
    applySettings();
    plotChart();
}

// Show settings dialog
void SatelliteTrackerGUI::on_displaySettings_clicked()
{
    SatelliteTrackerSettingsDialog dialog(&m_settings);
    if (dialog.exec() == QDialog::Accepted)
    {
        applySettings();
        plotChart();
    }
}

void SatelliteTrackerGUI::on_dateTimeSelect_currentTextChanged(const QString &text)
{
    if (text == "Now")
    {
        m_settings.m_dateTime = "";
        ui->dateTime->setVisible(false);
    }
    else
    {
        m_settings.m_dateTime = ui->dateTime->dateTime().toString(Qt::ISODateWithMs);
        ui->dateTime->setVisible(true);
    }
    applySettings();
    plotChart();
}

void SatelliteTrackerGUI::on_dateTime_dateTimeChanged(const QDateTime &datetime)
{
    (void) datetime;
    if (ui->dateTimeSelect->currentIndex() == 1)
    {
        m_settings.m_dateTime = ui->dateTime->dateTime().toString(Qt::ISODateWithMs);
        applySettings();
        plotChart();
    }
}

// Find target on the Map
void SatelliteTrackerGUI::on_viewOnMap_clicked()
{
    if (!m_settings.m_target.isEmpty())
        FeatureWebAPIUtils::mapFind(m_settings.m_target);
}

void SatelliteTrackerGUI::on_updateSatData_clicked()
{
    m_satelliteTracker->getInputMessageQueue()->push(SatelliteTracker::MsgUpdateSatData::create());
}

void SatelliteTrackerGUI::on_selectSats_clicked()
{
    SatelliteSelectionDialog dialog(&m_settings, m_satellites);
    if (dialog.exec() == QDialog::Accepted)
    {
        updateSelectedSats();
        applySettings();
    }
}

void SatelliteTrackerGUI::on_radioControl_clicked()
{
    SatelliteRadioControlDialog dialog(&m_settings, m_satellites);
    if (dialog.exec() == QDialog::Accepted)
        applySettings();
}

void SatelliteTrackerGUI::on_autoTarget_clicked(bool checked)
{
    m_settings.m_autoTarget = checked;
    applySettings();
}

void SatelliteTrackerGUI::updateStatus()
{
    int state = m_satelliteTracker->getState();

    if (m_lastFeatureState != state)
    {
        // We set checked state of start/stop button, in case it was changed via API
        bool oldState;
        switch (state)
        {
            case Feature::StNotStarted:
                ui->startStop->setStyleSheet("QToolButton { background:rgb(79,79,79); }");
                break;
            case Feature::StIdle:
                oldState = ui->startStop->blockSignals(true);
                ui->startStop->setChecked(false);
                ui->startStop->blockSignals(oldState);
                ui->startStop->setStyleSheet("QToolButton { background-color : blue; }");
                break;
            case Feature::StRunning:
                oldState = ui->startStop->blockSignals(true);
                ui->startStop->setChecked(true);
                ui->startStop->blockSignals(oldState);
                ui->startStop->setStyleSheet("QToolButton { background-color : green; }");
                break;
            case Feature::StError:
                ui->startStop->setStyleSheet("QToolButton { background-color : red; }");
                QMessageBox::information(this, tr("Message"), m_satelliteTracker->getErrorMessage());
                break;
            default:
                break;
        }

        m_lastFeatureState = state;
    }

    // Indicate if satellite data is being updated
    bool updatingSatData = m_satelliteTracker->isUpdatingSatData();
    if (updatingSatData != m_lastUpdatingSatData)
    {
        if (updatingSatData)
            ui->updateSatData->setStyleSheet("QToolButton { background-color : green; }");
        else
            ui->updateSatData->setStyleSheet("QToolButton { background: none; }");
        m_lastUpdatingSatData = updatingSatData;
    }

    updateTimeToAOS();
}

// Update time to AOS
void SatelliteTrackerGUI::updateTimeToAOS()
{
    if (m_geostationarySatVisible)
        ui->aos->setText("Now");
    else if (m_nextTargetAOS.isValid())
    {
        QDateTime currentTime = SatelliteTracker::currentDateTime();
        int secondsToAOS = m_nextTargetAOS.toSecsSinceEpoch() - currentTime.toSecsSinceEpoch();
        if (secondsToAOS > 0)
        {
            int seconds = secondsToAOS % 60;
            int minutes = (secondsToAOS / 60) % 60;
            int hours = (secondsToAOS / (60 * 60)) % 24;
            int days = secondsToAOS / (60 * 60 * 24);
            if (days == 1)
                ui->aos->setText(QString("1 day"));
            else if (days > 0)
                ui->aos->setText(QString("%1 days").arg(days));
            else
            {
                ui->aos->setText(QString("%1:%2:%3")
                                        .arg(hours, 2, 10, QLatin1Char('0'))
                                        .arg(minutes, 2, 10, QLatin1Char('0'))
                                        .arg(seconds, 2, 10, QLatin1Char('0')));
            }
        }
        else if (m_nextTargetLOS < currentTime)
            ui->aos->setText("");
        else
            ui->aos->setText("Now");
    }
    else
        ui->aos->setText("");
}

void SatelliteTrackerGUI::applySettings(bool force)
{
    if (m_doApplySettings)
    {
        SatelliteTracker::MsgConfigureSatelliteTracker* message = SatelliteTracker::MsgConfigureSatelliteTracker::create(m_settings, force);
        m_satelliteTracker->getInputMessageQueue()->push(message);
    }
}

void SatelliteTrackerGUI::on_nextPass_clicked()
{
    if (m_targetSatState != nullptr)
    {
        if (m_plotPass < m_targetSatState->m_passes.size() - 1)
        {
            m_plotPass++;
            ui->passLabel->setText(QString("%1").arg(m_plotPass));
            plotChart();
        }
    }
}

void SatelliteTrackerGUI::on_prevPass_clicked()
{
    if (m_plotPass > 0)
    {
        m_plotPass--;
        ui->passLabel->setText(QString("%1").arg(m_plotPass));
        plotChart();
    }
}

void SatelliteTrackerGUI::on_darkTheme_clicked(bool checked)
{
    m_settings.m_chartsDarkTheme = checked;
    plotChart();
    applySettings();
}

void SatelliteTrackerGUI::on_chartSelect_currentIndexChanged(int index)
{
    (void) index;
    plotChart();
}

void SatelliteTrackerGUI::plotChart()
{
    if (ui->chartSelect->currentIndex() == 0)
        plotPolarChart();
    else
        plotAzElChart();
}

// Linear interpolation
static double interpolate(double x0, double y0, double x1, double y1, double x)
{
    return (y0*(x1-x) + y1*(x-x0)) / (x1-x0);
}

// Plot pass in polar coords
void SatelliteTrackerGUI::plotPolarChart()
{
    if ((m_targetSatState == nullptr) || !m_satellites.contains(m_settings.m_target) || (m_targetSatState->m_passes.size() == 0))
    {
        ui->passChart->setChart(&m_emptyChart);
        return;
    }

    QChart *oldChart = m_polarChart;

    if (m_plotPass >= m_targetSatState->m_passes.size() - 1)
    {
        m_plotPass = m_targetSatState->m_passes.size() - 1;
        ui->passLabel->setText(QString("%1").arg(m_plotPass));
    }
    SatellitePass *pass = m_targetSatState->m_passes[m_plotPass];

    // Always create a new chart, otherwise sometimes they aren't drawn properly
    m_polarChart = new QPolarChart();
    m_polarChart->setTheme(m_settings.m_chartsDarkTheme ? QChart::ChartThemeDark : QChart::ChartThemeLight);
    QValueAxis *angularAxis = new QValueAxis();
    QCategoryAxis *radialAxis = new QCategoryAxis();

    angularAxis->setTickCount(9);
    angularAxis->setMinorTickCount(1);
    angularAxis->setLabelFormat("%d");
    angularAxis->setRange(0, 360);

    radialAxis->setMin(0);
    radialAxis->setMax(90);
    radialAxis->append("90", 0);
    radialAxis->append("60", 30);
    radialAxis->append("30", 60);
    radialAxis->append("0", 90);
    radialAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    m_polarChart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);
    m_polarChart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
    m_polarChart->legend()->hide();
    m_polarChart->layout()->setContentsMargins(0, 0, 0, 0);
    m_polarChart->setMargins(QMargins(1, 1, 1, 1));

    SatNogsSatellite *sat = m_satellites.value(m_settings.m_target);

    if (pass->m_aos.isValid() && pass->m_los.isValid())
    {
        QString title;
        if (m_settings.m_utc)
            title = pass->m_aos.date().toString(m_settings.m_dateFormat);
        else
            title = pass->m_aos.toLocalTime().date().toString(m_settings.m_dateFormat);
        m_polarChart->setTitle(QString("%1").arg(title));

        QLineSeries *polarSeries = new QLineSeries();

        getPassAzEl(nullptr, nullptr, polarSeries,
                    sat->m_tle->m_tle0, sat->m_tle->m_tle1, sat->m_tle->m_tle2,
                    m_settings.m_latitude, m_settings.m_longitude, m_settings.m_heightAboveSeaLevel/1000.0,
                    pass->m_aos, pass->m_los);

        // Polar charts can't handle points that are more than 180 degrees apart, so
        // we need to split passes that cross from 359 -> 0 degrees (or the reverse)
        QList<QLineSeries *> series;
        series.append(new QLineSeries());
        QLineSeries *s = series.first();
        QPen pen(QColor(32, 159, 223), 2, Qt::SolidLine);
        s->setPen(pen);

        qreal prevAz = polarSeries->at(0).x();
        qreal prevEl = polarSeries->at(0).y();
        for (int i = 1; i < polarSeries->count(); i++)
        {
            qreal az = polarSeries->at(i).x();
            qreal el = polarSeries->at(i).y();
            if ((prevAz > 270.0) && (az <= 90.0))
            {
                double elMid = interpolate(prevAz, prevEl, az+360.0, el, 360.0);
                s->append(360.0, elMid);
                series.append(new QLineSeries());
                s = series.last();
                s->setPen(pen);
                s->append(0.0, elMid);
                s->append(az, el);
            }
            else if ((prevAz <= 90.0) && (az > 270.0))
            {
                double elMid = interpolate(prevAz, prevEl, az-360.0, el, 0.0);
                s->append(0.0, elMid);
                series.append(new QLineSeries());
                s = series.last();
                s->setPen(pen);
                s->append(360.0, elMid);
                s->append(az, el);
            }
            else
                s->append(polarSeries->at(i));
            prevAz = az;
            prevEl = el;
        }

        for (int i = 0; i < series.length(); i++)
        {
            m_polarChart->addSeries(series[i]);
            series[i]->attachAxis(angularAxis);
            series[i]->attachAxis(radialAxis);
        }

        // Create series with single point, so we can plot time of AOS
        QLineSeries *aosSeries = new QLineSeries();
        aosSeries->append(polarSeries->at(0));
        QTime time;
        if (m_settings.m_utc)
            time = pass->m_aos.time();
        else
            time = pass->m_aos.toLocalTime().time();
        if (m_settings.m_utc)
            aosSeries->setPointLabelsFormat(QString("AOS %1").arg(time.toString("hh:mm")));
        else
            aosSeries->setPointLabelsFormat(QString("AOS %1").arg(time.toString("hh:mm")));
        aosSeries->setPointLabelsVisible(true);
        aosSeries->setPointLabelsClipping(false);
        m_polarChart->addSeries(aosSeries);
        aosSeries->attachAxis(angularAxis);
        aosSeries->attachAxis(radialAxis);
        // Create series with single point, so we can plot time of LOS
        QLineSeries *losSeries = new QLineSeries();
        losSeries->append(polarSeries->at(polarSeries->count()-1));
        if (m_settings.m_utc)
            time = pass->m_los.time();
        else
            time = pass->m_los.toLocalTime().time();
        losSeries->setPointLabelsFormat(QString("LOS %1").arg(time.toString("hh:mm")));
        losSeries->setPointLabelsVisible(true);
        losSeries->setPointLabelsClipping(false);
        m_polarChart->addSeries(losSeries);
        losSeries->attachAxis(angularAxis);
        losSeries->attachAxis(radialAxis);

        QDateTime currentTime;
        if (m_settings.m_dateTime == "")
            currentTime = SatelliteTracker::currentDateTimeUtc();
        else if (m_settings.m_utc)
            currentTime = QDateTime::fromString(m_settings.m_dateTime, Qt::ISODateWithMs);
        else
            currentTime = QDateTime::fromString(m_settings.m_dateTime, Qt::ISODateWithMs).toUTC();
        if ((currentTime >= pass->m_aos) && (currentTime <= pass->m_los))
        {
            // Create series with single point, so we can plot current time
            QLineSeries *nowSeries = new QLineSeries();
            // Find closest point to current time
            int idx = std::round(polarSeries->count() * (currentTime.toMSecsSinceEpoch() - pass->m_aos.toMSecsSinceEpoch())
                                                       / (pass->m_los.toMSecsSinceEpoch() - pass->m_aos.toMSecsSinceEpoch()));
            nowSeries->append(polarSeries->at(idx));
            nowSeries->setPointLabelsFormat(m_settings.m_target);
            nowSeries->setPointLabelsVisible(true);
            nowSeries->setPointLabelsClipping(false);
            m_polarChart->addSeries(nowSeries);
            nowSeries->attachAxis(angularAxis);
            nowSeries->attachAxis(radialAxis);
            // Redraw in 5 seconds (call plotChart, incase user selects a different chart)
            QTimer::singleShot(5000, this, &SatelliteTrackerGUI::plotChart);
        }

        delete polarSeries;
    }
    else
    {
        // Possibly geostationary, just plot current position
        QDateTime currentTime;
        if (m_settings.m_dateTime == "")
            currentTime = SatelliteTracker::currentDateTimeUtc();
        else if (m_settings.m_utc)
            currentTime = QDateTime::fromString(m_settings.m_dateTime, Qt::ISODateWithMs);
        else
            currentTime = QDateTime::fromString(m_settings.m_dateTime, Qt::ISODateWithMs).toUTC();
        QString title;
        if (m_settings.m_utc)
            title = currentTime.date().toString(m_settings.m_dateFormat);
        else
            title = currentTime.toLocalTime().date().toString(m_settings.m_dateFormat);
        m_polarChart->setTitle(QString("%1").arg(title));

        QLineSeries *nowSeries = new QLineSeries();

        QDateTime endTime = currentTime.addSecs(1);
        getPassAzEl(nullptr, nullptr, nowSeries,
                    sat->m_tle->m_tle0, sat->m_tle->m_tle1, sat->m_tle->m_tle2,
                    m_settings.m_latitude, m_settings.m_longitude, m_settings.m_heightAboveSeaLevel/1000.0,
                    currentTime, endTime);

        nowSeries->setPointLabelsFormat(m_settings.m_target);
        nowSeries->setPointLabelsVisible(true);
        nowSeries->setPointLabelsClipping(false);
        m_polarChart->addSeries(nowSeries);
        nowSeries->attachAxis(angularAxis);
        nowSeries->attachAxis(radialAxis);
    }

    ui->passChart->setChart(m_polarChart);

    delete oldChart;
}

// Plot target elevation/azimuth for the next pass
void SatelliteTrackerGUI::plotAzElChart()
{
    if ((m_targetSatState == nullptr) || !m_satellites.contains(m_settings.m_target) || (m_targetSatState->m_passes.size() == 0))
    {
        ui->passChart->setChart(&m_emptyChart);
        return;
    }

    QChart *oldChart = m_lineChart;

    if (m_plotPass >= m_targetSatState->m_passes.size() - 1)
    {
        m_plotPass = m_targetSatState->m_passes.size() - 1;
        ui->passLabel->setText(QString("%1").arg(m_plotPass));
    }
    SatellitePass *pass = m_targetSatState->m_passes[m_plotPass];

    // Always create a new chart, otherwise sometimes they aren't drawn properly
    m_lineChart = new QChart();
    m_lineChart->setTheme(m_settings.m_chartsDarkTheme ? QChart::ChartThemeDark : QChart::ChartThemeLight);
    QDateTimeAxis *xAxis = new QDateTimeAxis();
    QValueAxis *yLeftAxis = new QValueAxis();
    QValueAxis *yRightAxis = new QValueAxis();

    QString title;
    if (m_settings.m_utc)
        title = pass->m_aos.date().toString(m_settings.m_dateFormat);
    else
        title = pass->m_aos.toLocalTime().date().toString(m_settings.m_dateFormat);
    m_lineChart->setTitle(QString("%1").arg(title));
    m_lineChart->legend()->hide();
    m_lineChart->addAxis(xAxis, Qt::AlignBottom);
    m_lineChart->addAxis(yLeftAxis, Qt::AlignLeft);
    m_lineChart->addAxis(yRightAxis, Qt::AlignRight);
    m_lineChart->layout()->setContentsMargins(0, 0, 0, 0);
    m_lineChart->setMargins(QMargins(1, 1, 1, 1));

    SatNogsSatellite *sat = m_satellites.value(m_settings.m_target);

    QLineSeries *azSeries = new QLineSeries();
    QLineSeries *elSeries = new QLineSeries();

    getPassAzEl(azSeries, elSeries, nullptr,
                sat->m_tle->m_tle0, sat->m_tle->m_tle1, sat->m_tle->m_tle2,
                m_settings.m_latitude, m_settings.m_longitude, m_settings.m_heightAboveSeaLevel/1000.0,
                pass->m_aos, pass->m_los);

    // Split crossing of 360/0 degrees in to multiple series in the same colour
    QList<QLineSeries *> azSeriesList;
    QPen pen(QColor(153, 202, 83), 2, Qt::SolidLine);
    QLineSeries *s = new QLineSeries();
    azSeriesList.append(s);
    s->setPen(pen);
    qreal prevAz = azSeries->at(0).y();
    for (int i = 0; i < azSeries->count(); i++)
    {
        qreal az = azSeries->at(i).y();
        if (((prevAz >= 270) && (az < 90)) || ((prevAz < 90) && (az >= 270)))
        {
            s = new QLineSeries();
            azSeriesList.append(s);
            s->setPen(pen);
        }
        s->append(azSeries->at(i).x(), az);
        prevAz = az;
    }

    m_lineChart->addSeries(elSeries);
    elSeries->attachAxis(xAxis);
    elSeries->attachAxis(yLeftAxis);
    for (int i = 0; i < azSeriesList.size(); i++)
    {
        m_lineChart->addSeries(azSeriesList[i]);
        azSeriesList[i]->attachAxis(xAxis);
        azSeriesList[i]->attachAxis(yRightAxis);
    }
    xAxis->setRange(pass->m_aos, pass->m_los);
    xAxis->setFormat("hh:mm");
    yLeftAxis->setRange(0.0, 90.0);
    yLeftAxis->setTickCount(7);
    yLeftAxis->setLabelFormat("%d");
    yLeftAxis->setTitleText(QString("Elevation (%1)").arg(QChar(0xb0)));
    yRightAxis->setRange(0.0, 360.0);
    yRightAxis->setTickCount(7);
    yRightAxis->setLabelFormat("%d");
    yRightAxis->setTitleText(QString("Azimuth (%1)").arg(QChar(0xb0)));

    ui->passChart->setChart(m_lineChart);

    delete azSeries;
    delete oldChart;
}

void SatelliteTrackerGUI::resizeTable()
{
    // Fill table with a row of dummy data that will size the columns nicely
    int row = ui->satTable->rowCount();
    ui->satTable->setRowCount(row + 1);
    ui->satTable->setItem(row, SAT_COL_NAME, new QTableWidgetItem("Satellite123"));
    ui->satTable->setItem(row, SAT_COL_AZ, new QTableWidgetItem("360"));
    ui->satTable->setItem(row, SAT_COL_EL, new QTableWidgetItem("-90"));
    ui->satTable->setItem(row, SAT_COL_TNE, new QTableWidgetItem("9999:99 AOS"));
    ui->satTable->setItem(row, SAT_COL_DUR, new QTableWidgetItem("999:99"));
    ui->satTable->setItem(row, SAT_COL_AOS, new QTableWidgetItem("+1 10:17"));
    ui->satTable->setItem(row, SAT_COL_LOS, new QTableWidgetItem("+1 10:17"));
    ui->satTable->setItem(row, SAT_COL_MAX_EL, new QTableWidgetItem("90"));
    ui->satTable->setItem(row, SAT_COL_DIR, new QTableWidgetItem("^"));
    ui->satTable->setItem(row, SAT_COL_ALT, new QTableWidgetItem("50000"));
    ui->satTable->setItem(row, SAT_COL_RANGE, new QTableWidgetItem("50000"));
    ui->satTable->setItem(row, SAT_COL_RANGE_RATE, new QTableWidgetItem("10.0"));
    ui->satTable->setItem(row, SAT_COL_DOPPLER, new QTableWidgetItem("10000"));
    ui->satTable->setItem(row, SAT_COL_PATH_LOSS, new QTableWidgetItem("100"));
    ui->satTable->setItem(row, SAT_COL_NORAD_ID, new QTableWidgetItem("123456"));
    ui->satTable->resizeColumnsToContents();
    ui->satTable->setRowCount(row);
}

// As we only have limited space in table, display time plus number of days to AOS/LOS
// unless it's greater than 10 days, in which case just display the date
QString SatelliteTrackerGUI::formatDaysTime(qint64 days, QDateTime dateTime)
{
    QDateTime dt;
    if (m_settings.m_utc)
        dt = dateTime.toUTC();
    else
        dt = dateTime.toLocalTime();
    if (abs(days) > 10)
        return dt.date().toString(m_settings.m_dateFormat);
    else if (days == 0)
        return dt.time().toString("hh:mm");
    else if (days > 0)
        return dt.time().toString(QString("hh:mm +%1").arg(days));
    else
        return dt.time().toString(QString("hh:mm %1").arg(days));
}


QString SatelliteTrackerGUI::formatSecondsHHMM(qint64 seconds)
{
    char const* sign = "";
    if(seconds < 0)
    {
        sign    = "-";
        seconds = -seconds;
    }
    return QString("%1%2:%3").arg(sign).arg(seconds/60).arg(seconds%60,2,10,QChar('0'));
}


// Table item showing some text, but sorted by datetime set as user data
class DateTimeSortedTableWidgetItem : public QTableWidgetItem {
public:
    bool operator<(const QTableWidgetItem& other) const
    {
        QVariant v1 = data(Qt::UserRole);
        QVariant v2 = other.data(Qt::UserRole);
        if (v1.isValid() && v2.isValid())
            return v1.toDateTime() < v2.toDateTime();
        else
            return false;
    }
};


class NaturallySortedTableWidgetItem : public QTableWidgetItem
{
public:
    bool operator<(const QTableWidgetItem &other) const override
    {
        QCollator coll;
        coll.setNumericMode(true);
        return coll.compare( text() , other.text() ) < 0;
    }
};



#define SPEED_OF_LIGHT 299792458.0

// Frequency in Hz, speed in m/s
static double doppler(double frequency, double speed)
{
    return frequency * speed / SPEED_OF_LIGHT;
}

// Frequency in Hz, speed in m/s
static double freeSpaceLoss(double frequency, double distance)
{
    return 20.0 * log10(distance) + 20 * log10(frequency) + 20 * log10(4*M_PI/SPEED_OF_LIGHT);
}

// Distance in m, delay in s
static double propagationDelay(double distance)
{
    return distance / SPEED_OF_LIGHT;
}

// Update satellite data table with latest data for the satellite
void SatelliteTrackerGUI::updateTable(SatelliteState *satState)
{
    // Does the table already contain this satellite?
    QList<QTableWidgetItem *> matches = ui->satTable->findItems(satState->m_name, Qt::MatchExactly);
    QTableWidgetItem *items[SAT_COL_COLUMNS];
    if (matches.size() == 0)
    {
        // Add a new row
        int row = ui->satTable->rowCount();
        ui->satTable->setRowCount(row + 1);
        for (int i = 0; i < SAT_COL_COLUMNS; i++)
        {
            if ((i == SAT_COL_AOS) || (i == SAT_COL_LOS))
                items[i] = new DateTimeSortedTableWidgetItem();
            else if((i == SAT_COL_NAME) || (i == SAT_COL_NORAD_ID))
                items[i] = new QTableWidgetItem();
            else
                items[i] = new NaturallySortedTableWidgetItem();
            items[i]->setToolTip(ui->satTable->horizontalHeaderItem(i)->toolTip());
            ui->satTable->setItem(row, i, items[i]);
        }
        // Static columns
        items[SAT_COL_NAME]->setText(satState->m_name);
        if (m_satellites.contains(satState->m_name))
        {
            SatNogsSatellite *sat = m_satellites.value(satState->m_name);
            items[SAT_COL_NORAD_ID]->setData(Qt::DisplayRole, sat->m_noradCatId);
        }

        // Text alignment
        for( int col : {SAT_COL_AZ, SAT_COL_EL, SAT_COL_TNE, SAT_COL_DUR, SAT_COL_MAX_EL,
                        SAT_COL_ALT, SAT_COL_RANGE, SAT_COL_RANGE_RATE, SAT_COL_DOPPLER,
                        SAT_COL_PATH_LOSS, SAT_COL_DELAY})
            items[col]->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
    else
    {
        // Update existing row
        int row = ui->satTable->row(matches[0]);
        for (int i = 0; i < SAT_COL_COLUMNS; i++)
            items[i] = ui->satTable->item(row, i);
    }

    items[SAT_COL_AZ]->setData(Qt::DisplayRole, (int)round(satState->m_azimuth));
    items[SAT_COL_EL]->setData(Qt::DisplayRole, (int)round(satState->m_elevation));
    if (satState->m_passes.size() > 0)
    {
        // Get number of days to AOS/LOS
        QDateTime currentDateTime = QDateTime::currentDateTime();
        int daysToAOS = currentDateTime.daysTo(satState->m_passes[0]->m_aos);
        int daysToLOS = currentDateTime.daysTo(satState->m_passes[0]->m_los);
        if( satState->m_passes[ 0 ]->m_aos > currentDateTime )
            items[SAT_COL_TNE]->setText(formatSecondsHHMM(currentDateTime.secsTo(satState->m_passes[0]->m_aos))+" AOS");
        else
            items[SAT_COL_TNE]->setText(formatSecondsHHMM(currentDateTime.secsTo(satState->m_passes[0]->m_los))+" LOS");
        items[SAT_COL_DUR]->setText(formatSecondsHHMM(satState->m_passes[0]->m_aos.secsTo(satState->m_passes[0]->m_los)));
        items[SAT_COL_AOS]->setText(formatDaysTime(daysToAOS, satState->m_passes[0]->m_aos));
        items[SAT_COL_AOS]->setData(Qt::UserRole, satState->m_passes[0]->m_aos);
        items[SAT_COL_LOS]->setText(formatDaysTime(daysToLOS, satState->m_passes[0]->m_los));
        items[SAT_COL_LOS]->setData(Qt::UserRole, satState->m_passes[0]->m_los);
        items[SAT_COL_MAX_EL]->setData(Qt::DisplayRole, (int)round(satState->m_passes[0]->m_maxElevation));
        if (satState->m_passes[0]->m_northToSouth)
            items[SAT_COL_DIR]->setText(QString("%1").arg(QChar(0x2193))); // Down arrow
        else
            items[SAT_COL_DIR]->setText(QString("%1").arg(QChar(0x2191))); // Up arrow
    }
    else
    {
        items[SAT_COL_TNE]->setText("");
        items[SAT_COL_DUR]->setText("");
        items[SAT_COL_AOS]->setText("");
        items[SAT_COL_LOS]->setText("");
        items[SAT_COL_MAX_EL]->setData(Qt::DisplayRole, QVariant());
        items[SAT_COL_DIR]->setText("");
    }
    items[SAT_COL_ALT]->setData(Qt::DisplayRole, (int)round(satState->m_altitude));
    items[SAT_COL_RANGE]->setData(Qt::DisplayRole, (int)round(satState->m_range));
    items[SAT_COL_RANGE_RATE]->setData(Qt::DisplayRole, QString::number(satState->m_rangeRate, 'f', 3));
    items[SAT_COL_DOPPLER]->setData(Qt::DisplayRole, (int)round(-doppler(m_settings.m_defaultFrequency, satState->m_rangeRate*1000.0)));
    items[SAT_COL_PATH_LOSS]->setData(Qt::DisplayRole, QString::number(freeSpaceLoss(m_settings.m_defaultFrequency, satState->m_range*1000.0), 'f', 1));
    items[SAT_COL_DELAY]->setData(Qt::DisplayRole, QString::number(propagationDelay(satState->m_range*1000.0)*1000.0, 'f', 1));
}

void SatelliteTrackerGUI::on_satTable_cellDoubleClicked(int row, int column)
{
    (void) column;

    QString sat = ui->satTable->item(row, SAT_COL_NAME)->text();
    FeatureWebAPIUtils::mapFind(sat);
}

// Columns in table reordered
void SatelliteTrackerGUI::satTable_sectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex)
{
    (void) oldVisualIndex;
    m_settings.m_columnIndexes[logicalIndex] = newVisualIndex;
}

// Column in table resized (when hidden size is 0)
void SatelliteTrackerGUI::satTable_sectionResized(int logicalIndex, int oldSize, int newSize)
{
    (void) oldSize;
    m_settings.m_columnSizes[logicalIndex] = newSize;
}

// Right click in table header - show column select menu
void SatelliteTrackerGUI::columnSelectMenu(QPoint pos)
{
    menu->popup(ui->satTable->horizontalHeader()->viewport()->mapToGlobal(pos));
}

// Hide/show column when menu selected
void SatelliteTrackerGUI::columnSelectMenuChecked(bool checked)
{
    (void) checked;
    QAction* action = qobject_cast<QAction*>(sender());
    if (action != nullptr)
    {
        int idx = action->data().toInt(nullptr);
        ui->satTable->setColumnHidden(idx, !action->isChecked());
    }
}

// Create column select menu item
QAction *SatelliteTrackerGUI::createCheckableItem(QString &text, int idx, bool checked)
{
    QAction *action = new QAction(text, this);
    action->setCheckable(true);
    action->setChecked(checked);
    action->setData(QVariant(idx));
    connect(action, SIGNAL(triggered()), this, SLOT(columnSelectMenuChecked()));
    return action;
}
