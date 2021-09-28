///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
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

#ifndef PLUGINS_CHANNELTX_UDPSINK_UDPSOURCEUDPHANDLER_H_
#define PLUGINS_CHANNELTX_UDPSINK_UDPSOURCEUDPHANDLER_H_

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QMutex>
#include <stdint.h>

#include "dsp/dsptypes.h"
#include "util/message.h"
#include "util/messagequeue.h"

class UDPSourceUDPHandler : public QObject
{
    Q_OBJECT
public:
    UDPSourceUDPHandler();
    virtual ~UDPSourceUDPHandler();

    void start();
    void stop();
    void configureUDPLink(const QString& address, quint16 port, const QString& multicastAddress, bool multicastJoin);
    void configureMulticastAddress(const QString& address);
    void resetReadIndex();
    void resizeBuffer(float sampleRate);

    void readSample(qint16 &t);      //!< audio mono
    void readSample(AudioSample &a); //!< audio stereo
    void readSample(Sample &s);      //!< I/Q stream

    void setAutoRWBalance(bool autoRWBalance) { m_autoRWBalance = autoRWBalance; }
    void setFeedbackMessageQueue(MessageQueue *messageQueue) { m_feedbackMessageQueue = messageQueue; }

    /** Get buffer gauge value in % of buffer size ([-50:50])
     *  [-50:0] : write leads or read lags
     *  [0:50]  : read leads or write lags
     */
    inline int32_t getBufferGauge() const
    {
        int32_t val = m_rwDelta - (m_nbUDPFrames/2);
        return (100*val) / m_nbUDPFrames;
    }

    static const int m_udpBlockSize = 512; // UDP block size in number of bytes
    static const int m_minNbUDPFrames = 256;  // number of frames of block size in the UDP buffer

public slots:
    void dataReadyRead();

private:
    class MsgUDPAddressAndPort : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const QString& getAddress() const { return m_address; }
        quint16 getPort() const { return m_port; }
        const QString& getMulticastAddress() const { return m_multicastAddress; }
        bool getMulticastJoin() const { return m_multicastJoin; }

        static MsgUDPAddressAndPort* create(const QString& address, quint16 port, const QString& multicastAddress, bool multicastJoin)
        {
            return new MsgUDPAddressAndPort(address, port, multicastAddress, multicastJoin);
        }

    private:
        QString m_address;
        quint16 m_port;
        QString m_multicastAddress;
        bool m_multicastJoin;

        MsgUDPAddressAndPort(const QString& address, quint16 port, const QString& multicastAddress, bool multicastJoin) :
            Message(),
            m_address(address),
            m_port(port),
            m_multicastAddress(multicastAddress),
            m_multicastJoin(multicastJoin)
        { }
    };

    typedef char (udpBlk_t)[m_udpBlockSize];

    void moveData(char *blk);
    void advanceReadPointer(int nbBytes);
    void applyUDPLink(const QString& address, quint16 port, const QString& multicastAddress, bool muticastJoin);
    bool handleMessage(const Message& message);

    QUdpSocket *m_dataSocket;
    QHostAddress m_dataAddress;
    QHostAddress m_remoteAddress;
    QHostAddress m_multicastAddress;
    quint16 m_dataPort;
    quint16 m_remotePort;
    bool m_dataConnected;
    bool m_multicast;
    udpBlk_t *m_udpBuf;
    char m_udpDump[m_udpBlockSize + 8192]; // UDP block size + largest possible block
    int m_udpDumpIndex;
    int m_nbUDPFrames;
    int m_nbAllocatedUDPFrames;
    int m_writeFrameIndex;
    int m_readFrameIndex;
    int m_readIndex;
    int m_rwDelta;
    float m_d;
    bool m_autoRWBalance;
    MessageQueue *m_feedbackMessageQueue;
    MessageQueue m_inputMessageQueue;

private slots:
    void handleMessages();
};



#endif /* PLUGINS_CHANNELTX_UDPSINK_UDPSOURCEUDPHANDLER_H_ */
