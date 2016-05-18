#include "client.h"

#include <QDataStream>
#include <QException>



Client::Client(QString ipAddress, quint16 hostPort, QObject *parent)
    : QObject(parent)
{
    address = ipAddress;
    this->hostPort = hostPort;
    socket = new QTcpSocket();
    if (!reconnect())
        qDebug() << "Couldn't initialize connection on startup.";
}

Client::~Client() {
    close();
    delete socket;
}

bool Client::reconnect() {
    try {
        socket->connectToHost(QHostAddress(address), hostPort, QTcpSocket::ReadWrite);
        connect(socket, SIGNAL(readyRead()), this, SLOT(getData()));
        connect(socket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    } catch (...) {
        qDebug() << "Couldn't reconnect.";
        connected = false;
        return false;
    }
    return true;
}

void Client::connectionEstablished() {
    connected = true;
    qDebug() << "Successfully connected";
}

void Client::getData() {
    QString sep(QString(SMS::endchar) + "\n");

    // get info from socket
    QTextStream stream(socket);
    QString str = stream.readAll();
    if (str == "")
        return;
    qDebug() << "client got: " << str
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

bool Client::send(QString string) {
    if (socket != NULL && this->connected)
    {
        try {
            QDataStream stream(socket);
            stream.writeBytes(string.toStdString().c_str(), string.length());
            qDebug() << "Successful send";
            return true;
        } catch (QException e) {
            qDebug() << QString("Error sending data") + QString(e.what());
            connected = false;
            return false;
        }
    }
    else {
        qDebug() << "Socket not open.";
        return false;
    }
}

void Client::close() {
    connected = false;
    try {
        socket->close();
    } catch (...) {
        qDebug() << "Error closing socket";
    }
}
