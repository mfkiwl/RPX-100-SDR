///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Bernhard Isemann, oe3bia                                   //
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

#ifndef _SDRPLAYV3_SDRPLAYV3SETTINGS_H_
#define _SDRPLAYV3_SDRPLAYV3SETTINGS_H_

#include <stdint.h>
#include <QByteArray>
#include <QString>
#include <QDebug>

struct SDRPlayV3Settings {
    typedef enum {
        FC_POS_INFRA = 0,
        FC_POS_SUPRA,
        FC_POS_CENTER
    } fcPos_t;

    uint64_t m_centerFrequency;
    int32_t  m_LOppmTenths;
    uint32_t m_ifFrequencyIndex;
    uint32_t m_bandwidthIndex;
    uint32_t m_devSampleRate;
    uint32_t m_log2Decim;
    fcPos_t m_fcPos;
    bool m_dcBlock;
    bool m_iqCorrection;
    int  m_lnaIndex;
    bool m_ifAGC;
    int  m_ifGain;
    bool m_amNotch;
    bool m_fmNotch;
    bool m_dabNotch;
    bool m_biasTee;
    int m_tuner;
    int m_antenna;
    bool m_extRef;
    bool     m_useReverseAPI;
    QString  m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;

    SDRPlayV3Settings();
    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);

    void debug(const char *title) const
    {
        qDebug() << QString(title)
                << ": m_centerFrequency: " << m_centerFrequency
                << " m_LOppmTenths: " << m_LOppmTenths
                << " m_ifFrequencyIndex: " << m_ifFrequencyIndex
                << " m_bandwidthIndex: " << m_bandwidthIndex
                << " m_devSampleRate: " << m_devSampleRate
                << " m_log2Decim: " << m_log2Decim
                << " m_fcPos: " << m_fcPos
                << " m_dcBlock: " << m_dcBlock
                << " m_iqCorrection: " << m_iqCorrection
                << " m_lnaIndex: " << m_lnaIndex
                << " m_ifAGC: " << m_ifAGC
                << " m_ifGain: " << m_ifGain
                << " m_amNotch: " << m_amNotch
                << " m_fmNotch: " << m_fmNotch
                << " m_dabNotch: " << m_dabNotch
                << " m_biasTee: " << m_biasTee
                << " m_tuner: " << m_tuner
                << " m_antenna: " << m_antenna
                << " m_extRef: " << m_extRef;
    }
};

#endif /* _SDRPLAYV3_SDRPLAYV3SETTINGS_H_ */
