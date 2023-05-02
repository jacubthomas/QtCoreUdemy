#ifndef Q_SHAREDPTR_W_QMAP_H
#define Q_SHAREDPTR_W_QMAP_H

#include <QDebug>
#include <QMap>
#include <QObject>
#include <QSharedPointer>
#include <QString>

class q_sharedptr_w_qmap : public QObject
{
    Q_OBJECT
public:
    typedef QMap<QString, QSharedPointer<q_sharedptr_w_qmap>> TestMap;
    q_sharedptr_w_qmap(QObject *parent = nullptr, QString name = "");
    ~q_sharedptr_w_qmap();
    TestMap generateMap();
    void printMap(TestMap map);
    void practice();
};

#endif // Q_SHAREDPTR_W_QMAP_H
