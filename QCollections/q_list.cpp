#include "q_list.h"

void q_list::practice() {
    QList<int> list;

    // easy append
    list << 1 << 2 << 3;

    for(int i=0; i<5; i++) {
        list.append(i);
    }

    qInfo() << list;

    qInfo() << "length" << list.length();
    qInfo() << "size" << list.size();
    qInfo() << "count()" << list.count();
    qInfo() << "count(4)" << list.count(4);

    list.replace(2, 99);

    list << 3 << 3 << 3;

    qInfo() << list;

    list.removeAll(3);

    qInfo() << list;


    //    foreach(int i, list) {
    //        qInfo() << i;
    //    }

    qInfo() << "List contains 6?" << list.contains(6);
    qInfo() << "Index of 6 in list" << list.indexOf(6);

    list.clear();
    qInfo() << "size" << list.size();
}
