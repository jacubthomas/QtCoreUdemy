#include "q_deleteall.h"


q_deleteall::q_deleteall(QObject *parent, QString name) : m_name(name)
{
    qInfo() << "Constructed" << this->m_name;
}

q_deleteall::~q_deleteall()
{
    qInfo() << "Garbage collected" << this->m_name;

}

void q_deleteall::practice()
{
    QList<q_deleteall*> list;

    for (int i=0; i<5; i++) {
        list.append(new q_deleteall(nullptr, "Item" + QString::number(i)));
    }

    foreach(q_deleteall* element, list) {
        qInfo() << element;
    }

    // frees all pointers in list, but does not remove items from the list
    qDeleteAll(list);
    qInfo() << "list size =" << list.size();

    /* dangling pointer - trying access memory which has been freed.
     * This will crash your program!
     *
     * qInfo() << list.at(0);
     */

    // this should accompany qDeleteAll
    list.clear();

    qInfo() << "list size =" << list.size();
}
