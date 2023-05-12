#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QLoggingCategory>
#include <QTextStream>

// Declare a logging category - MACRO
Q_DECLARE_LOGGING_CATEGORY(network);
// Defines a logging category - MACRO
Q_LOGGING_CATEGORY(network, "network");

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

void lhandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

    QString txt;
    switch (type) {
    case QtInfoMsg:
        txt = QString("Info: %1").arg(msg);
        break;
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        break;
    }

    QFile file("log.txt");
    if(file.open(QIODevice::Append)) {
        QTextStream ts(&file);
        ts << QDateTime::currentDateTime().toString() << " - " << txt << " file: " << context.file << " line: " << context.line << "\r\n";
        ts.flush();
        file.close();
    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);

}


// helpful for generating a log file
void interceptLogMessages() {

    qInstallMessageHandler(lhandler);

    qDebug() << "This is a debug";
    qInfo() << "This is an info";
    qWarning() << "This is a warning";
    qCritical() << "This is a critical";
    // qFatals crash the application
    qFatal("This is a fatal");


}

void creatingMessagesWithCategories() {
    qInfo() << "test";
    qInfo(network) << "info test";
    qWarning(network) << "warning test";

    // turn off category for debug
    QLoggingCategory::setFilterRules("network.debug=false");

    // will not log
    qDebug(network) << "debug test";

    if (!network().isDebugEnabled()) {
        QLoggingCategory::setFilterRules("network.debug=true");
        // will log
        qDebug(network) << "we turned back on the debug test";
    }

    qDebug(network) << "yes";
}

void qLoggingWithCategories() {
    // no macro needed
    QLoggingCategory logtest("testing");
    logtest.setEnabled(QtMsgType::QtDebugMsg, false);

    qDebug() << "Debug = " << logtest.isDebugEnabled();
    qInfo() << "Info = " << logtest.isInfoEnabled();
    qWarning() << "Warning = " << logtest.isWarningEnabled();
    qCritical() << "Critical = " << logtest.isCriticalEnabled();

    qDebug(logtest) << "This is a debug";
    qInfo(logtest) << "This is an info";
    qWarning(logtest) << "This is a warning";
    qCritical(logtest) << "This is a critical";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    interceptLogMessages();
    creatingMessagesWithCategories();
    qLoggingWithCategories();

    return a.exec();
}
