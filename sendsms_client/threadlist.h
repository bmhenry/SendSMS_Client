#ifndef THREADLIST
#define THREADLIST

#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QList>


class ThreadList : public QFrame
{
    Q_OBJECT

public:
    ThreadList(QWidget *parent = 0);

    void addItem(QString title, QString text);

private:
    QListWidget *list;
};


#endif // THREADLIST

