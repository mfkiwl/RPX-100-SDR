///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
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

#ifndef _TESTSOURCE_TESTSOURCEWORKER_H_
#define _TESTSOURCE_TESTSOURCEWORKER_H_

#include <map>

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include <QDebug>

#include "dsp/samplesinkfifo.h"
#include "dsp/decimators.h"
#include "dsp/ncof.h"
#include "util/message.h"
#include "util/messagequeue.h"

#include "testsourcesettings.h"

#define TESTSOURCE_THROTTLE_MS 50

class TestSourceWorker : public QObject {
	Q_OBJECT

public:
	TestSourceWorker(SampleSinkFifo* sampleFifo, QObject* parent = 0);
	~TestSourceWorker();

	void startWork();
	void stopWork();
	void setSamplerate(int samplerate);
    void setLog2Decimation(unsigned int log2_decim);
    void setFcPos(int fcPos);
	void setBitSize(uint32_t bitSizeIndex);
    void setAmplitudeBits(int32_t amplitudeBits);
    void setDCFactor(float iFactor);
    void setIFactor(float iFactor);
    void setQFactor(float qFactor);
    void setPhaseImbalance(float phaseImbalance);
    void setFrequencyShift(int shift);
    void setToneFrequency(int toneFrequency);
    void setModulation(TestSourceSettings::Modulation modulation);
    void setAMModulation(float amModulation);
    void setFMDeviation(float deviation);
    void setPattern0();
    void setPattern1();
    void setPattern2();

private:
	volatile bool m_running;

	qint16  *m_buf;
    quint32 m_bufsize;
    quint32 m_chunksize;
	SampleVector m_convertBuffer;
	SampleSinkFifo* m_sampleFifo;
	NCOF m_nco;
    NCOF m_toneNco;
	int m_frequencyShift;
	int m_toneFrequency;
	TestSourceSettings::Modulation m_modulation;
	float m_amModulation;
	float m_fmDeviationUnit;
	float m_fmPhasor;
    uint32_t m_pulseWidth; //!< pulse width in number of samples
    uint32_t m_pulseSampleCount;
    uint32_t m_pulsePatternCount;
    uint32_t m_pulsePatternCycle;
    uint32_t m_pulsePatternPlaces;

	int m_samplerate;
    unsigned int m_log2Decim;
    int m_fcPos;
	uint32_t m_bitSizeIndex;
	uint32_t m_bitShift;
    int32_t m_amplitudeBits;
    float m_dcBias;
    float m_iBias;
    float m_qBias;
    float m_phaseImbalance;
    int32_t m_amplitudeBitsDC;
    int32_t m_amplitudeBitsI;
    int32_t m_amplitudeBitsQ;

    uint64_t m_frequency;
    int m_fcPosShift;

    int m_throttlems;
    QTimer m_timer;
    QElapsedTimer m_elapsedTimer;
    bool m_throttleToggle;
    QMutex m_mutex;

    MessageQueue m_inputMessageQueue;

	Decimators<qint32, qint16, SDR_RX_SAMP_SZ, 8, true> m_decimators_8;
    Decimators<qint32, qint16, SDR_RX_SAMP_SZ, 12, true> m_decimators_12;
    Decimators<qint32, qint16, SDR_RX_SAMP_SZ, 16, true> m_decimators_16;

    std::map<int, int> m_timerHistogram;
    uint32_t m_histoCounter;

	void callback(const qint16* buf, qint32 len);
	void setBuffers(quint32 chunksize);
    void generate(quint32 chunksize);
    void pullAF(Real& afSample);

	//  Decimate according to specified log2 (ex: log2=4 => decim=16)
	inline void convert_8(SampleVector::iterator* it, const qint16* buf, qint32 len)
	{
	    if (m_log2Decim == 0) {
	        m_decimators_8.decimate1(it, buf, len);
	    } else {
	        if (m_fcPos == 0) { // Infradyne
	            switch (m_log2Decim) {
	            case 1:
	                m_decimators_8.decimate2_inf(it, buf, len);
	                break;
	            case 2:
	                m_decimators_8.decimate4_inf(it, buf, len);
	                break;
	            case 3:
	                m_decimators_8.decimate8_inf(it, buf, len);
	                break;
	            case 4:
	                m_decimators_8.decimate16_inf(it, buf, len);
	                break;
	            case 5:
	                m_decimators_8.decimate32_inf(it, buf, len);
	                break;
                case 6:
                    m_decimators_8.decimate64_inf(it, buf, len);
                    break;
	            default:
	                break;
	            }
	        } else if (m_fcPos == 1)  {// Supradyne
	            switch (m_log2Decim) {
	            case 1:
	                m_decimators_8.decimate2_sup(it, buf, len);
	                break;
	            case 2:
	                m_decimators_8.decimate4_sup(it, buf, len);
	                break;
	            case 3:
	                m_decimators_8.decimate8_sup(it, buf, len);
	                break;
	            case 4:
	                m_decimators_8.decimate16_sup(it, buf, len);
	                break;
	            case 5:
	                m_decimators_8.decimate32_sup(it, buf, len);
	                break;
                case 6:
                    m_decimators_8.decimate64_sup(it, buf, len);
                    break;
	            default:
	                break;
	            }
	        } else { // Centered
	            switch (m_log2Decim) {
	            case 1:
	                m_decimators_8.decimate2_cen(it, buf, len);
	                break;
	            case 2:
	                m_decimators_8.decimate4_cen(it, buf, len);
	                break;
	            case 3:
	                m_decimators_8.decimate8_cen(it, buf, len);
	                break;
	            case 4:
	                m_decimators_8.decimate16_cen(it, buf, len);
	                break;
	            case 5:
	                m_decimators_8.decimate32_cen(it, buf, len);
	                break;
                case 6:
                    m_decimators_8.decimate64_cen(it, buf, len);
                    break;
	            default:
	                break;
	            }
	        }
	    }
	}

	void convert_12(SampleVector::iterator* it, const qint16* buf, qint32 len)
    {
        if (m_log2Decim == 0) {
            m_decimators_12.decimate1(it, buf, len);
        } else {
            if (m_fcPos == 0) { // Infradyne
                switch (m_log2Decim) {
                case 1:
                    m_decimators_12.decimate2_inf(it, buf, len);
                    break;
                case 2:
                    m_decimators_12.decimate4_inf(it, buf, len);
                    break;
                case 3:
                    m_decimators_12.decimate8_inf(it, buf, len);
                    break;
                case 4:
                    m_decimators_12.decimate16_inf(it, buf, len);
                    break;
                case 5:
                    m_decimators_12.decimate32_inf(it, buf, len);
                    break;
                case 6:
                    m_decimators_12.decimate64_inf(it, buf, len);
                    break;
                default:
                    break;
                }
            } else if (m_fcPos == 1)  {// Supradyne
                switch (m_log2Decim) {
                case 1:
                    m_decimators_12.decimate2_sup(it, buf, len);
                    break;
                case 2:
                    m_decimators_12.decimate4_sup(it, buf, len);
                    break;
                case 3:
                    m_decimators_12.decimate8_sup(it, buf, len);
                    break;
                case 4:
                    m_decimators_12.decimate16_sup(it, buf, len);
                    break;
                case 5:
                    m_decimators_12.decimate32_sup(it, buf, len);
                    break;
                case 6:
                    m_decimators_12.decimate64_sup(it, buf, len);
                    break;
                default:
                    break;
                }
            } else { // Centered
                switch (m_log2Decim) {
                case 1:
                    m_decimators_12.decimate2_cen(it, buf, len);
                    break;
                case 2:
                    m_decimators_12.decimate4_cen(it, buf, len);
                    break;
                case 3:
                    m_decimators_12.decimate8_cen(it, buf, len);
                    break;
                case 4:
                    m_decimators_12.decimate16_cen(it, buf, len);
                    break;
                case 5:
                    m_decimators_12.decimate32_cen(it, buf, len);
                    break;
                case 6:
                    m_decimators_12.decimate64_cen(it, buf, len);
                    break;
                default:
                    break;
                }
            }
        }
    }

	void convert_16(SampleVector::iterator* it, const qint16* buf, qint32 len)
    {
        if (m_log2Decim == 0) {
            m_decimators_16.decimate1(it, buf, len);
        } else {
            if (m_fcPos == 0) { // Infradyne
                switch (m_log2Decim) {
                case 1:
                    m_decimators_16.decimate2_inf(it, buf, len);
                    break;
                case 2:
                    m_decimators_16.decimate4_inf(it, buf, len);
                    break;
                case 3:
                    m_decimators_16.decimate8_inf(it, buf, len);
                    break;
                case 4:
                    m_decimators_16.decimate16_inf(it, buf, len);
                    break;
                case 5:
                    m_decimators_16.decimate32_inf(it, buf, len);
                    break;
                case 6:
                    m_decimators_16.decimate64_inf(it, buf, len);
                    break;
                default:
                    break;
                }
            } else if (m_fcPos == 1)  {// Supradyne
                switch (m_log2Decim) {
                case 1:
                    m_decimators_16.decimate2_sup(it, buf, len);
                    break;
                case 2:
                    m_decimators_16.decimate4_sup(it, buf, len);
                    break;
                case 3:
                    m_decimators_16.decimate8_sup(it, buf, len);
                    break;
                case 4:
                    m_decimators_16.decimate16_sup(it, buf, len);
                    break;
                case 5:
                    m_decimators_16.decimate32_sup(it, buf, len);
                    break;
                case 6:
                    m_decimators_16.decimate64_sup(it, buf, len);
                    break;
                default:
                    break;
                }
            } else { // Centered
                switch (m_log2Decim) {
                case 1:
                    m_decimators_16.decimate2_cen(it, buf, len);
                    break;
                case 2:
                    m_decimators_16.decimate4_cen(it, buf, len);
                    break;
                case 3:
                    m_decimators_16.decimate8_cen(it, buf, len);
                    break;
                case 4:
                    m_decimators_16.decimate16_cen(it, buf, len);
                    break;
                case 5:
                    m_decimators_16.decimate32_cen(it, buf, len);
                    break;
                case 6:
                    m_decimators_16.decimate64_cen(it, buf, len);
                    break;
                default:
                    break;
                }
            }
        }
    }


private slots:
    void tick();
    void handleInputMessages();
};

#endif // _TESTSOURCE_TESTSOURCEWORKER_H_
