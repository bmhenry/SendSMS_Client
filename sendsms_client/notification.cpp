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



Notification::Notification(QList<QString> data, quint32 msecs, QWidget *parent) :
    QDialog(parent), isHovered(false)
{
    name = data.at(0);
    number = data.at(1);
    message = data.at(2);

    // Remove default frame and window buttons
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint |
                         Qt::Window | Qt::WindowDoesNotAcceptFocus);

    // cause deletion of object on close
    this->setAttribute(Qt::WA_DeleteOnClose);

    // Set window icon
    setWindowIcon(QIcon("./sms.ico"));

    // set size
    resize(300, 100);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // set background
    this->setStyleSheet(QString("Notification{background:#ffffff;border:1px solid #aaaaaa;}"));

    // move window to bottom right corner of screen
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = screenGeometry.width() - (this->width() + 10);
    int y = screenGeometry.height() - (this->height() + 40); // get above taskbar
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
    buttonLayout->addWidget(replyButton, 1, Qt::AlignLeft);
    buttonLayout->addWidget(closeButton, 1, Qt::AlignRight);

    mainLayout->addWidget(buttonWidget, 1);

    setLayout(mainLayout);

    qDebug() << "Notification should be visible.";
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fadeOut()));

    timer->start(msecs);
    anim = new QPropertyAnimation(this, "windowOpacity");
    anim->setDuration(2000);
    anim->setStartValue(1);
    anim->setEndValue(0);

    this->show();
}

Notification::~Notification() {

}

void Notification::enterEvent(QEvent *) {
    isHovered = true;

    try {
        anim->stop();
        this->setWindowOpacity(1);
    }
    catch (...) {}
}

void Notification::leaveEvent(QEvent *) {
    isHovered = false;

    if (!timer->isActive())
        timer->start(timer->interval()/2);
}

void Notification::fadeOut() {
    if (!isHovered) {
        // fade out animation
        anim->start();
        connect(anim, SIGNAL(finished()), this, SLOT(hide()));
    }
}

void Notification::hide() {
    delete(anim);
    this->close();
}

void Notification::replyClicked() {

}

void Notification::closeClicked() {
    this->close();
}
