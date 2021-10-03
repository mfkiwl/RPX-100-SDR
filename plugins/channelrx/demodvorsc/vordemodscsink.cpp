///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
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

#include <complex.h>

#include "audio/audiooutputdevice.h"
#include "dsp/dspengine.h"
#include "util/db.h"
#include "util/stepfunctions.h"
#include "util/morse.h"
#include "util/units.h"

#include "vordemodscreport.h"
#include "vordemodscsettings.h"
#include "vordemodscsink.h"

VORDemodSCSink::VORDemodSCSink() :
        m_channelFrequencyOffset(0),
        m_channelSampleRate(VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE),
        m_audioSampleRate(48000),
        m_squelchCount(0),
        m_squelchOpen(false),
        m_squelchDelayLine(9600),
        m_magsqSum(0.0f),
        m_magsqPeak(0.0f),
        m_magsqCount(0),
        m_volumeAGC(0.003),
        m_audioFifo(48000),
        m_refPrev(0.0f),
        m_movingAverageIdent(5000),
        m_prevBit(0),
        m_bitTime(0),
        m_varGoertzel(30, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE),
        m_refGoertzel(30, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE)
{
	m_audioBuffer.resize(1<<14);
	m_audioBufferFill = 0;

	m_magsq = 0.0;

	applySettings(m_settings, true);
    applyChannelSettings(m_channelSampleRate, m_channelFrequencyOffset, true);
}

VORDemodSCSink::~VORDemodSCSink()
{
}

void VORDemodSCSink::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end)
{
    Complex ci;

    for (SampleVector::const_iterator it = begin; it != end; ++it)
    {
        Complex c(it->real(), it->imag());
        c *= m_nco.nextIQ();

        if (m_interpolatorDistance < 1.0f) // interpolate
        {
            while (!m_interpolator.interpolate(&m_interpolatorDistanceRemain, c, &ci))
            {
                processOneSample(ci);
                m_interpolatorDistanceRemain += m_interpolatorDistance;
            }
        }
        else // decimate
        {
            if (m_interpolator.decimate(&m_interpolatorDistanceRemain, c, &ci))
            {
                processOneSample(ci);
                m_interpolatorDistanceRemain += m_interpolatorDistance;
            }
        }
    }

    if (m_audioBufferFill > 0)
    {
        uint res = m_audioFifo.write((const quint8*)&m_audioBuffer[0], m_audioBufferFill);

        if (res != m_audioBufferFill) {
            qDebug("VORDemodSCSink::feed: %u/%u tail samples written", res, m_audioBufferFill);
        }

        m_audioBufferFill = 0;
    }
}

void VORDemodSCSink::processOneAudioSample(Complex &ci)
{
    Real re = ci.real() / SDR_RX_SCALEF;
    Real im = ci.imag() / SDR_RX_SCALEF;
    Real magsq = re*re + im*im;
    m_movingAverage(magsq);
    m_magsq = m_movingAverage.asDouble();
    m_magsqSum += magsq;

    if (magsq > m_magsqPeak)
    {
        m_magsqPeak = magsq;
    }

    m_magsqCount++;

    m_squelchDelayLine.write(magsq);

    if (m_magsq < m_squelchLevel)
    {
        if (m_squelchCount > 0) {
            m_squelchCount--;
        }
    }
    else
    {
        if (m_squelchCount < (unsigned int)m_audioSampleRate / 10) {
            m_squelchCount++;
        }
    }

    qint16 sample;

    m_squelchOpen = (m_squelchCount >= (unsigned int)m_audioSampleRate / 20);

    if (m_squelchOpen && !m_settings.m_audioMute)
    {
        Real demod;

        {
            demod = sqrt(m_squelchDelayLine.readBack(m_audioSampleRate/20));
            m_volumeAGC.feed(demod);
            demod = (demod - m_volumeAGC.getValue()) / m_volumeAGC.getValue();
        }

        demod = m_bandpass.filter(demod);

        Real attack = (m_squelchCount - 0.05f * m_audioSampleRate) / (0.05f * m_audioSampleRate);
        sample = demod * StepFunctions::smootherstep(attack) * (m_audioSampleRate/24) * m_settings.m_volume;
    }
    else
    {
        sample = 0;
    }

    m_audioBuffer[m_audioBufferFill].l = sample;
    m_audioBuffer[m_audioBufferFill].r = sample;
    ++m_audioBufferFill;

    if (m_audioBufferFill >= m_audioBuffer.size())
    {
        uint res = m_audioFifo.write((const quint8*)&m_audioBuffer[0], m_audioBufferFill);

        if (res != m_audioBufferFill)
        {
            qDebug("VORDemodSCSink::processOneAudioSample: %u/%u audio samples written", res, m_audioBufferFill);
            m_audioFifo.clear();
        }

        m_audioBufferFill = 0;
    }
}


void VORDemodSCSink::processOneSample(Complex &ci)
{
    Complex ca;

    // Resample as audio
    if (m_audioInterpolatorDistance < 1.0f) // interpolate
    {
        while (!m_audioInterpolator.interpolate(&m_audioInterpolatorDistanceRemain, ci, &ca))
        {
            processOneAudioSample(ca);
            m_audioInterpolatorDistanceRemain += m_audioInterpolatorDistance;
        }
    }
    else // decimate
    {
        if (m_audioInterpolator.decimate(&m_audioInterpolatorDistanceRemain, ci, &ca))
        {
            processOneAudioSample(ca);
            m_audioInterpolatorDistanceRemain += m_audioInterpolatorDistance;
        }
    }

    Real re = ci.real() / SDR_RX_SCALEF;
    Real im = ci.imag() / SDR_RX_SCALEF;
    Real magsq = re*re + im*im;

    // AM Demod
    Real mag = std::sqrt(magsq);

    // Calculate phase of 30Hz variable AM signal
    double varPhase;
    double varMag;
    if (m_varGoertzel.size() == VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE - 1)
    {
        m_varGoertzel.goertzel(mag);
        varPhase = Units::radiansToDegrees(m_varGoertzel.phase());
        varMag = m_varGoertzel.mag();
        m_varGoertzel.reset();
    }
    else
        m_varGoertzel.filter(mag);

    Complex magc(mag, 0.0);

    // Mix reference sub-carrier down to 0Hz
    Complex fm0 = magc;
    fm0 *= m_ncoRef.nextIQ();
    // Filter other signals
    Complex fmfilt = m_lowpassRef.filter(fm0);

    // FM demod
    Real phi = std::arg(std::conj(m_refPrev) * fmfilt);
    m_refPrev = fmfilt;

    // Calculate phase of 30Hz reference FM signal
    if (m_refGoertzel.size() == VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE - 1)
    {
        m_refGoertzel.goertzel(phi);
        float phaseDeg = Units::radiansToDegrees(m_refGoertzel.phase());
        double refMag = m_refGoertzel.mag();
        int groupDelay = (301-1)/2;
        float filterPhaseShift = 360.0*30.0*groupDelay/VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE;
        float shiftedPhase = phaseDeg + filterPhaseShift;

        // Calculate difference in phase, which is the radial
        float phaseDifference = shiftedPhase - varPhase;
        if (phaseDifference < 0.0)
            phaseDifference += 360.0;
        else if (phaseDifference >= 360.0)
            phaseDifference -= 360.0;

        // qDebug() << "Ref phase: " << phaseDeg << " var phase " << varPhase;

        if (getMessageQueueToChannel())
        {
            VORDemodSCReport::MsgReportRadial *msg = VORDemodSCReport::MsgReportRadial::create(phaseDifference, refMag, varMag);
            getMessageQueueToChannel()->push(msg);
        }

        m_refGoertzel.reset();
    }
    else
        m_refGoertzel.filter(phi);

    // Ident demod
    // Remove ident sub-carrier offset
    Complex c1 = magc;
    c1 *= m_ncoIdent.nextIQ();
    // Filter other signals
    Complex c2 = std::abs(m_lowpassIdent.filter(c1));

    // Filter noise with moving average (moving average preserves edges)
    m_movingAverageIdent(c2.real());
    Real mav = m_movingAverageIdent.asFloat();

    // Caclulate noise floor
    if (mav > m_identMaxs[m_binCnt])
        m_identMaxs[m_binCnt] = mav;
    m_binSampleCnt++;
    if (m_binSampleCnt >= m_samplesPerDot10wpm/2)
    {
        // Calc minimum of maximums
        m_identNoise = 1.0f;
        for (int i = 0; i < m_identBins; i++)
        {
            m_identNoise = std::min(m_identNoise, m_identMaxs[i]);
        }
        m_binSampleCnt = 0;
        m_binCnt++;
        if (m_binCnt == m_identBins)
            m_binCnt = 0;
        m_identMaxs[m_binCnt] = 0.0f;

        // Prevent divide by zero
        if (m_identNoise == 0.0f)
            m_identNoise = 1e-20f;
    }

    // CW demod
    int bit = (mav / m_identNoise) >= m_settings.m_identThreshold;
    if ((m_prevBit == 0) && (bit == 1))
    {
        if (m_bitTime > 7*m_samplesPerDot10wpm)
        {
            if (m_ident != "")
            {
                qDebug() << "VORDemodSCSink::processOneSample:" << m_ident << " " << Morse::toString(m_ident);

                if (getMessageQueueToChannel())
                {
                    VORDemodSCReport::MsgReportIdent *msg = VORDemodSCReport::MsgReportIdent::create(m_ident);
                    getMessageQueueToChannel()->push(msg);
                }

                m_ident = "";
            }
        }
        else if (m_bitTime > 2.5*m_samplesPerDot10wpm)
        {
            m_ident.append(" ");
        }
        m_bitTime = 0;
    }
    else if (bit == 1)
    {
        m_bitTime++;
    }
    else if ((m_prevBit == 1) && (bit == 0))
    {
        if (m_bitTime > 2*m_samplesPerDot10wpm)
        {
            m_ident.append("-");
        }
        else if (m_bitTime > 0.2*m_samplesPerDot10wpm)
        {
            m_ident.append(".");
        }
        m_bitTime = 0;
    }
    else
    {
        m_bitTime++;
        if (m_bitTime > 10*m_samplesPerDot7wpm)
        {
            m_ident = m_ident.simplified();
            if (m_ident != "")
            {
                qDebug() << "VORDemodSCSink::processOneSample:" << m_ident << " " << Morse::toString(m_ident);

                if (getMessageQueueToChannel())
                {
                    VORDemodSCReport::MsgReportIdent *msg = VORDemodSCReport::MsgReportIdent::create(m_ident);
                    getMessageQueueToChannel()->push(msg);
                }

                m_ident = "";
            }
            m_bitTime = 0;
        }
    }
    m_prevBit = bit;
}

void VORDemodSCSink::applyChannelSettings(int channelSampleRate, int channelFrequencyOffset, bool force)
{
    qDebug() << "VORDemodSCSink::applyChannelSettings:"
            << " channelSampleRate: " << channelSampleRate
            << " channelFrequencyOffset: " << channelFrequencyOffset;

    if ((m_channelFrequencyOffset != channelFrequencyOffset) ||
        (m_channelSampleRate != channelSampleRate) || force)
    {
        m_nco.setFreq(-channelFrequencyOffset, channelSampleRate);
    }

    if ((m_channelSampleRate != channelSampleRate) || force)
    {
        m_interpolator.create(16, channelSampleRate, VORDemodSCSettings::VORDEMOD_CHANNEL_BANDWIDTH);
        m_interpolatorDistanceRemain = 0;
        m_interpolatorDistance = (Real) channelSampleRate / (Real) VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE;

        m_samplesPerDot7wpm = VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE*60/(50*7);
        m_samplesPerDot10wpm = VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE*60/(50*10);

        m_ncoIdent.setFreq(-1020, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE);  // +-50Hz source offset allowed
        m_ncoRef.setFreq(-9960, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE);
        m_lowpassIdent.create(301, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE, 100.0f);
        m_lowpassRef.create(301, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE, 600.0f); // Max deviation is 480Hz
        m_movingAverageIdent.resize(m_samplesPerDot10wpm/5);  // Needs to be short enough for noise floor calculation

        m_binSampleCnt = 0;
        m_binCnt = 0;
        m_identNoise = 0.0001f;
        for (int i = 0; i < m_identBins; i++)
        {
            m_identMaxs[i] = 0.0f;
        }
    }

    m_channelSampleRate = channelSampleRate;
    m_channelFrequencyOffset = channelFrequencyOffset;
}

void VORDemodSCSink::applySettings(const VORDemodSCSettings& settings, bool force)
{
    qDebug() << "VORDemodSCSink::applySettings:"
            << " m_volume: " << settings.m_volume
            << " m_squelch: " << settings.m_squelch
            << " m_audioMute: " << settings.m_audioMute
            << " m_audioDeviceName: " << settings.m_audioDeviceName
            << " force: " << force;

    if ((m_settings.m_squelch != settings.m_squelch) || force) {
        m_squelchLevel = CalcDb::powerFromdB(settings.m_squelch);
    }

    m_settings = settings;
}

void VORDemodSCSink::applyAudioSampleRate(int sampleRate)
{
    if (sampleRate < 0)
    {
        qWarning("VORDemodSCSink::applyAudioSampleRate: invalid sample rate: %d", sampleRate);
        return;
    }

    qDebug("VORDemodSCSink::applyAudioSampleRate: sampleRate: %d m_channelSampleRate: %d", sampleRate, m_channelSampleRate);

    // (ICAO Annex 10 3.3.6.3) - Optional voice audio is 300Hz to 3kHz
    m_audioInterpolator.create(16, VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE, 3000.0f);
    m_audioInterpolatorDistanceRemain = 0;
    m_audioInterpolatorDistance = (Real) VORDemodSCSettings::VORDEMOD_CHANNEL_SAMPLE_RATE / (Real) sampleRate;
    m_bandpass.create(301, sampleRate, 300.0f, 3000.0f);
    m_audioFifo.setSize(sampleRate);
    m_squelchDelayLine.resize(sampleRate/5);

    m_volumeAGC.resizeNew(sampleRate/10, 0.003f);

    m_audioSampleRate = sampleRate;
}
