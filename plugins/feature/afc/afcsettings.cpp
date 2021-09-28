///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Edouard Griffiths, F4EXB                                   //
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

#include "util/simpleserializer.h"
#include "settings/serializable.h"

#include "afcsettings.h"

AFCSettings::AFCSettings()
{
    resetToDefaults();
}

void AFCSettings::resetToDefaults()
{
    m_title = "AFC";
    m_rgbColor = QColor(255, 255, 0).rgb();
    m_trackerDeviceSetIndex = -1;
    m_trackedDeviceSetIndex = -1;
    m_hasTargetFrequency = false;
    m_transverterTarget = false;
    m_targetFrequency = 0;
    m_freqTolerance = 1000;
    m_trackerAdjustPeriod = 20;
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIFeatureSetIndex = 0;
    m_reverseAPIFeatureIndex = 0;
}

QByteArray AFCSettings::serialize() const
{
    SimpleSerializer s(1);

    s.writeString(1, m_title);
    s.writeU32(2, m_rgbColor);
    s.writeS32(3, m_trackerDeviceSetIndex);
    s.writeU32(4, m_trackerAdjustPeriod);
    s.writeS32(5, m_trackedDeviceSetIndex);
    s.writeBool(6, m_hasTargetFrequency);
    s.writeBool(7, m_transverterTarget);
    s.writeU64(8, m_targetFrequency);
    s.writeU64(9, m_freqTolerance);
    s.writeBool(10, m_useReverseAPI);
    s.writeString(11, m_reverseAPIAddress);
    s.writeU32(12, m_reverseAPIPort);
    s.writeU32(13, m_reverseAPIFeatureSetIndex);
    s.writeU32(14, m_reverseAPIFeatureIndex);

    return s.final();
}

bool AFCSettings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if(!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if(d.getVersion() == 1)
    {
        QByteArray bytetmp;
        uint32_t utmp;
        QString strtmp;

        d.readString(1, &m_title, "AFC");
        d.readU32(2, &m_rgbColor, QColor(255, 255, 0).rgb());
        d.readS32(3, &m_trackerDeviceSetIndex, -1);
        d.readU32(4, &m_trackerAdjustPeriod, 20);
        d.readS32(5, &m_trackedDeviceSetIndex, -1);
        d.readBool(6, &m_hasTargetFrequency, false);
        d.readBool(7, &m_transverterTarget, false);
        d.readU64(8, &m_targetFrequency, 0);
        d.readU64(9, &m_freqTolerance, 1000);
        d.readBool(10, &m_useReverseAPI, false);
        d.readString(11, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(12, &utmp, 0);

        if ((utmp > 1023) && (utmp < 65535)) {
            m_reverseAPIPort = utmp;
        } else {
            m_reverseAPIPort = 8888;
        }

        d.readU32(13, &utmp, 0);
        m_reverseAPIFeatureSetIndex = utmp > 99 ? 99 : utmp;
        d.readU32(14, &utmp, 0);
        m_reverseAPIFeatureIndex = utmp > 99 ? 99 : utmp;

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}
