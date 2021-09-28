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

#ifndef PLUGINS_CHANNELRX_DEMODSSB_SSBDEMODSETTINGS_H_
#define PLUGINS_CHANNELRX_DEMODSSB_SSBDEMODSETTINGS_H_

#include <QByteArray>

class Serializable;

struct SSBDemodSettings
{
    qint32 m_inputFrequencyOffset;
    Real m_rfBandwidth;
    Real m_lowCutoff;
    Real m_volume;
    int  m_spanLog2;
    bool m_audioBinaural;
    bool m_audioFlipChannels;
    bool m_dsb;
    bool m_audioMute;
    bool m_agc;
    bool m_agcClamping;
    int  m_agcTimeLog2;
    int  m_agcPowerThreshold;
    int  m_agcThresholdGate;
    quint32 m_rgbColor;
    QString m_title;
    QString m_audioDeviceName;
    int m_streamIndex; //!< MIMO channel. Not relevant when connected to SI (single Rx).
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;
    uint16_t m_reverseAPIChannelIndex;

    Serializable *m_channelMarker;
    Serializable *m_spectrumGUI;

    SSBDemodSettings();
    void resetToDefaults();
    void setChannelMarker(Serializable *channelMarker) { m_channelMarker = channelMarker; }
    void setSpectrumGUI(Serializable *spectrumGUI) { m_spectrumGUI = spectrumGUI; }
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);

    static const int m_minPowerThresholdDB;
    static const float m_mminPowerThresholdDBf;
};


#endif /* PLUGINS_CHANNELRX_DEMODSSB_SSBDEMODSETTINGS_H_ */
