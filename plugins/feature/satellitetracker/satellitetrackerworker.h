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

#ifndef INCLUDE_FEATURE_SATELLITETRACKERWORKER_H_
#define INCLUDE_FEATURE_SATELLITETRACKERWORKER_H_

#include <QObject>
#include <QTimer>
#include <QAbstractSocket>

#include "util/message.h"
#include "util/messagequeue.h"
#include "util/astronomy.h"

#include "satellitetrackersettings.h"
#include "satellitetrackersgp4.h"
#include "satnogs.h"

class WebAPIAdapterInterface;
class QTcpServer;
class QTcpSocket;
class SatelliteTracker;
class SatelliteTrackerWorker;
class QDateTime;
class QGeoCoordinate;

class SatWorkerState
{
public:
    SatWorkerState(QString name) :
        m_name(name)
    {
        m_satState.m_name = name;
    }

    bool hasAOS();

protected:
    QString m_name;             // Name of the satellite
    QDateTime m_aos;            // Time of next AOS
    QDateTime m_los;            // Time of next LOS
    QTimer m_aosTimer;
    QTimer m_losTimer;
    QTimer m_dopplerTimer;
    QList<int> m_initFrequencyOffset;
    SatelliteState m_satState;

    friend SatelliteTrackerWorker;
};

class SatelliteTrackerWorker : public QObject
{
    Q_OBJECT

public:
    class MsgConfigureSatelliteTrackerWorker : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const SatelliteTrackerSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureSatelliteTrackerWorker* create(const SatelliteTrackerSettings& settings, bool force)
        {
            return new MsgConfigureSatelliteTrackerWorker(settings, force);
        }

    private:
        SatelliteTrackerSettings m_settings;
        bool m_force;

        MsgConfigureSatelliteTrackerWorker(const SatelliteTrackerSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    SatelliteTrackerWorker(SatelliteTracker* satelliteTracker, WebAPIAdapterInterface *webAPIAdapterInterface);
    ~SatelliteTrackerWorker();
    void reset();
    bool startWork();
    void stopWork();
    bool isRunning() const { return m_running; }
    MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }
    void setMessageQueueToFeature(MessageQueue *messageQueue) { m_msgQueueToFeature = messageQueue; }
    void setMessageQueueToGUI(MessageQueue *messageQueue) { m_msgQueueToGUI = messageQueue; }

private:

    SatelliteTracker* m_satelliteTracker;
    WebAPIAdapterInterface *m_webAPIAdapterInterface;
    MessageQueue m_inputMessageQueue;  //!< Queue for asynchronous inbound communication
    MessageQueue *m_msgQueueToFeature; //!< Queue to report channel change to main feature object
    MessageQueue *m_msgQueueToGUI;
    SatelliteTrackerSettings m_settings;
    bool m_running;
    QMutex m_mutex;
    QTimer m_pollTimer;
    QHash<QString, SatNogsSatellite *> m_satellites;
    QHash<QString, SatWorkerState *> m_workerState;
    bool m_recalculatePasses;           //!< Recalculate passes as something has changed
    bool m_flipRotation;                //!< Use 180 elevation to avoid 360/0 degree discontinutiy
    bool m_extendedAzRotation;          //!< Use 450+ degree azimuth to avoid 360/0 degree discontinuity

    bool handleMessage(const Message& cmd);
    void applySettings(const SatelliteTrackerSettings& settings, bool force = false);
    MessageQueue *getMessageQueueToGUI() { return m_msgQueueToGUI; }
    void removeFromMap(QString id);
    void sendToMap(QList<MessageQueue*> *mapMessageQueues, QString id, QString image, QString text,
                   double lat, double lon, double altitude, double rotation,
                   QList<QGeoCoordinate *> *track = nullptr, QList<QGeoCoordinate *> *predictedTrack = nullptr);
    void applyDeviceAOSSettings(const QString& name);
    void startStopSinks(bool start);
    void calculateRotation(SatWorkerState *satWorkerState);

private slots:
    void handleInputMessages();
    void update();
    void aos(SatWorkerState *satWorkerState);
    void los(SatWorkerState *satWorkerState);
    void doppler(SatWorkerState *satWorkerState);
};

#endif // INCLUDE_FEATURE_SATELLITETRACKERWORKER_H_
