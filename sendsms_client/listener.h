#ifndef LISTENER
#define LISTENER


#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
#include <QThread>


class Listener : public QThread
{
    Q_OBJECT

public:
    QTcpSocket *socket;

    Listener(QTcpSocket *socket);
    void run();

signals:
    void gotInfo(QString);
};

#endif // LISTENER

