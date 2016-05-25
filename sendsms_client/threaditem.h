#ifndef THREADITEM
#define THREADITEM

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>


class ThreadItem : public QFrame
{
    Q_OBJECT

public:
    ThreadItem(QString filename, QString name, QString number, QString text, QWidget *parent = 0);

    inline void setTitle(QString title) { titleLabel->setText(title); }
    inline void setText(QString text) { textLabel->setText(text) ;}
    inline void setFilename(QString filename) { this->filename = filename; }
    inline void setName(QString name) { this->name = name; }
    inline void setNumber(QString number) { this->number = number; }

    inline QString getFilename() { return filename; }
    inline QString getName() { return name; }
    inline QString getNumber() { return number; }


private:
    QLabel *titleLabel;
    QLabel *textLabel;
    QString filename;
    QString name;
    QString number;
};


#endif // THREADITEM

