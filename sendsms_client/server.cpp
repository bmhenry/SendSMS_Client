#include "server.h"

#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QDataStream>
#include <QException>
#include <QDebug>


Server::Server(QObject *parent)
    : QObject(parent), hostPort(5000), socket(NULL)
{
    server = new QTcpServer();

    connect(server, SIGNAL(newConnection()), this, SLOT(handleConnection()));
}

void Server::start() {
    server->listen(QHostAddress::AnyIPv4, hostPort);
}

void Server::handleConnection()
{
    socket = server->nextPendingConnection();
    socket->waitForReadyRead();

    // get info from socket
    QTextStream stream(socket);
    QString str = stream.readAll();
    qDebug() << "server got: " << str << "; from: " << socket->peerAddress().toString();

    emit gotInfo(str);
}

void Server::sendString(QString string)
{
    if (socket != NULL && socket->isOpen())
    {
        try {
            QDataStream stream(socket);
            stream.writeBytes(string.toStdString().c_str(), string.length());
        } catch (QException e) {
            qDebug() << QString("Error sending data") + QString(e.what());
        }
    }
    else
        qDebug() << "Socket not open.";
}

void Server::stop() {
    if (socket != NULL && socket->isOpen())
        socket->close();

    if (server->isListening())
        server->close();
}
