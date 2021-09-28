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

#ifndef PLUGINS_CHANNELRX_DEMODDSD_DSDDEMODSETTINGS_H_
#define PLUGINS_CHANNELRX_DEMODDSD_DSDDEMODSETTINGS_H_

#include <QByteArray>

class Serializable;

struct DSDDemodSettings
{
    qint64 m_inputFrequencyOffset;
    Real  m_rfBandwidth;
    Real  m_fmDeviation;
    Real  m_demodGain;
    Real  m_volume;
    int  m_baudRate;
    int  m_squelchGate;
    Real m_squelch;
    bool m_audioMute;
    bool m_enableCosineFiltering;
    bool m_syncOrConstellation;
    bool m_slot1On;
    bool m_slot2On;
    bool m_tdmaStereo;
    bool m_pllLock;
    quint32 m_rgbColor;
    QString m_title;
    bool m_highPassFilter;
    int m_traceLengthMutliplier; // x 50ms
    int m_traceStroke; // [0..255]
    int m_traceDecay; // [0..255]
    QString m_audioDeviceName;
    int m_streamIndex; //!< MIMO channel. Not relevant when connected to SI (single Rx).
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;
    uint16_t m_reverseAPIChannelIndex;

    Serializable *m_channelMarker;
    Serializable *m_scopeGUI;

    DSDDemodSettings();
    void resetToDefaults();
    void setChannelMarker(Serializable *channelMarker) { m_channelMarker = channelMarker; }
    void setScopeGUI(Serializable *scopeGUI) { m_scopeGUI = scopeGUI; }
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
};


#endif /* PLUGINS_CHANNELRX_DEMODDSD_DSDDEMODSETTINGS_H_ */
