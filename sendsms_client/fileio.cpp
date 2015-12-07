#include "fileio.h"

#include <QTextStream>
#include <QDebug>
#include <QDir>



void sms_example()
{
    QFile file(app_dir() + QString("/sms/example.sms"));
    file.open(QFile::WriteOnly);

    QTextStream out(&file);
    out << "IN\nNOW\nPERSON A, PERSON B, PERSON E\nINTRO\n" << QChar(0x1d) << "\n";
    out << "IN\nNOW\nYOU\nTHIS IS A TEST!\n" << QChar(0x1d) << "\n";
    out << "OUT\nTHEN\nME\nTHIS IS A TEST AGAIN!\n" << QChar(0x1d) << "\n";

    file.close();

    QFile file2(app_dir() + QString("/sms/example2.sms"));
    file2.open(QFile::WriteOnly);

    QTextStream out2(&file2);
    out2 << "IN\nNOW\nPERSON D, PERSON C\nINTRO\n" << QChar(0x1d) << "\n";
    out2 << "IN\nNOW\nYOU\nTHIS IS A TEST AGAIN!\n" << QChar(0x1d) << "\n";
    out2 << "OUT\nTHEN\nME\nTHIS IS A TEST AGAIN AGAIN AGAIN AGAIN AGAIN AGAIN AGAIN AGAIN!\n" << QChar(0x1d) << "\n";

    file2.close();
}

QStringList sms_get_list()
{
    return QDir(app_dir() + QString("/sms")).entryList();
}

QList<SMS> sms_parse(QString filename)
{
    // create list
    QList<SMS> list;

    QFile file(app_dir() + QString("./sms/") + filename);
    if (!file.exists())
    {
        qDebug() << "Couldn't find file " + filename;
        return list;
    }

    file.open(QFile::ReadOnly);

    // read each line
    QTextStream stream(&file);
    while (!stream.atEnd())
    {
        SMS sms;
        sms.type = stream.readLine() == QString("OUT") ? 1 : 0;
        sms.timestamp = stream.readLine();
        sms.people = stream.readLine();

        QString line;
        line = stream.readLine();
        while (!line.contains(QChar(0x1d)))
        {
            sms.message += line;
            line = stream.readLine();
        }

        list.append(sms);
    }

    // close the file
    file.close();

    return list;
}

void sms_append(QString fileName, QString addition)
{
    QFile file(fileName);

    file.open(QFile::Append);
    QTextStream out(&file);

    out << addition;

    file.close();
}
