#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <QWidget>

class TextDisplay : public QWidget
{
    Q_OBJECT

public:
    TextDisplay(QString text, QString fontFamily = "Helvetica", int fontSize = 10,
                int fontColor = Qt::black, QWidget* parent = 0);
    QSize sizeHint() const;

signals:
    void repainted(QSize);

protected:
    void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

private:
    QString text;
    QString fontFamily;
    int fontSize;
    int fontColor;
};

#endif // TEXTDISPLAY_H
