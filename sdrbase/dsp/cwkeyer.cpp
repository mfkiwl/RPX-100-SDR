///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 F4EXB                                                      //
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

#include <stdint.h>
#include <QChar>
#include <QDebug>
#include "cwkeyer.h"
#include "util/stepfunctions.h"

MESSAGE_CLASS_DEFINITION(CWKeyer::MsgConfigureCWKeyer, Message)

/**
 * 0:  dot
 * 1:  dash
 * -1: end of sequence
 */
const signed char CWKeyer::m_asciiToMorse[128][7] = {
        {-1,0,0,0,0,0,0}, // 0
        {-1,0,0,0,0,0,0}, // 1
        {-1,0,0,0,0,0,0}, // 2
        {-1,0,0,0,0,0,0}, // 3
        {-1,0,0,0,0,0,0}, // 4
        {-1,0,0,0,0,0,0}, // 5
        {-1,0,0,0,0,0,0}, // 6
        {-1,0,0,0,0,0,0}, // 7
        {-1,0,0,0,0,0,0}, // 8
        {-1,0,0,0,0,0,0}, // 9
        {-1,0,0,0,0,0,0}, // 10
        {-1,0,0,0,0,0,0}, // 11
        {-1,0,0,0,0,0,0}, // 12
        {-1,0,0,0,0,0,0}, // 13
        {-1,0,0,0,0,0,0}, // 14
        {-1,0,0,0,0,0,0}, // 15
        {-1,0,0,0,0,0,0}, // 16
        {-1,0,0,0,0,0,0}, // 17
        {-1,0,0,0,0,0,0}, // 18
        {-1,0,0,0,0,0,0}, // 19
        {-1,0,0,0,0,0,0}, // 20
        {-1,0,0,0,0,0,0}, // 21
        {-1,0,0,0,0,0,0}, // 22
        {-1,0,0,0,0,0,0}, // 23
        {-1,0,0,0,0,0,0}, // 24
        {-1,0,0,0,0,0,0}, // 25
        {-1,0,0,0,0,0,0}, // 26
        {-1,0,0,0,0,0,0}, // 27
        {-1,0,0,0,0,0,0}, // 28
        {-1,0,0,0,0,0,0}, // 29
        {-1,0,0,0,0,0,0}, // 30
        {-1,0,0,0,0,0,0}, // 31
        {-1,0,0,0,0,0,0}, // 32 space is treated as word separator
        {1,0,1,0,1,1,-1}, // 33 !
        {0,1,0,0,1,0,-1}, // 34 "
        {-1,0,0,0,0,0,0}, // 35
        {-1,0,0,0,0,0,0}, // 36
        {-1,0,0,0,0,0,0}, // 37
        {-1,0,0,0,0,0,0}, // 38
        {0,1,1,1,1,0,-1}, // 39 '
        {1,0,1,1,0,1,-1}, // 40 (
        {1,0,1,1,0,1,-1}, // 41 )
        {-1,0,0,0,0,0,0}, // 42
        {0,1,0,1,0,-1,0}, // 43 +
        {1,1,0,0,1,1,-1}, // 44 ,
        {1,0,0,0,0,1,-1}, // 45 -
        {0,1,0,1,0,1,-1}, // 46 .
        {1,0,0,1,0,-1,0}, // 47 /
        {1,1,1,1,1,-1,0}, // 48 0
        {0,1,1,1,1,-1,0}, // 49 1
        {0,0,1,1,1,-1,0}, // 50 2
        {0,0,0,1,1,-1,0}, // 51 3
        {0,0,0,0,1,-1,0}, // 52 4
        {0,0,0,0,0,-1,0}, // 53 5
        {1,0,0,0,0,-1,0}, // 54 6
        {1,1,0,0,0,-1,0}, // 55 7
        {1,1,1,0,0,-1,0}, // 56 8
        {1,1,1,1,0,-1,0}, // 57 9
        {1,1,1,0,0,0,-1}, // 58 :
        {1,0,1,0,1,0,-1}, // 59 ;
        {-1,0,0,0,0,0,0}, // 60 <
        {1,0,0,0,1,-1,0}, // 61 =
        {-1,0,0,0,0,0,0}, // 62 >
        {0,0,1,1,0,0,-1}, // 63 ?
        {0,1,1,0,1,0,-1}, // 64 @
        {0,1,-1,0,0,0,0}, // 65 A
        {1,0,0,0,-1,0,0}, // 66 B
        {1,0,1,0,-1,0,0}, // 67 C
        {1,0,0,-1,0,0,0}, // 68 D
        {0,-1,0,0,0,0,0}, // 69 E
        {0,0,1,0,-1,0,0}, // 70 F
        {1,1,0,-1,0,0,0}, // 71 G
        {0,0,0,0,-1,0,0}, // 72 H
        {0,0,-1,0,0,0,0}, // 73 I
        {0,1,1,1,-1,0,0}, // 74 J
        {1,0,1,-1,0,0,0}, // 75 K
        {0,1,0,0,-1,0,0}, // 76 L
        {1,1,-1,0,0,0,0}, // 77 M
        {1,0,-1,0,0,0,0}, // 78 N
        {1,1,1,-1,0,0,0}, // 79 O
        {0,1,1,0,-1,0,0}, // 80 P
        {1,1,0,1,-1,0,0}, // 81 Q
        {0,1,0,-1,0,0,0}, // 82 R
        {0,0,0,-1,0,0,0}, // 83 S
        {1,-1,0,0,0,0,0}, // 84 T
        {0,0,1,-1,0,0,0}, // 85 U
        {0,0,0,1,-1,0,0}, // 86 V
        {0,1,1,-1,0,0,0}, // 87 W
        {1,0,0,1,-1,0,0}, // 88 X
        {1,0,1,1,-1,0,0}, // 89 Y
        {1,1,0,0,-1,0,0}, // 90 Z
        {-1,0,0,0,0,0,0}, // 91 [
        {-1,0,0,0,0,0,0}, // 92 back /
        {-1,0,0,0,0,0,0}, // 93 ]
        {-1,0,0,0,0,0,0}, // 94 ^
        {-1,0,0,0,0,0,0}, // 95 _
        {-1,0,0,0,0,0,0}, // 96 `
        {0,1,-1,0,0,0,0}, // 97 A lowercase same as uppercase
        {1,0,0,0,-1,0,0}, // 98 B
        {1,0,1,0,-1,0,0}, // 99 C
        {1,0,0,-1,0,0,0}, // 100 D
        {0,-1,0,0,0,0,0}, // 101 E
        {0,0,1,0,-1,0,0}, // 102 F
        {1,1,0,-1,0,0,0}, // 103 G
        {0,0,0,0,-1,0,0}, // 104 H
        {0,0,-1,0,0,0,0}, // 105 I
        {0,1,1,1,-1,0,0}, // 106 J
        {1,0,1,-1,0,0,0}, // 107 K
        {0,1,0,0,-1,0,0}, // 108 L
        {1,1,-1,0,0,0,0}, // 109 M
        {1,0,-1,0,0,0,0}, // 110 N
        {1,1,1,-1,0,0,0}, // 111 O
        {0,1,1,0,-1,0,0}, // 112 P
        {1,1,0,1,-1,0,0}, // 113 Q
        {0,1,0,-1,0,0,0}, // 114 R
        {0,0,0,-1,0,0,0}, // 115 S
        {1,-1,0,0,0,0,0}, // 116 T
        {0,0,1,-1,0,0,0}, // 117 U
        {0,0,0,1,-1,0,0}, // 118 V
        {0,1,1,-1,0,0,0}, // 119 W
        {1,0,0,1,-1,0,0}, // 120 X
        {1,0,1,1,-1,0,0}, // 121 Y
        {1,1,0,0,-1,0,0}, // 122 Z
        {-1,0,0,0,0,0,0}, // 123 {
        {-1,0,0,0,0,0,0}, // 124 |
        {-1,0,0,0,0,0,0}, // 125 }
        {-1,0,0,0,0,0,0}, // 126 ~
        {-1,0,0,0,0,0,0}, // 127 DEL
};

CWKeyer::CWKeyer() :
    m_mutex(QMutex::Recursive),
    m_textPointer(0),
	m_elementPointer(0),
    m_samplePointer(0),
    m_elementSpace(false),
    m_characterSpace(false),
    m_key(false),
    m_dot(false),
    m_dash(false),
    m_elementOn(false),
	m_asciiChar('\0'),
    m_keyIambicState(KeySilent),
	m_textState(TextStart)
{
    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));
    applySettings(m_settings, true);
}

CWKeyer::~CWKeyer()
{
}

void CWKeyer::setSampleRate(int sampleRate)
{
    CWKeyerSettings settings = m_settings;
    settings.m_sampleRate = sampleRate;
    MsgConfigureCWKeyer *msg = MsgConfigureCWKeyer::create(settings, false);
    m_inputMessageQueue.push(msg);
}

int CWKeyer::getSample()
{
    QMutexLocker mutexLocker(&m_mutex);

    if (m_settings.m_mode == CWKeyerSettings::CWText)
    {
    	nextStateText();
        return m_key ? 1 : 0;
    }
    else if ((m_settings.m_mode == CWKeyerSettings::CWDots) || (m_settings.m_mode == CWKeyerSettings::CWDashes))
    {
        nextStateIambic();
        return m_key ? 1 : 0;
    }
    else if (m_settings.m_mode == CWKeyerSettings::CWKeyboard)
    {
        if (m_settings.m_keyboardIambic)
        {
            nextStateIambic();
            return m_key ? 1 : 0;
        }
        else
        {
            return (m_dot || m_dash) ? 1 : 0;
        }
    }
    else
    {
    	return 0;
    }
}

void CWKeyer::nextStateIambic()
{
    switch (m_keyIambicState)
    {
    case KeySilent:
        if (m_dot)
        {
            m_keyIambicState = KeyDot;
            m_samplePointer = 0;
        }
        else if (m_dash)
        {
            m_keyIambicState = KeyDash;
            m_samplePointer = 0;
        }

        m_key = false;
        break;
    case KeyDot:
        if (m_samplePointer < m_dotLength) // dot key
        {
            m_key = true;
            m_samplePointer++;
        }
        else if (m_samplePointer < 2*m_dotLength) // dot silence (+1 dot length)
        {
            m_key = false;
            m_samplePointer++;
        }
        else // end
        {
            if (m_dash)
            {
                m_keyIambicState = KeyDash;
            }
            else if (!m_dot)
            {
                m_keyIambicState = KeySilent;
            }

            m_samplePointer = 0;
            m_key = false;
        }
        break;
    case KeyDash:
        if (m_samplePointer < 3*m_dotLength) // dash key
        {
            m_key = true;
            m_samplePointer++;
        }
        else if (m_samplePointer < 4*m_dotLength) // dash silence (+1 dot length)
        {
            m_key = false;
            m_samplePointer++;
        }
        else // end
        {
            if (m_dot)
            {
                m_keyIambicState = KeyDot;
            }
            else if (!m_dash)
            {
                m_keyIambicState = KeySilent;
            }

            m_samplePointer = 0;
            m_key = false;
        }
        break;
    default:
        m_samplePointer = 0;
        m_key = false;
        break;
    }
}

void CWKeyer::nextStateText()
{
	switch (m_textState)
	{
	case TextStart:
		m_samplePointer = 0;
		m_elementPointer = 0;
		m_textPointer = 0;
		m_textState = TextStartChar;
		m_key = false;
		m_dot = false;
		m_dash = false;
		break;
	case TextStartChar:
		m_samplePointer = 0;
		m_elementPointer = 0;
		if (m_textPointer < m_settings.m_text.length())
		{
            m_asciiChar = (m_settings.m_text.at(m_textPointer)).toLatin1();
//            qDebug() << "CWKeyer::nextStateText: TextStartChar: " << m_asciiChar;

            if (m_asciiChar < 0) { // non ASCII
                m_asciiChar = 0;
            }

            if (m_asciiChar == ' ')
            {
                m_textState = TextWordSpace;
            }
            else
            {
                m_textState = TextStartElement;
            }
            m_textPointer++;
		}
		else // end of text
		{
		    m_textState = TextEnd;
		}
		break;
	case TextStartElement:
		m_samplePointer = 0;
//        qDebug() << "CWKeyer::nextStateText: TextStartElement: " << (int) m_asciiToMorse[m_asciiChar][m_elementPointer];
		if (m_asciiToMorse[(uint8_t)(m_asciiChar&0x7F)][m_elementPointer] == -1) // end of morse character
		{
		    m_elementPointer = 0;
		    m_textState = TextCharSpace;
		}
		else
		{
            if (m_asciiToMorse[(uint8_t)(m_asciiChar&0x7F)][m_elementPointer] == 0) // dot
            {
                m_dot = true;
                m_dash = false;
            }
            else // dash
            {
                m_dot = false;
                m_dash = true;
            }
	        m_keyIambicState = KeySilent; // reset iambic state
	        nextStateIambic(); // init dash or dot
            m_dot = false; // release keys
            m_dash = false;
            m_textState = TextElement;
            m_elementPointer++;
		}
		break;
	case TextElement:
		nextStateIambic(); // dash or dot
		if (m_keyIambicState == KeySilent) // done
		{
			m_textState = TextStartElement; // next element
		}
		break;
	case TextCharSpace:
		if (m_samplePointer < 2*m_dotLength) // - 1 dot length space from element
		{
			m_samplePointer++;
			m_key = false;
		}
		else
		{
			m_textState = TextStartChar;
		}
		break;
	case TextWordSpace:
		if (m_samplePointer < 4*m_dotLength) // - 3 dot length space from character
		{
			m_samplePointer++;
			m_key = false;
		}
		else
		{
			m_textState = TextStartChar;
		}
		break;
	case TextEnd:
	    if (m_settings.m_loop)
	    {
	        m_textState = TextStart;
	    }
        m_key = false;
        m_dot = false;
        m_dash = false;
	    break;
	case TextStop:
	default:
		m_key = false;
        m_dot = false;
        m_dash = false;
		break;
	}
}

bool CWKeyer::eom()
{
    return !(m_textPointer < m_settings.m_text.length());
}

void CWKeyer::setKeyboardDots()
{
    m_dot = true;
    m_dash = false;
    m_keyIambicState = KeySilent;
}

void CWKeyer::setKeyboardDashes()
{
    m_dot = false;
    m_dash = true;
    m_keyIambicState = KeySilent;
}

void CWKeyer::setKeyboardSilence()
{
    m_dot = false;
    m_dash = false;
}

CWSmoother::CWSmoother() :
        m_fadeInCounter(0),
        m_fadeOutCounter(0),
        m_nbFadeSamples(0),
        m_fadeInSamples(0),
        m_fadeOutSamples(0)
{
    setNbFadeSamples(192); // default is 4 ms at 48 kHz sample rate
}

CWSmoother::~CWSmoother()
{
    delete[] m_fadeInSamples;
    delete[] m_fadeOutSamples;
}

void CWSmoother::setNbFadeSamples(unsigned int nbFadeSamples)
{
    if (nbFadeSamples != m_nbFadeSamples)
    {
        QMutexLocker mutexLocker(&m_mutex);

        m_nbFadeSamples = nbFadeSamples;

        if (m_fadeInSamples) delete[] m_fadeInSamples;
        if (m_fadeOutSamples) delete[] m_fadeOutSamples;

        m_fadeInSamples = new float[m_nbFadeSamples];
        m_fadeOutSamples = new float[m_nbFadeSamples];

        for (unsigned int i = 0; i < m_nbFadeSamples; i++)
        {
            float x = i/ (float) m_nbFadeSamples;
            float y = 1.0f -x;

            m_fadeInSamples[i] = StepFunctions::smootherstep(x);
            m_fadeOutSamples[i] = StepFunctions::smootherstep(y);
        }

        m_fadeInCounter = 0;
        m_fadeOutCounter = 0;
    }
}

bool CWSmoother::getFadeSample(bool on, float& sample)
{
    QMutexLocker mutexLocker(&m_mutex);

    if (on)
    {
        m_fadeOutCounter = 0;

        if (m_fadeInCounter < m_nbFadeSamples)
        {
            sample = m_fadeInSamples[m_fadeInCounter];
            m_fadeInCounter++;
            return true;
        }
        else
        {
            sample = 1.0f;
            return false;
        }
    }
    else
    {
        m_fadeInCounter = 0;

        if (m_fadeOutCounter < m_nbFadeSamples)
        {
            sample = m_fadeOutSamples[m_fadeOutCounter];
            m_fadeOutCounter++;
            return true;
        }
        else
        {
            sample = 0.0f;
            return false;
        }
    }
}

bool CWKeyer::handleMessage(const Message& cmd)
{
    if (MsgConfigureCWKeyer::match(cmd))
    {
        MsgConfigureCWKeyer& cfg = (MsgConfigureCWKeyer&) cmd;
        qDebug() << "CWKeyer::handleMessage: MsgConfigureCWKeyer";

        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }

    return true;
}

void CWKeyer::handleInputMessages()
{
	Message* message;

	while ((message = m_inputMessageQueue.pop()) != 0)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}

void CWKeyer::applySettings(const CWKeyerSettings& settings, bool force)
{
    qDebug() << "CWKeyer::applySettings: "
        << " m_dashKey: " << settings.m_dashKey
        << " m_dashKeyModifiers: " << settings.m_dashKeyModifiers
        << " m_dotKey: " << settings.m_dotKey
        << " m_dotKeyModifiers: " << settings.m_dotKeyModifiers
        << " m_keyboardIambic: " << settings.m_keyboardIambic
        << " m_loop: " << settings.m_loop
        << " m_mode: " << settings.m_mode
        << " m_sampleRate: " << settings.m_sampleRate
        << " m_text: " << settings.m_text
        << " m_wpm: " << settings.m_wpm;

    if ((m_settings.m_wpm != settings.m_wpm)
     || (m_settings.m_sampleRate != settings.m_sampleRate) || force)
    {
        QMutexLocker mutexLocker(&m_mutex);
        m_dotLength = (int) ((1.2f / settings.m_wpm) * settings.m_sampleRate);
        m_cwSmoother.setNbFadeSamples(m_dotLength/10); // 10% the dot time
    }

    if ((m_settings.m_mode != settings.m_mode) || force)
    {
        QMutexLocker mutexLocker(&m_mutex);

        if (settings.m_mode == CWKeyerSettings::CWText)
        {
            m_textState = TextStart;
        }
        else if (settings.m_mode == CWKeyerSettings::CWDots)
        {
            m_dot = true;
            m_dash = false;
            m_keyIambicState = KeySilent;
        }
        else if (settings.m_mode == CWKeyerSettings::CWDashes)
        {
            m_dot = false;
            m_dash = true;
            m_keyIambicState = KeySilent;
        }
        else if (settings.m_mode == CWKeyerSettings::CWKeyboard)
        {
            m_dot = false;
            m_dash = false;
            m_keyIambicState = KeySilent;
        }
    }

    if ((m_settings.m_text != settings.m_text) || force)
    {
        QMutexLocker mutexLocker(&m_mutex);
        m_textState = TextStart;
    }

    m_settings = settings;
}

void CWKeyer::webapiSettingsPutPatch(
    const QStringList& channelSettingsKeys,
    CWKeyerSettings& cwKeyerSettings,
    SWGSDRangel::SWGCWKeyerSettings *apiCwKeyerSettings
)
{
    if (channelSettingsKeys.contains("cwKeyer.loop")) {
        cwKeyerSettings.m_loop = apiCwKeyerSettings->getLoop() != 0;
    }
    if (channelSettingsKeys.contains("cwKeyer.mode")) {
        cwKeyerSettings.m_mode = (CWKeyerSettings::CWMode) apiCwKeyerSettings->getMode();
    }
    if (channelSettingsKeys.contains("cwKeyer.text")) {
        cwKeyerSettings.m_text = *apiCwKeyerSettings->getText();
    }
    if (channelSettingsKeys.contains("cwKeyer.sampleRate")) {
        cwKeyerSettings.m_sampleRate = apiCwKeyerSettings->getSampleRate();
    }
    if (channelSettingsKeys.contains("cwKeyer.wpm")) {
        cwKeyerSettings.m_wpm = apiCwKeyerSettings->getWpm();
    }
    if (channelSettingsKeys.contains("cwKeyer.keyboardIambic")) {
        cwKeyerSettings.m_keyboardIambic = apiCwKeyerSettings->getKeyboardIambic() != 0;
    }
    if (channelSettingsKeys.contains("cwKeyer.dotKey")) {
        cwKeyerSettings.m_dotKey = (Qt::Key) apiCwKeyerSettings->getDotKey();
    }
    if (channelSettingsKeys.contains("cwKeyer.dotKeyModifiers")) {
        cwKeyerSettings.m_dotKeyModifiers = (Qt::KeyboardModifiers) apiCwKeyerSettings->getDotKeyModifiers();
    }
    if (channelSettingsKeys.contains("cwKeyer.dashKey")) {
        cwKeyerSettings.m_dashKey = (Qt::Key) apiCwKeyerSettings->getDashKey();
    }
    if (channelSettingsKeys.contains("cwKeyer.dashKeyModifiers")) {
        cwKeyerSettings.m_dashKeyModifiers = (Qt::KeyboardModifiers) apiCwKeyerSettings->getDashKeyModifiers();
    }
}

void CWKeyer::webapiFormatChannelSettings(
    SWGSDRangel::SWGCWKeyerSettings *apiCwKeyerSettings,
    const CWKeyerSettings& cwKeyerSettings
)
{
    apiCwKeyerSettings->setLoop(cwKeyerSettings.m_loop ? 1 : 0);
    apiCwKeyerSettings->setMode((int) cwKeyerSettings.m_mode);
    apiCwKeyerSettings->setSampleRate(cwKeyerSettings.m_sampleRate);

    if (apiCwKeyerSettings->getText()) {
        *apiCwKeyerSettings->getText() = cwKeyerSettings.m_text;
    } else {
        apiCwKeyerSettings->setText(new QString(cwKeyerSettings.m_text));
    }

    apiCwKeyerSettings->setWpm(cwKeyerSettings.m_wpm);
    apiCwKeyerSettings->setKeyboardIambic(cwKeyerSettings.m_keyboardIambic ? 1 : 0);
    apiCwKeyerSettings->setDotKey((int) cwKeyerSettings.m_dotKey);
    apiCwKeyerSettings->setDotKeyModifiers((unsigned int) cwKeyerSettings.m_dotKeyModifiers);
    apiCwKeyerSettings->setDashKey((int) cwKeyerSettings.m_dashKey);
    apiCwKeyerSettings->setDashKeyModifiers((unsigned int) cwKeyerSettings.m_dashKeyModifiers);
}
