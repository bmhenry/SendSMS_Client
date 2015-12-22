#ifndef SENDBAR
#define SENDBAR


#include <QFrame>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>


class SendBar : public QFrame
{
    Q_OBJECT

public:
    SendBar(QWidget *parent = 0);

    QPushButton *sendButton;
    //QTextEdit *textEdit;
    QLineEdit *textEdit;

public slots:
    void sendPressed();

signals:
    void sendSent(QString);
};

#endif // SENDBAR

