#ifndef Q_SETTINGS_H
#define Q_SETTINGS_H

#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QRandomGenerator>
#include <QSettings>
#include <QStringList>

class q_settings
{
public:
    q_settings(QString file) : filename(file) {};
    ~q_settings(){};
    void practice();
    void part1();
    void part2();
    void part3();
    void assignment();
    void info(QSettings &settings);
    void load(QSettings &settings);
    void save(QSettings &settings);
    void saveAge(QSettings *setting, QString group, QString name, int age);
    int getAge(QSettings* setting, QString group, QString name);
    bool checkFileExists();


private:
    QString filename;
};

#endif // Q_SETTINGS_H

