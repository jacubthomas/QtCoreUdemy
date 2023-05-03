#include "q_iodevice.h"

void q_IODevice::practice() {
//    qBufferOverview();
//    writeAFile();
//    appendToFile();
//    readASmallFile();
//    readALargeFile();
//    qTextStreams();
//    qDataStreams();
//    qDirs();

    /*Recursive directory traversal*/
//    QDir root(QCoreApplication::applicationDirPath());
//    root.cdUp();
//    navigateDirectoryRecursively(root);
//    qFileInfos();
//    qStorageInfos();
//    qLockFiles();
    assignmentQTemporaryFile();
}

void q_IODevice::qBufferOverview() {
    QBuffer buffer;
    if (buffer.open(QIODevice::ReadWrite)) {
        qInfo() << "Device is open";

        QByteArray data("Hello World");
        for (int i=0; i<5; i++) {
            buffer.write(data);
            buffer.write("\r\n");
        }

        // go back to the beginning of the buffer
        buffer.seek(0);

        qInfo() << buffer.readAll();

        qInfo() << "Closing buffer...";

        buffer.close();
        qInfo() << "Finished";
    } else {
        qInfo() << "Could not open the device";
    }
}

void q_IODevice::writeAFile() {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)) {

        QString now = QDateTime::currentDateTime().toString();

        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hello world");

        file.write(data);
        file.flush();
        file.close();

        qInfo().noquote() << "Wrote to the file" << filename;
    } else {
        qInfo() << file.errorString();
    }
}

void q_IODevice::appendToFile() {
    QFile file(filename);

    if (file.open(QIODevice::Append)) {

        QString now = QDateTime::currentDateTime().toString();

        QByteArray data;
        data.append("\r\n");
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hello world");

        file.write(data);
        file.flush();
        file.close();

        qInfo().noquote() << "Wrote to the file" << filename;
    } else {
        qInfo() << file.errorString();
    }
}


void q_IODevice::readASmallFile() {
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly)) {

        // Small files only!
        qInfo() << file.readAll();

        file.close();

    } else {
        qInfo() << file.errorString();
    }
}

void q_IODevice::readALargeFile() {
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly)) {

        qInfo() << "-----------------------";
        readChunks(file);
        qInfo() << "-----------------------";
        qInfo() << "       ... Or ...      ";

        file.seek(0);

        qInfo() << "-----------------------";
        readLines(file);
        qInfo() << "-----------------------";

        file.close();

    } else {
        qInfo() << file.errorString();
    }
}

void q_IODevice::readChunks(QFile &file) {
    if (!file.isReadable()) return;
    file.seek(0);
    while (!file.atEnd()) {
        qInfo() << file.read(25);     // 25 bytes of plaintext at a time
    }
}

void q_IODevice::readLines(QFile &file) {
    if (!file.isReadable()) return;
    file.seek(0);
    while (!file.atEnd()) {
        qInfo() << file.readLine();     // looks for `\n`
    }
}

void q_IODevice::read(QFile &file) {
    if (!file.isReadable()) {
        qWarning() << "Unable to read from file!";
        return;
    }

    QTextStream stream(&file);
    stream.seek(0);

    while (!stream.atEnd()) {
        qInfo() << stream.readLine();
    }
}

void q_IODevice::write(QFile &file) {

    if (!file.isWritable()) {
        qWarning() << "Unable to write to file!";
        return;
    }

    QTextStream stream(&file);
    stream.seek(file.size());   // go to end & append
    for (int i=0; i<5; i++) {
        stream << QString::number(i) << "-Item\r\n";
    }
    stream.flush();

    qInfo() << "File written";

}

bool q_IODevice::readSuccess() {
    QFile file(filename2);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return false;
    }

    QDataStream stream(&file);
    if (stream.version() != QDataStream::Qt_5_15) {
        qWarning() << "Wrong file version";
        file.close();
        return false;
    }

    int age;
    QString name;
    double weight;

    stream >> age >> name >> weight;

    file.close();

    qInfo() << "Name" << name;
    qInfo() << "Age" << age;
    qInfo() << "Weight" << weight;

    return true;
}

bool q_IODevice::writeSuccess() {
    QFile file(filename2);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << file.errorString();
        return false;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_15);

    int age = 45;
    QString name = "Bryan";
    double weight = 185.06;
    qInfo() << "Writing file";
    stream << age << name << weight;

    if (!file.flush()) {
        qWarning() << file.errorString();
        file.close();
        return false;
    }

    file.close();
    qInfo() << "Closing file";
    return true;
}


// QTextStream is a convenience class, beneficial for handling things like encoding;
// Unfortunately, qt 5 QTextStreams do not offer the encoding support provide by 6.
void q_IODevice::qTextStreams() {
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {

        QTextStream stream(&file);
//        qInfo() << "Encoding:" << stream.encoding();      // not in qt 5

        write(file);
        read(file);
        file.close();
    } else {
        qInfo() << file.errorString();
    }
}

void q_IODevice::qDataStreams() {
    if (writeSuccess()) {
        readSuccess();
    }
}

void q_IODevice::qDirs() {
    QDir dir(QCoreApplication::applicationDirPath());
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();
    dir.cdUp();
    qInfo() << dir.absolutePath();
    list(dir);
    dir.mkdir("Test");
    list(dir);
    dir.rmdir("Test");    // succeeds only if directory is empty - otherwise recursiveRem()
    list(dir);
}

void q_IODevice::list(QDir &root) {

    qInfo() << "----Listing----";
    foreach(QFileInfo fi, root.entryInfoList(QDir::Filter::Dirs,
                                             QDir::Name )) {
        if (fi.isDir()) {
            qInfo() << fi.absoluteFilePath();
        }
    }
}

void q_IODevice::navigateDirectoryRecursively(QDir &root) {
    qInfo() << "----Listing----";
    foreach(QFileInfo fi, root.entryInfoList(QDir::AllEntries |
                                             QDir::NoDotAndDotDot)) {

        if (fi.isDir()) qInfo() << "Dir" << fi.filePath();
        if (fi.isFile()) qInfo() << "file" << fi.filePath();

        if (fi.isDir()) {
            QDir child (fi.filePath());
            qInfo() << "Inspecting:" << child.absolutePath();
            navigateDirectoryRecursively(child);
        }

    }
}

void q_IODevice::listForFileInfo(QString path) {
    qInfo () << "List:" << path;

    QDir dir(path);

    QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);

    foreach(QFileInfo fi, dirs) {
        qInfo() << fi.fileName();
    }
    foreach(QFileInfo fi, files) {
        qInfo() << "..Name:" << fi.fileName();
        qInfo() << "..Size:" << fi.size();
        qInfo() << "..Created:" << fi.birthTime();
        qInfo() << "..Modified:" << fi.lastModified();
    }

    // Recursive
    foreach(QFileInfo fi, dirs) {
        listForFileInfo(fi.absoluteFilePath());
    }
}

void q_IODevice::qFileInfos() {
    listForFileInfo(QDir::tempPath());
    qInfo() << "Done";
}

void q_IODevice::qStorageInfos() {
    QStorageInfo root = QStorageInfo::root();
    QDir dir(root.rootPath());
    qInfo() << "Root:" << root.rootPath();

    foreach(QFileInfo fi, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        qInfo() << fi.filePath();
    }
    qInfo() << "--------------------------------";
    foreach(QStorageInfo storage, QStorageInfo::mountedVolumes()) {
        qInfo() << "Name:" << storage.displayName();
        qInfo() << "Type:" << storage.fileSystemType();
        qInfo() << "Total:" << storage.bytesTotal() /1000/1000 << "MB";
        qInfo() << "Available:" << storage.bytesAvailable() /1000/1000 << "MB";
        qInfo() << "Device:" << storage.device();
        qInfo() << "Root:" << storage.isRoot();
        qInfo() << "\r\n";
    }
}

void q_IODevice::qLockFiles() {
    qInfo() << "Attempting to lock a file...";

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    QFile file(path);
    QLockFile lock(file.fileName() + "l");
    lock.setStaleLockTime(15000);

    if (lock.tryLock()) {
        qInfo() << "Putting into file...";
        if (file.open(QIODevice::WriteOnly)) {
            QByteArray data;
            data.append("QWERRQSFJSDOIFN()@#YH!R@#I)RH@#(*GRWU(@Q!GFW&GF");
            file.write(data);
            file.close();
            qInfo() << "Finished with file ...";
            // Took over x secondss here, auto unlock
        }
        qInfo() << "Unlocking file";
        lock.unlock(); // comment out to see it lock
    } else {
        qInfo() << "Could not lock the file!";
        qint64 pid;
        QString host;
        QString application;

        if (lock.getLockInfo(&pid,&host,&application)) {
            qInfo() << "The file is locked by:";
            qInfo() << "Pid" << pid;
            qInfo() << "Host" << host;
            qInfo() << "Application" << application;
        } else {
            qInfo() << "File is locked, but we can't get the info!";
        }
    }

}

void q_IODevice::assignmentQTemporaryFile() {
    QTemporaryFile file(QString("testTempFile"));
    if (file.open()) {
        qInfo() << "Opened temporary file:" << file.fileName();
        QByteArray data("Hello world");
        file.write(data);
        file.seek(0);
        qInfo() << file.readAll();
    } else {
        qWarning() << "Failed to open temporary file.";
    }
}
