///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Edouard Griffiths, F4EXB                                   //
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

#ifndef INCLUDE_BLADERFOUTPUTTHREAD_H
#define INCLUDE_BLADERFOUTPUTTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <libbladeRF.h>
#include "dsp/interpolators.h"

#define BLADERFOUTPUT_BLOCKSIZE (1<<16)

class SampleSourceFifo;

class Bladerf1OutputThread : public QThread {
	Q_OBJECT

public:
	Bladerf1OutputThread(struct bladerf* dev, SampleSourceFifo* sampleFifo, QObject* parent = NULL);
	~Bladerf1OutputThread();

	void startWork();
	void stopWork();
	void setLog2Interpolation(unsigned int log2_interp);
	bool isRunning() const { return m_running; }

private:
	QMutex m_startWaitMutex;
	QWaitCondition m_startWaiter;
	bool m_running;

	struct bladerf* m_dev;
	qint16 m_buf[2*BLADERFOUTPUT_BLOCKSIZE];
    SampleSourceFifo* m_sampleFifo;

	unsigned int m_log2Interp;

	Interpolators<qint16, SDR_TX_SAMP_SZ, 12> m_interpolators;

	void run();
	void callback(qint16* buf, qint32 len);
    void callbackPart(qint16* buf, SampleVector& data, unsigned int iBegin, unsigned int iEnd);
};

#endif // INCLUDE_BLADERFOUTPUTTHREAD_H
