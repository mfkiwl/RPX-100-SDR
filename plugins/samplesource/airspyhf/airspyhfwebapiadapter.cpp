///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
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
#include "airspyhfinput.h"
#include "airspyhfwebapiadapter.h"

AirspyHFWebAPIAdapter::AirspyHFWebAPIAdapter()
{}

AirspyHFWebAPIAdapter::~AirspyHFWebAPIAdapter()
{}

int AirspyHFWebAPIAdapter::webapiSettingsGet(
        SWGRPX100::SWGDeviceSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setAirspyHfSettings(new SWGRPX100::SWGAirspyHFSettings());
    response.getAirspyHfSettings()->init();
    AirspyHFInput::webapiFormatDeviceSettings(response, m_settings);
    return 200;
}

int AirspyHFWebAPIAdapter::webapiSettingsPutPatch(
        bool force,
        const QStringList& deviceSettingsKeys,
        SWGRPX100::SWGDeviceSettings& response, // query + response
        QString& errorMessage)
{
    (void) force; // no action
    (void) errorMessage;
    AirspyHFInput::webapiUpdateDeviceSettings(m_settings, deviceSettingsKeys, response);
    return 200;
}
