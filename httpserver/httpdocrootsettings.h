/*
 * httpdocrootsettings.h
 *
 *  Created on: Nov 13, 2017
 *      Author: oe3bia
 */

#ifndef HTTPSERVER_HTTPDOCROOTSETTINGS_H_
#define HTTPSERVER_HTTPDOCROOTSETTINGS_H_

#include <QString>

namespace qtwebapp {

class HttpDocrootSettings
{
public:
    QString path;
    QString encoding;
    int maxAge;
    int cacheTime;
    int cacheSize;
    int maxCachedFileSize;

    HttpDocrootSettings() {
        resetToDefaults();
    }

    void resetToDefaults()
    {
        path = "/opt/install/RPX-100-SDR";
        encoding = "UTF-8";
        maxAge = 60000;
        cacheTime = 60000;
        cacheSize = 1000000;
        maxCachedFileSize = 65536;
    }
};

} // end of namespace

#endif /* HTTPSERVER_HTTPDOCROOTSETTINGS_H_ */
