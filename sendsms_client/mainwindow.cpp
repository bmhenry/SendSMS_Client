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
#include "titlebar.h"

#include <QLabel>
#include <QPushButton>



MainWindow::MainWindow()
{
    // Remove default frame and window buttons:
    this->setWindowFlags(Qt::FramelessWindowHint);

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
    w->setStyleSheet(QString("#centralWidget{border:1px solid black;}"));

    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    /*
     *  Window Buttons:
     *                  */
    // create custom bar for window operations
    titlebar = new TitleBar(w);
    w->connect(titlebar->exitButton, SIGNAL(released()), this, SLOT(exit()));
    w->connect(titlebar->minimizeButton, SIGNAL(released()), this, SLOT(minimize()));
    w->connect(titlebar, SIGNAL(moveSignal(QPoint)), this, SLOT(windowMove(QPoint)));

    mainLayout->addWidget(titlebar);



    /*
     * Message Lists:
     *                  */
    // Layout for the lists (bottom portion below menu bar)
    QWidget *listContainer = new QWidget(w);
    QHBoxLayout *listLayout = new QHBoxLayout(listContainer);

    // List of message threads (individual people or MMS)
    threadList = new QListWidget;

    // TEST: add an item to the threadlist
    QListWidgetItem *item = new QListWidgetItem(threadList);
    QFrame *widget = new QFrame();
    widget->setStyleSheet(QString("background:black;color:white;border:2px solid blue;"));
    QVBoxLayout *l = new QVBoxLayout(widget);
    QLabel *str = new QLabel("Meow.");
    QLabel *str2 = new QLabel("Test.");
    l->addWidget(str);
    l->addWidget(str2);
    item->setSizeHint(widget->minimumSizeHint());

    threadList->addItem("Hello!");
    threadList->addItem(item);
    threadList->setItemWidget(item, widget);

    listLayout->addWidget(threadList);

    mainLayout->addWidget(listContainer);

    createActions();
    createMenus();

    setWindowTitle(tr("SendSMS"));
    resize(800,400);
    this->setMinimumSize(400, 400);
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
