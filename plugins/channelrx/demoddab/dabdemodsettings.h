///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB.                                  //
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

#ifndef INCLUDE_DABDEMODSETTINGS_H
#define INCLUDE_DABDEMODSETTINGS_H

#include <QByteArray>

class Serializable;

// Number of columns in the table
#define DABDEMOD_COLUMNS 3

struct DABDemodSettings
{
    qint32 m_inputFrequencyOffset;
    Real m_rfBandwidth;
    QString m_filter;
    QString m_program;
    Real m_volume;
    bool m_audioMute;

    quint32 m_rgbColor;
    QString m_title;
    Serializable *m_channelMarker;
    QString m_audioDeviceName;
    int m_streamIndex; //!< MIMO channel. Not relevant when connected to SI (single Rx).
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;
    uint16_t m_reverseAPIChannelIndex;

    int m_columnIndexes[DABDEMOD_COLUMNS];//!< How the columns are ordered in the table
    int m_columnSizes[DABDEMOD_COLUMNS];  //!< Size of the columns in the table

    DABDemodSettings();
    void resetToDefaults();
    void setChannelMarker(Serializable *channelMarker) { m_channelMarker = channelMarker; }
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
};

#endif /* INCLUDE_DABDEMODSETTINGS_H */
