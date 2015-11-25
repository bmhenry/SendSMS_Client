#ifndef TITLEBAR
#define TITLEBAR

#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>
#include <QWidget>

#include "mainwindow.h"

// forward declare mainwindow
class MainWindow;

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    QPushButton *exitButton;
    QPushButton *minimizeButton;

    QPoint posChange;

    TitleBar(QWidget *parent = 0, MainWindow *m = 0);

signals:
    void moveSignal(QPoint posChange);

private:
    QHBoxLayout *layout;
    MainWindow *mainWindow;

    QPoint curPos;
    QPoint lastMousePos;
    bool moving;

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // TITLEBAR

