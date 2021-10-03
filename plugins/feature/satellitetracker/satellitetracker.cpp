///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
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

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>

#include "SWGFeatureSettings.h"
#include "SWGFeatureReport.h"
#include "SWGFeatureActions.h"
#include "SWGDeviceState.h"
#include "SWGSatelliteTrackerSettings.h"
#include "SWGSatelliteDeviceSettings.h"

#include "dsp/dspengine.h"
#include "util/httpdownloadmanager.h"

#include "satellitetrackerworker.h"
#include "satellitetracker.h"

MESSAGE_CLASS_DEFINITION(SatelliteTracker::MsgConfigureSatelliteTracker, Message)
MESSAGE_CLASS_DEFINITION(SatelliteTracker::MsgStartStop, Message)
MESSAGE_CLASS_DEFINITION(SatelliteTracker::MsgUpdateSatData, Message)
MESSAGE_CLASS_DEFINITION(SatelliteTracker::MsgSatData, Message)

const char* const SatelliteTracker::m_featureIdURI = "RPX100.feature.satellitetracker";
const char* const SatelliteTracker::m_featureId = "SatelliteTracker";

SatelliteTracker::SatelliteTracker(WebAPIAdapterInterface *webAPIAdapterInterface) :
    Feature(m_featureIdURI, webAPIAdapterInterface),
    m_updatingSatData(false),
    m_tleIndex(0),
    m_firstUpdateSatData(true)
{
    qDebug("SatelliteTracker::SatelliteTracker: webAPIAdapterInterface: %p", webAPIAdapterInterface);
    setObjectName(m_featureId);
    m_worker = new SatelliteTrackerWorker(this, webAPIAdapterInterface);
    m_state = StIdle;
    m_errorMessage = "SatelliteTracker error";
    m_networkManager = new QNetworkAccessManager();
    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(networkManagerFinished(QNetworkReply*)));
    connect(&m_dlm, &HttpDownloadManager::downloadComplete, this, &SatelliteTracker::downloadFinished);

    if (!readSatData())
        updateSatData();
}

SatelliteTracker::~SatelliteTracker()
{
    if (m_worker->isRunning()) {
        stop();
    }

    delete m_worker;
}

void SatelliteTracker::start()
{
    qDebug("SatelliteTracker::start");

    m_worker->reset();
    m_worker->setMessageQueueToFeature(getInputMessageQueue());
    m_worker->setMessageQueueToGUI(getMessageQueueToGUI());
    bool ok = m_worker->startWork();
    m_state = ok ? StRunning : StError;
    m_thread.start();

    m_worker->getInputMessageQueue()->push(SatelliteTrackerWorker::MsgConfigureSatelliteTrackerWorker::create(m_settings, true));
    m_worker->getInputMessageQueue()->push(MsgSatData::create(m_satellites));
}

void SatelliteTracker::stop()
{
    qDebug("SatelliteTracker::stop");
    m_worker->stopWork();
    m_state = StIdle;
    m_thread.quit();
    m_thread.wait();
}

bool SatelliteTracker::handleMessage(const Message& cmd)
{
    if (MsgConfigureSatelliteTracker::match(cmd))
    {
        MsgConfigureSatelliteTracker& cfg = (MsgConfigureSatelliteTracker&) cmd;
        qDebug() << "SatelliteTracker::handleMessage: MsgConfigureSatelliteTracker";
        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else if (MsgStartStop::match(cmd))
    {
        MsgStartStop& cfg = (MsgStartStop&) cmd;
        qDebug() << "SatelliteTracker::handleMessage: MsgStartStop: start:" << cfg.getStartStop();

        if (cfg.getStartStop()) {
            start();
        } else {
            stop();
        }

        return true;
    }
    else if (MsgUpdateSatData::match(cmd))
    {
        // When the GUI first opens, it will make an initial request to update the sats
        // In the first instance, just return the data we've read
        if (m_firstUpdateSatData && (m_satellites.size() > 0))
        {
            if (m_guiMessageQueue)
                m_guiMessageQueue->push(MsgSatData::create(m_satellites));
            m_firstUpdateSatData = false;
        }
        else
            updateSatData();
        return true;
    }
    else
    {
        return false;
    }
}

QByteArray SatelliteTracker::serialize() const
{
    return m_settings.serialize();
}

bool SatelliteTracker::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureSatelliteTracker *msg = MsgConfigureSatelliteTracker::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureSatelliteTracker *msg = MsgConfigureSatelliteTracker::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void SatelliteTracker::applySettings(const SatelliteTrackerSettings& settings, bool force)
{
    bool tlesChanged = false;

    qDebug() << "SatelliteTracker::applySettings:"
            << " m_latitude: " << settings.m_latitude
            << " m_longitude: " << settings.m_longitude
            << " m_heightAboveSeaLevel: " << settings.m_heightAboveSeaLevel
            << " m_target: " << settings.m_target
            << " m_satellites: " << settings.m_satellites
            << " m_tles: " << settings.m_tles
            << " m_dateTime: " << settings.m_dateTime
            << " m_minAOSElevation: " << settings.m_minAOSElevation
            << " m_minPassElevation: " << settings.m_minPassElevation
            << " m_azElUnits: " << settings.m_azElUnits
            << " m_groundTrackPoints: " << settings.m_groundTrackPoints
            << " m_dateFormat: " << settings.m_dateFormat
            << " m_utc: " << settings.m_utc
            << " m_updatePeriod: " << settings.m_updatePeriod
            << " m_dopplerPeriod: " << settings.m_dopplerPeriod
            << " m_defaultFrequency: " << settings.m_defaultFrequency
            << " m_drawOnMap: " << settings.m_drawOnMap
            << " m_autoTarget: " << settings.m_autoTarget
            << " m_aosSpeech: " << settings.m_aosSpeech
            << " m_losSpeech: " << settings.m_losSpeech
            << " m_aosCommand: " << settings.m_aosCommand
            << " m_losCommand: " << settings.m_losCommand
            << " m_predictionPeriod: " << settings.m_predictionPeriod
            << " m_passStartTime: " << settings.m_passStartTime
            << " m_passFinishTime: " << settings.m_passFinishTime
            << " m_deviceSettings: " << settings.m_deviceSettings
            << " m_title: " << settings.m_title
            << " m_rgbColor: " << settings.m_rgbColor
            << " m_useReverseAPI: " << settings.m_useReverseAPI
            << " m_reverseAPIAddress: " << settings.m_reverseAPIAddress
            << " m_reverseAPIPort: " << settings.m_reverseAPIPort
            << " m_reverseAPIFeatureSetIndex: " << settings.m_reverseAPIFeatureSetIndex
            << " m_reverseAPIFeatureIndex: " << settings.m_reverseAPIFeatureIndex
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((m_settings.m_latitude != settings.m_latitude) || force) {
        reverseAPIKeys.append("latitude");
    }
    if ((m_settings.m_longitude != settings.m_longitude) || force) {
        reverseAPIKeys.append("longitude");
    }
    if ((m_settings.m_heightAboveSeaLevel != settings.m_heightAboveSeaLevel) || force) {
        reverseAPIKeys.append("heightAboveSeaLevel");
    }
    if ((m_settings.m_target != settings.m_target) || force) {
        reverseAPIKeys.append("target");
    }
    if ((m_settings.m_satellites != settings.m_satellites) || force) {
        reverseAPIKeys.append("satellites");
    }
    if ((m_settings.m_tles != settings.m_tles) || force) {
        tlesChanged = true;
        reverseAPIKeys.append("tles");
    }
    if ((m_settings.m_dateTime != settings.m_dateTime) || force) {
        reverseAPIKeys.append("dateTime");
    }
    if ((m_settings.m_minAOSElevation != settings.m_minAOSElevation) || force) {
        reverseAPIKeys.append("minAOSElevation");
    }
    if ((m_settings.m_minPassElevation != settings.m_minPassElevation) || force) {
        reverseAPIKeys.append("minPassElevation");
    }
    if ((m_settings.m_azElUnits != settings.m_azElUnits) || force) {
        reverseAPIKeys.append("azElUnits");
    }
    if ((m_settings.m_groundTrackPoints != settings.m_groundTrackPoints) || force) {
        reverseAPIKeys.append("groundTrackPoints");
    }
    if ((m_settings.m_dateFormat != settings.m_dateFormat) || force) {
        reverseAPIKeys.append("dateFormat");
    }
    if ((m_settings.m_utc != settings.m_utc) || force) {
        reverseAPIKeys.append("utc");
    }
    if ((m_settings.m_updatePeriod != settings.m_updatePeriod) || force) {
        reverseAPIKeys.append("updatePeriod");
    }
    if ((m_settings.m_dopplerPeriod != settings.m_dopplerPeriod) || force) {
        reverseAPIKeys.append("dopplerPeriod");
    }
    if ((m_settings.m_defaultFrequency != settings.m_defaultFrequency) || force) {
        reverseAPIKeys.append("defaultFrequency");
    }
    if ((m_settings.m_drawOnMap != settings.m_drawOnMap) || force) {
        reverseAPIKeys.append("drawOnMap");
    }
    if ((m_settings.m_autoTarget != settings.m_autoTarget) || force) {
        reverseAPIKeys.append("autoTarget");
    }
    if ((m_settings.m_aosSpeech != settings.m_aosSpeech) || force) {
        reverseAPIKeys.append("aosSpeech");
    }
    if ((m_settings.m_losSpeech != settings.m_losSpeech) || force) {
        reverseAPIKeys.append("losSpeech");
    }
    if ((m_settings.m_aosCommand != settings.m_aosCommand) || force) {
        reverseAPIKeys.append("aosCommand");
    }
    if ((m_settings.m_losCommand != settings.m_losCommand) || force) {
        reverseAPIKeys.append("losCommand");
    }
    if ((m_settings.m_predictionPeriod != settings.m_predictionPeriod) || force) {
        reverseAPIKeys.append("predictionPeriod");
    }
    if ((m_settings.m_passStartTime != settings.m_passStartTime) || force) {
        reverseAPIKeys.append("passStartTime");
    }
    if ((m_settings.m_passFinishTime != settings.m_passFinishTime) || force) {
        reverseAPIKeys.append("passFinishTime");
    }
    if ((m_settings.m_deviceSettings != settings.m_deviceSettings) || force) {
        reverseAPIKeys.append("deviceSettings");
    }
    if ((m_settings.m_title != settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((m_settings.m_rgbColor != settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }

    SatelliteTrackerWorker::MsgConfigureSatelliteTrackerWorker *msg = SatelliteTrackerWorker::MsgConfigureSatelliteTrackerWorker::create(
        settings, force
    );
    m_worker->getInputMessageQueue()->push(msg);

    if (settings.m_useReverseAPI)
    {
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIFeatureSetIndex != settings.m_reverseAPIFeatureSetIndex) ||
                (m_settings.m_reverseAPIFeatureIndex != settings.m_reverseAPIFeatureIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    m_settings = settings;

    if (tlesChanged)
    {
        // Do we already have the TLE files, or do we need to download them?
        bool existing = true;
        for (int i = 0; i < m_settings.m_tles.size(); i++)
        {
            QFile tlesFile(tleURLToFilename(m_settings.m_tles[i]));
            if (!tlesFile.exists())
            {
                existing = false;
                break;
            }
        }
        if (existing)
            readSatData();
        else
            updateSatData();
    }
}

int SatelliteTracker::webapiRun(bool run,
    SWGRPX100::SWGDeviceState& response,
    QString& errorMessage)
{
    (void) errorMessage;
    getFeatureStateStr(*response.getState());
    MsgStartStop *msg = MsgStartStop::create(run);
    getInputMessageQueue()->push(msg);
    return 202;
}

int SatelliteTracker::webapiSettingsGet(
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setSatelliteTrackerSettings(new SWGRPX100::SWGSatelliteTrackerSettings());
    response.getSatelliteTrackerSettings()->init();
    webapiFormatFeatureSettings(response, m_settings);
    return 200;
}

int SatelliteTracker::webapiSettingsPutPatch(
    bool force,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    SatelliteTrackerSettings settings = m_settings;
    webapiUpdateFeatureSettings(settings, featureSettingsKeys, response);

    MsgConfigureSatelliteTracker *msg = MsgConfigureSatelliteTracker::create(settings, force);
    m_inputMessageQueue.push(msg);

    qDebug("SatelliteTracker::webapiSettingsPutPatch: forward to GUI: %p", m_guiMessageQueue);
    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureSatelliteTracker *msgToGUI = MsgConfigureSatelliteTracker::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatFeatureSettings(response, settings);
    return 200;
}

static QList<QString *> *convertStringListToPtrs(QStringList listIn)
{
    QList<QString *> *listOut = new QList<QString *>();

    for (int i = 0; i < listIn.size(); i++)
        listOut->append(new QString(listIn[i]));

    return listOut;
}

static QStringList convertPtrsToStringList(QList<QString *> *listIn)
{
    QStringList listOut;

    for (int i = 0; i < listIn->size(); i++)
        listOut.append(*listIn->at(i));

    return listOut;
}

// Convert struct SatelliteDeviceSettings to Swagger
QList<SWGRPX100::SWGSatelliteDeviceSettingsList*>* SatelliteTracker::getSWGSatelliteDeviceSettingsList(const SatelliteTrackerSettings& settings)
{
    QList <SWGRPX100::SWGSatelliteDeviceSettingsList*>* deviceSettingsList = new QList<SWGRPX100::SWGSatelliteDeviceSettingsList*>();
    QHashIterator<QString, QList<SatelliteTrackerSettings::SatelliteDeviceSettings *> *> i(settings.m_deviceSettings);
    while (i.hasNext())
    {
        i.next();
        QList<SatelliteTrackerSettings::SatelliteDeviceSettings*>* l = i.value();
        if (l->size() > 0)
        {
            SWGRPX100::SWGSatelliteDeviceSettingsList* dsl = new SWGRPX100::SWGSatelliteDeviceSettingsList();
            dsl->setSatellite(new QString(i.key()));
            QList<SWGRPX100::SWGSatelliteDeviceSettings*>* ds = new QList<SWGRPX100::SWGSatelliteDeviceSettings*>();
            for (int j = 0; j < l->size(); j++)
            {
                SWGRPX100::SWGSatelliteDeviceSettings* deviceSettings = new SWGRPX100::SWGSatelliteDeviceSettings();
                deviceSettings->setDeviceSet(new QString(l->at(j)->m_deviceSet));
                deviceSettings->setPresetGroup(new QString(l->at(j)->m_presetGroup));
                deviceSettings->setPresetDescription(new QString(l->at(j)->m_presetDescription));
                deviceSettings->setPresetFrequency(l->at(j)->m_presetFrequency);
                QList<qint32>* doppler = new QList<qint32>();
                for (int k = 0; k < l->at(j)->m_doppler.size(); k++) {
                    doppler->append(l->at(j)->m_doppler[k]);
                }
                deviceSettings->setDoppler(doppler);
                deviceSettings->setStartOnAos((int)l->at(j)->m_startOnAOS ? 1 : 0);
                deviceSettings->setStopOnLos((int)l->at(j)->m_stopOnLOS ? 1 : 0);
                deviceSettings->setStartStopFileSinks((int)l->at(j)->m_startStopFileSink ? 1 : 0);
                deviceSettings->setFrequency((int)l->at(j)->m_frequency);
                deviceSettings->setAosCommand(new QString(l->at(j)->m_aosCommand));
                deviceSettings->setLosCommand(new QString(l->at(j)->m_losCommand));
                ds->append(deviceSettings);
            }
            dsl->setDeviceSettings(ds);
            deviceSettingsList->append(dsl);
        }
    }
    return deviceSettingsList;
}

// Dereference a potentionally null string
static QString getString(QString *sp)
{
    QString s;
    if (sp != nullptr) {
        s = *sp;
    }
    return s;
}

// Convert Swagger device settings to struct SatelliteDeviceSettings
QHash<QString, QList<SatelliteTrackerSettings::SatelliteDeviceSettings *> *> SatelliteTracker::getSatelliteDeviceSettings(QList<SWGRPX100::SWGSatelliteDeviceSettingsList*>* list)
{
    QHash<QString, QList<SatelliteTrackerSettings::SatelliteDeviceSettings *> *> hash;

    for (int i = 0; i < list->size(); i++)
    {
        SWGRPX100::SWGSatelliteDeviceSettingsList* satList = list->at(i);
        if (satList->getSatellite())
        {
            QString satellite = *satList->getSatellite();
            QList<SWGRPX100::SWGSatelliteDeviceSettings*>* swgDeviceSettingsList = satList->getDeviceSettings();
            if (swgDeviceSettingsList)
            {
                QList<SatelliteTrackerSettings::SatelliteDeviceSettings *> *deviceSettingsList = new QList<SatelliteTrackerSettings::SatelliteDeviceSettings *>();
                for (int j = 0; j < swgDeviceSettingsList->size(); j++)
                {
                    SatelliteTrackerSettings::SatelliteDeviceSettings *deviceSettings = new SatelliteTrackerSettings::SatelliteDeviceSettings();
                    deviceSettings->m_deviceSet = getString(swgDeviceSettingsList->at(j)->getDeviceSet());
                    deviceSettings->m_presetGroup = getString(swgDeviceSettingsList->at(j)->getPresetGroup());
                    deviceSettings->m_presetFrequency = swgDeviceSettingsList->at(j)->getPresetFrequency();
                    deviceSettings->m_presetDescription = getString(swgDeviceSettingsList->at(j)->getPresetDescription());
                    if (swgDeviceSettingsList->at(j)->getDoppler()) {
                        deviceSettings->m_doppler = *swgDeviceSettingsList->at(j)->getDoppler();
                    }
                    deviceSettings->m_startOnAOS = swgDeviceSettingsList->at(j)->getStartOnAos();
                    deviceSettings->m_stopOnLOS = swgDeviceSettingsList->at(j)->getStopOnLos();
                    deviceSettings->m_startStopFileSink = swgDeviceSettingsList->at(j)->getStartStopFileSinks();
                    deviceSettings->m_frequency = swgDeviceSettingsList->at(j)->getFrequency();
                    deviceSettings->m_aosCommand = getString(swgDeviceSettingsList->at(j)->getAosCommand());
                    deviceSettings->m_losCommand = getString(swgDeviceSettingsList->at(j)->getLosCommand());
                    deviceSettingsList->append(deviceSettings);
                }
                hash.insert(satellite, deviceSettingsList);
            }
            else
            {
                qDebug() << "SatelliteTracker::getSatelliteDeviceSettings: No device settings for satellite " << satellite;
            }
        }
        else
        {
            qDebug() << "SatelliteTracker::getSatelliteDeviceSettings: No satellite name in device settings";
        }
    }

    return hash;
}

void SatelliteTracker::webapiFormatFeatureSettings(
    SWGRPX100::SWGFeatureSettings& response,
    const SatelliteTrackerSettings& settings)
{
    response.getSatelliteTrackerSettings()->setLatitude(settings.m_latitude);
    response.getSatelliteTrackerSettings()->setLongitude(settings.m_longitude);
    response.getSatelliteTrackerSettings()->setHeightAboveSeaLevel(settings.m_heightAboveSeaLevel);
    response.getSatelliteTrackerSettings()->setTarget(new QString(settings.m_target));
    response.getSatelliteTrackerSettings()->setSatellites(convertStringListToPtrs(settings.m_satellites));
    response.getSatelliteTrackerSettings()->setTles(convertStringListToPtrs(settings.m_tles));
    response.getSatelliteTrackerSettings()->setDateTime(new QString(settings.m_dateTime));
    response.getSatelliteTrackerSettings()->setMinAosElevation(settings.m_minAOSElevation);
    response.getSatelliteTrackerSettings()->setMinPassElevation(settings.m_minPassElevation);
    response.getSatelliteTrackerSettings()->setRotatorMaxAzimuth(settings.m_rotatorMaxAzimuth);
    response.getSatelliteTrackerSettings()->setRotatorMaxElevation(settings.m_rotatorMaxElevation);
    response.getSatelliteTrackerSettings()->setAzElUnits((int)settings.m_azElUnits);
    response.getSatelliteTrackerSettings()->setGroundTrackPoints(settings.m_groundTrackPoints);
    response.getSatelliteTrackerSettings()->setDateFormat(new QString(settings.m_dateFormat));
    response.getSatelliteTrackerSettings()->setUtc(settings.m_utc ? 1 : 0);
    response.getSatelliteTrackerSettings()->setUpdatePeriod(settings.m_updatePeriod);
    response.getSatelliteTrackerSettings()->setDopplerPeriod(settings.m_dopplerPeriod);
    response.getSatelliteTrackerSettings()->setDefaultFrequency(settings.m_defaultFrequency);
    response.getSatelliteTrackerSettings()->setDrawOnMap(settings.m_drawOnMap ? 1 : 0);
    response.getSatelliteTrackerSettings()->setAutoTarget(settings.m_autoTarget ? 1 : 0);
    response.getSatelliteTrackerSettings()->setAosSpeech(new QString(settings.m_aosSpeech));
    response.getSatelliteTrackerSettings()->setLosSpeech(new QString(settings.m_losSpeech));
    response.getSatelliteTrackerSettings()->setAosCommand(new QString(settings.m_aosCommand));
    response.getSatelliteTrackerSettings()->setLosCommand(new QString(settings.m_losCommand));
    response.getSatelliteTrackerSettings()->setPredictionPeriod(settings.m_predictionPeriod);
    response.getSatelliteTrackerSettings()->setPassStartTime(new QString(settings.m_passStartTime.toString()));
    response.getSatelliteTrackerSettings()->setPassFinishTime(new QString(settings.m_passFinishTime.toString()));
    response.getSatelliteTrackerSettings()->setDeviceSettings(getSWGSatelliteDeviceSettingsList(settings));

    if (response.getSatelliteTrackerSettings()->getTitle()) {
        *response.getSatelliteTrackerSettings()->getTitle() = settings.m_title;
    } else {
        response.getSatelliteTrackerSettings()->setTitle(new QString(settings.m_title));
    }

    response.getSatelliteTrackerSettings()->setRgbColor(settings.m_rgbColor);
    response.getSatelliteTrackerSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getSatelliteTrackerSettings()->getReverseApiAddress()) {
        *response.getSatelliteTrackerSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getSatelliteTrackerSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getSatelliteTrackerSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getSatelliteTrackerSettings()->setReverseApiFeatureSetIndex(settings.m_reverseAPIFeatureSetIndex);
    response.getSatelliteTrackerSettings()->setReverseApiFeatureIndex(settings.m_reverseAPIFeatureIndex);
}

void SatelliteTracker::webapiUpdateFeatureSettings(
    SatelliteTrackerSettings& settings,
    const QStringList& featureSettingsKeys,
    SWGRPX100::SWGFeatureSettings& response)
{
    if (featureSettingsKeys.contains("latitude")) {
        settings.m_latitude = response.getSatelliteTrackerSettings()->getLatitude();
    }
    if (featureSettingsKeys.contains("longitude")) {
        settings.m_longitude = response.getSatelliteTrackerSettings()->getLongitude();
    }
    if (featureSettingsKeys.contains("heightAboveSeaLevel")) {
        settings.m_heightAboveSeaLevel = response.getSatelliteTrackerSettings()->getHeightAboveSeaLevel();
    }
    if (featureSettingsKeys.contains("target")) {
        settings.m_target = *response.getSatelliteTrackerSettings()->getTarget();
    }
    if (featureSettingsKeys.contains("satellites")) {
        settings.m_satellites = convertPtrsToStringList(response.getSatelliteTrackerSettings()->getSatellites());
    }
    if (featureSettingsKeys.contains("tles")) {
        settings.m_tles = convertPtrsToStringList(response.getSatelliteTrackerSettings()->getTles());
    }
    if (featureSettingsKeys.contains("dateTime")) {
        settings.m_dateTime = *response.getSatelliteTrackerSettings()->getDateTime();
    }
    if (featureSettingsKeys.contains("minAOSElevation")) {
        settings.m_minAOSElevation = response.getSatelliteTrackerSettings()->getMinAosElevation();
    }
    if (featureSettingsKeys.contains("minPassElevation")) {
        settings.m_minPassElevation = response.getSatelliteTrackerSettings()->getMinPassElevation();
    }
    if (featureSettingsKeys.contains("rotatorMaxAzimuth")) {
        settings.m_rotatorMaxAzimuth = response.getSatelliteTrackerSettings()->getRotatorMaxAzimuth();
    }
    if (featureSettingsKeys.contains("rotatorMaxElevation")) {
        settings.m_rotatorMaxElevation = response.getSatelliteTrackerSettings()->getRotatorMaxElevation();
    }
    if (featureSettingsKeys.contains("azElUnits")) {
        settings.m_azElUnits = (SatelliteTrackerSettings::AzElUnits)response.getSatelliteTrackerSettings()->getAzElUnits();
    }
    if (featureSettingsKeys.contains("groundTrackPoints")) {
        settings.m_groundTrackPoints = response.getSatelliteTrackerSettings()->getGroundTrackPoints();
    }
    if (featureSettingsKeys.contains("dateFormat")) {
        settings.m_dateFormat = *response.getSatelliteTrackerSettings()->getDateFormat();
    }
    if (featureSettingsKeys.contains("utc")) {
        settings.m_utc = response.getSatelliteTrackerSettings()->getUtc() != 0;
    }
    if (featureSettingsKeys.contains("updatePeriod")) {
        settings.m_updatePeriod = response.getSatelliteTrackerSettings()->getUpdatePeriod();
    }
    if (featureSettingsKeys.contains("dopplerPeriod")) {
        settings.m_dopplerPeriod = response.getSatelliteTrackerSettings()->getDopplerPeriod();
    }
    if (featureSettingsKeys.contains("defaultFrequency")) {
        settings.m_defaultFrequency = response.getSatelliteTrackerSettings()->getDefaultFrequency();
    }
    if (featureSettingsKeys.contains("drawOnMap")) {
        settings.m_drawOnMap = response.getSatelliteTrackerSettings()->getDrawOnMap() != 0;
    }
    if (featureSettingsKeys.contains("autoTarget")) {
        settings.m_autoTarget = response.getSatelliteTrackerSettings()->getAutoTarget() != 0;
    }
    if (featureSettingsKeys.contains("aosSpeech")) {
        settings.m_aosSpeech = *response.getSatelliteTrackerSettings()->getAosSpeech();
    }
    if (featureSettingsKeys.contains("losSpeech")) {
        settings.m_losSpeech = *response.getSatelliteTrackerSettings()->getLosSpeech();
    }
    if (featureSettingsKeys.contains("aosCommand")) {
        settings.m_aosCommand = *response.getSatelliteTrackerSettings()->getAosCommand();
    }
    if (featureSettingsKeys.contains("losCommand")) {
        settings.m_losCommand = *response.getSatelliteTrackerSettings()->getLosCommand();
    }
    if (featureSettingsKeys.contains("predictionPeriod")) {
        settings.m_predictionPeriod = response.getSatelliteTrackerSettings()->getPredictionPeriod();
    }
    if (featureSettingsKeys.contains("passStartTime")) {
        settings.m_passStartTime = QTime::fromString(*response.getSatelliteTrackerSettings()->getPassStartTime());
    }
    if (featureSettingsKeys.contains("passFinishTime")) {
        settings.m_passFinishTime = QTime::fromString(*response.getSatelliteTrackerSettings()->getPassFinishTime());
    }
    if (featureSettingsKeys.contains("deviceSettings")) {
        settings.m_deviceSettings = getSatelliteDeviceSettings(response.getSatelliteTrackerSettings()->getDeviceSettings());
    }
    if (featureSettingsKeys.contains("title")) {
        settings.m_title = *response.getSatelliteTrackerSettings()->getTitle();
    }
    if (featureSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getSatelliteTrackerSettings()->getRgbColor();
    }
    if (featureSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getSatelliteTrackerSettings()->getUseReverseApi() != 0;
    }
    if (featureSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getSatelliteTrackerSettings()->getReverseApiAddress();
    }
    if (featureSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getSatelliteTrackerSettings()->getReverseApiPort();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureSetIndex")) {
        settings.m_reverseAPIFeatureSetIndex = response.getSatelliteTrackerSettings()->getReverseApiFeatureSetIndex();
    }
    if (featureSettingsKeys.contains("reverseAPIFeatureIndex")) {
        settings.m_reverseAPIFeatureIndex = response.getSatelliteTrackerSettings()->getReverseApiFeatureIndex();
    }
}

void SatelliteTracker::webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const SatelliteTrackerSettings& settings, bool force)
{
    SWGRPX100::SWGFeatureSettings *swgFeatureSettings = new SWGRPX100::SWGFeatureSettings();
    // swgFeatureSettings->setOriginatorFeatureIndex(getIndexInDeviceSet());
    // swgFeatureSettings->setOriginatorFeatureSetIndex(getDeviceSetIndex());
    swgFeatureSettings->setFeatureType(new QString("SatelliteTracker"));
    swgFeatureSettings->setSatelliteTrackerSettings(new SWGRPX100::SWGSatelliteTrackerSettings());
    SWGRPX100::SWGSatelliteTrackerSettings *swgSatelliteTrackerSettings = swgFeatureSettings->getSatelliteTrackerSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (featureSettingsKeys.contains("latitude") || force) {
        swgSatelliteTrackerSettings->setLatitude(settings.m_latitude);
    }
    if (featureSettingsKeys.contains("longitude") || force) {
        swgSatelliteTrackerSettings->setLongitude(settings.m_longitude);
    }
    if (featureSettingsKeys.contains("heightAboveSeaLevel") || force) {
        swgSatelliteTrackerSettings->setHeightAboveSeaLevel(settings.m_heightAboveSeaLevel);
    }
    if (featureSettingsKeys.contains("target") || force) {
        swgSatelliteTrackerSettings->setTarget(new QString(settings.m_target));
    }
    if (featureSettingsKeys.contains("satellites") || force) {
        swgSatelliteTrackerSettings->setSatellites(convertStringListToPtrs(settings.m_satellites));
    }
    if (featureSettingsKeys.contains("tles") || force) {
        swgSatelliteTrackerSettings->setTles(convertStringListToPtrs(settings.m_satellites));
    }
    if (featureSettingsKeys.contains("dateTime") || force) {
        swgSatelliteTrackerSettings->setDateTime(new QString(settings.m_dateTime));
    }
    if (featureSettingsKeys.contains("minAOSElevation") || force) {
        swgSatelliteTrackerSettings->setMinAosElevation(settings.m_minAOSElevation);
    }
    if (featureSettingsKeys.contains("minPassElevation") || force) {
        swgSatelliteTrackerSettings->setMinPassElevation(settings.m_minPassElevation);
    }
    if (featureSettingsKeys.contains("azElUnits") || force) {
        swgSatelliteTrackerSettings->setAzElUnits((int)settings.m_azElUnits);
    }
    if (featureSettingsKeys.contains("groundTrackPoints") || force) {
        swgSatelliteTrackerSettings->setGroundTrackPoints(settings.m_groundTrackPoints);
    }
    if (featureSettingsKeys.contains("dateFormat") || force) {
        swgSatelliteTrackerSettings->setDateFormat(new QString(settings.m_dateFormat));
    }
    if (featureSettingsKeys.contains("utc") || force) {
        swgSatelliteTrackerSettings->setUtc(settings.m_utc);
    }
    if (featureSettingsKeys.contains("updatePeriod") || force) {
        swgSatelliteTrackerSettings->setUpdatePeriod(settings.m_updatePeriod);
    }
    if (featureSettingsKeys.contains("dopplerPeriod") || force) {
        swgSatelliteTrackerSettings->setDopplerPeriod(settings.m_dopplerPeriod);
    }
    if (featureSettingsKeys.contains("defaultFrequency") || force) {
        swgSatelliteTrackerSettings->setDefaultFrequency(settings.m_defaultFrequency);
    }
    if (featureSettingsKeys.contains("drawOnMap") || force) {
        swgSatelliteTrackerSettings->setDrawOnMap(settings.m_drawOnMap);
    }
    if (featureSettingsKeys.contains("aosSpeech") || force) {
        swgSatelliteTrackerSettings->setAosSpeech(new QString(settings.m_aosSpeech));
    }
    if (featureSettingsKeys.contains("losSpeech") || force) {
        swgSatelliteTrackerSettings->setLosSpeech(new QString(settings.m_losSpeech));
    }
    if (featureSettingsKeys.contains("aosCommand") || force) {
        swgSatelliteTrackerSettings->setAosCommand(new QString(settings.m_aosCommand));
    }
    if (featureSettingsKeys.contains("losCommand") || force) {
        swgSatelliteTrackerSettings->setLosCommand(new QString(settings.m_losCommand));
    }
    if (featureSettingsKeys.contains("predictionPeriod") || force) {
        swgSatelliteTrackerSettings->setPredictionPeriod(settings.m_predictionPeriod);
    }
    if (featureSettingsKeys.contains("passStartTime") || force) {
        swgSatelliteTrackerSettings->setPassStartTime(new QString(settings.m_passStartTime.toString()));
    }
    if (featureSettingsKeys.contains("passFinishTime") || force) {
        swgSatelliteTrackerSettings->setPassFinishTime(new QString(settings.m_passFinishTime.toString()));
    }
    if (featureSettingsKeys.contains("deviceSettings") || force) {
        swgSatelliteTrackerSettings->setDeviceSettings(getSWGSatelliteDeviceSettingsList(settings));
    }
    if (featureSettingsKeys.contains("title") || force) {
        swgSatelliteTrackerSettings->setTitle(new QString(settings.m_title));
    }
    if (featureSettingsKeys.contains("rgbColor") || force) {
        swgSatelliteTrackerSettings->setRgbColor(settings.m_rgbColor);
    }

    QString channelSettingsURL = QString("http://%1:%2/RPX100/featureset/%3/feature/%4/settings")
            .arg(settings.m_reverseAPIAddress)
            .arg(settings.m_reverseAPIPort)
            .arg(settings.m_reverseAPIFeatureSetIndex)
            .arg(settings.m_reverseAPIFeatureIndex);
    m_networkRequest.setUrl(QUrl(channelSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgFeatureSettings->asJson().toUtf8());
    buffer->seek(0);

    // Always use PATCH to avoid passing reverse API settings
    QNetworkReply *reply = m_networkManager->sendCustomRequest(m_networkRequest, "PATCH", buffer);
    buffer->setParent(reply);

    delete swgFeatureSettings;
}

void SatelliteTracker::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "SatelliteTracker::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("SatelliteTracker::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

QString SatelliteTracker::satNogsSatellitesFilename()
{
    return HttpDownloadManager::downloadDir() + "/satnogs_satellites.json";
}

QString SatelliteTracker::satNogsTransmittersFilename()
{
    return HttpDownloadManager::downloadDir() + "/satnogs_transmitters.json";
}

QString SatelliteTracker::satNogsTLEFilename()
{
    return HttpDownloadManager::downloadDir() + "/satnogs_tle.json";
}

QString SatelliteTracker::tleURLToFilename(const QString& string)
{
    if (string == "https://db.satnogs.org/api/tle/")
        return satNogsTLEFilename();
    QUrl url(string);
    return HttpDownloadManager::downloadDir() + "/tle_" + url.fileName();
}

void SatelliteTracker::downloadFinished(const QString& filename, bool success)
{
    if (success)
    {
        if (filename == satNogsSatellitesFilename())
        {
            m_dlm.download(QUrl("https://db.satnogs.org/api/transmitters/"), satNogsTransmittersFilename());
        }
        else if (filename == satNogsTransmittersFilename())
        {
            m_tleIndex = 0;
            if (m_settings.m_tles.size() > 0)
                m_dlm.download(QUrl(m_settings.m_tles[0]), tleURLToFilename(m_settings.m_tles[0]));
            else
                qWarning() << "Satellite Tracker: No TLEs";
        }
        else if ((m_tleIndex < m_settings.m_tles.size()) && (filename == tleURLToFilename(m_settings.m_tles[m_tleIndex])))
        {
            m_tleIndex++;
            if (m_tleIndex < m_settings.m_tles.size())
                m_dlm.download(QUrl(m_settings.m_tles[m_tleIndex]), tleURLToFilename(m_settings.m_tles[m_tleIndex]));
            else
            {
                readSatData();
                m_updatingSatData = false;
            }
        }
        else
            qDebug() << "SatelliteTracker::downloadFinished: Unexpected filename: " << filename;
    }
    else
        m_updatingSatData = false;
}

bool SatelliteTracker::readSatData()
{
    QFile satsFile(satNogsSatellitesFilename());
    if (satsFile.open(QIODevice::ReadOnly))
    {
        if (parseSatellites(satsFile.readAll()))
        {
            QFile transmittersFile(satNogsTransmittersFilename());
            if (transmittersFile.open(QIODevice::ReadOnly))
            {
                if (parseTransmitters(transmittersFile.readAll()))
                {
                    for (int i = 0; i < m_settings.m_tles.size(); i++)
                    {
                        QFile tlesFile(tleURLToFilename(m_settings.m_tles[i]));
                        if (tlesFile.open(QIODevice::ReadOnly))
                        {
                            bool ok;
                            if (tlesFile.fileName() == satNogsTLEFilename())
                            {
                                ok = parseSatNogsTLEs(tlesFile.readAll());
                            }
                            else
                                ok = parseTxtTLEs(tlesFile.readAll());
                            if (!ok)
                                qDebug() << "SatelliteTracker::readSatData - failed to parse: " << tlesFile.fileName();
                        }
                        else
                            qDebug() << "SatelliteTracker::readSatData - failed to open: " << tlesFile.fileName();
                    }

                    qDebug() << "SatelliteTracker::readSatData - read " << m_satellites.size() << " satellites";

                    // Send to GUI
                    if (m_guiMessageQueue)
                        m_guiMessageQueue->push(MsgSatData::create(m_satellites));
                    // Send to worker
                    m_worker->getInputMessageQueue()->push(MsgSatData::create(m_satellites));

                    return true;
                }
            }
        }
    }
    qDebug() << "SatelliteTracker::readSatData - Failed to read satellites";
    return false;
}

bool SatelliteTracker::parseSatellites(const QByteArray& json)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(json);

    if (jsonResponse.isArray())
    {
        m_satellites = SatNogsSatellite::createHash(jsonResponse.array());
        m_satellitesId.clear();

        // Create second table, hashed on ID
        QHashIterator<QString, SatNogsSatellite *> i(m_satellites);
        while (i.hasNext())
        {
            i.next();
            SatNogsSatellite *sat = i.value();
            m_satellitesId.insert(sat->m_noradCatId, sat);
        }
        return true;
    }
    else
        return false;
}

bool SatelliteTracker::parseTransmitters(const QByteArray& json)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(json);

    if (jsonResponse.isArray())
    {
        QList<SatNogsTransmitter *> transmitters = SatNogsTransmitter::createList(jsonResponse.array());

        QHashIterator<QString, SatNogsSatellite *> i(m_satellites);
        while (i.hasNext())
        {
            i.next();
            SatNogsSatellite *sat = i.value();
            sat->addTransmitters(transmitters);
        }
        return true;
    }
    else
        return false;
}

bool SatelliteTracker::parseSatNogsTLEs(const QByteArray& json)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(json);

    if (jsonResponse.isArray())
    {
        QList<SatNogsTLE *> tles = SatNogsTLE::createList(jsonResponse.array());

        QHashIterator<QString, SatNogsSatellite *> i(m_satellites);
        while (i.hasNext())
        {
            i.next();
            SatNogsSatellite *sat = i.value();
            sat->addTLE(tles);
        }
        return true;
    }
    else
        return false;
}

bool SatelliteTracker::parseTxtTLEs(const QByteArray& txt)
{
    QList<SatNogsTLE *> tles = SatNogsTLE::createList(txt);

    QHashIterator<QString, SatNogsSatellite *> i(m_satellites);
    while (i.hasNext())
    {
        i.next();
        SatNogsSatellite *sat = i.value();
        sat->addTLE(tles);
    }

    // Create satellites, that we have TLEs for, but no existing entry
    for (int i = 0; i < tles.size(); i++)
    {
        if (!m_satellitesId.contains(tles[i]->m_noradCatId))
        {
            SatNogsSatellite *sat = new SatNogsSatellite(tles[i]);
            m_satellites.insert(sat->m_name, sat);
            m_satellitesId.insert(sat->m_noradCatId, sat);
        }
    }

    return true;
}

void SatelliteTracker::updateSatData()
{
    QMutexLocker mutexLocker(&m_mutex);

    if (m_updatingSatData == false)
    {
        m_updatingSatData = true;
        qDebug() << "SatelliteTracker::updateSatData: requesting satellites";
        m_dlm.download(QUrl("https://db.satnogs.org/api/satellites/"), satNogsSatellitesFilename());
    }
    else
        qDebug() << "SatelliteTracker::updateSatData: update in progress";
}

// Redirect requests for current time via these methods, so it can be adjusted when testing

QDateTime SatelliteTracker::currentDateTimeUtc()
{
    QDateTime now = QDateTime::currentDateTimeUtc();
    //now = now.addSecs(26*60);
    return now;
}

QDateTime SatelliteTracker::currentDateTime()
{
    QDateTime now = QDateTime::currentDateTime();
    //now = now.addSecs(26*60);
    return now;
}
