#ifndef Q_DELETEALL_MAP_H
#define Q_DELETEALL_MAP_H

#include <QDebug>
#include <QMap>
#include <QObject>
#include <QString>

class q_deleteall_map : public QObject
{
    Q_OBJECT
public:
    explicit q_deleteall_map(QObject *parent = nullptr, QString name = "");
    ~q_deleteall_map();
    void practice();
};

#endif // Q_DELETEALL_MAP_H
