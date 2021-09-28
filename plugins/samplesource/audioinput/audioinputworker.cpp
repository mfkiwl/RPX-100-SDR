///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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
#include <stdio.h>
#include <errno.h>

#include "dsp/samplesinkfifo.h"
#include "audio/audiofifo.h"

#include "audioinputworker.h"

AudioInputWorker::AudioInputWorker(SampleSinkFifo* sampleFifo, AudioFifo *fifo, QObject* parent) :
    QObject(parent),
    m_fifo(fifo),
    m_running(false),
    m_log2Decim(0),
    m_iqMapping(AudioInputSettings::IQMapping::L),
    m_convertBuffer(m_convBufSamples),
    m_sampleFifo(sampleFifo),
    m_quNCOPhase(0)
{
}

AudioInputWorker::~AudioInputWorker()
{
}

void AudioInputWorker::startWork()
{
    connect(m_fifo, SIGNAL(dataReady()), this, SLOT(handleAudio()));
    m_running = true;
}

void AudioInputWorker::stopWork()
{
    disconnect(m_fifo, SIGNAL(dataReady()), this, SLOT(handleAudio()));
    m_running = false;
}

void AudioInputWorker::workIQ(unsigned int nbRead)
{
    // Map between left and right audio channels and IQ channels
    if ((m_iqMapping == AudioInputSettings::IQMapping::L) || // mono
        (m_iqMapping == AudioInputSettings::IQMapping::R))
    {
        for (uint32_t i = 0; i < nbRead; i++)
        {
            qint16 r = m_buf[i*2 + (m_iqMapping == AudioInputSettings::IQMapping::R ? 1 : 0)]; // real sample

            if (m_quNCOPhase == 0) // 0
            {
                m_buf[i*2]   = r;  // 1
                m_buf[i*2+1] = 0;  // 0
                m_quNCOPhase = 1;  // next phase
            }
            else if (m_quNCOPhase == 1) // -pi/2
            {
                m_buf[i*2]   = 0;  // 0
                m_buf[i*2+1] = -r; // -1
                m_quNCOPhase = 2;  // next phase
            }
            else if (m_quNCOPhase == 2) // pi or -pi
            {
                m_buf[i*2]   = -r; // -1
                m_buf[i*2+1] = 0;  // 0
                m_quNCOPhase = 3;  // next phase
            }
            else if (m_quNCOPhase == 3) // pi/2
            {
                m_buf[i*2]   = 0;  // 0
                m_buf[i*2+1] = r;  // 1
                m_quNCOPhase = 0;  // next phase
            }
        }
    }
    else if (m_iqMapping == AudioInputSettings::IQMapping::LR) // stereo - reverse
    {
        for (uint32_t i = 0; i < nbRead; i++)
        {
            qint16 t = m_buf[i*2];
            m_buf[i*2] = m_buf[i*2+1];
            m_buf[i*2+1] = t;
        }
    }

    decimate(m_buf, nbRead);
}

void AudioInputWorker::decimate(qint16 *buf, unsigned int nbRead)
{
    SampleVector::iterator it = m_convertBuffer.begin();

    switch (m_log2Decim)
    {
    case 0:
        m_decimatorsIQ.decimate1(&it, buf, 2*nbRead);
        break;
    case 1:
        m_decimatorsIQ.decimate2_cen(&it, buf, 2*nbRead);
        break;
    case 2:
        m_decimatorsIQ.decimate4_cen(&it, buf, 2*nbRead);
        break;
    case 3:
        m_decimatorsIQ.decimate8_cen(&it, buf, 2*nbRead);
        break;
    case 4:
        m_decimatorsIQ.decimate16_cen(&it, buf, 2*nbRead);
        break;
    case 5:
        m_decimatorsIQ.decimate32_cen(&it, buf, 2*nbRead);
        break;
    case 6:
        m_decimatorsIQ.decimate64_cen(&it, buf, 2*nbRead);
        break;
    default:
        break;
    }

    m_sampleFifo->write(m_convertBuffer.begin(), it);
}

void AudioInputWorker::handleAudio()
{
    uint32_t nbRead;

    while ((nbRead = m_fifo->read((unsigned char *) m_buf, m_convBufSamples)) != 0) {
        workIQ(nbRead);
    }
}
