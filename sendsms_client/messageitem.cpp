#include "messageitem.h"

#include <QHBoxLayout>
#include <QPointer>
#include <QDebug>

#include "messagelist.h"

MessageItem::MessageItem(QString text, QString timestamp, SMS::SMS_Type type,
                         QListWidgetItem *item, QWidget *parent)
    : QFrame(parent), messageContainer(NULL), item(item)
{
    qDebug() << "MI: " << this->size();

    // create widget layout
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(padding, padding, padding, padding);

//    this->setMinimumWidth(450);

    // create inner widget (allows aligning the message inside if it's a sent/recieved message)
    messageContainer = new MessageTextContainer(text, timestamp, this);
    messageContainer->setMinimumWidth(200);
    messageContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    connect(messageContainer, SIGNAL(resized(QSize)), this, SLOT(catchResized(QSize)));


    // create expanding widget to fill empty space (fills 2/3 of the space)
    QWidget *expander = new QWidget(this);

    if (type == SMS::RECEIVED)
    {
        messageContainer->setStyleSheet(QString("MessageTextContainer{background:#FFCC80; border-radius:5px;}"));
        layout->addWidget(messageContainer, 1);
        layout->addWidget(expander, 2);
    }
    else if (type == SMS::SENT)
    {
        messageContainer->setStyleSheet(QString("MessageTextContainer{background:#FFA726; border-radius:5px;}"));
        layout->addWidget(expander, 2);
        layout->addWidget(messageContainer, 1);
    }

    resize(sizeHint());
    item->setSizeHint(sizeHint());
    qDebug() << "MI Post: " << sizeHint() << item->sizeHint();
}

void MessageItem::catchResized(QSize) {
    this->resize(sizeHint());
    item->setSizeHint(sizeHint());
}

void MessageItem::resizeEvent(QResizeEvent *) {
//    qDebug() << "MI Resize: " << this->size();
}

QSize MessageItem::sizeHint() const {
    QSize size;
    size.setHeight(messageContainer->sizeHint().height() + 2*padding);
    size.setWidth(this->width());
    return size;
}
