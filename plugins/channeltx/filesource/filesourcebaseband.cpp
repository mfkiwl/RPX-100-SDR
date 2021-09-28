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

#include "dsp/upchannelizer.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"

#include "filesourcebaseband.h"

MESSAGE_CLASS_DEFINITION(FileSourceBaseband::MsgConfigureFileSourceBaseband, Message)
MESSAGE_CLASS_DEFINITION(FileSourceBaseband::MsgConfigureFileSourceName, Message)
MESSAGE_CLASS_DEFINITION(FileSourceBaseband::MsgConfigureFileSourceWork, Message)
MESSAGE_CLASS_DEFINITION(FileSourceBaseband::MsgConfigureFileSourceSeek, Message)

FileSourceBaseband::FileSourceBaseband() :
    m_avg(0.0),
    m_peak(0.0),
    m_nbSamples(1),
    m_mutex(QMutex::Recursive)
{
    m_sampleFifo.resize(SampleSourceFifo::getSizePolicy(48000));
    m_channelizer = new UpChannelizer(&m_source);

    qDebug("FileSourceBaseband::FileSourceBaseband");
    QObject::connect(
        &m_sampleFifo,
        &SampleSourceFifo::dataRead,
        this,
        &FileSourceBaseband::handleData,
        Qt::QueuedConnection
    );

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));
}

FileSourceBaseband::~FileSourceBaseband()
{
    delete m_channelizer;
}

void FileSourceBaseband::reset()
{
    QMutexLocker mutexLocker(&m_mutex);
    m_sampleFifo.reset();
}

void FileSourceBaseband::pull(const SampleVector::iterator& begin, unsigned int nbSamples)
{
    unsigned int part1Begin, part1End, part2Begin, part2End;
    m_sampleFifo.read(nbSamples, part1Begin, part1End, part2Begin, part2End);
    SampleVector& data = m_sampleFifo.getData();

    if (part1Begin != part1End)
    {
        std::copy(
            data.begin() + part1Begin,
            data.begin() + part1End,
            begin
        );
    }

    unsigned int shift = part1End - part1Begin;

    if (part2Begin != part2End)
    {
        std::copy(
            data.begin() + part2Begin,
            data.begin() + part2End,
            begin + shift
        );
    }
}

void FileSourceBaseband::handleData()
{
    QMutexLocker mutexLocker(&m_mutex);
    SampleVector& data = m_sampleFifo.getData();
    unsigned int ipart1begin;
    unsigned int ipart1end;
    unsigned int ipart2begin;
    unsigned int ipart2end;

    unsigned int remainder = m_sampleFifo.remainder();

    while ((remainder > 0) && (m_inputMessageQueue.size() == 0))
    {
        m_sampleFifo.write(remainder, ipart1begin, ipart1end, ipart2begin, ipart2end);

        if (ipart1begin != ipart1end) { // first part of FIFO data
            processFifo(data, ipart1begin, ipart1end);
        }

        if (ipart2begin != ipart2end) { // second part of FIFO data (used when block wraps around)
            processFifo(data, ipart2begin, ipart2end);
        }

        remainder = m_sampleFifo.remainder();
    }

    m_source.getMagSqLevels(m_avg, m_peak, m_nbSamples);
}

void FileSourceBaseband::processFifo(SampleVector& data, unsigned int iBegin, unsigned int iEnd)
{
    m_channelizer->prefetch(iEnd - iBegin);
    m_channelizer->pull(data.begin() + iBegin, iEnd - iBegin);
}

void FileSourceBaseband::handleInputMessages()
{
	Message* message;

	while ((message = m_inputMessageQueue.pop()) != nullptr)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}

bool FileSourceBaseband::handleMessage(const Message& cmd)
{
    if (MsgConfigureFileSourceBaseband::match(cmd))
    {
        QMutexLocker mutexLocker(&m_mutex);
        MsgConfigureFileSourceBaseband& cfg = (MsgConfigureFileSourceBaseband&) cmd;
        qDebug() << "FileSourceBaseband::handleMessage: MsgConfigureFileSourceBaseband";

        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else if (DSPSignalNotification::match(cmd))
    {
        QMutexLocker mutexLocker(&m_mutex);
        DSPSignalNotification& notif = (DSPSignalNotification&) cmd;
        qDebug() << "FileSourceBaseband::handleMessage: DSPSignalNotification: basebandSampleRate: " << notif.getSampleRate();
        m_sampleFifo.resize(SampleSourceFifo::getSizePolicy(notif.getSampleRate()));
        m_channelizer->setBasebandSampleRate(notif.getSampleRate());

		return true;
    }
    else if (MsgConfigureFileSourceName::match(cmd))
	{
        QMutexLocker mutexLocker(&m_mutex);
		MsgConfigureFileSourceName& conf = (MsgConfigureFileSourceName&) cmd;
        qDebug() << "FileSourceBaseband::handleMessage: MsgConfigureFileSourceName: " << conf.getFileName();
        m_source.openFileStream(conf.getFileName());

		return true;
	}
    else if (MsgConfigureFileSourceWork::match(cmd))
    {
        QMutexLocker mutexLocker(&m_mutex);
		MsgConfigureFileSourceWork& conf = (MsgConfigureFileSourceWork&) cmd;
        qDebug() << "FileSourceBaseband::handleMessage: MsgConfigureFileSourceWork: " << conf.isWorking();
        m_source.setRunning(conf.isWorking());

		return true;
    }
	else if (MsgConfigureFileSourceSeek::match(cmd))
	{
        QMutexLocker mutexLocker(&m_mutex);
		MsgConfigureFileSourceSeek& conf = (MsgConfigureFileSourceSeek&) cmd;
        m_source.seekFileStream(conf.getMillis());

		return true;
	}
    else
    {
        return false;
    }
}

void FileSourceBaseband::applySettings(const FileSourceSettings& settings, bool force)
{
    qDebug() << "FileSourceBaseband::applySettings:"
        << "m_fileName:" << settings.m_fileName
        << "m_loop:" << settings.m_loop
        << "m_gainDB:" << settings.m_gainDB
        << "m_log2Interp:" << settings.m_log2Interp
        << "m_filterChainHash:" << settings.m_filterChainHash
        << " force: " << force;

    if ((m_settings.m_filterChainHash != settings.m_filterChainHash)
     || (m_settings.m_log2Interp != settings.m_log2Interp) || force)
    {
        m_channelizer->setInterpolation(settings.m_log2Interp, settings.m_filterChainHash);
    }

    m_source.applySettings(settings, force);
    m_settings = settings;
}

int FileSourceBaseband::getChannelSampleRate() const
{
    return m_channelizer->getChannelSampleRate();
}

quint64 FileSourceBaseband::getSamplesCount() const
{
    return m_source.getSamplesCount();
}