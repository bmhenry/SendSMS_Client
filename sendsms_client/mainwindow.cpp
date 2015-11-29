#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QString>
#include <QListWidgetItem>
#include <QPalette>
#include <QRect>
#include "mainwindow.h"

#include <QSize>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

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
    threadList = new ThreadList(w);
    listLayout->addWidget(threadList, 1);

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

    listLayout->addWidget(messageContainer, 5);

    mainLayout->addWidget(listContainer);

    /*
     *  Get SMS
     */
    //SMS example = sms_parse(QString("example.sms"));
    //messageList->addItem(example.message, example.timestamp, example.type);

    createActions();
    createMenus();

    setWindowTitle(tr("GracefulSMS"));
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
