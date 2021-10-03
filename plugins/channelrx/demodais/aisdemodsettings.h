///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Bernhard Isemann, oe3bia.                                  //
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
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

#ifndef INCLUDE_AISDEMODSETTINGS_H
#define INCLUDE_AISDEMODSETTINGS_H

#include <QByteArray>
#include <QString>

#include "dsp/dsptypes.h"

class Serializable;

// Number of columns in the tables
#define AISDEMOD_MESSAGE_COLUMNS 7

struct AISDemodSettings
{
    qint32 m_baud;
    qint32 m_inputFrequencyOffset;
    Real m_rfBandwidth;
    Real m_fmDeviation;
    Real m_correlationThreshold;
    QString m_filterMMSI;
    bool m_udpEnabled;
    QString m_udpAddress;
    uint16_t m_udpPort;
    enum UDPFormat {
        Binary,
        NMEA
    } m_udpFormat;
    int m_scopeCh1;
    int m_scopeCh2;

    quint32 m_rgbColor;
    QString m_title;
    Serializable *m_channelMarker;
    int m_streamIndex; //!< MIMO channel. Not relevant when connected to SI (single Rx).
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;
    uint16_t m_reverseAPIChannelIndex;
    Serializable *m_scopeGUI;

    int m_messageColumnIndexes[AISDEMOD_MESSAGE_COLUMNS];//!< How the columns are ordered in the table
    int m_messageColumnSizes[AISDEMOD_MESSAGE_COLUMNS];  //!< Size of the columns in the table

    static const int AISDEMOD_CHANNEL_SAMPLE_RATE = 57600; //!< 6x 9600 baud rate (use even multiple so Gausian filter has odd number of taps)

    AISDemodSettings();
    void resetToDefaults();
    void setChannelMarker(Serializable *channelMarker) { m_channelMarker = channelMarker; }
    void setScopeGUI(Serializable *scopeGUI) { m_scopeGUI = scopeGUI; }
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
};

#endif /* INCLUDE_AISDEMODSETTINGS_H */
