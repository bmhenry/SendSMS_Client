#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QString>
#include <QListWidgetItem>
#include <QPalette>
#include <QRect>
#include <QSize>
#include <QVBoxLayout>

#include "mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QTextEdit>



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

    // create central widget
    QWidget *w = new QWidget;
    setCentralWidget(w);

    w->setObjectName("centralWidget");
    w->setStyleSheet(QString("#centralWidget{background:#777777;}"));

    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    /*
     *  Window Buttons:
     *                  */
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
    threadList = new ThreadList();
    threadList->addItem("Person 1", "Hello, this is an automated message from the IRS.");
    threadList->addItem("Person 2", "Hey, have you burned all of those tax receipts yet?");
    threadList->addItem("Person 3", "Testing testing.");

    listLayout->addWidget(threadList, 1);

    // container for message list and send bar
    QFrame *messageContainer = new QFrame;
    QVBoxLayout *mcLayout = new QVBoxLayout(messageContainer);
    mcLayout->setMargin(0);

    // List for messages in current thread
    messageList = new MessageList();
    messageList->addItem("Hello, this is an automated message from the IRS. We would like to inform you that you're very stupid.", "yesterday", MessageList::RECEIVED);
    messageList->addItem("Lorem ipsum i dunno the rest so this is just a filler.", "today", MessageList::SENT);

    mcLayout->addWidget(messageList);

    // Bar for sending messages
    sendBar = new SendBar();

    mcLayout->addWidget(sendBar);


    listLayout->addWidget(messageContainer, 5);

    mainLayout->addWidget(listContainer);

    createActions();
    createMenus();

    setWindowTitle(tr("SendSMS"));
    resize(800,400);
    this->setMinimumSize(500, 300);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    // i could do custom handling here
    delete threadList;
    event->ignore();
    exit();
}

void MainWindow::connect()
{

}

void MainWindow::disconnect()
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
    qApp->exit(EXIT_SUCCESS);
}

void MainWindow::minimize()
{
    this->showMinimized();
}

void MainWindow::createActions()
{

}

void MainWindow::createMenus()
{

}
