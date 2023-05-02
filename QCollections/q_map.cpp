#include "q_map.h"

void q_map::practice()
{
    QMap<QString,int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 37);
    ages.insert("Rango", 15);

    qInfo() << "Keys: " << ages.keys();
    qInfo() << "Values" << ages.values();

    qInfo() << "Bryan is" << ages["Bryan"] << "years old.";

    ages.remove("Rango");
    qInfo() << "Contains Rango" << ages.contains("Rango");

    foreach(QString key, ages.keys()) {
        qInfo() << key << " = " << ages[key];
    }

    qInfo() << "Tammy" << ages.value("Tammy");

    // Since no `Test` key in map, value is `0`. Can provide default value `-1`
    qInfo() << "Test" << ages.value("Test");
    qInfo() << "Test" << ages.value("Test", -1);

    // Since `Bryan` exists in map, default value is not used
    ages["Bryan"] = 99;
    qInfo() << "Bryan" << ages.value("Bryan", -1);

    // Though `Test` is not in map, it inserts automatically with the assigned value
    ages["Test"] = 222;
    qInfo() << "Test" << ages.value("Test", -1);
}
