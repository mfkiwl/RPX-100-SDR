///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#ifndef INCLUDE_VORDEMODSCBASEBAND_H
#define INCLUDE_VORDEMODSCBASEBAND_H

#include <QObject>
#include <QMutex>

#include "dsp/samplesinkfifo.h"
#include "util/message.h"
#include "util/messagequeue.h"

#include "vordemodscsink.h"

class DownChannelizer;

class VORDemodSCBaseband : public QObject
{
    Q_OBJECT
public:
    class MsgConfigureVORDemodBaseband : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const VORDemodSCSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureVORDemodBaseband* create(const VORDemodSCSettings& settings, bool force)
        {
            return new MsgConfigureVORDemodBaseband(settings, force);
        }

    private:
        VORDemodSCSettings m_settings;
        bool m_force;

        MsgConfigureVORDemodBaseband(const VORDemodSCSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    VORDemodSCBaseband();
    ~VORDemodSCBaseband();
    void reset();
    void startWork();
    void stopWork();
    void feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end);
    MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; } //!< Get the queue for asynchronous inbound communication
    void getMagSqLevels(double& avg, double& peak, int& nbSamples) { m_sink.getMagSqLevels(avg, peak, nbSamples); }
    void setMessageQueueToChannel(MessageQueue *messageQueue) { m_sink.setMessageQueueToChannel(messageQueue); }
    bool getSquelchOpen() const { return m_sink.getSquelchOpen(); }
    int getAudioSampleRate() const { return m_sink.getAudioSampleRate(); }
    double getMagSq() const { return m_sink.getMagSq();  }
    bool isRunning() const { return m_running; }

private:
    SampleSinkFifo m_sampleFifo;
    DownChannelizer * m_channelizer;
    int m_channelSampleRate;
    VORDemodSCSink m_sink;
    MessageQueue m_inputMessageQueue; //!< Queue for asynchronous inbound communication
    VORDemodSCSettings m_settings;
    MessageQueue *m_messageQueueToGUI;
    bool m_running;
    QMutex m_mutex;

    bool handleMessage(const Message& cmd);
    void applySettings(const VORDemodSCSettings& settings, bool force = false);

private slots:
    void handleInputMessages();
    void handleData(); //!< Handle data when samples have to be processed
};

#endif // INCLUDE_VORDEMODSCBASEBAND_H
