#include "threaditem.h"

ThreadItem::ThreadItem(QString title, QString text, QWidget *parent)
    : QFrame(parent)
{
    QVBoxLayout *l = new QVBoxLayout(this);

    QFont titleFont("Helvetica", 12);
    QFont textFont("Helvetica", 10);

    titleLabel = new QLabel(title, this, 0);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet(QString("color:white;"));
    titleLabel->setFixedWidth(170);

    textLabel= new QLabel(text, this, 0);
    textLabel->setFont(textFont);
    textLabel->setStyleSheet(QString("color:white;"));
    textLabel->setFixedWidth(170);

    l->addWidget(titleLabel);
    l->addWidget(textLabel);
}

void ThreadItem::setTitle(QString title)
{
    titleLabel->setText(title);
}

void ThreadItem::setText(QString text)
{
    textLabel->setText(text);
}
