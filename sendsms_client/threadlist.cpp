#include "threadlist.h"

#include <QLabel>
#include <QVBoxLayout>

#include "threaditem.h"


ThreadList::ThreadList(QWidget *parent)
    : QFrame(parent)
{
    list = new QListWidget(this);
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

    // connect slot
    connect(list, SIGNAL(currentRowChanged(int)), this, SIGNAL(selectionChanged(int)));
}

void ThreadList::addItem(QString filename, QString title, QString text)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);

    // create widget for item
    ThreadItem *widget = new ThreadItem(filename, title, text, this);

    item->setSizeHint(widget->minimumSizeHint());

    list->setItemWidget(item, widget);
}

QString ThreadList::getCurrentFilename()
{
    ThreadItem *item = (ThreadItem*)list->itemWidget(list->currentItem());
    return item->getFile();
}
