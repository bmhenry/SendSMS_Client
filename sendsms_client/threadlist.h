#ifndef THREADLIST
#define THREADLIST

#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QList>

#include "threaditem.h"


class ThreadList : public QFrame
{
    Q_OBJECT

public:
    ThreadList(QWidget *parent = 0);

    void addItem(QString filename, QString title, QString text);
    void addConversation(QString filename);
    void setSelection(int index);

    QString getCurrentFilename();
    QString getCurrentNumber();

    void setTextAt(QString filename, QString text);

    bool contains(QString filename);

signals:
    void selectionChanged(int);

private:
    QListWidget *list;

    QList<QString> sms_filename_list;
    QList<ThreadItem*> itemList;    // list of pointers to the widgets in the listwidgetitems
};


#endif // THREADLIST

