#ifndef SMS_H
#define SMS_H

#include <QString>


class SMS {

public:
    // some constants for ease of use
    typedef enum SMS_Type {EMPTY, RECEIVED, SENT} SMS_Type;
    const static char endchar = 0x1d;

    SMS_Type type;
    QString timestamp;
    QString numbers;
    QString names;
    QString message;

    SMS(); // creates an empty SMS
    SMS(QString input); // parses an SMS from a single string
    SMS(SMS_Type smstype, QString timestamp, QString numbers, QString names, QString message);

    QString toString();
    SMS fromString(QString);
};

#endif // SMS_H
