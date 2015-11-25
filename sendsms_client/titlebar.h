#ifndef TITLEBAR
#define TITLEBAR

#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>
#include <QWidget>

#include "mainwindow.h"


class TitleBar : public QWidget
{
    Q_OBJECT

public:
    TitleBar(QWidget *parent = 0, MainWindow *m = 0);
    QPushButton *exitButton;
    QPushButton *minimizeButton;


private:
    QHBoxLayout *layout;
    QPoint lastMousePos;
    MainWindow *mainWindow;
    bool moving;

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // TITLEBAR

