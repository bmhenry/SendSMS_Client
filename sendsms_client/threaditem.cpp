#include "threaditem.h"

ThreadItem::ThreadItem(QString filename, QString title, QString text, QWidget *parent)
    : QFrame(parent)
{
    // set the sms file
    this->filename = QString(filename);

    // create a layout
    QVBoxLayout *l = new QVBoxLayout(this);

    // font for people in message
    QFont titleFont("Helvetica", 12);
    // font for message preview
    QFont textFont("Helvetica", 10);

    titleLabel = new QLabel(title, this, 0);
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

void ThreadItem::setTitle(QString title)
{
    titleLabel->setText(title);
}

QString ThreadItem::getTitle()
{
    return titleLabel->text();
}

void ThreadItem::setText(QString text)
{
    textLabel->setText(text);
}

void ThreadItem::setFile(QString filename)
{
    this->filename = filename;
}

QString ThreadItem::getFile()
{
    return filename;
}
