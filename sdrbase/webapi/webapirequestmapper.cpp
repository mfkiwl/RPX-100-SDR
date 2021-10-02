///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB.                                  //
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

#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonArray>

#include <boost/lexical_cast.hpp>

#include "httpdocrootsettings.h"
#include "webapirequestmapper.h"
#include "webapiutils.h"
#include "SWGInstanceSummaryResponse.h"
#include "SWGInstanceConfigResponse.h"
#include "SWGInstanceDevicesResponse.h"
#include "SWGInstanceChannelsResponse.h"
#include "SWGInstanceFeaturesResponse.h"
#include "SWGAudioDevices.h"
#include "SWGLocationInformation.h"
#include "SWGDVSerialDevices.h"
#include "SWGAMBEDevices.h"
#include "SWGLimeRFEDevices.h"
#include "SWGLimeRFESettings.h"
#include "SWGLimeRFEPower.h"
#include "SWGPresets.h"
#include "SWGPresetTransfer.h"
#include "SWGPresetIdentifier.h"
#include "SWGPresetImport.h"
#include "SWGPresetExport.h"
#include "SWGDeviceSettings.h"
#include "SWGDeviceState.h"
#include "SWGDeviceReport.h"
#include "SWGDeviceActions.h"
#include "SWGChannelsDetail.h"
#include "SWGChannelSettings.h"
#include "SWGChannelReport.h"
#include "SWGChannelActions.h"
#include "SWGSuccessResponse.h"
#include "SWGErrorResponse.h"
#include "SWGFeaturePresets.h"
#include "SWGFeaturePresetIdentifier.h"
#include "SWGFeaturePresetTransfer.h"
#include "SWGFeatureSetList.h"
#include "SWGFeatureSettings.h"
#include "SWGFeatureReport.h"
#include "SWGFeatureActions.h"
#include "SWGGLSpectrum.h"
#include "SWGSpectrumServer.h"

WebAPIRequestMapper::WebAPIRequestMapper(QObject* parent) :
    HttpRequestHandler(parent),
    m_adapter(0)
{
#ifndef _MSC_VER
    Q_INIT_RESOURCE(webapi);
#endif
    qtwebapp::HttpDocrootSettings docrootSettings;
    docrootSettings.path = ":/webapi";
    m_staticFileController = new qtwebapp::StaticFileController(docrootSettings, parent);
}

WebAPIRequestMapper::~WebAPIRequestMapper()
{
    delete m_staticFileController;
#ifndef _MSC_VER
    Q_CLEANUP_RESOURCE(webapi);
#endif
}

void WebAPIRequestMapper::service(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    if (m_adapter == 0) // format service unavailable if adapter is null
    {
        SWGrpx-100::SWGErrorResponse errorResponse;
        response.setHeader("Content-Type", "application/json");
        response.setHeader("Access-Control-Allow-Origin", "*");
        response.setStatus(500,"Service not available");

        errorResponse.init();
        *errorResponse.getMessage() = "Service not available";
        response.write(errorResponse.asJson().toUtf8());
    }
    else // normal processing
    {
        QByteArray path=request.getPath();

        // Handle pre-flight requests
        if (request.getMethod() == "OPTIONS")
        {
            qDebug("WebAPIRequestMapper::service: method OPTIONS: assume pre-flight");
            response.setHeader("Access-Control-Allow-Origin", "*");
            response.setHeader("Access-Control-Allow-Headers", "*");
            response.setHeader("Access-Control-Allow-Methods", "*");
            response.setStatus(200, "OK");
            return;
        }

        if (path == WebAPIAdapterInterface::instanceSummaryURL) {
            instanceSummaryService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceConfigURL) {
            instanceConfigService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceDevicesURL) {
            instanceDevicesService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceChannelsURL) {
            instanceChannelsService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceFeaturesURL) {
            instanceFeaturesService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceLoggingURL) {
            instanceLoggingService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAudioURL) {
            instanceAudioService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAudioInputParametersURL) {
            instanceAudioInputParametersService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAudioOutputParametersURL) {
            instanceAudioOutputParametersService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAudioInputCleanupURL) {
            instanceAudioInputCleanupService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAudioOutputCleanupURL) {
            instanceAudioOutputCleanupService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceLocationURL) {
            instanceLocationService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAMBESerialURL) {
            instanceAMBESerialService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceAMBEDevicesURL) {
            instanceAMBEDevicesService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceLimeRFESerialURL) {
            instanceLimeRFESerialService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceLimeRFEConfigURL) {
            instanceLimeRFEConfigService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceLimeRFERunURL) {
            instanceLimeRFERunService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceLimeRFEPowerURL) {
            instanceLimeRFEPowerService(request, response);
        } else if (path == WebAPIAdapterInterface::instancePresetsURL) {
            instancePresetsService(request, response);
        } else if (path == WebAPIAdapterInterface::instancePresetURL) {
            instancePresetService(request, response);
        } else if (path == WebAPIAdapterInterface::instancePresetFileURL) {
            instancePresetFileService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceFeaturePresetsURL) {
            instanceFeaturePresetsService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceFeaturePresetURL) {
            instanceFeaturePresetService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceDeviceSetsURL) {
            instanceDeviceSetsService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceDeviceSetURL) {
            instanceDeviceSetService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceFeatureSetsURL) {
            instanceFeatureSetsService(request, response);
        } else if (path == WebAPIAdapterInterface::instanceFeatureSetURL) {
            instanceFeatureSetService(request, response);
        }
        else
        {
            std::smatch desc_match;
            std::string pathStr(path.constData(), path.length());

            if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetURLRe)) {
                devicesetService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetDeviceURLRe)) {
                devicesetDeviceService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetFocusURLRe)) {
                devicesetFocusService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetSpectrumSettingsURLRe)) {
                devicesetSpectrumSettingsService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetSpectrumServerURLRe)) {
                devicesetSpectrumServerService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetDeviceSettingsURLRe)) {
                devicesetDeviceSettingsService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetDeviceRunURLRe)) {
                devicesetDeviceRunService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetDeviceSubsystemRunURLRe)) {
                devicesetDeviceSubsystemRunService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetDeviceReportURLRe)) {
                devicesetDeviceReportService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetDeviceActionsURLRe)) {
                devicesetDeviceActionsService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetChannelsReportURLRe)) {
                devicesetChannelsReportService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetChannelURLRe)) {
                devicesetChannelService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetChannelIndexURLRe)) {
                devicesetChannelIndexService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetChannelSettingsURLRe)) {
                devicesetChannelSettingsService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetChannelReportURLRe)) {
                devicesetChannelReportService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::devicesetChannelActionsURLRe)) {
                devicesetChannelActionsService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetURLRe)) {
                featuresetService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetFeatureURLRe)) {
                featuresetFeatureService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetPresetURLRe)) {
                featuresetPresetService(std::string(desc_match[1]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetFeatureIndexURLRe)) {
                featuresetFeatureIndexService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetFeatureRunURLRe)) {
                featuresetFeatureRunService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetFeatureSettingsURLRe)) {
                featuresetFeatureSettingsService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetFeatureReportURLRe)) {
                featuresetFeatureReportService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            } else if (std::regex_match(pathStr, desc_match, WebAPIAdapterInterface::featuresetFeatureActionsURLRe)) {
                featuresetFeatureActionsService(std::string(desc_match[1]), std::string(desc_match[2]), request, response);
            }
            else // serve static documentation pages
            {
                m_staticFileController->service(request, response);
            }

//            QDirIterator it(":", QDirIterator::Subdirectories);
//            while (it.hasNext()) {
//                qDebug() << "WebAPIRequestMapper::service: " << it.next();
//            }

        }
    }
}

void WebAPIRequestMapper::instanceSummaryService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGInstanceSummaryResponse normalResponse;

        int status = m_adapter->instanceSummary(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "DELETE")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;

        int status = m_adapter->instanceDelete(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceConfigService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGInstanceConfigResponse query;
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGInstanceConfigResponse normalResponse;
        int status = m_adapter->instanceConfigGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if ((request.getMethod() == "PUT") || (request.getMethod() == "PATCH"))
    {
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            WebAPIAdapterInterface::ConfigKeys configKeys;
            SWGrpx-100::SWGInstanceConfigResponse query;
            SWGrpx-100::SWGSuccessResponse normalResponse;
            query.init();

            if (validateConfig(query, jsonObject, configKeys))
            {
                int status = m_adapter->instanceConfigPutPatch(
                    request.getMethod() == "PUT",
                    query,
                    configKeys,
                    normalResponse,
                    errorResponse
                );
                response.setStatus(status);
                qDebug("WebAPIRequestMapper::instanceConfigService: %s: %d",
                    request.getMethod() == "PUT" ? "PUT" : "PATCH", status);

                if (status/100 == 2)
                {
                    normalResponse.setMessage(new QString("Configuration updated successfully"));
                    response.write(normalResponse.asJson().toUtf8());
                }
                else
                {
                    normalResponse.setMessage(new QString("Error occurred while updating configuration"));
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }

        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceDevicesService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGInstanceDevicesResponse normalResponse;
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        QByteArray dirStr = request.getParameter("direction");
        int direction = 0;

        if (dirStr.length() != 0)
        {
            bool ok;
            int tmp = dirStr.toInt(&ok);
            if (ok) {
                direction = tmp;
            }
        }

        int status = m_adapter->instanceDevices(direction, normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceChannelsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGInstanceChannelsResponse normalResponse;
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        QByteArray dirStr = request.getParameter("direction");
        int direction = 0;

        if (dirStr.length() != 0)
        {
            bool ok;
            int tmp = dirStr.toInt(&ok);
            if (ok) {
                direction = tmp;
            }
        }

        int status = m_adapter->instanceChannels(direction, normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceFeaturesService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGInstanceFeaturesResponse normalResponse;
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        int status = m_adapter->instanceFeatures(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceLoggingService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGLoggingInfo query;
    SWGrpx-100::SWGLoggingInfo normalResponse;
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        int status = m_adapter->instanceLoggingGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "PUT")
    {
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            query.fromJson(jsonStr);
            int status = m_adapter->instanceLoggingPut(query, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAudioService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGAudioDevices normalResponse;

        int status = m_adapter->instanceAudioGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAudioInputParametersService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    QString jsonStr = request.getBody();
    QJsonObject jsonObject;

    if (parseJsonBody(jsonStr, jsonObject, response))
    {
        SWGrpx-100::SWGAudioInputDevice normalResponse;
        resetAudioInputDevice(normalResponse);
        QStringList audioInputDeviceKeys;

        if (validateAudioInputDevice(normalResponse, jsonObject, audioInputDeviceKeys))
        {
            if (request.getMethod() == "PATCH")
            {
                int status = m_adapter->instanceAudioInputPatch(
                        normalResponse,
                        audioInputDeviceKeys,
                        errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else if (request.getMethod() == "DELETE")
            {
                int status = m_adapter->instanceAudioInputDelete(
                        normalResponse,
                        errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(405,"Invalid HTTP method");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid HTTP method";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON request");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON request";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(400,"Invalid JSON format");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid JSON format";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAudioOutputParametersService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    QString jsonStr = request.getBody();
    QJsonObject jsonObject;

    if (parseJsonBody(jsonStr, jsonObject, response))
    {
        SWGrpx-100::SWGAudioOutputDevice normalResponse;
        resetAudioOutputDevice(normalResponse);
        QStringList audioOutputDeviceKeys;

        if (validateAudioOutputDevice(normalResponse, jsonObject, audioOutputDeviceKeys))
        {
            if (request.getMethod() == "PATCH")
            {
                int status = m_adapter->instanceAudioOutputPatch(
                        normalResponse,
                        audioOutputDeviceKeys,
                        errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else if (request.getMethod() == "DELETE")
            {
                int status = m_adapter->instanceAudioOutputDelete(
                        normalResponse,
                        errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(405,"Invalid HTTP method");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid HTTP method";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON request");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON request";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(400,"Invalid JSON format");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid JSON format";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAudioInputCleanupService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "PATCH")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;

        int status = m_adapter->instanceAudioInputCleanupPatch(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAudioOutputCleanupService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "PATCH")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;

        int status = m_adapter->instanceAudioOutputCleanupPatch(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceLocationService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGLocationInformation normalResponse;

        int status = m_adapter->instanceLocationGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "PUT")
    {
        SWGrpx-100::SWGLocationInformation normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            normalResponse.fromJson(jsonStr);
            int status = m_adapter->instanceLocationPut(normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAMBESerialService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGDVSerialDevices normalResponse;

        int status = m_adapter->instanceAMBESerialGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceAMBEDevicesService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGAMBEDevices normalResponse;

        int status = m_adapter->instanceAMBEDevicesGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if ((request.getMethod() == "PATCH") || (request.getMethod() == "PUT"))
    {
        SWGrpx-100::SWGAMBEDevices query;
        SWGrpx-100::SWGAMBEDevices normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            if (validateAMBEDevices(query, jsonObject))
            {
                int status;

                if (request.getMethod() == "PATCH") {
                    status = m_adapter->instanceAMBEDevicesPatch(query, normalResponse, errorResponse);
                } else {
                    status = m_adapter->instanceAMBEDevicesPut(query, normalResponse, errorResponse);
                }

                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "DELETE")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;

        int status = m_adapter->instanceAMBEDevicesDelete(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceLimeRFESerialService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGLimeRFEDevices normalResponse;

        int status = m_adapter->instanceLimeRFESerialGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceLimeRFEConfigService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        QByteArray serialStr = request.getParameter("serial");
        SWGrpx-100::SWGLimeRFESettings normalResponse;

        int status = m_adapter->instanceLimeRFEConfigGet(serialStr, normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "PUT")
    {
        SWGrpx-100::SWGLimeRFESettings query;
        SWGrpx-100::SWGSuccessResponse normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            QStringList limeRFESettingsKeys;

            if (validateLimeRFEConfig(query, jsonObject, limeRFESettingsKeys))
            {
                if (limeRFESettingsKeys.contains("devicePath"))
                {
                    int status = m_adapter->instanceLimeRFEConfigPut(query, normalResponse, errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"LimeRFE device path expected in JSON body");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceLimeRFERunService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "PUT")
    {
        SWGrpx-100::SWGLimeRFESettings query;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            QStringList limeRFESettingsKeys;

            if (validateLimeRFEConfig(query, jsonObject, limeRFESettingsKeys))
            {
                if (limeRFESettingsKeys.contains("devicePath"))
                {
                    SWGrpx-100::SWGSuccessResponse normalResponse;
                    int status = m_adapter->instanceLimeRFERunPut(query, normalResponse, errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"LimeRFE device path expected in JSON body");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON format";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceLimeRFEPowerService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        QByteArray serialStr = request.getParameter("serial");
        SWGrpx-100::SWGLimeRFEPower normalResponse;

        int status = m_adapter->instanceLimeRFEPowerGet(serialStr, normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instancePresetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGPresets normalResponse;
        int status = m_adapter->instancePresetsGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
}

void WebAPIRequestMapper::instancePresetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "PATCH")
    {
        SWGrpx-100::SWGPresetTransfer query;
        SWGrpx-100::SWGPresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            query.fromJson(jsonStr);

            if (validatePresetTransfer(query))
            {
                int status = m_adapter->instancePresetPatch(query, normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "PUT")
    {
        SWGrpx-100::SWGPresetTransfer query;
        SWGrpx-100::SWGPresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            query.fromJson(jsonStr);

            if (validatePresetTransfer(query))
            {
                int status = m_adapter->instancePresetPut(query, normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "POST")
    {
        SWGrpx-100::SWGPresetTransfer query;
        SWGrpx-100::SWGPresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            query.fromJson(jsonStr);

            if (validatePresetTransfer(query))
            {
                int status = m_adapter->instancePresetPost(query, normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "DELETE")
    {
        SWGrpx-100::SWGPresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            normalResponse.fromJson(jsonStr);

            if (validatePresetIdentifer(normalResponse))
            {
                int status = m_adapter->instancePresetDelete(normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instancePresetFileService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "PUT")
    {
        SWGrpx-100::SWGPresetImport query;
        SWGrpx-100::SWGPresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            query.fromJson(jsonStr);

            if (query.getFilePath())
            {
                int status = m_adapter->instancePresetFilePut(query, normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "POST")
    {
        SWGrpx-100::SWGPresetExport query;
        SWGrpx-100::SWGPresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            query.fromJson(jsonStr);

            if (validatePresetExport(query))
            {
                int status = m_adapter->instancePresetFilePost(query, normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceFeaturePresetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGFeaturePresets normalResponse;
        int status = m_adapter->instanceFeaturePresetsGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
}

void WebAPIRequestMapper::instanceFeaturePresetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "DELETE")
    {
        SWGrpx-100::SWGFeaturePresetIdentifier normalResponse;
        QString jsonStr = request.getBody();
        QJsonObject jsonObject;

        if (parseJsonBody(jsonStr, jsonObject, response))
        {
            normalResponse.fromJson(jsonStr);

            if (validateFeaturePresetIdentifer(normalResponse))
            {
                int status = m_adapter->instanceFeaturePresetDelete(normalResponse, errorResponse);
                response.setStatus(status);

                if (status/100 == 2) {
                    response.write(normalResponse.asJson().toUtf8());
                } else {
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON request");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON request";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(400,"Invalid JSON format");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid JSON format";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceDeviceSetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGDeviceSetList normalResponse;
        int status = m_adapter->instanceDeviceSetsGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceFeatureSetsService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        SWGrpx-100::SWGFeatureSetList normalResponse;
        int status = m_adapter->instanceFeatureSetsGet(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceDeviceSetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "POST")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;
        QByteArray dirStr = request.getParameter("direction");
        int direction = 0;

        if (dirStr.length() != 0)
        {
            bool ok;
            int tmp = dirStr.toInt(&ok);
            if (ok) {
                direction = tmp;
            }
        }

        int status = m_adapter->instanceDeviceSetPost(direction, normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "DELETE")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;
        int status = m_adapter->instanceDeviceSetDelete(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::instanceFeatureSetService(qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "POST")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;

        int status = m_adapter->instanceFeatureSetPost(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else if (request.getMethod() == "DELETE")
    {
        SWGrpx-100::SWGSuccessResponse normalResponse;
        int status = m_adapter->instanceFeatureSetDelete(normalResponse, errorResponse);
        response.setStatus(status);

        if (status/100 == 2) {
            response.write(normalResponse.asJson().toUtf8());
        } else {
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        try
        {
            SWGrpx-100::SWGDeviceSet normalResponse;
            int deviceSetIndex = boost::lexical_cast<int>(indexStr);
            int status = m_adapter->devicesetGet(deviceSetIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        catch (const boost::bad_lexical_cast &e)
        {
            errorResponse.init();
            *errorResponse.getMessage() = "Wrong integer conversion on device set index";
            response.setStatus(400,"Invalid data");
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetFocusService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if (request.getMethod() == "PATCH")
        {
            SWGrpx-100::SWGSuccessResponse normalResponse;
            int status = m_adapter->devicesetFocusPatch(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetSpectrumSettingsService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if ((request.getMethod() == "PUT") || (request.getMethod() == "PATCH"))
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGGLSpectrum normalResponse;
                resetSpectrumSettings(normalResponse);
                QStringList spectrumSettingsKeys;

                if (validateSpectrumSettings(normalResponse, jsonObject, spectrumSettingsKeys))
                {
                    int status = m_adapter->devicesetSpectrumSettingsPutPatch(
                            deviceSetIndex,
                            (request.getMethod() == "PUT"), // force settings on PUT
                            spectrumSettingsKeys,
                            normalResponse,
                            errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGGLSpectrum normalResponse;
            resetSpectrumSettings(normalResponse);
            int status = m_adapter->devicesetSpectrumSettingsGet(deviceSetIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetSpectrumServerService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGSpectrumServer normalResponse;
            int status = m_adapter->devicesetSpectrumServerGet(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "POST")
        {
            SWGrpx-100::SWGSuccessResponse normalResponse;
            int status = m_adapter->devicesetSpectrumServerPost(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "DELETE")
        {
            SWGrpx-100::SWGSuccessResponse normalResponse;
            int status = m_adapter->devicesetSpectrumServerDelete(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetDeviceService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if (request.getMethod() == "PUT")
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGDeviceListItem query;
                SWGrpx-100::SWGDeviceListItem normalResponse;

                if (validateDeviceListItem(query, jsonObject))
                {
                    int status = m_adapter->devicesetDevicePut(deviceSetIndex, query, normalResponse, errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Missing device identification");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Missing device identification";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetDeviceSettingsService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if ((request.getMethod() == "PUT") || (request.getMethod() == "PATCH"))
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGDeviceSettings normalResponse;
                resetDeviceSettings(normalResponse);
                QStringList deviceSettingsKeys;

                if (validateDeviceSettings(normalResponse, jsonObject, deviceSettingsKeys))
                {
                    int status = m_adapter->devicesetDeviceSettingsPutPatch(
                            deviceSetIndex,
                            (request.getMethod() == "PUT"), // force settings on PUT
                            deviceSettingsKeys,
                            normalResponse,
                            errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGDeviceSettings normalResponse;
            resetDeviceSettings(normalResponse);
            int status = m_adapter->devicesetDeviceSettingsGet(deviceSetIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetDeviceRunService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->devicesetDeviceRunGet(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "POST")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->devicesetDeviceRunPost(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "DELETE")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->devicesetDeviceRunDelete(deviceSetIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetDeviceSubsystemRunService(const std::string& indexStr, const std::string& subsystemIndexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);
        int subsystemIndex = boost::lexical_cast<int>(subsystemIndexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->devicesetDeviceSubsystemRunGet(deviceSetIndex, subsystemIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "POST")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->devicesetDeviceSubsystemRunPost(deviceSetIndex, subsystemIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "DELETE")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->devicesetDeviceSubsystemRunDelete(deviceSetIndex, subsystemIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetDeviceReportService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        try
        {
            SWGrpx-100::SWGDeviceReport normalResponse;
            resetDeviceReport(normalResponse);
            int deviceSetIndex = boost::lexical_cast<int>(indexStr);
            int status = m_adapter->devicesetDeviceReportGet(deviceSetIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        catch (const boost::bad_lexical_cast &e)
        {
            errorResponse.init();
            *errorResponse.getMessage() = "Wrong integer conversion on device set index";
            response.setStatus(400,"Invalid data");
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetDeviceActionsService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(indexStr);

        if (request.getMethod() == "POST")
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGDeviceActions query;
                SWGrpx-100::SWGSuccessResponse normalResponse;
                resetDeviceActions(query);
                QStringList deviceActionsKeys;

                if (validateDeviceActions(query, jsonObject, deviceActionsKeys))
                {
                    int status = m_adapter->devicesetDeviceActionsPost(
                        deviceSetIndex,
                        deviceActionsKeys,
                        query,
                        normalResponse,
                        errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch(const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on device set index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetChannelsReportService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        try
        {
            SWGrpx-100::SWGChannelsDetail normalResponse;
            int deviceSetIndex = boost::lexical_cast<int>(indexStr);
            int status = m_adapter->devicesetChannelsReportGet(deviceSetIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        catch (const boost::bad_lexical_cast &e)
        {
            errorResponse.init();
            *errorResponse.getMessage() = "Wrong integer conversion on device set index";
            response.setStatus(400,"Invalid data");
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetChannelService(
        const std::string& deviceSetIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(deviceSetIndexStr);

        if (request.getMethod() == "POST")
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGChannelSettings query;
                SWGrpx-100::SWGSuccessResponse normalResponse;
                resetChannelSettings(query);

                if (jsonObject.contains("direction")) {
                    query.setDirection(jsonObject["direction"].toInt());
                } else {
                    query.setDirection(0); // assume Rx
                }

                if (jsonObject.contains("channelType") && jsonObject["channelType"].isString())
                {
                    query.setChannelType(new QString(jsonObject["channelType"].toString()));

                    int status = m_adapter->devicesetChannelPost(deviceSetIndex, query, normalResponse, errorResponse);

                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetChannelIndexService(
        const std::string& deviceSetIndexStr,
        const std::string& channelIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(deviceSetIndexStr);
        int channelIndex = boost::lexical_cast<int>(channelIndexStr);

        if (request.getMethod() == "DELETE")
        {
            SWGrpx-100::SWGSuccessResponse normalResponse;
            int status = m_adapter->devicesetChannelDelete(deviceSetIndex, channelIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetChannelSettingsService(
        const std::string& deviceSetIndexStr,
        const std::string& channelIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(deviceSetIndexStr);
        int channelIndex = boost::lexical_cast<int>(channelIndexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGChannelSettings normalResponse;
            resetChannelSettings(normalResponse);
            int status = m_adapter->devicesetChannelSettingsGet(deviceSetIndex, channelIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if ((request.getMethod() == "PUT") || (request.getMethod() == "PATCH"))
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGChannelSettings normalResponse;
                resetChannelSettings(normalResponse);
                QStringList channelSettingsKeys;

                if (validateChannelSettings(normalResponse, jsonObject, channelSettingsKeys))
                {
                    int status = m_adapter->devicesetChannelSettingsPutPatch(
                            deviceSetIndex,
                            channelIndex,
                            (request.getMethod() == "PUT"), // force settings on PUT
                            channelSettingsKeys,
                            normalResponse,
                            errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetChannelReportService(
        const std::string& deviceSetIndexStr,
        const std::string& channelIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(deviceSetIndexStr);
        int channelIndex = boost::lexical_cast<int>(channelIndexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGChannelReport normalResponse;
            resetChannelReport(normalResponse);
            int status = m_adapter->devicesetChannelReportGet(deviceSetIndex, channelIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::devicesetChannelActionsService(
        const std::string& deviceSetIndexStr,
        const std::string& channelIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int deviceSetIndex = boost::lexical_cast<int>(deviceSetIndexStr);
        int channelIndex = boost::lexical_cast<int>(channelIndexStr);

        if (request.getMethod() == "POST")
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGChannelActions query;
                SWGrpx-100::SWGSuccessResponse normalResponse;
                resetChannelActions(query);
                QStringList channelActionsKeys;

                if (validateChannelActions(query, jsonObject, channelActionsKeys))
                {
                    int status = m_adapter->devicesetChannelActionsPost(
                        deviceSetIndex,
                        channelIndex,
                        channelActionsKeys,
                        query,
                        normalResponse,
                        errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch(const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetService(const std::string& indexStr, qtwebapp::HttpRequest& request, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    if (request.getMethod() == "GET")
    {
        try
        {
            SWGrpx-100::SWGFeatureSet normalResponse;
            int deviceSetIndex = boost::lexical_cast<int>(indexStr);
            int status = m_adapter->featuresetGet(deviceSetIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        catch (const boost::bad_lexical_cast &e)
        {
            errorResponse.init();
            *errorResponse.getMessage() = "Wrong integer conversion on device set index";
            response.setStatus(400,"Invalid data");
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    else
    {
        response.setStatus(405,"Invalid HTTP method");
        errorResponse.init();
        *errorResponse.getMessage() = "Invalid HTTP method";
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetFeatureService(
        const std::string& featureSetIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);

        if (request.getMethod() == "POST")
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGFeatureSettings query;
                SWGrpx-100::SWGSuccessResponse normalResponse;
                resetFeatureSettings(query);

                if (jsonObject.contains("featureType") && jsonObject["featureType"].isString())
                {
                    query.setFeatureType(new QString(jsonObject["featureType"].toString()));

                    int status = m_adapter->featuresetFeaturePost(featureSetIndex, query, normalResponse, errorResponse);

                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetPresetService(
    const std::string& featureSetIndexStr,
    qtwebapp::HttpRequest& request,
    qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);

        if (request.getMethod() == "PATCH")
        {
            SWGrpx-100::SWGFeaturePresetIdentifier query;
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                query.fromJson(jsonStr);

                if (validateFeaturePresetIdentifer(query))
                {
                    int status = m_adapter->featuresetPresetPatch(featureSetIndex, query, errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(query.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "PUT")
        {
            SWGrpx-100::SWGFeaturePresetIdentifier query;
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                query.fromJson(jsonStr);

                if (validateFeaturePresetIdentifer(query))
                {
                    int status = m_adapter->featuresetPresetPut(featureSetIndex, query, errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(query.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "POST")
        {
            SWGrpx-100::SWGFeaturePresetIdentifier query;
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                query.fromJson(jsonStr);

                if (validateFeaturePresetIdentifer(query))
                {
                    int status = m_adapter->featuresetPresetPost(featureSetIndex, query, errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(query.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetFeatureIndexService(
        const std::string& featureSetIndexStr,
        const std::string& featureIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);
        int featureIndex = boost::lexical_cast<int>(featureIndexStr);

        if (request.getMethod() == "DELETE")
        {
            SWGrpx-100::SWGSuccessResponse normalResponse;
            int status = m_adapter->featuresetFeatureDelete(featureSetIndex, featureIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetFeatureRunService(
        const std::string& featureSetIndexStr,
        const std::string& featureIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);
        int featureIndex = boost::lexical_cast<int>(featureIndexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->featuresetFeatureRunGet(featureSetIndex, featureIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if (request.getMethod() == "POST")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->featuresetFeatureRunPost(featureSetIndex, featureIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }

        }
        else if (request.getMethod() == "DELETE")
        {
            SWGrpx-100::SWGDeviceState normalResponse;
            int status = m_adapter->featuresetFeatureRunDelete(featureSetIndex, featureIndex, normalResponse, errorResponse);

            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetFeatureSettingsService(
        const std::string& featureSetIndexStr,
        const std::string& featureIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);
        int featureIndex = boost::lexical_cast<int>(featureIndexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGFeatureSettings normalResponse;
            resetFeatureSettings(normalResponse);
            int status = m_adapter->featuresetFeatureSettingsGet(featureSetIndex, featureIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else if ((request.getMethod() == "PUT") || (request.getMethod() == "PATCH"))
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGFeatureSettings normalResponse;
                resetFeatureSettings(normalResponse);
                QStringList featureSettingsKeys;

                if (validateFeatureSettings(normalResponse, jsonObject, featureSettingsKeys))
                {
                    int status = m_adapter->featuresetFeatureSettingsPutPatch(
                            featureSetIndex,
                            featureIndex,
                            (request.getMethod() == "PUT"), // force settings on PUT
                            featureSettingsKeys,
                            normalResponse,
                            errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetFeatureReportService(
        const std::string& featureSetIndexStr,
        const std::string& featureIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);
        int featureIndex = boost::lexical_cast<int>(featureIndexStr);

        if (request.getMethod() == "GET")
        {
            SWGrpx-100::SWGFeatureReport normalResponse;
            resetFeatureReport(normalResponse);
            int status = m_adapter->featuresetFeatureReportGet(featureSetIndex, featureIndex, normalResponse, errorResponse);
            response.setStatus(status);

            if (status/100 == 2) {
                response.write(normalResponse.asJson().toUtf8());
            } else {
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

void WebAPIRequestMapper::featuresetFeatureActionsService(
        const std::string& featureSetIndexStr,
        const std::string& featureIndexStr,
        qtwebapp::HttpRequest& request,
        qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;
    response.setHeader("Content-Type", "application/json");
    response.setHeader("Access-Control-Allow-Origin", "*");

    try
    {
        int featureSetIndex = boost::lexical_cast<int>(featureSetIndexStr);
        int featureIndex = boost::lexical_cast<int>(featureIndexStr);

        if (request.getMethod() == "POST")
        {
            QString jsonStr = request.getBody();
            QJsonObject jsonObject;

            if (parseJsonBody(jsonStr, jsonObject, response))
            {
                SWGrpx-100::SWGFeatureActions query;
                SWGrpx-100::SWGSuccessResponse normalResponse;
                resetFeatureActions(query);
                QStringList featureActionsKeys;

                if (validateFeatureActions(query, jsonObject, featureActionsKeys))
                {
                    int status = m_adapter->featuresetFeatureActionsPost(
                        featureSetIndex,
                        featureIndex,
                        featureActionsKeys,
                        query,
                        normalResponse,
                        errorResponse);
                    response.setStatus(status);

                    if (status/100 == 2) {
                        response.write(normalResponse.asJson().toUtf8());
                    } else {
                        response.write(errorResponse.asJson().toUtf8());
                    }
                }
                else
                {
                    response.setStatus(400,"Invalid JSON request");
                    errorResponse.init();
                    *errorResponse.getMessage() = "Invalid JSON request";
                    response.write(errorResponse.asJson().toUtf8());
                }
            }
            else
            {
                response.setStatus(400,"Invalid JSON format");
                errorResponse.init();
                *errorResponse.getMessage() = "Invalid JSON format";
                response.write(errorResponse.asJson().toUtf8());
            }
        }
        else
        {
            response.setStatus(405,"Invalid HTTP method");
            errorResponse.init();
            *errorResponse.getMessage() = "Invalid HTTP method";
            response.write(errorResponse.asJson().toUtf8());
        }
    }
    catch(const boost::bad_lexical_cast &e)
    {
        errorResponse.init();
        *errorResponse.getMessage() = "Wrong integer conversion on index";
        response.setStatus(400,"Invalid data");
        response.write(errorResponse.asJson().toUtf8());
    }
}

bool WebAPIRequestMapper::parseJsonBody(QString& jsonStr, QJsonObject& jsonObject, qtwebapp::HttpResponse& response)
{
    SWGrpx-100::SWGErrorResponse errorResponse;

    try
    {
        QByteArray jsonBytes(jsonStr.toStdString().c_str());
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonBytes, &error);

        if (error.error == QJsonParseError::NoError)
        {
            jsonObject = doc.object();
        }
        else
        {
            QString errorMsg = QString("Input JSON error: ") + error.errorString() + QString(" at offset ") + QString::number(error.offset);
            errorResponse.init();
            *errorResponse.getMessage() = errorMsg;
            response.setStatus(400, errorMsg.toUtf8());
            response.write(errorResponse.asJson().toUtf8());
        }

        return (error.error == QJsonParseError::NoError);
    }
    catch (const std::exception& ex)
    {
        QString errorMsg = QString("Error parsing request: ") + ex.what();
        errorResponse.init();
        *errorResponse.getMessage() = errorMsg;
        response.setStatus(500, errorMsg.toUtf8());
        response.write(errorResponse.asJson().toUtf8());

        return false;
    }
}

bool WebAPIRequestMapper::validatePresetTransfer(SWGrpx-100::SWGPresetTransfer& presetTransfer)
{
    SWGrpx-100::SWGPresetIdentifier *presetIdentifier = presetTransfer.getPreset();

    if (presetIdentifier == 0) {
        return false;
    }

    return validatePresetIdentifer(*presetIdentifier);
}

bool WebAPIRequestMapper::validatePresetIdentifer(SWGrpx-100::SWGPresetIdentifier& presetIdentifier)
{
    return (presetIdentifier.getGroupName() && presetIdentifier.getName() && presetIdentifier.getType());
}

bool WebAPIRequestMapper::validateFeaturePresetTransfer(SWGrpx-100::SWGFeaturePresetTransfer& presetTransfer)
{
    SWGrpx-100::SWGFeaturePresetIdentifier *presetIdentifier = presetTransfer.getPreset();

    if (presetIdentifier == 0) {
        return false;
    }

    return validateFeaturePresetIdentifer(*presetIdentifier);
}

bool WebAPIRequestMapper::validateFeaturePresetIdentifer(SWGrpx-100::SWGFeaturePresetIdentifier& presetIdentifier)
{
    return (presetIdentifier.getGroupName() && presetIdentifier.getDescription());
}

bool WebAPIRequestMapper::validatePresetExport(SWGrpx-100::SWGPresetExport& presetExport)
{
    if (presetExport.getFilePath() == 0) {
        return false;
    }

    SWGrpx-100::SWGPresetIdentifier *presetIdentifier =  presetExport.getPreset();

    if (presetIdentifier == 0) {
        return false;
    }

    return validatePresetIdentifer(*presetIdentifier);
}

bool WebAPIRequestMapper::validateDeviceListItem(SWGrpx-100::SWGDeviceListItem& deviceListItem, QJsonObject& jsonObject)
{
    if (jsonObject.contains("direction")) {
        deviceListItem.setDirection(jsonObject["direction"].toInt());
    } else {
        deviceListItem.setDirection(0); // assume Rx
    }

    bool identified = false;

    if (jsonObject.contains("displayedName") && jsonObject["displayedName"].isString())
    {
        deviceListItem.setDisplayedName(new QString(jsonObject["displayedName"].toString()));
        identified = true;
    } else {
        deviceListItem.setDisplayedName(0);
    }


    if (jsonObject.contains("hwType") && jsonObject["hwType"].isString())
    {
        deviceListItem.setHwType(new QString(jsonObject["hwType"].toString()));
        identified = true;
    } else {
        deviceListItem.setHwType(0);
    }

    if (jsonObject.contains("serial") && jsonObject["serial"].isString())
    {
        deviceListItem.setSerial(new QString(jsonObject["serial"].toString()));
        identified = true;
    } else {
        deviceListItem.setSerial(0);
    }

    if (jsonObject.contains("index")) {
        deviceListItem.setIndex(jsonObject["index"].toInt(-1));
    } else {
        deviceListItem.setIndex(-1);
    }

    if (jsonObject.contains("sequence")){
        deviceListItem.setSequence(jsonObject["sequence"].toInt(-1));
    } else {
        deviceListItem.setSequence(-1);
    }

    if (jsonObject.contains("deviceStreamIndex")) {
        deviceListItem.setDeviceStreamIndex(jsonObject["deviceStreamIndex"].toInt(-1));
    } else {
        deviceListItem.setDeviceStreamIndex(-1);
    }

    return identified;
}

bool WebAPIRequestMapper::validateDeviceSettings(
        SWGrpx-100::SWGDeviceSettings& deviceSettings,
        QJsonObject& jsonObject,
        QStringList& deviceSettingsKeys)
{
    if (jsonObject.contains("direction")) {
        deviceSettings.setDirection(jsonObject["direction"].toInt());
    } else {
        deviceSettings.setDirection(0); // assume single Rx
    }

    if (jsonObject.contains("deviceHwType") && jsonObject["deviceHwType"].isString()) {
        deviceSettings.setDeviceHwType(new QString(jsonObject["deviceHwType"].toString()));
    } else {
        return false;
    }

    QString *deviceHwType = deviceSettings.getDeviceHwType();
    QString deviceSettingsKey;

    if (deviceSettings.getDirection() == 0) // source
    {
        if (WebAPIUtils::m_sourceDeviceHwIdToSettingsKey.contains(*deviceHwType)) {
            deviceSettingsKey = WebAPIUtils::m_sourceDeviceHwIdToSettingsKey[*deviceHwType];
        } else {
            return false;
        }
    }
    else if (deviceSettings.getDirection() == 1) // sink
    {
        if (WebAPIUtils::m_sinkDeviceHwIdToSettingsKey.contains(*deviceHwType)) {
            deviceSettingsKey = WebAPIUtils::m_sinkDeviceHwIdToSettingsKey[*deviceHwType];
        } else {
            return false;
        }
    }
    else if (deviceSettings.getDirection() == 2) // MIMO
    {
        if (WebAPIUtils::m_mimoDeviceHwIdToSettingsKey.contains(*deviceHwType)) {
            deviceSettingsKey = WebAPIUtils::m_mimoDeviceHwIdToSettingsKey[*deviceHwType];
        } else {
            return false;
        }
    }
    else
    {
        return false;
    }

    return getDeviceSettings(deviceSettingsKey, &deviceSettings, jsonObject, deviceSettingsKeys);
}

bool WebAPIRequestMapper::validateDeviceActions(
        SWGrpx-100::SWGDeviceActions& deviceActions,
        QJsonObject& jsonObject,
        QStringList& deviceActionsKeys)
{
    if (jsonObject.contains("direction")) {
        deviceActions.setDirection(jsonObject["direction"].toInt());
    } else {
        deviceActions.setDirection(0); // assume single Rx
    }

    if (jsonObject.contains("deviceHwType") && jsonObject["deviceHwType"].isString()) {
        deviceActions.setDeviceHwType(new QString(jsonObject["deviceHwType"].toString()));
    } else {
        return false;
    }

    QString *deviceHwType = deviceActions.getDeviceHwType();
    QString deviceActionsKey;

    if (deviceActions.getDirection() == 0) // source
    {
        if (WebAPIUtils::m_sourceDeviceHwIdToSettingsKey.contains(*deviceHwType)) {
            deviceActionsKey = WebAPIUtils::m_sourceDeviceHwIdToActionsKey[*deviceHwType];
        } else {
            return false;
        }
    }
    else if (deviceActions.getDirection() == 1) // sink
    {
        if (WebAPIUtils::m_sinkDeviceHwIdToSettingsKey.contains(*deviceHwType)) {
            deviceActionsKey = WebAPIUtils::m_sinkDeviceHwIdToActionsKey[*deviceHwType];
        } else {
            return false;
        }
    }
    else if (deviceActions.getDirection() == 2) // MIMO
    {
        if (WebAPIUtils::m_mimoDeviceHwIdToSettingsKey.contains(*deviceHwType)) {
            deviceActionsKey = WebAPIUtils::m_mimoDeviceHwIdToActionsKey[*deviceHwType];
        } else {
            return false;
        }
    }
    else
    {
        return false;
    }

    return getDeviceActions(deviceActionsKey, &deviceActions, jsonObject, deviceActionsKeys);
}

bool WebAPIRequestMapper::validateChannelSettings(
        SWGrpx-100::SWGChannelSettings& channelSettings,
        QJsonObject& jsonObject,
        QStringList& channelSettingsKeys)
{
    if (jsonObject.contains("direction")) {
        channelSettings.setDirection(jsonObject["direction"].toInt());
    } else {
        channelSettings.setDirection(0); // assume single Rx
    }

    if (jsonObject.contains("channelType") && jsonObject["channelType"].isString()) {
        channelSettings.setChannelType(new QString(jsonObject["channelType"].toString()));
    } else {
        return false;
    }

    QString *channelType = channelSettings.getChannelType();

    if (WebAPIUtils::m_channelTypeToSettingsKey.contains(*channelType)) {
        return getChannelSettings(WebAPIUtils::m_channelTypeToSettingsKey[*channelType], &channelSettings, jsonObject, channelSettingsKeys);
    } else {
        return false;
    }
}

bool WebAPIRequestMapper::validateChannelActions(
    SWGrpx-100::SWGChannelActions& channelActions,
    QJsonObject& jsonObject,
    QStringList& channelActionsKeys)
{
    if (jsonObject.contains("direction")) {
        channelActions.setDirection(jsonObject["direction"].toInt());
    } else {
        channelActions.setDirection(0); // assume single Rx
    }

    if (jsonObject.contains("channelType") && jsonObject["channelType"].isString()) {
        channelActions.setChannelType(new QString(jsonObject["channelType"].toString()));
    } else {
        return false;
    }

    QString *channelType = channelActions.getChannelType();

    if (WebAPIUtils::m_channelTypeToActionsKey.contains(*channelType)) {
        return getChannelActions(WebAPIUtils::m_channelTypeToActionsKey[*channelType], &channelActions, jsonObject, channelActionsKeys);
    } else {
        return false;
    }
}

bool WebAPIRequestMapper::validateFeatureSettings(
        SWGrpx-100::SWGFeatureSettings& featureSettings,
        QJsonObject& jsonObject,
        QStringList& featureSettingsKeys)
{
    if (jsonObject.contains("featureType") && jsonObject["featureType"].isString()) {
        featureSettings.setFeatureType(new QString(jsonObject["featureType"].toString()));
    } else {
        return false;
    }

    QString *featureType = featureSettings.getFeatureType();

    if (WebAPIUtils::m_featureTypeToSettingsKey.contains(*featureType)) {
        return getFeatureSettings(WebAPIUtils::m_featureTypeToSettingsKey[*featureType], &featureSettings, jsonObject, featureSettingsKeys);
    } else {
        return false;
    }
}

bool WebAPIRequestMapper::validateFeatureActions(
    SWGrpx-100::SWGFeatureActions& featureActions,
    QJsonObject& jsonObject,
    QStringList& featureActionsKeys)
{
    if (jsonObject.contains("featureType") && jsonObject["featureType"].isString()) {
        featureActions.setFeatureType(new QString(jsonObject["featureType"].toString()));
    } else {
        return false;
    }

    QString *featureType = featureActions.getFeatureType();

    if (WebAPIUtils::m_featureTypeToActionsKey.contains(*featureType)) {
        return getFeatureActions(WebAPIUtils::m_featureTypeToActionsKey[*featureType], &featureActions, jsonObject, featureActionsKeys);
    } else {
        return false;
    }
}

bool WebAPIRequestMapper::validateAudioInputDevice(
        SWGrpx-100::SWGAudioInputDevice& audioInputDevice,
        QJsonObject& jsonObject,
        QStringList& audioInputDeviceKeys)
{
    if (jsonObject.contains("index")) {
        audioInputDevice.setIndex(jsonObject["index"].toInt());
    } else {
        audioInputDevice.setIndex(-1); // assume systam default
    }
    if (jsonObject.contains("sampleRate"))
    {
        audioInputDevice.setSampleRate(jsonObject["sampleRate"].toInt());
        audioInputDeviceKeys.append("sampleRate");
    }
    if (jsonObject.contains("volume"))
    {
        audioInputDevice.setVolume(jsonObject["volume"].toDouble());
        audioInputDeviceKeys.append("volume");
    }
    return true;
}

bool WebAPIRequestMapper::validateAudioOutputDevice(
        SWGrpx-100::SWGAudioOutputDevice& audioOutputDevice,
        QJsonObject& jsonObject,
        QStringList& audioOutputDeviceKeys)
{
    if (jsonObject.contains("index")) {
        audioOutputDevice.setIndex(jsonObject["index"].toInt());
    } else {
        audioOutputDevice.setIndex(-1); // assume systam default
    }
    if (jsonObject.contains("sampleRate"))
    {
        audioOutputDevice.setSampleRate(jsonObject["sampleRate"].toInt());
        audioOutputDeviceKeys.append("sampleRate");
    }
    if (jsonObject.contains("copyToUDP"))
    {
        audioOutputDevice.setCopyToUdp(jsonObject["copyToUDP"].toInt() == 0 ? 0 : 1);
        audioOutputDeviceKeys.append("copyToUDP");
    }
    if (jsonObject.contains("udpUsesRTP"))
    {
        audioOutputDevice.setUdpUsesRtp(jsonObject["udpUsesRTP"].toInt() == 0 ? 0 : 1);
        audioOutputDeviceKeys.append("udpUsesRTP");
    }
    if (jsonObject.contains("udpChannelMode"))
    {
        audioOutputDevice.setUdpChannelMode(jsonObject["udpChannelMode"].toInt());
        audioOutputDeviceKeys.append("udpChannelMode");
    }
    if (jsonObject.contains("udpChannelCodec"))
    {
        audioOutputDevice.setUdpChannelCodec(jsonObject["udpChannelCodec"].toInt());
        audioOutputDeviceKeys.append("udpChannelCodec");
    }
    if (jsonObject.contains("udpDecimationFactor"))
    {
        audioOutputDevice.setUdpDecimationFactor(jsonObject["udpDecimationFactor"].toInt());
        audioOutputDeviceKeys.append("udpDecimationFactor");
    }
    if (jsonObject.contains("udpAddress"))
    {
        audioOutputDevice.setUdpAddress(new QString(jsonObject["udpAddress"].toString()));
        audioOutputDeviceKeys.append("udpAddress");
    }
    if (jsonObject.contains("udpPort"))
    {
        audioOutputDevice.setUdpPort(jsonObject["udpPort"].toInt());
        audioOutputDeviceKeys.append("udpPort");
    }
    return true;
}

bool WebAPIRequestMapper::validateAMBEDevices(SWGrpx-100::SWGAMBEDevices& ambeDevices, QJsonObject& jsonObject)
{
    if (jsonObject.contains("nbDevices"))
    {
        int nbDevices = jsonObject["nbDevices"].toInt();

        if (jsonObject.contains("ambeDevices"))
        {
            QJsonArray ambeDevicesJson = jsonObject["ambeDevices"].toArray();

            if (nbDevices != ambeDevicesJson.size()) {
                return false;
            }

            ambeDevices.init();
            ambeDevices.setNbDevices(nbDevices);
            QList<SWGrpx-100::SWGAMBEDevice *> *ambeList = ambeDevices.getAmbeDevices();

            for (int i = 0; i < nbDevices; i++)
            {
                QJsonObject ambeDeviceJson = ambeDevicesJson.at(i).toObject();
                if (ambeDeviceJson.contains("deviceRef") && ambeDeviceJson.contains("delete"))
                {
                    ambeList->push_back(new SWGrpx-100::SWGAMBEDevice());
                    ambeList->back()->init();
                    ambeList->back()->setDeviceRef(new QString(ambeDeviceJson["deviceRef"].toString()));
                    ambeList->back()->setDelete(ambeDeviceJson["delete"].toInt());
                }
                else
                {
                    return false;
                }
            }

            return true;
        }
    }

    return false;
}

bool WebAPIRequestMapper::validateLimeRFEConfig(SWGrpx-100::SWGLimeRFESettings& limeRFESettings, QJsonObject& jsonObject, QStringList& limeRFESettingsKeys)
{
    if (jsonObject.contains("devicePath"))
    {
        limeRFESettings.setDevicePath(new QString(jsonObject["devicePath"].toString()));
        limeRFESettingsKeys.append("devicePath");
    }
    if (jsonObject.contains("rxChannels"))
    {
        limeRFESettings.setRxChannels(jsonObject["rxChannels"].toInt());
        limeRFESettingsKeys.append("rxChannels");
    }
    if (jsonObject.contains("rxWidebandChannel"))
    {
        limeRFESettings.setRxWidebandChannel(jsonObject["rxWidebandChannel"].toInt());
        limeRFESettingsKeys.append("rxWidebandChannel");
    }
    if (jsonObject.contains("rxHAMChannel"))
    {
        limeRFESettings.setRxHamChannel(jsonObject["rxHAMChannel"].toInt());
        limeRFESettingsKeys.append("rxHAMChannel");
    }
    if (jsonObject.contains("rxCellularChannel"))
    {
        limeRFESettings.setRxCellularChannel(jsonObject["rxCellularChannel"].toInt());
        limeRFESettingsKeys.append("rxCellularChannel");
    }
    if (jsonObject.contains("rxPort"))
    {
        limeRFESettings.setRxPort(jsonObject["rxPort"].toInt());
        limeRFESettingsKeys.append("rxPort");
    }
    if (jsonObject.contains("attenuationFactor"))
    {
        limeRFESettings.setAttenuationFactor(jsonObject["attenuationFactor"].toInt());
        limeRFESettingsKeys.append("attenuationFactor");
    }
    if (jsonObject.contains("amfmNotch"))
    {
        limeRFESettings.setAmfmNotch(jsonObject["amfmNotch"].toInt());
        limeRFESettingsKeys.append("amfmNotch");
    }
    if (jsonObject.contains("txChannels"))
    {
        limeRFESettings.setTxChannels(jsonObject["txChannels"].toInt());
        limeRFESettingsKeys.append("txChannels");
    }
    if (jsonObject.contains("txWidebandChannel"))
    {
        limeRFESettings.setTxWidebandChannel(jsonObject["txWidebandChannel"].toInt());
        limeRFESettingsKeys.append("txWidebandChannel");
    }
    if (jsonObject.contains("txHAMChannel"))
    {
        limeRFESettings.setTxHamChannel(jsonObject["txHAMChannel"].toInt());
        limeRFESettingsKeys.append("txHAMChannel");
    }
    if (jsonObject.contains("txCellularChannel"))
    {
        limeRFESettings.setTxCellularChannel(jsonObject["txCellularChannel"].toInt());
        limeRFESettingsKeys.append("txCellularChannel");
    }
    if (jsonObject.contains("txPort"))
    {
        limeRFESettings.setTxPort(jsonObject["txPort"].toInt());
        limeRFESettingsKeys.append("txPort");
    }
    if (jsonObject.contains("rxOn"))
    {
        limeRFESettings.setRxOn(jsonObject["rxOn"].toInt());
        limeRFESettingsKeys.append("rxOn");
    }
    if (jsonObject.contains("txOn"))
    {
        limeRFESettings.setTxOn(jsonObject["txOn"].toInt());
        limeRFESettingsKeys.append("txOn");
    }
    if (jsonObject.contains("swrEnable"))
    {
        limeRFESettings.setSwrEnable(jsonObject["swrEnable"].toInt());
        limeRFESettingsKeys.append("swrEnable");
    }
    if (jsonObject.contains("swrSource"))
    {
        limeRFESettings.setSwrSource(jsonObject["swrSource"].toInt());
        limeRFESettingsKeys.append("swrSource");
    }

    return true;
}

bool WebAPIRequestMapper::validateSpectrumSettings(SWGrpx-100::SWGGLSpectrum& spectrumSettings, QJsonObject& jsonObject, QStringList& spectrumSettingsKeys)
{
    if (jsonObject.contains("fftSize"))
    {
        spectrumSettings.setFftSize(jsonObject["fftSize"].toInt(1024));
        spectrumSettingsKeys.append("fftSize");
    }
    if (jsonObject.contains("fftOverlap"))
    {
        spectrumSettings.setFftOverlap(jsonObject["fftOverlap"].toInt(0));
        spectrumSettingsKeys.append("fftOverlap");
    }
    if (jsonObject.contains("fftWindow"))
    {
        spectrumSettings.setFftWindow(jsonObject["fftWindow"].toInt(0));
        spectrumSettingsKeys.append("fftWindow");
    }
    if (jsonObject.contains("refLevel"))
    {
        spectrumSettings.setRefLevel(jsonObject["refLevel"].toDouble(0.0));
        spectrumSettingsKeys.append("refLevel");
    }
    if (jsonObject.contains("powerRange"))
    {
        spectrumSettings.setPowerRange(jsonObject["powerRange"].toDouble(100.0));
        spectrumSettingsKeys.append("powerRange");
    }
    if (jsonObject.contains("fpsPeriodMs"))
    {
        spectrumSettings.setFpsPeriodMs(jsonObject["fpsPeriodMs"].toInt(50));
        spectrumSettingsKeys.append("fpsPeriodMs");
    }
    if (jsonObject.contains("displayWaterfall"))
    {
        spectrumSettings.setDisplayWaterfall(jsonObject["displayWaterfall"].toInt(0));
        spectrumSettingsKeys.append("displayWaterfall");
    }
    if (jsonObject.contains("invertedWaterfall"))
    {
        spectrumSettings.setInvertedWaterfall(jsonObject["invertedWaterfall"].toInt(0));
        spectrumSettingsKeys.append("invertedWaterfall");
    }
    if (jsonObject.contains("displayHistogram"))
    {
        spectrumSettings.setDisplayHistogram(jsonObject["displayHistogram"].toInt(0));
        spectrumSettingsKeys.append("displayHistogram");
    }
    if (jsonObject.contains("decay"))
    {
        spectrumSettings.setDecay(jsonObject["decay"].toInt(1));
        spectrumSettingsKeys.append("decay");
    }
    if (jsonObject.contains("displayGrid"))
    {
        spectrumSettings.setDisplayGrid(jsonObject["displayGrid"].toInt(0));
        spectrumSettingsKeys.append("displayGrid");
    }
    if (jsonObject.contains("displayGridIntensity"))
    {
        spectrumSettings.setDisplayGridIntensity(jsonObject["displayGridIntensity"].toInt(30));
        spectrumSettingsKeys.append("displayGridIntensity");
    }
    if (jsonObject.contains("decayDivisor"))
    {
        spectrumSettings.setDecayDivisor(jsonObject["decayDivisor"].toInt(1));
        spectrumSettingsKeys.append("decayDivisor");
    }
    if (jsonObject.contains("histogramStroke"))
    {
        spectrumSettings.setHistogramStroke(jsonObject["histogramStroke"].toInt(10));
        spectrumSettingsKeys.append("histogramStroke");
    }
    if (jsonObject.contains("displayCurrent"))
    {
        spectrumSettings.setDisplayCurrent(jsonObject["displayCurrent"].toInt(1));
        spectrumSettingsKeys.append("displayCurrent");
    }
    if (jsonObject.contains("displayTraceIntensity"))
    {
        spectrumSettings.setDisplayTraceIntensity(jsonObject["displayTraceIntensity"].toInt(50));
        spectrumSettingsKeys.append("displayTraceIntensity");
    }
    if (jsonObject.contains("waterfallShare"))
    {
        spectrumSettings.setWaterfallShare(jsonObject["waterfallShare"].toDouble(0.5));
        spectrumSettingsKeys.append("waterfallShare");
    }
    if (jsonObject.contains("averagingMode"))
    {
        spectrumSettings.setAveragingMode(jsonObject["averagingMode"].toInt(0));
        spectrumSettingsKeys.append("averagingMode");
    }
    if (jsonObject.contains("averagingValue"))
    {
        spectrumSettings.setAveragingValue(jsonObject["averagingValue"].toInt(0));
        spectrumSettingsKeys.append("averagingValue");
    }
    if (jsonObject.contains("linear"))
    {
        spectrumSettings.setLinear(jsonObject["linear"].toInt(0));
        spectrumSettingsKeys.append("linear");
    }
    if (jsonObject.contains("ssb"))
    {
        spectrumSettings.setSsb(jsonObject["ssb"].toInt(0));
        spectrumSettingsKeys.append("ssb");
    }
    if (jsonObject.contains("usb"))
    {
        spectrumSettings.setUsb(jsonObject["usb"].toInt(1));
        spectrumSettingsKeys.append("usb");
    }
    if (jsonObject.contains("wsSpectrumAddress") && jsonObject["wsSpectrumAddress"].isString())
    {
        spectrumSettings.setWsSpectrumAddress(new QString(jsonObject["wsSpectrumAddress"].toString()));
        spectrumSettingsKeys.append("wsSpectrumAddress");
    }
    if (jsonObject.contains("wsSpectrumPort"))
    {
        spectrumSettings.setWsSpectrumPort(jsonObject["wsSpectrumPort"].toInt(8887));
        spectrumSettingsKeys.append("wsSpectrumPort");
    }

    return true;
}

bool WebAPIRequestMapper::validateConfig(
    SWGrpx-100::SWGInstanceConfigResponse& config,
    QJsonObject& jsonObject,
    WebAPIAdapterInterface::ConfigKeys& configKeys)
{
    if (jsonObject.contains("preferences"))
    {
        SWGrpx-100::SWGPreferences *preferences = new SWGrpx-100::SWGPreferences();
        config.setPreferences(preferences);
        QJsonObject preferencesJson = jsonObject["preferences"].toObject();
        configKeys.m_preferencesKeys = preferencesJson.keys();
        preferences->fromJsonObject(preferencesJson);
    }

    if (jsonObject.contains("commands"))
    {
        QList<SWGrpx-100::SWGCommand *> *commands = new QList<SWGrpx-100::SWGCommand *>();
        config.setCommands(commands);
        QJsonArray commandsJson = jsonObject["commands"].toArray();
        QJsonArray::const_iterator commandsIt = commandsJson.begin();

        for (; commandsIt != commandsJson.end(); ++commandsIt)
        {
            QJsonObject commandJson = commandsIt->toObject();
            commands->append(new SWGrpx-100::SWGCommand());
            configKeys.m_commandKeys.append(WebAPIAdapterInterface::CommandKeys());
            configKeys.m_commandKeys.back().m_keys = commandJson.keys();
            commands->back()->fromJsonObject(commandJson);
        }
    }

    if (jsonObject.contains("presets"))
    {
        QList<SWGrpx-100::SWGPreset *> *presets = new QList<SWGrpx-100::SWGPreset *>();
        config.setPresets(presets);
        QJsonArray presetsJson = jsonObject["presets"].toArray();
        QJsonArray::const_iterator presetsIt = presetsJson.begin();

        for (; presetsIt != presetsJson.end(); ++presetsIt)
        {
            QJsonObject presetJson = presetsIt->toObject();
            SWGrpx-100::SWGPreset *preset = new SWGrpx-100::SWGPreset();
            presets->append(preset);
            configKeys.m_presetKeys.append(WebAPIAdapterInterface::PresetKeys());
            appendPresetKeys(preset, presetJson, configKeys.m_presetKeys.back());
        }
    }

    if (jsonObject.contains("featuresetpresets"))
    {
        QList<SWGrpx-100::SWGFeatureSetPreset *> *featureSetPresets = new QList<SWGrpx-100::SWGFeatureSetPreset *>();
        config.setFeaturesetpresets(featureSetPresets);
        QJsonArray presetsJson = jsonObject["featuresetpresets"].toArray();
        QJsonArray::const_iterator featureSetPresetsIt = presetsJson.begin();

        for (; featureSetPresetsIt != presetsJson.end(); ++featureSetPresetsIt)
        {
            QJsonObject presetJson = featureSetPresetsIt->toObject();
            SWGrpx-100::SWGFeatureSetPreset *featureSetPreset = new SWGrpx-100::SWGFeatureSetPreset();
            featureSetPresets->append(featureSetPreset);
            configKeys.m_featureSetPresetKeys.append(WebAPIAdapterInterface::FeatureSetPresetKeys());
            appendFeatureSetPresetKeys(featureSetPreset, presetJson, configKeys.m_featureSetPresetKeys.back());
        }
    }

    if (jsonObject.contains("workingPreset"))
    {
        SWGrpx-100::SWGPreset *preset = new SWGrpx-100::SWGPreset();
        config.setWorkingPreset(preset);
        QJsonObject presetJson = jsonObject["workingPreset"].toObject();
        appendPresetKeys(preset, presetJson, configKeys.m_workingPresetKeys);
    }

    if (jsonObject.contains("workingFeatureSetPreset"))
    {
        SWGrpx-100::SWGFeatureSetPreset *preset = new SWGrpx-100::SWGFeatureSetPreset();
        config.setWorkingFeatureSetPreset(preset);
        QJsonObject presetJson = jsonObject["workingFeatureSetPreset"].toObject();
        appendFeatureSetPresetKeys(preset, presetJson, configKeys.m_workingFeatureSetPresetKeys);
    }

    return true;
}

bool WebAPIRequestMapper::appendFeatureSetPresetKeys(
    SWGrpx-100::SWGFeatureSetPreset *preset,
    const QJsonObject& presetJson,
    WebAPIAdapterInterface::FeatureSetPresetKeys& featureSetPresetKeys
)
{
    if (presetJson.contains("description"))
    {
        preset->setDescription(new QString(presetJson["description"].toString()));
        featureSetPresetKeys.m_keys.append("description");
    }
    if (presetJson.contains("group"))
    {
        preset->setGroup(new QString(presetJson["group"].toString()));
        featureSetPresetKeys.m_keys.append("group");
    }
    if (presetJson.contains("featureConfigs"))
    {
        QJsonArray featuresJson = presetJson["featureConfigs"].toArray();
        QJsonArray::const_iterator featuresIt = featuresJson.begin();
        QList<SWGrpx-100::SWGFeatureConfig*> *features = new QList<SWGrpx-100::SWGFeatureConfig*>();
        preset->setFeatureConfigs(features);

        for (; featuresIt != featuresJson.end(); ++featuresIt)
        {
            QJsonObject featureJson = featuresIt->toObject();
            SWGrpx-100::SWGFeatureConfig *featureConfig = new SWGrpx-100::SWGFeatureConfig();
            featureSetPresetKeys.m_featureKeys.append(WebAPIAdapterInterface::FeatureKeys());

            if (appendPresetFeatureKeys(featureConfig, featureJson, featureSetPresetKeys.m_featureKeys.back()))
            {
                features->append(featureConfig);
            }
            else
            {
                delete featureConfig;
                featureSetPresetKeys.m_featureKeys.takeLast(); // remove channel keys
            }
        }
    }

    return true;
}

bool WebAPIRequestMapper::appendPresetKeys(
    SWGrpx-100::SWGPreset *preset,
    const QJsonObject& presetJson,
    WebAPIAdapterInterface::PresetKeys& presetKeys
)
{
    if (presetJson.contains("centerFrequency"))
    {
        preset->setCenterFrequency(presetJson["centerFrequency"].toInt());
        presetKeys.m_keys.append("centerFrequency");
    }
    if (presetJson.contains("dcOffsetCorrection"))
    {
        preset->setDcOffsetCorrection(presetJson["dcOffsetCorrection"].toInt());
        presetKeys.m_keys.append("dcOffsetCorrection");
    }
    if (presetJson.contains("iqImbalanceCorrection"))
    {
        preset->setIqImbalanceCorrection(presetJson["iqImbalanceCorrection"].toInt());
        presetKeys.m_keys.append("iqImbalanceCorrection");
    }
    if (presetJson.contains("iqImbalanceCorrection"))
    {
        preset->setPresetType(presetJson["presetType"].toInt());
        presetKeys.m_keys.append("presetType");
    }
    if (presetJson.contains("description"))
    {
        preset->setDescription(new QString(presetJson["description"].toString()));
        presetKeys.m_keys.append("description");
    }
    if (presetJson.contains("group"))
    {
        preset->setGroup(new QString(presetJson["group"].toString()));
        presetKeys.m_keys.append("group");
    }
    if (presetJson.contains("layout"))
    {
        preset->setLayout(new QString(presetJson["layout"].toString()));
        presetKeys.m_keys.append("layout");
    }

    if (presetJson.contains("spectrumConfig"))
    {
        QJsonObject spectrumJson = presetJson["spectrumConfig"].toObject();
        presetKeys.m_spectrumKeys = spectrumJson.keys();
        SWGrpx-100::SWGGLSpectrum *spectrum = new SWGrpx-100::SWGGLSpectrum();
        preset->setSpectrumConfig(spectrum);
        spectrum->fromJsonObject(spectrumJson);
    }

    if (presetJson.contains("channelConfigs"))
    {
        QJsonArray channelsJson = presetJson["channelConfigs"].toArray();
        QJsonArray::const_iterator channelsIt = channelsJson.begin();
        QList<SWGrpx-100::SWGChannelConfig*> *channels = new QList<SWGrpx-100::SWGChannelConfig*>();
        preset->setChannelConfigs(channels);

        for (; channelsIt != channelsJson.end(); ++channelsIt)
        {
            QJsonObject channelJson = channelsIt->toObject();
            SWGrpx-100::SWGChannelConfig *channelConfig = new SWGrpx-100::SWGChannelConfig();
            presetKeys.m_channelsKeys.append(WebAPIAdapterInterface::ChannelKeys());

            if (appendPresetChannelKeys(channelConfig, channelJson, presetKeys.m_channelsKeys.back()))
            {
                channels->append(channelConfig);
            }
            else
            {
                delete channelConfig;
                presetKeys.m_channelsKeys.takeLast(); // remove channel keys
            }
        }
    }

    if (presetJson.contains("deviceConfigs"))
    {
        QJsonArray devicesJson = presetJson["deviceConfigs"].toArray();
        QJsonArray::const_iterator devicesIt = devicesJson.begin();
        QList<SWGrpx-100::SWGDeviceConfig*> *devices = new QList<SWGrpx-100::SWGDeviceConfig*>();
        preset->setDeviceConfigs(devices);

        for (; devicesIt != devicesJson.end(); ++devicesIt)
        {
            QJsonObject deviceJson = devicesIt->toObject();
            SWGrpx-100::SWGDeviceConfig *deviceConfig = new SWGrpx-100::SWGDeviceConfig();
            presetKeys.m_devicesKeys.append(WebAPIAdapterInterface::DeviceKeys());

            if (appendPresetDeviceKeys(deviceConfig, deviceJson, presetKeys.m_devicesKeys.back()))
            {
                devices->append(deviceConfig);
            }
            else
            {
                delete deviceConfig;
                presetKeys.m_devicesKeys.takeLast(); // remove device keys
            }
        }
    }

    return true;
}

bool WebAPIRequestMapper::appendPresetFeatureKeys(
        SWGrpx-100::SWGFeatureConfig *feature,
        const QJsonObject& featureSettingsJson,
        WebAPIAdapterInterface::FeatureKeys& featureKeys
)
{
    if (featureSettingsJson.contains("featureIdURI"))
    {
        QString *featureURI = new QString(featureSettingsJson["featureIdURI"].toString());
        feature->setFeatureIdUri(featureURI);
        featureKeys.m_keys.append("featureIdURI");

        if (featureSettingsJson.contains("config") && WebAPIUtils::m_featureURIToSettingsKey.contains(*featureURI))
        {
            SWGrpx-100::SWGFeatureSettings *featureSettings = new SWGrpx-100::SWGFeatureSettings();
            feature->setConfig(featureSettings);
            return getFeatureSettings(
                WebAPIUtils::m_channelURIToSettingsKey[*featureURI],
                featureSettings,
                featureSettingsJson["config"].toObject(),
                featureKeys.m_featureKeys
            );
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool WebAPIRequestMapper::appendPresetChannelKeys(
        SWGrpx-100::SWGChannelConfig *channel,
        const QJsonObject& channelSettingsJson,
        WebAPIAdapterInterface::ChannelKeys& channelKeys
)
{
    if (channelSettingsJson.contains("channelIdURI"))
    {
        QString *channelURI = new QString(channelSettingsJson["channelIdURI"].toString());
        channel->setChannelIdUri(channelURI);
        channelKeys.m_keys.append("channelIdURI");

        if (channelSettingsJson.contains("config") && WebAPIUtils::m_channelURIToSettingsKey.contains(*channelURI))
        {
            SWGrpx-100::SWGChannelSettings *channelSettings = new SWGrpx-100::SWGChannelSettings();
            channel->setConfig(channelSettings);
            return getChannelSettings(WebAPIUtils::m_channelURIToSettingsKey[*channelURI], channelSettings, channelSettingsJson["config"].toObject(), channelKeys.m_channelKeys);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool WebAPIRequestMapper::getChannelSettings(
    const QString& channelSettingsKey,
    SWGrpx-100::SWGChannelSettings *channelSettings,
    const QJsonObject& channelSettingsJson,
    QStringList& channelSettingsKeys
)
{
    QStringList channelKeys = channelSettingsJson.keys();

    if (channelKeys.contains(channelSettingsKey) && channelSettingsJson[channelSettingsKey].isObject())
    {
        QJsonObject settingsJsonObject = channelSettingsJson[channelSettingsKey].toObject();
        channelSettingsKeys = settingsJsonObject.keys();

        // get possible sub-keys
        if (channelSettingsKeys.contains("cwKeyer"))
        {
            QJsonObject cwJson; // unused
            appendSettingsSubKeys(settingsJsonObject, cwJson, "cwKeyer", channelSettingsKeys);
        }

        if (channelSettingsKey == "ADSBDemodSettings")
        {
            channelSettings->setAdsbDemodSettings(new SWGrpx-100::SWGADSBDemodSettings());
            channelSettings->getAdsbDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "AISDemodSettings")
        {
            channelSettings->setAisDemodSettings(new SWGrpx-100::SWGAISDemodSettings());
            channelSettings->getAisDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "AISModSettings")
        {
            channelSettings->setAisModSettings(new SWGrpx-100::SWGAISModSettings());
            channelSettings->getAisModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "AMDemodSettings")
        {
            channelSettings->setAmDemodSettings(new SWGrpx-100::SWGAMDemodSettings());
            channelSettings->getAmDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "AMModSettings")
        {
            channelSettings->setAmModSettings(new SWGrpx-100::SWGAMModSettings());
            channelSettings->getAmModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "APTDemodSettings")
        {
            channelSettings->setAptDemodSettings(new SWGrpx-100::SWGAPTDemodSettings());
            channelSettings->getAptDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "ATVDemodSettings")
        {
            channelSettings->setAtvDemodSettings(new SWGrpx-100::SWGATVDemodSettings());
            channelSettings->getAtvDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "ATVModSettings")
        {
            channelSettings->setAtvModSettings(new SWGrpx-100::SWGATVModSettings());
            channelSettings->getAtvModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "BeamSteeringCWModSettings")
        {
            channelSettings->setBeamSteeringCwModSettings(new SWGrpx-100::SWGBeamSteeringCWModSettings());
            channelSettings->getBeamSteeringCwModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "BFMDemodSettings")
        {
            channelSettings->setBfmDemodSettings(new SWGrpx-100::SWGBFMDemodSettings());
            channelSettings->getBfmDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "ChannelAnalyzerSettings")
        {
            processChannelAnalyzerSettings(channelSettings, settingsJsonObject, channelSettingsKeys);
        }
        else if (channelSettingsKey == "ChirpChatDemodSettings")
        {
            channelSettings->setChirpChatDemodSettings(new SWGrpx-100::SWGChirpChatDemodSettings());
            channelSettings->getChirpChatDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "ChirpChatModSettings")
        {
            channelSettings->setChirpChatModSettings(new SWGrpx-100::SWGChirpChatModSettings());
            channelSettings->getChirpChatModSettings()->init(); // contains a list of strings
            channelSettings->getChirpChatModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "DATVDemodSettings")
        {
            channelSettings->setDatvDemodSettings(new SWGrpx-100::SWGDATVDemodSettings());
            channelSettings->getDatvDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "DATVModSettings")
        {
            channelSettings->setDatvModSettings(new SWGrpx-100::SWGDATVModSettings());
            channelSettings->getDatvModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "DABDemodSettings")
        {
            channelSettings->setDabDemodSettings(new SWGrpx-100::SWGDABDemodSettings());
            channelSettings->getDabDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "DSDDemodSettings")
        {
            channelSettings->setDsdDemodSettings(new SWGrpx-100::SWGDSDDemodSettings());
            channelSettings->getDsdDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "FileSinkSettings")
        {
            channelSettings->setFileSinkSettings(new SWGrpx-100::SWGFileSinkSettings());
            channelSettings->getFileSinkSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "FileSourceSettings")
        {
            channelSettings->setFileSourceSettings(new SWGrpx-100::SWGFileSourceSettings());
            channelSettings->getFileSourceSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "FreeDVDemodSettings")
        {
            channelSettings->setFreeDvDemodSettings(new SWGrpx-100::SWGFreeDVDemodSettings());
            channelSettings->getFreeDvDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "FreeDVModSettings")
        {
            channelSettings->setFreeDvModSettings(new SWGrpx-100::SWGFreeDVModSettings());
            channelSettings->getFreeDvModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "FreqTrackerSettings")
        {
            channelSettings->setFreqTrackerSettings(new SWGrpx-100::SWGFreqTrackerSettings());
            channelSettings->getFreqTrackerSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "IEEE_802_15_4_ModSettings")
        {
            channelSettings->setIeee802154ModSettings(new SWGrpx-100::SWGIEEE_802_15_4_ModSettings());
            channelSettings->getIeee802154ModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "InterferometerSettings")
        {
            channelSettings->setInterferometerSettings(new SWGrpx-100::SWGInterferometerSettings());
            channelSettings->getInterferometerSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "NFMDemodSettings")
        {
            channelSettings->setNfmDemodSettings(new SWGrpx-100::SWGNFMDemodSettings());
            channelSettings->getNfmDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "NFMModSettings")
        {
            channelSettings->setNfmModSettings(new SWGrpx-100::SWGNFMModSettings());
            channelSettings->getNfmModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "NoiseFigureSettings")
        {
            channelSettings->setNoiseFigureSettings(new SWGrpx-100::SWGNoiseFigureSettings());
            channelSettings->getNoiseFigureSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "LocalSinkSettings")
        {
            channelSettings->setLocalSinkSettings(new SWGrpx-100::SWGLocalSinkSettings());
            channelSettings->getLocalSinkSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "LocalSourceSettings")
        {
            channelSettings->setLocalSourceSettings(new SWGrpx-100::SWGLocalSourceSettings());
            channelSettings->getLocalSourceSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "PacketDemodSettings")
        {
            channelSettings->setPacketDemodSettings(new SWGrpx-100::SWGPacketDemodSettings());
            channelSettings->getPacketDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "PacketModSettings")
        {
            channelSettings->setPacketModSettings(new SWGrpx-100::SWGPacketModSettings());
            channelSettings->getPacketModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "PagerDemodSettings")
        {
            channelSettings->setPagerDemodSettings(new SWGrpx-100::SWGPagerDemodSettings());
            channelSettings->getPagerDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "RadioClockSettings")
        {
            channelSettings->setRadioClockSettings(new SWGrpx-100::SWGRadioClockSettings());
            channelSettings->getRadioClockSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "RemoteSinkSettings")
        {
            channelSettings->setRemoteSinkSettings(new SWGrpx-100::SWGRemoteSinkSettings());
            channelSettings->getRemoteSinkSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "RemoteSourceSettings")
        {
            channelSettings->setRemoteSourceSettings(new SWGrpx-100::SWGRemoteSourceSettings());
            channelSettings->getRemoteSourceSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "SigMFFileSinkSettings")
        {
            channelSettings->setSigMfFileSinkSettings(new SWGrpx-100::SWGSigMFFileSinkSettings());
            channelSettings->getSigMfFileSinkSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "SSBDemodSettings")
        {
            channelSettings->setSsbDemodSettings(new SWGrpx-100::SWGSSBDemodSettings());
            channelSettings->getSsbDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "SSBModSettings")
        {
            channelSettings->setSsbModSettings(new SWGrpx-100::SWGSSBModSettings());
            channelSettings->getSsbModSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "UDPSourceSettings")
        {
            channelSettings->setUdpSourceSettings(new SWGrpx-100::SWGUDPSourceSettings());
            channelSettings->getUdpSourceSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "UDPSinkSettings")
        {
            channelSettings->setUdpSinkSettings(new SWGrpx-100::SWGUDPSinkSettings());
            channelSettings->getUdpSinkSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "VORDemodSettings")
        {
            channelSettings->setVorDemodSettings(new SWGrpx-100::SWGVORDemodSettings());
            channelSettings->getVorDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "WFMDemodSettings")
        {
            channelSettings->setWfmDemodSettings(new SWGrpx-100::SWGWFMDemodSettings());
            channelSettings->getWfmDemodSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (channelSettingsKey == "WFMModSettings")
        {
            channelSettings->setWfmModSettings(new SWGrpx-100::SWGWFMModSettings());
            channelSettings->getWfmModSettings()->fromJsonObject(settingsJsonObject);
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool WebAPIRequestMapper::getChannelActions(
    const QString& channelActionsKey,
    SWGrpx-100::SWGChannelActions *channelActions,
    const QJsonObject& channelActionsJson,
    QStringList& channelActionsKeys
)
{
    QStringList channelKeys = channelActionsJson.keys();

    if (channelKeys.contains(channelActionsKey) && channelActionsJson[channelActionsKey].isObject())
    {
        QJsonObject actionsJsonObject = channelActionsJson[channelActionsKey].toObject();
        channelActionsKeys = actionsJsonObject.keys();

        if (channelActionsKey == "AISModActions")
        {
            channelActions->setAisModActions(new SWGrpx-100::SWGAISModActions());
            channelActions->getAisModActions()->fromJsonObject(actionsJsonObject);
        }
        else if (channelActionsKey == "APTDemodActions")
        {
            channelActions->setAptDemodActions(new SWGrpx-100::SWGAPTDemodActions());
            channelActions->getAptDemodActions()->fromJsonObject(actionsJsonObject);
        }
        else if (channelActionsKey == "FileSinkActions")
        {
            channelActions->setFileSinkActions(new SWGrpx-100::SWGFileSinkActions());
            channelActions->getFileSinkActions()->fromJsonObject(actionsJsonObject);
        }
        else if (channelActionsKey == "FileSourceActions")
        {
            channelActions->setFileSourceActions(new SWGrpx-100::SWGFileSourceActions());
            channelActions->getFileSourceActions()->fromJsonObject(actionsJsonObject);
        }
        else if (channelActionsKey == "IEEE_802_15_4_ModActions")
        {
            channelActions->setIeee802154ModActions(new SWGrpx-100::SWGIEEE_802_15_4_ModActions());
            channelActions->getIeee802154ModActions()->fromJsonObject(actionsJsonObject);
        }
        else if (channelActionsKey == "PacketModActions")
        {
            channelActions->setPacketModActions(new SWGrpx-100::SWGPacketModActions());
            channelActions->getPacketModActions()->fromJsonObject(actionsJsonObject);
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool WebAPIRequestMapper::appendPresetDeviceKeys(
        SWGrpx-100::SWGDeviceConfig *device,
        const QJsonObject& deviceSettngsJson,
        WebAPIAdapterInterface::DeviceKeys& devicelKeys
)
{
    if (deviceSettngsJson.contains("deviceId"))
    {
        QString *deviceId = new QString(deviceSettngsJson["deviceId"].toString());
        device->setDeviceId(deviceId);
        devicelKeys.m_keys.append("deviceId");

        if (deviceSettngsJson.contains("deviceSerial"))
        {
            device->setDeviceSerial(new QString(deviceSettngsJson["deviceSerial"].toString()));
            devicelKeys.m_keys.append("deviceSerial");
        }

        if (deviceSettngsJson.contains("deviceSequence"))
        {
            device->setDeviceSequence(deviceSettngsJson["deviceSequence"].toInt());
            devicelKeys.m_keys.append("deviceSequence");
        }

        if (deviceSettngsJson.contains("config") && WebAPIUtils::m_deviceIdToSettingsKey.contains(*deviceId))
        {
            SWGrpx-100::SWGDeviceSettings *deviceSettings = new SWGrpx-100::SWGDeviceSettings();
            device->setConfig(deviceSettings);
            return getDeviceSettings(WebAPIUtils::m_deviceIdToSettingsKey[*deviceId], deviceSettings, deviceSettngsJson["config"].toObject(), devicelKeys.m_deviceKeys);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool WebAPIRequestMapper::getDeviceSettings(
        const QString& deviceSettingsKey,
        SWGrpx-100::SWGDeviceSettings *deviceSettings,
        const QJsonObject& deviceSettingsJson,
        QStringList& deviceSettingsKeys
)
{
    QStringList deviceKeys = deviceSettingsJson.keys();

    if (deviceKeys.contains(deviceSettingsKey) && deviceSettingsJson[deviceSettingsKey].isObject())
    {
        QJsonObject settingsJsonObject = deviceSettingsJson[deviceSettingsKey].toObject();
        deviceSettingsKeys = settingsJsonObject.keys();

        if (deviceSettingsKey == "airspySettings")
        {
            deviceSettings->setAirspySettings(new SWGrpx-100::SWGAirspySettings());
            deviceSettings->getAirspySettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "airspyHFSettings")
        {
            deviceSettings->setAirspyHfSettings(new SWGrpx-100::SWGAirspyHFSettings());
            deviceSettings->getAirspyHfSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "audioInputSettings")
        {
            deviceSettings->setAudioInputSettings(new SWGrpx-100::SWGAudioInputSettings());
            deviceSettings->getAudioInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "audioOutputSettings")
        {
            deviceSettings->setAudioOutputSettings(new SWGrpx-100::SWGAudioOutputSettings());
            deviceSettings->getAudioOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "bladeRF1InputSettings")
        {
            deviceSettings->setBladeRf1InputSettings(new SWGrpx-100::SWGBladeRF1InputSettings());
            deviceSettings->getBladeRf1InputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "bladeRF1OutputSettings")
        {
            deviceSettings->setBladeRf1OutputSettings(new SWGrpx-100::SWGBladeRF1OutputSettings());
            deviceSettings->getBladeRf1OutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "bladeRF2InputSettings")
        {
            deviceSettings->setBladeRf2InputSettings(new SWGrpx-100::SWGBladeRF2InputSettings());
            deviceSettings->getBladeRf2InputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "bladeRF2OutputSettings")
        {
            deviceSettings->setBladeRf2OutputSettings(new SWGrpx-100::SWGBladeRF2OutputSettings());
            deviceSettings->getBladeRf2OutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "bladeRF2MIMOSettings")
        {
            if (deviceSettingsKeys.contains("streams") && settingsJsonObject["streams"].isArray()) {
                appendSettingsArrayKeys(settingsJsonObject, "streams", deviceSettingsKeys);
            }

            deviceSettings->setBladeRf2MimoSettings(new SWGrpx-100::SWGBladeRF2MIMOSettings());
            deviceSettings->getBladeRf2MimoSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "fcdProSettings")
        {
            deviceSettings->setFcdProSettings(new SWGrpx-100::SWGFCDProSettings());
            deviceSettings->getFcdProSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "fcdProPlusSettings")
        {
            deviceSettings->setFcdProPlusSettings(new SWGrpx-100::SWGFCDProPlusSettings());
            deviceSettings->getFcdProPlusSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "fileInputSettings")
        {
            deviceSettings->setFileInputSettings(new SWGrpx-100::SWGFileInputSettings());
            deviceSettings->getFileInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "fileOutputSettings")
        {
            deviceSettings->setFileOutputSettings(new SWGrpx-100::SWGFileOutputSettings());
            deviceSettings->getFileOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "hackRFInputSettings")
        {
            deviceSettings->setHackRfInputSettings(new SWGrpx-100::SWGHackRFInputSettings());
            deviceSettings->getHackRfInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "hackRFOutputSettings")
        {
            deviceSettings->setHackRfOutputSettings(new SWGrpx-100::SWGHackRFOutputSettings());
            deviceSettings->getHackRfOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "kiwiSDRSettings")
        {
            deviceSettings->setKiwiSdrSettings(new SWGrpx-100::SWGKiwiSDRSettings());
            deviceSettings->getKiwiSdrSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "limeSdrInputSettings")
        {
            deviceSettings->setLimeSdrInputSettings(new SWGrpx-100::SWGLimeSdrInputSettings());
            deviceSettings->getLimeSdrInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "limeSdrOutputSettings")
        {
            deviceSettings->setLimeSdrOutputSettings(new SWGrpx-100::SWGLimeSdrOutputSettings());
            deviceSettings->getLimeSdrOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "limeSdrMIMOSettings")
        {
            if (deviceSettingsKeys.contains("streams") && settingsJsonObject["streams"].isArray()) {
                appendSettingsArrayKeys(settingsJsonObject, "streams", deviceSettingsKeys);
            }

            deviceSettings->setLimeSdrMimoSettings(new SWGrpx-100::SWGLimeSdrMIMOSettings());
            deviceSettings->getLimeSdrMimoSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "metisMISOSettings")
        {
            if (deviceSettingsKeys.contains("streams") && settingsJsonObject["streams"].isArray()) {
                appendSettingsArrayKeys(settingsJsonObject, "streams", deviceSettingsKeys);
            }

            deviceSettings->setMetisMisoSettings(new SWGrpx-100::SWGMetisMISOSettings());
            deviceSettings->getMetisMisoSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "perseusSettings")
        {
            deviceSettings->setPerseusSettings(new SWGrpx-100::SWGPerseusSettings());
            deviceSettings->getPerseusSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "plutoSdrInputSettings")
        {
            deviceSettings->setPlutoSdrInputSettings(new SWGrpx-100::SWGPlutoSdrInputSettings());
            deviceSettings->getPlutoSdrInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "plutoSdrOutputSettings")
        {
            deviceSettings->setPlutoSdrOutputSettings(new SWGrpx-100::SWGPlutoSdrOutputSettings());
            deviceSettings->getPlutoSdrOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "rtlSdrSettings")
        {
            deviceSettings->setRtlSdrSettings(new SWGrpx-100::SWGRtlSdrSettings());
            deviceSettings->getRtlSdrSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "sdrPlaySettings")
        {
            deviceSettings->setSdrPlaySettings(new SWGrpx-100::SWGSDRPlaySettings());
            deviceSettings->getSdrPlaySettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "sdrPlayV3Settings")
        {
            deviceSettings->setSdrPlayV3Settings(new SWGrpx-100::SWGSDRPlayV3Settings());
            deviceSettings->getSdrPlayV3Settings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "sigMFFileInputSettings")
        {
            deviceSettings->setSigMfFileInputSettings(new SWGrpx-100::SWGSigMFFileInputSettings());
            deviceSettings->getSigMfFileInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "soapySDRInputSettings")
        {
            processSoapySDRSettings(deviceSettings, settingsJsonObject, deviceSettingsKeys, true);
            // deviceSettings->setSoapySdrInputSettings(new SWGrpx-100::SWGSoapySDRInputSettings());
            // deviceSettings->getSoapySdrInputSettings()->init(); // contains complex objects
            // deviceSettings->getSoapySdrInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "soapySDROutputSettings")
        {
            processSoapySDRSettings(deviceSettings, settingsJsonObject, deviceSettingsKeys, false);
            // deviceSettings->setSoapySdrOutputSettings(new SWGrpx-100::SWGSoapySDROutputSettings());
            // deviceSettings->getSoapySdrOutputSettings()->init(); // contains complex objects
            // deviceSettings->getSoapySdrOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "testSourceSettings")
        {
            deviceSettings->setTestSourceSettings(new SWGrpx-100::SWGTestSourceSettings());
            deviceSettings->getTestSourceSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "testMISettings")
        {
            if (deviceSettingsKeys.contains("streams") && settingsJsonObject["streams"].isArray()) {
                appendSettingsArrayKeys(settingsJsonObject, "streams", deviceSettingsKeys);
            }

            deviceSettings->setTestMiSettings(new SWGrpx-100::SWGTestMISettings());
            deviceSettings->getTestMiSettings()->init();
            deviceSettings->getTestMiSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "testMOSyncSettings")
        {
            if (deviceSettingsKeys.contains("streams") && settingsJsonObject["streams"].isArray()) {
                appendSettingsArrayKeys(settingsJsonObject, "streams", deviceSettingsKeys);
            }

            deviceSettings->setTestMoSyncSettings(new SWGrpx-100::SWGTestMOSyncSettings());
            deviceSettings->getTestMoSyncSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "usrpInputSettings")
        {
            deviceSettings->setUsrpInputSettings(new SWGrpx-100::SWGUSRPInputSettings());
            deviceSettings->getUsrpInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "usrpOutputSettings")
        {
            deviceSettings->setUsrpOutputSettings(new SWGrpx-100::SWGUSRPOutputSettings());
            deviceSettings->getUsrpOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "xtrxInputSettings")
        {
            deviceSettings->setXtrxInputSettings(new SWGrpx-100::SWGXtrxInputSettings());
            deviceSettings->getXtrxInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "xtrxOutputSettings")
        {
            deviceSettings->setXtrxOutputSettings(new SWGrpx-100::SWGXtrxOutputSettings());
            deviceSettings->getXtrxOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "XtrxMIMOSettings")
        {
            if (deviceSettingsKeys.contains("streams") && settingsJsonObject["streams"].isArray()) {
                appendSettingsArrayKeys(settingsJsonObject, "streams", deviceSettingsKeys);
            }

            deviceSettings->setXtrxMimoSettings(new SWGrpx-100::SWGXtrxMIMOSettings());
            deviceSettings->getXtrxMimoSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "remoteInputSettings")
        {
            deviceSettings->setRemoteInputSettings(new SWGrpx-100::SWGRemoteInputSettings());
            deviceSettings->getRemoteInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "localInputSettings")
        {
            deviceSettings->setLocalInputSettings(new SWGrpx-100::SWGLocalInputSettings());
            deviceSettings->getLocalInputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "remoteOutputSettings")
        {
            deviceSettings->setRemoteOutputSettings(new SWGrpx-100::SWGRemoteOutputSettings());
            deviceSettings->getRemoteOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (deviceSettingsKey == "localOutputSettings")
        {
            deviceSettings->setLocalOutputSettings(new SWGrpx-100::SWGLocalOutputSettings());
            deviceSettings->getLocalOutputSettings()->fromJsonObject(settingsJsonObject);
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }

}

bool WebAPIRequestMapper::getDeviceActions(
        const QString& deviceActionsKey,
        SWGrpx-100::SWGDeviceActions *deviceActions,
        const QJsonObject& deviceActionsJson,
        QStringList& deviceActionsKeys
)
{
    QStringList deviceKeys = deviceActionsJson.keys();

    if (deviceKeys.contains(deviceActionsKey) && deviceActionsJson[deviceActionsKey].isObject())
    {
        QJsonObject actionsJsonObject = deviceActionsJson[deviceActionsKey].toObject();
        deviceActionsKeys = actionsJsonObject.keys();

        if (deviceActionsKey == "SigMFFileInputActions")
        {
            deviceActions->setSigMfFileInputActions(new SWGrpx-100::SWGSigMFFileInputActions());
            deviceActions->getSigMfFileInputActions()->fromJsonObject(actionsJsonObject);
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }

}

bool WebAPIRequestMapper::getFeatureSettings(
    const QString& featureSettingsKey,
    SWGrpx-100::SWGFeatureSettings *featureSettings,
    const QJsonObject& featureSettingsJson,
    QStringList& featureSettingsKeys
)
{
    QStringList featureKeys = featureSettingsJson.keys();

    if (featureKeys.contains(featureSettingsKey) && featureSettingsJson[featureSettingsKey].isObject())
    {
        QJsonObject settingsJsonObject = featureSettingsJson[featureSettingsKey].toObject();
        featureSettingsKeys = settingsJsonObject.keys();

        if (featureSettingsKey == "AISSSettings")
        {
            featureSettings->setAisSettings(new SWGrpx-100::SWGAISSettings());
            featureSettings->getAisSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "AntennaToolsSettings")
        {
            featureSettings->setAntennaToolsSettings(new SWGrpx-100::SWGAntennaToolsSettings());
            featureSettings->getAntennaToolsSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "APRSSettings")
        {
            featureSettings->setAprsSettings(new SWGrpx-100::SWGAPRSSettings());
            featureSettings->getAprsSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "GS232ControllerSettings")
        {
            featureSettings->setGs232ControllerSettings(new SWGrpx-100::SWGGS232ControllerSettings());
            featureSettings->getGs232ControllerSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "MapSettings")
        {
            featureSettings->setMapSettings(new SWGrpx-100::SWGMapSettings());
            featureSettings->getMapSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "PERTesterSettings")
        {
            featureSettings->setPerTesterSettings(new SWGrpx-100::SWGPERTesterSettings());
            featureSettings->getPerTesterSettings()->init();
            featureSettings->getPerTesterSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "SatelliteTrackerSettings")
        {
            featureSettings->setSatelliteTrackerSettings(new SWGrpx-100::SWGSatelliteTrackerSettings());
            featureSettings->getSatelliteTrackerSettings()->init();
            featureSettings->getSatelliteTrackerSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "SimplePTTSettings")
        {
            featureSettings->setSimplePttSettings(new SWGrpx-100::SWGSimplePTTSettings());
            featureSettings->getSimplePttSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "StarTrackerSettings")
        {
            featureSettings->setStarTrackerSettings(new SWGrpx-100::SWGStarTrackerSettings());
            featureSettings->getStarTrackerSettings()->fromJsonObject(settingsJsonObject);
        }
        else if (featureSettingsKey == "RigCtlServerSettings")
        {
            featureSettings->setRigCtlServerSettings(new SWGrpx-100::SWGRigCtlServerSettings());
            featureSettings->getRigCtlServerSettings()->fromJsonObject(settingsJsonObject);
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool WebAPIRequestMapper::getFeatureActions(
    const QString& featureActionsKey,
    SWGrpx-100::SWGFeatureActions *featureActions,
    const QJsonObject& featureActionsJson,
    QStringList& featureActionsKeys
)
{
    QStringList featureKeys = featureActionsJson.keys();

    if (featureKeys.contains(featureActionsKey) && featureActionsJson[featureActionsKey].isObject())
    {
        QJsonObject actionsJsonObject = featureActionsJson[featureActionsKey].toObject();
        featureActionsKeys = actionsJsonObject.keys();

        if (featureActionsKey == "MapActions")
        {
            featureActions->setMapActions(new SWGrpx-100::SWGMapActions());
            featureActions->getMapActions()->fromJsonObject(actionsJsonObject);
        }
        else if (featureActionsKey == "SimplePTTActions")
        {
            featureActions->setSimplePttActions(new SWGrpx-100::SWGSimplePTTActions());
            featureActions->getSimplePttActions()->fromJsonObject(actionsJsonObject);
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

void WebAPIRequestMapper::appendSettingsSubKeys(
        const QJsonObject& parentSettingsJsonObject,
        QJsonObject& childSettingsJsonObject,
        const QString& parentKey,
        QStringList& keyList)
{
    childSettingsJsonObject = parentSettingsJsonObject[parentKey].toObject();
    QStringList childSettingsKeys = childSettingsJsonObject.keys();

    for (int i = 0; i < childSettingsKeys.size(); i++) {
        keyList.append(parentKey + QString(".") + childSettingsKeys.at(i));
    }
}

void WebAPIRequestMapper::appendSettingsArrayKeys(
        const QJsonObject& parentSettingsJsonObject,
        const QString& parentKey,
        QStringList& keyList)
{
    QJsonArray arrayJson = parentSettingsJsonObject[parentKey].toArray();

    for (int arrayIndex = 0; arrayIndex < arrayJson.count(); arrayIndex++)
    {
        QJsonValue v = arrayJson.at(arrayIndex);

        if (v.isObject())
        {
            QJsonObject itemSettingsJsonObject = v.toObject();
            QStringList itemSettingsKeys = itemSettingsJsonObject.keys();
            keyList.append(tr("%1[%2]").arg(parentKey).arg(arrayIndex));

            for (int i = 0; i < itemSettingsKeys.size(); i++) {
                keyList.append(tr("%1[%2].%3").arg(parentKey).arg(arrayIndex).arg(itemSettingsKeys[i]));
            }
        }
    }
}

void WebAPIRequestMapper::resetSpectrumSettings(SWGrpx-100::SWGGLSpectrum& spectrumSettings)
{
    spectrumSettings.cleanup();
}

void WebAPIRequestMapper::resetDeviceSettings(SWGrpx-100::SWGDeviceSettings& deviceSettings)
{
    deviceSettings.cleanup();
    deviceSettings.setDeviceHwType(nullptr);
    deviceSettings.setAirspySettings(nullptr);
    deviceSettings.setAirspyHfSettings(nullptr);
    deviceSettings.setAudioInputSettings(nullptr);
    deviceSettings.setBladeRf1InputSettings(nullptr);
    deviceSettings.setBladeRf1OutputSettings(nullptr);
    deviceSettings.setFcdProPlusSettings(nullptr);
    deviceSettings.setFcdProSettings(nullptr);
    deviceSettings.setFileInputSettings(nullptr);
    deviceSettings.setFileOutputSettings(nullptr);
    deviceSettings.setHackRfInputSettings(nullptr);
    deviceSettings.setHackRfOutputSettings(nullptr);
    deviceSettings.setLimeSdrInputSettings(nullptr);
    deviceSettings.setLimeSdrOutputSettings(nullptr);
    deviceSettings.setPerseusSettings(nullptr);
    deviceSettings.setPlutoSdrInputSettings(nullptr);
    deviceSettings.setPlutoSdrOutputSettings(nullptr);
    deviceSettings.setRtlSdrSettings(nullptr);
    deviceSettings.setRemoteOutputSettings(nullptr);
    deviceSettings.setRemoteInputSettings(nullptr);
    deviceSettings.setSdrPlaySettings(nullptr);
    deviceSettings.setSdrPlayV3Settings(nullptr);
    deviceSettings.setTestSourceSettings(nullptr);
    deviceSettings.setUsrpInputSettings(nullptr);
    deviceSettings.setUsrpOutputSettings(nullptr);
}

void WebAPIRequestMapper::resetDeviceReport(SWGrpx-100::SWGDeviceReport& deviceReport)
{
    deviceReport.cleanup();
    deviceReport.setDeviceHwType(nullptr);
    deviceReport.setAirspyHfReport(nullptr);
    deviceReport.setAirspyReport(nullptr);
    deviceReport.setFileInputReport(nullptr);
    deviceReport.setLimeSdrInputReport(nullptr);
    deviceReport.setLimeSdrOutputReport(nullptr);
    deviceReport.setPerseusReport(nullptr);
    deviceReport.setPlutoSdrInputReport(nullptr);
    deviceReport.setPlutoSdrOutputReport(nullptr);
    deviceReport.setRtlSdrReport(nullptr);
    deviceReport.setRemoteOutputReport(nullptr);
    deviceReport.setRemoteInputReport(nullptr);
    deviceReport.setSdrPlayReport(nullptr);
    deviceReport.setSdrPlayV3Report(nullptr);
    deviceReport.setUsrpOutputReport(nullptr);
}

void WebAPIRequestMapper::resetDeviceActions(SWGrpx-100::SWGDeviceActions& deviceActions)
{
    deviceActions.cleanup();
    deviceActions.setDeviceHwType(nullptr);
    // deviceActions.setXtrxInputActions(nullptr);
}

void WebAPIRequestMapper::resetChannelSettings(SWGrpx-100::SWGChannelSettings& channelSettings)
{
    channelSettings.cleanup();
    channelSettings.setChannelType(nullptr);
    channelSettings.setAdsbDemodSettings(nullptr);
    channelSettings.setAisDemodSettings(nullptr);
    channelSettings.setAisModSettings(nullptr);
    channelSettings.setAmDemodSettings(nullptr);
    channelSettings.setAmModSettings(nullptr);
    channelSettings.setAptDemodSettings(nullptr);
    channelSettings.setAtvModSettings(nullptr);
    channelSettings.setBfmDemodSettings(nullptr);
    channelSettings.setDatvModSettings(nullptr);
    channelSettings.setDabDemodSettings(nullptr);
    channelSettings.setDsdDemodSettings(nullptr);
    channelSettings.setIeee802154ModSettings(nullptr);
    channelSettings.setNfmDemodSettings(nullptr);
    channelSettings.setNfmModSettings(nullptr);
    channelSettings.setNoiseFigureSettings(nullptr);
    channelSettings.setPacketDemodSettings(nullptr);
    channelSettings.setPacketModSettings(nullptr);
    channelSettings.setPagerDemodSettings(nullptr);
    channelSettings.setRemoteSinkSettings(nullptr);
    channelSettings.setRemoteSourceSettings(nullptr);
    channelSettings.setSsbDemodSettings(nullptr);
    channelSettings.setSsbModSettings(nullptr);
    channelSettings.setUdpSourceSettings(nullptr);
    channelSettings.setUdpSinkSettings(nullptr);
    channelSettings.setVorDemodSettings(nullptr);
    channelSettings.setWfmDemodSettings(nullptr);
    channelSettings.setWfmModSettings(nullptr);
}

void WebAPIRequestMapper::resetChannelReport(SWGrpx-100::SWGChannelReport& channelReport)
{
    channelReport.cleanup();
    channelReport.setChannelType(nullptr);
    channelReport.setAdsbDemodReport(nullptr);
    channelReport.setAisDemodReport(nullptr);
    channelReport.setAisModReport(nullptr);
    channelReport.setAmDemodReport(nullptr);
    channelReport.setAmModReport(nullptr);
    channelReport.setAtvModReport(nullptr);
    channelReport.setBfmDemodReport(nullptr);
    channelReport.setDatvModReport(nullptr);
    channelReport.setDsdDemodReport(nullptr);
    channelReport.setNfmDemodReport(nullptr);
    channelReport.setNfmModReport(nullptr);
    channelReport.setNoiseFigureReport(nullptr);
    channelReport.setIeee802154ModReport(nullptr);
    channelReport.setPacketModReport(nullptr);
    channelReport.setRemoteSourceReport(nullptr);
    channelReport.setSsbDemodReport(nullptr);
    channelReport.setSsbModReport(nullptr);
    channelReport.setUdpSourceReport(nullptr);
    channelReport.setUdpSinkReport(nullptr);
    channelReport.setVorDemodReport(nullptr);
    channelReport.setWfmDemodReport(nullptr);
    channelReport.setWfmModReport(nullptr);
}

void WebAPIRequestMapper::resetChannelActions(SWGrpx-100::SWGChannelActions& channelActions)
{
    channelActions.cleanup();
    channelActions.setAisModActions(nullptr);
    channelActions.setAptDemodActions(nullptr);
    channelActions.setChannelType(nullptr);
    channelActions.setFileSourceActions(nullptr);
    channelActions.setIeee802154ModActions(nullptr);
    channelActions.setPacketModActions(nullptr);
}

void WebAPIRequestMapper::resetAudioInputDevice(SWGrpx-100::SWGAudioInputDevice& audioInputDevice)
{
    audioInputDevice.cleanup();
    audioInputDevice.setName(nullptr);
}

void WebAPIRequestMapper::resetAudioOutputDevice(SWGrpx-100::SWGAudioOutputDevice& audioOutputDevice)
{
    audioOutputDevice.cleanup();
    audioOutputDevice.setName(nullptr);
    audioOutputDevice.setUdpAddress(nullptr);
}

void WebAPIRequestMapper::resetFeatureSettings(SWGrpx-100::SWGFeatureSettings& featureSettings)
{
    featureSettings.cleanup();
    featureSettings.setFeatureType(nullptr);
    featureSettings.setAntennaToolsSettings(nullptr);
    featureSettings.setAprsSettings(nullptr);
    featureSettings.setGs232ControllerSettings(nullptr);
    featureSettings.setMapSettings(nullptr);
    featureSettings.setPerTesterSettings(nullptr);
    featureSettings.setSatelliteTrackerSettings(nullptr);
    featureSettings.setSimplePttSettings(nullptr);
    featureSettings.setStarTrackerSettings(nullptr);
    featureSettings.setRigCtlServerSettings(nullptr);
}

void WebAPIRequestMapper::resetFeatureReport(SWGrpx-100::SWGFeatureReport& featureReport)
{
    featureReport.cleanup();
    featureReport.setFeatureType(nullptr);
    featureReport.setSimplePttReport(nullptr);
}

void WebAPIRequestMapper::resetFeatureActions(SWGrpx-100::SWGFeatureActions& featureActions)
{
    featureActions.cleanup();
    featureActions.setFeatureType(nullptr);
    featureActions.setMapActions(nullptr);
    featureActions.setSimplePttActions(nullptr);
}

void WebAPIRequestMapper::processChannelAnalyzerSettings(
        SWGrpx-100::SWGChannelSettings *channelSettings,
        const QJsonObject& channelSettingsJson,
        QStringList& channelSettingsKeys
)
{
    SWGrpx-100::SWGChannelAnalyzerSettings *channelAnalyzerSettings = new SWGrpx-100::SWGChannelAnalyzerSettings();
    channelSettings->setChannelAnalyzerSettings(channelAnalyzerSettings);
    channelAnalyzerSettings->init();

    if (channelSettingsJson.contains("bandwidth")) {
        channelAnalyzerSettings->setBandwidth(channelSettingsJson["bandwidth"].toInt());
    }
    if (channelSettingsJson.contains("downSample")) {
        channelAnalyzerSettings->setDownSample(channelSettingsJson["downSample"].toInt());
    }
    if (channelSettingsJson.contains("downSampleRate")) {
        channelAnalyzerSettings->setDownSampleRate(channelSettingsJson["downSampleRate"].toInt());
    }
    if (channelSettingsJson.contains("fll")) {
        channelAnalyzerSettings->setFll(channelSettingsJson["fll"].toInt());
    }
    if (channelSettingsJson.contains("frequency")) {
        channelAnalyzerSettings->setFrequency(channelSettingsJson["frequency"].toInt());
    }
    if (channelSettingsJson.contains("inputType")) {
        channelAnalyzerSettings->setInputType(channelSettingsJson["inputType"].toInt());
    }
    if (channelSettingsJson.contains("lowCutoff")) {
        channelAnalyzerSettings->setLowCutoff(channelSettingsJson["lowCutoff"].toInt());
    }
    if (channelSettingsJson.contains("pll")) {
        channelAnalyzerSettings->setPll(channelSettingsJson["pll"].toInt());
    }
    if (channelSettingsJson.contains("pllPskOrder")) {
        channelAnalyzerSettings->setPllPskOrder(channelSettingsJson["pllPskOrder"].toInt());
    }
    if (channelSettingsJson.contains("rgbColor")) {
        channelAnalyzerSettings->setRgbColor(channelSettingsJson["rgbColor"].toInt());
    }
    if (channelSettingsJson.contains("rrc")) {
        channelAnalyzerSettings->setRrc(channelSettingsJson["rrc"].toInt());
    }
    if (channelSettingsJson.contains("rrcRolloff")) {
        channelAnalyzerSettings->setRrcRolloff(channelSettingsJson["rrcRolloff"].toInt());
    }
    if (channelSettingsJson.contains("spanLog2")) {
        channelAnalyzerSettings->setSpanLog2(channelSettingsJson["spanLog2"].toInt());
    }
    if (channelSettingsJson.contains("ssb")) {
        channelAnalyzerSettings->setSsb(channelSettingsJson["ssb"].toInt());
    }
    if (channelSettingsJson.contains("title")) {
        channelAnalyzerSettings->setTitle(new QString(channelSettingsJson["title"].toString()));
    }

    if (channelSettingsJson.contains("spectrumConfig"))
    {
        SWGrpx-100::SWGGLSpectrum *spectrum = new SWGrpx-100::SWGGLSpectrum();
        spectrum->init();
        channelAnalyzerSettings->setSpectrumConfig(spectrum);
        QJsonObject spectrumJson;
        appendSettingsSubKeys(channelSettingsJson, spectrumJson, "spectrumConfig", channelSettingsKeys);
        spectrum->fromJsonObject(spectrumJson);
    }

    if (channelSettingsJson.contains("scopeConfig") && channelSettingsJson["scopeConfig"].isObject())
    {
        SWGrpx-100::SWGGLScope *scopeConfig = new SWGrpx-100::SWGGLScope();
        scopeConfig->init();
        channelAnalyzerSettings->setScopeConfig(scopeConfig);
        QJsonObject scopeConfigJson;
        appendSettingsSubKeys(channelSettingsJson, scopeConfigJson, "scopeConfig", channelSettingsKeys);
        scopeConfig->fromJsonObject(scopeConfigJson);

        if (scopeConfigJson.contains("tracesData") && scopeConfigJson["tracesData"].isArray())
        {
            QList<SWGrpx-100::SWGTraceData *> *tracesData = new QList<SWGrpx-100::SWGTraceData *>();
            scopeConfig->setTracesData(tracesData);
            QJsonArray tracesJson = scopeConfigJson["tracesData"].toArray();

            for (int i = 0; i < tracesJson.size(); i++)
            {
                SWGrpx-100::SWGTraceData *traceData = new SWGrpx-100::SWGTraceData();
                tracesData->append(traceData);
                QJsonObject traceJson = tracesJson.at(i).toObject();
                traceData->fromJsonObject(traceJson);
            }

            QStringList tracesDataKeys;
            appendSettingsArrayKeys(scopeConfigJson, "tracesData", tracesDataKeys);

            for (int i = 0; i < tracesDataKeys.size(); i++) {
                channelSettingsKeys.append(QString("scopeConfig.") + tracesDataKeys.at(i));
            }
        }

        if (scopeConfigJson.contains("triggersData") && scopeConfigJson["triggersData"].isArray())
        {
            QList<SWGrpx-100::SWGTriggerData *> *triggersData = new QList<SWGrpx-100::SWGTriggerData *>();
            scopeConfig->setTriggersData(triggersData);
            QJsonArray triggersJson = scopeConfigJson["triggersData"].toArray();

            for (int i = 0; i < triggersJson.size(); i++)
            {
                SWGrpx-100::SWGTriggerData *triggerData = new SWGrpx-100::SWGTriggerData();
                triggersData->append(triggerData);
                QJsonObject triggerJson = triggersJson.at(i).toObject();
                triggerData->fromJsonObject(triggerJson);
            }

            QStringList triggersDataKeys;
            appendSettingsArrayKeys(scopeConfigJson, "triggersData", triggersDataKeys);

            for (int i = 0; i < triggersDataKeys.size(); i++) {
                channelSettingsKeys.append(QString("scopeConfig.") + triggersDataKeys.at(i));
            }
        }
    }
}

void WebAPIRequestMapper::processSoapySDRSettings(
        SWGrpx-100::SWGDeviceSettings *deviceSettings,
        QJsonObject& deviceSettingsJson,
        QStringList& deviceSettingsKeys,
        bool inputElseOutput
)
{
    if (inputElseOutput)
    {
        SWGrpx-100::SWGSoapySDRInputSettings *swgSoapySDRInputSettings = new SWGrpx-100::SWGSoapySDRInputSettings();
        deviceSettings->setSoapySdrInputSettings(swgSoapySDRInputSettings);
        swgSoapySDRInputSettings->init();

        if (deviceSettingsJson.contains("centerFrequency")) {
            swgSoapySDRInputSettings->setCenterFrequency(deviceSettingsJson["centerFrequency"].toInt());
        }
        if (deviceSettingsJson.contains("LOppmTenths")) {
            swgSoapySDRInputSettings->setLOppmTenths(deviceSettingsJson["LOppmTenths"].toInt());
        }
        if (deviceSettingsJson.contains("devSampleRate")) {
            swgSoapySDRInputSettings->setDevSampleRate(deviceSettingsJson["devSampleRate"].toInt());
        }
        if (deviceSettingsJson.contains("log2Decim")) {
            swgSoapySDRInputSettings->setLog2Decim(deviceSettingsJson["log2Decim"].toInt());
        }
        if (deviceSettingsJson.contains("fcPos")) {
            swgSoapySDRInputSettings->setFcPos(deviceSettingsJson["fcPos"].toInt());
        }
        if (deviceSettingsJson.contains("softDCCorrection")) {
            swgSoapySDRInputSettings->setSoftDcCorrection(deviceSettingsJson["softDCCorrection"].toInt());
        }
        if (deviceSettingsJson.contains("softIQCorrection")) {
            swgSoapySDRInputSettings->setSoftIqCorrection(deviceSettingsJson["softIQCorrection"].toInt());
        }
        if (deviceSettingsJson.contains("transverterMode")) {
            swgSoapySDRInputSettings->setTransverterMode(deviceSettingsJson["transverterMode"].toInt());
        }
        if (deviceSettingsJson.contains("transverterDeltaFrequency")) {
            swgSoapySDRInputSettings->setTransverterDeltaFrequency(deviceSettingsJson["transverterDeltaFrequency"].toInt());
        }
        if (deviceSettingsJson.contains("antenna")) {
            swgSoapySDRInputSettings->setAntenna(new QString(deviceSettingsJson["antenna"].toString()));
        }
        if (deviceSettingsJson.contains("bandwidth")) {
            swgSoapySDRInputSettings->setBandwidth(deviceSettingsJson["bandwidth"].toInt());
        }
        if (deviceSettingsJson.contains("globalGain")) {
            swgSoapySDRInputSettings->setGlobalGain(deviceSettingsJson["globalGain"].toInt());
        }
        if (deviceSettingsJson.contains("autoGain")) {
            swgSoapySDRInputSettings->setAutoGain(deviceSettingsJson["autoGain"].toInt());
        }
        if (deviceSettingsJson.contains("autoDCCorrection")) {
            swgSoapySDRInputSettings->setAutoDcCorrection(deviceSettingsJson["autoDCCorrection"].toInt());
        }
        if (deviceSettingsJson.contains("autoIQCorrection")) {
            swgSoapySDRInputSettings->setAutoIqCorrection(deviceSettingsJson["autoIQCorrection"].toInt());
        }
        if (deviceSettingsJson.contains("dcCorrection"))
        {
            SWGrpx-100::SWGComplex *swgComplex = new SWGrpx-100::SWGComplex;
            swgSoapySDRInputSettings->setDcCorrection(swgComplex);
            QJsonObject complexJson = deviceSettingsJson["dcCorrection"].toObject();

            if (complexJson.contains("real")) {
                swgComplex->setReal(complexJson["real"].toDouble());
            }
            if (complexJson.contains("imag")) {
                swgComplex->setImag(complexJson["imag"].toDouble());
            }
        }
        if (deviceSettingsJson.contains("iqCorrection"))
        {
            SWGrpx-100::SWGComplex *swgComplex = new SWGrpx-100::SWGComplex;
            swgSoapySDRInputSettings->setIqCorrection(swgComplex);
            QJsonObject complexJson = deviceSettingsJson["iqCorrection"].toObject();

            if (complexJson.contains("real")) {
                swgComplex->setReal(complexJson["real"].toDouble());
            }
            if (complexJson.contains("imag")) {
                swgComplex->setImag(complexJson["imag"].toDouble());
            }
        }
        if (deviceSettingsJson.contains("useReverseAPI")) {
            swgSoapySDRInputSettings->setUseReverseApi(deviceSettingsJson["useReverseAPI"].toInt());
        }
        if (deviceSettingsJson.contains("reverseAPIAddress")) {
            swgSoapySDRInputSettings->setReverseApiAddress(new QString(deviceSettingsJson["reverseAPIAddress"].toString()));
        }
        if (deviceSettingsJson.contains("reverseAPIPort")) {
            swgSoapySDRInputSettings->setReverseApiPort(deviceSettingsJson["reverseAPIPort"].toInt());
        }
        if (deviceSettingsJson.contains("reverseAPIDeviceIndex")) {
            swgSoapySDRInputSettings->setReverseApiDeviceIndex(deviceSettingsJson["reverseAPIDeviceIndex"].toInt());
        }
    }
    else
    {
        SWGrpx-100::SWGSoapySDROutputSettings *swgSoapySDROutputSettings = new SWGrpx-100::SWGSoapySDROutputSettings();
        deviceSettings->setSoapySdrOutputSettings(swgSoapySDROutputSettings);
        swgSoapySDROutputSettings->init();

        if (deviceSettingsJson.contains("centerFrequency")) {
            swgSoapySDROutputSettings->setCenterFrequency(deviceSettingsJson["centerFrequency"].toInt());
        }
        if (deviceSettingsJson.contains("LOppmTenths")) {
            swgSoapySDROutputSettings->setLOppmTenths(deviceSettingsJson["LOppmTenths"].toInt());
        }
        if (deviceSettingsJson.contains("devSampleRate")) {
            swgSoapySDROutputSettings->setDevSampleRate(deviceSettingsJson["devSampleRate"].toInt());
        }
        if (deviceSettingsJson.contains("log2Interp")) {
            swgSoapySDROutputSettings->setLog2Interp(deviceSettingsJson["log2Interp"].toInt());
        }
        if (deviceSettingsJson.contains("transverterMode")) {
            swgSoapySDROutputSettings->setTransverterMode(deviceSettingsJson["transverterMode"].toInt());
        }
        if (deviceSettingsJson.contains("transverterDeltaFrequency")) {
            swgSoapySDROutputSettings->setTransverterDeltaFrequency(deviceSettingsJson["transverterDeltaFrequency"].toInt());
        }
        if (deviceSettingsJson.contains("antenna")) {
            swgSoapySDROutputSettings->setAntenna(new QString(deviceSettingsJson["antenna"].toString()));
        }
        if (deviceSettingsJson.contains("bandwidth")) {
            swgSoapySDROutputSettings->setBandwidth(deviceSettingsJson["bandwidth"].toInt());
        }
        if (deviceSettingsJson.contains("globalGain")) {
            swgSoapySDROutputSettings->setGlobalGain(deviceSettingsJson["globalGain"].toInt());
        }
        if (deviceSettingsJson.contains("autoGain")) {
            swgSoapySDROutputSettings->setAutoGain(deviceSettingsJson["autoGain"].toInt());
        }
        if (deviceSettingsJson.contains("autoDCCorrection")) {
            swgSoapySDROutputSettings->setAutoDcCorrection(deviceSettingsJson["autoDCCorrection"].toInt());
        }
        if (deviceSettingsJson.contains("autoIQCorrection")) {
            swgSoapySDROutputSettings->setAutoIqCorrection(deviceSettingsJson["autoIQCorrection"].toInt());
        }
        if (deviceSettingsJson.contains("dcCorrection"))
        {
            SWGrpx-100::SWGComplex *swgComplex = new SWGrpx-100::SWGComplex;
            swgSoapySDROutputSettings->setDcCorrection(swgComplex);
            QJsonObject complexJson = deviceSettingsJson["dcCorrection"].toObject();

            if (complexJson.contains("real")) {
                swgComplex->setReal(complexJson["real"].toDouble());
            }
            if (complexJson.contains("imag")) {
                swgComplex->setImag(complexJson["imag"].toDouble());
            }
        }
        if (deviceSettingsJson.contains("iqCorrection"))
        {
            SWGrpx-100::SWGComplex *swgComplex = new SWGrpx-100::SWGComplex;
            swgSoapySDROutputSettings->setIqCorrection(swgComplex);
            QJsonObject complexJson = deviceSettingsJson["iqCorrection"].toObject();

            if (complexJson.contains("real")) {
                swgComplex->setReal(complexJson["real"].toDouble());
            }
            if (complexJson.contains("imag")) {
                swgComplex->setImag(complexJson["imag"].toDouble());
            }
        }
        if (deviceSettingsJson.contains("useReverseAPI")) {
            swgSoapySDROutputSettings->setUseReverseApi(deviceSettingsJson["useReverseAPI"].toInt());
        }
        if (deviceSettingsJson.contains("reverseAPIAddress")) {
            swgSoapySDROutputSettings->setReverseApiAddress(new QString(deviceSettingsJson["reverseAPIAddress"].toString()));
        }
        if (deviceSettingsJson.contains("reverseAPIPort")) {
            swgSoapySDROutputSettings->setReverseApiPort(deviceSettingsJson["reverseAPIPort"].toInt());
        }
        if (deviceSettingsJson.contains("reverseAPIDeviceIndex")) {
            swgSoapySDROutputSettings->setReverseApiDeviceIndex(deviceSettingsJson["reverseAPIDeviceIndex"].toInt());
        }
    }

    if (deviceSettingsKeys.contains("deviceArgSettings"))
    {
        QList<SWGrpx-100::SWGArgValue *> *swgArgSettings = new QList<SWGrpx-100::SWGArgValue *>;
        QJsonArray argsJson = deviceSettingsJson["deviceArgSettings"].toArray();

        if (inputElseOutput) {
            deviceSettings->getSoapySdrInputSettings()->setDeviceArgSettings(swgArgSettings);
        } else {
            deviceSettings->getSoapySdrOutputSettings()->setDeviceArgSettings(swgArgSettings);
        }

        for (int i = 0; i < argsJson.count(); i++)
        {
            SWGrpx-100::SWGArgValue *argValue = new SWGrpx-100::SWGArgValue();
            swgArgSettings->append(argValue);
            QJsonObject argValueJson = argsJson.at(i).toObject();
            argValue->fromJsonObject(argValueJson);
        }

        appendSettingsArrayKeys(deviceSettingsJson, "deviceArgSettings", deviceSettingsKeys);
    }

    if (deviceSettingsKeys.contains("individualGains"))
    {
        QList<SWGrpx-100::SWGArgValue *> *swgIndividualGains = new QList<SWGrpx-100::SWGArgValue *>;
        QJsonArray argsJson = deviceSettingsJson["individualGains"].toArray();

        if (inputElseOutput) {
            deviceSettings->getSoapySdrInputSettings()->setIndividualGains(swgIndividualGains);
        } else {
            deviceSettings->getSoapySdrOutputSettings()->setIndividualGains(swgIndividualGains);
        }

        for (int i = 0; i < argsJson.count(); i++)
        {
            SWGrpx-100::SWGArgValue *argValue = new SWGrpx-100::SWGArgValue();
            swgIndividualGains->append(argValue);
            QJsonObject argValueJson = argsJson.at(i).toObject();
            argValue->fromJsonObject(argValueJson);
        }

        appendSettingsArrayKeys(deviceSettingsJson, "individualGains", deviceSettingsKeys);
    }

    if (deviceSettingsKeys.contains("streamArgSettings"))
    {
        QList<SWGrpx-100::SWGArgValue *> *swgStreamArgSettings = new QList<SWGrpx-100::SWGArgValue *>;
        QJsonArray argsJson = deviceSettingsJson["streamArgSettings"].toArray();

        if (inputElseOutput) {
            deviceSettings->getSoapySdrInputSettings()->setStreamArgSettings(swgStreamArgSettings);
        } else {
            deviceSettings->getSoapySdrOutputSettings()->setStreamArgSettings(swgStreamArgSettings);
        }

        for (int i = 0; i < argsJson.count(); i++)
        {
            SWGrpx-100::SWGArgValue *argValue = new SWGrpx-100::SWGArgValue();
            swgStreamArgSettings->append(argValue);
            QJsonObject argValueJson = argsJson.at(i).toObject();
            argValue->fromJsonObject(argValueJson);
        }

        appendSettingsArrayKeys(deviceSettingsJson, "streamArgSettings", deviceSettingsKeys);
    }

    if (deviceSettingsKeys.contains("tunableElements"))
    {
        QList<SWGrpx-100::SWGArgValue *> *swgTunableElements = new QList<SWGrpx-100::SWGArgValue *>;
        QJsonArray argsJson = deviceSettingsJson["tunableElements"].toArray();

        if (inputElseOutput) {
            deviceSettings->getSoapySdrInputSettings()->setTunableElements(swgTunableElements);
        } else {
            deviceSettings->getSoapySdrOutputSettings()->setTunableElements(swgTunableElements);
        }

        for (int i = 0; i < argsJson.count(); i++)
        {
            SWGrpx-100::SWGArgValue *argValue = new SWGrpx-100::SWGArgValue();
            swgTunableElements->append(argValue);
            QJsonObject argValueJson = argsJson.at(i).toObject();
            argValue->fromJsonObject(argValueJson);
        }

        appendSettingsArrayKeys(deviceSettingsJson, "tunableElements", deviceSettingsKeys);
    }
}
