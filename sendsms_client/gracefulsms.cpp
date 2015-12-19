#include "gracefulsms.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

#include "fileio.h"

bool first_run()
{
    // create settings file
    QFile settingsFile(app_dir() + QString("/gracefulsms.settings"));
    settingsFile.open(QIODevice::WriteOnly);

    QTextStream out(&settingsFile);

    out << "Hello!" << endl;

    settingsFile.close();

    // create sms directory
    QDir(app_dir()).mkdir(QString("sms"));

    // create 'about' file for first thread
    sms_about();

    // create example text
    //sms_example();

    return true;
}
