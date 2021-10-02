///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
//                                                                               //
// Implementation of static web API adapters used for preset serialization and   //
// deserialization                                                               //
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

#include "SWGDeviceSettings.h"
#include "usrpinput.h"
#include "usrpinputwebapiadapter.h"

USRPInputWebAPIAdapter::USRPInputWebAPIAdapter()
{}

USRPInputWebAPIAdapter::~USRPInputWebAPIAdapter()
{}

int USRPInputWebAPIAdapter::webapiSettingsGet(
        SWGrpx-100::SWGDeviceSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setUsrpInputSettings(new SWGrpx-100::SWGUSRPInputSettings());
    response.getUsrpInputSettings()->init();
    USRPInput::webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int USRPInputWebAPIAdapter::webapiSettingsPutPatch(
        bool force,
        const QStringList& deviceSettingsKeys,
        SWGrpx-100::SWGDeviceSettings& response, // query + response
        QString& errorMessage)
{
    (void) force; // no action
    (void) errorMessage;
    USRPInput::webapiUpdateDeviceSettings(m_settings, deviceSettingsKeys, response);
    return 200;
}
