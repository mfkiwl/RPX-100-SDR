///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia.                                  //
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

#ifndef SDRBASE_DSP_SPECTRUMSETTNGS_H
#define SDRBASE_DSP_SPECTRUMSETTNGS_H

#include <QByteArray>
#include <QString>

#include "export.h"
#include "dsp/dsptypes.h"
#include "dsp/fftwindow.h"
#include "dsp/spectrummarkers.h"
#include "settings/serializable.h"

class SDRBASE_API SpectrumSettings : public Serializable
{
public:
    enum AveragingMode
    {
        AvgModeNone,
        AvgModeMoving,
        AvgModeFixed,
        AvgModeMax
    };

    enum MarkersDisplay
    {
        MarkersDisplayNone,
        MarkersDisplaySpectrum
    };

	int m_fftSize;
	int m_fftOverlap;
	FFTWindow::Function m_fftWindow;
	Real m_refLevel;
	Real m_powerRange;
	int m_fpsPeriodMs; //!< FPS capping period in ms FPS = 1000/m_fpsPeriodMs. If zero: no limit.
	int m_decay;
	int m_decayDivisor;
	int m_histogramStroke;
	int m_displayGridIntensity;
	int m_displayTraceIntensity;
	bool m_displayWaterfall;
	bool m_invertedWaterfall;
    Real m_waterfallShare;
	bool m_displayMaxHold;
	bool m_displayCurrent;
	bool m_displayHistogram;
	bool m_displayGrid;
	AveragingMode m_averagingMode;
	int m_averagingIndex;
	unsigned int m_averagingValue;
	bool m_linear; //!< linear else logarithmic scale
    bool m_ssb;    //!< SSB display with spectrum center at start of array or display - else spectrum center is on center
    bool m_usb;    //!< USB display with increasing frequencies towads the right - else decreasing frequencies
    QString m_wsSpectrumAddress;
    uint16_t m_wsSpectrumPort;
	QList<SpectrumHistogramMarker> m_histogramMarkers;
	QList<SpectrumWaterfallMarker> m_waterfallMarkers;
	static const int m_log2FFTSizeMin = 6;   // 64
	static const int m_log2FFTSizeMax = 15;  // 32k

    SpectrumSettings();
	virtual ~SpectrumSettings();
    void resetToDefaults();

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

	QList<SpectrumHistogramMarker>& getHistogramMarkers() { return m_histogramMarkers; }
	QList<SpectrumWaterfallMarker>& getWaterfallMarkers() { return m_waterfallMarkers; }

    static int getAveragingMaxScale(AveragingMode averagingMode); //!< Max power of 10 multiplier to 2,5,10 base ex: 2 -> 2,5,10,20,50,100,200,500,1000
    static int getAveragingValue(int averagingIndex, AveragingMode averagingMode);
    static int getAveragingIndex(int averagingValue, AveragingMode averagingMode);
	static uint64_t getMaxAveragingValue(int fftSize, AveragingMode averagingMode);
};

#endif // SDRBASE_DSP_SPECTRUMSETTNGS_H
