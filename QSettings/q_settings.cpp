#include "q_settings.h"

void q_settings::practice()
{
//    part1();
//    part2();
//    part3();
    assignment();
}

void q_settings::info(QSettings &settings)
{
    qInfo() << "File:" << settings.fileName();
    qInfo() << "Keys:" << settings.allKeys();
}

void q_settings::load(QSettings &settings)
{
    //    qInfo() << settings.value("test", 222); // with defaultValue
    qInfo() << settings.value("test").toString();
    bool ok;
    qInfo() << settings.value("test").toInt(&ok);
    if (!ok) {
        // something bad happened
        qInfo() << "Could not convert to int";
    }
}

// simple save
void q_settings::save(QSettings &settings)
{
    settings.setValue("test", 123);
    qInfo() << settings.status();
    qInfo() << "Saved";
}

// save an age for a member of a particular group
void q_settings::saveAge(QSettings *setting, QString group, QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name, age);
    setting->endGroup();
}


// retrieve an age for a member of a particular group - print errors
int q_settings::getAge(QSettings* setting, QString group, QString name)
{
    setting->beginGroup(group);

    if(!setting->contains(name)) {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    if(!ok) {
        qWarning() << "Could not convert to int";
        setting->endGroup();
        return 0;
    }
    setting->endGroup();
    return value;
}

// Check if a given file exists from the member path filename
bool q_settings::checkFileExists()
{
    QFileInfo check_file(this->filename);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        qInfo() << "Settings file already exists!";
        return true;
    } else {
        qInfo() << "Settings file does not already exist!";
        return false;
    }
}

// use a simple save
void q_settings::part1 () {
    QSettings settings(QCoreApplication::organizationName(),
                       QCoreApplication::applicationName());
    /* PART 1: QSettings */
    if (settings.allKeys().length() == 0) {
        qInfo() << "No settings... saving...";
        save(settings);
    } else {
        qInfo() << "Loading the settings...";
        load(settings);
    }

    info(settings);
}

// use a more sophisticated save, across multiple groups
void q_settings::part2 () {
    QSettings settings(QCoreApplication::organizationName(),
                       QCoreApplication::applicationName());
    /* PART 2: QSettings with Groups */
    saveAge(&settings, "people", "Bryan", 44);
    saveAge(&settings, "beer", "twoheart", 1);
    saveAge(&settings, "beer", "Bryan", 11);

    QStringList people;
    people << "Bryan" << "Tammy" << "Heather" << "Chris";

    foreach(QString person, people) {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings, "test", person, value);
    }

    // MANUALLY FORCE A SAVE
    settings.sync();
    qInfo() << "File:" << settings.fileName();

    foreach(QString group, settings.childGroups()) {
        settings.beginGroup(group);

        qInfo() << "Group:" << group;
        foreach(QString key, settings.childKeys()) {
            qInfo() << "... key:" << key << " = " << settings.value(key).toString();
        }

        settings.endGroup();
    }
}

// Continuation of part2, but writing QSettings to a specific filepath for easy retrieval
void q_settings::part3 () {
    // Control where the settings are stored - at path specified by filename
    // IniFormat is a flat file; NativeFormat is platform specific
    QSettings settings (this->filename, QSettings::Format::IniFormat);

    /* PART 2: QSettings: Setting the filename */
    saveAge(&settings, "people", "Bryan", 44);
    saveAge(&settings, "beer", "twoheart", 1);
    saveAge(&settings, "beer", "Bryan", 11);

    QStringList people;
    people << "Bryan" << "Tammy" << "Heather" << "Chris";

    foreach(QString person, people) {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings, "test", person, value);
    }

    // MANUALLY FORCE A SAVE
    settings.sync();
    qInfo() << "File:" << settings.fileName();

    foreach(QString group, settings.childGroups()) {
        settings.beginGroup(group);

        qInfo() << "Group:" << group;
        foreach(QString key, settings.childKeys()) {
            qInfo() << "... key:" << key << " = " << settings.value(key).toString();
        }

        settings.endGroup();
    }
}


// Program demonstrating persistence of state. Run once to write settings and again to retrieve
void q_settings::assignment()
{
    // Control where the settings are stored - at path specified by filename
    // IniFormat is a flat file; NativeFormat is platform specific
    bool exists = checkFileExists();
    QString group = "config";
    QString name = "jacubthomas";
    if (exists) {
        qInfo() << "... Loading ...";
        QSettings settings (this->filename, QSettings::Format::IniFormat);

        int age = getAge(&settings, group, name);

        qInfo() << name << "is" << age;

    } else {
        qInfo() << "... Writing settings ...";
        QSettings settings (this->filename, QSettings::Format::IniFormat);

        saveAge(&settings, group, name, 30);
    }
}
