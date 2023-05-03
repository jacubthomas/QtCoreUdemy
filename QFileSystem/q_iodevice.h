#ifndef Q_IODEVICE_H
#define Q_IODEVICE_H

#include <QBuffer>
#include <QCoreApplication>
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QIODevice>
#include <QLockFile>
#include <QTemporaryFile>
#include <QTextStream>
#include <QStorageInfo>

class q_IODevice
{
public:
    q_IODevice(){};
    ~q_IODevice(){};
    void practice();
    void qBufferOverview();
    void writeAFile();
    void appendToFile();
    void readASmallFile();
    void readALargeFile();
    void readChunks(QFile &file);
    void readLines(QFile &file);
    void read(QFile &file);
    void write(QFile &file);
    bool readSuccess();
    bool writeSuccess();
    void qTextStreams();
    void qDataStreams();
    void qDirs();
    void list(QDir &root);
    void navigateDirectoryRecursively(QDir &root);
    void listForFileInfo(QString path);
    void qFileInfos();
    void qStorageInfos();
    void qLockFiles();
    void assignmentQTemporaryFile();

private:
    QString filename = "test.txt";
    QString filename2 = "test2.txt";
};
#endif // Q_IODEVICE_H
