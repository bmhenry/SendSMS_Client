#include "textdisplay.h"
#include <QPainter>
#include <QDebug>
#include <QFontMetrics>
#include <QResizeEvent>


TextDisplay::TextDisplay(QString text, QString fontFamily, int fontSize,
                         int fontColor, QWidget* parent)
    : QWidget(parent), text(text), fontFamily(fontFamily),
      fontSize(fontSize), fontColor(fontColor)
{
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    this->repaint();
}

void TextDisplay::resizeEvent(QResizeEvent *e) {
//    qDebug() << e->size();
}

QSize TextDisplay::sizeHint() const {
    QSize size;
    size.setHeight(this->minimumHeight());
    size.setWidth(this->width());
    return size;
}

void TextDisplay::paintEvent(QPaintEvent *e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.setPen(fontColor);
    painter.setFont(QFont(fontFamily, fontSize));

    QRect rect(QPoint(0, 0), this->size());
    QRect bound;

    painter.drawText(rect, Qt::TextWordWrap | Qt::TextWrapAnywhere, text, &bound);

    this->resize(bound.size());
    qDebug() << "TD paint: " << bound.size();
    painter.drawLine(QPointF(0, 0), QPointF(this->width()-1, 0));
    painter.drawLine(QPointF(this->width()-1, 0), QPointF(this->width()-1, this->height()-1));
    painter.drawLine(QPointF(this->width()-1, this->height()-1), QPointF(0, this->height()-1));
    painter.drawLine(QPointF(0, this->height()-1), QPointF(0, 0));
    this->setMinimumHeight(bound.size().height());

    emit repainted(bound.size());
}
