#include "threaditem.h"

ThreadItem::ThreadItem(QString title, QString text, bool colorToggle, QWidget *parent)
    : QFrame(parent)
{
    if (colorToggle)
        this->setStyleSheet(QString(".ThreadItem{background:#aaaaaa;border:1px solid #888888;}"));
    else
        this->setStyleSheet(QString(".ThreadItem{background:#9fb9f9;border:1px solid #888888;}"));

    QVBoxLayout *l = new QVBoxLayout(this);
    titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(QString("color:white;"));
    textLabel= new QLabel(text);
    textLabel->setStyleSheet(QString("color:white;"));

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
