#ifndef SERVER
#define SERVER

#include <QTcpServer>


class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);

    void start();
    void stop();
    inline bool isActive() { return server->isListening(); }
    inline quint16 getPort() { return hostPort; }

private slots:
    void handleConnection();

signals:
    void gotInfo(QString);

private:
    QTcpServer *server;
    const quint16 hostPort;
};

#endif // SERVER

