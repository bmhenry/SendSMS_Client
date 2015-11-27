#ifndef SENDBAR
#define SENDBAR


#include <QFrame>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>


class SendBar : public QFrame
{
public:
    SendBar(QWidget *parent = 0);
    QPushButton *sendButton;
    //QTextEdit *textEdit;
    QLineEdit *textEdit;
};

#endif // SENDBAR

