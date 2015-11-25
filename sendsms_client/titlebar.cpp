#include "titlebar.h"

#include <QDebug>



TitleBar::TitleBar(QWidget *parent, MainWindow *m)
    : QWidget(parent), moving(false)
{
    mainWindow = m;

    // enable mouse tracking
    this->setMouseTracking(true);

    // set stylesheet
    this->setStyleSheet(QString("background-color:white;"));

    // create layout
    layout = new QHBoxLayout(this);

    // create exit button
    exitButton = new QPushButton("Exit", this);
    exitButton->setMaximumSize(exitButton->sizeHint());

    layout->addWidget(exitButton, 0, Qt::AlignRight);

    // create minimize button
//    minimizeButton = new QPushButton("Minimize", this);
//    minimizeButton->setMaximumSize(minimizeButton->sizeHint());

//    layout->addWidget(minimizeButton, 0, Qt::AlignRight);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
//    if (event->button() == Qt::LeftButton)
//    {
//        lastMousePos = event->pos();
//        moving = true;
//        qDebug() << event->pos();
//    }
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
//    if ((event->button() & Qt::LeftButton) && moving) {
//        QPoint newpos = this->pos() + (event->pos() - lastMousePos);
//        mainWindow->move(newpos);
//        qDebug() << "Should move to " << newpos;
//    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
//    if (event->button() == Qt::LeftButton)
//        moving = false;
}
