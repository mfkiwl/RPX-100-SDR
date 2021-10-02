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

#include <QtPlugin>
#include "plugin/pluginapi.h"

#ifndef SERVER_MODE
#include "chirpchatmodgui.h"
#endif
#include "chirpchatmod.h"
#include "chirpchatmodwebapiadapter.h"
#include "chirpchatmodplugin.h"

const PluginDescriptor ChirpChatModPlugin::m_pluginDescriptor = {
    ChirpChatMod::m_channelId,
    QStringLiteral("ChirpChat Modulator"),
    QStringLiteral("6.8.0"),
    QStringLiteral("(c) Edouard Griffiths, F4EXB"),
    QStringLiteral("https://github.com/f4exb/rpx-100"),
    true,
    QStringLiteral("https://github.com/f4exb/rpx-100")
};

ChirpChatModPlugin::ChirpChatModPlugin(QObject* parent) :
    QObject(parent),
    m_pluginAPI(0)
{
}

const PluginDescriptor& ChirpChatModPlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}

void ChirpChatModPlugin::initPlugin(PluginAPI* pluginAPI)
{
	m_pluginAPI = pluginAPI;

	// register LoRa modulator
	m_pluginAPI->registerTxChannel(ChirpChatMod::m_channelIdURI, ChirpChatMod::m_channelId, this);
}

void ChirpChatModPlugin::createTxChannel(DeviceAPI *deviceAPI, BasebandSampleSource **bs, ChannelAPI **cs) const
{
	if (bs || cs)
	{
		ChirpChatMod *instance = new ChirpChatMod(deviceAPI);

		if (bs) {
			*bs = instance;
		}

		if (cs) {
			*cs = instance;
		}
	}
}

#ifdef SERVER_MODE
ChannelGUI* ChirpChatModPlugin::createTxChannelGUI(
        DeviceUISet *deviceUISet,
        BasebandSampleSource *txChannel) const
{
	(void) deviceUISet;
	(void) txChannel;
    return nullptr;
}
#else
ChannelGUI* ChirpChatModPlugin::createTxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSource *txChannel) const
{
    return ChirpChatModGUI::create(m_pluginAPI, deviceUISet, txChannel);
}
#endif

ChannelWebAPIAdapter* ChirpChatModPlugin::createChannelWebAPIAdapter() const
{
	return new ChirpChatModWebAPIAdapter();
}
