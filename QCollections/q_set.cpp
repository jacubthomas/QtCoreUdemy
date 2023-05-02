#include "q_set.h"

void q_set::practice()
{
    QSet<QString> people;
    people << "Bryan" << "Tammy" << "Chris" << "Heather";
    people.insert("Rango");

    // only one Bryan allowed in set, no two occurrences will appear
    people.insert("Bryan");

    foreach(QString person, people) {
        qInfo() << person;
    }

    qInfo() << "Bryan in collection?" << people.contains("Bryan");
    qInfo() << "size" << people.size();

}
