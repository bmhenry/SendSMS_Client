#ifndef SERVER
#define SERVER

#include <QThread>
#include <QTextStream>
#include <QTcpServer>
#include <QTcpSocket>

#include "listener.h"



class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    ~Server();

    void startServer();
    void stopServer();
    void getData();
    void sendString(QString string);

    inline bool isActive() { return server->isListening(); }
    inline quint16 getPort() { return hostPort; }

private slots:
    void handleConnection();
    void readyRead();

signals:
    void gotInfo(QString);

private:
    bool should_run;
    QTcpServer *server;
    QTcpSocket *socket;
    quint16 hostPort;
    Listener *listener;
};

#endif // SERVER

