#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

// QString automatically encodes to UTF-16 - Work with non-english languages

QByteArray makeDataASCII() {
    QByteArray data;
    for (int i=0; i<10; i++) {
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(108);
        data.append(111);
        data.append(33);
        data.append(13); // \r
        data.append(10); // \n
    }
    return data;
}

void ascii() {
    QByteArray data = makeDataASCII();
    qInfo() << data;

    QFile file("data_ascii.txt");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(data);
        file.close();
    }
    qInfo() << "Done.";
}

QString makeDataUTF8() {
    QString data;

    data.append("Unicode test\r\n");
    for (int i=0; i<10; i++) {
        int number = QRandomGenerator::global()->bounded(1112063);
        data.append(QChar(number));
    }
    return data;
}

void utf8() {
    QString data = makeDataUTF8();
    qInfo() << data;
    QFile file("data_utf8.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream.autoDetectUnicode();
        stream << data;
        stream.flush();
        file.close();
    }
    qInfo() << "Done.";
    qInfo() << "UTF8: " << data;
    qInfo() << "ASCII" << data.toLatin1();

}
/* Not fully supported in Qt 5. Can work with Utf16 using auto-detect,
 * but cannot specifically configure embedding = Utf16
QString makeDataUTF16() {
    QString data;
    data.append("Unicode test\r\n");
    for (int i=0; i<10; i++) {
        int number = QRandomGenerator::global()->bounded(1112063);
        data.append(QChar(number));
    }
    return data;
}

// UTF16 is more streamlined than UTF8, but UTF8 plays better with ASCII
void utf16() {
    QString data = makeDataUTF16();
    qInfo() << data;
    QFile file("data_utf16.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream.autoDetectUnicode();
        stream << data;
        stream.flush();
        file.close();
    }
    qInfo() << "Done.";
    qInfo() << "UTF8: " << data.toUtf8();
    qInfo() << "UTF16: " << data;
    qInfo() << "ASCII" << data.toLatin1();
}
*/

QString makeData() {
    QString data;
    for (int i=0; i<10; i++) {
        data.append("Hello\r\n");
    }
    return data;
}

// Comes up often when working with hardware
void base64() {
    QString data = makeData();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded: " << encoded;
    qInfo() << "-----------------------------------";
    qInfo() << "Decoded: " << decoded;
}

void hex() {
    QString data = makeData();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded(bytes.toHex());
    QByteArray decoded(QByteArray::fromHex(encoded));
    qInfo() << "Encoded: " << encoded;
    qInfo() << "-----------------------------------";
    qInfo() << "Decoded: " << decoded;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ascii();
    utf8();
//    utf16();      // not fully supported on older versions of Qt
    base64();
    hex();
    return a.exec();
}
