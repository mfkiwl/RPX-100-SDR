///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Bernhard Isemann, oe3bia.                                  //
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

#ifndef INCLUDE_DEMODANALYZER_WEBAPIADAPTER_H
#define INCLUDE_DEMODANALYZER_WEBAPIADAPTER_H

#include "feature/featurewebapiadapter.h"
#include "demodanalyzersettings.h"

/**
 * Standalone API adapter only for the settings
 */
class DemodAnalyzerWebAPIAdapter : public FeatureWebAPIAdapter {
public:
    DemodAnalyzerWebAPIAdapter();
    virtual ~DemodAnalyzerWebAPIAdapter();

    virtual QByteArray serialize() const { return m_settings.serialize(); }
    virtual bool deserialize(const QByteArray& data) { return m_settings.deserialize(data); }

    virtual int webapiSettingsGet(
            SWGRPX100::SWGFeatureSettings& response,
            QString& errorMessage);

    virtual int webapiSettingsPutPatch(
            bool force,
            const QStringList& featureSettingsKeys,
            SWGRPX100::SWGFeatureSettings& response,
            QString& errorMessage);

private:
    DemodAnalyzerSettings m_settings;
};

#endif // INCLUDE_DEMODANALYZER_WEBAPIADAPTER_H
