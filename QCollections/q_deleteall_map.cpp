#include "q_deleteall_map.h"

q_deleteall_map::q_deleteall_map(QObject *parent, QString name)
{
    this->setObjectName(name);
    qInfo() << "Constructed" << this;
}

q_deleteall_map::~q_deleteall_map()
{
    qInfo() << "Garbage collected" << this;
}

void q_deleteall_map::practice()
{
    QMap<QString,q_deleteall_map*> map;

    for (int i = 0; i < 5; i++) {
        QString id = "ID-" + QString::number(i);
        QString name = "Item-" + QString::number(i);
        map.insert(id, new q_deleteall_map(nullptr, name));
    }

    foreach(QString key, map.keys()) {
        qInfo() << key << map[key];
    }

    qDeleteAll(map);
    // qInfo() << map["ID-0"] is a dangling pointer!
    map.clear();
}
