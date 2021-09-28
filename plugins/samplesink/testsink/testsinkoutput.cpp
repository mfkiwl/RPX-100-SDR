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

#include <string.h>
#include <errno.h>
#include <QDebug>

#include "SWGDeviceSettings.h"
#include "SWGDeviceState.h"

#include "util/simpleserializer.h"
#include "dsp/dspcommands.h"
#include "dsp/dspengine.h"
#include "dsp/basebandsamplesink.h"

#include "device/deviceapi.h"

#include "testsinkoutput.h"
#include "testsinkworker.h"

MESSAGE_CLASS_DEFINITION(TestSinkOutput::MsgConfigureTestSink, Message)
MESSAGE_CLASS_DEFINITION(TestSinkOutput::MsgStartStop, Message)

TestSinkOutput::TestSinkOutput(DeviceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
	m_settings(),
    m_spectrumVis(SDR_TX_SCALEF),
	m_testSinkWorker(nullptr),
	m_deviceDescription("TestSink"),
	m_masterTimer(deviceAPI->getMasterTimer())
{
    m_deviceAPI->setNbSinkStreams(1);
}

TestSinkOutput::~TestSinkOutput()
{
	stop();
}

void TestSinkOutput::destroy()
{
    delete this;
}

void TestSinkOutput::init()
{
    applySettings(m_settings, true);
}

bool TestSinkOutput::start()
{
	QMutexLocker mutexLocker(&m_mutex);
	qDebug() << "TestSinkOutput::start";

	m_testSinkWorker = new TestSinkWorker(&m_sampleSourceFifo);
    m_testSinkWorker->moveToThread(&m_testSinkWorkerThread);
    m_testSinkWorker->setSpectrumSink(&m_spectrumVis);
	m_testSinkWorker->setSamplerate(m_settings.m_sampleRate);
	m_testSinkWorker->setLog2Interpolation(m_settings.m_log2Interp);
	m_testSinkWorker->connectTimer(m_masterTimer);
	startWorker();
	mutexLocker.unlock();

	qDebug("TestSinkOutput::start: started");
	return true;
}

void TestSinkOutput::stop()
{
	qDebug() << "TestSinkOutput::stop";
	QMutexLocker mutexLocker(&m_mutex);

	if(m_testSinkWorker != 0)
	{
		stopWorker();
		delete m_testSinkWorker;
		m_testSinkWorker = nullptr;
	}
}

void TestSinkOutput::startWorker()
{
    m_testSinkWorker->startWork();
    m_testSinkWorkerThread.start();
}

void TestSinkOutput::stopWorker()
{
	m_testSinkWorker->stopWork();
	m_testSinkWorkerThread.quit();
	m_testSinkWorkerThread.wait();
}

QByteArray TestSinkOutput::serialize() const
{
    return m_settings.serialize();
}

bool TestSinkOutput::deserialize(const QByteArray& data)
{
    bool success = true;

    if (!m_settings.deserialize(data))
    {
        m_settings.resetToDefaults();
        success = false;
    }

    MsgConfigureTestSink* message = MsgConfigureTestSink::create(m_settings, true);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureTestSink* messageToGUI = MsgConfigureTestSink::create(m_settings, true);
        m_guiMessageQueue->push(messageToGUI);
    }

    return success;
}

const QString& TestSinkOutput::getDeviceDescription() const
{
	return m_deviceDescription;
}

int TestSinkOutput::getSampleRate() const
{
	return m_settings.m_sampleRate;
}

quint64 TestSinkOutput::getCenterFrequency() const
{
	return m_settings.m_centerFrequency;
}

void TestSinkOutput::setCenterFrequency(qint64 centerFrequency)
{
    TestSinkSettings settings = m_settings;
    settings.m_centerFrequency = centerFrequency;

    MsgConfigureTestSink* message = MsgConfigureTestSink::create(settings, false);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgConfigureTestSink* messageToGUI = MsgConfigureTestSink::create(settings, false);
        m_guiMessageQueue->push(messageToGUI);
    }
}

bool TestSinkOutput::handleMessage(const Message& message)
{
    if (MsgStartStop::match(message))
	{
        MsgStartStop& cmd = (MsgStartStop&) message;
        qDebug() << "TestSinkOutput::handleMessage: MsgStartStop: " << (cmd.getStartStop() ? "start" : "stop");

        if (cmd.getStartStop())
        {
            if (m_deviceAPI->initDeviceEngine()) {
                m_deviceAPI->startDeviceEngine();
            }
        }
        else
        {
            m_deviceAPI->stopDeviceEngine();
        }

        return true;
	}
	else if (MsgConfigureTestSink::match(message))
    {
	    qDebug() << "TestSinkOutput::handleMessage: MsgConfigureTestSink";
	    MsgConfigureTestSink& conf = (MsgConfigureTestSink&) message;
        applySettings(conf.getSettings(), conf.getForce());
        return true;
    }
	else
	{
		return false;
	}
}

void TestSinkOutput::applySettings(const TestSinkSettings& settings, bool force)
{
    QMutexLocker mutexLocker(&m_mutex);
    bool forwardChange = false;

    if (force || (m_settings.m_centerFrequency != settings.m_centerFrequency))
    {
        m_settings.m_centerFrequency = settings.m_centerFrequency;
        forwardChange = true;
    }

    if (force || (m_settings.m_sampleRate != settings.m_sampleRate))
    {
        m_settings.m_sampleRate = settings.m_sampleRate;

        if (m_testSinkWorker) {
            m_testSinkWorker->setSamplerate(m_settings.m_sampleRate);
        }

        forwardChange = true;
    }

    if (force || (m_settings.m_log2Interp != settings.m_log2Interp))
    {
        m_settings.m_log2Interp = settings.m_log2Interp;

        if (m_testSinkWorker) {
            m_testSinkWorker->setLog2Interpolation(m_settings.m_log2Interp);
        }

        forwardChange = true;
    }

    if (forwardChange)
    {
        qDebug("TestSinkOutput::applySettings: forward: m_centerFrequency: %llu m_sampleRate: %llu m_log2Interp: %d",
                m_settings.m_centerFrequency,
                m_settings.m_sampleRate,
                m_settings.m_log2Interp);
        DSPSignalNotification *notif = new DSPSignalNotification(m_settings.m_sampleRate, m_settings.m_centerFrequency);
        m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);
    }
}

int TestSinkOutput::webapiRunGet(
        SWGSDRangel::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    return 200;
}

int TestSinkOutput::webapiRun(
        bool run,
        SWGSDRangel::SWGDeviceState& response,
        QString& errorMessage)
{
    (void) errorMessage;
    m_deviceAPI->getDeviceEngineStateStr(*response.getState());
    MsgStartStop *message = MsgStartStop::create(run);
    m_inputMessageQueue.push(message);

    if (m_guiMessageQueue)
    {
        MsgStartStop *messagetoGui = MsgStartStop::create(run);
        m_guiMessageQueue->push(messagetoGui);
    }

    return 200;
}


