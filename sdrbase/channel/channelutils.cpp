///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
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
    if ((xChannelURI == "rpx-100.channel.chanalyzerng")
     || (xChannelURI == "org.f4exb.rpx-100ove.channel.chanalyzer")) {
        return "rpx-100.channel.chanalyzer";
    } else if (xChannelURI == "de.maintech.rpx-100ove.channel.am") {
        return "rpx-100.channel.amdemod";
    } else if (xChannelURI == "de.maintech.rpx-100ove.channel.nfm") {
        return "rpx-100.channel.nfmdemod";
    } else if (xChannelURI == "de.maintech.rpx-100ove.channel.ssb") {
        return "rpx-100.channel.ssbdemod";
    } else if (xChannelURI == "de.maintech.rpx-100ove.channel.wfm") {
        return "rpx-100.channel.wfmdemod";
    } else if (xChannelURI == "rpx-100.channel.udpsrc") {
        return "rpx-100.channel.udpsink";
    } else if (xChannelURI == "rpx-100.channeltx.udpsink") {
        return "rpx-100.channeltx.udpsource";
    } else  {
        return xChannelURI;
    }
}