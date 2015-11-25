#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QLabel>
#include <QMainWindow>
#include <QListView>
#include <QListWidget>
#include <QWidget>

#include "titlebar.h"


class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void connect();
    void disconnect();
    void about();
    void exit();

private:
    void createActions();
    void createMenus();

    TitleBar *titlebar;
    QMenu *settingsMenu;

    QAction *connectAct;
    QAction *openAct;
    QAction *aboutAct;
    QAction *exitAct;

    //QListView *threadList;
    //QListView *messageList;
    QListWidget *threadList;
    QListWidget *messageList;
};

#endif // MAINWINDOW_H
