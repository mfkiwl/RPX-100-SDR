/**
  @file
  @author Stefan Frings
*/

#ifndef HTTPCONNECTIONHANDLER_H
#define HTTPCONNECTIONHANDLER_H

#ifndef QT_NO_OPENSSL
   #include <QSslConfiguration>
#endif
#include <QTcpSocket>
#include <QSettings>
#include <QTimer>
#include <QThread>
#include "httpglobal.h"
#include "httprequest.h"
#include "httprequesthandler.h"
#include "httplistenersettings.h"

#include "export.h"

namespace qtwebapp {

/** Alias type definition, for compatibility to different Qt versions */
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    typedef qintptr tSocketDescriptor;
#else
    typedef int tSocketDescriptor;
#endif

/** Alias for QSslConfiguration if OpenSSL is not supported */
#ifdef QT_NO_OPENSSL
  #define QSslConfiguration QObject
#endif

/**
  The connection handler accepts incoming connections and dispatches incoming requests to to a
  request mapper. Since HTTP clients can send multiple requests before waiting for the response,
  the incoming requests are queued and processed one after the other.
  <p>
  Example for the required configuration settings:
  <code><pre>
  readTimeout=60000
  maxRequestSize=16000
  maxMultiPartSize=1000000
  </pre></code>
  <p>
  The readTimeout value defines the maximum time to wait for a complete HTTP request.
  @see HttpRequest for description of config settings maxRequestSize and maxMultiPartSize.
*/
class HTTPSERVER_API HttpConnectionHandler : public QThread {
    Q_OBJECT
    Q_DISABLE_COPY(HttpConnectionHandler)

public:

    /**
      Constructor.
      @param settings Configuration settings of the HTTP webserver as Qt settings
      @param requestHandler Handler that will process each incoming HTTP request
      @param sslConfiguration SSL (HTTPS) will be used if not NULL
    */
    HttpConnectionHandler(QSettings* settings, HttpRequestHandler* requestHandler, QSslConfiguration* sslConfiguration=NULL);

    /**
      Constructor.
      @param settings Configuration settings of the HTTP webserver as a structure
      @param requestHandler Handler that will process each incoming HTTP request
      @param sslConfiguration SSL (HTTPS) will be used if not NULL
    */
    HttpConnectionHandler(const HttpListenerSettings* settings, HttpRequestHandler* requestHandler, QSslConfiguration* sslConfiguration=NULL);

    /** Destructor */
    virtual ~HttpConnectionHandler();

    /** Returns true, if this handler is in use. */
    bool isBusy();

    /** Mark this handler as busy */
    void setBusy();

    /**
     * Get a listener settings constant reference. Can be changed on the HttpListener only.
     * @return The current listener settings
     */
    const HttpListenerSettings *getListenerSettings() const { return listenerSettings; }


private:

    /** Configuration settings */
    QSettings* settings;

    /** Configuration settings */
    const HttpListenerSettings* listenerSettings;

    /** TCP socket of the current connection  */
    QTcpSocket* socket;

    /** Time for read timeout detection */
    QTimer readTimer;

    /** Storage for the current incoming HTTP request */
    HttpRequest* currentRequest;

    /** Dispatches received requests to services */
    HttpRequestHandler* requestHandler;

    /** This shows the busy-state from a very early time */
    bool busy;

    /** Configuration for SSL */
    QSslConfiguration* sslConfiguration;

    /** Executes the threads own event loop */
    void run();

    /**  Create SSL or TCP socket */
    void createSocket();

    /** Settings flag */
    bool useQtSettings;

public slots:

    /**
      Received from from the listener, when the handler shall start processing a new connection.
      @param socketDescriptor references the accepted connection.
    */
    void handleConnection(tSocketDescriptor socketDescriptor);

private slots:

    /** Received from the socket when a read-timeout occurred */
    void readTimeout();

    /** Received from the socket when incoming data can be read */
    void read();

    /** Received from the socket when a connection has been closed */
    void disconnected();

};

} // end of namespace

#endif // HTTPCONNECTIONHANDLER_H
