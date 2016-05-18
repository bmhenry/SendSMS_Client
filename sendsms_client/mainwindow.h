#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QCloseEvent>
#include <QDebug>
#include <QLabel>
#include <QListView>
#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QString>
#include <QWidget>

#include "titlebar.h"
#include "threadlist.h"
#include "messagelist.h"
#include "sendbar.h"
#include "client.h"
#include "notification.h"

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
    void reconnect();
    void connectSocket();
    void disconnectSocket();
    void about();
    void exit();
    void minimize();
    void windowMove(QPoint posChange);

    void clientData(QString);
    void sendMessage(QString);

    void threadChanged(int);

#ifdef QT_DEBUG
    void fakeNotify();
#endif

private:
    Client *client;

    TitleBar *titlebar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

#ifdef QT_DEBUG
    QMenu *debugMenu;
    QAction *notificationAct;
#endif
    QMenu *settingsMenu;

    QAction *reconnectAct;
    QAction *connectAct;
    QAction *openAct;
    QAction *aboutAct;
    QAction *exitAct;

    ThreadList *threadList;
    MessageList *messageList;
    SendBar *sendBar;

    Notification *notification;
};

#endif // MAINWINDOW_H
