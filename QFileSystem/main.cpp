#include "q_iodevice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    q_IODevice* io = new q_IODevice();
    io->practice();
    delete io;

    return a.exec();
}
