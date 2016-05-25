#include "sms.h"

#include <QDebug>
#include <QTextStream>


SMS::SMS()
{
    this->type = SMS::EMPTY;
    this->timestamp = "";
    this->numbers = "";
    this->names = "";
    this->message = "";
}

SMS::SMS(QString input)
{
    if (input == NULL ||
       (input[input.size() - 1] != '\n' && input[input.size() - 2] != endchar))
    {
        qDebug() << "Error: input string for SMS() doesn't terminate in proper end character";
        this->type = SMS::EMPTY;
    }

    // remove the endchar and newline on the end
    input.chop(2);

    QTextStream stream(&input);

    this->type = stream.readLine() == "RECEIVED" ? SMS::RECEIVED : SMS::SENT;
    this->timestamp = stream.readLine();
    this->numbers = stream.readLine();
    this->names = stream.readLine();
    this->message = stream.readAll();
}

SMS::SMS(SMS_Type smstype, QString timestamp, QString numbers, QString names, QString message)
{
    this->type = smstype;
    this->timestamp = timestamp;
    this->numbers = numbers;
    this->names = names;
    this->message = message;
}

QString SMS::toString()
{
    QString str;

    str += type == SMS::RECEIVED ? "RECEIVED\n" : "SENT\n";
    str += timestamp + "\n" + numbers + "\n" + names + "\n" + message + "\n" + endchar + "\n";

    return str;
}
