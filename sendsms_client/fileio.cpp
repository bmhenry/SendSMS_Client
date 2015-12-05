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

QList<SMS> sms_parse(QString filename)
{
    // create list
    QList<SMS> list;

    QFile file(app_dir() + QString("/sms/") + filename);
    if (!file.exists())
        return list;

    file.open(QFile::ReadOnly);

    // read each line
    QTextStream stream(file);
    while (!stream.atEnd())
    {
        SMS sms;
        sms.type = stream.readLine();
        sms.timestamp = stream.readLine();
        sms.people = stream.readLine();

        QString line;
        line = stream.readLine();
        while (!line.contains(QChar(0x1d)))
        {
            sms.message += line;
            line = stream.readLine();
        }
    }

    QTextStream in(&file);

    // close the file
    file.close();
}

void sms_append(QString fileName, QString addition)
{
    QFile file(fileName);

    file.open(QFile::Append);
    QTextStream out(&file);

    out << addition;

    file.close();
}
