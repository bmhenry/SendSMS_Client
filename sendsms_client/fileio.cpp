#include "fileio.h"

#include <QTextStream>


void sms_example()
{
    QFile file(app_dir() + QString("/sms/example.sms"));
    file.open(QFile::WriteOnly);

    QTextStream out(&file);
    out << "IN\nNOW\nPERSON A\nTHIS IS A TEST" << " " << QChar(0x1d);

    file.close();
}

SMS sms_parse(QString filename)
{
    QFile file(app_dir() + QString("/sms/") + filename);
    if (!file.open(QFile::ReadOnly))
        return SMS();

    QTextStream in(&file);

    SMS sms;
    QString check;
    QString message;

    in >> check;

    if (check == QString("IN"))
        sms.type = 1;
    else
        sms.type = 0;

    in >> sms.timestamp;

    while (1)
    {
        in >> check;

        if (check == QString(QChar(0x1f)))
            break;
        else
            sms.people.push_back(check);
    }

    while (1)
    {
        in >> check;

        if (check == QString(QChar(0x1d)))
            break;
        else
            message += check;
    }

    sms.message = message;
    file.close();

    return sms;
}

void sms_append(QString fileName, QString addition)
{

}
