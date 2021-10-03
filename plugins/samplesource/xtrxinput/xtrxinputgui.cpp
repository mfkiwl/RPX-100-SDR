///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017, 2018 Bernhard Isemann, oe3bia                             //
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

#include "xtrxinputgui.h"

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include <algorithm>

#include "ui_xtrxinputgui.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "device/deviceapi.h"
#include "device/deviceuiset.h"

XTRXInputGUI::XTRXInputGUI(DeviceUISet *deviceUISet, QWidget* parent) :
    DeviceGUI(parent),
    ui(new Ui::XTRXInputGUI),
    m_deviceUISet(deviceUISet),
    m_settings(),
    m_sampleRateMode(true),
    m_sampleRate(0),
    m_lastEngineState(DeviceAPI::StNotStarted),
    m_doApplySettings(true),
    m_forceSettings(true),
    m_statusCounter(0),
    m_deviceStatusCounter(0)
{
    m_XTRXInput = (XTRXInput*) m_deviceUISet->m_deviceAPI->getSampleSource();

    ui->setupUi(this);

    float minF, maxF, stepF;

    m_XTRXInput->getLORange(minF, maxF, stepF);
    ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->centerFrequency->setValueRange(7, ((uint32_t) minF)/1000, ((uint32_t) maxF)/1000); // frequency dial is in kHz

    m_XTRXInput->getSRRange(minF, maxF, stepF);
    ui->sampleRate->setColorMapper(ColorMapper(ColorMapper::GrayGreenYellow));
    ui->sampleRate->setValueRange(8, (uint32_t) minF, (uint32_t) maxF);

    m_XTRXInput->getLPRange(minF, maxF, stepF);
    ui->lpf->setColorMapper(ColorMapper(ColorMapper::GrayYellow));
    ui->lpf->setValueRange(6, (minF/1000)+1, maxF/1000);

    ui->ncoFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));

    ui->channelNumberText->setText(tr("#%1").arg(m_XTRXInput->getChannelIndex()));

    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));
    connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    m_statusTimer.start(500);

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));

    displaySettings();

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
}

XTRXInputGUI::~XTRXInputGUI()
{
    delete ui;
}

void XTRXInputGUI::destroy()
{
    delete this;
}

void XTRXInputGUI::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    sendSettings();
}

QByteArray XTRXInputGUI::serialize() const
{
    return m_settings.serialize();
}

bool XTRXInputGUI::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        displaySettings();
        m_forceSettings = true;
        sendSettings();
        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

bool XTRXInputGUI::handleMessage(const Message& message)
{

    if (DeviceXTRXShared::MsgReportBuddyChange::match(message))
    {
        DeviceXTRXShared::MsgReportBuddyChange& report = (DeviceXTRXShared::MsgReportBuddyChange&) message;
        m_settings.m_devSampleRate = report.getDevSampleRate();
        m_settings.m_log2HardDecim = report.getLog2HardDecimInterp();

        if (report.getRxElseTx()) {
            m_settings.m_centerFrequency = report.getCenterFrequency();
        }

        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);

        return true;
    }
    else if (DeviceXTRXShared::MsgReportClockSourceChange::match(message))
    {
        DeviceXTRXShared::MsgReportClockSourceChange& report = (DeviceXTRXShared::MsgReportClockSourceChange&) message;
        m_settings.m_extClockFreq = report.getExtClockFeq();
        m_settings.m_extClock = report.getExtClock();

        blockApplySettings(true);
        ui->extClock->setExternalClockFrequency(m_settings.m_extClockFreq);
        ui->extClock->setExternalClockActive(m_settings.m_extClock);
        blockApplySettings(false);

        return true;
    }
    else if (XTRXInput::MsgReportClockGenChange::match(message))
    {
        m_settings.m_devSampleRate = m_XTRXInput->getDevSampleRate();
        m_settings.m_log2HardDecim = m_XTRXInput->getLog2HardDecim();

        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);

        return true;
    }
    else if (XTRXInput::MsgReportStreamInfo::match(message))
    {
        XTRXInput::MsgReportStreamInfo& report = (XTRXInput::MsgReportStreamInfo&) message;

        if (report.getSuccess())
        {
            if (report.getActive()) {
                ui->streamStatusLabel->setStyleSheet("QLabel { background-color : green; }");
            } else {
                ui->streamStatusLabel->setStyleSheet("QLabel { background-color : blue; }");
            }

            ui->fifoBar->setMaximum(report.getFifoSize());
            ui->fifoBar->setValue(report.getFifoFilledCount());
            ui->fifoBar->setToolTip(tr("FIFO fill %1/%2 samples").arg(QString::number(report.getFifoFilledCount())).arg(QString::number(report.getFifoSize())));
        }
        else
        {
            ui->streamStatusLabel->setStyleSheet("QLabel { background:rgb(79,79,79); }");
        }

        return true;
    }
    else if (DeviceXTRXShared::MsgReportDeviceInfo::match(message))
    {
        DeviceXTRXShared::MsgReportDeviceInfo& report = (DeviceXTRXShared::MsgReportDeviceInfo&) message;
        ui->temperatureText->setText(tr("%1C").arg(QString::number(report.getTemperature(), 'f', 0)));

        if (report.getGPSLocked()) {
            ui->gpsStatusLabel->setStyleSheet("QLabel { background-color : green; }");
        } else {
            ui->gpsStatusLabel->setStyleSheet("QLabel { background:rgb(48,48,48); }");
        }

        return true;
    }
    else if (XTRXInput::MsgStartStop::match(message))
    {
        XTRXInput::MsgStartStop& notif = (XTRXInput::MsgStartStop&) message;
        blockApplySettings(true);
        ui->startStop->setChecked(notif.getStartStop());
        blockApplySettings(false);

        return true;
    }

    return false;
}

void XTRXInputGUI::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()))
    {
        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            m_sampleRate = notif->getSampleRate();
            m_deviceCenterFrequency = notif->getCenterFrequency();
            qDebug("XTRXInputGUI::handleInputMessages: DSPSignalNotification: SampleRate: %d, CenterFrequency: %llu", notif->getSampleRate(), notif->getCenterFrequency());
            updateSampleRateAndFrequency();

            delete message;
        }
        else if (XTRXInput::MsgConfigureXTRX::match(*message))
        {
            qDebug("XTRXInputGUI::handleInputMessages: MsgConfigureXTRX");
            const XTRXInput::MsgConfigureXTRX& cfg = (XTRXInput::MsgConfigureXTRX&) *message;
            m_settings = cfg.getSettings();
            displaySettings();

            delete message;
        }
        else
        {
            if (handleMessage(*message)) {
                delete message;
            }
        }
    }
}

void XTRXInputGUI::updateADCRate()
{
    uint32_t adcRate = m_XTRXInput->getClockGen() / 4;

    if (adcRate < 100000000) {
        ui->adcRateLabel->setText(tr("%1k").arg(QString::number(adcRate / 1000.0f, 'g', 5)));
    } else {
        ui->adcRateLabel->setText(tr("%1M").arg(QString::number(adcRate / 1000000.0f, 'g', 5)));
    }
}

void XTRXInputGUI::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_deviceCenterFrequency);
    displaySampleRate();
}

void XTRXInputGUI::displaySampleRate()
{
    float minF, maxF, stepF;
    m_XTRXInput->getSRRange(minF, maxF, stepF);

    ui->sampleRate->blockSignals(true);

    if (m_sampleRateMode)
    {
        ui->sampleRateMode->setStyleSheet("QToolButton { background:rgb(60,60,60); }");
        ui->sampleRateMode->setText("SR");
        ui->sampleRate->setValueRange(8, (uint32_t) minF, (uint32_t) maxF);
        ui->sampleRate->setValue(m_settings.m_devSampleRate);
        ui->sampleRate->setToolTip("Device to host sample rate (S/s)");
        ui->deviceRateText->setToolTip("Baseband sample rate (S/s)");
        uint32_t basebandSampleRate = m_settings.m_devSampleRate/(1<<m_settings.m_log2SoftDecim);
        ui->deviceRateText->setText(tr("%1k").arg(QString::number(basebandSampleRate / 1000.0f, 'g', 5)));
    }
    else
    {
        ui->sampleRateMode->setStyleSheet("QToolButton { background:rgb(50,50,50); }");
        ui->sampleRateMode->setText("BB");
        ui->sampleRate->setValueRange(8, (uint32_t) minF/(1<<m_settings.m_log2SoftDecim), (uint32_t) maxF/(1<<m_settings.m_log2SoftDecim));
        ui->sampleRate->setValue(m_settings.m_devSampleRate/(1<<m_settings.m_log2SoftDecim));
        ui->sampleRate->setToolTip("Baseband sample rate (S/s)");
        ui->deviceRateText->setToolTip("Device to host sample rate (S/s)");
        ui->deviceRateText->setText(tr("%1k").arg(QString::number(m_settings.m_devSampleRate / 1000.0f, 'g', 5)));
    }

    ui->sampleRate->blockSignals(false);
}

void XTRXInputGUI::displaySettings()
{
    ui->extClock->setExternalClockFrequency(m_settings.m_extClockFreq);
    ui->extClock->setExternalClockActive(m_settings.m_extClock);

    setCenterFrequencyDisplay();
    displaySampleRate();

    ui->dcOffset->setChecked(m_settings.m_dcBlock);
    ui->iqImbalance->setChecked(m_settings.m_iqCorrection);

    ui->hwDecim->setCurrentIndex(m_settings.m_log2HardDecim);
    ui->swDecim->setCurrentIndex(m_settings.m_log2SoftDecim);

    updateADCRate();

    ui->lpf->setValue(m_settings.m_lpfBW / 1000);
    ui->pwrmode->setCurrentIndex(m_settings.m_pwrmode);

    ui->gain->setValue(m_settings.m_gain);
    ui->gainText->setText(tr("%1").arg(m_settings.m_gain));

    ui->antenna->setCurrentIndex((int) m_settings.m_antennaPath);

    ui->gainMode->setCurrentIndex((int) m_settings.m_gainMode);
    ui->lnaGain->setValue(m_settings.m_lnaGain);
    ui->tiaGain->setCurrentIndex(m_settings.m_tiaGain - 1);
    ui->pgaGain->setValue(m_settings.m_pgaGain);

    if (m_settings.m_gainMode == XTRXInputSettings::GAIN_AUTO)
    {
        ui->gain->setEnabled(true);
        ui->lnaGain->setEnabled(false);
        ui->tiaGain->setEnabled(false);
        ui->pgaGain->setEnabled(false);
    }
    else
    {
        ui->gain->setEnabled(false);
        ui->lnaGain->setEnabled(true);
        ui->tiaGain->setEnabled(true);
        ui->pgaGain->setEnabled(true);
    }

    setNCODisplay();

    ui->ncoEnable->setChecked(m_settings.m_ncoEnable);
}

void XTRXInputGUI::setNCODisplay()
{
    int ncoHalfRange = (m_settings.m_devSampleRate * (1<<(m_settings.m_log2HardDecim)))/2;
    ui->ncoFrequency->setValueRange(
            false,
            8,
            -ncoHalfRange,
            ncoHalfRange);

    ui->ncoFrequency->blockSignals(true);
    ui->ncoFrequency->setToolTip(QString("NCO frequency shift in Hz (Range: +/- %1 kHz)").arg(ncoHalfRange/1000));
    ui->ncoFrequency->setValue(m_settings.m_ncoFrequency);
    ui->ncoFrequency->blockSignals(false);
}

void XTRXInputGUI::setCenterFrequencyDisplay()
{
    int64_t centerFrequency = m_settings.m_centerFrequency;
    ui->centerFrequency->setToolTip(QString("Main center frequency in kHz (LO: %1 kHz)").arg(centerFrequency/1000));

    if (m_settings.m_ncoEnable) {
        centerFrequency += m_settings.m_ncoFrequency;
    }

    ui->centerFrequency->blockSignals(true);
    ui->centerFrequency->setValue(centerFrequency < 0 ? 0 : (uint64_t) centerFrequency/1000); // kHz
    ui->centerFrequency->blockSignals(false);
}

void XTRXInputGUI::setCenterFrequencySetting(uint64_t kHzValue)
{
    int64_t centerFrequency = kHzValue*1000;

    if (m_settings.m_ncoEnable) {
        centerFrequency -= m_settings.m_ncoFrequency;
    }

    m_settings.m_centerFrequency = centerFrequency < 0 ? 0 : (uint64_t) centerFrequency;
    ui->centerFrequency->setToolTip(QString("Main center frequency in kHz (LO: %1 kHz)").arg(centerFrequency/1000));
}

void XTRXInputGUI::sendSettings()
{
    if(!m_updateTimer.isActive())
        m_updateTimer.start(100);
}

void XTRXInputGUI::updateHardware()
{
    if (m_doApplySettings)
    {
        qDebug() << "XTRXInputGUI::updateHardware";
        XTRXInput::MsgConfigureXTRX* message = XTRXInput::MsgConfigureXTRX::create(m_settings, m_forceSettings);
        m_XTRXInput->getInputMessageQueue()->push(message);
        m_forceSettings = false;
        m_updateTimer.stop();
    }
}

void XTRXInputGUI::updateStatus()
{
    int state = m_deviceUISet->m_deviceAPI->state();

    if(m_lastEngineState != state)
    {
        switch(state)
        {
        case DeviceAPI::StNotStarted:
            ui->startStop->setStyleSheet("QToolButton { background:rgb(79,79,79); }");
            break;
        case DeviceAPI::StIdle:
            ui->startStop->setStyleSheet("QToolButton { background-color : blue; }");
            break;
        case DeviceAPI::StRunning:
            ui->startStop->setStyleSheet("QToolButton { background-color : green; }");
            break;
        case DeviceAPI::StError:
            ui->startStop->setStyleSheet("QToolButton { background-color : red; }");
            QMessageBox::information(this, tr("Message"), m_deviceUISet->m_deviceAPI->errorMessage());
            break;
        default:
            break;
        }

        m_lastEngineState = state;
    }

    if (m_statusCounter < 1)
    {
        m_statusCounter++;
    }
    else
    {
        XTRXInput::MsgGetStreamInfo* message = XTRXInput::MsgGetStreamInfo::create();
        m_XTRXInput->getInputMessageQueue()->push(message);
        m_statusCounter = 0;
    }

    if (m_deviceStatusCounter < 10)
    {
        m_deviceStatusCounter++;
    }
    else
    {
        if (m_deviceUISet->m_deviceAPI->isBuddyLeader())
        {
            XTRXInput::MsgGetDeviceInfo* message = XTRXInput::MsgGetDeviceInfo::create();
            m_XTRXInput->getInputMessageQueue()->push(message);
        }

        m_deviceStatusCounter = 0;
    }
}

void XTRXInputGUI::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void XTRXInputGUI::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        XTRXInput::MsgStartStop *message = XTRXInput::MsgStartStop::create(checked);
        m_XTRXInput->getInputMessageQueue()->push(message);
    }
}

void XTRXInputGUI::on_centerFrequency_changed(quint64 value)
{
    setCenterFrequencySetting(value);
    sendSettings();
}

void XTRXInputGUI::on_ncoFrequency_changed(qint64 value)
{
    m_settings.m_ncoFrequency = value;
    setCenterFrequencyDisplay();
    sendSettings();
}

void XTRXInputGUI::on_ncoEnable_toggled(bool checked)
{
    m_settings.m_ncoEnable = checked;
    setCenterFrequencyDisplay();
    sendSettings();
}

void XTRXInputGUI::on_dcOffset_toggled(bool checked)
{
    m_settings.m_dcBlock = checked;
    sendSettings();
}

void XTRXInputGUI::on_iqImbalance_toggled(bool checked)
{
    m_settings.m_iqCorrection = checked;
    sendSettings();
}

void XTRXInputGUI::on_sampleRate_changed(quint64 value)
{
    if (m_sampleRateMode) {
        m_settings.m_devSampleRate = value;
    } else {
        m_settings.m_devSampleRate = value * (1 << m_settings.m_log2SoftDecim);
    }

    updateADCRate();
    setNCODisplay();
    sendSettings();
}

void XTRXInputGUI::on_hwDecim_currentIndexChanged(int index)
{
    if ((index <0) || (index > 5)) {
        return;
    }

    m_settings.m_log2HardDecim = index;

    updateADCRate();
    setNCODisplay();
    sendSettings();
}

void XTRXInputGUI::on_swDecim_currentIndexChanged(int index)
{
    if ((index <0) || (index > 6)) {
        return;
    }

    m_settings.m_log2SoftDecim = index;
    displaySampleRate();

    if (m_sampleRateMode) {
        m_settings.m_devSampleRate = ui->sampleRate->getValueNew();
    } else {
        m_settings.m_devSampleRate = ui->sampleRate->getValueNew() * (1 << m_settings.m_log2SoftDecim);
    }

    sendSettings();
}

void XTRXInputGUI::on_lpf_changed(quint64 value)
{
    m_settings.m_lpfBW = value * 1000;
    sendSettings();
}

void XTRXInputGUI::on_gainMode_currentIndexChanged(int index)
{
    m_settings.m_gainMode = (XTRXInputSettings::GainMode) index;

    if (index == 0)
    {
        ui->gain->setEnabled(true);
        ui->lnaGain->setEnabled(false);
        ui->tiaGain->setEnabled(false);
        ui->pgaGain->setEnabled(false);
    }
    else
    {
        ui->gain->setEnabled(false);
        ui->lnaGain->setEnabled(true);
        ui->tiaGain->setEnabled(true);
        ui->pgaGain->setEnabled(true);
    }

    sendSettings();
}

void XTRXInputGUI::on_gain_valueChanged(int value)
{
    m_settings.m_gain = value;
    ui->gainText->setText(tr("%1").arg(m_settings.m_gain));
    sendSettings();
}

void XTRXInputGUI::on_lnaGain_valueChanged(int value)
{
    m_settings.m_lnaGain = value;
    ui->lnaGainText->setText(tr("%1").arg(m_settings.m_lnaGain));
    sendSettings();
}

void XTRXInputGUI::on_tiaGain_currentIndexChanged(int index)
{
    m_settings.m_tiaGain = index + 1;
    sendSettings();
}

void XTRXInputGUI::on_pgaGain_valueChanged(int value)
{
    m_settings.m_pgaGain = value;
    ui->pgaGainText->setText(tr("%1").arg(m_settings.m_pgaGain));
    sendSettings();
}

void XTRXInputGUI::on_antenna_currentIndexChanged(int index)
{
    m_settings.m_antennaPath = (xtrx_antenna_t) index;
    sendSettings();
}

void XTRXInputGUI::on_extClock_clicked()
{
    m_settings.m_extClock = ui->extClock->getExternalClockActive();
    m_settings.m_extClockFreq = ui->extClock->getExternalClockFrequency();
    qDebug("XTRXInputGUI::on_extClock_clicked: %u Hz %s", m_settings.m_extClockFreq, m_settings.m_extClock ? "on" : "off");
    sendSettings();
}

void XTRXInputGUI::on_pwrmode_currentIndexChanged(int index)
{
    m_settings.m_pwrmode = index;
    sendSettings();
}

void XTRXInputGUI::on_sampleRateMode_toggled(bool checked)
{
    m_sampleRateMode = checked;
    displaySampleRate();
}

void XTRXInputGUI::openDeviceSettingsDialog(const QPoint& p)
{
    BasicDeviceSettingsDialog dialog(this);
    dialog.setUseReverseAPI(m_settings.m_useReverseAPI);
    dialog.setReverseAPIAddress(m_settings.m_reverseAPIAddress);
    dialog.setReverseAPIPort(m_settings.m_reverseAPIPort);
    dialog.setReverseAPIDeviceIndex(m_settings.m_reverseAPIDeviceIndex);

    dialog.move(p);
    dialog.exec();

    m_settings.m_useReverseAPI = dialog.useReverseAPI();
    m_settings.m_reverseAPIAddress = dialog.getReverseAPIAddress();
    m_settings.m_reverseAPIPort = dialog.getReverseAPIPort();
    m_settings.m_reverseAPIDeviceIndex = dialog.getReverseAPIDeviceIndex();

    sendSettings();
}
