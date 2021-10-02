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

#include <QCoreApplication>
#include <QSysInfo>

#include <signal.h>
#include <vector>

#include "loggerwithfile.h"
#include "mainparser.h"
#include "mainserver.h"
#include "dsp/dsptypes.h"

void handler(int sig) {
    fprintf(stderr, "quit the application by signal(%d).\n", sig);
    QCoreApplication::quit();
}

#ifndef _WIN32
void catchUnixSignals(const std::vector<int>& quitSignals) {
    sigset_t blocking_mask;
    sigemptyset(&blocking_mask);

    for (std::vector<int>::const_iterator it = quitSignals.begin(); it != quitSignals.end(); ++it) {
        sigaddset(&blocking_mask, *it);
    }

    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_mask    = blocking_mask;
    sa.sa_flags   = 0;

    for (std::vector<int>::const_iterator it = quitSignals.begin(); it != quitSignals.end(); ++it) {
        sigaction(*it, &sa, 0);
    }
}
#endif

static int runQtApplication(int argc, char* argv[], qtwebapp::LoggerWithFile *logger)
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("oe3bia");
    QCoreApplication::setApplicationName("RPX100");
    QCoreApplication::setApplicationVersion(RPX100_VERSION);

#ifndef _WIN32
    int catchSignals[] = {SIGQUIT, SIGINT, SIGTERM, SIGHUP};
    std::vector<int> vsig(catchSignals, catchSignals + sizeof(catchSignals) / sizeof(int));
    catchUnixSignals(vsig);
#endif

    MainParser parser;
    parser.parse(a);

#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
    qInfo("%s %s Qt %s %db %s %s DSP Rx:%db Tx:%db PID %lld",
          qPrintable(QCoreApplication::applicationName()),
          qPrintable(QCoreApplication::applicationVersion()),
          qPrintable(QString(QT_VERSION_STR)),
          QT_POINTER_SIZE*8,
          qPrintable(QSysInfo::currentCpuArchitecture()),
          qPrintable(QSysInfo::prettyProductName()),
          SDR_RX_SAMP_SZ,
          SDR_TX_SAMP_SZ,
          QCoreApplication::applicationPid());
#else
    qInfo("%s %s Qt %s %db DSP Rx:%db Tx:%db PID %lld",
          qPrintable(QCoreApplication::applicationName()),
          qPrintable((QCoreApplication::>applicationVersion()),
                     qPrintable(QString(QT_VERSION_STR)),
                     QT_POINTER_SIZE*8,
                     SDR_RX_SAMP_SZ,
                     SDR_TX_SAMP_SZ,
                     QCoreApplication::applicationPid());
#endif

          MainServer m(logger, parser, &a);

          // This will cause the application to exit when the main core is finished
          QObject::connect(&m, SIGNAL(finished()), &a, SLOT(quit()));

          return a.exec();
          }

      int main(int argc, char* argv[])
      {
        qtwebapp::LoggerWithFile *logger = new qtwebapp::LoggerWithFile(qApp);
        logger->installMsgHandler();
        int res = runQtApplication(argc, argv, logger);
        delete logger;
        qWarning("RPX100 quit.");
        return res;
      }
