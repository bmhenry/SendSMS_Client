#include "threadlist.h"

#include <QLabel>
#include <QVBoxLayout>

#include "threaditem.h"


ThreadList::ThreadList(QWidget *parent)
    : QFrame(parent)
{
    list = new QListWidget();
    list->setMinimumWidth(200);
    list->setStyleSheet(QString(
                            "QListWidget{border:1px solid black; background:#aaaaaa;}"
                            "QListWidget::item{background:#515151;}"
                            "QListWidget::item:selected{background:#c94c4c;}"
                            "QListWidget::item:focus{border:0px;}"));

    // create layout to display list within this widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(list);
    layout->setSpacing(0);
}

void ThreadList::addItem(QString title, QString text)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);

    // create widget for item
    ThreadItem *widget = new ThreadItem(title, text);

    item->setSizeHint(widget->minimumSizeHint());

    list->setItemWidget(item, widget);
}
