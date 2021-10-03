///////////////////////////////////////////////////////////////////////////////////
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

#include <QGlobalStatic>
#include <QCoreApplication>
#include <QString>

#include "loggerwithfile.h"
#include "dsp/dsptypes.h"
#include "feature/featureset.h"
#include "feature/feature.h"
#include "device/deviceset.h"
#include "channel/channelapi.h"

#include "maincore.h"

MESSAGE_CLASS_DEFINITION(MainCore::MsgDeviceSetFocus, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgDVSerial, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgDeleteInstance, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgLoadPreset, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgSavePreset, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgDeletePreset, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgLoadFeatureSetPreset, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgSaveFeatureSetPreset, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgDeleteFeatureSetPreset, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgAddDeviceSet, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgRemoveLastDeviceSet, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgAddFeatureSet, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgRemoveLastFeatureSet, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgSetDevice, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgAddChannel, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgDeleteChannel, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgApplySettings, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgAddFeature, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgDeleteFeature, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgChannelReport, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgChannelSettings, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgChannelDemodReport, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgChannelDemodQuery, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgMapItem, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgPacket, Message)
MESSAGE_CLASS_DEFINITION(MainCore::MsgTargetAzimuthElevation, Message)

MainCore::MainCore()
{
	m_masterTimer.setTimerType(Qt::PreciseTimer);
	m_masterTimer.start(50);
}

MainCore::~MainCore()
{}

Q_GLOBAL_STATIC(MainCore, mainCore)
MainCore *MainCore::instance()
{
	return mainCore;
}

void MainCore::setLoggingOptions()
{
    m_logger->setConsoleMinMessageLevel(m_settings.getConsoleMinLogLevel());

    if (m_settings.getUseLogFile())
    {
        qtwebapp::FileLoggerSettings fileLoggerSettings; // default values

        if (m_logger->hasFileLogger()) {
            fileLoggerSettings = m_logger->getFileLoggerSettings(); // values from file logger if it exists
        }

        fileLoggerSettings.fileName = m_settings.getLogFileName(); // put new values
        m_logger->createOrSetFileLogger(fileLoggerSettings, 2000); // create file logger if it does not exist and apply settings in any case
    }

    if (m_logger->hasFileLogger()) {
        m_logger->setFileMinMessageLevel(m_settings.getFileMinLogLevel());
    }

    m_logger->setUseFileLogger(m_settings.getUseLogFile());

    if (m_settings.getUseLogFile())
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
        QString appInfoStr(QString("%1 %2 Qt %3 %4b %5 %6 DSP Rx:%7b Tx:%8b PID %9")
                .arg(QCoreApplication::applicationName())
                .arg(QCoreApplication::applicationVersion())
                .arg(QT_VERSION_STR)
                .arg(QT_POINTER_SIZE*8)
                .arg(QSysInfo::currentCpuArchitecture())
                .arg(QSysInfo::prettyProductName())
                .arg(SDR_RX_SAMP_SZ)
                .arg(SDR_TX_SAMP_SZ)
                .arg(QCoreApplication::applicationPid()));
#else
        QString appInfoStr(QString("%1 %2 Qt %3 %4b DSP Rx:%5b Tx:%6b PID %7")
                .arg(QCoreApplication::applicationName())
                .arg(QCoreApplication::applicationVersion())
                .arg(QT_VERSION_STR)
                .arg(QT_POINTER_SIZE*8)
                .arg(SDR_RX_SAMP_SZ)
                .arg(SDR_RX_SAMP_SZ)
                .arg(QCoreApplication::applicationPid());
 #endif
        m_logger->logToFile(QtInfoMsg, appInfoStr);
    }
}

ChannelAPI *MainCore::getChannel(unsigned int deviceSetIndex, int channelIndex)
{
    if (deviceSetIndex < m_deviceSets.size()) {
        return m_deviceSets[deviceSetIndex]->getChannelAt(channelIndex);
    } else {
        return nullptr;
    }
}

Feature *MainCore::getFeature(unsigned int featureSetIndex, int featureIndex)
{
    if (featureSetIndex < m_featureSets.size()) {
        return m_featureSets[featureSetIndex]->getFeatureAt(featureIndex);
    } else {
        return nullptr;
    }
}

void MainCore::appendFeatureSet()
{
    int newIndex = m_featureSets.size();
    FeatureSet *featureSet = new FeatureSet(newIndex);
    m_featureSets.push_back(featureSet);
    m_featureSetsMap.insert(featureSet, newIndex);
}

void MainCore::removeFeatureSet(unsigned int index)
{
    if (index < m_featureSets.size())
    {
        FeatureSet *featureSet = m_featureSets[index];
        m_featureSetsMap.remove(featureSet);
        m_featureSets.erase(m_featureSets.begin() + index);
    }
}

void MainCore::removeLastFeatureSet()
{
    if (m_featureSets.size() != 0)
    {
        FeatureSet *featureSet = m_featureSets.back();
        m_featureSetsMap.remove(featureSet);
        m_featureSets.pop_back();
    }
}

void MainCore::appendDeviceSet(int deviceType)
{
    int newIndex = m_deviceSets.size();
    DeviceSet *deviceSet = new DeviceSet(newIndex, deviceType);
    m_deviceSets.push_back(deviceSet);
    m_deviceSetsMap.insert(deviceSet, newIndex);
}

void MainCore::removeLastDeviceSet()
{
    if (m_deviceSets.size() != 0)
    {
        DeviceSet *deviceSet = m_deviceSets.back();
        m_deviceSetsMap.remove(deviceSet);
        m_deviceSets.pop_back();
    }
}

void MainCore::addChannelInstance(DeviceSet *deviceSet, ChannelAPI *channelAPI)
{
    m_channelsMap.insert(channelAPI, deviceSet);
    // debugMaps();
}

void MainCore::removeChannelInstanceAt(DeviceSet *deviceSet, int channelIndex)
{
    int deviceSetIndex = m_deviceSetsMap[deviceSet];
    ChannelAPI *channelAPI = m_deviceSets[deviceSetIndex]->getChannelAt(channelIndex);

    if (channelAPI) {
        m_channelsMap.remove(channelAPI);
    }
}

void MainCore::removeChannelInstance(ChannelAPI *channelAPI)
{
    if (channelAPI) {
        m_channelsMap.remove(channelAPI);
    }
}

void MainCore::clearChannels(DeviceSet *deviceSet)
{
    for (int i = 0; i < deviceSet->getNumberOfChannels(); i++)
    {
        ChannelAPI *channelAPI = deviceSet->getChannelAt(i);
        m_channelsMap.remove(channelAPI);
    }
}

void MainCore::addFeatureInstance(FeatureSet *featureSet, Feature *feature)
{
    m_featuresMap.insert(feature, featureSet);
    // debugMaps();
}

void MainCore::removeFeatureInstanceAt(FeatureSet *featureSet, int featureIndex)
{
    int featureSetIndex = m_featureSetsMap[featureSet];
    Feature *feature = m_featureSets[featureSetIndex]->getFeatureAt(featureIndex);

    if (feature) {
        m_featuresMap.remove(feature);
    }
}

void MainCore::removeFeatureInstance(Feature *feature)
{
    if (feature) {
        m_featuresMap.remove(feature);
    }
}

void MainCore::clearFeatures(FeatureSet *featureSet)
{
    for (int i = 0; i < featureSet->getNumberOfFeatures(); i++)
    {
        Feature *feature = featureSet->getFeatureAt(i);
        m_featuresMap.remove(feature);
    }
}

void MainCore::debugMaps()
{
    QMap<DeviceSet*, int>::const_iterator dsIt = m_deviceSetsMap.begin();

    for (; dsIt != m_deviceSetsMap.end(); ++dsIt) {
        qDebug("MainCore::debugMaps: device set %d #%d", dsIt.key()->getIndex(), dsIt.value());
    }

    QMap<FeatureSet*, int>::const_iterator fsIt = m_featureSetsMap.begin();

    for (; fsIt != m_featureSetsMap.end(); ++fsIt) {
        qDebug("MainCore::debugMaps: feature set %d #%d", fsIt.key()->getIndex(), fsIt.value());
    }

    QMap<ChannelAPI*, DeviceSet*>::const_iterator chIt = m_channelsMap.begin();

    for (; chIt != m_channelsMap.end(); ++chIt) {
        qDebug("MainCore::debugMaps: channel ds: %d - %d: %s %s",
            chIt.value()->getIndex(), chIt.key()->getIndexInDeviceSet(), qPrintable(chIt.key()->getURI()), qPrintable(chIt.key()->getName()));
    }

    QMap<Feature*, FeatureSet*>::const_iterator feIt = m_featuresMap.begin();

    for (; feIt != m_featuresMap.end(); ++feIt) {
        qDebug("MainCore::debugMaps: feature fs: %d - %d: %s %s",
            feIt.value()->getIndex(), feIt.key()->getIndexInFeatureSet(), qPrintable(feIt.key()->getURI()), qPrintable(feIt.key()->getName()));
    }
}
