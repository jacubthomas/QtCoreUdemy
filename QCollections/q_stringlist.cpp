#include "q_stringlist.h"


void q_stringlist::practice()
{
    QStringList names { "Bryan" };
    names << "Tammy" << "Rango";
    names.append("Heather");

    // all occurrences of letter `a` in each string will be replaced with `@`
    names.replaceInStrings("a", "@");
    qInfo() << names;

    // put it back & sort
    names.replaceInStrings("@", "a");
    names.sort();
    qInfo() << names;

    QString people = names.join(",");
    qInfo() << people;

    QStringList mylist = names.filter("r");
    qInfo() << mylist;

    QString me = "Bryan";
    qInfo() << "Contains: " << names.contains(me);
    qInfo() << "Index: " << names.indexOf(me);
    qInfo() << "Value: " << names.at(names.indexOf(me));
}
