#include "notification.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QIcon>
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


Notification::Notification(QList<QString> data, quint32 timerInterval, QWidget *parent) :
    QDialog(parent), timerInterval(timerInterval)
{
    name = data.at(0);
    number = data.at(1);
    message = data.at(2);

    // Remove default frame and window buttons
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint |
                         Qt::Window | Qt::WindowDoesNotAcceptFocus);

    // Set window icon
    setWindowIcon(QIcon("./sms.ico"));

    // set size
    resize(300, 100);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // move window to bottom right corner of screen
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = screenGeometry.width() - this->width();
    int y = screenGeometry.height() - (this->height() + 100); // get above taskbar
    this->move(x, y);

    // create central widget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(10);

    QLabel *numberLabel = new QLabel(this);
    numberLabel->setText(number);
    mainLayout->addWidget(numberLabel, 0, Qt::AlignLeft);

    QLabel *messageLabel = new QLabel(this);
    messageLabel->setText(message);
    mainLayout->addWidget(messageLabel, 0, Qt::AlignHCenter);

    QWidget *buttonWidget = new QWidget(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton *closeButton = new QPushButton("Close", this);
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeClicked()));
    QPushButton *replyButton = new QPushButton("Reply", this);
    connect(replyButton, SIGNAL(clicked(bool)), this, SLOT(replyClicked()));
    buttonLayout->addWidget(closeButton, 0, Qt::AlignRight);
    buttonLayout->addWidget(replyButton, 0, Qt::AlignLeft);

    mainLayout->addWidget(buttonWidget, 1);

    setLayout(mainLayout);

    qDebug() << "Notification should be visible.";
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(hide()));

    timer->start(timerInterval);
}

Notification::~Notification() {
    delete timer;
}

void Notification::hide() {
    this->destroy();
}

void Notification::replyClicked() {

}

void Notification::closeClicked() {
    this->close();
}
