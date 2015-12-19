#include "server.h"

#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>


Server::Server(QObject *parent)
    : QObject(parent), hostPort(5000)
{
    server = new QTcpServer();

    connect(server, SIGNAL(newConnection()), this, SLOT(handleConnection()));
}

void Server::start() {
    server->listen(QHostAddress::AnyIPv4, hostPort);
}

void Server::handleConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    socket->waitForReadyRead();

    // get info from socket
    QTextStream stream(socket);
    QString str = stream.readAll();
    qDebug() << "server got: " << str << "; from: " << socket->peerAddress().toString();

    socket->close();

    emit gotInfo(str);
}

void Server::stop() {
    server->close();
}
