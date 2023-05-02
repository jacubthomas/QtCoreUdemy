#include "q_sharedptr_w_qmap.h"

q_sharedptr_w_qmap::q_sharedptr_w_qmap(QObject *parent, QString name)
{
    this->setObjectName(name);
    qInfo() << "Constructed" << this;
}

q_sharedptr_w_qmap::~q_sharedptr_w_qmap()
{
    qInfo() << "Garbage collected" << this;
}

void q_sharedptr_w_qmap::printMap(TestMap map) {
    foreach (QString key, map.keys()) {
        qInfo() << key << ":" << map[key];
    }
}


q_sharedptr_w_qmap::TestMap q_sharedptr_w_qmap::generateMap() {
    q_sharedptr_w_qmap::TestMap map;

    for (int i=0; i<5; i++) {
        QString key = QString::number(i);
        QString name = "Item-" + QString::number(i);
        QSharedPointer<q_sharedptr_w_qmap> ptr(new q_sharedptr_w_qmap(nullptr, name));
        map.insert(key, ptr);
    }
    return map;
}

void q_sharedptr_w_qmap::practice()
{
    q_sharedptr_w_qmap::TestMap map = generateMap();
    printMap(map);

    qInfo() << "Deleting one key/pair";
    map.remove(QString::number(2));
    printMap(map);

    qInfo() << "Clearing map";

    map.clear();
}

