///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
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

#include "udpsinkfec.h"

#include <QThread>
#include <QDebug>

#include <boost/crc.hpp>
#include <boost/cstdint.hpp>

#include "util/timeutil.h"

#include "remoteoutputsender.h"

UDPSinkFEC::UDPSinkFEC() :
    m_sampleRate(48000),
    m_nbSamples(0),
    m_nbBlocksFEC(0),
    m_txDelayRatio(0.0),
    m_txDelay(0),
    m_dataBlock(nullptr),
    m_txBlockIndex(0),
    m_txBlocksIndex(0),
    m_frameCount(0),
    m_sampleIndex(0),
    m_remoteOutputSender(nullptr),
    m_senderThread(nullptr),
    m_remoteAddress("127.0.0.1"),
    m_remotePort(9090)
{
    memset((char *) &m_superBlock, 0, sizeof(RemoteSuperBlock));
    m_currentMetaFEC.init();

    m_senderThread = new QThread(this);
    m_remoteOutputSender = new RemoteOutputSender();
    m_remoteOutputSender->moveToThread(m_senderThread);
}

UDPSinkFEC::~UDPSinkFEC()
{
    delete m_remoteOutputSender;
    delete m_senderThread;
}

void UDPSinkFEC::startSender()
{
    qDebug("UDPSinkFEC::startSender");
    m_remoteOutputSender->setDestination(m_remoteAddress, m_remotePort);
    m_senderThread->start();
}

void UDPSinkFEC::stopSender()
{
    qDebug("UDPSinkFEC::stopSender");
	m_senderThread->exit();
	m_senderThread->wait();
}

void UDPSinkFEC::setTxDelay(float txDelayRatio)
{
    // delay is calculated from the fraction of the nominal UDP block process time
    // frame size: 127 * (126 or 63 samples depending on I or Q sample bytes of 2 or 4 bytes respectively)
    // divided by sample rate gives the frame process time
    // divided by the number of actual blocks including FEC blocks gives the block (i.e. UDP block) process time
    m_txDelayRatio = txDelayRatio;
    int samplesPerBlock = RemoteNbBytesPerBlock / sizeof(Sample);
    double delay = m_sampleRate == 0 ? 1.0 : (127*samplesPerBlock*txDelayRatio) / m_sampleRate;
    delay /= 128 + m_nbBlocksFEC;
    m_txDelay = delay * 1e6;
    qDebug() << "UDPSinkFEC::setTxDelay:"
        << "txDelay:" << txDelayRatio
        << "m_txDelay:" << m_txDelay << " us"
        << "m_sampleRate:" << m_sampleRate;
}

void UDPSinkFEC::setNbBlocksFEC(uint32_t nbBlocksFEC)
{
    qDebug() << "UDPSinkFEC::setNbBlocksFEC: nbBlocksFEC: " << nbBlocksFEC;
    m_nbBlocksFEC = nbBlocksFEC;
    setTxDelay(m_txDelayRatio);
}

void UDPSinkFEC::setSampleRate(uint32_t sampleRate)
{
    qDebug() << "UDPSinkFEC::setSampleRate: sampleRate: " << sampleRate;
    m_sampleRate = sampleRate;
    setTxDelay(m_txDelayRatio);
}

void UDPSinkFEC::setRemoteAddress(const QString& address, uint16_t port)
{
    qDebug() << "UDPSinkFEC::setRemoteAddress: address: " << address << " port: " << port;
    m_remoteAddress = address;
    m_remotePort = port;
    m_remoteOutputSender->setDestination(m_remoteAddress, m_remotePort);
}

void UDPSinkFEC::write(const SampleVector::iterator& begin, uint32_t sampleChunkSize)
{
    const SampleVector::iterator end = begin + sampleChunkSize;

    SampleVector::const_iterator it = begin;

    while (it != end)
    {
        int inSamplesIndex = it - begin;
        int inRemainingSamples = end - it;

        if (m_txBlockIndex == 0)
        {
            RemoteMetaDataFEC metaData;
            uint64_t nowus = TimeUtil::nowus();

            metaData.m_centerFrequency = 0; // frequency not set by stream
            metaData.m_sampleRate = m_sampleRate;
            metaData.m_sampleBytes = (SDR_RX_SAMP_SZ <= 16 ? 2 : 4);
            metaData.m_sampleBits = SDR_RX_SAMP_SZ;
            metaData.m_nbOriginalBlocks = RemoteNbOrginalBlocks;
            metaData.m_nbFECBlocks = m_nbBlocksFEC;
            metaData.m_tv_sec = nowus / 1000000UL;  // tv.tv_sec;
            metaData.m_tv_usec = nowus % 1000000UL; // tv.tv_usec;

            if (!m_dataBlock) { // on the very first cycle there is no data block allocated
                m_dataBlock = m_remoteOutputSender->getDataBlock(); // ask a new block to sender
            }

            boost::crc_32_type crc32;
            crc32.process_bytes(&metaData, sizeof(RemoteMetaDataFEC)-4);
            metaData.m_crc32 = crc32.checksum();
            RemoteSuperBlock& superBlock = m_dataBlock->m_superBlocks[0]; // first block
            superBlock.init();
            superBlock.m_header.m_frameIndex = m_frameCount;
            superBlock.m_header.m_blockIndex = m_txBlockIndex;
            superBlock.m_header.m_sampleBytes = (SDR_RX_SAMP_SZ <= 16 ? 2 : 4);
            superBlock.m_header.m_sampleBits = SDR_RX_SAMP_SZ;

            RemoteMetaDataFEC *destMeta = (RemoteMetaDataFEC *) &superBlock.m_protectedBlock;
            *destMeta = metaData;

            if (!(metaData == m_currentMetaFEC))
            {
                qDebug() << "UDPSinkFEC::write: meta: "
                        << "|" << metaData.m_centerFrequency
                        << ":" << metaData.m_sampleRate
                        << ":" << (int) (metaData.m_sampleBytes & 0xF)
                        << ":" << (int) metaData.m_sampleBits
                        << "|" << (int) metaData.m_nbOriginalBlocks
                        << ":" << (int) metaData.m_nbFECBlocks
                        << "|" << metaData.m_tv_sec
                        << ":" << metaData.m_tv_usec;

                m_currentMetaFEC = metaData;
            }

            m_txBlockIndex = 1; // next Tx block with data
        } // block zero

        // handle different sample sizes...
        int samplesPerBlock = RemoteNbBytesPerBlock / (SDR_RX_SAMP_SZ <= 16 ? 4 : 8); // two I or Q samples
        if (m_sampleIndex + inRemainingSamples < samplesPerBlock) // there is still room in the current super block
        {
            memcpy((void *) &m_superBlock.m_protectedBlock.buf[m_sampleIndex*sizeof(Sample)],
                    (const void *) &(*(begin+inSamplesIndex)),
                    inRemainingSamples * sizeof(Sample));
            m_sampleIndex += inRemainingSamples;
            it = end; // all input samples are consumed
        }
        else // complete super block and initiate the next if not end of frame
        {
            memcpy((void *) &m_superBlock.m_protectedBlock.buf[m_sampleIndex*sizeof(Sample)],
                    (const void *) &(*(begin+inSamplesIndex)),
                    (samplesPerBlock - m_sampleIndex) * sizeof(Sample));
            it += samplesPerBlock - m_sampleIndex;
            m_sampleIndex = 0;

            m_superBlock.m_header.m_frameIndex = m_frameCount;
            m_superBlock.m_header.m_blockIndex = m_txBlockIndex;
            m_superBlock.m_header.m_sampleBytes = (SDR_RX_SAMP_SZ <= 16 ? 2 : 4);
            m_superBlock.m_header.m_sampleBits = SDR_RX_SAMP_SZ;
            m_dataBlock->m_superBlocks[m_txBlockIndex] = m_superBlock;

            if (m_txBlockIndex == RemoteNbOrginalBlocks - 1) // frame complete
            {
                m_dataBlock->m_txControlBlock.m_frameIndex = m_frameCount;
                m_dataBlock->m_txControlBlock.m_processed = false;
                m_dataBlock->m_txControlBlock.m_complete = true;
                m_dataBlock->m_txControlBlock.m_nbBlocksFEC = m_nbBlocksFEC;
                m_dataBlock->m_txControlBlock.m_txDelay = m_txDelay;
                m_dataBlock->m_txControlBlock.m_dataAddress = m_remoteAddress;
                m_dataBlock->m_txControlBlock.m_dataPort = m_remotePort;

                m_dataBlock = m_remoteOutputSender->getDataBlock(); // ask a new block to sender

                m_txBlockIndex = 0;
                m_frameCount++;
            }
            else
            {
                m_txBlockIndex++;
            }
        }
    }
}

