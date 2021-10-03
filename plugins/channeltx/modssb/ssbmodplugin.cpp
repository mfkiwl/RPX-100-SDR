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
#include "ssbmodgui.h"
#endif
#include "ssbmod.h"
#include "ssbmodwebapiadapter.h"
#include "ssbmodplugin.h"

const PluginDescriptor SSBModPlugin::m_pluginDescriptor = {
    SSBMod::m_channelId,
    QStringLiteral("SSB Modulator"),
    QStringLiteral("6.4.0"),
    QStringLiteral("(c) Bernhard Isemann, oe3bia"),
    QStringLiteral("https://github.com/oe3bia/RPX100"),
    true,
    QStringLiteral("https://github.com/oe3bia/RPX100")
};

SSBModPlugin::SSBModPlugin(QObject* parent) :
    QObject(parent),
    m_pluginAPI(0)
{
}

const PluginDescriptor& SSBModPlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}

void SSBModPlugin::initPlugin(PluginAPI* pluginAPI)
{
	m_pluginAPI = pluginAPI;

	// register SSB modulator
    m_pluginAPI->registerTxChannel(SSBMod::m_channelIdURI, SSBMod::m_channelId, this);
}

void SSBModPlugin::createTxChannel(DeviceAPI *deviceAPI, BasebandSampleSource **bs, ChannelAPI **cs) const
{
	if (bs || cs)
	{
		SSBMod *instance = new SSBMod(deviceAPI);

		if (bs) {
			*bs = instance;
		}

		if (cs) {
			*cs = instance;
		}
	}
}

#ifdef SERVER_MODE
ChannelGUI* SSBModPlugin::createTxChannelGUI(
        DeviceUISet *deviceUISet,
        BasebandSampleSource *txChannel) const
{
	(void) deviceUISet;
	(void) txChannel;
    return nullptr;
}
#else
ChannelGUI* SSBModPlugin::createTxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSource *txChannel) const
{
    return SSBModGUI::create(m_pluginAPI, deviceUISet, txChannel);
}
#endif

ChannelWebAPIAdapter* SSBModPlugin::createChannelWebAPIAdapter() const
{
	return new SSBModWebAPIAdapter();
}

