#ifndef MESSAGEITEM
#define MESSAGEITEM

#include <QString>
#include <QLabel>
#include <QSpacerItem>
#include <QListWidgetItem>

#include "sms.h"
#include "textdisplay.h"
#include "messagetextcontainer.h"


class MessageItem : public QFrame
{
    Q_OBJECT

public:
    MessageItem(QString text, QString timestamp, SMS::SMS_Type type,
                QListWidgetItem *item, QWidget *parent = 0);
//    ~MessageItem();
    QSize sizeHint() const;

private slots:
    void catchResized(QSize);

protected:
    virtual void resizeEvent(QResizeEvent *e);

private:
    const static int padding = 10;
    const static int margin = 10;
    QListWidgetItem *item;
    TextDisplay *textDisplay;
    MessageTextContainer *messageContainer;
    QLabel *timestampLabel;
};

#endif // MESSAGEITEM

