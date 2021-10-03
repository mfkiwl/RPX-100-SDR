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

#ifndef INCLUDE_FEATURE_SATELLITETRACKER_H_
#define INCLUDE_FEATURE_SATELLITETRACKER_H_

#include <QThread>
#include <QNetworkRequest>

#include "feature/feature.h"
#include "util/message.h"
#include "util/httpdownloadmanager.h"

#include "satellitetrackersettings.h"
#include "satnogs.h"

class WebAPIAdapterInterface;
class SatelliteTrackerWorker;
class QNetworkAccessManager;
class QNetworkReply;

namespace SWGRPX100 {
    class SWGDeviceState;
    class SWGSatelliteDeviceSettingsList;
}

class SatelliteTracker : public Feature
{
	Q_OBJECT
public:
    class MsgConfigureSatelliteTracker : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const SatelliteTrackerSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureSatelliteTracker* create(const SatelliteTrackerSettings& settings, bool force) {
            return new MsgConfigureSatelliteTracker(settings, force);
        }

    private:
        SatelliteTrackerSettings m_settings;
        bool m_force;

        MsgConfigureSatelliteTracker(const SatelliteTrackerSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    class MsgStartStop : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        bool getStartStop() const { return m_startStop; }

        static MsgStartStop* create(bool startStop) {
            return new MsgStartStop(startStop);
        }

    protected:
        bool m_startStop;

        MsgStartStop(bool startStop) :
            Message(),
            m_startStop(startStop)
        { }
    };

    class MsgUpdateSatData : public Message {
        MESSAGE_CLASS_DECLARATION

    public:

        static MsgUpdateSatData* create() {
            return new MsgUpdateSatData();
        }

    private:

        MsgUpdateSatData() :
            Message()
        { }
    };

    class MsgSatData : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        QHash<QString, SatNogsSatellite *> getSatellites() { return m_satellites; }

        static MsgSatData* create(QHash<QString, SatNogsSatellite *> satellites) {
            return new MsgSatData(satellites);
        }

    private:
        QHash<QString, SatNogsSatellite *> m_satellites;

        MsgSatData(QHash<QString, SatNogsSatellite *> satellites) :
            Message(),
            m_satellites(satellites)
        { }
    };

    SatelliteTracker(WebAPIAdapterInterface *webAPIAdapterInterface);
    virtual ~SatelliteTracker();
    virtual void destroy() { delete this; }
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) const { id = objectName(); }
    virtual void getTitle(QString& title) const { title = m_settings.m_title; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual int webapiRun(bool run,
            SWGRPX100::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiSettingsGet(
            SWGRPX100::SWGFeatureSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& featureSettingsKeys,
            SWGRPX100::SWGFeatureSettings& response,
            QString& errorMessage);

    static void webapiFormatFeatureSettings(
        SWGRPX100::SWGFeatureSettings& response,
        const SatelliteTrackerSettings& settings);

    static void webapiUpdateFeatureSettings(
            SatelliteTrackerSettings& settings,
            const QStringList& featureSettingsKeys,
            SWGRPX100::SWGFeatureSettings& response);

    static QDateTime currentDateTimeUtc();
    static QDateTime currentDateTime();

    static const char* const m_featureIdURI;
    static const char* const m_featureId;

    bool isUpdatingSatData() { return m_updatingSatData; }

private:
    QThread m_thread;
    SatelliteTrackerWorker *m_worker;
    SatelliteTrackerSettings m_settings;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;
    HttpDownloadManager m_dlm;
    bool m_updatingSatData;
    int m_tleIndex;
    QMutex m_mutex;

    QHash<QString, SatNogsSatellite *> m_satellites;    // Satellites, hashed on name
    QHash<int, SatNogsSatellite *> m_satellitesId;      // Same data as m_satellites, but hashed on id, rather than name
    bool m_firstUpdateSatData;

    void start();
    void stop();
    void applySettings(const SatelliteTrackerSettings& settings, bool force = false);
    void webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const SatelliteTrackerSettings& settings, bool force);

    QString satNogsSatellitesFilename();
    QString satNogsTransmittersFilename();
    QString satNogsTLEFilename();
    QString tleURLToFilename(const QString& string);
    bool parseSatellites(const QByteArray& json);
    bool parseTransmitters(const QByteArray& json);
    bool parseSatNogsTLEs(const QByteArray& json);
    bool parseTxtTLEs(const QByteArray& txt);
    bool readSatData();
    void updateSatData();
    void updateSatellitesReply(QNetworkReply *reply);
    void updateTransmittersReply(QNetworkReply *reply);
    void updateTLEsReply(QNetworkReply *reply);
    static QList<SWGRPX100::SWGSatelliteDeviceSettingsList*>* getSWGSatelliteDeviceSettingsList(const SatelliteTrackerSettings& settings);
    static QHash<QString, QList<SatelliteTrackerSettings::SatelliteDeviceSettings *> *> getSatelliteDeviceSettings(QList<SWGRPX100::SWGSatelliteDeviceSettingsList*>* list);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
    void downloadFinished(const QString& filename, bool success);
};

#endif // INCLUDE_FEATURE_SATELLITETRACKER_H_
