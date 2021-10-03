///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Bernhard Isemann, oe3bia                                   //
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

#include <stdio.h>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "device/deviceapi.h"
#include "device/deviceuiset.h"
#include "plutosdr/deviceplutosdr.h"
#include "plutosdrinput.h"
#include "ui_plutosdrinputgui.h"
#include "plutosdrinputgui.h"

PlutoSDRInputGui::PlutoSDRInputGui(DeviceUISet *deviceUISet, QWidget* parent) :
    DeviceGUI(parent),
    ui(new Ui::PlutoSDRInputGUI),
    m_deviceUISet(deviceUISet),
    m_settings(),
    m_sampleRateMode(true),
    m_forceSettings(true),
    m_sampleSource(NULL),
    m_sampleRate(0),
    m_deviceCenterFrequency(0),
    m_lastEngineState(DeviceAPI::StNotStarted),
    m_doApplySettings(true),
    m_statusCounter(0)
{
    m_sampleSource = (PlutoSDRInput*) m_deviceUISet->m_deviceAPI->getSampleSource();

    ui->setupUi(this);
    ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    updateFrequencyLimits();

    ui->sampleRate->setColorMapper(ColorMapper(ColorMapper::GrayGreenYellow));
    ui->sampleRate->setValueRange(8, DevicePlutoSDR::srLowLimitFreq, DevicePlutoSDR::srHighLimitFreq);

    ui->lpf->setColorMapper(ColorMapper(ColorMapper::GrayYellow));

    quint32 minLimit, maxLimit;
    ((PlutoSDRInput *) m_sampleSource)->getbbLPRange(minLimit, maxLimit);
    ui->lpf->setValueRange(5, minLimit/1000, maxLimit/1000);

    ui->lpFIR->setColorMapper(ColorMapper(ColorMapper::GrayYellow));
    ui->lpFIR->setValueRange(5, 1U, 56000U); // will be dynamically recalculated

    ui->swDecimLabel->setText(QString::fromUtf8("S\u2193"));
    ui->lpFIRDecimationLabel->setText(QString::fromUtf8("\u2193"));

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));

    blockApplySettings(true);
    displaySettings();
    blockApplySettings(false);

    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));
    connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    m_statusTimer.start(500);

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
    m_sampleSource->setMessageQueueToGUI(&m_inputMessageQueue);
}

PlutoSDRInputGui::~PlutoSDRInputGui()
{
    delete ui;
}

void PlutoSDRInputGui::destroy()
{
    delete this;
}

void PlutoSDRInputGui::resetToDefaults()
{

}

QByteArray PlutoSDRInputGui::serialize() const
{
    return m_settings.serialize();
}

bool PlutoSDRInputGui::deserialize(const QByteArray& data)
{
    if(m_settings.deserialize(data))
    {
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        sendSettings(true);
        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

bool PlutoSDRInputGui::handleMessage(const Message& message)
{
    if (PlutoSDRInput::MsgConfigurePlutoSDR::match(message))
    {
        const PlutoSDRInput::MsgConfigurePlutoSDR& cfg = (PlutoSDRInput::MsgConfigurePlutoSDR&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (PlutoSDRInput::MsgStartStop::match(message))
    {
        PlutoSDRInput::MsgStartStop& notif = (PlutoSDRInput::MsgStartStop&) message;
        blockApplySettings(true);
        ui->startStop->setChecked(notif.getStartStop());
        blockApplySettings(false);

        return true;
    }
    else if (DevicePlutoSDRShared::MsgCrossReportToBuddy::match(message)) // message from buddy
    {
        DevicePlutoSDRShared::MsgCrossReportToBuddy& conf = (DevicePlutoSDRShared::MsgCrossReportToBuddy&) message;
        m_settings.m_devSampleRate = conf.getDevSampleRate();
        m_settings.m_lpfFIRlog2Decim = conf.getLpfFiRlog2IntDec();
        m_settings.m_lpfFIRBW = conf.getLpfFirbw();
        m_settings.m_LOppmTenths = conf.getLoPPMTenths();
        m_settings.m_lpfFIREnable = conf.isLpfFirEnable();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);

        return true;
    }
    else
    {
        return false;
    }
}

void PlutoSDRInputGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        PlutoSDRInput::MsgStartStop *message = PlutoSDRInput::MsgStartStop::create(checked);
        m_sampleSource->getInputMessageQueue()->push(message);
    }
}

void PlutoSDRInputGui::on_centerFrequency_changed(quint64 value)
{
    m_settings.m_centerFrequency = value * 1000;
    sendSettings();
}

void PlutoSDRInputGui::on_loPPM_valueChanged(int value)
{
    ui->loPPMText->setText(QString("%1").arg(QString::number(value/10.0, 'f', 1)));
    m_settings.m_LOppmTenths = value;
    sendSettings();
}

void PlutoSDRInputGui::on_dcOffset_toggled(bool checked)
{
    m_settings.m_dcBlock = checked;
    sendSettings();
}

void PlutoSDRInputGui::on_iqImbalance_toggled(bool checked)
{
    m_settings.m_iqCorrection = checked;
    sendSettings();
}

void PlutoSDRInputGui::on_rfDCOffset_toggled(bool checked)
{
    m_settings.m_hwRFDCBlock = checked;
    sendSettings();
}

void PlutoSDRInputGui::on_bbDCOffset_toggled(bool checked)
{
    m_settings.m_hwBBDCBlock = checked;
    sendSettings();
}

void PlutoSDRInputGui::on_hwIQImbalance_toggled(bool checked)
{
    m_settings.m_hwIQCorrection = checked;
    sendSettings();
}


void PlutoSDRInputGui::on_swDecim_currentIndexChanged(int index)
{
    m_settings.m_log2Decim = index > 6 ? 6 : index;
    displaySampleRate();
    m_settings.m_devSampleRate = ui->sampleRate->getValueNew();

    if (!m_sampleRateMode) {
        m_settings.m_devSampleRate <<= m_settings.m_log2Decim;
    }

    sendSettings();
}

void PlutoSDRInputGui::on_fcPos_currentIndexChanged(int index)
{
    m_settings.m_fcPos = (PlutoSDRInputSettings::fcPos_t) (index < (int) PlutoSDRInputSettings::FC_POS_END ? index : PlutoSDRInputSettings::FC_POS_CENTER);
    displayFcTooltip();
    sendSettings();
}

void PlutoSDRInputGui::on_sampleRate_changed(quint64 value)
{
    m_settings.m_devSampleRate = value;

    if (!m_sampleRateMode) {
        m_settings.m_devSampleRate <<= m_settings.m_log2Decim;
    }

    displayFcTooltip();
    sendSettings();
}

void PlutoSDRInputGui::on_lpf_changed(quint64 value)
{
    m_settings.m_lpfBW = value * 1000;
    sendSettings();
}

void PlutoSDRInputGui::on_lpFIREnable_toggled(bool checked)
{
    m_settings.m_lpfFIREnable = checked;
    ui->lpFIRDecimation->setEnabled(checked);
    ui->lpFIRGain->setEnabled(checked);
    sendSettings();
}

void PlutoSDRInputGui::on_lpFIR_changed(quint64 value)
{
    m_settings.m_lpfFIRBW = value * 1000;
    sendSettings();
}

void PlutoSDRInputGui::on_lpFIRDecimation_currentIndexChanged(int index)
{
    m_settings.m_lpfFIRlog2Decim = index > 2 ? 2 : index;
    setSampleRateLimits();
    sendSettings();
}

void PlutoSDRInputGui::on_lpFIRGain_currentIndexChanged(int index)
{
    m_settings.m_lpfFIRGain = 6*(index > 3 ? 3 : index) - 12;
    sendSettings();
}

void PlutoSDRInputGui::on_gainMode_currentIndexChanged(int index)
{
    m_settings.m_gainMode = (PlutoSDRInputSettings::GainMode) (index < PlutoSDRInputSettings::GAIN_END ? index : 0);
    ui->gain->setEnabled(m_settings.m_gainMode == PlutoSDRInputSettings::GAIN_MANUAL);
    sendSettings();
}

void PlutoSDRInputGui::on_gain_valueChanged(int value)
{
    ui->gainText->setText(tr("%1").arg(value));
    m_settings.m_gain = value;
    sendSettings();
}

void PlutoSDRInputGui::on_antenna_currentIndexChanged(int index)
{
    m_settings.m_antennaPath = (PlutoSDRInputSettings::RFPath) (index < PlutoSDRInputSettings::RFPATH_END ? index : 0);
    sendSettings();
}

void PlutoSDRInputGui::on_transverter_clicked()
{
    m_settings.m_transverterMode = ui->transverter->getDeltaFrequencyAcive();
    m_settings.m_transverterDeltaFrequency = ui->transverter->getDeltaFrequency();
    m_settings.m_iqOrder = ui->transverter->getIQOrder();
    qDebug("PlutoSDRInputGui::on_transverter_clicked: %lld Hz %s", m_settings.m_transverterDeltaFrequency, m_settings.m_transverterMode ? "on" : "off");
    updateFrequencyLimits();
    m_settings.m_centerFrequency = ui->centerFrequency->getValueNew()*1000;
    sendSettings();
}

void PlutoSDRInputGui::on_sampleRateMode_toggled(bool checked)
{
    m_sampleRateMode = checked;
    displaySampleRate();
}

void PlutoSDRInputGui::displaySampleRate()
{
    ui->sampleRate->blockSignals(true);
    displayFcTooltip();

    if (m_sampleRateMode)
    {
        ui->sampleRateMode->setStyleSheet("QToolButton { background:rgb(60,60,60); }");
        ui->sampleRateMode->setText("SR");
        ui->sampleRate->setValueRange(8, DevicePlutoSDR::srLowLimitFreq, DevicePlutoSDR::srHighLimitFreq);
        ui->sampleRate->setValue(m_settings.m_devSampleRate);
        ui->sampleRate->setToolTip("Device to host sample rate (S/s)");
        ui->deviceRateText->setToolTip("Baseband sample rate (S/s)");
        uint32_t basebandSampleRate = m_settings.m_devSampleRate/(1<<m_settings.m_log2Decim);
        ui->deviceRateText->setText(tr("%1k").arg(QString::number(basebandSampleRate / 1000.0f, 'g', 5)));
    }
    else
    {
        ui->sampleRateMode->setStyleSheet("QToolButton { background:rgb(50,50,50); }");
        ui->sampleRateMode->setText("BB");
        ui->sampleRate->setValueRange(8, DevicePlutoSDR::srLowLimitFreq/(1<<m_settings.m_log2Decim), DevicePlutoSDR::srHighLimitFreq/(1<<m_settings.m_log2Decim));
        ui->sampleRate->setValue(m_settings.m_devSampleRate/(1<<m_settings.m_log2Decim));
        ui->sampleRate->setToolTip("Baseband sample rate (S/s)");
        ui->deviceRateText->setToolTip("Device to host sample rate (S/s)");
        ui->deviceRateText->setText(tr("%1k").arg(QString::number(m_settings.m_devSampleRate / 1000.0f, 'g', 5)));
    }

    ui->sampleRate->blockSignals(false);
}

void PlutoSDRInputGui::displayFcTooltip()
{
    int32_t fShift = DeviceSampleSource::calculateFrequencyShift(
        m_settings.m_log2Decim,
        (DeviceSampleSource::fcPos_t) m_settings.m_fcPos,
        m_settings.m_devSampleRate,
        DeviceSampleSource::FrequencyShiftScheme::FSHIFT_STD
    );
    ui->fcPos->setToolTip(tr("Relative position of device center frequency: %1 kHz").arg(QString::number(fShift / 1000.0f, 'g', 5)));
}

void PlutoSDRInputGui::displaySettings()
{
    ui->transverter->setDeltaFrequency(m_settings.m_transverterDeltaFrequency);
    ui->transverter->setDeltaFrequencyActive(m_settings.m_transverterMode);
    ui->transverter->setIQOrder(m_settings.m_iqOrder);
    updateFrequencyLimits();
    ui->centerFrequency->setValue(m_settings.m_centerFrequency / 1000);
    displaySampleRate();

    ui->dcOffset->setChecked(m_settings.m_dcBlock);
    ui->iqImbalance->setChecked(m_settings.m_iqCorrection);
    ui->bbDCOffset->setChecked(m_settings.m_hwBBDCBlock);
    ui->rfDCOffset->setChecked(m_settings.m_hwRFDCBlock);
    ui->hwIQImbalance->setChecked(m_settings.m_hwIQCorrection);
    ui->loPPM->setValue(m_settings.m_LOppmTenths);
    ui->loPPMText->setText(QString("%1").arg(QString::number(m_settings.m_LOppmTenths/10.0, 'f', 1)));

    ui->swDecim->setCurrentIndex(m_settings.m_log2Decim);
    ui->fcPos->setCurrentIndex((int) m_settings.m_fcPos);

    ui->lpf->setValue(m_settings.m_lpfBW / 1000);

    ui->lpFIREnable->setChecked(m_settings.m_lpfFIREnable);
    ui->lpFIR->setValue(m_settings.m_lpfFIRBW / 1000);
    ui->lpFIRDecimation->setCurrentIndex(m_settings.m_lpfFIRlog2Decim);
    ui->lpFIRGain->setCurrentIndex((m_settings.m_lpfFIRGain + 12)/6);
    ui->lpFIRDecimation->setEnabled(m_settings.m_lpfFIREnable);
    ui->lpFIRGain->setEnabled(m_settings.m_lpfFIREnable);

    ui->gainMode->setCurrentIndex((int) m_settings.m_gainMode);
    ui->gain->setValue(m_settings.m_gain);
    ui->gainText->setText(tr("%1").arg(m_settings.m_gain));

    ui->antenna->setCurrentIndex((int) m_settings.m_antennaPath);

    setFIRBWLimits();
    setSampleRateLimits();
}

void PlutoSDRInputGui::sendSettings(bool forceSettings)
{
    m_forceSettings = forceSettings;
    if(!m_updateTimer.isActive()) { m_updateTimer.start(100); }
}

void PlutoSDRInputGui::updateHardware()
{
    if (m_doApplySettings)
    {
        qDebug() << "PlutoSDRInputGui::updateHardware";
        PlutoSDRInput::MsgConfigurePlutoSDR* message = PlutoSDRInput::MsgConfigurePlutoSDR::create(m_settings, m_forceSettings);
        m_sampleSource->getInputMessageQueue()->push(message);
        m_forceSettings = false;
        m_updateTimer.stop();
    }
}

void PlutoSDRInputGui::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void PlutoSDRInputGui::updateStatus()
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

    if (m_statusCounter % 2 == 0) // 1s
    {
        uint32_t adcRate = ((PlutoSDRInput *) m_sampleSource)->getADCSampleRate();

        if (adcRate < 100000000) {
            ui->adcRateText->setText(tr("%1k").arg(QString::number(adcRate / 1000.0f, 'g', 5)));
        } else {
            ui->adcRateText->setText(tr("%1M").arg(QString::number(adcRate / 1000000.0f, 'g', 5)));
        }
    }

    if (m_statusCounter % 4 == 0) // 2s
    {
        std::string rssiStr;
        ((PlutoSDRInput *) m_sampleSource)->getRSSI(rssiStr);
        ui->rssiText->setText(tr("-%1").arg(QString::fromStdString(rssiStr)));
        int gaindB;
        ((PlutoSDRInput *) m_sampleSource)->getGain(gaindB);
        ui->actualGainText->setText(tr("%1").arg(gaindB));
    }

    if (m_statusCounter % 10 == 0) // 5s
    {
        if (m_deviceUISet->m_deviceAPI->isBuddyLeader()) {
            ((PlutoSDRInput *) m_sampleSource)->fetchTemperature();
        }

        ui->temperatureText->setText(tr("%1C").arg(QString::number(((PlutoSDRInput *) m_sampleSource)->getTemperature(), 'f', 0)));
    }

    m_statusCounter++;
}

void PlutoSDRInputGui::setFIRBWLimits()
{
    float high = DevicePlutoSDR::firBWHighLimitFactor * ((PlutoSDRInput *) m_sampleSource)->getFIRSampleRate();
    float low = DevicePlutoSDR::firBWLowLimitFactor * ((PlutoSDRInput *) m_sampleSource)->getFIRSampleRate();
    ui->lpFIR->setValueRange(5, (int(low)/1000)+1, (int(high)/1000)+1);
    ui->lpFIR->setValue(m_settings.m_lpfFIRBW/1000);
}

void PlutoSDRInputGui::setSampleRateLimits()
{
    uint32_t low = ui->lpFIREnable->isChecked() ? DevicePlutoSDR::srLowLimitFreq / (1<<ui->lpFIRDecimation->currentIndex()) : DevicePlutoSDR::srLowLimitFreq;
    ui->sampleRate->setValueRange(8, low, DevicePlutoSDR::srHighLimitFreq);
    ui->sampleRate->setValue(m_settings.m_devSampleRate);
}

void PlutoSDRInputGui::updateFrequencyLimits()
{
    qint64 minLimit, maxLimit;
    // values should be in kHz
    qint64 deltaFrequency = m_settings.m_transverterMode ? m_settings.m_transverterDeltaFrequency/1000 : 0;
    ((PlutoSDRInput *) m_sampleSource)->getLORange(minLimit, maxLimit);

    minLimit = minLimit/1000 + deltaFrequency;
    maxLimit = maxLimit/1000 + deltaFrequency;

    minLimit = minLimit < 0 ? 0 : minLimit > 9999999 ? 9999999 : minLimit;
    maxLimit = maxLimit < 0 ? 0 : maxLimit > 9999999 ? 9999999 : maxLimit;

    qDebug("PlutoSDRInputGui::updateFrequencyLimits: delta: %lld min: %lld max: %lld", deltaFrequency, minLimit, maxLimit);

    ui->centerFrequency->setValueRange(7, minLimit, maxLimit);
}

void PlutoSDRInputGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {
        qDebug("PlutoSDRInputGui::handleInputMessages: message: %s", message->getIdentifier());

        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            m_sampleRate = notif->getSampleRate();
            m_deviceCenterFrequency = notif->getCenterFrequency();
            qDebug("PlutoSDRInputGui::handleInputMessages: DSPSignalNotification: SampleRate: %d, CenterFrequency: %llu", notif->getSampleRate(), notif->getCenterFrequency());
            updateSampleRateAndFrequency();
            setFIRBWLimits();

            delete message;
        }
        else
        {
            if (handleMessage(*message))
            {
                delete message;
            }
        }
    }
}

void PlutoSDRInputGui::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_deviceCenterFrequency);
    displaySampleRate();
}

void PlutoSDRInputGui::openDeviceSettingsDialog(const QPoint& p)
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
