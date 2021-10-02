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

#ifndef INCLUDE_FEATURE_AIS_H_
#define INCLUDE_FEATURE_AIS_H_

#include <QThread>
#include <QNetworkRequest>
#include <QTimer>

#include "feature/feature.h"
#include "util/message.h"

#include "aissettings.h"

class WebAPIAdapterInterface;
class QNetworkAccessManager;
class QNetworkReply;

namespace SWGrpx-100 {
    class SWGDeviceState;
}

class AIS : public Feature
{
	Q_OBJECT
public:
    class MsgConfigureAIS : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const AISSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureAIS* create(const AISSettings& settings, bool force) {
            return new MsgConfigureAIS(settings, force);
        }

    private:
        AISSettings m_settings;
        bool m_force;

        MsgConfigureAIS(const AISSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    AIS(WebAPIAdapterInterface *webAPIAdapterInterface);
    virtual ~AIS();
    virtual void destroy() { delete this; }
    virtual bool handleMessage(const Message& cmd);

    virtual void getIdentifier(QString& id) const { id = objectName(); }
    virtual void getTitle(QString& title) const { title = m_settings.m_title; }

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

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
        const AISSettings& settings);

    static void webapiUpdateFeatureSettings(
            AISSettings& settings,
            const QStringList& featureSettingsKeys,
            SWGrpx-100::SWGFeatureSettings& response);

    static const char* const m_featureIdURI;
    static const char* const m_featureId;

private:
    AISSettings m_settings;
    QList<PipeEndPoint::AvailablePipeSource> m_availablePipes;
    QTimer m_updatePipesTimer;

    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    void start();
    void stop();
    void applySettings(const AISSettings& settings, bool force = false);
    void webapiReverseSendSettings(QList<QString>& featureSettingsKeys, const AISSettings& settings, bool force);

private slots:
    void updatePipes();
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // INCLUDE_FEATURE_AIS_H_
