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

#ifndef INCLUDE_FEATURE_RIGCTLSERVER_H_
#define INCLUDE_FEATURE_RIGCTLSERVER_H_

#include <QThread>
#include <QNetworkRequest>

#include "feature/feature.h"
#include "util/message.h"

#include "rigctlserversettings.h"

class WebAPIAdapterInterface;
class RigCtlServerWorker;
class QNetworkAccessManager;
class QNetworkReply;

namespace SWGSDRangel {
    class SWGDeviceState;
}

class RigCtlServer : public Feature
{
	Q_OBJECT
public:
    class MsgConfigureRigCtlServer : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const RigCtlServerSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureRigCtlServer* create(const RigCtlServerSettings& settings, bool force) {
            return new MsgConfigureRigCtlServer(settings, force);
        }

    private:
        RigCtlServerSettings m_settings;
        bool m_force;

        MsgConfigureRigCtlServer(const RigCtlServerSettings& settings, bool force) :
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

    RigCtlServer(WebAPIAdapterInterface *webAPIAdapterInterface);
    virtual ~RigCtlServer();
    virtual void destroy() { delete this; }
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) const { id = objectName(); }
    virtual void getTitle(QString& title) const { title = m_settings.m_title; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual int webapiRun(bool run,
            SWGSDRangel::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiSettingsGet(
            SWGSDRangel::SWGFeatureSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& featureSettingsKeys,
            SWGSDRangel::SWGFeatureSettings& response,
            QString& errorMessage);

    static void webapiFormatFeatureSettings(
        SWGSDRangel::SWGFeatureSettings& response,
        const RigCtlServerSettings& settings);

    static void webapiUpdateFeatureSettings(
            RigCtlServerSettings& settings,
            const QStringList& featureSettingsKeys,
            SWGSDRangel::SWGFeatureSettings& response);

    static const char* const m_featureIdURI;
    static const char* const m_featureId;

private:
    QThread m_thread;
    RigCtlServerWorker *m_worker;
    RigCtlServerSettings m_settings;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void start();
    void stop();
    void applySettings(const RigCtlServerSettings& settings, bool force = false);
    void webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const RigCtlServerSettings& settings, bool force);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_FEATURE_RIGCTLSERVER_H_
