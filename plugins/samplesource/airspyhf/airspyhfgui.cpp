///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Bernhard Isemann, oe3bia                                   //
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

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include <libairspyhf/airspyhf.h>

#include <device/deviceapi.h>
#include "device/deviceuiset.h"

#include "ui_airspyhfgui.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "airspyhfgui.h"

AirspyHFGui::AirspyHFGui(DeviceUISet *deviceUISet, QWidget* parent) :
	DeviceGUI(parent),
	ui(new Ui::AirspyHFGui),
	m_deviceUISet(deviceUISet),
	m_doApplySettings(true),
	m_forceSettings(true),
	m_settings(),
	m_sampleSource(0),
	m_lastEngineState(DeviceAPI::StNotStarted)
{
    m_sampleSource = (AirspyHFInput*) m_deviceUISet->m_deviceAPI->getSampleSource();

    ui->setupUi(this);
	ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
	updateFrequencyLimits();

	connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));
	connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
	m_statusTimer.start(500);

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));

	displaySettings();

	m_rates = ((AirspyHFInput*) m_sampleSource)->getSampleRates();
	displaySampleRates();
    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
    m_sampleSource->setMessageQueueToGUI(&m_inputMessageQueue);

    sendSettings();
}

AirspyHFGui::~AirspyHFGui()
{
	delete ui;
}

void AirspyHFGui::destroy()
{
	delete this;
}

void AirspyHFGui::resetToDefaults()
{
	m_settings.resetToDefaults();
	displaySettings();
	sendSettings();
}

QByteArray AirspyHFGui::serialize() const
{
	return m_settings.serialize();
}

bool AirspyHFGui::deserialize(const QByteArray& data)
{
	if(m_settings.deserialize(data)) {
		displaySettings();
		m_forceSettings = true;
		sendSettings();
		return true;
	} else {
		resetToDefaults();
		return false;
	}
}

bool AirspyHFGui::handleMessage(const Message& message)
{
    if (AirspyHFInput::MsgConfigureAirspyHF::match(message))
    {
        const AirspyHFInput::MsgConfigureAirspyHF& cfg = (AirspyHFInput::MsgConfigureAirspyHF&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (AirspyHFInput::MsgStartStop::match(message))
    {
        AirspyHFInput::MsgStartStop& notif = (AirspyHFInput::MsgStartStop&) message;
        blockApplySettings(true);
        ui->startStop->setChecked(notif.getStartStop());
        blockApplySettings(false);

        return true;
    }
    else
    {
        return false;
    }
}

void AirspyHFGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {
        qDebug("AirspyHFGui::handleInputMessages: message: %s", message->getIdentifier());

        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            m_sampleRate = notif->getSampleRate();
            m_deviceCenterFrequency = notif->getCenterFrequency();
            qDebug("AirspyGui::handleInputMessages: DSPSignalNotification: SampleRate:%d, CenterFrequency:%llu", notif->getSampleRate(), notif->getCenterFrequency());
            updateSampleRateAndFrequency();

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

void AirspyHFGui::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_deviceCenterFrequency);
    ui->deviceRateText->setText(tr("%1k").arg((float)m_sampleRate / 1000));
}

void AirspyHFGui::updateFrequencyLimits()
{
    // values in kHz
    qint64 deltaFrequency = m_settings.m_transverterMode ? m_settings.m_transverterDeltaFrequency/1000 : 0;

    qint64 minLimit;
    qint64 maxLimit;

    switch(m_settings.m_bandIndex)
    {
    case 1:
        minLimit = AirspyHFInput::loLowLimitFreqVHF/1000 + deltaFrequency;
        maxLimit = AirspyHFInput::loHighLimitFreqVHF/1000 + deltaFrequency;
        break;
    case 0:
    default:
        minLimit = AirspyHFInput::loLowLimitFreqHF/1000 + deltaFrequency;
        maxLimit = AirspyHFInput::loHighLimitFreqHF/1000 + deltaFrequency;
        break;
    }

    minLimit = minLimit < 0 ? 0 : minLimit > 9999999 ? 9999999 : minLimit;
    maxLimit = maxLimit < 0 ? 0 : maxLimit > 9999999 ? 9999999 : maxLimit;

    qDebug("AirspyHFGui::updateFrequencyLimits: delta: %lld min: %lld max: %lld", deltaFrequency, minLimit, maxLimit);

    ui->centerFrequency->setValueRange(7, minLimit, maxLimit);
}

void AirspyHFGui::displaySettings()
{
    blockApplySettings(true);
    ui->band->blockSignals(true);
    m_settings.m_bandIndex = m_settings.m_centerFrequency <= 31000000UL ? 0 : 1; // override
    ui->band->setCurrentIndex(m_settings.m_bandIndex);
    updateFrequencyLimits();
    ui->transverter->setDeltaFrequency(m_settings.m_transverterDeltaFrequency);
    ui->transverter->setDeltaFrequencyActive(m_settings.m_transverterMode);
    ui->transverter->setIQOrder(m_settings.m_iqOrder);
	ui->centerFrequency->setValue(m_settings.m_centerFrequency / 1000);
	ui->LOppm->setValue(m_settings.m_LOppmTenths);
	ui->LOppmText->setText(QString("%1").arg(QString::number(m_settings.m_LOppmTenths/10.0, 'f', 1)));
	ui->sampleRate->setCurrentIndex(m_settings.m_devSampleRateIndex);
	ui->decim->setCurrentIndex(m_settings.m_log2Decim);
    ui->band->blockSignals(false);
    ui->dsp->setChecked(m_settings.m_useDSP);
    ui->lna->setChecked(m_settings.m_useLNA);
    ui->att->setCurrentIndex(m_settings.m_attenuatorSteps);
	ui->dcOffset->setChecked(m_settings.m_dcBlock);
	ui->iqImbalance->setChecked(m_settings.m_iqCorrection);
    displayAGC();
    blockApplySettings(false);
}

void AirspyHFGui::displaySampleRates()
{
	unsigned int savedIndex = m_settings.m_devSampleRateIndex;
	ui->sampleRate->blockSignals(true);

	if (m_rates.size() > 0)
	{
		ui->sampleRate->clear();

		for (unsigned int i = 0; i < m_rates.size(); i++)
		{
		    int sampleRate = m_rates[i]/1000;
			ui->sampleRate->addItem(QString("%1").arg(QString("%1").arg(sampleRate, 5, 10, QChar(' '))));
		}
	}

	ui->sampleRate->blockSignals(false);

	if (savedIndex < m_rates.size())
	{
		ui->sampleRate->setCurrentIndex(savedIndex);
	}
	else
	{
		ui->sampleRate->setCurrentIndex((int) m_rates.size()-1);
	}
}

void AirspyHFGui::displayAGC()
{
    if (m_settings.m_useAGC)
    {
        if (m_settings.m_agcHigh) {
            ui->agc->setCurrentIndex(2);
        } else {
            ui->agc->setCurrentIndex(1);
        }
    }
    else
    {
        ui->agc->setCurrentIndex(0);
    }
}

void AirspyHFGui::sendSettings()
{
	if(!m_updateTimer.isActive())
		m_updateTimer.start(100);
}

void AirspyHFGui::on_centerFrequency_changed(quint64 value)
{
	m_settings.m_centerFrequency = value * 1000;
	sendSettings();
}

void AirspyHFGui::on_LOppm_valueChanged(int value)
{
    m_settings.m_LOppmTenths = value;
    ui->LOppmText->setText(QString("%1").arg(QString::number(m_settings.m_LOppmTenths/10.0, 'f', 1)));
    sendSettings();
}

void AirspyHFGui::on_resetLOppm_clicked()
{
    ui->LOppm->setValue(0);
}

void AirspyHFGui::on_sampleRate_currentIndexChanged(int index)
{
	m_settings.m_devSampleRateIndex = index;
	sendSettings();
}

void AirspyHFGui::on_decim_currentIndexChanged(int index)
{
	if ((index < 0) || (index > 8))
		return;
	m_settings.m_log2Decim = index;
	sendSettings();
}

void AirspyHFGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        AirspyHFInput::MsgStartStop *message = AirspyHFInput::MsgStartStop::create(checked);
        m_sampleSource->getInputMessageQueue()->push(message);
    }
}

void AirspyHFGui::on_transverter_clicked()
{
    m_settings.m_transverterMode = ui->transverter->getDeltaFrequencyAcive();
    m_settings.m_transverterDeltaFrequency = ui->transverter->getDeltaFrequency();
    m_settings.m_iqOrder = ui->transverter->getIQOrder();
    qDebug("AirspyHFGui::on_transverter_clicked: %lld Hz %s", m_settings.m_transverterDeltaFrequency, m_settings.m_transverterMode ? "on" : "off");
    updateFrequencyLimits();
    m_settings.m_centerFrequency = ui->centerFrequency->getValueNew()*1000;
    sendSettings();
}

void AirspyHFGui::on_band_currentIndexChanged(int index)
{
    if ((index < 0) || (index > 1)) {
        return;
    }

    m_settings.m_bandIndex = index;
    updateFrequencyLimits();
    qDebug("AirspyHFGui::on_band_currentIndexChanged: freq: %llu", ui->centerFrequency->getValueNew() * 1000);
    m_settings.m_centerFrequency = ui->centerFrequency->getValueNew() * 1000;
    sendSettings();
}

void AirspyHFGui::on_dsp_toggled(bool checked)
{
    m_settings.m_useDSP = checked;
    sendSettings();
}

void AirspyHFGui::on_lna_toggled(bool checked)
{
    m_settings.m_useLNA = checked;
    sendSettings();
}

void AirspyHFGui::on_agc_currentIndexChanged(int index)
{
    if (index == 0)
    {
        m_settings.m_useAGC = false;
        sendSettings();
    }
    else if (index <= 2)
    {
        m_settings.m_useAGC = true;

        if (index == 1) {
            m_settings.m_agcHigh = false;
        } else {
            m_settings.m_agcHigh = true;
        }

        sendSettings();
    }
}

void AirspyHFGui::on_att_currentIndexChanged(int index)
{
    if ((index >= 0) && (index <= 8))
    {
        m_settings.m_attenuatorSteps = index;
        sendSettings();
    }
}

void AirspyHFGui::on_dcOffset_toggled(bool checked)
{
	m_settings.m_dcBlock = checked;
	sendSettings();
}

void AirspyHFGui::on_iqImbalance_toggled(bool checked)
{
	m_settings.m_iqCorrection = checked;
	sendSettings();
}

void AirspyHFGui::updateHardware()
{
	qDebug() << "AirspyHFGui::updateHardware";
	AirspyHFInput::MsgConfigureAirspyHF* message = AirspyHFInput::MsgConfigureAirspyHF::create(m_settings, m_forceSettings);
	m_sampleSource->getInputMessageQueue()->push(message);
	m_forceSettings = false;
	m_updateTimer.stop();
}

void AirspyHFGui::updateStatus()
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
}

uint32_t AirspyHFGui::getDevSampleRate(unsigned int rate_index)
{
	if (rate_index < m_rates.size())
	{
		return m_rates[rate_index];
	}
	else
	{
		return m_rates[0];
	}
}

int AirspyHFGui::getDevSampleRateIndex(uint32_t sampeRate)
{
	for (unsigned int i=0; i < m_rates.size(); i++)
	{
		if (sampeRate == m_rates[i])
		{
			return i;
		}
	}

	return -1;
}

void AirspyHFGui::openDeviceSettingsDialog(const QPoint& p)
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
