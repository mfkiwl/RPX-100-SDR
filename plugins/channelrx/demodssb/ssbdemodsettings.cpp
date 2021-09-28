///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB.                                  //
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

#include <QColor>

#include "dsp/dspengine.h"
#include "util/simpleserializer.h"
#include "settings/serializable.h"
#include "ssbdemodsettings.h"

#ifdef SDR_RX_SAMPLE_24BIT
const int SSBDemodSettings::m_minPowerThresholdDB = -120;
const float SSBDemodSettings::m_mminPowerThresholdDBf = 120.0f;
#else
const int SSBDemodSettings::m_minPowerThresholdDB = -100;
const float SSBDemodSettings::m_mminPowerThresholdDBf = 100.0f;
#endif

SSBDemodSettings::SSBDemodSettings() :
    m_channelMarker(0),
    m_spectrumGUI(0)
{
    resetToDefaults();
}

void SSBDemodSettings::resetToDefaults()
{
    m_audioBinaural = false;
    m_audioFlipChannels = false;
    m_dsb = false;
    m_audioMute = false;
    m_agc = false;
    m_agcClamping = false;
    m_agcPowerThreshold = -100;
    m_agcThresholdGate = 4;
    m_agcTimeLog2 = 7;
    m_rfBandwidth = 3000;
    m_lowCutoff = 300;
    m_volume = 1.0;
    m_spanLog2 = 3;
    m_inputFrequencyOffset = 0;
    m_rgbColor = QColor(0, 255, 0).rgb();
    m_title = "SSB Demodulator";
    m_audioDeviceName = AudioDeviceManager::m_defaultDeviceName;
    m_streamIndex = 0;
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIDeviceIndex = 0;
    m_reverseAPIChannelIndex = 0;
}

QByteArray SSBDemodSettings::serialize() const
{
    SimpleSerializer s(1);
    s.writeS32(1, m_inputFrequencyOffset);
    s.writeS32(2, m_rfBandwidth / 100.0);
    s.writeS32(3, m_volume * 10.0);

    if (m_spectrumGUI) {
        s.writeBlob(4, m_spectrumGUI->serialize());
    }

    s.writeU32(5, m_rgbColor);
    s.writeS32(6, m_lowCutoff / 100.0);
    s.writeS32(7, m_spanLog2);
    s.writeBool(8, m_audioBinaural);
    s.writeBool(9, m_audioFlipChannels);
    s.writeBool(10, m_dsb);
    s.writeBool(11, m_agc);
    s.writeS32(12, m_agcTimeLog2);
    s.writeS32(13, m_agcPowerThreshold);
    s.writeS32(14, m_agcThresholdGate);
    s.writeBool(15, m_agcClamping);
    s.writeString(16, m_title);
    s.writeString(17, m_audioDeviceName);
    s.writeBool(18, m_useReverseAPI);
    s.writeString(19, m_reverseAPIAddress);
    s.writeU32(20, m_reverseAPIPort);
    s.writeU32(21, m_reverseAPIDeviceIndex);
    s.writeU32(22, m_reverseAPIChannelIndex);
    s.writeS32(23, m_streamIndex);

    return s.final();
}

bool SSBDemodSettings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if(!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if(d.getVersion() == 1)
    {
        QByteArray bytetmp;
        qint32 tmp;
        uint32_t utmp;
        QString strtmp;

        d.readS32(1, &m_inputFrequencyOffset, 0);
        d.readS32(2, &tmp, 30);
        m_rfBandwidth = tmp * 100.0;
        d.readS32(3, &tmp, 30);
        m_volume = tmp / 10.0;

        if (m_spectrumGUI) {
            d.readBlob(4, &bytetmp);
            m_spectrumGUI->deserialize(bytetmp);
        }

        d.readU32(5, &m_rgbColor);
        d.readS32(6, &tmp, 30);
        m_lowCutoff = tmp * 100.0;
        d.readS32(7, &m_spanLog2, 3);
        d.readBool(8, &m_audioBinaural, false);
        d.readBool(9, &m_audioFlipChannels, false);
        d.readBool(10, &m_dsb, false);
        d.readBool(11, &m_agc, false);
        d.readS32(12, &m_agcTimeLog2, 7);
        d.readS32(13, &m_agcPowerThreshold, -40);
        d.readS32(14, &m_agcThresholdGate, 4);
        d.readBool(15, &m_agcClamping, false);
        d.readString(16, &m_title, "SSB Demodulator");
        d.readString(17, &m_audioDeviceName, AudioDeviceManager::m_defaultDeviceName);
        d.readBool(18, &m_useReverseAPI, false);
        d.readString(19, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(20, &utmp, 0);

        if ((utmp > 1023) && (utmp < 65535)) {
            m_reverseAPIPort = utmp;
        } else {
            m_reverseAPIPort = 8888;
        }

        d.readU32(21, &utmp, 0);
        m_reverseAPIDeviceIndex = utmp > 99 ? 99 : utmp;
        d.readU32(22, &utmp, 0);
        m_reverseAPIChannelIndex = utmp > 99 ? 99 : utmp;
        d.readS32(23, &m_streamIndex, 0);

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}
