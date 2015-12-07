#ifndef THREADITEM
#define THREADITEM

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>


class ThreadItem : public QFrame
{
    Q_OBJECT

public:
    ThreadItem(QString filename, QString title, QString text, QWidget *parent = 0);

    void setTitle(QString title);
    void setText(QString text);
    void setFile(QString filename);

    QString getFile();

private:
    QLabel *titleLabel;
    QLabel *textLabel;
    QString filename;
};


#endif // THREADITEM

