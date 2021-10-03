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

#include "SWGChannelSettings.h"
#include "localsource.h"
#include "localsourcewebapiadapter.h"

LocalSourceWebAPIAdapter::LocalSourceWebAPIAdapter()
{}

LocalSourceWebAPIAdapter::~LocalSourceWebAPIAdapter()
{}

int LocalSourceWebAPIAdapter::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setLocalSourceSettings(new SWGRPX100::SWGLocalSourceSettings());
    response.getLocalSourceSettings()->init();
    LocalSource::webapiFormatChannelSettings(response, m_settings);

    return 200;
}

int LocalSourceWebAPIAdapter::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) force; // no action
    (void) errorMessage;
    LocalSource::webapiUpdateChannelSettings(m_settings, channelSettingsKeys, response);

    return 200;
}
