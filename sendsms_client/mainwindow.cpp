#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QString>
#include <QListWidgetItem>
#include <QPalette>
#include <QRect>
#include "mainwindow.h"

#include <QSize>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

#include <QFile>
#include <QTextStream>

#include "gracefulsms.h"
#include "fileio.h"



MainWindow::MainWindow()
{
    // Remove default frame and window buttons:
    //this->setWindowFlags(Qt::FramelessWindowHint);

    // set window icon
    this->setWindowIcon(QIcon("./sms.ico"));

    // center window on screen
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);

    // check if this is first run, if so do necessary actions
    if (is_first_run())
        first_run();

    // create central widget
    QWidget *w = new QWidget(this);
    setCentralWidget(w);

    w->setObjectName("centralWidget");
    w->setStyleSheet(QString("#centralWidget{background:white;padding:0;}"));

    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    /*
     *  Window Buttons:
     *                  */
    menuBar = new QMenuBar(this);
    statusBar = new QStatusBar(this);

#ifdef QT_DEBUG
    debugMenu = menuBar->addMenu(QString("Debug"));
    notificationAct = new QAction(QString("Notification"), this);
    debugMenu->addAction(notificationAct);
    connect(notificationAct, SIGNAL(triggered(bool)), this, SLOT(fakeNotify()));
#endif

    reconnectAct = menuBar->addAction("Reconnect");
    connect(reconnectAct, SIGNAL(triggered(bool)), this, SLOT(reconnect()));

    setMenuBar(menuBar);
    setStatusBar(statusBar);

    statusBar->showMessage("Hello!");


    // create custom bar for window operations
    /*
    titlebar = new TitleBar(w);
    w->connect(titlebar->exitButton, SIGNAL(released()), this, SLOT(exit()));
    w->connect(titlebar->minimizeButton, SIGNAL(released()), this, SLOT(minimize()));
    w->connect(titlebar, SIGNAL(moveSignal(QPoint)), this, SLOT(windowMove(QPoint)));

    mainLayout->addWidget(titlebar);
    */


    /*
     * Message Lists:
     *                  */
    // Layout for the lists (bottom portion below menu bar)
    QWidget *listContainer = new QWidget(w);
    QHBoxLayout *listLayout = new QHBoxLayout(listContainer);

    // List of message threads (individual people or MMS)
    threadList = new ThreadList(w);
    listLayout->addWidget(threadList, 1);
    w->connect(threadList, SIGNAL(selectionChanged(int)), this, SLOT(threadChanged(int)));

    // container for message list and send bar
    QFrame *messageContainer = new QFrame(w);
    QVBoxLayout *mcLayout = new QVBoxLayout(messageContainer);
    mcLayout->setMargin(0);

    // List for messages in current thread
    messageList = new MessageList(messageContainer);
    mcLayout->addWidget(messageList);

    // Bar for sending messages
    sendBar = new SendBar(messageContainer);
    mcLayout->addWidget(sendBar);
    w->connect(sendBar, SIGNAL(sendSent(QString)), this, SLOT(sendMessage(QString)));

    listLayout->addWidget(messageContainer, 5);

    mainLayout->addWidget(listContainer);

    /*
     *  Get SMS threads
     */

    QStringList file_list = sms_get_list();

    for (int file = 0; file < file_list.length(); file++)
    {
        QString filename = file_list.at(file);

        qDebug() << filename;
        if (filename == "." || filename == "..")
            continue;

        // add the sms to the threadlist
        threadList->addConversation(filename);
    }

    // select the first thread
    threadList->setSelection(0);

    // start tcp client
    client = new Client("192.168.0.100", 8000, this);
    w->connect(client, SIGNAL(gotInfo(QString)), this, SLOT(clientData(QString)));
    w->connect(client, SIGNAL(connectSuccess()), this, SLOT(reconnectSuccess()));

    setWindowTitle(tr("GracefulSMS"));
    resize(1000,500);
//    statusBar->setSizeGripEnabled(false);
    this->setMinimumSize(500, 300);
}

void MainWindow::threadChanged(int)
{
    // get the filename at the new index
    QString filename = threadList->getCurrentFilename();

    // case for the about text
//    if (filename == "about.txt")
//    {
//        QFile about(sms_dir() + "/about.txt");
//        about.open(QFile::ReadOnly);
//        messageList->clear();
//        messageList->addItem(QString(about.readAll()), "", SMS::RECEIVED);
//        about.close();

//        return;
//    }

    // update the message thread
    QList<SMS> sms_list = sms_parse(filename);
    messageList->clear();

    // skip the first element, it's the list of all people in the message
    for (int i = 1; i < sms_list.length(); i++)
    {
        SMS sms = sms_list.at(i);
        messageList->addItem(sms.message, sms.timestamp, sms.type);
    }
}

void MainWindow::clientData(QString str)
{
    QList<QString> info = handle_input(str);

    if (info.length() == 0 || info.at(0) == NULL)
        return;

    QString number = info.at(0);
    QString name = info.at(1);
    QString filename = number + ".sms";
    QString type = info.at(2);
    QString message = info.at(3);

    // if the file that was changed is the same as the one currently viewed...
    if (filename == threadList->getCurrentFilename())
        // update the displayed messages
        threadChanged((int) 0);
    // if the file already exists, then so does the thread. do nothing more
    // but if the file doesn't exist, create it and add a new thread
    else if (!threadList->contains(filename))
    {
        qDebug() << filename;
        if (filename == "." || filename == "..")
            return;

        threadList->addConversation(filename);
    }

    // update the message preview text for the thread
    threadList->setTextAt(filename, message);
    threadList->repaint();

    // create the notification
    // TODO: add condition using signals so that new notification doesn't cause
    //  existing one to disappear if the user is typing in it
    if (type == "1") {
        QList<QString> data;
        data.append(name);        // name
        data.append(number);  // phone number
        data.append(message);   // message
        notification = new Notification(data, 10000);
    }
}

void MainWindow::sendMessage(QString str)
{
    // get the current number of the person being messaged
    QString number = threadList->getCurrentNumber();
    QString name = threadList->getCurrentName();
    // send the number followed by the message, \n after the number and 0x1d after the message
    QString sendString = number + "\n" + name + "\n" + str + QChar(0x1d) + "\n";
    qDebug() << "sending:\n" << sendString;
    client->send(sendString);
}

#ifdef QT_DEBUG
void MainWindow::fakeNotify()
{
    QList<QString> fakeData;
    fakeData.append("name");
    fakeData.append("number");
    fakeData.append("message");
    notification = new Notification(fakeData, 2000);
}
#endif

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    exit();
}

void MainWindow::reconnect() {
    client->reconnect();
}

void MainWindow::reconnectSuccess() {
    statusBar->showMessage("Reconnected", 5000);
}

void MainWindow::connectSocket()
{

}

void MainWindow::disconnectSocket()
{

}

void MainWindow::about()
{

}

void MainWindow::windowMove(QPoint posChange)
{
    this->move(this->pos() + posChange);
}

void MainWindow::exit()
{
    client->close();

    qApp->exit(EXIT_SUCCESS);
}

void MainWindow::minimize()
{
    this->showMinimized();
}
