#include "test.h"

Test::Test(QString name, QObject *parent)
{
    m_name = name;
    qInfo() << "Constructed " << this;
}

Test::~Test()
{
    qInfo() << "Garbage Collected " << this;
}

QString Test::getName()
{
    return m_name;
}
