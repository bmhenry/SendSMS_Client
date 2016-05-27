#ifndef MESSAGETEXTCONTAINER_H
#define MESSAGETEXTCONTAINER_H

#include <QLabel>
#include <QFrame>
#include "textdisplay.h"

class MessageTextContainer : public QFrame
{
    Q_OBJECT

public:
    MessageTextContainer(QString text, QString timestamp, QWidget* parent = 0);
    QSize sizeHint() const;

signals:
    void resized(QSize);

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    const static int padding = 10;
    TextDisplay *textDisplay;
    QLabel *timeLabel;

private slots:
    void catchRepainted(QSize);
};

#endif // MESSAGETEXTCONTAINER_H
