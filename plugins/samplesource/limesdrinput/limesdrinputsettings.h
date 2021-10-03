///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Bernhard Isemann, oe3bia                                   //
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

#ifndef PLUGINS_SAMPLESOURCE_LIMESDRINPUT_LIMESDRINPUTSETTINGS_H_
#define PLUGINS_SAMPLESOURCE_LIMESDRINPUT_LIMESDRINPUTSETTINGS_H_

#include <QByteArray>
#include <QString>
#include <stdint.h>

/**
 * These are the settings individual to each hardware channel or software Rx chain
 * Plus the settings to be saved in the presets
 */
struct LimeSDRInputSettings
{
    enum PathRFE
    {
        PATH_RFE_NONE = 0,
        PATH_RFE_LNAH,
        PATH_RFE_LNAL,
        PATH_RFE_LNAW,
        PATH_RFE_LB1,
        PATH_RFE_LB2
    };

    typedef enum {
        GAIN_AUTO,
        GAIN_MANUAL
    } GainMode;

    // global settings to be saved
    uint64_t m_centerFrequency;
    int      m_devSampleRate;
    uint32_t m_log2HardDecim;
    // channel settings
    bool     m_dcBlock;
    bool     m_iqCorrection;
    uint32_t m_log2SoftDecim;
    float    m_lpfBW;        //!< LMS amalog lowpass filter bandwidth (Hz)
    bool     m_lpfFIREnable; //!< Enable LMS digital lowpass FIR filters
    float    m_lpfFIRBW;     //!< LMS digital lowpass FIR filters bandwidth (Hz)
    uint32_t m_gain;         //!< Optimally distributed gain (dB)
    bool     m_ncoEnable;    //!< Enable TSP NCO and mixing
    int      m_ncoFrequency; //!< Actual NCO frequency (the resulting frequency with mixing is displayed)
    PathRFE  m_antennaPath;
    GainMode m_gainMode;     //!< Gain mode: auto or manual
    uint32_t m_lnaGain;      //!< Manual LAN gain
    uint32_t m_tiaGain;      //!< Manual TIA gain
    uint32_t m_pgaGain;      //!< Manual PGA gain
    bool     m_extClock;     //!< True if external clock source
    uint32_t m_extClockFreq; //!< Frequency (Hz) of external clock source
    bool     m_transverterMode;
    qint64   m_transverterDeltaFrequency;
    bool     m_iqOrder;
    uint8_t  m_gpioDir;      //!< GPIO pin direction LSB first; 0 input, 1 output
    uint8_t  m_gpioPins;     //!< GPIO pins to write; LSB first
    bool     m_useReverseAPI;
    QString  m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIDeviceIndex;

    LimeSDRInputSettings();
    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
};

#endif /* PLUGINS_SAMPLESOURCE_LIMESDRINPUT_LIMESDRINPUTSETTINGS_H_ */
