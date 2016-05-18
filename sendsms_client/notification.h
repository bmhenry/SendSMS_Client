#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QDialog>
#include <QTimer>
#include <QList>
#include <QString>
#include <QPropertyAnimation>



class Notification : public QDialog
{
    Q_OBJECT

public:
    explicit Notification(QList<QString> data, quint32 msecs, QWidget *parent = 0);
    ~Notification();

private:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

    QString name;
    QString number;
    QString message;
    bool isHovered;

    QTimer *timer;
    QPropertyAnimation *anim;

private slots:
    void fadeOut();
    void hide();
    void replyClicked();
    void closeClicked();
};

#endif // NOTIFICATION_H
