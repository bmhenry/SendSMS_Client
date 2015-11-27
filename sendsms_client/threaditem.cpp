#include "threaditem.h"

ThreadItem::ThreadItem(QString title, QString text, QWidget *parent)
    : QFrame(parent)
{
    QVBoxLayout *l = new QVBoxLayout(this);

    titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(QString("color:white;"));
    titleLabel->setFixedWidth(170);

    textLabel= new QLabel(text);
    textLabel->setStyleSheet(QString("color:white;"));
    textLabel->setFixedWidth(170);

    l->addWidget(titleLabel);
    l->addWidget(textLabel);
}

void ThreadItem::setTitle(QString title)
{
    titleLabel = new QLabel(title);
}

void ThreadItem::setText(QString text)
{
    textLabel = new QLabel(text);
}
