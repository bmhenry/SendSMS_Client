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

    // create blank expanding widgt
    QWidget *expand = new QWidget;
    expand->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    expand->setStyleSheet("background:transparent;");
    layout->addWidget(expand);

    // create minimize button
    minimizeButton = new QPushButton("Minimize", this);
    minimizeButton->setMaximumSize(minimizeButton->sizeHint());

    layout->addWidget(minimizeButton);

    // create exit button
    exitButton = new QPushButton("Exit", this);
    exitButton->setMaximumSize(exitButton->sizeHint());

    layout->addWidget(exitButton);

}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastMousePos = event->pos();
        moving = true;
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (moving)
    {
        QPoint newpos = this->pos() + (event->pos() - lastMousePos);
        if (newpos != curPos)
        {
            posChange = event->pos() - lastMousePos;
            curPos = newpos;
            emit moveSignal(newpos);
        }
    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        moving = false;
}
