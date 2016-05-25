#include "threaditem.h"

ThreadItem::ThreadItem(QString filename, QString name, QString number, QString text, QWidget *parent)
    : QFrame(parent), filename(filename), name(name), number(number)
{
    // create a layout
    QVBoxLayout *l = new QVBoxLayout(this);

    // font for people in message
    QFont titleFont("Helvetica", 12);
    // font for message preview
    QFont textFont("Helvetica", 10);

    titleLabel = new QLabel(name, this, 0);
    titleLabel->setFont(titleFont);
    //titleLabel->setStyleSheet(QString("color:white;"));
    titleLabel->setFixedWidth(170);

    textLabel= new QLabel(text, this, 0);
    textLabel->setFont(textFont);
    //textLabel->setStyleSheet(QString("color:white;"));
    textLabel->setFixedWidth(170);

    l->addWidget(titleLabel);
    l->addWidget(textLabel);
}
