///////////////////////////////////////////////////////////////////////////////////
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
#include <QString>
#include <QMessageBox>

#include "ui_testsinkgui.h"
#include "plugin/pluginapi.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "dsp/spectrumvis.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"

#include "maincore.h"

#include "device/deviceapi.h"
#include "device/deviceuiset.h"
#include "testsinkgui.h"

TestSinkGui::TestSinkGui(DeviceUISet *deviceUISet, QWidget* parent) :
	DeviceGUI(parent),
	ui(new Ui::TestSinkGui),
	m_deviceUISet(deviceUISet),
	m_doApplySettings(true),
	m_forceSettings(true),
	m_settings(),
    m_sampleRate(0),
    m_generation(false),
	m_samplesCount(0),
	m_tickCount(0),
	m_lastEngineState(DeviceAPI::StNotStarted)
{
	ui->setupUi(this);
    m_sampleSink = (TestSinkOutput*) m_deviceUISet->m_deviceAPI->getSampleSink();

	ui->centerFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
	ui->centerFrequency->setValueRange(7, 0, pow(10,7));

    ui->sampleRate->setColorMapper(ColorMapper(ColorMapper::GrayGreenYellow));
    ui->sampleRate->setValueRange(8, 32000U, 90000000U);

    m_spectrumVis = m_sampleSink->getSpectrumVis();
    m_spectrumVis->setGLSpectrum(ui->glSpectrum);
    ui->glSpectrum->setCenterFrequency(m_settings.m_centerFrequency);
    ui->glSpectrum->setSampleRate(m_settings.m_sampleRate*(1<<m_settings.m_log2Interp));
    ui->spectrumGUI->setBuddies(m_spectrumVis, ui->glSpectrum);

	connect(&(m_deviceUISet->m_deviceAPI->getMasterTimer()), SIGNAL(timeout()), this, SLOT(tick()));
	connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));
	connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
	m_statusTimer.start(500);

	displaySettings();

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
}

TestSinkGui::~TestSinkGui()
{
	delete ui;
}

void TestSinkGui::destroy()
{
	delete this;
}

void TestSinkGui::resetToDefaults()
{
	m_settings.resetToDefaults();
	displaySettings();
	sendSettings();
}

QByteArray TestSinkGui::serialize() const
{
	return m_settings.serialize();
}

bool TestSinkGui::deserialize(const QByteArray& data)
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

bool TestSinkGui::handleMessage(const Message& message)
{
    if (TestSinkOutput::MsgConfigureTestSink::match(message))
    {
        qDebug("TestSinkGui::handleMessage: message: MsgConfigureTestSink");
        const TestSinkOutput::MsgConfigureTestSink& cfg = (TestSinkOutput::MsgConfigureTestSink&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
	else if (TestSinkOutput::MsgStartStop::match(message))
	{
	    TestSinkOutput::MsgStartStop& notif = (TestSinkOutput::MsgStartStop&) message;
        qDebug("TestSinkGui::handleMessage: message: MsgStartStop: %s", notif.getStartStop() ? "start" : "stop");
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

void TestSinkGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {

        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            qDebug("TestSinkGui::handleInputMessages: DSPSignalNotification: SampleRate:%d, CenterFrequency:%llu", notif->getSampleRate(), notif->getCenterFrequency());
            m_sampleRate = notif->getSampleRate();
            m_deviceCenterFrequency = notif->getCenterFrequency();
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

void TestSinkGui::updateSampleRateAndFrequency()
{
    m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate);
    m_deviceUISet->getSpectrum()->setCenterFrequency(m_deviceCenterFrequency);
    ui->deviceRateText->setText(tr("%1k").arg((float)(m_sampleRate*(1<<m_settings.m_log2Interp)) / 1000));
}

void TestSinkGui::displaySettings()
{
    ui->centerFrequency->setValue(m_settings.m_centerFrequency / 1000);
    ui->sampleRate->setValue(m_settings.m_sampleRate);
}

void TestSinkGui::sendSettings()
{
    if (!m_updateTimer.isActive()) {
        m_updateTimer.start(100);
    }
}

void TestSinkGui::updateHardware()
{
    qDebug() << "TestSinkGui::updateHardware";
    TestSinkOutput::MsgConfigureTestSink* message = TestSinkOutput::MsgConfigureTestSink::create(m_settings, m_forceSettings);
    m_sampleSink->getInputMessageQueue()->push(message);
    m_forceSettings = false;
    m_updateTimer.stop();
}

void TestSinkGui::updateStatus()
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

void TestSinkGui::on_centerFrequency_changed(quint64 value)
{
    m_settings.m_centerFrequency = value * 1000;
    ui->glSpectrum->setCenterFrequency(m_settings.m_centerFrequency);
    sendSettings();
}

void TestSinkGui::on_sampleRate_changed(quint64 value)
{
    m_settings.m_sampleRate = value;
    ui->glSpectrum->setSampleRate(m_settings.m_sampleRate*(1<<m_settings.m_log2Interp));
    sendSettings();
}

void TestSinkGui::on_interp_currentIndexChanged(int index)
{
    if (index < 0) {
        return;
    }

    m_settings.m_log2Interp = index;
    ui->glSpectrum->setSampleRate(m_settings.m_sampleRate*(1<<m_settings.m_log2Interp));
    sendSettings();
}

void TestSinkGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        TestSinkOutput::MsgStartStop *message = TestSinkOutput::MsgStartStop::create(checked);
        m_sampleSink->getInputMessageQueue()->push(message);
    }
}

void TestSinkGui::tick()
{
}
