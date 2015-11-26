#ifndef THREADITEM
#define THREADITEM

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>


class ThreadItem : public QFrame
{
    Q_OBJECT

public:
    ThreadItem(QString title, QString text, bool colorToggle, QWidget *parent = 0);

    void setTitle(QString title);
    void setText(QString text);

private:
    QLabel *titleLabel;
    QLabel *textLabel;
};


#endif // THREADITEM

