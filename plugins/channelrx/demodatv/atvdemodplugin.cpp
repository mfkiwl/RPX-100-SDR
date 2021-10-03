///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 F4HKW                                                      //
// for oe3bia / RPX100                                                          //
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
#include <QAction>
#include "plugin/pluginapi.h"

#include "atvdemodgui.h"
#include "atvdemod.h"
#include "atvdemodplugin.h"
#include "atvdemodwebapiadapter.h"

const PluginDescriptor ATVDemodPlugin::m_ptrPluginDescriptor =
{
    ATVDemod::m_channelId,
	QString("ATV Demodulator"),
	QString("6.7.0"),
    QString("(c) F4HKW for oe3bia / RPX100"),
	QString("https://github.com/oe3bia/RPX100"),
	true,
	QString("https://github.com/oe3bia/RPX100")
};

ATVDemodPlugin::ATVDemodPlugin(QObject* ptrParent) :
    QObject(ptrParent),
    m_ptrPluginAPI(NULL)
{

}

const PluginDescriptor& ATVDemodPlugin::getPluginDescriptor() const
{
    return m_ptrPluginDescriptor;
}

void ATVDemodPlugin::initPlugin(PluginAPI* ptrPluginAPI)
{
    m_ptrPluginAPI = ptrPluginAPI;

	// register ATV demodulator
    m_ptrPluginAPI->registerRxChannel(ATVDemod::m_channelIdURI, ATVDemod::m_channelId, this);
}

void ATVDemodPlugin::createRxChannel(DeviceAPI *deviceAPI, BasebandSampleSink **bs, ChannelAPI **cs) const
{
	if (bs || cs)
	{
		ATVDemod *instance = new ATVDemod(deviceAPI);

		if (bs) {
			*bs = instance;
		}

		if (cs) {
			*cs = instance;
		}
	}
}

ChannelGUI* ATVDemodPlugin::createRxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel) const
{
    return ATVDemodGUI::create(m_ptrPluginAPI, deviceUISet, rxChannel);
}

ChannelWebAPIAdapter* ATVDemodPlugin::createChannelWebAPIAdapter() const
{
	return new ATVDemodWebAPIAdapter();
}
