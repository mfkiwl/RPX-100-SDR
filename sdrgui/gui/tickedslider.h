///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Bernhard Isemann, oe3bia.                                  //
//                                                                               //
// Swagger server adapter interface                                              //
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

#ifndef SDRGUI_GUI_TICKEDSLIDER_H_
#define SDRGUI_GUI_TICKEDSLIDER_H_

#include <QSlider>
#include <QColor>

#include "export.h"

class SDRGUI_API TickedSlider : public QSlider
{
public:
    TickedSlider(QWidget* parent = 0);
    void setTickColor(const QColor& color) { m_tickColor = color; }

protected:
    virtual void paintEvent(QPaintEvent *ev);

private:
    QColor m_tickColor;
};


#endif /* SDRGUI_GUI_TICKEDSLIDER_H_ */
