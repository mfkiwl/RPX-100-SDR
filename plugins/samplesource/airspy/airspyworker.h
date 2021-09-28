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

#ifndef INCLUDE_AIRSPYWORKER_H
#define INCLUDE_AIRSPYWORKER_H

#include <QObject>
#include <libairspy/airspy.h>

#include "dsp/samplesinkfifo.h"
#include "dsp/decimators.h"

#define AIRSPY_BLOCKSIZE (1<<17)

class AirspyWorker : public QObject {
	Q_OBJECT

public:
	AirspyWorker(struct airspy_device* dev, SampleSinkFifo* sampleFifo, QObject* parent = NULL);
	~AirspyWorker();

	bool startWork();
	void stopWork();
	void setSamplerate(uint32_t samplerate);
	void setLog2Decimation(unsigned int log2_decim);
	void setFcPos(int fcPos);
    void setIQOrder(bool iqOrder) { m_iqOrder = iqOrder; }

private:
	bool m_running;

	struct airspy_device* m_dev;
	qint16 m_buf[2*AIRSPY_BLOCKSIZE];
	SampleVector m_convertBuffer;
	SampleSinkFifo* m_sampleFifo;

	int m_samplerate;
	unsigned int m_log2Decim;
	int m_fcPos;
    bool m_iqOrder;

	Decimators<qint32, qint16, SDR_RX_SAMP_SZ, 12, true> m_decimatorsIQ;
	Decimators<qint32, qint16, SDR_RX_SAMP_SZ, 12, false> m_decimatorsQI;

	void callbackIQ(const qint16* buf, qint32 len);
	void callbackQI(const qint16* buf, qint32 len);
	static int rx_callback(airspy_transfer_t* transfer);
};

#endif // INCLUDE_AIRSPYWORKER_H
