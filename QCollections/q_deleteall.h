#ifndef Q_DELETEALL_H
#define Q_DELETEALL_H

#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>

class q_deleteall : public QObject
{
    Q_OBJECT
public:
    explicit q_deleteall(QObject *parent = nullptr, QString name = "");
    ~q_deleteall();
    void practice();

private:
    QString m_name;

};

#endif // Q_DELETEALL_H
