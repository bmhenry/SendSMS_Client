#include "messageitem.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "messagelist.h"

MessageItem::MessageItem(QString text, QString timestamp, SMS::SMS_Type type, QWidget *parent)
    : QFrame(parent)
{

    // create widget layout
    QHBoxLayout *layout = new QHBoxLayout(this);

    // create inner widget (allows aligning the message inside if it's a sent/recieved message)
    QFrame *innerWidget = new QFrame(this);
    innerWidget->setMinimumWidth(200);
    innerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // create expanding widget to fill empty space (fills 2/3 of the space)
    QWidget *expander = new QWidget(this);

    if (type == SMS::RECEIVED)
    {
        innerWidget->setStyleSheet(QString("MessageItem > QFrame{background:#FFCC80; border-radius:5px;}"));
        layout->addWidget(innerWidget, 2);
        layout->addWidget(expander, 3);
    }
    else if (type == SMS::SENT)
    {
        innerWidget->setStyleSheet(QString("MessageItem > QFrame{background:#FFA726;border:1px solid white; border-radius:5px;}"));
        layout->addWidget(expander, 3);
        layout->addWidget(innerWidget, 2);
    }

    QVBoxLayout *l = new QVBoxLayout(innerWidget);
    l->setSpacing(5);

    textLabel = new QLabel(text);
    //textLabel->setStyleSheet(QString("color:white;"));
    textLabel->setWordWrap(true);
    textLabel->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    timestampLabel= new QLabel(timestamp);
    //timestampLabel->setStyleSheet(QString("color:white;"));
    timestampLabel->setWordWrap(true);

    l->addWidget(textLabel);
    l->addWidget(timestampLabel, 0, Qt::AlignRight);
}
