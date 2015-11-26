#ifndef THREADLIST
#define THREADLIST

#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QList>


struct ItemStorage
{
    QString *title;
    QString *text;
};

class ThreadList : public QWidget
{
public:
    ThreadList();

    void addItem(QString title, QString text);

private:
    bool colorToggle;
    QListWidget *list;
};


#endif // THREADLIST

