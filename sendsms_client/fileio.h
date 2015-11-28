#ifndef FILEIO
#define FILEIO

#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QTextStream>


// get directory of the application
inline QString app_dir() { return qApp->applicationDirPath(); }

// check if first time ran
inline bool is_first_run() { return QFile::exists(QString(app_dir() + "/gracefulsms.settings")); }

// check for sms file
inline bool sms_exists(QString fileName) { return QFile::exists(QString(app_dir() + "/sms/" + fileName)); }

// append to sms file
void sms_append(QString fileName, QString addition);


#endif // FILEIO
