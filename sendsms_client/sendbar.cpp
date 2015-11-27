#include "sendbar.h"

#include <QHBoxLayout>


SendBar::SendBar(QWidget *parent)
    : QFrame(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(2);

    // box for new message text
    textEdit = new QLineEdit(this);
    textEdit->adjustSize();
    textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    textEdit->setStyleSheet(QString("QLineEdit{border:1px solid black;}"));

    layout->addWidget(textEdit);

    // send button
    sendButton = new QPushButton("Send", this);

    layout->addWidget(sendButton);
}
