///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Bernhard Isemann, oe3bia                                   //
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
//                                                                               //
// Implementation of static web API adapters used for preset serialization and   //
// deserialization                                                               //
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

#include "device/devicewebapiadapter.h"
#include "sdrplayv3settings.h"

class SDRPlayV3WebAPIAdapter : public DeviceWebAPIAdapter
{
public:
    SDRPlayV3WebAPIAdapter();
    virtual ~SDRPlayV3WebAPIAdapter();
    virtual QByteArray serialize() { return m_settings.serialize(); }
    virtual bool deserialize(const QByteArray& data) { return m_settings.deserialize(data); }

    virtual int webapiSettingsGet(
            SWGRPX100::SWGDeviceSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& deviceSettingsKeys,
            SWGRPX100::SWGDeviceSettings& response, // query + response
            QString& errorMessage);

private:
    SDRPlayV3Settings m_settings;
};
