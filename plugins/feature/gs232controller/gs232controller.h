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

#ifndef INCLUDE_FEATURE_GS232CONTROLLER_H_
#define INCLUDE_FEATURE_GS232CONTROLLER_H_

#include <QThread>
#include <QNetworkRequest>
#include <QTimer>

#include "feature/feature.h"
#include "util/message.h"

#include "gs232controllersettings.h"

class WebAPIAdapterInterface;
class GS232ControllerWorker;
class QNetworkAccessManager;
class QNetworkReply;

namespace SWGrpx-100 {
    class SWGDeviceState;
}

class GS232Controller : public Feature
{
	Q_OBJECT
public:
    class MsgConfigureGS232Controller : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const GS232ControllerSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureGS232Controller* create(const GS232ControllerSettings& settings, bool force) {
            return new MsgConfigureGS232Controller(settings, force);
        }

    private:
        GS232ControllerSettings m_settings;
        bool m_force;

        MsgConfigureGS232Controller(const GS232ControllerSettings& settings, bool force) :
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

    class MsgReportWorker : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        QString getMessage() { return m_message; }

        static MsgReportWorker* create(QString message) {
            return new MsgReportWorker(message);
        }

    private:
        QString m_message;

        MsgReportWorker(QString message) :
            Message(),
            m_message(message)
        {}
    };

    GS232Controller(WebAPIAdapterInterface *webAPIAdapterInterface);
    virtual ~GS232Controller();
    virtual void destroy() { delete this; }
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) const { id = objectName(); }
    virtual void getTitle(QString& title) const { title = m_settings.m_title; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual int webapiRun(bool run,
            SWGrpx-100::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiSettingsGet(
            SWGrpx-100::SWGFeatureSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& featureSettingsKeys,
            SWGrpx-100::SWGFeatureSettings& response,
            QString& errorMessage);

    static void webapiFormatFeatureSettings(
        SWGrpx-100::SWGFeatureSettings& response,
        const GS232ControllerSettings& settings);

    static void webapiUpdateFeatureSettings(
            GS232ControllerSettings& settings,
            const QStringList& featureSettingsKeys,
            SWGrpx-100::SWGFeatureSettings& response);

    static const char* const m_featureIdURI;
    static const char* const m_featureId;

private:
    QThread m_thread;
    GS232ControllerWorker *m_worker;
    GS232ControllerSettings m_settings;
    QList<AvailablePipeSource> m_availablePipes;
    PipeEndPoint *m_selectedPipe;
    QTimer m_updatePipesTimer;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void start();
    void stop();
    void applySettings(const GS232ControllerSettings& settings, bool force = false);
    void webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const GS232ControllerSettings& settings, bool force);

private slots:
    void updatePipes();
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_FEATURE_GS232CONTROLLER_H_
