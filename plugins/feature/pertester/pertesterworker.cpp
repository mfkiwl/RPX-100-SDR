///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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

#include <algorithm>
#include <random>

#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkDatagram>
#include <QEventLoop>
#include <QTimer>
#include <QRegExp>

#include "util/ax25.h"

#include "pertester.h"
#include "pertesterworker.h"
#include "pertesterreport.h"

MESSAGE_CLASS_DEFINITION(PERTesterWorker::MsgConfigurePERTesterWorker, Message)
MESSAGE_CLASS_DEFINITION(PERTesterReport::MsgReportStats, Message)

PERTesterWorker::PERTesterWorker() :
    m_msgQueueToFeature(nullptr),
    m_msgQueueToGUI(nullptr),
    m_running(false),
    m_mutex(QMutex::Recursive),
    m_rxUDPSocket(nullptr),
    m_tx(0),
    m_rxMatched(0),
    m_rxUnmatched(0)
{
    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));
}

PERTesterWorker::~PERTesterWorker()
{
    closeUDP();
    disconnect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));
    m_inputMessageQueue.clear();
}

void PERTesterWorker::reset()
{
    QMutexLocker mutexLocker(&m_mutex);
    m_inputMessageQueue.clear();
}

bool PERTesterWorker::startWork()
{
    qDebug() << "PERTesterWorker::startWork";
    QMutexLocker mutexLocker(&m_mutex);
    openUDP(m_settings);
    // Automatically restart if previous run had finished, otherwise continue
    if (m_tx >= m_settings.m_packetCount)
        resetStats();
    connect(&m_txTimer, SIGNAL(timeout()), this, SLOT(tx()));
    m_txTimer.start(m_settings.m_interval * 1000.0);
    m_running = true;
    return m_running;
}

void PERTesterWorker::stopWork()
{
    QMutexLocker mutexLocker(&m_mutex);
    m_txTimer.stop();
    closeUDP();
    disconnect(&m_txTimer, SIGNAL(timeout()), this, SLOT(tx()));
    m_running = false;
}

void PERTesterWorker::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != nullptr)
    {
        if (handleMessage(*message)) {
            delete message;
        }
    }
}

void PERTesterWorker::resetStats()
{
    m_tx = 0;
    m_rxMatched = 0;
    m_rxUnmatched = 0;
    if (getMessageQueueToGUI())
        getMessageQueueToGUI()->push(PERTesterReport::MsgReportStats::create(m_tx, m_rxMatched, m_rxUnmatched));
}

bool PERTesterWorker::handleMessage(const Message& cmd)
{
    if (MsgConfigurePERTesterWorker::match(cmd))
    {
        QMutexLocker mutexLocker(&m_mutex);
        MsgConfigurePERTesterWorker& cfg = (MsgConfigurePERTesterWorker&) cmd;

        applySettings(cfg.getSettings(), cfg.getForce());
        return true;
    }
    else if (PERTester::MsgResetStats::match(cmd))
    {
        resetStats();
        return true;
    }
    else
    {
        return false;
    }
}

void PERTesterWorker::applySettings(const PERTesterSettings& settings, bool force)
{
    qDebug() << "PERTesterWorker::applySettings:"
            << " force: " << force;

    if (   (settings.m_rxUDPAddress != m_settings.m_rxUDPAddress)
        || (settings.m_rxUDPPort != m_settings.m_rxUDPPort)
        || force)
    {
        openUDP(settings);
    }

    if ((settings.m_interval != m_settings.m_interval) || force)
        m_txTimer.setInterval(settings.m_interval * 1000.0);

    m_settings = settings;
}

void PERTesterWorker::openUDP(const PERTesterSettings& settings)
{
    closeUDP();
    m_rxUDPSocket = new QUdpSocket();
    if (!m_rxUDPSocket->bind(QHostAddress(settings.m_rxUDPAddress), settings.m_rxUDPPort))
    {
        qCritical() << "PERTesterWorker::openUDP: Failed to bind to port " << settings.m_rxUDPAddress << ":" << settings.m_rxUDPPort << ". Error: " << m_rxUDPSocket->error();
        if (m_msgQueueToFeature)
            m_msgQueueToFeature->push(PERTester::MsgReportWorker::create(QString("Failed to bind to port %1:%2 - %3").arg(settings.m_rxUDPAddress).arg(settings.m_rxUDPPort).arg(m_rxUDPSocket->error())));
    }
    else
        qDebug() << "PERTesterWorker::openUDP: Listening on port " << settings.m_rxUDPAddress << ":" << settings.m_rxUDPPort << ".";
    connect(m_rxUDPSocket, &QUdpSocket::readyRead, this, &PERTesterWorker::rx);
}

void PERTesterWorker::closeUDP()
{
    if (m_rxUDPSocket != nullptr)
    {
        qDebug() << "PERTesterWorker::closeUDP: Closing port " << m_settings.m_rxUDPAddress << ":" << m_settings.m_rxUDPPort << ".";
        disconnect(m_rxUDPSocket, &QUdpSocket::readyRead, this, &PERTesterWorker::rx);
        delete m_rxUDPSocket;
        m_rxUDPSocket = nullptr;
    }
}

void PERTesterWorker::rx()
{
    while (m_rxUDPSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = m_rxUDPSocket->receiveDatagram();
        QByteArray packet = datagram.data();
        // Ignore header and CRC, if requested
        packet = packet.mid(m_settings.m_ignoreLeadingBytes, packet.size() - m_settings.m_ignoreLeadingBytes - m_settings.m_ignoreTrailingBytes);
        // Remove from list of transmitted packets
        int i;
        for (i = 0; i < m_txPackets.size(); i++)
        {
            if (packet == m_txPackets[i])
            {
                m_rxMatched++;
                m_txPackets.removeAt(i);
                break;
            }
        }
        if (i == m_txPackets.size())
        {
            qDebug() << "PERTesterWorker::rx: Received packet that was not transmitted: " << packet.toHex();
            m_rxUnmatched++;
        }
    }
    if (getMessageQueueToGUI())
        getMessageQueueToGUI()->push(PERTesterReport::MsgReportStats::create(m_tx, m_rxMatched, m_rxUnmatched));
}

void PERTesterWorker::tx()
{
    QRegExp ax25Dst("^%\\{ax25\\.dst=([A-Za-z0-9-]+)\\}");
    QRegExp ax25Src("^%\\{ax25\\.src=([A-Za-z0-9-]+)\\}");
    QRegExp num("^%\\{num\\}");
    QRegExp data("^%\\{data=([0-9]+),([0-9]+)\\}");
    QRegExp hex("^(0x)?([0-9a-fA-F]?[0-9a-fA-F])");
    QByteArray bytes;
    int pos = 0;

    while (pos < m_settings.m_packet.size())
    {
        if (m_settings.m_packet[pos] == '%')
        {
            if (ax25Dst.indexIn(m_settings.m_packet, pos, QRegExp::CaretAtOffset) != -1)
            {
                // AX.25 destination callsign & SSID
                QString address = ax25Dst.capturedTexts()[1];
                bytes.append(AX25Packet::encodeAddress(address));
                pos += ax25Dst.matchedLength();
            }
            else if (ax25Src.indexIn(m_settings.m_packet, pos, QRegExp::CaretAtOffset) != -1)
            {
                // AX.25 source callsign & SSID
                QString address = ax25Src.capturedTexts()[1];
                bytes.append(AX25Packet::encodeAddress(address, 1));
                pos += ax25Src.matchedLength();
            }
            else if (num.indexIn(m_settings.m_packet, pos, QRegExp::CaretAtOffset) != -1)
            {
                // Big endian packet number
                bytes.append((m_tx >> 24) & 0xff);
                bytes.append((m_tx >> 16) & 0xff);
                bytes.append((m_tx >> 8) & 0xff);
                bytes.append(m_tx & 0xff);
                pos += num.matchedLength();
            }
            else if (data.indexIn(m_settings.m_packet, pos, QRegExp::CaretAtOffset) != -1)
            {
                // Constrained random number of random bytes
                int minBytes = data.capturedTexts()[1].toInt();
                int maxBytes = data.capturedTexts()[2].toInt();
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr0(minBytes, maxBytes);
                std::uniform_int_distribution<> distr1(0, 255);
                int count = distr0(gen);
                for (int i = 0; i < count; i++)
                    bytes.append(distr1(gen));
                pos += data.matchedLength();
            }
            else
            {
                qWarning() << "PERTester: Unsupported substitution in packet: pos=" << pos << " in " << m_settings.m_packet;
                break;
            }
        }
        else if (m_settings.m_packet[pos] == '\"')
        {
            // ASCII string in double quotes
            int startIdx = pos + 1;
            int endQuoteIdx = m_settings.m_packet.indexOf('\"', startIdx);
            if (endQuoteIdx != -1)
            {
                int len = endQuoteIdx - startIdx;
                QString string = m_settings.m_packet.mid(startIdx, len);
                bytes.append(string.toLocal8Bit());
                pos = endQuoteIdx + 1;
            }
            else
            {
                qWarning() << "PERTester: Unterminated string: pos=" << pos << " in " << m_settings.m_packet;
                break;
            }
        }
        else if (hex.indexIn(m_settings.m_packet, pos, QRegExp::CaretAtOffset) != -1)
        {
            // Hex byte
            int value = hex.capturedTexts()[2].toInt(nullptr, 16);
            bytes.append(value);
            pos += hex.matchedLength();
        }
        else if ((m_settings.m_packet[pos] == ' ') || (m_settings.m_packet[pos] == ',') || (m_settings.m_packet[pos] == ':'))
        {
            pos++;
        }
        else
        {
            qWarning() << "PERTester: Unexpected character in packet: pos=" << pos << " in " << m_settings.m_packet;
            break;
        }
    }

    if ((pos >= m_settings.m_packet.size()) && (m_tx < m_settings.m_packetCount))
    {
        // Send packet via UDP
        m_txUDPSocket.writeDatagram(bytes.data(), bytes.size(), QHostAddress(m_settings.m_txUDPAddress), m_settings.m_txUDPPort);
        m_tx++;
        m_txPackets.append(bytes);
        if (getMessageQueueToGUI())
            getMessageQueueToGUI()->push(PERTesterReport::MsgReportStats::create(m_tx, m_rxMatched, m_rxUnmatched));
    }

    if (m_tx >= m_settings.m_packetCount)
    {
        // Test complete
        m_txTimer.stop();
        // Wait for a couple of seconds for the last packet to be received
        QTimer::singleShot(2000, this, &PERTesterWorker::testComplete);
    }
}

void PERTesterWorker::testComplete()
{
    stopWork();
    if (m_msgQueueToFeature != nullptr)
        m_msgQueueToFeature->push(PERTester::MsgReportWorker::create("Complete"));
    qDebug() << "PERTesterWorker::tx: Test complete";
}
