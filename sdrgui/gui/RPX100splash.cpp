///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia.                                  //
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

#include "RPX100splash.h"

RPX100Splash::RPX100Splash(const QPixmap& pixmap)
{
   QSplashScreen::setPixmap(pixmap);
};

RPX100Splash::~RPX100Splash()
{
};

void RPX100Splash::drawContents(QPainter *painter)
{
    QPixmap textPix = QSplashScreen::pixmap();
    painter->setPen(this->color);
    painter->drawText(this->rect, this->alignement, this->message);
};

void RPX100Splash::showStatusMessage(const QString &message, const QColor &color)
{
    this->message = message;
    this->color = color;
    this->showMessage(this->message, this->alignement, this->color);
};

void RPX100Splash::setMessageRect(QRect rect, int alignement)
{
    this->rect = rect;
    this->alignement = alignement;
};