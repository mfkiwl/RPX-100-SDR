///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
// Copyright (C) 2020 Bernhard Isemann, oe3bia                                   //
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

#include <QJsonArray>
#include <QList>

#include "webapiutils.h"

const QMap<QString, QString> WebAPIUtils::m_channelURIToSettingsKey = {
    {"RPX100.channel.adsbdemod", "ADSBDemodSettings"},
    {"RPX100.channel.modais", "AISModSettings"},
    {"RPX100.channel.aisdemod", "AISDemodSettings"},
    {"RPX100.channel.aptdemod", "APTDemodSettings"},
    {"RPX100.channel.amdemod", "AMDemodSettings"},
    {"RPX100.channel.aptdemod", "APTDemodSettings"},
    {"de.maintech.RPX100ove.channel.am", "AMDemodSettings"}, // remap
    {"RPX100.channeltx.modam", "AMModSettings"},
    {"RPX100.channeltx.modatv", "ATVModSettings"},
    {"RPX100.channeltx.moddatv", "DATVModSettings"},
    {"RPX100.channel.bfm", "BFMDemodSettings"},
    {"RPX100.channel.chanalyzer", "ChannelAnalyzerSettings"},
    {"RPX100.channel.chanalyzerng", "ChannelAnalyzerSettings"}, // remap
    {"org.oe3bia.RPX100ove.channel.chanalyzer", "ChannelAnalyzerSettings"}, // remap
    {"RPX100.channel.chirpchatdemod", "ChirpChatDemodSettings"},
    {"RPX100.channel.modchirpchat", "ChirpChatModSettings"},
    {"RPX100.channel.demodatv", "ATVDemodSettings"},
    {"RPX100.channel.demoddatv", "DATVDemodSettings"},
    {"RPX100.channel.dabdemod", "DABDemodSettings"},
    {"RPX100.channel.dsddemod", "DSDDemodSettings"},
    {"RPX100.channel.filesink", "FileSinkSettings"},
    {"RPX100.channeltx.filesource", "FileSourceSettings"},
    {"RPX100.channel.freedvdemod", "FreeDVDemodSettings"},
    {"RPX100.channeltx.freedvmod", "FreeDVModSettings"},
    {"RPX100.channel.freqtracker", "FreqTrackerSettings"},
    {"RPX100.channel.nfmdemod", "NFMDemodSettings"},
    {"de.maintech.RPX100ove.channel.nfm", "NFMDemodSettings"}, // remap
    {"RPX100.channeltx.modnfm", "NFMModSettings"},
    {"RPX100.channel.noisefigure", "NoiseFigureSettings"},
    {"RPX100.demod.localsink", "LocalSinkSettings"},
    {"RPX100.channel.localsink", "LocalSinkSettings"}, // remap
    {"RPX100.channel.localsource", "LocalSourceSettings"},
    {"RPX100.channel.packetdemod", "PacketDemodSettings"},
    {"RPX100.channel.pagerdemod", "PagerDemodSettings"},
    {"RPX100.channeltx.modpacket", "PacketModSettings"},
    {"RPX100.channeltx.mod802.15.4", "IEEE_802_15_4_ModSettings"},
    {"RPX100.channel.radioclock", "RadioClockSettings"},
    {"RPX100.demod.remotesink", "RemoteSinkSettings"},
    {"RPX100.channeltx.remotesource", "RemoteSourceSettings"},
    {"RPX100.channeltx.modssb", "SSBModSettings"},
    {"RPX100.channel.ssbdemod", "SSBDemodSettings"},
    {"de.maintech.RPX100ove.channel.ssb", "SSBDemodSettings"}, // remap
    {"RPX100.channeltx.udpsource", "UDPSourceSettings"},
    {"RPX100.channeltx.udpsink", "UDPSinkSettings"}, // remap
    {"RPX100.channel.udpsink", "UDPSinkSettings"},
    {"RPX100.channel.udpsrc", "UDPSourceSettings"}, // remap
    {"RPX100.channel.vordemod", "VORDemodSettings"},
    {"RPX100.channel.wfmdemod", "WFMDemodSettings"},
    {"de.maintech.RPX100ove.channel.wfm", "WFMDemodSettings"}, // remap
    {"RPX100.channeltx.modwfm", "WFMModSettings"},
    {"RPX100.channel.beamsteeringcwmod", "BeamSteeringCWModSettings"},
    {"RPX100.channelmimo.interferometer", "InterferometerSettings"},
    {"RPX100.channel.sigmffilesink", "SigMFFileSinkSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_deviceIdToSettingsKey = {
    {"RPX100.samplesource.airspy", "airspySettings"},
    {"RPX100.samplesource.airspyhf", "airspyHFSettings"},
    {"RPX100.samplesource.audioinput", "audioInputSettings"},
    {"RPX100.samplesink.audiooutput", "audioOutputSettings"},
    {"RPX100.samplesource.bladerf1input", "bladeRF1InputSettings"},
    {"RPX100.samplesource.bladerf", "bladeRF1InputSettings"}, // remap
    {"RPX100.samplesink.bladerf1output", "bladeRF1OutputSettings"},
    {"RPX100.samplesource.bladerf1output", "bladeRF1OutputSettings"}, // remap
    {"RPX100.samplesource.bladerfoutput", "bladeRF1OutputSettings"}, // remap
    {"RPX100.samplesource.bladerf2input", "bladeRF2InputSettings"},
    {"RPX100.samplesink.bladerf2output", "bladeRF2OutputSettings"},
    {"RPX100.samplesource.bladerf2output", "bladeRF2OutputSettings"}, // remap
    {"RPX100.samplemimo.bladerf2mimo", "bladeRF2MIMOSettings"},
    {"RPX100.samplesource.fcdpro", "fcdProSettings"},
    {"RPX100.samplesource.fcdproplus", "fcdProPlusSettings"},
    {"RPX100.samplesource.fileinput", "fileInputSettings"},
    {"RPX100.samplesource.filesource", "fileInputSettings"}, // remap
    {"RPX100.samplesource.hackrf", "hackRFInputSettings"},
    {"RPX100.samplesink.hackrf", "hackRFOutputSettings"},
    {"RPX100.samplesource.hackrfoutput", "hackRFOutputSettings"}, // remap
    {"RPX100.samplesource.kiwisdrsource", "kiwiSDRSettings"},
    {"RPX100.samplesource.limesdr", "limeSdrInputSettings"},
    {"RPX100.samplesink.limesdr", "limeSdrOutputSettings"},
    {"RPX100.samplesource.localinput", "localInputSettings"},
    {"RPX100.samplesink.localoutput", "localOutputSettings"},
    {"RPX100.samplesource.localoutput", "localOutputSettings"}, // remap
    {"RPX100.samplemimo.metismiso", "metisMISOSettings"},
    {"RPX100.samplesource.perseus", "perseusSettings"},
    {"RPX100.samplesource.plutosdr", "plutoSdrInputSettings"},
    {"RPX100.samplesink.plutosdr", "plutoSdrOutputSettings"},
    {"RPX100.samplesource.rtlsdr", "rtlSdrSettings"},
    {"RPX100.samplesource.remoteinput", "remoteInputSettings"},
    {"RPX100.samplesink.remoteoutput", "remoteOutputSettings"},
    {"RPX100.samplesource.sdrplay", "sdrPlaySettings"},
    {"RPX100.samplesource.sdrplayv3", "sdrPlayV3Settings"},
    {"RPX100.samplesource.sigmffileinput", "sigMFFileInputSettings"},
    {"RPX100.samplesource.soapysdrinput", "soapySDRInputSettings"},
    {"RPX100.samplesink.soapysdroutput", "soapySDROutputSettings"},
    {"RPX100.samplesource.testsource", "testSourceSettings"},
    {"RPX100.samplemimo.testmi", "testMISettings"},
    {"RPX100.samplemimo.testmosync", "testMOSyncSettings"},
    {"RPX100.samplesource.usrp", "usrpInputSettings"},
    {"RPX100.samplesink.usrp", "usrpOutputSettings"},
    {"RPX100.samplesource.xtrx", "xtrxInputSettings"},
    {"RPX100.samplesink.xtrx", "xtrxOutputSettings"},
    {"RPX100.samplemimo.xtrxmimo", "xtrxMIMOSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_channelTypeToSettingsKey = {
    {"ADSBDemod", "ADSBDemodSettings"},
    {"AISDemod", "AISDemodSettings"},
    {"AISMod", "AISModSettings"},
    {"APTDemod", "APTDemodSettings"},
    {"AMDemod", "AMDemodSettings"},
    {"AMMod", "AMModSettings"},
    {"ATVDemod", "ATVDemodSettings"},
    {"ATVMod", "ATVModSettings"},
    {"BFMDemod", "BFMDemodSettings"},
    {"ChannelAnalyzer", "ChannelAnalyzerSettings"},
    {"ChirpChatDemod", "ChirpChatDemodSettings"},
    {"ChirpChatMod", "ChirpChatModSettings"},
    {"DATVDemod", "DATVDemodSettings"},
    {"DATVMod", "DATVModSettings"},
    {"DABDemod", "DABDemodSettings"},
    {"DSDDemod", "DSDDemodSettings"},
    {"FileSink", "FileSinkSettings"},
    {"FileSource", "FileSourceSettings"},
    {"FreeDVDemod", "FreeDVDemodSettings"},
    {"FreeDVMod", "FreeDVModSettings"},
    {"FreqTracker", "FreqTrackerSettings"},
    {"IEEE_802_15_4_Mod", "IEEE_802_15_4_ModSettings"},
    {"NFMDemod", "NFMDemodSettings"},
    {"NFMMod", "NFMModSettings"},
    {"NoiseFigure", "NoiseFigureSettings"},
    {"PacketDemod", "PacketDemodSettings"},
    {"PacketMod", "PacketModSettings"},
    {"PagerDemod", "PagerDemodSettings"},
    {"LocalSink", "LocalSinkSettings"},
    {"LocalSource", "LocalSourceSettings"},
    {"RadioClock", "RadioClockSettings"},
    {"RemoteSink", "RemoteSinkSettings"},
    {"RemoteSource", "RemoteSourceSettings"},
    {"SSBMod", "SSBModSettings"},
    {"SSBDemod", "SSBDemodSettings"},
    {"UDPSink", "UDPSinkSettings"},
    {"UDPSource", "UDPSourceSettings"},
    {"VORDemod", "VORDemodSettings"},
    {"WFMDemod", "WFMDemodSettings"},
    {"WFMMod", "WFMModSettings"},
    {"BeamSteeringCWMod", "BeamSteeringCWModSettings"},
    {"Interferometer", "InterferometerSettings"},
    {"SigMFFileSink", "SigMFFileSinkSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_channelTypeToActionsKey = {
    {"AISMod", "AISModActions"},
    {"APTDemod", "APTDemodActions"},
    {"FileSink", "FileSinkActions"},
    {"FileSource", "FileSourceActions"},
    {"SigMFFileSink", "SigMFFileSinkActions"},
    {"IEEE_802_15_4_Mod", "IEEE_802_15_4_ModActions"},
    {"PacketMod", "PacketModActions"}
};

const QMap<QString, QString> WebAPIUtils::m_sourceDeviceHwIdToSettingsKey = {
    {"Airspy", "airspySettings"},
    {"AirspyHF", "airspyHFSettings"},
    {"AudioInput", "audioInputSettings"},
    {"BladeRF1", "bladeRF1InputSettings"},
    {"BladeRF2", "bladeRF2InputSettings"},
    {"FCDPro", "fcdProSettings"},
    {"FCDPro+", "fcdProPlusSettings"},
    {"FileInput", "fileInputSettings"},
    {"HackRF", "hackRFInputSettings"},
    {"KiwiSDR", "kiwiSDRSettings"},
    {"LimeSDR", "limeSdrInputSettings"},
    {"LocalInput", "localInputSettings"},
    {"Perseus", "perseusSettings"},
    {"PlutoSDR", "plutoSdrInputSettings"},
    {"RTLSDR", "rtlSdrSettings"},
    {"RemoteInput", "remoteInputSettings"},
    {"SDRplay1", "sdrPlaySettings"},
    {"SDRplayV3", "sdrPlayV3Settings"},
    {"SigMFFileInput", "sigMFFileInputSettings"},
    {"SoapySDR", "soapySDRInputSettings"},
    {"TestSource", "testSourceSettings"},
    {"USRP", "usrpInputSettings"},
    {"XTRX", "xtrxInputSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_sourceDeviceHwIdToActionsKey = {
    {"Airspy", "airspyActions"},
    {"AirspyHF", "airspyHFActions"},
    {"AudioInput", "audioInputActions"},
    {"BladeRF1", "bladeRF1InputActions"},
    {"FCDPro", "fcdProActions"},
    {"FCDPro+", "fcdProPlusActions"},
    {"HackRF", "hackRFInputActions"},
    {"KiwiSDR", "kiwiSDRActions"},
    {"LimeSDR", "limeSdrInputActions"},
    {"LocalInput", "localInputActions"},
    {"Perseus", "perseusActions"},
    {"PlutoSDR", "plutoSdrInputActions"},
    {"RemoteInput", "remoteInputActions"},
    {"RTLSDR", "rtlSdrActions"},
    {"SDRplay1", "sdrPlayActions"},
    {"SDRplayV3", "sdrPlayV3Actions"},
    {"SigMFFileInput", "sigMFFileActions"},
    {"SoapySDR", "soapySDRInputActions"},
    {"TestSource", "testSourceActions"},
    {"USRP", "usrpSourceActions"},
    {"XTRX", "xtrxInputActions"}
};

const QMap<QString, QString> WebAPIUtils::m_sinkDeviceHwIdToSettingsKey = {
    {"AudioOutput", "audioOutputSettings"},
    {"BladeRF1", "bladeRF1OutputSettings"},
    {"BladeRF2", "bladeRF2OutputSettings"},
    {"FileOutput", "fileOutputSettings"},
    {"HackRF", "hackRFOutputSettings"},
    {"LimeSDR", "limeSdrOutputSettings"},
    {"LocalOutput", "localOutputSettings"},
    {"PlutoSDR", "plutoSdrOutputSettings"},
    {"RemoteOutput", "remoteOutputSettings"},
    {"SoapySDR", "soapySDROutputSettings"},
    {"USRP", "usrpOutputSettings"},
    {"XTRX", "xtrxOutputSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_sinkDeviceHwIdToActionsKey = {
};

const QMap<QString, QString> WebAPIUtils::m_mimoDeviceHwIdToSettingsKey = {
    {"BladeRF2", "bladeRF2MIMOSettings"},
    {"MetisMISO", "metisMISOSettings"},
    {"TestMI", "testMISettings"},
    {"TestMOSync", "testMOSyncSettings"},
    {"XTRX", "xtrxMIMOSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_mimoDeviceHwIdToActionsKey = {
};

const QMap<QString, QString> WebAPIUtils::m_featureTypeToSettingsKey = {
    {"AIS", "AISSettings"},
    {"AntennaTools", "AntennaToolsSettings"},
    {"APRS", "APRSSettings"},
    {"GS232Controller", "GS232ControllerSettings"},
    {"Map", "MapSettings"},
    {"PERTester", "PERTesterSettings"},
    {"SatelliteTracker", "SatelliteTrackerSettings"},
    {"SimplePTT", "SimplePTTSettings"},
    {"StarTracker", "StarTrackerSettings"},
    {"RigCtlServer", "RigCtlServerSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_featureTypeToActionsKey = {
    {"Map", "MapActions"},
    {"SimplePTT", "SimplePTTActions"}
};

const QMap<QString, QString> WebAPIUtils::m_featureURIToSettingsKey = {
    {"RPX100.feature.ais", "AISSSettings"},
    {"RPX100.feature.antennatools", "AntennaToolsSettings"},
    {"RPX100.feature.aprs", "APRSSettings"},
    {"RPX100.feature.gs232controller", "GS232ControllerSettings"},
    {"RPX100.feature.map", "MapSettings"},
    {"RPX100.feature.pertester", "PERTesterSettings"},
    {"RPX100.feature.satellitetracker", "SatelliteTrackerSettings"},
    {"RPX100.feature.simpleptt", "SimplePTTSettings"},
    {"RPX100.feature.startracker", "StarTrackerSettings"},
    {"RPX100.feature.rigctlserver", "RigCtlServerSettings"}
};

// Get integer value from within JSON object
bool WebAPIUtils::getObjectInt(const QJsonObject &json, const QString &key, int &value)
{
    if (json.contains(key))
    {
        value = json[key].toInt();
        return true;
    }

    return false;
}

// Get string value from within JSON object
bool WebAPIUtils::getObjectString(const QJsonObject &json, const QString &key, QString &value)
{
    if (json.contains(key))
    {
        value = json[key].toString();
        return true;
    }

    return false;
}

// Get a list of JSON objects from within JSON object
bool WebAPIUtils::getObjectObjects(const QJsonObject &json, const QString &key, QList<QJsonObject> &objects)
{
    bool processed = false;

    if (json.contains(key))
    {
        if (json[key].isArray())
        {
            QJsonArray a = json[key].toArray();

            for (QJsonArray::const_iterator  it = a.begin(); it != a.end(); it++)
            {
                if (it->isObject())
                {
                    objects.push_back(it->toObject());
                    processed = true;
                }
            }
        }
    }

    return processed;
}

// Get double value from within nested JSON object
bool WebAPIUtils::getSubObjectDouble(const QJsonObject &json, const QString &key, double &value)
{
    for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
    {
        QJsonValue jsonValue = it.value();

        if (jsonValue.isObject())
        {
            QJsonObject subObject = jsonValue.toObject();

            if (subObject.contains(key))
            {
                value = subObject[key].toDouble();
                return true;
            }
        }
    }

    return false;
}

// Set double value withing nested JSON object
bool WebAPIUtils::setSubObjectDouble(QJsonObject &json, const QString &key, double value)
{
    for (QJsonObject::iterator  it = json.begin(); it != json.end(); it++)
    {
        QJsonValue jsonValue = it.value();

        if (jsonValue.isObject())
        {
            QJsonObject subObject = jsonValue.toObject();

            if (subObject.contains(key))
            {
                subObject[key] = value;
                it.value() = subObject;
                return true;
            }
        }
    }

    return false;
}

// Get integer value from within nested JSON object
bool WebAPIUtils::getSubObjectInt(const QJsonObject &json, const QString &key, int &value)
{
    for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
    {
        QJsonValue jsonValue = it.value();

        if (jsonValue.isObject())
        {
            QJsonObject subObject = jsonValue.toObject();

            if (subObject.contains(key))
            {
                value = subObject[key].toInt();
                return true;
            }
        }
    }

    return false;
}

// Set integer value withing nested JSON object
bool WebAPIUtils::setSubObjectInt(QJsonObject &json, const QString &key, int value)
{
    for (QJsonObject::iterator  it = json.begin(); it != json.end(); it++)
    {
        QJsonValue jsonValue = it.value();

        if (jsonValue.isObject())
        {
            QJsonObject subObject = jsonValue.toObject();

            if (subObject.contains(key))
            {
                subObject[key] = value;
                it.value() = subObject;
                return true;
            }
        }
    }

    return false;
}

// look for value in key=value
bool WebAPIUtils::extractValue(const QJsonObject &json, const QString &key, QJsonValue &value)
{
    // final
    if (json.contains(key))
    {
        value = json[key];
        return true;
    }
    else
    {
        for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
        {
            QJsonValue jsonValue = it.value();

            if (jsonValue.isObject())
            {
                if (extractValue(jsonValue.toObject(), key, value)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// look for [...] in key=[...]
bool WebAPIUtils::extractArray(const QJsonObject &json, const QString &key, QJsonArray &value)
{
    // final
    if (json.contains(key))
    {
        if (json[key].isArray())
        {
            value = json[key].toArray();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
        {
            QJsonValue jsonValue = it.value();

            if (jsonValue.isObject())
            {
                if (extractArray(jsonValue.toObject(), key, value)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// look for {...} in key={...}
bool WebAPIUtils::extractObject(const QJsonObject &json, const QString &key, QJsonObject &value)
{
    // final
    if (json.contains(key))
    {
        if (json[key].isObject())
        {
            value = json[key].toObject();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
        {
            QJsonValue jsonValue = it.value();

            if (jsonValue.isObject())
            {
                if (extractObject(jsonValue.toObject(), key, value)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// set value in key=value
bool WebAPIUtils::setValue(const QJsonObject &json, const QString &key, const QJsonValue &value)
{
    // final
    if (json.contains(key))
    {
        json[key] = value;
        return true;
    }
    else
    {
        for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
        {
            QJsonValue jsonValue = it.value();

            if (jsonValue.isObject())
            {
                if (setValue(jsonValue.toObject(), key, value)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// set [...] in key=[...]
bool WebAPIUtils::setArray(const QJsonObject &json, const QString &key, const QJsonArray &value)
{
    // final
    if (json.contains(key))
    {
        if (json[key].isArray())
        {
            json[key] = value;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
        {
            QJsonValue jsonValue = it.value();

            if (jsonValue.isObject())
            {
                if (setArray(jsonValue.toObject(), key, value)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// set {...} in key={...}
bool WebAPIUtils::setObject(const QJsonObject &json, const QString &key, const QJsonObject &value)
{
    // final
    if (json.contains(key))
    {
        if (json[key].isObject())
        {
            json[key] = value;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (QJsonObject::const_iterator  it = json.begin(); it != json.end(); it++)
        {
            QJsonValue jsonValue = it.value();

            if (jsonValue.isObject())
            {
                if (setObject(jsonValue.toObject(), key, value)) {
                    return true;
                }
            }
        }
    }

    return false;
}
