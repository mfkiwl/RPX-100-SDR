///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// (c) 2015 John Greb                                                            //
// (c) 2020 Edouard Griffiths, F4EXB                                             //
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

#include <stdio.h>

#include <QTime>
#include <QDebug>
#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>

#include "SWGChannelSettings.h"
#include "SWGChannelReport.h"
#include "SWGChirpChatDemodReport.h"

#include "dsp/dspcommands.h"
#include "device/deviceapi.h"
#include "feature/feature.h"
#include "util/ax25.h"
#include "util/db.h"
#include "maincore.h"

#include "chirpchatdemodmsg.h"
#include "chirpchatdemod.h"

MESSAGE_CLASS_DEFINITION(ChirpChatDemod::MsgConfigureChirpChatDemod, Message)
MESSAGE_CLASS_DEFINITION(ChirpChatDemod::MsgReportDecodeBytes, Message)
MESSAGE_CLASS_DEFINITION(ChirpChatDemod::MsgReportDecodeString, Message)

const char* const ChirpChatDemod::m_channelIdURI = "rpx-100.channel.chirpchatdemod";
const char* const ChirpChatDemod::m_channelId = "ChirpChatDemod";

ChirpChatDemod::ChirpChatDemod(DeviceAPI* deviceAPI) :
        ChannelAPI(m_channelIdURI, ChannelAPI::StreamSingleSink),
        m_deviceAPI(deviceAPI),
        m_spectrumVis(SDR_RX_SCALEF),
        m_basebandSampleRate(0),
        m_lastMsgSignalDb(0.0),
        m_lastMsgNoiseDb(0.0),
        m_lastMsgSyncWord(0),
        m_lastMsgPacketLength(0),
        m_lastMsgNbParityBits(0),
        m_lastMsgHasCRC(false),
        m_lastMsgNbSymbols(0),
        m_lastMsgNbCodewords(0),
        m_lastMsgEarlyEOM(false),
        m_lastMsgHeaderCRC(false),
        m_lastMsgHeaderParityStatus(0),
        m_lastMsgPayloadCRC(false),
        m_lastMsgPayloadParityStatus(0),
        m_udpSink(this, 256)
{
	setObjectName(m_channelId);

    m_thread = new QThread(this);
    m_basebandSink = new ChirpChatDemodBaseband();
    m_basebandSink->setSpectrumSink(&m_spectrumVis);
    m_basebandSink->setDecoderMessageQueue(getInputMessageQueue()); // Decoder held on the main thread
    m_basebandSink->moveToThread(m_thread);

	applySettings(m_settings, true);

    m_deviceAPI->addChannelSink(this);
    m_deviceAPI->addChannelSinkAPI(this);
}

ChirpChatDemod::~ChirpChatDemod()
{
    m_deviceAPI->removeChannelSinkAPI(this);
    m_deviceAPI->removeChannelSink(this);
    delete m_basebandSink;
    delete m_thread;
}

uint32_t ChirpChatDemod::getNumberOfDeviceStreams() const
{
    return m_deviceAPI->getNbSourceStreams();
}

void ChirpChatDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool pO)
{
    (void) pO;
	m_basebandSink->feed(begin, end);
}

void ChirpChatDemod::start()
{
    qDebug() << "ChirpChatDemod::start";

    if (m_basebandSampleRate != 0) {
        m_basebandSink->setBasebandSampleRate(m_basebandSampleRate);
    }

    m_basebandSink->reset();
    m_thread->start();

    SpectrumSettings spectrumSettings = m_spectrumVis.getSettings();
    spectrumSettings.m_ssb = true;
    SpectrumVis::MsgConfigureSpectrumVis *msg = SpectrumVis::MsgConfigureSpectrumVis::create(spectrumSettings, false);
    m_spectrumVis.getInputMessageQueue()->push(msg);}

void ChirpChatDemod::stop()
{
    qDebug() << "ChirpChatDemod::stop";
	m_thread->exit();
	m_thread->wait();
}

bool ChirpChatDemod::handleMessage(const Message& cmd)
{
	if (MsgConfigureChirpChatDemod::match(cmd))
	{
		qDebug() << "ChirpChatDemod::handleMessage: MsgConfigureChirpChatDemod";
		MsgConfigureChirpChatDemod& cfg = (MsgConfigureChirpChatDemod&) cmd;
		ChirpChatDemodSettings settings = cfg.getSettings();
		applySettings(settings, cfg.getForce());

		return true;
	}
    else if (ChirpChatDemodMsg::MsgDecodeSymbols::match(cmd))
    {
        qDebug() << "ChirpChatDemod::handleMessage: MsgDecodeSymbols";
        ChirpChatDemodMsg::MsgDecodeSymbols& msg = (ChirpChatDemodMsg::MsgDecodeSymbols&) cmd;
        m_lastMsgSignalDb = msg.getSingalDb();
        m_lastMsgNoiseDb = msg.getNoiseDb();
        m_lastMsgSyncWord = msg.getSyncWord();

        if (m_settings.m_codingScheme == ChirpChatDemodSettings::CodingLoRa)
        {
            m_decoder.decodeSymbols(msg.getSymbols(), m_lastMsgBytes);
            QDateTime dt = QDateTime::currentDateTime();
            m_lastMsgTimestamp = dt.toString(Qt::ISODateWithMs);
            m_lastMsgPacketLength = m_decoder.getPacketLength();
            m_lastMsgNbParityBits = m_decoder.getNbParityBits();
            m_lastMsgHasCRC = m_decoder.getHasCRC();
            m_lastMsgNbSymbols = m_decoder.getNbSymbols();
            m_lastMsgNbCodewords = m_decoder.getNbCodewords();
            m_lastMsgEarlyEOM = m_decoder.getEarlyEOM();
            m_lastMsgHeaderCRC = m_decoder.getHeaderCRCStatus();
            m_lastMsgHeaderParityStatus = m_decoder.getHeaderParityStatus();
            m_lastMsgPayloadCRC = m_decoder.getPayloadCRCStatus();
            m_lastMsgPayloadParityStatus = m_decoder.getPayloadParityStatus();

            QByteArray bytesCopy(m_lastMsgBytes);
            bytesCopy.truncate(m_lastMsgPacketLength);
            bytesCopy.replace('\0', " ");
            m_lastMsgString = QString(bytesCopy.toStdString().c_str());

            if (m_settings.m_sendViaUDP)
            {
                uint8_t *bytes = reinterpret_cast<uint8_t*>(m_lastMsgBytes.data());
                m_udpSink.writeUnbuffered(bytes, m_lastMsgPacketLength);
            }

            if (getMessageQueueToGUI())
            {
                MsgReportDecodeBytes *msgToGUI = MsgReportDecodeBytes::create(m_lastMsgBytes);
                msgToGUI->setSyncWord(m_lastMsgSyncWord);
                msgToGUI->setSignalDb(m_lastMsgSignalDb);
                msgToGUI->setNoiseDb(m_lastMsgNoiseDb);
                msgToGUI->setPacketSize(m_lastMsgPacketLength);
                msgToGUI->setNbParityBits(m_lastMsgNbParityBits);
                msgToGUI->setHasCRC(m_lastMsgHasCRC);
                msgToGUI->setNbSymbols(m_lastMsgNbSymbols);
                msgToGUI->setNbCodewords(m_lastMsgNbCodewords);
                msgToGUI->setEarlyEOM(m_lastMsgEarlyEOM);
                msgToGUI->setHeaderParityStatus(m_lastMsgHeaderParityStatus);
                msgToGUI->setHeaderCRCStatus(m_lastMsgHeaderCRC);
                msgToGUI->setPayloadParityStatus(m_lastMsgPayloadParityStatus);
                msgToGUI->setPayloadCRCStatus(m_lastMsgPayloadCRC);
                getMessageQueueToGUI()->push(msgToGUI);
            }

            // Is this an APRS packet?
            // As per: https://github.com/oe3cjb/TTGO-T-Beam-LoRa-APRS/blob/master/lib/BG_RF95/BG_RF95.cpp
            // There is a 3 byte header for LoRa APRS packets. Addressing follows in ASCII: srccall>dst:
            int colonIdx = m_lastMsgBytes.indexOf(':');
            int greaterThanIdx =  m_lastMsgBytes.indexOf('>');
            if (   (m_lastMsgBytes[0] == '<')
                && (greaterThanIdx != -1)
                && (colonIdx != -1)
                && ((m_lastMsgHasCRC && m_lastMsgPayloadCRC) || !m_lastMsgHasCRC)
               )
            {
                QByteArray packet;

                // Extract addresses
                const char *d = m_lastMsgBytes.data();
                QString srcString = QString::fromLatin1(d + 3, greaterThanIdx - 3);
                QString dstString = QString::fromLatin1(d + greaterThanIdx + 1, colonIdx - greaterThanIdx - 1);

                // Convert to AX.25 format
                packet.append(AX25Packet::encodeAddress(dstString));
                packet.append(AX25Packet::encodeAddress(srcString, 1));
                packet.append(3);
                packet.append(-16); // 0xf0
                packet.append(m_lastMsgBytes.mid(colonIdx+1));
                if (!m_lastMsgHasCRC)
                {
                    packet.append((char)0); // dummy crc
                    packet.append((char)0);
                }

                // Forward to APRS and other packet features
                MessagePipes& messagePipes = MainCore::instance()->getMessagePipes();
                QList<MessageQueue*> *packetMessageQueues = messagePipes.getMessageQueues(this, "packets");
                if (packetMessageQueues)
                {
                    QList<MessageQueue*>::iterator it = packetMessageQueues->begin();
                    for (; it != packetMessageQueues->end(); ++it)
                    {
                        MainCore::MsgPacket *msg = MainCore::MsgPacket::create(this, packet, QDateTime::currentDateTime());
                        (*it)->push(msg);
                    }
                }
            }

            if (m_settings.m_autoNbSymbolsMax)
            {
                ChirpChatDemodSettings settings = m_settings;
                settings.m_nbSymbolsMax = m_lastMsgNbSymbols;
                applySettings(settings);

                if (getMessageQueueToGUI()) // forward to GUI if any
                {
                    MsgConfigureChirpChatDemod *msgToGUI = MsgConfigureChirpChatDemod::create(settings, false);
                    getMessageQueueToGUI()->push(msgToGUI);
                }
            }
        }
        else
        {
            m_decoder.decodeSymbols(msg.getSymbols(), m_lastMsgString);
            QDateTime dt = QDateTime::currentDateTime();
            m_lastMsgTimestamp = dt.toString(Qt::ISODateWithMs);

            if (m_settings.m_sendViaUDP)
            {
                const QByteArray& byteArray = m_lastMsgString.toUtf8();
                const uint8_t *bytes = reinterpret_cast<const uint8_t*>(byteArray.data());
                m_udpSink.writeUnbuffered(bytes, byteArray.size());
            }

            if (getMessageQueueToGUI())
            {
                MsgReportDecodeString *msgToGUI = MsgReportDecodeString::create(m_lastMsgString);
                msgToGUI->setSyncWord(m_lastMsgSyncWord);
                msgToGUI->setSignalDb(m_lastMsgSignalDb);
                msgToGUI->setNoiseDb(m_lastMsgNoiseDb);
                getMessageQueueToGUI()->push(msgToGUI);
            }
        }

        return true;
    }
    else if (DSPSignalNotification::match(cmd))
    {
        DSPSignalNotification& notif = (DSPSignalNotification&) cmd;
        m_basebandSampleRate = notif.getSampleRate();
        // Forward to the sink
        DSPSignalNotification* rep = new DSPSignalNotification(notif); // make a copy
        qDebug() << "ChirpChatDemod::handleMessage: DSPSignalNotification: m_basebandSampleRate: " << m_basebandSampleRate;
        m_basebandSink->getInputMessageQueue()->push(rep);

        if (getMessageQueueToGUI())
        {
            DSPSignalNotification* repToGUI = new DSPSignalNotification(notif); // make a copy
            getMessageQueueToGUI()->push(repToGUI);
        }

        return true;
    }
	else
	{
		return false;
	}
}

QByteArray ChirpChatDemod::serialize() const
{
    return m_settings.serialize();
}

bool ChirpChatDemod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureChirpChatDemod *msg = MsgConfigureChirpChatDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureChirpChatDemod *msg = MsgConfigureChirpChatDemod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

void ChirpChatDemod::applySettings(const ChirpChatDemodSettings& settings, bool force)
{
    qDebug() << "ChirpChatDemod::applySettings:"
            << " m_inputFrequencyOffset: " << settings.m_inputFrequencyOffset
            << " m_bandwidthIndex: " << settings.m_bandwidthIndex
            << " m_spreadFactor: " << settings.m_spreadFactor
            << " m_deBits: " << settings.m_deBits
            << " m_codingScheme: " << settings.m_codingScheme
            << " m_hasHeader: " << settings.m_hasHeader
            << " m_hasCRC: " << settings.m_hasCRC
            << " m_nbParityBits: " << settings.m_nbParityBits
            << " m_packetLength: " << settings.m_packetLength
            << " m_autoNbSymbolsMax: " << settings.m_autoNbSymbolsMax
            << " m_sendViaUDP: " << settings.m_sendViaUDP
            << " m_udpAddress: " << settings.m_udpAddress
            << " m_udpPort: " << settings.m_udpPort
            << " m_rgbColor: " << settings.m_rgbColor
            << " m_title: " << settings.m_title
            << " force: " << force;

    QList<QString> reverseAPIKeys;

    if ((settings.m_inputFrequencyOffset != m_settings.m_inputFrequencyOffset) || force) {
        reverseAPIKeys.append("inputFrequencyOffset");
    }

    if ((settings.m_bandwidthIndex != m_settings.m_bandwidthIndex) || force)
    {
        reverseAPIKeys.append("bandwidthIndex");
        DSPSignalNotification *msg = new DSPSignalNotification(
            ChirpChatDemodSettings::bandwidths[settings.m_bandwidthIndex],
            0);
        m_spectrumVis.getInputMessageQueue()->push(msg);
    }

    if ((settings.m_spreadFactor != m_settings.m_spreadFactor) || force) {
        reverseAPIKeys.append("spreadFactor");
    }
    if ((settings.m_deBits != m_settings.m_deBits) || force) {
        reverseAPIKeys.append("deBits");
    }
    if ((settings.m_fftWindow != m_settings.m_fftWindow) || force) {
        reverseAPIKeys.append("fftWindow");
    }

    if ((settings.m_spreadFactor != m_settings.m_spreadFactor)
     || (settings.m_deBits != m_settings.m_deBits) || force) {
         m_decoder.setNbSymbolBits(settings.m_spreadFactor, settings.m_deBits);
    }

    if ((settings.m_codingScheme != m_settings.m_codingScheme) || force)
    {
        reverseAPIKeys.append("codingScheme");
        m_decoder.setCodingScheme(settings.m_codingScheme);
    }

    if ((settings.m_hasHeader != m_settings.m_hasHeader) || force)
    {
        reverseAPIKeys.append("hasHeader");
        m_decoder.setLoRaHasHeader(settings.m_hasHeader);
    }

    if ((settings.m_hasCRC != m_settings.m_hasCRC) || force)
    {
        reverseAPIKeys.append("hasCRC");
        m_decoder.setLoRaHasCRC(settings.m_hasCRC);
    }

    if ((settings.m_nbParityBits != m_settings.m_nbParityBits) || force)
    {
        reverseAPIKeys.append("nbParityBits");
        m_decoder.setLoRaParityBits(settings.m_nbParityBits);
    }

    if ((settings.m_packetLength != m_settings.m_packetLength) || force)
    {
        reverseAPIKeys.append("packetLength");
        m_decoder.setLoRaPacketLength(settings.m_packetLength);
    }

    if ((settings.m_decodeActive != m_settings.m_decodeActive) || force) {
        reverseAPIKeys.append("decodeActive");
    }
    if ((settings.m_eomSquelchTenths != m_settings.m_eomSquelchTenths) || force) {
        reverseAPIKeys.append("eomSquelchTenths");
    }
    if ((settings.m_nbSymbolsMax != m_settings.m_nbSymbolsMax) || force) {
        reverseAPIKeys.append("nbSymbolsMax");
    }
    if ((settings.m_preambleChirps != m_settings.m_preambleChirps) || force) {
        reverseAPIKeys.append("preambleChirps");
    }
    if ((settings.m_rgbColor != m_settings.m_rgbColor) || force) {
        reverseAPIKeys.append("rgbColor");
    }
    if ((settings.m_title != m_settings.m_title) || force) {
        reverseAPIKeys.append("title");
    }
    if ((settings.m_sendViaUDP != m_settings.m_sendViaUDP) || force) {
        reverseAPIKeys.append("sendViaUDP");
    }
    if ((settings.m_autoNbSymbolsMax != m_settings.m_autoNbSymbolsMax) || force) {
        reverseAPIKeys.append("autoNbSymbolsMax");
    }

    if ((settings.m_udpAddress != m_settings.m_udpAddress) || force)
    {
        reverseAPIKeys.append("udpAddress");
        m_udpSink.setAddress(settings.m_udpAddress);
    }

    if ((settings.m_udpPort != m_settings.m_udpPort) || force)
    {
        reverseAPIKeys.append("udpPort");
        m_udpSink.setPort(settings.m_udpPort);
    }

    if (m_settings.m_streamIndex != settings.m_streamIndex)
    {
        if (m_deviceAPI->getSampleMIMO()) // change of stream is possible for MIMO devices only
        {
            m_deviceAPI->removeChannelSinkAPI(this);
            m_deviceAPI->removeChannelSink(this, m_settings.m_streamIndex);
            m_deviceAPI->addChannelSink(this, settings.m_streamIndex);
            m_deviceAPI->addChannelSinkAPI(this);
        }

        reverseAPIKeys.append("streamIndex");
    }

    ChirpChatDemodBaseband::MsgConfigureChirpChatDemodBaseband *msg =
        ChirpChatDemodBaseband::MsgConfigureChirpChatDemodBaseband::create(settings, force);
    m_basebandSink->getInputMessageQueue()->push(msg);

    if (settings.m_useReverseAPI)
    {
        bool fullUpdate = ((m_settings.m_useReverseAPI != settings.m_useReverseAPI) && settings.m_useReverseAPI) ||
                (m_settings.m_reverseAPIAddress != settings.m_reverseAPIAddress) ||
                (m_settings.m_reverseAPIPort != settings.m_reverseAPIPort) ||
                (m_settings.m_reverseAPIDeviceIndex != settings.m_reverseAPIDeviceIndex) ||
                (m_settings.m_reverseAPIChannelIndex != settings.m_reverseAPIChannelIndex);
        webapiReverseSendSettings(reverseAPIKeys, settings, fullUpdate || force);
    }

    QList<MessageQueue*> *messageQueues = MainCore::instance()->getMessagePipes().getMessageQueues(this, "settings");

    if (messageQueues) {
        sendChannelSettings(messageQueues, reverseAPIKeys, settings, force);
    }

    m_settings = settings;
}

int ChirpChatDemod::webapiSettingsGet(
    SWGrpx-100::SWGChannelSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setChirpChatDemodSettings(new SWGrpx-100::SWGChirpChatDemodSettings());
    response.getChirpChatDemodSettings()->init();
    webapiFormatChannelSettings(response, m_settings);

    return 200;
}

int ChirpChatDemod::webapiSettingsPutPatch(
    bool force,
    const QStringList& channelSettingsKeys,
    SWGrpx-100::SWGChannelSettings& response,
    QString& errorMessage)
{
    (void) errorMessage;
    ChirpChatDemodSettings settings = m_settings;
    webapiUpdateChannelSettings(settings, channelSettingsKeys, response);

    MsgConfigureChirpChatDemod *msg = MsgConfigureChirpChatDemod::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        MsgConfigureChirpChatDemod *msgToGUI = MsgConfigureChirpChatDemod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    webapiFormatChannelSettings(response, settings);

    return 200;
}

void ChirpChatDemod::webapiUpdateChannelSettings(
        ChirpChatDemodSettings& settings,
        const QStringList& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings& response)
{
    if (channelSettingsKeys.contains("inputFrequencyOffset")) {
        settings.m_inputFrequencyOffset = response.getChirpChatDemodSettings()->getInputFrequencyOffset();
    }
    if (channelSettingsKeys.contains("bandwidthIndex")) {
        settings.m_bandwidthIndex = response.getChirpChatDemodSettings()->getBandwidthIndex();
    }
    if (channelSettingsKeys.contains("spreadFactor")) {
        settings.m_spreadFactor = response.getChirpChatDemodSettings()->getSpreadFactor();
    }
    if (channelSettingsKeys.contains("deBits")) {
        settings.m_deBits = response.getChirpChatDemodSettings()->getDeBits();
    }
    if (channelSettingsKeys.contains("fftWindow")) {
        settings.m_fftWindow = (FFTWindow::Function) response.getChirpChatDemodSettings()->getFftWindow();
    }
    if (channelSettingsKeys.contains("codingScheme")) {
        settings.m_codingScheme = (ChirpChatDemodSettings::CodingScheme) response.getChirpChatDemodSettings()->getCodingScheme();
    }
    if (channelSettingsKeys.contains("decodeActive")) {
        settings.m_decodeActive = response.getChirpChatDemodSettings()->getDecodeActive() != 0;
    }
    if (channelSettingsKeys.contains("eomSquelchTenths")) {
        settings.m_eomSquelchTenths = response.getChirpChatDemodSettings()->getEomSquelchTenths();
    }
    if (channelSettingsKeys.contains("nbSymbolsMax")) {
        settings.m_nbSymbolsMax = response.getChirpChatDemodSettings()->getNbSymbolsMax();
    }
    if (channelSettingsKeys.contains("autoNbSymbolsMax")) {
        settings.m_autoNbSymbolsMax = response.getChirpChatDemodSettings()->getAutoNbSymbolsMax() != 0;
    }
    if (channelSettingsKeys.contains("preambleChirps")) {
        settings.m_preambleChirps = response.getChirpChatDemodSettings()->getPreambleChirps();
    }
    if (channelSettingsKeys.contains("nbParityBits")) {
        settings.m_nbParityBits = response.getChirpChatDemodSettings()->getNbParityBits();
    }
    if (channelSettingsKeys.contains("packetLength")) {
        settings.m_packetLength = response.getChirpChatDemodSettings()->getPacketLength();
    }
    if (channelSettingsKeys.contains("hasCRC")) {
        settings.m_hasCRC = response.getChirpChatDemodSettings()->getHasCrc() != 0;
    }
    if (channelSettingsKeys.contains("hasHeader")) {
        settings.m_hasHeader = response.getChirpChatDemodSettings()->getHasHeader() != 0;
    }
    if (channelSettingsKeys.contains("sendViaUDP")) {
        settings.m_sendViaUDP = response.getChirpChatDemodSettings()->getSendViaUdp() != 0;
    }
    if (channelSettingsKeys.contains("udpAddress")) {
        settings.m_udpAddress = *response.getChirpChatDemodSettings()->getUdpAddress();
    }
    if (channelSettingsKeys.contains("udpPort"))
    {
        uint16_t port = response.getChirpChatDemodSettings()->getUdpPort();
        settings.m_udpPort = port < 1024 ? 1024 : port;
    }
    if (channelSettingsKeys.contains("rgbColor")) {
        settings.m_rgbColor = response.getChirpChatDemodSettings()->getRgbColor();
    }
    if (channelSettingsKeys.contains("title")) {
        settings.m_title = *response.getChirpChatDemodSettings()->getTitle();
    }
    if (channelSettingsKeys.contains("streamIndex")) {
        settings.m_streamIndex = response.getChirpChatDemodSettings()->getStreamIndex();
    }
    if (channelSettingsKeys.contains("useReverseAPI")) {
        settings.m_useReverseAPI = response.getChirpChatDemodSettings()->getUseReverseApi() != 0;
    }
    if (channelSettingsKeys.contains("reverseAPIAddress")) {
        settings.m_reverseAPIAddress = *response.getChirpChatDemodSettings()->getReverseApiAddress();
    }
    if (channelSettingsKeys.contains("reverseAPIPort")) {
        settings.m_reverseAPIPort = response.getChirpChatDemodSettings()->getReverseApiPort();
    }
    if (channelSettingsKeys.contains("reverseAPIDeviceIndex")) {
        settings.m_reverseAPIDeviceIndex = response.getChirpChatDemodSettings()->getReverseApiDeviceIndex();
    }
    if (channelSettingsKeys.contains("reverseAPIChannelIndex")) {
        settings.m_reverseAPIChannelIndex = response.getChirpChatDemodSettings()->getReverseApiChannelIndex();
    }
}

int ChirpChatDemod::webapiReportGet(
    SWGrpx-100::SWGChannelReport& response,
    QString& errorMessage)
{
    (void) errorMessage;
    response.setChirpChatDemodReport(new SWGrpx-100::SWGChirpChatDemodReport());
    response.getChirpChatDemodReport()->init();
    webapiFormatChannelReport(response);
    return 200;
}

void ChirpChatDemod::webapiFormatChannelSettings(SWGrpx-100::SWGChannelSettings& response, const ChirpChatDemodSettings& settings)
{
    response.getChirpChatDemodSettings()->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    response.getChirpChatDemodSettings()->setBandwidthIndex(settings.m_bandwidthIndex);
    response.getChirpChatDemodSettings()->setSpreadFactor(settings.m_spreadFactor);
    response.getChirpChatDemodSettings()->setDeBits(settings.m_deBits);
    response.getChirpChatDemodSettings()->setFftWindow((int) settings.m_fftWindow);
    response.getChirpChatDemodSettings()->setCodingScheme((int) settings.m_codingScheme);
    response.getChirpChatDemodSettings()->setDecodeActive(settings.m_decodeActive ? 1 : 0);
    response.getChirpChatDemodSettings()->setEomSquelchTenths(settings.m_eomSquelchTenths);
    response.getChirpChatDemodSettings()->setNbSymbolsMax(settings.m_nbSymbolsMax);
    response.getChirpChatDemodSettings()->setAutoNbSymbolsMax(settings.m_autoNbSymbolsMax ? 1 : 0);
    response.getChirpChatDemodSettings()->setPreambleChirps(settings.m_preambleChirps);
    response.getChirpChatDemodSettings()->setNbParityBits(settings.m_nbParityBits);
    response.getChirpChatDemodSettings()->setHasCrc(settings.m_hasCRC ? 1 : 0);
    response.getChirpChatDemodSettings()->setHasHeader(settings.m_hasHeader ? 1 : 0);
    response.getChirpChatDemodSettings()->setSendViaUdp(settings.m_sendViaUDP ? 1 : 0);

    if (response.getChirpChatDemodSettings()->getUdpAddress()) {
        *response.getChirpChatDemodSettings()->getUdpAddress() = settings.m_udpAddress;
    } else {
        response.getChirpChatDemodSettings()->setUdpAddress(new QString(settings.m_udpAddress));
    }

    response.getChirpChatDemodSettings()->setUdpPort(settings.m_udpPort);
    response.getChirpChatDemodSettings()->setRgbColor(settings.m_rgbColor);

    if (response.getChirpChatDemodSettings()->getTitle()) {
        *response.getChirpChatDemodSettings()->getTitle() = settings.m_title;
    } else {
        response.getChirpChatDemodSettings()->setTitle(new QString(settings.m_title));
    }

    response.getChirpChatDemodSettings()->setUseReverseApi(settings.m_useReverseAPI ? 1 : 0);

    if (response.getChirpChatDemodSettings()->getReverseApiAddress()) {
        *response.getChirpChatDemodSettings()->getReverseApiAddress() = settings.m_reverseAPIAddress;
    } else {
        response.getChirpChatDemodSettings()->setReverseApiAddress(new QString(settings.m_reverseAPIAddress));
    }

    response.getChirpChatDemodSettings()->setReverseApiPort(settings.m_reverseAPIPort);
    response.getChirpChatDemodSettings()->setReverseApiDeviceIndex(settings.m_reverseAPIDeviceIndex);
    response.getChirpChatDemodSettings()->setReverseApiChannelIndex(settings.m_reverseAPIChannelIndex);
}

void ChirpChatDemod::webapiFormatChannelReport(SWGrpx-100::SWGChannelReport& response)
{
    response.getChirpChatDemodReport()->setChannelPowerDb(CalcDb::dbPower(getTotalPower()));
    response.getChirpChatDemodReport()->setSignalPowerDb(m_lastMsgSignalDb);
    response.getChirpChatDemodReport()->setNoisePowerDb(CalcDb::dbPower(getCurrentNoiseLevel()));
    response.getChirpChatDemodReport()->setSnrPowerDb(m_lastMsgSignalDb - m_lastMsgNoiseDb);
    response.getChirpChatDemodReport()->setChannelSampleRate(m_basebandSink->getChannelSampleRate());
    response.getChirpChatDemodReport()->setHasCrc(m_lastMsgHasCRC);
    response.getChirpChatDemodReport()->setNbParityBits(m_lastMsgNbParityBits);
    response.getChirpChatDemodReport()->setPacketLength(m_lastMsgPacketLength);
    response.getChirpChatDemodReport()->setNbSymbols(m_lastMsgNbSymbols);
    response.getChirpChatDemodReport()->setNbCodewords(m_lastMsgNbCodewords);
    response.getChirpChatDemodReport()->setHeaderParityStatus(m_lastMsgHeaderParityStatus);
    response.getChirpChatDemodReport()->setHeaderCrcStatus(m_lastMsgHeaderCRC);
    response.getChirpChatDemodReport()->setPayloadParityStatus(m_lastMsgPayloadParityStatus);
    response.getChirpChatDemodReport()->setPayloadCrcStatus(m_lastMsgPayloadCRC);
    response.getChirpChatDemodReport()->setMessageTimestamp(new QString(m_lastMsgTimestamp));
    response.getChirpChatDemodReport()->setMessageString(new QString(m_lastMsgString));

    response.getChirpChatDemodReport()->setMessageBytes(new QList<QString *>);
    QList<QString *> *bytesStr = response.getChirpChatDemodReport()->getMessageBytes();

    for (QByteArray::const_iterator it = m_lastMsgBytes.begin(); it != m_lastMsgBytes.end(); ++it)
    {
        unsigned char b = *it;
        bytesStr->push_back(new QString(tr("%1").arg(b, 2, 16, QChar('0'))));
    }
}

void ChirpChatDemod::webapiReverseSendSettings(QList<QString>& channelSettingsKeys, const ChirpChatDemodSettings& settings, bool force)
{
    SWGrpx-100::SWGChannelSettings *swgChannelSettings = new SWGrpx-100::SWGChannelSettings();
    webapiFormatChannelSettings(channelSettingsKeys, swgChannelSettings, settings, force);

    QString channelSettingsURL = QString("http://%1:%2/rpx-100/deviceset/%3/channel/%4/settings")
            .arg(settings.m_reverseAPIAddress)
            .arg(settings.m_reverseAPIPort)
            .arg(settings.m_reverseAPIDeviceIndex)
            .arg(settings.m_reverseAPIChannelIndex);
    m_networkRequest.setUrl(QUrl(channelSettingsURL));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QBuffer *buffer = new QBuffer();
    buffer->open((QBuffer::ReadWrite));
    buffer->write(swgChannelSettings->asJson().toUtf8());
    buffer->seek(0);

    // Always use PATCH to avoid passing reverse API settings
    QNetworkReply *reply = m_networkManager->sendCustomRequest(m_networkRequest, "PATCH", buffer);
    buffer->setParent(reply);

    delete swgChannelSettings;
}

void ChirpChatDemod::sendChannelSettings(
    QList<MessageQueue*> *messageQueues,
    QList<QString>& channelSettingsKeys,
    const ChirpChatDemodSettings& settings,
    bool force)
{
    QList<MessageQueue*>::iterator it = messageQueues->begin();

    for (; it != messageQueues->end(); ++it)
    {
        SWGrpx-100::SWGChannelSettings *swgChannelSettings = new SWGrpx-100::SWGChannelSettings();
        webapiFormatChannelSettings(channelSettingsKeys, swgChannelSettings, settings, force);
        MainCore::MsgChannelSettings *msg = MainCore::MsgChannelSettings::create(
            this,
            channelSettingsKeys,
            swgChannelSettings,
            force
        );
        (*it)->push(msg);
    }
}

void ChirpChatDemod::webapiFormatChannelSettings(
        QList<QString>& channelSettingsKeys,
        SWGrpx-100::SWGChannelSettings *swgChannelSettings,
        const ChirpChatDemodSettings& settings,
        bool force
)
{
    swgChannelSettings->setDirection(0); // Single sink (Rx)
    swgChannelSettings->setOriginatorChannelIndex(getIndexInDeviceSet());
    swgChannelSettings->setOriginatorDeviceSetIndex(getDeviceSetIndex());
    swgChannelSettings->setChannelType(new QString(m_channelId));
    swgChannelSettings->setChirpChatDemodSettings(new SWGrpx-100::SWGChirpChatDemodSettings());
    SWGrpx-100::SWGChirpChatDemodSettings *swgChirpChatDemodSettings = swgChannelSettings->getChirpChatDemodSettings();

    // transfer data that has been modified. When force is on transfer all data except reverse API data

    if (channelSettingsKeys.contains("inputFrequencyOffset") || force) {
        swgChirpChatDemodSettings->setInputFrequencyOffset(settings.m_inputFrequencyOffset);
    }
    if (channelSettingsKeys.contains("bandwidthIndex") || force) {
        swgChirpChatDemodSettings->setBandwidthIndex(settings.m_bandwidthIndex);
    }
    if (channelSettingsKeys.contains("spreadFactor") || force) {
        swgChirpChatDemodSettings->setSpreadFactor(settings.m_spreadFactor);
    }
    if (channelSettingsKeys.contains("deBits") || force) {
        swgChirpChatDemodSettings->setDeBits(settings.m_deBits);
    }
    if (channelSettingsKeys.contains("fftWindow") || force) {
        swgChirpChatDemodSettings->setFftWindow((int) settings.m_fftWindow);
    }
    if (channelSettingsKeys.contains("codingScheme") || force) {
        swgChirpChatDemodSettings->setCodingScheme((int) settings.m_codingScheme);
    }
    if (channelSettingsKeys.contains("decodeActive") || force) {
        swgChirpChatDemodSettings->setDecodeActive(settings.m_decodeActive ? 1 : 0);
    }
    if (channelSettingsKeys.contains("eomSquelchTenths") || force) {
        swgChirpChatDemodSettings->setEomSquelchTenths(settings.m_eomSquelchTenths);
    }
    if (channelSettingsKeys.contains("nbSymbolsMax") || force) {
        swgChirpChatDemodSettings->setNbSymbolsMax(settings.m_nbSymbolsMax);
    }
    if (channelSettingsKeys.contains("autoNbSymbolsMax") || force) {
        swgChirpChatDemodSettings->setAutoNbSymbolsMax(settings.m_nbSymbolsMax ? 1 : 0);
    }
    if (channelSettingsKeys.contains("preambleChirps") || force) {
        swgChirpChatDemodSettings->setPreambleChirps(settings.m_preambleChirps);
    }
    if (channelSettingsKeys.contains("nbParityBits") || force) {
        swgChirpChatDemodSettings->setNbParityBits(settings.m_nbParityBits);
    }
    if (channelSettingsKeys.contains("hasCRC") || force) {
        swgChirpChatDemodSettings->setHasCrc(settings.m_hasCRC ? 1 : 0);
    }
    if (channelSettingsKeys.contains("hasHeader") || force) {
        swgChirpChatDemodSettings->setHasHeader(settings.m_hasHeader ? 1 : 0);
    }
    if (channelSettingsKeys.contains("sendViaUDP") || force) {
        swgChirpChatDemodSettings->setSendViaUdp(settings.m_sendViaUDP ? 1 : 0);
    }
    if (channelSettingsKeys.contains("udpAddress") || force) {
        swgChirpChatDemodSettings->setUdpAddress(new QString(settings.m_udpAddress));
    }
    if (channelSettingsKeys.contains("updPort") || force) {
        swgChirpChatDemodSettings->setUdpPort(settings.m_udpPort);
    }
    if (channelSettingsKeys.contains("rgbColor") || force) {
        swgChirpChatDemodSettings->setRgbColor(settings.m_rgbColor);
    }
    if (channelSettingsKeys.contains("title") || force) {
        swgChirpChatDemodSettings->setTitle(new QString(settings.m_title));
    }
}

void ChirpChatDemod::networkManagerFinished(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();

    if (replyError)
    {
        qWarning() << "ChirpChatDemod::networkManagerFinished:"
                << " error(" << (int) replyError
                << "): " << replyError
                << ": " << reply->errorString();
    }
    else
    {
        QString answer = reply->readAll();
        answer.chop(1); // remove last \n
        qDebug("ChirpChatDemod::networkManagerFinished: reply:\n%s", answer.toStdString().c_str());
    }

    reply->deleteLater();
}

bool ChirpChatDemod::getDemodActive() const
{
    return m_basebandSink->getDemodActive();
}

double ChirpChatDemod::getCurrentNoiseLevel() const
{
    return m_basebandSink->getCurrentNoiseLevel();
}

double ChirpChatDemod::getTotalPower() const
{
    return m_basebandSink->getTotalPower();
}
