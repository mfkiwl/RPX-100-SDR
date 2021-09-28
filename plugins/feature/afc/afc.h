///////////////////////////////////////////////////////////////////////////////////
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

#ifndef INCLUDE_FEATURE_AFC_H_
#define INCLUDE_FEATURE_AFC_H_

#include <QThread>
#include <QNetworkRequest>

#include "feature/feature.h"
#include "util/message.h"

#include "afcsettings.h"

class QNetworkAccessManager;
class QNetworkReply;
class WebAPIAdapterInterface;
class DeviceSet;
class AFCWorker;

namespace SWGSDRangel {
    class SWGDeviceState;
}

class AFC : public Feature
{
	Q_OBJECT
public:
    class MsgConfigureAFC : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const AFCSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureAFC* create(const AFCSettings& settings, bool force) {
            return new MsgConfigureAFC(settings, force);
        }

    private:
        AFCSettings m_settings;
        bool m_force;

        MsgConfigureAFC(const AFCSettings& settings, bool force) :
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

    class MsgDeviceTrack : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        static MsgDeviceTrack* create() {
            return new MsgDeviceTrack();
        }
    protected:
        MsgDeviceTrack() :
            Message()
        { }
    };

    class MsgDevicesApply : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        static MsgDevicesApply* create() {
            return new MsgDevicesApply();
        }
    protected:
        MsgDevicesApply() :
            Message()
        { }
    };

    AFC(WebAPIAdapterInterface *webAPIAdapterInterface);
    virtual ~AFC();
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

    virtual int webapiReportGet(
            SWGSDRangel::SWGFeatureReport& response,
            QString& errorMessage);

    virtual int webapiActionsPost(
            const QStringList& featureActionsKeys,
            SWGSDRangel::SWGFeatureActions& query,
            QString& errorMessage);

    static void webapiFormatFeatureSettings(
        SWGSDRangel::SWGFeatureSettings& response,
        const AFCSettings& settings);

    static void webapiUpdateFeatureSettings(
            AFCSettings& settings,
            const QStringList& featureSettingsKeys,
            SWGSDRangel::SWGFeatureSettings& response);

    static const char* const m_featureIdURI;
    static const char* const m_featureId;

private:
    QThread m_thread;
    AFCWorker *m_worker;
    AFCSettings m_settings;
    DeviceSet *m_trackerDeviceSet;
    DeviceSet *m_trackedDeviceSet;
    int m_trackerIndexInDeviceSet;
    ChannelAPI *m_trackerChannelAPI;
    QList<ChannelAPI*> m_trackedChannelAPIs;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void start();
    void stop();
    void applySettings(const AFCSettings& settings, bool force = false);
    void webapiFormatFeatureReport(SWGSDRangel::SWGFeatureReport& response);
    void webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const AFCSettings& settings, bool force);
    void trackerDeviceChange(int deviceIndex);
    void trackedDeviceChange(int deviceIndex);
    void removeTrackerFeatureReference();
    void removeTrackedFeatureReferences();

private slots:
    void networkManagerFinished(QNetworkReply *reply);
    void handleChannelMessageQueue(MessageQueue* messageQueue);
};

#endif // INCLUDE_FEATURE_AFC_H_
