#ifndef FILEIO
#define FILEIO

#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QList>
#include <QStringList>


typedef struct SMS {
    bool type; // 0 = received (in), 1 = sent (out)
    QString timestamp;
    QString people; // other people in the message
    QString message;
} SMS;


// get directory of the application
inline QString app_dir() { return qApp->applicationDirPath(); }

// check if first time ran
inline bool is_first_run() { return !QFile::exists(QString(app_dir() + "/gracefulsms.settings")); }

// check for sms file
inline bool sms_exists(QString fileName) { return QFile::exists(QString(app_dir() + "/sms/" + fileName)); }

// get list of sms files in the sms directory
QStringList sms_get_list();

// write an example sms file
void sms_example();

// parse an sms file
QList<SMS> sms_parse(QString filename);

// append to sms file
void sms_append(QString fileName, QString addition);


#endif // FILEIO
