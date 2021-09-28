///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
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

#ifndef _TESTSOURCE_TESTSOURCESETTINGS_H_
#define _TESTSOURCE_TESTSOURCESETTINGS_H_

#include <QString>

struct TestSourceSettings {
    typedef enum {
        FC_POS_INFRA = 0,
        FC_POS_SUPRA,
        FC_POS_CENTER
    } fcPos_t;

    typedef enum {
        AutoCorrNone,
        AutoCorrDC,
        AutoCorrDCAndIQ,
        AutoCorrLast,
    } AutoCorrOptions;

    typedef enum {
        ModulationNone,
        ModulationAM,
        ModulationFM,
        ModulationPattern0,
        ModulationPattern1,
        ModulationPattern2,
        ModulationLast
    } Modulation;

    quint64 m_centerFrequency;
	qint32 m_frequencyShift;
	quint32 m_sampleRate;
    quint32 m_log2Decim;
    fcPos_t m_fcPos;
	quint32 m_sampleSizeIndex;
	qint32 m_amplitudeBits;
    AutoCorrOptions m_autoCorrOptions;
    Modulation m_modulation;
    int m_modulationTone;   //!< 10'Hz
    int m_amModulation;     //!< percent
    int m_fmDeviation;      //!< 100'Hz
    float m_dcFactor;       //!< -1.0 < x < 1.0
    float m_iFactor;        //!< -1.0 < x < 1.0
    float m_qFactor;        //!< -1.0 < x < 1.0
    float m_phaseImbalance; //!< -1.0 < x < 1.0
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;

	TestSourceSettings();
	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
};





#endif /* _TESTSOURCE_TESTSOURCESETTINGS_H_ */
