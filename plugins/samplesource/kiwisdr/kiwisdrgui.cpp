///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Vort                                                       //
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
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

#include <QTime>
#include <QDateTime>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>

#include "ui_kiwisdrgui.h"
#include "plugin/pluginapi.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "util/db.h"

#include "mainwindow.h"

#include "kiwisdrgui.h"
#include "device/deviceapi.h"
#include "device/deviceuiset.h"

KiwiSDRGui::KiwiSDRGui(DeviceUISet *deviceUISet, QWidget* parent) :
    DeviceGUI(parent),
    ui(new Ui::KiwiSDRGui),
    m_deviceUISet(deviceUISet),
    m_settings(),
    m_doApplySettings(true),
    m_forceSettings(true),
    m_sampleSource(0),
    m_tickCount(0),
    m_lastEngineState(DeviceAPI::StNotStarted)
{
    qDebug("KiwiSDRGui::KiwiSDRGui");
    m_sampleSource = m_deviceUISet->m_deviceAPI->getSampleSource();

	m_statusTooltips.push_back("Idle");          // 0
	m_statusTooltips.push_back("Connecting..."); // 1
	m_statusTooltips.push_back("Connected");     // 2
	m_statusTooltips.push_back("Error");         // 3
	m_statusTooltips.push_back("Disconnected");  // 4

	m_statusColors.push_back("gray");               // Idle
	m_statusColors.push_back("rgb(232, 212, 35)");  // Connecting (yellow)
	m_statusColors.push_back("rgb(35, 138, 35)");   // Connected (green)
	m_statusColors.push_back("rgb(232, 85, 85)");   // Error (red)
	m_statusColors.push_back("rgb(232, 85, 232)");  // Disconnected (magenta)

    ui->setupUi(this);
    ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->centerFrequency->setValueRange(7, 0, 9999999);

    displaySettings();

    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));
    connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    m_statusTimer.start(500);

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
    m_sampleSource->setMessageQueueToGUI(&m_inputMessageQueue);

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));
}

KiwiSDRGui::~KiwiSDRGui()
{
    delete ui;
}

void KiwiSDRGui::destroy()
{
    delete this;
}

void KiwiSDRGui::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    sendSettings();
}

QByteArray KiwiSDRGui::serialize() const
{
    return m_settings.serialize();
}

bool KiwiSDRGui::deserialize(const QByteArray& data)
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

void KiwiSDRGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
		KiwiSDRInput::MsgStartStop *message = KiwiSDRInput::MsgStartStop::create(checked);
        m_sampleSource->getInputMessageQueue()->push(message);
    }
}

void KiwiSDRGui::on_centerFrequency_changed(quint64 value)
{
    m_settings.m_centerFrequency = value * 1000;
    sendSettings();
}

void KiwiSDRGui::on_serverAddress_returnPressed()
{
	on_serverAddressApplyButton_clicked();
}

void KiwiSDRGui::on_serverAddressApplyButton_clicked()
{
	m_settings.m_serverAddress = ui->serverAddress->text();
	sendSettings();
}

void KiwiSDRGui::on_dcBlock_toggled(bool checked)
{
	m_settings.m_dcBlock = checked;
	sendSettings();
}

void KiwiSDRGui::on_agc_toggled(bool checked)
{
	m_settings.m_useAGC = checked;
	sendSettings();
}

void KiwiSDRGui::on_gain_valueChanged(int value)
{
	m_settings.m_gain = value;
	ui->gainText->setText(QString::number(m_settings.m_gain) + " dB");
	sendSettings();
}

void KiwiSDRGui::displaySettings()
{
    blockApplySettings(true);

    ui->centerFrequency->setValue(m_settings.m_centerFrequency / 1000);
	ui->serverAddress->setText(m_settings.m_serverAddress);
	ui->gain->setValue(m_settings.m_gain);
	ui->gainText->setText(QString::number(m_settings.m_gain) + " dB");
	ui->agc->setChecked(m_settings.m_useAGC);
    ui->dcBlock->setChecked(m_settings.m_dcBlock);

    blockApplySettings(false);
}

void KiwiSDRGui::sendSettings()
{
    if (!m_updateTimer.isActive()) {
        m_updateTimer.start(100);
    }
}

void KiwiSDRGui::updateHardware()
{
    if (m_doApplySettings)
    {
		KiwiSDRInput::MsgConfigureKiwiSDR* message = KiwiSDRInput::MsgConfigureKiwiSDR::create(m_settings, m_forceSettings);
        m_sampleSource->getInputMessageQueue()->push(message);
        m_forceSettings = false;
        m_updateTimer.stop();
    }
}

void KiwiSDRGui::updateStatus()
{
    int state = m_deviceUISet->m_deviceAPI->state();

    if (m_lastEngineState != state)
    {
        switch (state)
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

bool KiwiSDRGui::handleMessage(const Message& message)
{
    if (KiwiSDRInput::MsgConfigureKiwiSDR::match(message))
    {
        qDebug("KiwiSDRGui::handleMessage: MsgConfigureKiwiSDR");
        const KiwiSDRInput::MsgConfigureKiwiSDR& cfg = (KiwiSDRInput::MsgConfigureKiwiSDR&) message;
        m_settings = cfg.getSettings();
        displaySettings();
        return true;
    }
    else if (KiwiSDRInput::MsgStartStop::match(message))
    {
        qDebug("KiwiSDRGui::handleMessage: MsgStartStop");
		KiwiSDRInput::MsgStartStop& notif = (KiwiSDRInput::MsgStartStop&) message;
        blockApplySettings(true);
        ui->startStop->setChecked(notif.getStartStop());
        blockApplySettings(false);

        return true;
    }
	else if (KiwiSDRInput::MsgSetStatus::match(message))
	{
		qDebug("KiwiSDRGui::handleMessage: MsgSetStatus");
		KiwiSDRInput::MsgSetStatus& notif = (KiwiSDRInput::MsgSetStatus&) message;
		int status = notif.getStatus();
		ui->statusIndicator->setToolTip(m_statusTooltips[status]);
		ui->statusIndicator->setStyleSheet("QLabel { background-color: " +
			m_statusColors[status] + "; border-radius: 7px; }");
		return true;
	}
    else
    {
        return false;
    }
}

void KiwiSDRGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {
        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            m_deviceSampleRate = notif->getSampleRate();
            m_deviceCenterFrequency = notif->getCenterFrequency();
            qDebug("KiwiSDRGui::handleInputMessages: DSPSignalNotification: SampleRate:%d, CenterFrequency:%llu",
                    notif->getSampleRate(),
                    notif->getCenterFrequency());
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

void KiwiSDRGui::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_deviceSampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_deviceCenterFrequency);
    ui->deviceRateText->setText(tr("%1k").arg((float)m_deviceSampleRate / 1000));
}

void KiwiSDRGui::openDeviceSettingsDialog(const QPoint& p)
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
