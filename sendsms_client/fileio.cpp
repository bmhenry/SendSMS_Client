#include "fileio.h"

#include <QTextStream>
#include <QDebug>
#include <QDir>



void sms_about()
{
    QFile file(app_dir() + "/about.txt");
    file.open(QFile::WriteOnly);

    QTextStream out(&file);
    QString welcome(
                "Hey there!"
                "I hope that this app proves useful to you, and also makes you feel safer"
                "about using a service to text from your computer while at home.\n"
                );
    out << welcome;

    file.close();
}

void sms_example()
{
    QFile file(sms_dir() + QString("example.sms"));
    file.open(QFile::WriteOnly);

    QTextStream out(&file);
    out << SMS(SMS::RECEIVED, "NOW", "Person A, Person B, Person C", "HEADER").toString();
    out << SMS(SMS::RECEIVED, "NOW", "Them", "This is a test!").toString();
    out << SMS(SMS::SENT, "THEN", "Me", "This is simply another test!").toString();

    file.close();
}

void sms_makefile(QString filename, QString people)
{
    QFile file(sms_dir() + filename);
    file.open(QFile::WriteOnly);

    QTextStream out(&file);
    out << SMS(SMS::RECEIVED, "INTRO", people, "INTRO").toString();

    file.close();
}

QStringList sms_get_list()
{
    return QDir(sms_dir()).entryList();
}

QList<SMS> sms_parse(QString filename)
{

    // create list
    QList<SMS> list;

    // check that the file is an sms file, otherwise skip
    //if (QFileInfo(filename).suffix() != QString("sms"))
    //    return;

    QFile file(sms_dir() + filename);
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
        sms.type = stream.readLine() == "RECEIVED" ? 0 : 1;
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
    QFile file(sms_dir() + fileName);

    file.open(QFile::Append);
    QTextStream out(&file);

    out << addition;

    file.close();
}

QString handle_input(QString info)
{
    // parse the information
    SMS sms(info);

    if (sms.type == SMS::EMPTY)
        return NULL; // bad sms, do nothing

    // get the list of people and use it to create the sms file
    // for now this only works for conversations with only one other person
    QString filename = sms.people + ".sms";

    if (!sms_exists(filename))
        // file doesnt already exist, create it
        sms_makefile(filename, sms.people);

    // then append the file
    sms_append(filename, sms.toString());

    return filename;
}
