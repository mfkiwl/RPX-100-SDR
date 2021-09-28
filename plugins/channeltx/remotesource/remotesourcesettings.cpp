///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018-2019 Edouard Griffiths, F4EXB                              //
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

#include "remotesourcesettings.h"

#include <QColor>

#include "util/simpleserializer.h"
#include "settings/serializable.h"


RemoteSourceSettings::RemoteSourceSettings()
{
    resetToDefaults();
}

void RemoteSourceSettings::resetToDefaults()
{
    m_dataAddress = "127.0.0.1";
    m_dataPort = 9090;
    m_rgbColor = QColor(140, 4, 4).rgb();
    m_title = "Remote source";
    m_channelMarker = nullptr;
    m_streamIndex = 0;
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIDeviceIndex = 0;
    m_reverseAPIChannelIndex = 0;
}

QByteArray RemoteSourceSettings::serialize() const
{
    SimpleSerializer s(1);
    s.writeString(1, m_dataAddress);
    s.writeU32(2, m_dataPort);
    s.writeU32(3, m_rgbColor);
    s.writeString(4, m_title);
    s.writeBool(5, m_useReverseAPI);
    s.writeString(6, m_reverseAPIAddress);
    s.writeU32(7, m_reverseAPIPort);
    s.writeU32(8, m_reverseAPIDeviceIndex);
    s.writeU32(9, m_reverseAPIChannelIndex);
    s.writeS32(10, m_streamIndex);

    return s.final();
}

bool RemoteSourceSettings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if(!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if(d.getVersion() == 1)
    {
        uint32_t tmp;
        QString strtmp;

        d.readString(1, &m_dataAddress, "127.0.0.1");
        d.readU32(2, &tmp, 0);

        if ((tmp > 1023) && (tmp < 65535)) {
            m_dataPort = tmp;
        } else {
            m_dataPort = 9090;
        }

        d.readU32(3, &m_rgbColor, QColor(0, 255, 255).rgb());
        d.readString(4, &m_title, "Remote source");
        d.readBool(5, &m_useReverseAPI, false);
        d.readString(6, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(7, &tmp, 0);

        if ((tmp > 1023) && (tmp < 65535)) {
            m_reverseAPIPort = tmp;
        } else {
            m_reverseAPIPort = 8888;
        }

        d.readU32(8, &tmp, 0);
        m_reverseAPIDeviceIndex = tmp > 99 ? 99 : tmp;
        d.readU32(9, &tmp, 0);
        m_reverseAPIChannelIndex = tmp > 99 ? 99 : tmp;
        d.readS32(10, &m_streamIndex, 0);

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}
