#ifndef CLIENT_H
#define CLIENT_H

#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QTcpSocket>

#include "sms.h"


class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QString ipAddress, quint16 hostPort, QObject *parent = 0);
    ~Client();

    bool reconnect();
    bool isConnected() { return socket->isOpen(); }
    bool send(QString string);
    void close();

    bool connected;

signals:
    void connectSuccess();
    void gotInfo(QString);

public slots:
    void getData();
    void connectionEstablished();

private:
    QString address;
    quint16 hostPort;
    QTcpSocket *socket;
};

#endif // CLIENT_H
