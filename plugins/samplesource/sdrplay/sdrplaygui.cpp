///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Edouard Griffiths, F4EXB                                   //
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

#include "sdrplaygui.h"

#include "device/deviceapi.h"
#include "device/deviceuiset.h"

#include "ui_sdrplaygui.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"


SDRPlayGui::SDRPlayGui(DeviceUISet *deviceUISet, QWidget* parent) :
    DeviceGUI(parent),
    ui(new Ui::SDRPlayGui),
    m_deviceUISet(deviceUISet),
    m_doApplySettings(true),
    m_forceSettings(true)
{
    m_sampleSource = (SDRPlayInput*) m_deviceUISet->m_deviceAPI->getSampleSource();

    ui->setupUi(this);
    ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->centerFrequency->setValueRange(7, 10U, 12000U);

    ui->fBand->clear();
    for (unsigned int i = 0; i < SDRPlayBands::getNbBands(); i++)
    {
        ui->fBand->addItem(SDRPlayBands::getBandName(i));
    }

    ui->ifFrequency->clear();
    for (unsigned int i = 0; i < SDRPlayIF::getNbIFs(); i++)
    {
        ui->ifFrequency->addItem(QString::number(SDRPlayIF::getIF(i)/1000));
    }

    ui->samplerate->clear();
    for (unsigned int i = 0; i < SDRPlaySampleRates::getNbRates(); i++)
    {
        ui->samplerate->addItem(QString::number(SDRPlaySampleRates::getRate(i)/1000));
    }

    ui->bandwidth->clear();
    for (unsigned int i = 0; i < SDRPlayBandwidths::getNbBandwidths(); i++)
    {
        ui->bandwidth->addItem(QString::number(SDRPlayBandwidths::getBandwidth(i)/1000));
    }

    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));
    connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    m_statusTimer.start(500);

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));

    displaySettings();

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
    m_sampleSource->setMessageQueueToGUI(&m_inputMessageQueue);
}

SDRPlayGui::~SDRPlayGui()
{
    delete ui;
}

void SDRPlayGui::destroy()
{
    delete this;
}

void SDRPlayGui::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    sendSettings();
}

QByteArray SDRPlayGui::serialize() const
{
    return m_settings.serialize();
}

bool SDRPlayGui::deserialize(const QByteArray& data)
{
    if(m_settings.deserialize(data))
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

bool SDRPlayGui::handleMessage(const Message& message)
{
    if (SDRPlayInput::MsgConfigureSDRPlay::match(message))
    {
        const SDRPlayInput::MsgConfigureSDRPlay& cfg = (SDRPlayInput::MsgConfigureSDRPlay&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (SDRPlayInput::MsgReportSDRPlayGains::match(message))
    {
    	qDebug() << "SDRPlayGui::handleMessage: MsgReportSDRPlayGains";

    	SDRPlayInput::MsgReportSDRPlayGains msg = (SDRPlayInput::MsgReportSDRPlayGains&) message;

    	if (m_settings.m_tunerGainMode)
    	{
            ui->gainLNA->setChecked(msg.getLNAGain() != 0);
            ui->gainMixer->setChecked(msg.getMixerGain() != 0);
            ui->gainBaseband->setValue(msg.getBasebandGain());

            QString gainText = QStringLiteral("%1").arg(msg.getBasebandGain(), 2, 10, QLatin1Char('0'));
            ui->gainBasebandText->setText(gainText);
    	}
    	else
    	{
    	    ui->gainTuner->setValue(msg.getTunerGain());

            QString gainText = QStringLiteral("%1").arg(msg.getTunerGain(), 3, 10, QLatin1Char('0'));
            ui->gainTunerText->setText(gainText);
    	}

        return true;
    }
    else if (SDRPlayInput::MsgStartStop::match(message))
    {
        SDRPlayInput::MsgStartStop& notif = (SDRPlayInput::MsgStartStop&) message;
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

void SDRPlayGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {
        qDebug("SDRPlayGui::handleInputMessages: message: %s", message->getIdentifier());

        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            m_sampleRate = notif->getSampleRate();
            m_deviceCenterFrequency = notif->getCenterFrequency();
            qDebug("SDRPlayGui::handleInputMessages: DSPSignalNotification: SampleRate:%d, CenterFrequency:%llu", notif->getSampleRate(), notif->getCenterFrequency());
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

void SDRPlayGui::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_deviceCenterFrequency);
    ui->deviceRateText->setText(tr("%1k").arg((float)m_sampleRate / 1000));
}


void SDRPlayGui::displaySettings()
{
    ui->centerFrequency->setValue(m_settings.m_centerFrequency / 1000);

    ui->ppm->setValue(m_settings.m_LOppmTenths);
    ui->ppmText->setText(QString("%1").arg(QString::number(m_settings.m_LOppmTenths/10.0, 'f', 1)));

    ui->samplerate->setCurrentIndex(m_settings.m_devSampleRateIndex);

    ui->dcOffset->setChecked(m_settings.m_dcBlock);
    ui->iqImbalance->setChecked(m_settings.m_iqCorrection);

    ui->fBand->setCurrentIndex(m_settings.m_frequencyBandIndex);
    ui->bandwidth->setCurrentIndex(m_settings.m_bandwidthIndex);
    ui->ifFrequency->setCurrentIndex(m_settings.m_ifFrequencyIndex);
    ui->samplerate->setCurrentIndex(m_settings.m_devSampleRateIndex);

    ui->decim->setCurrentIndex(m_settings.m_log2Decim);
    ui->fcPos->setCurrentIndex((int) m_settings.m_fcPos);

    ui->gainTunerOn->setChecked(m_settings.m_tunerGainMode);

    if (m_settings.m_tunerGainMode)
    {
        ui->gainTuner->setEnabled(true);
        ui->gainLNA->setEnabled(false);
        ui->gainMixer->setEnabled(false);
        ui->gainBaseband->setEnabled(false);

        int gain = m_settings.m_tunerGain;
        ui->gainTuner->setValue(gain);
        QString gainText = QStringLiteral("%1").arg(gain, 3, 10, QLatin1Char('0'));
        ui->gainTunerText->setText(gainText);
        m_settings.m_tunerGain = gain;
    }
    else
    {
        ui->gainTuner->setEnabled(false);
        ui->gainLNA->setEnabled(true);
        ui->gainMixer->setEnabled(true);
        ui->gainBaseband->setEnabled(true);

        ui->gainLNA->setChecked(m_settings.m_lnaOn != 0);
        ui->gainMixer->setChecked(m_settings.m_mixerAmpOn != 0);

        int gain = m_settings.m_basebandGain;
        ui->gainBaseband->setValue(gain);
        QString gainText = QStringLiteral("%1").arg(gain, 2, 10, QLatin1Char('0'));
        ui->gainBasebandText->setText(gainText);
    }
}

void SDRPlayGui::sendSettings()
{
    if(!m_updateTimer.isActive())
        m_updateTimer.start(100);
}

void SDRPlayGui::updateHardware()
{
    qDebug() << "SDRPlayGui::updateHardware";
    SDRPlayInput::MsgConfigureSDRPlay* message = SDRPlayInput::MsgConfigureSDRPlay::create( m_settings, m_forceSettings);
    m_sampleSource->getInputMessageQueue()->push(message);
    m_forceSettings = false;
    m_updateTimer.stop();
}

void SDRPlayGui::updateStatus()
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

void SDRPlayGui::on_centerFrequency_changed(quint64 value)
{
    m_settings.m_centerFrequency = value * 1000;
    sendSettings();
}

void SDRPlayGui::on_ppm_valueChanged(int value)
{
    m_settings.m_LOppmTenths = value;
    ui->ppmText->setText(QString("%1").arg(QString::number(m_settings.m_LOppmTenths/10.0, 'f', 1)));
    sendSettings();
}

void SDRPlayGui::on_dcOffset_toggled(bool checked)
{
    qDebug("SDRPlayGui::on_dcOffset_toggled: %s", checked ? "on" : "off");
    m_settings.m_dcBlock = checked;
    sendSettings();
}

void SDRPlayGui::on_iqImbalance_toggled(bool checked)
{
    m_settings.m_iqCorrection = checked;
    sendSettings();
}

void SDRPlayGui::on_fBand_currentIndexChanged(int index)
{
    ui->centerFrequency->setValueRange(
            7,
            SDRPlayBands::getBandLow(index),
            SDRPlayBands::getBandHigh(index));

    ui->centerFrequency->setValue((SDRPlayBands::getBandLow(index)+SDRPlayBands::getBandHigh(index)) / 2);
    m_settings.m_centerFrequency = (SDRPlayBands::getBandLow(index)+SDRPlayBands::getBandHigh(index)) * 500;
    m_settings.m_frequencyBandIndex = index;

    sendSettings();
}

void SDRPlayGui::on_bandwidth_currentIndexChanged(int index)
{
    m_settings.m_bandwidthIndex = index;
    sendSettings();
}

void SDRPlayGui::on_samplerate_currentIndexChanged(int index)
{
    m_settings.m_devSampleRateIndex = index;
    sendSettings();
}

void SDRPlayGui::on_ifFrequency_currentIndexChanged(int index)
{
    m_settings.m_ifFrequencyIndex = index;
    sendSettings();
}

void SDRPlayGui::on_decim_currentIndexChanged(int index)
{
    m_settings.m_log2Decim = index;
    sendSettings();
}

void SDRPlayGui::on_fcPos_currentIndexChanged(int index)
{
    m_settings.m_fcPos = (SDRPlaySettings::fcPos_t) index;
    sendSettings();
}

void SDRPlayGui::on_gainTunerOn_toggled(bool checked)
{
    qDebug("SDRPlayGui::on_gainTunerOn_toggled: %s", checked ? "on" : "off");
    m_settings.m_tunerGainMode = true;
    ui->gainTuner->setEnabled(true);
    ui->gainLNA->setEnabled(false);
    ui->gainMixer->setEnabled(false);
    ui->gainBaseband->setEnabled(false);

    sendSettings();
}

void SDRPlayGui::on_gainTuner_valueChanged(int value)
{
    int gain = value;
    QString gainText = QStringLiteral("%1").arg(gain, 3, 10, QLatin1Char('0'));
    m_settings.m_tunerGain = gain;

    sendSettings();
}

void SDRPlayGui::on_gainManualOn_toggled(bool checked)
{
    qDebug("SDRPlayGui::on_gainManualOn_toggled: %s", checked ? "on" : "off");
    m_settings.m_tunerGainMode = false;
    ui->gainTuner->setEnabled(false);
    ui->gainLNA->setEnabled(true);
    ui->gainMixer->setEnabled(true);
    ui->gainBaseband->setEnabled(true);

    sendSettings();
}

void SDRPlayGui::on_gainLNA_toggled(bool checked)
{
	m_settings.m_lnaOn = checked ? 1 : 0;
	sendSettings();
}

void SDRPlayGui::on_gainMixer_toggled(bool checked)
{
	m_settings.m_mixerAmpOn = checked ? 1 : 0;
	sendSettings();
}

void SDRPlayGui::on_gainBaseband_valueChanged(int value)
{
	m_settings.m_basebandGain = value;

    QString gainText = QStringLiteral("%1").arg(value, 2, 10, QLatin1Char('0'));
    ui->gainBasebandText->setText(gainText);

	sendSettings();
}

void SDRPlayGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        SDRPlayInput::MsgStartStop *message = SDRPlayInput::MsgStartStop::create(checked);
        m_sampleSource->getInputMessageQueue()->push(message);
    }
}

void SDRPlayGui::openDeviceSettingsDialog(const QPoint& p)
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
