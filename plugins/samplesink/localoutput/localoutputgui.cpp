///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
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

#include <stdint.h>
#include <sstream>
#include <iostream>

#include <QDebug>
#include <QMessageBox>
#include <QTime>
#include <QDateTime>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>

#include "ui_localoutputgui.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "mainwindow.h"
#include "util/simpleserializer.h"
#include "device/deviceapi.h"
#include "device/deviceuiset.h"
#include "localoutputgui.h"


LocalOutputGui::LocalOutputGui(DeviceUISet *deviceUISet, QWidget* parent) :
	DeviceGUI(parent),
	ui(new Ui::LocalOutputGui),
	m_deviceUISet(deviceUISet),
	m_settings(),
	m_sampleSink(0),
	m_acquisition(false),
	m_streamSampleRate(0),
	m_streamCenterFrequency(0),
	m_lastEngineState(DeviceAPI::StNotStarted),
    m_samplesCount(0),
    m_tickCount(0),
    m_doApplySettings(true),
    m_forceSettings(true)
{
    m_paletteGreenText.setColor(QPalette::WindowText, Qt::green);
    m_paletteWhiteText.setColor(QPalette::WindowText, Qt::white);

	ui->setupUi(this);

	ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
	ui->centerFrequency->setValueRange(7, 0, 9999999U);

	ui->centerFrequencyHz->setColorMapper(ColorMapper(ColorMapper::GrayGold));
	ui->centerFrequencyHz->setValueRange(3, 0, 999U);

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));

	displaySettings();

	connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
	m_statusTimer.start(500);
    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));

    m_sampleSink = (LocalOutput*) m_deviceUISet->m_deviceAPI->getSampleSink();

	connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
	m_sampleSink->setMessageQueueToGUI(&m_inputMessageQueue);

    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));

    m_forceSettings = true;
    sendSettings();
}

LocalOutputGui::~LocalOutputGui()
{
    disconnect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    delete m_networkManager;
	delete ui;
}

void LocalOutputGui::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void LocalOutputGui::destroy()
{
	delete this;
}

void LocalOutputGui::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    m_forceSettings = true;
    sendSettings();
}

QByteArray LocalOutputGui::serialize() const
{
    return m_settings.serialize();
}

bool LocalOutputGui::deserialize(const QByteArray& data)
{
    qDebug("LocalOutputGui::deserialize");

    if (m_settings.deserialize(data))
    {
        displaySettings();
        m_forceSettings = true;
        sendSettings();

        return true;
    }
    else
    {
        return false;
    }
}

bool LocalOutputGui::handleMessage(const Message& message)
{
    if (LocalOutput::MsgConfigureLocalOutput::match(message))
    {
        const LocalOutput::MsgConfigureLocalOutput& cfg = (LocalOutput::MsgConfigureLocalOutput&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
	else if (LocalOutput::MsgStartStop::match(message))
    {
	    LocalOutput::MsgStartStop& notif = (LocalOutput::MsgStartStop&) message;
        blockApplySettings(true);
        ui->startStop->setChecked(notif.getStartStop());
        blockApplySettings(false);

        return true;
    }
    else if (LocalOutput::MsgReportSampleRateAndFrequency::match(message))
    {
        LocalOutput::MsgReportSampleRateAndFrequency& notif = (LocalOutput::MsgReportSampleRateAndFrequency&) message;
        m_streamSampleRate = notif.getSampleRate();
        m_streamCenterFrequency = notif.getCenterFrequency();
        updateSampleRateAndFrequency();

        return true;
    }
	else
	{
		return false;
	}
}

void LocalOutputGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {
        //qDebug("LocalOutputGui::handleInputMessages: message: %s", message->getIdentifier());

        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;

            if (notif->getSampleRate() != m_streamSampleRate) {
                m_streamSampleRate = notif->getSampleRate();
            }

            m_streamCenterFrequency = notif->getCenterFrequency();

            qDebug("LocalOutputGui::handleInputMessages: DSPSignalNotification: SampleRate:%d, CenterFrequency:%llu", notif->getSampleRate(), notif->getCenterFrequency());

            updateSampleRateAndFrequency();
            DSPSignalNotification *fwd = new DSPSignalNotification(*notif);
            m_sampleSink->getInputMessageQueue()->push(fwd);

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

void LocalOutputGui::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_streamSampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_streamCenterFrequency);
    ui->deviceRateText->setText(tr("%1k").arg((float)m_streamSampleRate / 1000));
    blockApplySettings(true);
    ui->centerFrequency->setValue(m_streamCenterFrequency / 1000);
    ui->centerFrequencyHz->setValue(m_streamCenterFrequency % 1000);
    blockApplySettings(false);
}

void LocalOutputGui::displaySettings()
{
    blockApplySettings(true);

    ui->centerFrequency->setValue(m_streamCenterFrequency / 1000);
    ui->centerFrequencyHz->setValue(m_streamCenterFrequency % 1000);
    ui->deviceRateText->setText(tr("%1k").arg(m_streamSampleRate / 1000.0));

	blockApplySettings(false);
}

void LocalOutputGui::sendSettings()
{
    if(!m_updateTimer.isActive())
        m_updateTimer.start(100);
}

void LocalOutputGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        LocalOutput::MsgStartStop *message = LocalOutput::MsgStartStop::create(checked);
        m_sampleSink->getInputMessageQueue()->push(message);
    }
}

void LocalOutputGui::updateHardware()
{
    if (m_doApplySettings)
    {
        qDebug() << "LocalOutputGui::updateHardware";
        LocalOutput::MsgConfigureLocalOutput* message =
                LocalOutput::MsgConfigureLocalOutput::create(m_settings, m_forceSettings);
        m_sampleSink->getInputMessageQueue()->push(message);
        m_forceSettings = false;
        m_updateTimer.stop();
    }
}

void LocalOutputGui::updateStatus()
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

void LocalOutputGui::openDeviceSettingsDialog(const QPoint& p)
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
