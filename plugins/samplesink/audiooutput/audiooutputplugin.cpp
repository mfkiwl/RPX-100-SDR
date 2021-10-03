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
#include "util/simpleserializer.h"
#include "audiooutputplugin.h"
#include "audiooutputwebapiadapter.h"

#ifdef SERVER_MODE
#include "audiooutput.h"
#else
#include "audiooutputgui.h"
#endif

const PluginDescriptor AudioOutputPlugin::m_pluginDescriptor = {
    QString("AudioOutput"),
	QString("Audio output"),
	QString("6.8.0"),
	QString("(c) Bernhard Isemann, oe3bia"),
	QString("https://github.com/oe3bia/RPX100"),
	true,
	QString("https://github.com/oe3bia/RPX100")
};

const QString AudioOutputPlugin::m_hardwareID = "AudioOutput";
const QString AudioOutputPlugin::m_deviceTypeID = AUDIOOUTPUT_DEVICE_TYPE_ID;

AudioOutputPlugin::AudioOutputPlugin(QObject* parent) :
	QObject(parent)
{
}

const PluginDescriptor& AudioOutputPlugin::getPluginDescriptor() const
{
	return m_pluginDescriptor;
}

void AudioOutputPlugin::initPlugin(PluginAPI* pluginAPI)
{
	pluginAPI->registerSampleSink(m_deviceTypeID, this);
}

void AudioOutputPlugin::enumOriginDevices(QStringList& listedHwIds, OriginDevices& originDevices)
{
    if (listedHwIds.contains(m_hardwareID)) { // check if it was done
        return;
    }

    originDevices.append(OriginDevice(
        "AudioOutput",
        m_hardwareID,
        QString(),
        0, // Sequence
        0, // nb Rx
        1  // nb Tx
    ));

    listedHwIds.append(m_hardwareID);
}

PluginInterface::SamplingDevices AudioOutputPlugin::enumSampleSinks(const OriginDevices& originDevices)
{
	SamplingDevices result;

    for (OriginDevices::const_iterator it = originDevices.begin(); it != originDevices.end(); ++it)
    {
        if (it->hardwareId == m_hardwareID)
        {
            result.append(SamplingDevice(
                it->displayableName,
                it->hardwareId,
                m_deviceTypeID,
                it->serial,
                it->sequence,
                PluginInterface::SamplingDevice::BuiltInDevice,
                PluginInterface::SamplingDevice::StreamSingleTx,
                1,
                0
            ));
        }
    }

	return result;
}

#ifdef SERVER_MODE
DeviceGUI* AudioOutputPlugin::createSampleSinkPluginInstanceGUI(
        const QString& sinkId,
        QWidget **widget,
        DeviceUISet *deviceUISet)
{
    (void) sinkId;
    (void) widget;
    (void) deviceUISet;
    return nullptr;
}
#else
DeviceGUI* AudioOutputPlugin::createSampleSinkPluginInstanceGUI(
        const QString& sinkId,
        QWidget **widget,
        DeviceUISet *deviceUISet)
{
	if (sinkId == m_deviceTypeID)
	{
		AudioOutputGui* gui = new AudioOutputGui(deviceUISet);
		*widget = gui;
		return gui;
	}
	else
	{
		return nullptr;
	}
}
#endif

DeviceSampleSink* AudioOutputPlugin::createSampleSinkPluginInstance(const QString& sinkId, DeviceAPI *deviceAPI)
{
    if(sinkId == m_deviceTypeID)
    {
        AudioOutput* output = new AudioOutput(deviceAPI);
        return output;
    }
    else
    {
        return nullptr;
    }
}

DeviceWebAPIAdapter *AudioOutputPlugin::createDeviceWebAPIAdapter() const
{
    return new AudioOutputWebAPIAdapter();
}
