///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Bernhard Isemann, oe3bia                                   //
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

#include "chirpchatdemoddecoderascii.h"

void ChirpChatDemodDecoderASCII::decodeSymbols(const std::vector<unsigned short>& symbols, QString& str)
{
    std::vector<unsigned short>::const_iterator it = symbols.begin();
    QByteArray bytes;

    for (; it != symbols.end(); ++it) {
        bytes.push_back(*it & 0x7F);
    }

    str = QString(bytes.toStdString().c_str());
}
