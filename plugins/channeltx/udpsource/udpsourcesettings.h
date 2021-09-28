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

#ifndef PLUGINS_CHANNELTX_UDPSINK_UDPSOURCESETTINGS_H_
#define PLUGINS_CHANNELTX_UDPSINK_UDPSOURCESETTINGS_H_

#include <QByteArray>
#include <QString>
#include <stdint.h>

#include "dsp/dsptypes.h"

class Serializable;

struct UDPSourceSettings
{
    enum SampleFormat {
        FormatSnLE,
        FormatNFM,
        FormatLSB,
        FormatUSB,
        FormatAM,
        FormatNone
    };

    SampleFormat m_sampleFormat;
    Real m_inputSampleRate;
    qint64 m_inputFrequencyOffset;
    Real m_rfBandwidth;
    Real m_lowCutoff;
    int m_fmDeviation;
    Real m_amModFactor;
    bool m_channelMute;
    Real m_gainIn;
    Real m_gainOut;
    Real m_squelch; //!< squared magnitude
    Real m_squelchGate; //!< seconds
    bool m_squelchEnabled;
    bool m_autoRWBalance;
    bool m_stereoInput;
    quint32 m_rgbColor;

    QString m_udpAddress;
    uint16_t m_udpPort;
    QString m_multicastAddress;
    bool m_multicastJoin;

    QString m_title;
    int m_streamIndex;

    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;
    uint16_t m_reverseAPIChannelIndex;

    Serializable *m_channelMarker;
    Serializable *m_spectrumGUI;

    UDPSourceSettings();
    void resetToDefaults();
    void setChannelMarker(Serializable *channelMarker) { m_channelMarker = channelMarker; }
    void setSpectrumGUI(Serializable *spectrumGUI) { m_spectrumGUI = spectrumGUI; }
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
};




#endif /* PLUGINS_CHANNELTX_UDPSINK_UDPSOURCESETTINGS_H_ */
