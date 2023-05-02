#ifndef Q_STRINGVIEW_H
#define Q_STRINGVIEW_H

#include <QDebug>
#include <QString>
#include <QStringView>

class q_stringview
{
public:
    q_stringview(){};
    ~q_stringview(){};
    void practice();
    void display(QStringView &view);
};

#endif // Q_STRINGVIEW_H
