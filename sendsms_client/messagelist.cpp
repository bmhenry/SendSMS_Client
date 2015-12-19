#include "messagelist.h"

#include <QVBoxLayout>
#include <QDateTime>

#include "messageitem.h"


MessageList::MessageList(QWidget *parent)
    : QFrame(parent)
{
    // create layout to display list within this widget
    QVBoxLayout *layout = new QVBoxLayout(this);

    // create list
    list = new QListWidget(this);
    list->setMinimumWidth(200);
    list->setStyleSheet(QString("QListWidget{border:1px solid black; background:#aaaaaa;}"));
    list->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);

    layout->addWidget(list);
}

void MessageList::addItem(QString text, QString timestamp, int type)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);

    //QDateTime time = QDateTime::fromMSecsSinceEpoch(timestamp.toInt());
    //QString stamp = time.toString(QString("h:mm A, MMM dd"));

    // create widget for item
    // if it doesn't have a timestamp, don't try to give it one
    // timestamp.trimmed() == "" ? "" : stamp
    MessageItem *widget = new MessageItem(text, timestamp, type, list);

    item->setSizeHint(widget->minimumSizeHint());

    list->setItemWidget(item, widget);

    list->scrollToBottom();
}

void MessageList::clear()
{
    list->clear();
}
