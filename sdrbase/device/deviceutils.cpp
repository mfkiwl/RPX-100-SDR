///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
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

#include "deviceutils.h"

bool DeviceUtils::compareDeviceURIs(const QString& registerdDeviceURI, const QString& xDeviceURI)
{
    return registerdDeviceURI == getRegisteredDeviceURI(xDeviceURI);
}

QString DeviceUtils::getRegisteredDeviceURI(const QString& xDeviceURI)
{
    if (xDeviceURI == "RPX100.samplesource.bladerf") {
        return "RPX100.samplesource.bladerf1input";
    } else if ((xDeviceURI == "RPX100.samplesource.bladerf1output")
            || (xDeviceURI == "RPX100.samplesource.bladerfoutput")) {
        return "RPX100.samplesink.bladerf1output";
    } else if (xDeviceURI == "RPX100.samplesource.bladerf2output") {
        return "RPX100.samplesink.bladerf2output";
    } else if (xDeviceURI == "RPX100.samplesource.filesource") {
        return "RPX100.samplesource.fileinput";
    } else if (xDeviceURI == "RPX100.samplesource.hackrfoutput") {
        return "RPX100.samplesink.hackrf";
    } else if (xDeviceURI == "RPX100.samplesource.localoutput") {
        return "RPX100.samplesink.localoutput";
    } else  {
        return xDeviceURI;
    }
}