///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB.                                  //
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
#include "filesink.h"
#include "filesinkwebapiadapter.h"

FileSinkWebAPIAdapter::FileSinkWebAPIAdapter()
{}

FileSinkWebAPIAdapter::~FileSinkWebAPIAdapter()
{}

int FileSinkWebAPIAdapter::webapiSettingsGet(
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) errorMessage;
    (void) response;
    response.setFileSinkSettings(new SWGRPX100::SWGFileSinkSettings());
    response.getFileSinkSettings()->init();
    FileSink::webapiFormatChannelSettings(response, m_settings);

    return 200;
}

int FileSinkWebAPIAdapter::webapiSettingsPutPatch(
        bool force,
        const QStringList& channelSettingsKeys,
        SWGRPX100::SWGChannelSettings& response,
        QString& errorMessage)
{
    (void) force; // no action
    (void) errorMessage;
    FileSink::webapiUpdateChannelSettings(m_settings, channelSettingsKeys, response);

    return 200;
}
