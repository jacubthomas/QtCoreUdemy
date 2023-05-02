#include "q_sharedptr_w_qlist.h"

q_sharedptr_w_qlist::q_sharedptr_w_qlist(QObject *parent, QString name)
{
    this->setObjectName(name);
    qInfo() << "Constructed" << this;
}

q_sharedptr_w_qlist::~q_sharedptr_w_qlist()
{
    qInfo() << "Garbage collected" << this;
}

void q_sharedptr_w_qlist::practice()
{
    QList<QSharedPointer<q_sharedptr_w_qlist>> list;

    for (int i=0; i<5; i++) {
        QSharedPointer<q_sharedptr_w_qlist> item(
            new q_sharedptr_w_qlist(nullptr, "Item" + QString::number(i)));
    }

    foreach(QSharedPointer<q_sharedptr_w_qlist> element, list) {
        qInfo() << element.data();
    }

    /* Here we see there power of smart pointers. Whether we remove an item or
     * clear the entire list, memory is managed for us without leak.
     */
    qInfo() << "Remove one item";
    list.removeAt(0);
    qInfo() << "Clearing";
    list.clear();

}
