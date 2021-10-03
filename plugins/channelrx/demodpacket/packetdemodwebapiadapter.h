///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia.                                  //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#ifndef INCLUDE_PACKETDEMOD_WEBAPIADAPTER_H
#define INCLUDE_PACKETDEMOD_WEBAPIADAPTER_H

#include "channel/channelwebapiadapter.h"
#include "packetdemodsettings.h"

/**
 * Standalone API adapter only for the settings
 */
class PacketDemodWebAPIAdapter : public ChannelWebAPIAdapter {
public:
    PacketDemodWebAPIAdapter();
    virtual ~PacketDemodWebAPIAdapter();

    virtual QByteArray serialize() const { return m_settings.serialize(); }
    virtual bool deserialize(const QByteArray& data) { return m_settings.deserialize(data); }

    virtual int webapiSettingsGet(
            SWGRPX100::SWGChannelSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGChannelSettings& response,
            QString& errorMessage);

private:
    PacketDemodSettings m_settings;
};

#endif // INCLUDE_PACKETDEMOD_WEBAPIADAPTER_H
