///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia.                                  //
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

#ifndef INCLUDE_DEMODATV_WEBAPIADAPTER_H
#define INCLUDE_DEMODATV_WEBAPIADAPTER_H

#include "channel/channelwebapiadapter.h"
#include "atvdemodsettings.h"

/**
 * Standalone API adapter only for the settings
 */
class ATVDemodWebAPIAdapter : public ChannelWebAPIAdapter {
public:
    ATVDemodWebAPIAdapter();
    virtual ~ATVDemodWebAPIAdapter();

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

    static void webapiFormatChannelSettings(
            SWGRPX100::SWGChannelSettings& response,
            const ATVDemodSettings& settings);

    static void webapiUpdateChannelSettings(
            ATVDemodSettings& settings,
            const QStringList& channelSettingsKeys,
            SWGRPX100::SWGChannelSettings& response);

private:
    ATVDemodSettings m_settings;
};

#endif // INCLUDE_DEMODATV_WEBAPIADAPTER_H
