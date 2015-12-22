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
    list->setStyleSheet(QString("QListWidget{margin:0; border:1px solid black; background:#f7f7f7;}"));
    list->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);

    layout->addWidget(list);
}

void MessageList::addItem(QString text, QString timestamp, int type)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);

    MessageItem *widget = new MessageItem(text, timestamp, type, list);

    item->setSizeHint(widget->minimumSizeHint());

    list->setItemWidget(item, widget);

    list->scrollToBottom();
}

void MessageList::clear()
{
    list->clear();
}
