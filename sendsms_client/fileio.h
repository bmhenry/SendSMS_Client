#ifndef FILEIO
#define FILEIO

#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QList>
#include <QStringList>

#include "sms.h"



// get directory of the application
inline QString app_dir() { return qApp->applicationDirPath(); }

// get directory of sms
inline QString sms_dir() { return app_dir() + "/sms/"; }

// check if first time ran
inline bool is_first_run() { return !QFile::exists(QString(app_dir() + "/gracefulsms.settings")); }

// create 'about' sms file for first thread
void sms_about();

// check for sms file
inline bool sms_exists(QString fileName) { return QFile::exists(QString(sms_dir() + fileName)); }

// create an sms file
void sms_makefile(QString filename, QString names, QString numbers);

// get list of sms files in the sms directory
QStringList sms_get_list();

// write an example sms file
void sms_example();

// parse an sms file
QList<SMS> sms_parse(QString filename);

// append to sms file
void sms_append(QString fileName, QString addition);

// handles info sent to the server from the android device
QList<QString> handle_input(QString info);


#endif // FILEIO
