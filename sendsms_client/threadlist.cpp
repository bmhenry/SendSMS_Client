#include "threadlist.h"

#include <QLabel>
#include <QVBoxLayout>

#include "threaditem.h"


ThreadList::ThreadList()
{
    list = new QListWidget();
    colorToggle = false;

    // create layout to display list within this widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(list);
}

void ThreadList::addItem(QString title, QString text)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);

    // create widget for item
    ThreadItem *widget = new ThreadItem(title, text, colorToggle);
    colorToggle = !colorToggle;

    item->setSizeHint(widget->minimumSizeHint());

    list->setItemWidget(item, widget);
}
