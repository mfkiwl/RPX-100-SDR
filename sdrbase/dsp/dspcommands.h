///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
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

#ifndef INCLUDE_DSPCOMMANDS_H
#define INCLUDE_DSPCOMMANDS_H

#include <QString>
#include "util/message.h"
#include "fftwindow.h"
#include "export.h"

class DeviceSampleSource;
class BasebandSampleSink;
class DeviceSampleSink;
class BasebandSampleSource;
class AudioFifo;

class SDRBASE_API DSPAcquisitionInit : public Message {
	MESSAGE_CLASS_DECLARATION
};

class SDRBASE_API DSPAcquisitionStart : public Message {
	MESSAGE_CLASS_DECLARATION
};

class SDRBASE_API DSPAcquisitionStop : public Message {
	MESSAGE_CLASS_DECLARATION
};

class SDRBASE_API DSPGenerationInit : public Message {
	MESSAGE_CLASS_DECLARATION
};

class SDRBASE_API DSPGenerationStart : public Message {
	MESSAGE_CLASS_DECLARATION
};

class SDRBASE_API DSPGenerationStop : public Message {
	MESSAGE_CLASS_DECLARATION
};

class SDRBASE_API DSPGetSourceDeviceDescription : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	void setDeviceDescription(const QString& text) { m_deviceDescription = text; }
	const QString& getDeviceDescription() const { return m_deviceDescription; }

private:
	QString m_deviceDescription;
};

class SDRBASE_API DSPGetSinkDeviceDescription : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	void setDeviceDescription(const QString& text) { m_deviceDescription = text; }
	const QString& getDeviceDescription() const { return m_deviceDescription; }

private:
	QString m_deviceDescription;
};

class SDRBASE_API DSPGetErrorMessage : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	void setErrorMessage(const QString& text) { m_errorMessage = text; }
	const QString& getErrorMessage() const { return m_errorMessage; }

private:
	QString m_errorMessage;
};

class SDRBASE_API DSPSetSource : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPSetSource(DeviceSampleSource* sampleSource) : Message(), m_sampleSource(sampleSource) { }

	DeviceSampleSource* getSampleSource() const { return m_sampleSource; }

private:
	DeviceSampleSource* m_sampleSource;
};

class SDRBASE_API DSPSetSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPSetSink(DeviceSampleSink* sampleSink) : Message(), m_sampleSink(sampleSink) { }

	DeviceSampleSink* getSampleSink() const { return m_sampleSink; }

private:
	DeviceSampleSink* m_sampleSink;
};

class SDRBASE_API DSPAddBasebandSampleSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPAddBasebandSampleSink(BasebandSampleSink* sampleSink) : Message(), m_sampleSink(sampleSink) { }

	BasebandSampleSink* getSampleSink() const { return m_sampleSink; }

private:
	BasebandSampleSink* m_sampleSink;
};

class SDRBASE_API DSPAddSpectrumSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPAddSpectrumSink(BasebandSampleSink* sampleSink) : Message(), m_sampleSink(sampleSink) { }

	BasebandSampleSink* getSampleSink() const { return m_sampleSink; }

private:
	BasebandSampleSink* m_sampleSink;
};

class SDRBASE_API DSPAddBasebandSampleSource : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPAddBasebandSampleSource(BasebandSampleSource* sampleSource) : Message(), m_sampleSource(sampleSource) { }

	BasebandSampleSource* getSampleSource() const { return m_sampleSource; }

private:
	BasebandSampleSource* m_sampleSource;
};

class SDRBASE_API DSPRemoveBasebandSampleSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPRemoveBasebandSampleSink(BasebandSampleSink* sampleSink) : Message(), m_sampleSink(sampleSink) { }

	BasebandSampleSink* getSampleSink() const { return m_sampleSink; }

private:
	BasebandSampleSink* m_sampleSink;
};

class SDRBASE_API DSPRemoveSpectrumSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPRemoveSpectrumSink(BasebandSampleSink* sampleSink) : Message(), m_sampleSink(sampleSink) { }

	BasebandSampleSink* getSampleSink() const { return m_sampleSink; }

private:
	BasebandSampleSink* m_sampleSink;
};

class SDRBASE_API DSPRemoveBasebandSampleSource : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPRemoveBasebandSampleSource(BasebandSampleSource* sampleSource) : Message(), m_sampleSource(sampleSource) { }

	BasebandSampleSource* getSampleSource() const { return m_sampleSource; }

private:
	BasebandSampleSource* m_sampleSource;
};

class SDRBASE_API DSPAddAudioSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPAddAudioSink(AudioFifo* audioFifo) : Message(), m_audioFifo(audioFifo) { }

	AudioFifo* getAudioFifo() const { return m_audioFifo; }

private:
	AudioFifo* m_audioFifo;
};

class SDRBASE_API DSPRemoveAudioSink : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPRemoveAudioSink(AudioFifo* audioFifo) : Message(), m_audioFifo(audioFifo) { }

	AudioFifo* getAudioFifo() const { return m_audioFifo; }

private:
	AudioFifo* m_audioFifo;
};

class SDRBASE_API DSPConfigureCorrection : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPConfigureCorrection(bool dcOffsetCorrection, bool iqImbalanceCorrection) :
		Message(),
		m_dcOffsetCorrection(dcOffsetCorrection),
		m_iqImbalanceCorrection(iqImbalanceCorrection)
	{ }

	bool getDCOffsetCorrection() const { return m_dcOffsetCorrection; }
	bool getIQImbalanceCorrection() const { return m_iqImbalanceCorrection; }

private:
	bool m_dcOffsetCorrection;
	bool m_iqImbalanceCorrection;

};

class SDRBASE_API DSPEngineReport : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPEngineReport(int sampleRate, quint64 centerFrequency) :
		Message(),
		m_sampleRate(sampleRate),
		m_centerFrequency(centerFrequency)
	{ }

	int getSampleRate() const { return m_sampleRate; }
	quint64 getCenterFrequency() const { return m_centerFrequency; }

private:
	int m_sampleRate;
	quint64 m_centerFrequency;
};

class SDRBASE_API DSPConfigureScopeVis : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPConfigureScopeVis(int triggerChannel, Real triggerLevelHigh, Real triggerLevelLow) :
		Message(),
		m_triggerChannel(triggerChannel),
		m_triggerLevelHigh(triggerLevelHigh),
		m_triggerLevelLow(triggerLevelLow)
	{ }

	int getTriggerChannel() const { return m_triggerChannel; }
	Real getTriggerLevelHigh() const { return m_triggerLevelHigh; }
	Real getTriggerLevelLow() const { return m_triggerLevelLow; }

private:
	int m_triggerChannel;
	Real m_triggerLevelHigh;
	Real m_triggerLevelLow;
};

class SDRBASE_API DSPSignalNotification : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPSignalNotification(int samplerate, qint64 centerFrequency) :
		Message(),
		m_sampleRate(samplerate),
		m_centerFrequency(centerFrequency)
	{ }

	int getSampleRate() const { return m_sampleRate; }
	qint64 getCenterFrequency() const { return m_centerFrequency; }

private:
	int m_sampleRate;
	qint64 m_centerFrequency;
};

class SDRBASE_API DSPMIMOSignalNotification : public Message {
	MESSAGE_CLASS_DECLARATION
public:
	DSPMIMOSignalNotification(int samplerate, qint64 centerFrequency, bool sourceOrSink, unsigned int index) :
		Message(),
		m_sampleRate(samplerate),
		m_centerFrequency(centerFrequency),
		m_sourceOrSink(sourceOrSink),
		m_index(index)
	{ }
	int getSampleRate() const { return m_sampleRate; }
	qint64 getCenterFrequency() const { return m_centerFrequency; }
	bool getSourceOrSink() const { return m_sourceOrSink; }
	unsigned int getIndex() const { return m_index; }
private:
	int m_sampleRate;
	qint64 m_centerFrequency;
	bool m_sourceOrSink;
	unsigned int m_index;
};

class SDRBASE_API DSPConfigureChannelizer : public Message {
	MESSAGE_CLASS_DECLARATION

public:
	DSPConfigureChannelizer(int sampleRate, int centerFrequency) :
		Message(),
		m_sampleRate(sampleRate),
		m_centerFrequency(centerFrequency)
	{ }

	int getSampleRate() const { return m_sampleRate; }
	int getCenterFrequency() const { return m_centerFrequency; }

private:
	int m_sampleRate;
	int m_centerFrequency;
};

class SDRBASE_API DSPConfigureAudio : public Message {
    MESSAGE_CLASS_DECLARATION

public:
    enum AudioType
    {
        AudioInput,
        AudioOutput
    };

    DSPConfigureAudio(int sampleRate, AudioType audioType) :
        m_sampleRate(sampleRate),
        m_autioType(audioType)
    { }

    int getSampleRate() const { return m_sampleRate; }
    AudioType getAudioType() const { return m_autioType; }

private:
    int m_sampleRate;
    AudioType m_autioType;
};

#endif // INCLUDE_DSPCOMMANDS_H
