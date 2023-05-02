#include "q_settings.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = a.applicationDirPath() + "/settings.ini";

    qInfo() << filename;

//    QSettings set(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    q_settings* qset = new q_settings(filename);
    qset->practice();
    delete qset;

    return a.exec();
}
