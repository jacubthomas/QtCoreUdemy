#ifndef Q_SHAREDPTR_W_QLIST_H
#define Q_SHAREDPTR_W_QLIST_H

#include <QDebug>
#include <QList>
#include <QObject>
#include <QSharedPointer>
#include <QString>

class q_sharedptr_w_qlist : public QObject
{
    Q_OBJECT
public:
    q_sharedptr_w_qlist(QObject *parent = nullptr, QString name = "");
    ~q_sharedptr_w_qlist();
    void practice();
private:
};

#endif // Q_SHAREDPTR_W_QLIST_H
