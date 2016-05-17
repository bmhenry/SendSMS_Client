#include "sms.h"

#include <QDebug>
#include <QTextStream>


SMS::SMS()
{
    this->type = SMS::EMPTY;
    this->timestamp = "";
    this->people = "";
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

    this->type = stream.readLine() == "RECEIVED" ? 0 : 1;
    this->timestamp = stream.readLine();
    this->people = stream.readLine();
    this->message = stream.readAll();
}

SMS::SMS(int smstype, QString timestamp, QString people, QString message)
{
    this->type = smstype;
    this->timestamp = timestamp;
    this->people = people;
    this->message = message;
}

QString SMS::toString()
{
    QString str;

    str += type == SMS::RECEIVED ? "RECEIVED\n" : "SENT\n";
    str += timestamp + "\n" + people + "\n" + message + "\n" + endchar + "\n";

    return str;
}
