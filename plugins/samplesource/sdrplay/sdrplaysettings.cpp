///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Bernhard Isemann, oe3bia                                   //
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

#include "sdrplaysettings.h"

#include <QtGlobal>
#include "util/simpleserializer.h"

SDRPlaySettings::SDRPlaySettings()
{
	resetToDefaults();
}

void SDRPlaySettings::resetToDefaults()
{
	m_centerFrequency = 7040*1000;
	m_tunerGain = 0;
    m_LOppmTenths = 0;
    m_frequencyBandIndex = 0;
    m_ifFrequencyIndex = 0;
    m_bandwidthIndex = 0;
	m_devSampleRateIndex = 0;
    m_log2Decim = 0;
    m_fcPos = FC_POS_CENTER;
    m_dcBlock = false;
    m_iqCorrection = false;
    m_tunerGainMode = true;
    m_lnaOn = false;
    m_mixerAmpOn = false;
    m_basebandGain = 29;
    m_iqOrder = true;
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIDeviceIndex = 0;
}

QByteArray SDRPlaySettings::serialize() const
{
	SimpleSerializer s(1);

	s.writeS32(1, m_LOppmTenths);
    s.writeU32(2, m_frequencyBandIndex);
    s.writeU32(3, m_ifFrequencyIndex);
    s.writeS32(4, m_tunerGain);
    s.writeU32(5, m_bandwidthIndex);
	s.writeU32(6, m_devSampleRateIndex);
	s.writeU32(7, m_log2Decim);
	s.writeS32(8, (int) m_fcPos);
	s.writeBool(9, m_dcBlock);
	s.writeBool(10, m_iqCorrection);
	s.writeBool(11, m_tunerGainMode);
	s.writeBool(12, m_lnaOn);
	s.writeBool(13, m_mixerAmpOn);
	s.writeS32(14, m_basebandGain);
    s.writeBool(15, m_useReverseAPI);
    s.writeString(16, m_reverseAPIAddress);
    s.writeU32(17, m_reverseAPIPort);
    s.writeU32(18, m_reverseAPIDeviceIndex);
    s.writeBool(19, m_iqOrder);

	return s.final();
}

bool SDRPlaySettings::deserialize(const QByteArray& data)
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
        d.readU32(2, &m_frequencyBandIndex, 0);
        d.readU32(3, &m_ifFrequencyIndex, 0);
		d.readS32(4, &m_tunerGain, 0);
        d.readU32(5, &m_bandwidthIndex, 0);
        d.readU32(6, &m_devSampleRateIndex, 0);
		d.readU32(7, &m_log2Decim, 0);
		d.readS32(8, &intval, 0);
		m_fcPos = (fcPos_t) intval;
		d.readBool(9, &m_dcBlock, false);
		d.readBool(10, &m_iqCorrection, false);
		d.readBool(11, &m_tunerGainMode, true);
		d.readBool(12, &m_lnaOn, false);
		d.readBool(13, &m_mixerAmpOn, false);
		d.readS32(14, &m_basebandGain, 29);
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
        d.readBool(19, &m_iqOrder, true);

		return true;
	}
	else
	{
		resetToDefaults();
		return false;
	}
}
