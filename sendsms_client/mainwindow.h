#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QLabel>
#include <QMainWindow>
#include <QListView>
#include <QListWidget>
#include <QWidget>
#include <QString>

#include "titlebar.h"
#include "threadlist.h"
#include "messagelist.h"
#include "sendbar.h"
#include "server.h"

// forward declare titlebar
class TitleBar;

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
    void minimize();
    void windowMove(QPoint posChange);

    void serverInput(QString);
    void sendMessage(QString);

    void threadChanged(int);

private:
    void createActions();
    void createMenus();

    Server *server;

    TitleBar *titlebar;
    QMenu *settingsMenu;

    QAction *connectAct;
    QAction *openAct;
    QAction *aboutAct;
    QAction *exitAct;

    ThreadList *threadList;
    MessageList *messageList;
    SendBar *sendBar;
};

#endif // MAINWINDOW_H
