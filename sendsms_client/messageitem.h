#ifndef MESSAGEITEM
#define MESSAGEITEM

#include <QString>
#include <QLabel>

class MessageItem : public QFrame
{
    Q_OBJECT

public:
    MessageItem(QString text, QString timestamp, bool type, QWidget *parent = 0);

private:
    QLabel *textLabel;
    QLabel *timestampLabel;
};

#endif // MESSAGEITEM

