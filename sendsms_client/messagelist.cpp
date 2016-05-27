#include "messagelist.h"

#include <QVBoxLayout>
#include <QDateTime>
#include <QDebug>

#include "messageitem.h"


MessageList::MessageList(QWidget *parent)
    : QFrame(parent)
{
    // create layout to display list within this widget
    QVBoxLayout *layout = new QVBoxLayout(this);

    // create list
    list = new QListWidget(this);
    list->setMinimumWidth(200);
    list->setStyleSheet(QString("QListWidget{margin:0; border:1px solid black; background:#f7f7f7;}"));
    list->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    layout->addWidget(list);
}

void MessageList::addItem(QString text, QString timestamp, SMS::SMS_Type type)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);
    MessageItem *widget = new MessageItem(text, timestamp, type, item, list);
    item->setSizeHint(widget->sizeHint());
    list->setItemWidget(item, widget);

    list->repaint();
    list->scrollToBottom();
}

void MessageList::clear()
{
    list->clear();
}
