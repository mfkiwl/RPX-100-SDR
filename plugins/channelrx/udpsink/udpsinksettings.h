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

#ifndef PLUGINS_CHANNELRX_UDPSRC_UDPSRCSETTINGS_H_
#define PLUGINS_CHANNELRX_UDPSRC_UDPSRCSETTINGS_H_

#include <QByteArray>
#include <QString>
#include <stdint.h>

class Serializable;

struct UDPSinkSettings
{
    enum SampleFormat {
        FormatIQ16,
        FormatIQ24,
        FormatNFM,
        FormatNFMMono,
        FormatLSB,
        FormatUSB,
        FormatLSBMono,
        FormatUSBMono,
        FormatAMMono,
        FormatAMNoDCMono,
        FormatAMBPFMono,
        FormatNone
    };

    float m_outputSampleRate;
    SampleFormat m_sampleFormat;
    int64_t m_inputFrequencyOffset;
    float m_rfBandwidth;
    int m_fmDeviation;
    bool m_channelMute;
    float m_gain;
    int  m_squelchdB;  //!< power dB
    int  m_squelchGate; //!< 100ths seconds
    bool m_squelchEnabled;
    bool m_agc;
    bool m_audioActive;
    bool m_audioStereo;
    int m_volume;
    quint32 m_rgbColor;

    QString m_udpAddress;
    uint16_t m_udpPort;
    uint16_t m_audioPort;

    QString m_title;

    int m_streamIndex; //!< MIMO channel. Not relevant when connected to SI (single Rx).
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;
    uint16_t m_reverseAPIChannelIndex;

    Serializable *m_channelMarker;
    Serializable *m_spectrumGUI;

    UDPSinkSettings();
    void resetToDefaults();
    void setChannelMarker(Serializable *channelMarker) { m_channelMarker = channelMarker; }
    void setSpectrumGUI(Serializable *spectrumGUI) { m_spectrumGUI = spectrumGUI; }
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
};



#endif /* PLUGINS_CHANNELRX_UDPSRC_UDPSRCSETTINGS_H_ */
