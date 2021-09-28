///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Edouard Griffiths, F4EXB                                   //
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

#include "sdrplayv3settings.h"

#include <QtGlobal>
#include "util/simpleserializer.h"

SDRPlayV3Settings::SDRPlayV3Settings()
{
    resetToDefaults();
}

void SDRPlayV3Settings::resetToDefaults()
{
    m_centerFrequency = 7040*1000;
    m_LOppmTenths = 0;
    m_ifFrequencyIndex = 0;
    m_bandwidthIndex = 3;
    m_devSampleRate = 2000000;
    m_log2Decim = 0;
    m_fcPos = FC_POS_CENTER;
    m_dcBlock = false;
    m_iqCorrection = false;
    m_lnaIndex = 0;
    m_ifAGC = true;
    m_ifGain = -40;
    m_amNotch = false;
    m_fmNotch = false;
    m_dabNotch = false;
    m_biasTee = false;
    m_tuner = 0;
    m_antenna = 0;
    m_extRef = false;
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIDeviceIndex = 0;
}

QByteArray SDRPlayV3Settings::serialize() const
{
    SimpleSerializer s(1);

    s.writeS32(1, m_LOppmTenths);
    s.writeU32(3, m_ifFrequencyIndex);
    s.writeU32(5, m_bandwidthIndex);
    s.writeU32(6, m_devSampleRate);
    s.writeU32(7, m_log2Decim);
    s.writeS32(8, (int) m_fcPos);
    s.writeBool(9, m_dcBlock);
    s.writeBool(10, m_iqCorrection);
    s.writeS32(11, m_lnaIndex);
    s.writeBool(13, m_ifAGC);
    s.writeS32(14, m_ifGain);
    s.writeBool(15, m_useReverseAPI);
    s.writeString(16, m_reverseAPIAddress);
    s.writeU32(17, m_reverseAPIPort);
    s.writeU32(18, m_reverseAPIDeviceIndex);
    s.writeBool(19, m_amNotch);
    s.writeBool(20, m_fmNotch);
    s.writeBool(21, m_dabNotch);
    s.writeBool(22, m_biasTee);
    s.writeS32(23, m_tuner);
    s.writeS32(24, m_antenna);
    s.writeBool(25, m_extRef);
    return s.final();
}

bool SDRPlayV3Settings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if (!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if (d.getVersion() == 1)
    {
        int intval;
        uint32_t uintval;

        d.readS32(1, &m_LOppmTenths, 0);
        d.readU32(3, &m_ifFrequencyIndex, 0);
        d.readU32(5, &m_bandwidthIndex, 3);
        d.readU32(6, &m_devSampleRate, 2000000);
        d.readU32(7, &m_log2Decim, 0);
        d.readS32(8, &intval, 0);
        m_fcPos = (fcPos_t) intval;
        d.readBool(9, &m_dcBlock, false);
        d.readBool(10, &m_iqCorrection, false);
        d.readS32(11, &m_lnaIndex, 0);
        d.readBool(13, &m_ifAGC, true);
        d.readS32(14, &m_ifGain, -40);
        d.readBool(15, &m_useReverseAPI, false);
        d.readString(16, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(17, &uintval, 0);

        if ((uintval > 1023) && (uintval < 65535)) {
            m_reverseAPIPort = uintval;
        } else {
            m_reverseAPIPort = 8888;
        }

        d.readU32(18, &uintval, 0);
        m_reverseAPIDeviceIndex = uintval > 99 ? 99 : uintval;
        d.readBool(19, &m_amNotch, false);
        d.readBool(20, &m_fmNotch, false);
        d.readBool(21, &m_dabNotch, false);
        d.readBool(22, &m_biasTee, false);
        d.readS32(23, &m_tuner, 0);
        d.readS32(24, &m_antenna, 0);
        d.readBool(25, &m_extRef, false);

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}
