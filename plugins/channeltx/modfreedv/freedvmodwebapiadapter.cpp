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
#include "dsp/cwkeyer.h"
#include "freedvmod.h"
#include "freedvmodwebapiadapter.h"

FreeDVModWebAPIAdapter::FreeDVModWebAPIAdapter()
{}

FreeDVModWebAPIAdapter::~FreeDVModWebAPIAdapter()
{}

int FreeDVModWebAPIAdapter::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    response.setFreeDvModSettings(new SWGRPX100::SWGFreeDVModSettings());
    response.getFreeDvModSettings()->init();
    FreeDVMod::webapiFormatChannelSettings(response, m_settings);

    const CWKeyerSettings& cwKeyerSettings = m_settings.getCWKeyerSettings();
    SWGRPX100::SWGCWKeyerSettings *apiCwKeyerSettings = response.getFreeDvModSettings()->getCwKeyer();
    apiCwKeyerSettings->init();
    CWKeyer::webapiFormatChannelSettings(apiCwKeyerSettings, cwKeyerSettings);

    return 200;
}

int FreeDVModWebAPIAdapter::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) force; // no action
    (void) errorMessage;
    FreeDVMod::webapiUpdateChannelSettings(m_settings, channelSettingsKeys, response);

    if (channelSettingsKeys.contains("cwKeyer"))
    {
        CWKeyerSettings newCWKeyerSettings;
        SWGRPX100::SWGCWKeyerSettings *apiCwKeyerSettings = response.getFreeDvModSettings()->getCwKeyer();
        CWKeyer::webapiSettingsPutPatch(channelSettingsKeys, newCWKeyerSettings, apiCwKeyerSettings);
        m_settings.setCWKeyerSettings(newCWKeyerSettings);
        const QByteArray& serializedNewSettings = m_settings.serialize(); // effectively update CW keyer settings
    }

    FreeDVMod::webapiFormatChannelSettings(response, m_settings);
    return 200;
}
