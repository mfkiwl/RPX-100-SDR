///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Edouard Griffiths, F4EXB.                                  //
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

#include <QColor>
#include <QDataStream>

#include "dsp/dspengine.h"
#include "util/simpleserializer.h"
#include "settings/serializable.h"
#include "pagerdemodsettings.h"

PagerDemodSettings::PagerDemodSettings() :
    m_channelMarker(0),
    m_scopeGUI(0)
{
    resetToDefaults();
}

void PagerDemodSettings::resetToDefaults()
{
    m_baud = 1200;
    m_inputFrequencyOffset = 0;
    m_rfBandwidth = 20000.0f;
    m_fmDeviation = 4500.0f;
    m_decode = Standard;
    m_filterAddress = "";
    m_udpEnabled = false;
    m_udpAddress = "127.0.0.1";
    m_udpPort = 9999;
    m_scopeCh1 = 4;
    m_scopeCh2 = 9;
    m_rgbColor = QColor(200, 191, 231).rgb();
    m_title = "Pager Demodulator";
    m_streamIndex = 0;
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIDeviceIndex = 0;
    m_reverseAPIChannelIndex = 0;
    m_reverse = false;

    for (int i = 0; i < PAGERDEMOD_MESSAGE_COLUMNS; i++)
    {
        m_messageColumnIndexes[i] = i;
        m_messageColumnSizes[i] = -1; // Autosize
    }
}

QByteArray PagerDemodSettings::serialize() const
{
    SimpleSerializer s(1);

    s.writeS32(1, m_inputFrequencyOffset);
    s.writeFloat(2, m_rfBandwidth);
    s.writeFloat(3, m_fmDeviation);
    s.writeS32(4, m_baud);
    s.writeString(5, m_filterAddress);
    s.writeS32(6, (int)m_decode);
    s.writeBool(7, m_udpEnabled);
    s.writeString(8, m_udpAddress);
    s.writeU32(9, m_udpPort);
    s.writeS32(10, m_scopeCh1);
    s.writeS32(11, m_scopeCh2);
    s.writeU32(12, m_rgbColor);
    s.writeString(13, m_title);
    if (m_channelMarker) {
        s.writeBlob(14, m_channelMarker->serialize());
    }
    s.writeS32(15, m_streamIndex);
    s.writeBool(16, m_useReverseAPI);
    s.writeString(17, m_reverseAPIAddress);
    s.writeU32(18, m_reverseAPIPort);
    s.writeU32(19, m_reverseAPIDeviceIndex);
    s.writeU32(20, m_reverseAPIChannelIndex);
    s.writeBlob(21, m_scopeGUI->serialize());
    s.writeBool(22, m_reverse);
    s.writeBlob(23, serializeIntList(m_sevenbit));
    s.writeBlob(24, serializeIntList(m_unicode));

    for (int i = 0; i < PAGERDEMOD_MESSAGE_COLUMNS; i++) {
        s.writeS32(100 + i, m_messageColumnIndexes[i]);
    }
    for (int i = 0; i < PAGERDEMOD_MESSAGE_COLUMNS; i++) {
        s.writeS32(200 + i, m_messageColumnSizes[i]);
    }

    return s.final();
}

bool PagerDemodSettings::deserialize(const QByteArray& data)
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
        QByteArray blob;

        d.readS32(1, &m_inputFrequencyOffset, 0);
        d.readFloat(2, &m_rfBandwidth, 20000.0f);
        d.readFloat(3, &m_fmDeviation, 4500.0f);
        d.readS32(4, &m_baud, 1200);
        d.readString(5, &m_filterAddress, "");
        d.readS32(6, (int*)&m_decode, (int)Standard);
        d.readBool(7, &m_udpEnabled);
        d.readString(8, &m_udpAddress);
        d.readU32(9, &utmp);
        if ((utmp > 1023) && (utmp < 65535)) {
            m_udpPort = utmp;
        } else {
            m_udpPort = 9999;
        }
        d.readS32(10, &m_scopeCh1, 4);
        d.readS32(11, &m_scopeCh2, 9);
        d.readU32(12, &m_rgbColor, QColor(200, 191, 231).rgb());
        d.readString(13, &m_title, "Pager Demodulator");
        d.readBlob(14, &bytetmp);
        if (m_channelMarker) {
            m_channelMarker->deserialize(bytetmp);
        }
        d.readS32(15, &m_streamIndex, 0);
        d.readBool(16, &m_useReverseAPI, false);
        d.readString(17, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(18, &utmp, 0);
        if ((utmp > 1023) && (utmp < 65535)) {
            m_reverseAPIPort = utmp;
        } else {
            m_reverseAPIPort = 8888;
        }
        d.readU32(19, &utmp, 0);
        m_reverseAPIDeviceIndex = utmp > 99 ? 99 : utmp;
        d.readU32(20, &utmp, 0);
        m_reverseAPIChannelIndex = utmp > 99 ? 99 : utmp;

        if (m_scopeGUI)
        {
            d.readBlob(21, &bytetmp);
            m_scopeGUI->deserialize(bytetmp);
        }
        d.readBool(22, &m_reverse, false);
        d.readBlob(23, &blob);
        deserializeIntList(blob, m_sevenbit);
        d.readBlob(24, &blob);
        deserializeIntList(blob, m_unicode);

        for (int i = 0; i < PAGERDEMOD_MESSAGE_COLUMNS; i++) {
            d.readS32(100 + i, &m_messageColumnIndexes[i], i);
        }
        for (int i = 0; i < PAGERDEMOD_MESSAGE_COLUMNS; i++) {
            d.readS32(200 + i, &m_messageColumnSizes[i], -1);
        }

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

QByteArray PagerDemodSettings::serializeIntList(const QList<qint32>& ints) const
{
    QByteArray data;
    QDataStream *stream = new QDataStream(&data,  QIODevice::WriteOnly);
    (*stream) << ints;
    delete stream;
    return data;
}

void PagerDemodSettings::deserializeIntList(const QByteArray& data, QList<qint32>& ints)
{
    QDataStream *stream = new QDataStream(data);
    (*stream) >> ints;
    delete stream;
}
