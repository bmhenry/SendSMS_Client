#include "threadlist.h"

#include <QLabel>
#include <QVBoxLayout>

#include <QList>

#include "threaditem.h"
#include "fileio.h"


ThreadList::ThreadList(QWidget *parent)
    : QFrame(parent)
{
    list = new QListWidget(this);
    list->setMinimumWidth(200);

    this->setStyleSheet(QString(
                            "QListWidget{border:1px solid black; background:#fefefe; show-decoration-selected:0;}"
                            "QListWidget::item{background:#FFF176; color:black;}"
                            "QListWidget::item:alternate{background:#FFD54F;}"
                            "QListWidget::item:selected{ background:#F9A825; color:white;}"
                            "QListWidget::item:focus{border:0px;}"));
    list->setAlternatingRowColors(true);

    // create layout to display list within this widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(list);
    layout->setSpacing(0);

    // connect slot
    connect(list, SIGNAL(currentRowChanged(int)), this, SIGNAL(selectionChanged(int)));
}

void ThreadList::setSelection(int index)
{
    list->setCurrentRow(index);
}

void ThreadList::addItem(QString filename, QString title, QString text)
{
    // create item to add to list
    QListWidgetItem *item = new QListWidgetItem(list);

    // create widget for item
    ThreadItem *widget = new ThreadItem(filename, title, text, this);
    item->setSizeHint(widget->minimumSizeHint());
    list->setItemWidget(item, widget);

    // add filename to list
    sms_filename_list.append(filename);
    itemList.append(widget);
}

void ThreadList::addConversation(QString filename)
{
    // open the file and get the first sms for list
    QList<SMS> sms_list = sms_parse(filename);

    QString people, last_message;
    if (sms_list.length() >= 2)
    {
        people = sms_list.at(0).people;
        last_message = sms_list.at(sms_list.length() - 1).message;
        this->addItem(filename, people, last_message);
    }
}

bool ThreadList::contains(QString filename)
{
    return sms_filename_list.contains(filename);
}

void ThreadList::setTextAt(QString filename, QString text)
{
    int index = sms_filename_list.indexOf(filename);
    if (index >= 0)
    {
        ThreadItem *item = itemList.at(index);
        item->setText(text);
    }
}

QString ThreadList::getCurrentFilename()
{
    ThreadItem *item = (ThreadItem*)list->itemWidget(list->currentItem());
    return item->getFile();
}

QString ThreadList::getCurrentNumber()
{
    ThreadItem *item = (ThreadItem*)list->itemWidget(list->currentItem());
    return item->getTitle();
}
