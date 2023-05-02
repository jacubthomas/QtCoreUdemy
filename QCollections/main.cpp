#include <QCoreApplication>
//#include "q_list.h"
//#include "q_map.h"
//#include "q_set.h"
//#include "q_stringlist.h"
//#include "q_deleteall.h"
//#include "q_sharedptr_w_qlist.h"
//#include "q_deleteall_map.h"
#include "q_sharedptr_w_qmap.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Practice with QList/Qvector. */
//    q_list* list = new q_list();
//    list->practice();
//    delete list;

    /* Practice with QSet */
//    q_set* set = new q_set();
//    set->practice();
//    delete set;

    /* Practice with QStringList */
//    q_stringlist* stringlist = new q_stringlist();
//    stringlist->practice();
//    delete stringlist;

    /* Practice with QDeleteAll and QList */
//    q_deleteall* deleteall = new q_deleteall();
//    deleteall->practice();
//    delete deleteall;

    /* Practice deleting a List of SharedPointers to QObjects.
     * There is value in using sharedpointers, so as to prevent leaks/dangling pointers!
     */
//    q_sharedptr_w_qlist* qspwql = new q_sharedptr_w_qlist();
//    qspwql->practice();
//    delete qspwql;

    /* Practice with QDeleteAll and QMap */
//    q_deleteall_map* q_deleteall_map = new class q_deleteall_map();
//    q_deleteall_map->practice();
//    delete q_deleteall_map;

    /* Practice deleting a Map of SharedPointers to QObjects.
     * There is value in using sharedpointers, so as to prevent leaks/dangling pointers!
     */
    q_sharedptr_w_qmap* qspwqm = new q_sharedptr_w_qmap();
    qspwqm->practice();
    delete qspwqm;

    return a.exec();
}
