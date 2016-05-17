#include "server.h"

#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QDataStream>
#include <QException>
#include <QDebug>
#include <QStringList>
#include "sms.h"


Server::Server(QObject *parent)
    : QObject(parent), hostPort(5000), socket(NULL)
{
    server = new QTcpServer();
    socket = new QTcpSocket();
    connect(server, SIGNAL(newConnection()), this, SLOT(handleConnection()));

    listener = new Listener(socket);
    connect(listener, SIGNAL(gotInfo(QString)), this, SIGNAL(gotInfo(QString)));
    connect(listener, SIGNAL(finished()), listener,SLOT(deleteLater()));
}

Server::~Server() {
    delete(listener);
}

void Server::startServer()
{
    server->listen(QHostAddress::AnyIPv4, hostPort);
}

void Server::handleConnection()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Server::readyRead() {
    getData();
}

void Server::getData()
{
    QString sep(QString(SMS::endchar) + "\n");

    // get info from socket
    QTextStream stream(socket);
    QString str = stream.readAll();
    qDebug() << "server got: " << str
             << "; from: " << socket->peerAddress().toString();
    QStringList strings = str.split(sep, QString::SkipEmptyParts);

    for (int i = 0; i < strings.length(); i++)
        strings[i].append(sep);

    qDebug() << strings;

    for (int i = 0; i < strings.length(); i++) {
        //strings[i].append(sep);
        qDebug() << strings[i];
        emit gotInfo(strings[i]);
    }
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

void Server::stopServer() {
    should_run = false;
    socket->close();
    server->close();
}

