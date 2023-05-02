#include "q_stringview.h"

void q_stringview::practice() {
    QString data = "Hello world, how are you today?";

    QStringView view(data);

    display(view);
}

void q_stringview::display(QStringView &view)
{
    qInfo() << view;

    qInfo() << "Size" << view.size();
    qInfo() << "Data" << view.data();
    qInfo() << "Contains" << view.contains(QString("ello"));
    qInfo() << "Count of `l`" << view.count('l');
    qInfo() << "At 1: " << view.at(1);
    qInfo() << "Index[0] " << view[0];
    qInfo() << "IndexOf" << view.indexOf('e');
}

/* Issues with QStringView
 * If you are having issues with QStringView, for example, it is displaying what looks
 * like garbage:
 *      Output: "\u0001\u0000\u0000................."
 * Your strings encoding and the console does not know how to display it correctly.
 * String views are just classes that display a string from a pointer. try:
 *      .toString()
 *      .toLatin1()
 *      .toUtf8()
 * Additionally if you are creating a QString in the constructor you might have to separate the QString from the QStringView"
 *      QStringView Person::display()
 *      {
 *          QString name = QString(m_firstname + " " + m_lastname);
 *          QStringView view(name);
 *          return view;
 *      }
 *  https://doc.qt.io/qt-6/qstringview.html
 */
