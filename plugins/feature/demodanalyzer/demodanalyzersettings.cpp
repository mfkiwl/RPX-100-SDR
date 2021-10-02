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

#include "demodanalyzersettings.h"

const QStringList DemodAnalyzerSettings::m_channelTypes = {
    QStringLiteral("AISDemod"),
    QStringLiteral("AISMod"),
    QStringLiteral("AMDemod"),
    QStringLiteral("AMMod"),
    QStringLiteral("DABDemod"),
    QStringLiteral("DSDDemod"),
    QStringLiteral("NFMDemod"),
    QStringLiteral("NFMMod"),
    QStringLiteral("PacketDemod"),
    QStringLiteral("PacketMod"),
    QStringLiteral("SSBDemod"),
    QStringLiteral("SSBMod"),
    QStringLiteral("WFMDemod"),
    QStringLiteral("WFMMod"),
};

const QStringList DemodAnalyzerSettings::m_channelURIs = {
    QStringLiteral("RPX100.channel.aisdemod"),
    QStringLiteral("RPX100.channel.modais"),
    QStringLiteral("RPX100.channel.amdemod"),
    QStringLiteral("RPX100.channeltx.modam"),
    QStringLiteral("RPX100.channel.dabdemod"),
    QStringLiteral("RPX100.channel.dsddemod"),
    QStringLiteral("RPX100.channel.nfmdemod"),
    QStringLiteral("RPX100.channeltx.modnfm"),
    QStringLiteral("RPX100.channel.packetdemod"),
    QStringLiteral("RPX100.channeltx.modpacket"),
    QStringLiteral("RPX100.channel.ssbdemod"),
    QStringLiteral("RPX100.channeltx.modssb"),
    QStringLiteral("RPX100.channel.wfmdemod"),
    QStringLiteral("RPX100.channeltx.modwfm"),
};

DemodAnalyzerSettings::DemodAnalyzerSettings() :
    m_spectrumGUI(nullptr),
    m_scopeGUI(nullptr)
{
    resetToDefaults();
}

void DemodAnalyzerSettings::resetToDefaults()
{
    m_log2Decim = 0;
    m_title = "Demod Analyzer";
    m_rgbColor = QColor(128, 128, 128).rgb();
    m_useReverseAPI = false;
    m_reverseAPIAddress = "127.0.0.1";
    m_reverseAPIPort = 8888;
    m_reverseAPIFeatureSetIndex = 0;
    m_reverseAPIFeatureIndex = 0;
}

QByteArray DemodAnalyzerSettings::serialize() const
{
    SimpleSerializer s(1);

    s.writeBlob(1, m_spectrumGUI->serialize());
    s.writeBlob(2, m_scopeGUI->serialize());
    s.writeS32(3, m_log2Decim);
    s.writeString(5, m_title);
    s.writeU32(6, m_rgbColor);
    s.writeBool(7, m_useReverseAPI);
    s.writeString(8, m_reverseAPIAddress);
    s.writeU32(9, m_reverseAPIPort);
    s.writeU32(10, m_reverseAPIFeatureSetIndex);
    s.writeU32(11, m_reverseAPIFeatureIndex);

    return s.final();
}

bool DemodAnalyzerSettings::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if (!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if (d.getVersion() == 1)
    {
        QByteArray bytetmp;
        uint32_t utmp;
        QString strtmp;

        if (m_spectrumGUI)
        {
            d.readBlob(1, &bytetmp);
            m_spectrumGUI->deserialize(bytetmp);
        }

        if (m_scopeGUI)
        {
            d.readBlob(2, &bytetmp);
            m_scopeGUI->deserialize(bytetmp);
        }

        d.readS32(3, &m_log2Decim, 0);
        d.readString(5, &m_title, "Demod Analyzer");
        d.readU32(6, &m_rgbColor, QColor(128, 128, 128).rgb());
        d.readBool(7, &m_useReverseAPI, false);
        d.readString(8, &m_reverseAPIAddress, "127.0.0.1");
        d.readU32(9, &utmp, 0);

        if ((utmp > 1023) && (utmp < 65535)) {
            m_reverseAPIPort = utmp;
        } else {
            m_reverseAPIPort = 8888;
        }

        d.readU32(10, &utmp, 0);
        m_reverseAPIFeatureSetIndex = utmp > 99 ? 99 : utmp;
        d.readU32(11, &utmp, 0);
        m_reverseAPIFeatureIndex = utmp > 99 ? 99 : utmp;

        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}
