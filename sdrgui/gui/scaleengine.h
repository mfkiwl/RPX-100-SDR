///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
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

#ifndef INCLUDE_SCALEENGINE_H
#define INCLUDE_SCALEENGINE_H

#include <QFont>
#include <QString>
#include <QList>
#include "dsp/physicalunit.h"
#include "export.h"

class SDRGUI_API ScaleEngine {
public:
	struct Tick {
		float pos;
		bool major;
		float textPos;
		float textSize;
		QString text;
	};
	typedef QList<Tick> TickList;

	ScaleEngine();

	void setOrientation(Qt::Orientation orientation);
	void setFont(const QFont& font);
	void setSize(float size);
	float getSize() { return m_size; }
	void setRange(Unit::Physical physicalUnit, float rangeMin, float rangeMax);
    float getRange() const { return m_rangeMax - m_rangeMin; }
    float getRangeMin() const { return m_rangeMin; }
    float getRangeMax() const { return m_rangeMax; }
	void setMakeOpposite(bool makeOpposite) { m_makeOpposite = makeOpposite; }
	void setFixedDecimalPlaces(int decimalPlaces) { m_fixedDecimalPlaces =decimalPlaces; }

	float getPosFromValue(double value);
	float getValueFromPos(double pos);
	const TickList& getTickList();

	QString getRangeMinStr();
	QString getRangeMaxStr();

	float getScaleWidth();

private:
	// base configuration
	Qt::Orientation m_orientation;
	QFont m_font;
	float m_charSize;

	// graph configuration
	float m_size;
	Unit::Physical m_physicalUnit;
	float m_rangeMin;
	float m_rangeMax;

	// calculated values
	bool m_recalc;
	double m_scale;
	QString m_unitStr;
	TickList m_tickList;
	double m_majorTickValueDistance;
	double m_firstMajorTickValue;
	int m_numMinorTicks;
	int m_decimalPlaces;
	int m_fixedDecimalPlaces;
	bool m_makeOpposite; // will show -value instead of value

	QString formatTick(double value, int decimalPlaces);
	void calcCharSize();
	void calcScaleFactor();
	double calcMajorTickUnits(double distance, int* retDecimalPlaces);
	int calcTickTextSize(double distance);
	void forceTwoTicks();
	void reCalc();

	double majorTickValue(int tick);
	double minorTickValue(int tick);
};

#endif // INCLUDE_SCALEENGINE_H
