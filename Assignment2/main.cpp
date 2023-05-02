#include "test.h"

Test* getObject(){
    Test* obj = new Test(QString("Tom"));
    qInfo().noquote() << "getObject() - " << obj << " : " << obj->getName();
    return obj;
}

void test(){
    Test* ptr = getObject();
    QSharedPointer<Test> sharedp(ptr);
    QScopedPointer<Test> scopedp(ptr);
    qInfo().noquote() << "test(sharedp) - " << sharedp->getName();
    qInfo().noquote() << "test(scopedp) - " << scopedp->getName();
    delete ptr;
}

/**
 * @brief createSharedPtr - creates and returns a sharedptr to a Test object
 * @return sharedptr<Test>
 */
QSharedPointer<Test> createSharedPtr() {
    qInfo() << "Creating a pointer";
    QSharedPointer<Test> sharedp(new Test(QString("Jim")));
    return sharedp;
}

/**
 * @brief createScopedPtr - creates, but fails to return a scopedptr to a Test object
 * this is due to the nature of scopedptrs; they are deleted as soon as the function
 * that has created them comes to an end. This being said, I have commented out the
 * code that will fail to compile.
 * @return scopedptr<Test>
 */
//QScopedPointer<Test> createScopedPtr() {
//    qInfo() << "Creating a pointer";
//    QScopedPointer<Test> scopedp(new Test(QString("Jim")));
//    return scopedp;
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
