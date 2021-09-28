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

#ifndef INCLUDE_FEATURE_GS232CONTROLLERWORKER_H_
#define INCLUDE_FEATURE_GS232CONTROLLERWORKER_H_

#include <QObject>
#include <QTimer>
#include <QSerialPort>

#include "util/message.h"
#include "util/messagequeue.h"

#include "gs232controllersettings.h"

class GS232ControllerWorker : public QObject
{
    Q_OBJECT
public:
    class MsgConfigureGS232ControllerWorker : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const GS232ControllerSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureGS232ControllerWorker* create(const GS232ControllerSettings& settings, bool force)
        {
            return new MsgConfigureGS232ControllerWorker(settings, force);
        }

    private:
        GS232ControllerSettings m_settings;
        bool m_force;

        MsgConfigureGS232ControllerWorker(const GS232ControllerSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    GS232ControllerWorker();
    ~GS232ControllerWorker();
    void reset();
    bool startWork();
    void stopWork();
    bool isRunning() const { return m_running; }
    MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }
    void setMessageQueueToFeature(MessageQueue *messageQueue) { m_msgQueueToFeature = messageQueue; }
    void setMessageQueueToGUI(MessageQueue *messageQueue) { m_msgQueueToGUI = messageQueue; }

private:

    MessageQueue m_inputMessageQueue;  //!< Queue for asynchronous inbound communication
    MessageQueue *m_msgQueueToFeature; //!< Queue to report channel change to main feature object
    MessageQueue *m_msgQueueToGUI;
    GS232ControllerSettings m_settings;
    bool m_running;
    QMutex m_mutex;
    QSerialPort m_serialPort;
    QTimer m_pollTimer;

    float m_lastAzimuth;
    float m_lastElevation;

    bool m_spidSetOutstanding;
    bool m_spidSetSent;
    bool m_spidStatusSent;

    bool handleMessage(const Message& cmd);
    void applySettings(const GS232ControllerSettings& settings, bool force = false);
    MessageQueue *getMessageQueueToGUI() { return m_msgQueueToGUI; }
    void openSerialPort(const GS232ControllerSettings& settings);
    void setAzimuth(float azimuth);
    void setAzimuthElevation(float azimuth, float elevation);

private slots:
    void handleInputMessages();
    void readSerialData();
    void update();
};

#endif // INCLUDE_FEATURE_GS232CONTROLLERWORKER_H_
