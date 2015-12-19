#ifndef MESSAGELIST
#define MESSAGELIST

#include <QListWidget>
#include <QLabel>
#include <QString>

#include "fileio.h"


class MessageList : public QFrame
{
    Q_OBJECT

public:
    MessageList(QWidget *parent = 0);

    // type 0 = received message, type 1 = sent message
    void addItem(QString text, QString timestamp, int type);
    void clear();

private:
    QListWidget *list;
};


#endif // MESSAGELIST

