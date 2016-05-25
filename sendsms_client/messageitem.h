#ifndef MESSAGEITEM
#define MESSAGEITEM

#include <QString>
#include <QLabel>

#include "sms.h"

class MessageItem : public QFrame
{
    Q_OBJECT

public:
    MessageItem(QString text, QString timestamp, SMS::SMS_Type type, QWidget *parent = 0);

private:
    QLabel *textLabel;
    QLabel *timestampLabel;
};

#endif // MESSAGEITEM

