#include <QCoreApplication>
#include "q_stringview.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    q_stringview* qSV = new q_stringview();
    qSV->practice();
    delete qSV;

    return a.exec();
}
