#ifndef TEST_H
#define TEST_H

#include <QSharedPointer>
#include <QScopedPointer>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QCoreApplication>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QString name, QObject* parent = nullptr);
    ~Test();
    QString getName();
private:
    QString m_name;
};

#endif // TEST_H
