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

    void addItem(QString filename, QString title, QString text);
    void addConversation(QString filename);
    QString getCurrentFilename();
    void setSelection(int index);

    bool contains(QString filename);

signals:
    void selectionChanged(int);

private:
    QListWidget *list;
    QList<QString> sms_filename_list;
};


#endif // THREADLIST

