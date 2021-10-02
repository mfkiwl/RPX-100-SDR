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

#ifndef INCLUDE_FEATURE_SIMPLEPTT_H_
#define INCLUDE_FEATURE_SIMPLEPTT_H_

#include <QThread>
#include <QNetworkRequest>

#include "feature/feature.h"
#include "util/message.h"

#include "simplepttsettings.h"

class WebAPIAdapterInterface;
class SimplePTTWorker;
class QNetworkAccessManager;
class QNetworkReply;

namespace SWGrpx-100 {
    class SWGDeviceState;
}

class SimplePTT : public Feature
{
	Q_OBJECT
public:
    class MsgConfigureSimplePTT : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const SimplePTTSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureSimplePTT* create(const SimplePTTSettings& settings, bool force) {
            return new MsgConfigureSimplePTT(settings, force);
        }

    private:
        SimplePTTSettings m_settings;
        bool m_force;

        MsgConfigureSimplePTT(const SimplePTTSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    class MsgPTT : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        bool getTx() const { return m_tx; }

        static MsgPTT* create(bool tx) {
            return new MsgPTT(tx);
        }

    private:
        bool m_tx;

        MsgPTT(bool tx) :
            Message(),
            m_tx(tx)
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

    SimplePTT(WebAPIAdapterInterface *webAPIAdapterInterface);
    virtual ~SimplePTT();
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

    virtual int webapiReportGet(
            SWGrpx-100::SWGFeatureReport& response,
            QString& errorMessage);

    virtual int webapiActionsPost(
            const QStringList& featureActionsKeys,
            SWGrpx-100::SWGFeatureActions& query,
            QString& errorMessage);

    static void webapiFormatFeatureSettings(
        SWGrpx-100::SWGFeatureSettings& response,
        const SimplePTTSettings& settings);

    static void webapiUpdateFeatureSettings(
            SimplePTTSettings& settings,
            const QStringList& featureSettingsKeys,
            SWGrpx-100::SWGFeatureSettings& response);

    static const char* const m_featureIdURI;
    static const char* const m_featureId;

private:
    QThread m_thread;
    SimplePTTWorker *m_worker;
    SimplePTTSettings m_settings;
    bool m_ptt;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void start();
    void stop();
    void applySettings(const SimplePTTSettings& settings, bool force = false);
    void webapiFormatFeatureReport(SWGrpx-100::SWGFeatureReport& response);
    void webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const SimplePTTSettings& settings, bool force);

private slots:
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_FEATURE_SIMPLEPTT_H_
