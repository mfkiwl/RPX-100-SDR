///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
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

#include "localsourceplugin.h"

#include <QtPlugin>
#include "plugin/pluginapi.h"

#ifndef SERVER_MODE
#include "localsourcegui.h"
#endif
#include "localsource.h"
#include "localsourcewebapiadapter.h"
#include "localsourceplugin.h"

const PluginDescriptor LocalSourcePlugin::m_pluginDescriptor = {
    LocalSource::m_channelId,
    QStringLiteral("Local channel source"),
    QStringLiteral("6.3.3"),
    QStringLiteral("(c) Edouard Griffiths, F4EXB"),
    QStringLiteral("https://github.com/f4exb/rpx-100"),
    true,
    QStringLiteral("https://github.com/f4exb/rpx-100")
};

LocalSourcePlugin::LocalSourcePlugin(QObject* parent) :
    QObject(parent),
    m_pluginAPI(0)
{
}

const PluginDescriptor& LocalSourcePlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}

void LocalSourcePlugin::initPlugin(PluginAPI* pluginAPI)
{
    m_pluginAPI = pluginAPI;

    // register channel Source
    m_pluginAPI->registerTxChannel(LocalSource::m_channelIdURI, LocalSource::m_channelId, this);
}

void LocalSourcePlugin::createTxChannel(DeviceAPI *deviceAPI, BasebandSampleSource **bs, ChannelAPI **cs) const
{
	if (bs || cs)
	{
		LocalSource *instance = new LocalSource(deviceAPI);

		if (bs) {
			*bs = instance;
		}

		if (cs) {
			*cs = instance;
		}
	}
}

#ifdef SERVER_MODE
ChannelGUI* LocalSourcePlugin::createTxChannelGUI(
        DeviceUISet *deviceUISet,
        BasebandSampleSource *txChannel) const
{
	(void) deviceUISet;
	(void) txChannel;
    return nullptr;
}
#else
ChannelGUI* LocalSourcePlugin::createTxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSource *txChannel) const
{
    return LocalSourceGUI::create(m_pluginAPI, deviceUISet, txChannel);
}
#endif

ChannelWebAPIAdapter* LocalSourcePlugin::createChannelWebAPIAdapter() const
{
	return new LocalSourceWebAPIAdapter();
}
