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

#include <QColor>

#include "dsp/dspengine.h"
#include "util/simpleserializer.h"
#include "settings/serializable.h"
#include "udpsinksettings.h"

UDPSinkSettings::UDPSinkSettings() :
    m_channelMarker(0),
    m_spectrumGUI(0)
{
    resetToDefaults();
}

void UDPSinkSettings::resetToDefaults()
{
    m_outputSampleRate = 48000;
    m_sampleFormat = FormatIQ16;
    m_inputFrequencyOffset = 0;
    m_rfBandwidth = 12500;
    m_fmDeviation = 2500;
    m_channelMute = false;
    m_gain = 1.0;
    m_squelchdB = -60;
    m_squelchGate = 0.0;
    m_squelchEnabled = true;
    m_agc = false;
    m_audioActive = false;
    m_audioStereo = false;
    m_volume = 20;
    m_streamIndex = 0;
    m_udpAddress = "127.0.0.1";
    m_udpPort = 9998;
    m_audioPort = 9997;
    m_rgbColor = QColor(225, 25, 99).rgb();
    m_title = "UDP Sample Sink";
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIDeviceIndex = 0;
    m_reverseAPIChannelIndex = 0;
}

QByteArray UDPSinkSettings::serialize() const
{
    SimpleSerializer s(1);
    s.writeS32(2, m_inputFrequencyOffset);
    s.writeS32(3, (int) m_sampleFormat);
    s.writeReal(4, m_outputSampleRate);
    s.writeReal(5, m_rfBandwidth);

    if (m_channelMarker) {
        s.writeBlob(6, m_channelMarker->serialize());
    }

    if (m_spectrumGUI) {
        s.writeBlob(7, m_spectrumGUI->serialize());
    }

    s.writeS32(8, m_gain*10.0);
    s.writeU32(9, m_rgbColor);
    s.writeBool(11, m_audioActive);
    s.writeS32(12, m_volume);
    s.writeBool(14, m_audioStereo);
    s.writeS32(15, m_fmDeviation);
    s.writeS32(16, m_squelchdB);
    s.writeS32(17, m_squelchGate);
    s.writeBool(18, m_agc);
    s.writeString(19, m_title);
    s.writeString(20, m_udpAddress);
    s.writeU32(21, m_udpPort);
    s.writeU32(22, m_audioPort);
    s.writeBool(23, m_useReverseAPI);
    s.writeString(24, m_reverseAPIAddress);
    s.writeU32(25, m_reverseAPIPort);
    s.writeU32(26, m_reverseAPIDeviceIndex);
    s.writeU32(27, m_reverseAPIChannelIndex);
    s.writeS32(28, m_streamIndex);

    return s.final();

}

bool UDPSinkSettings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if (!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if (d.getVersion() == 1)
    {
        QByteArray bytetmp;
        QString strtmp;
        int32_t s32tmp;
        quint32 u32tmp;

        if (m_channelMarker) {
            d.readBlob(6, &bytetmp);
            m_channelMarker->deserialize(bytetmp);
        }

        d.readS32(2, &s32tmp, 0);
        m_inputFrequencyOffset = s32tmp;

        d.readS32(3, &s32tmp, FormatIQ16);

        if ((s32tmp >= 0) && (s32tmp < (int) FormatNone)) {
            m_sampleFormat = (SampleFormat) s32tmp;
        } else {
            m_sampleFormat = FormatIQ16;
        }

        d.readReal(4, &m_outputSampleRate, 48000.0);
        d.readReal(5, &m_rfBandwidth, 32000.0);

        if (m_spectrumGUI) {
            d.readBlob(7, &bytetmp);
            m_spectrumGUI->deserialize(bytetmp);
        }

        d.readS32(8, &s32tmp, 10);
        m_gain = s32tmp / 10.0;
        d.readU32(9, &m_rgbColor);
        d.readBool(11, &m_audioActive, false);
        d.readS32(12, &m_volume, 20);
        d.readBool(14, &m_audioStereo, false);
        d.readS32(15, &m_fmDeviation, 2500);
        d.readS32(16, &m_squelchdB, -60);
        d.readS32(17, &m_squelchGate, 5);
        d.readBool(18, &m_agc, false);
        d.readString(19, &m_title, "UDP Sample Source");
        d.readString(20, &m_udpAddress, "127.0.0.1");

        d.readU32(21, &u32tmp, 9998);

        if ((u32tmp > 1024) & (u32tmp < 65538)) {
            m_udpPort = u32tmp;
        } else {
            m_udpPort = 9998;
        }

        d.readU32(22, &u32tmp, 9997);

        if ((u32tmp > 1024) & (u32tmp < 65538)) {
            m_audioPort = u32tmp;
        } else {
            m_audioPort = 9997;
        }

        d.readBool(23, &m_useReverseAPI, false);
        d.readString(24, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(25, &u32tmp, 0);

        if ((u32tmp > 1023) && (u32tmp < 65535)) {
            m_reverseAPIPort = u32tmp;
        } else {
            m_reverseAPIPort = 8888;
        }

        d.readU32(26, &u32tmp, 0);
        m_reverseAPIDeviceIndex = u32tmp > 99 ? 99 : u32tmp;
        d.readU32(27, &u32tmp, 0);
        m_reverseAPIChannelIndex = u32tmp > 99 ? 99 : u32tmp;
        d.readS32(28, &m_streamIndex, 0);

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

