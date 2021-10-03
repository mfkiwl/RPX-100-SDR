///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Bernhard Isemann, oe3bia                                   //
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

#include "bladerf1inputthread.h"

#include <stdio.h>
#include <errno.h>
#include <algorithm>
#include "dsp/samplesinkfifo.h"



Bladerf1InputThread::Bladerf1InputThread(struct bladerf* dev, SampleSinkFifo* sampleFifo, QObject* parent) :
	QThread(parent),
	m_running(false),
	m_dev(dev),
	m_convertBuffer(BLADERF_BLOCKSIZE),
	m_sampleFifo(sampleFifo),
	m_log2Decim(0),
	m_fcPos(0),
    m_iqOrder(true)
{
    std::fill(m_buf, m_buf + 2*BLADERF_BLOCKSIZE, 0);
}

Bladerf1InputThread::~Bladerf1InputThread()
{
	stopWork();
}

void Bladerf1InputThread::startWork()
{
	m_startWaitMutex.lock();
	start();
	while(!m_running)
		m_startWaiter.wait(&m_startWaitMutex, 100);
	m_startWaitMutex.unlock();
}

void Bladerf1InputThread::stopWork()
{
	m_running = false;
	wait();
}

void Bladerf1InputThread::setLog2Decimation(unsigned int log2_decim)
{
	m_log2Decim = log2_decim;
}

void Bladerf1InputThread::setFcPos(int fcPos)
{
	m_fcPos = fcPos;
}

void Bladerf1InputThread::run()
{
	int res;

	m_running = true;
	m_startWaiter.wakeAll();

	while(m_running) {
		if((res = bladerf_sync_rx(m_dev, m_buf, BLADERF_BLOCKSIZE, NULL, 10000)) < 0) {
			qCritical("BladerfThread: sync error: %s", strerror(errno));
			break;
		}

        if (m_iqOrder) {
    		callbackIQ(m_buf, 2 * BLADERF_BLOCKSIZE);
        } else {
            callbackQI(m_buf, 2 * BLADERF_BLOCKSIZE);
        }
	}

	m_running = false;
}

//  Decimate according to specified log2 (ex: log2=4 => decim=16)
void Bladerf1InputThread::callbackIQ(const qint16* buf, qint32 len)
{
	SampleVector::iterator it = m_convertBuffer.begin();

	if (m_log2Decim == 0)
	{
		m_decimatorsIQ.decimate1(&it, buf, len);
	}
	else
	{
		if (m_fcPos == 0) // Infra
		{
			switch (m_log2Decim)
			{
			case 1:
				m_decimatorsIQ.decimate2_inf(&it, buf, len);
				break;
			case 2:
				m_decimatorsIQ.decimate4_inf(&it, buf, len);
				break;
			case 3:
				m_decimatorsIQ.decimate8_inf(&it, buf, len);
				break;
			case 4:
				m_decimatorsIQ.decimate16_inf(&it, buf, len);
				break;
			case 5:
				m_decimatorsIQ.decimate32_inf(&it, buf, len);
				break;
            case 6:
                m_decimatorsIQ.decimate64_inf(&it, buf, len);
                break;
			default:
				break;
			}
		}
		else if (m_fcPos == 1) // Supra
		{
			switch (m_log2Decim)
			{
			case 1:
				m_decimatorsIQ.decimate2_sup(&it, buf, len);
				break;
			case 2:
				m_decimatorsIQ.decimate4_sup(&it, buf, len);
				break;
			case 3:
				m_decimatorsIQ.decimate8_sup(&it, buf, len);
				break;
			case 4:
				m_decimatorsIQ.decimate16_sup(&it, buf, len);
				break;
			case 5:
				m_decimatorsIQ.decimate32_sup(&it, buf, len);
				break;
            case 6:
                m_decimatorsIQ.decimate64_sup(&it, buf, len);
                break;
			default:
				break;
			}
		}
		else if (m_fcPos == 2) // Center
		{
			switch (m_log2Decim)
			{
			case 1:
				m_decimatorsIQ.decimate2_cen(&it, buf, len);
				break;
			case 2:
				m_decimatorsIQ.decimate4_cen(&it, buf, len);
				break;
			case 3:
				m_decimatorsIQ.decimate8_cen(&it, buf, len);
				break;
			case 4:
				m_decimatorsIQ.decimate16_cen(&it, buf, len);
				break;
			case 5:
				m_decimatorsIQ.decimate32_cen(&it, buf, len);
				break;
            case 6:
                m_decimatorsIQ.decimate64_cen(&it, buf, len);
                break;
			default:
				break;
			}
		}
	}


	m_sampleFifo->write(m_convertBuffer.begin(), it);
}

void Bladerf1InputThread::callbackQI(const qint16* buf, qint32 len)
{
	SampleVector::iterator it = m_convertBuffer.begin();

	if (m_log2Decim == 0)
	{
		m_decimatorsQI.decimate1(&it, buf, len);
	}
	else
	{
		if (m_fcPos == 0) // Infra
		{
			switch (m_log2Decim)
			{
			case 1:
				m_decimatorsQI.decimate2_inf(&it, buf, len);
				break;
			case 2:
				m_decimatorsQI.decimate4_inf(&it, buf, len);
				break;
			case 3:
				m_decimatorsQI.decimate8_inf(&it, buf, len);
				break;
			case 4:
				m_decimatorsQI.decimate16_inf(&it, buf, len);
				break;
			case 5:
				m_decimatorsQI.decimate32_inf(&it, buf, len);
				break;
            case 6:
                m_decimatorsQI.decimate64_inf(&it, buf, len);
                break;
			default:
				break;
			}
		}
		else if (m_fcPos == 1) // Supra
		{
			switch (m_log2Decim)
			{
			case 1:
				m_decimatorsQI.decimate2_sup(&it, buf, len);
				break;
			case 2:
				m_decimatorsQI.decimate4_sup(&it, buf, len);
				break;
			case 3:
				m_decimatorsQI.decimate8_sup(&it, buf, len);
				break;
			case 4:
				m_decimatorsQI.decimate16_sup(&it, buf, len);
				break;
			case 5:
				m_decimatorsQI.decimate32_sup(&it, buf, len);
				break;
            case 6:
                m_decimatorsQI.decimate64_sup(&it, buf, len);
                break;
			default:
				break;
			}
		}
		else if (m_fcPos == 2) // Center
		{
			switch (m_log2Decim)
			{
			case 1:
				m_decimatorsQI.decimate2_cen(&it, buf, len);
				break;
			case 2:
				m_decimatorsQI.decimate4_cen(&it, buf, len);
				break;
			case 3:
				m_decimatorsQI.decimate8_cen(&it, buf, len);
				break;
			case 4:
				m_decimatorsQI.decimate16_cen(&it, buf, len);
				break;
			case 5:
				m_decimatorsQI.decimate32_cen(&it, buf, len);
				break;
            case 6:
                m_decimatorsQI.decimate64_cen(&it, buf, len);
                break;
			default:
				break;
			}
		}
	}


	m_sampleFifo->write(m_convertBuffer.begin(), it);
}
