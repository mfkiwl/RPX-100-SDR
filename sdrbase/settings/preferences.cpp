#include "settings/preferences.h"
#include "util/simpleserializer.h"

Preferences::Preferences()
{
	resetToDefaults();
}

void Preferences::resetToDefaults()
{
	m_sourceDevice.clear();
	m_audioType.clear();
	m_audioDevice.clear();
	m_sourceIndex = 0;
        m_stationName = "Home";
	m_latitude = 49.012423; // Set an interesting location so map doesn't open up in the middle of the ocean
	m_longitude = 8.418125;
        m_altitude = 0.0f;
	m_useLogFile = false;
	m_logFileName = "RPX100.log";
	m_consoleMinLogLevel = QtDebugMsg;
    m_fileMinLogLevel = QtDebugMsg;
}

QByteArray Preferences::serialize() const
{
	SimpleSerializer s(1);
	s.writeString(2, m_sourceDevice);
	s.writeString(3, m_audioType);
	s.writeString(4, m_audioDevice);
	s.writeS32(5, m_sourceIndex);
	s.writeFloat(6, m_latitude);
	s.writeFloat(7, m_longitude);
	s.writeS32(8, (int) m_consoleMinLogLevel);
	s.writeBool(9, m_useLogFile);
	s.writeString(10, m_logFileName);
    s.writeS32(11, (int) m_fileMinLogLevel);
        s.writeString(12, m_stationName);
        s.writeFloat(13, m_altitude);
	return s.final();
}

bool Preferences::deserialize(const QByteArray& data)
{
    int tmpInt;

	SimpleDeserializer d(data);

	if(!d.isValid()) {
		resetToDefaults();
		return false;
	}

	if(d.getVersion() == 1)
	{
		d.readString(2, &m_sourceDevice);
		d.readString(3, &m_audioType);
		d.readString(4, &m_audioDevice);
		d.readS32(5, &m_sourceIndex, 0);
		d.readFloat(6, &m_latitude, 0.0f);
		d.readFloat(7, &m_longitude, 0.0f);

		d.readS32(8, &tmpInt, (int) QtDebugMsg);

		if ((tmpInt == (int) QtDebugMsg) ||
		    (tmpInt == (int) QtInfoMsg) ||
		    (tmpInt == (int) QtWarningMsg) ||
		    (tmpInt == (int) QtCriticalMsg) ||
		    (tmpInt == (int) QtFatalMsg)) {
            m_consoleMinLogLevel = (QtMsgType) tmpInt;
		} else {
		    m_consoleMinLogLevel = QtDebugMsg;
		}

		d.readBool(9, &m_useLogFile, false);
		d.readString(10, &m_logFileName, "RPX100.log");

        d.readS32(11, &tmpInt, (int) QtDebugMsg);
        d.readString(12, &m_stationName, "Home");
        d.readFloat(13, &m_altitude, 0.0f);

        if ((tmpInt == (int) QtDebugMsg) ||
            (tmpInt == (int) QtInfoMsg) ||
            (tmpInt == (int) QtWarningMsg) ||
            (tmpInt == (int) QtCriticalMsg) ||
            (tmpInt == (int) QtFatalMsg)) {
            m_fileMinLogLevel = (QtMsgType) tmpInt;
        } else {
            m_fileMinLogLevel = QtDebugMsg;
        }

		return true;
	} else
	{
		resetToDefaults();
		return false;
	}
}
