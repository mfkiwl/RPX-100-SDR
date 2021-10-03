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

#include "channelutils.h"

bool ChannelUtils::compareChannelURIs(const QString& registerdChannelURI, const QString& xChannelURI)
{
    return registerdChannelURI == getRegisteredChannelURI(xChannelURI);
}

QString ChannelUtils::getRegisteredChannelURI(const QString& xChannelURI)
{
    if ((xChannelURI == "RPX100.channel.chanalyzerng")
     || (xChannelURI == "org.oe3bia.RPX100ove.channel.chanalyzer")) {
        return "RPX100.channel.chanalyzer";
    } else if (xChannelURI == "de.maintech.RPX100ove.channel.am") {
        return "RPX100.channel.amdemod";
    } else if (xChannelURI == "de.maintech.RPX100ove.channel.nfm") {
        return "RPX100.channel.nfmdemod";
    } else if (xChannelURI == "de.maintech.RPX100ove.channel.ssb") {
        return "RPX100.channel.ssbdemod";
    } else if (xChannelURI == "de.maintech.RPX100ove.channel.wfm") {
        return "RPX100.channel.wfmdemod";
    } else if (xChannelURI == "RPX100.channel.udpsrc") {
        return "RPX100.channel.udpsink";
    } else if (xChannelURI == "RPX100.channeltx.udpsink") {
        return "RPX100.channeltx.udpsource";
    } else  {
        return xChannelURI;
    }
}