///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Bernhard Isemann, oe3bia                                   //
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

#include <QtPlugin>
#include "plugin/pluginapi.h"

#ifndef SERVER_MODE
#include "nfmmodgui.h"
#endif
#include "nfmmod.h"
#include "nfmmodwebapiadapter.h"
#include "nfmmodplugin.h"

const PluginDescriptor NFMModPlugin::m_pluginDescriptor = {
    NFMMod::m_channelId,
    QStringLiteral("NFM Modulator"),
    QStringLiteral("6.9.0"),
    QStringLiteral("(c) Bernhard Isemann, oe3bia"),
    QStringLiteral("https://github.com/oe3bia/RPX100"),
    true,
    QStringLiteral("https://github.com/oe3bia/RPX100")
};

NFMModPlugin::NFMModPlugin(QObject* parent) :
    QObject(parent),
    m_pluginAPI(0)
{
}

const PluginDescriptor& NFMModPlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}

void NFMModPlugin::initPlugin(PluginAPI* pluginAPI)
{
	m_pluginAPI = pluginAPI;

	// register AM modulator
	m_pluginAPI->registerTxChannel(NFMMod::m_channelIdURI, NFMMod::m_channelId, this);
}

void NFMModPlugin::createTxChannel(DeviceAPI *deviceAPI, BasebandSampleSource **bs, ChannelAPI **cs) const
{
	if (bs || cs)
	{
		NFMMod *instance = new NFMMod(deviceAPI);

		if (bs) {
			*bs = instance;
		}

		if (cs) {
			*cs = instance;
		}
	}
}

#ifdef SERVER_MODE
ChannelGUI* NFMModPlugin::createTxChannelGUI(
        DeviceUISet *deviceUISet,
        BasebandSampleSource *txChannel) const
{
	(void) deviceUISet;
	(void) txChannel;
    return nullptr;
}
#else
ChannelGUI* NFMModPlugin::createTxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSource *txChannel) const
{
    return NFMModGUI::create(m_pluginAPI, deviceUISet, txChannel);
}
#endif

ChannelWebAPIAdapter* NFMModPlugin::createChannelWebAPIAdapter() const
{
	return new NFMModWebAPIAdapter();
}
