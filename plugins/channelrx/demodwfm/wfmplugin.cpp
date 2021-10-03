#include "wfmplugin.h"

#include <QtPlugin>
#include "plugin/pluginapi.h"

#ifndef SERVER_MODE
#include "wfmdemodgui.h"
#endif
#include "wfmdemod.h"
#include "wfmdemodwebapiadapter.h"
#include "wfmplugin.h"

const PluginDescriptor WFMPlugin::m_pluginDescriptor = {
    WFMDemod::m_channelId,
	QStringLiteral("WFM Demodulator"),
	QStringLiteral("6.6.1"),
	QStringLiteral("(c) Bernhard Isemann, oe3bia"),
	QStringLiteral("https://github.com/oe3bia/RPX100"),
	true,
	QStringLiteral("https://github.com/oe3bia/RPX100")
};

WFMPlugin::WFMPlugin(QObject* parent) :
	QObject(parent),
	m_pluginAPI(0)
{
}

const PluginDescriptor& WFMPlugin::getPluginDescriptor() const
{
	return m_pluginDescriptor;
}

void WFMPlugin::initPlugin(PluginAPI* pluginAPI)
{
	m_pluginAPI = pluginAPI;

	// register WFM demodulator
	m_pluginAPI->registerRxChannel(WFMDemod::m_channelIdURI, WFMDemod::m_channelId, this);
}

void WFMPlugin::createRxChannel(DeviceAPI *deviceAPI, BasebandSampleSink **bs, ChannelAPI **cs) const
{
	if (bs || cs)
	{
		WFMDemod *instance = new WFMDemod(deviceAPI);

		if (bs) {
			*bs = instance;
		}

		if (cs) {
			*cs = instance;
		}
	}
}

#ifdef SERVER_MODE
ChannelGUI* WFMPlugin::createRxChannelGUI(
        DeviceUISet *deviceUISet,
        BasebandSampleSink *rxChannel) const
{
	(void) deviceUISet;
	(void) rxChannel;
    return nullptr;
}
#else
ChannelGUI* WFMPlugin::createRxChannelGUI(DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel) const
{
	return WFMDemodGUI::create(m_pluginAPI, deviceUISet, rxChannel);
}
#endif

ChannelWebAPIAdapter* WFMPlugin::createChannelWebAPIAdapter() const
{
	return new WFMDemodWebAPIAdapter();
}
