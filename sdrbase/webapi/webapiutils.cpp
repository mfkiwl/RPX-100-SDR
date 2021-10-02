///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#include <QJsonArray>
#include <QList>

#include "webapiutils.h"

const QMap<QString, QString> WebAPIUtils::m_channelURIToSettingsKey = {
    {"rpx-100.channel.adsbdemod", "ADSBDemodSettings"},
    {"rpx-100.channel.modais", "AISModSettings"},
    {"rpx-100.channel.aisdemod", "AISDemodSettings"},
    {"rpx-100.channel.aptdemod", "APTDemodSettings"},
    {"rpx-100.channel.amdemod", "AMDemodSettings"},
    {"rpx-100.channel.aptdemod", "APTDemodSettings"},
    {"de.maintech.rpx-100ove.channel.am", "AMDemodSettings"}, // remap
    {"rpx-100.channeltx.modam", "AMModSettings"},
    {"rpx-100.channeltx.modatv", "ATVModSettings"},
    {"rpx-100.channeltx.moddatv", "DATVModSettings"},
    {"rpx-100.channel.bfm", "BFMDemodSettings"},
    {"rpx-100.channel.chanalyzer", "ChannelAnalyzerSettings"},
    {"rpx-100.channel.chanalyzerng", "ChannelAnalyzerSettings"}, // remap
    {"org.f4exb.rpx-100ove.channel.chanalyzer", "ChannelAnalyzerSettings"}, // remap
    {"rpx-100.channel.chirpchatdemod", "ChirpChatDemodSettings"},
    {"rpx-100.channel.modchirpchat", "ChirpChatModSettings"},
    {"rpx-100.channel.demodatv", "ATVDemodSettings"},
    {"rpx-100.channel.demoddatv", "DATVDemodSettings"},
    {"rpx-100.channel.dabdemod", "DABDemodSettings"},
    {"rpx-100.channel.dsddemod", "DSDDemodSettings"},
    {"rpx-100.channel.filesink", "FileSinkSettings"},
    {"rpx-100.channeltx.filesource", "FileSourceSettings"},
    {"rpx-100.channel.freedvdemod", "FreeDVDemodSettings"},
    {"rpx-100.channeltx.freedvmod", "FreeDVModSettings"},
    {"rpx-100.channel.freqtracker", "FreqTrackerSettings"},
    {"rpx-100.channel.nfmdemod", "NFMDemodSettings"},
    {"de.maintech.rpx-100ove.channel.nfm", "NFMDemodSettings"}, // remap
    {"rpx-100.channeltx.modnfm", "NFMModSettings"},
    {"rpx-100.channel.noisefigure", "NoiseFigureSettings"},
    {"rpx-100.demod.localsink", "LocalSinkSettings"},
    {"rpx-100.channel.localsink", "LocalSinkSettings"}, // remap
    {"rpx-100.channel.localsource", "LocalSourceSettings"},
    {"rpx-100.channel.packetdemod", "PacketDemodSettings"},
    {"rpx-100.channel.pagerdemod", "PagerDemodSettings"},
    {"rpx-100.channeltx.modpacket", "PacketModSettings"},
    {"rpx-100.channeltx.mod802.15.4", "IEEE_802_15_4_ModSettings"},
    {"rpx-100.channel.radioclock", "RadioClockSettings"},
    {"rpx-100.demod.remotesink", "RemoteSinkSettings"},
    {"rpx-100.channeltx.remotesource", "RemoteSourceSettings"},
    {"rpx-100.channeltx.modssb", "SSBModSettings"},
    {"rpx-100.channel.ssbdemod", "SSBDemodSettings"},
    {"de.maintech.rpx-100ove.channel.ssb", "SSBDemodSettings"}, // remap
    {"rpx-100.channeltx.udpsource", "UDPSourceSettings"},
    {"rpx-100.channeltx.udpsink", "UDPSinkSettings"}, // remap
    {"rpx-100.channel.udpsink", "UDPSinkSettings"},
    {"rpx-100.channel.udpsrc", "UDPSourceSettings"}, // remap
    {"rpx-100.channel.vordemod", "VORDemodSettings"},
    {"rpx-100.channel.wfmdemod", "WFMDemodSettings"},
    {"de.maintech.rpx-100ove.channel.wfm", "WFMDemodSettings"}, // remap
    {"rpx-100.channeltx.modwfm", "WFMModSettings"},
    {"rpx-100.channel.beamsteeringcwmod", "BeamSteeringCWModSettings"},
    {"rpx-100.channelmimo.interferometer", "InterferometerSettings"},
    {"rpx-100.channel.sigmffilesink", "SigMFFileSinkSettings"}
};

const QMap<QString, QString> WebAPIUtils::m_deviceIdToSettingsKey = {
    {"rpx-100.samplesource.airspy", "airspySettings"},
    {"rpx-100.samplesource.airspyhf", "airspyHFSettings"},
    {"rpx-100.samplesource.audioinput", "audioInputSettings"},
    {"rpx-100.samplesink.audiooutput", "audioOutputSettings"},
    {"rpx-100.samplesource.bladerf1input", "bladeRF1InputSettings"},
    {"rpx-100.samplesource.bladerf", "bladeRF1InputSettings"}, // remap
    {"rpx-100.samplesink.bladerf1output", "bladeRF1OutputSettings"},
    {"rpx-100.samplesource.bladerf1output", "bladeRF1OutputSettings"}, // remap
    {"rpx-100.samplesource.bladerfoutput", "bladeRF1OutputSettings"}, // remap
    {"rpx-100.samplesource.bladerf2input", "bladeRF2InputSettings"},
    {"rpx-100.samplesink.bladerf2output", "bladeRF2OutputSettings"},
    {"rpx-100.samplesource.bladerf2output", "bladeRF2OutputSettings"}, // remap
    {"rpx-100.samplemimo.bladerf2mimo", "bladeRF2MIMOSettings"},
    {"rpx-100.samplesource.fcdpro", "fcdProSettings"},
    {"rpx-100.samplesource.fcdproplus", "fcdProPlusSettings"},
    {"rpx-100.samplesource.fileinput", "fileInputSettings"},
    {"rpx-100.samplesource.filesource", "fileInputSettings"}, // remap
    {"rpx-100.samplesource.hackrf", "hackRFInputSettings"},
    {"rpx-100.samplesink.hackrf", "hackRFOutputSettings"},
    {"rpx-100.samplesource.hackrfoutput", "hackRFOutputSettings"}, // remap
    {"rpx-100.samplesource.kiwisdrsource", "kiwiSDRSettings"},
    {"rpx-100.samplesource.limesdr", "limeSdrInputSettings"},
    {"rpx-100.samplesink.limesdr", "limeSdrOutputSettings"},
    {"rpx-100.samplesource.localinput", "localInputSettings"},
    {"rpx-100.samplesink.localoutput", "localOutputSettings"},
    {"rpx-100.samplesource.localoutput", "localOutputSettings"}, // remap
    {"rpx-100.samplemimo.metismiso", "metisMISOSettings"},
    {"rpx-100.samplesource.perseus", "perseusSettings"},
    {"rpx-100.samplesource.plutosdr", "plutoSdrInputSettings"},
    {"rpx-100.samplesink.plutosdr", "plutoSdrOutputSettings"},
    {"rpx-100.samplesource.rtlsdr", "rtlSdrSettings"},
    {"rpx-100.samplesource.remoteinput", "remoteInputSettings"},
    {"rpx-100.samplesink.remoteoutput", "remoteOutputSettings"},
    {"rpx-100.samplesource.sdrplay", "sdrPlaySettings"},
    {"rpx-100.samplesource.sdrplayv3", "sdrPlayV3Settings"},
    {"rpx-100.samplesource.sigmffileinput", "sigMFFileInputSettings"},
    {"rpx-100.samplesource.soapysdrinput", "soapySDRInputSettings"},
    {"rpx-100.samplesink.soapysdroutput", "soapySDROutputSettings"},
    {"rpx-100.samplesource.testsource", "testSourceSettings"},
    {"rpx-100.samplemimo.testmi", "testMISettings"},
    {"rpx-100.samplemimo.testmosync", "testMOSyncSettings"},
    {"rpx-100.samplesource.usrp", "usrpInputSettings"},
    {"rpx-100.samplesink.usrp", "usrpOutputSettings"},
    {"rpx-100.samplesource.xtrx", "xtrxInputSettings"},
    {"rpx-100.samplesink.xtrx", "xtrxOutputSettings"},
    {"rpx-100.samplemimo.xtrxmimo", "xtrxMIMOSettings"}
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
    {"rpx-100.feature.ais", "AISSSettings"},
    {"rpx-100.feature.antennatools", "AntennaToolsSettings"},
    {"rpx-100.feature.aprs", "APRSSettings"},
    {"rpx-100.feature.gs232controller", "GS232ControllerSettings"},
    {"rpx-100.feature.map", "MapSettings"},
    {"rpx-100.feature.pertester", "PERTesterSettings"},
    {"rpx-100.feature.satellitetracker", "SatelliteTrackerSettings"},
    {"rpx-100.feature.simpleptt", "SimplePTTSettings"},
    {"rpx-100.feature.startracker", "StarTrackerSettings"},
    {"rpx-100.feature.rigctlserver", "RigCtlServerSettings"}
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
