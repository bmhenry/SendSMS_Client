#ifndef SMS_H
#define SMS_H

#include <QString>


class SMS {

public:
    int type; // 0 = received (in), 1 = sent (out), -1 = not an sms/empty
    QString timestamp;
    QString people;
    QString message;

    // some constants for ease of use
    const static int EMPTY = -1;
    const static int RECEIVED = 0;
    const static int SENT = 1;
    const static char endchar = 0x1d;

    SMS(); // creatse an empty SMS
    SMS(QString input); // parses an SMS from a single string
    SMS(int smstype, QString timestamp, QString people, QString message);

    QString toString();
    SMS fromString(QString);
};

#endif // SMS_H
