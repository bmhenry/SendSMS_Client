#ifndef MESSAGELIST
#define MESSAGELIST

#include <QListWidget>
#include <QLabel>
#include <QString>


class MessageList : public QFrame
{
    Q_OBJECT

public:
    MessageList(QWidget *parent = 0);

    const static bool SENT = 1;
    const static bool RECEIVED = 0;

    // type 0 = received message, type 1 = sent message
    void addItem(QString text, QString timestamp, bool type);

private:
    QListWidget *list;
};


#endif // MESSAGELIST

