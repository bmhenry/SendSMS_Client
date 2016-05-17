#include "listener.h"


Listener::Listener(QTcpSocket *socket)
    : QThread()
{
    this->socket = socket;
}

void Listener::run() {
    qDebug() << "Listener started.";
    if (socket != NULL && socket->isOpen())
    {
        QTextStream stream(socket);
        QString str = stream.readAll();
        emit gotInfo(str);
    }
    else {
        qDebug() << "Socket was not open when checked.";
        emit gotInfo(NULL);
    }
}

