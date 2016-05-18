#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QDialog>
#include <QTimer>
#include <QList>
#include <QString>



class Notification : public QDialog
{
    Q_OBJECT

public:
    explicit Notification(QList<QString> data, quint32 timerInterval, QWidget *parent = 0);
    ~Notification();

private:
    QString name;
    QString number;
    QString message;
    quint32 timerInterval;

    QTimer *timer;

private slots:
    void hide();
    void replyClicked();
    void closeClicked();
};

#endif // NOTIFICATION_H
