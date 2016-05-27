#include "messagetextcontainer.h"

#include <QVBoxLayout>
#include <QDebug>


MessageTextContainer::MessageTextContainer(QString text, QString timestamp, QWidget* parent)
    : QFrame(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(padding, padding, padding, padding);

    textDisplay = new TextDisplay(text);
    textDisplay->setParent(this);
    connect(textDisplay, SIGNAL(repainted(QSize)), this, SLOT(catchRepainted(QSize)));
    layout->addWidget(textDisplay);

    timeLabel = new QLabel(timestamp, this);
    layout->addWidget(timeLabel, 0, Qt::AlignRight);

    resize(sizeHint());
    qDebug() << "MTC Post: " << this->size();
}

void MessageTextContainer::catchRepainted(QSize size) {
    this->resize(sizeHint());
    qDebug() << "MTC Catch: " << sizeHint();
    emit resized(size);
}

void MessageTextContainer::resizeEvent(QResizeEvent *) {
//    QSize req = sizeHint();
//    this->resize(req);
//    this->setMinimumHeight(req.height());
//    qDebug() << "MTC Resize: " << this->size();
}

QSize MessageTextContainer::sizeHint() const {
    QSize size;
    size.setHeight(padding +
                   textDisplay->sizeHint().height() +
                   padding +
                   timeLabel->sizeHint().height() +
                   padding);
    size.setWidth(padding + textDisplay->width() + padding);
    return size;
}
