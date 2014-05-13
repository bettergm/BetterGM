#include "preferences.h"

#include <QDesktopServices>
#include <QFileInfo>
#include <QDebug>

Preferences *Preferences::mInstance = 0;

Preferences *Preferences::instance() {
    if (!mInstance) {
        mInstance = new Preferences;
    }
    
    return mInstance;
}

void Preferences::deleteInstance() {
    delete mInstance;
    mInstance = 0;
}

Preferences::Preferences() :
    mSettings(new QSettings("LerpCO", "BetterGM"))
{
    mSettings->beginGroup("BetterGM");
        mName = mSettings->value(QLatin1String("UserName")).toString();
        mIP = mSettings->value(QLatin1String("JoinIP")).toString();
        mLoadPrevious = mSettings->value("LoadPrevious").toBool();
        mPreviousPath = mSettings->value("PreviousPath").toString();
        mPreviousItems = mSettings->value("PreviousItems").toStringList();
    mSettings->endGroup();
}

Preferences::~Preferences() {
    delete mSettings;
}

void Preferences::setName(QString name) {
    mName = name;
    mSettings->setValue(QLatin1String("BetterGM/UserName"), mName);
}

void Preferences::setIP(QString ip) {
    mIP = ip;
    mSettings->setValue(QLatin1String("BetterGM/JoinIP"), mIP);
}

void Preferences::setLoadPrevious(bool pre) {
    mLoadPrevious = pre;
    mSettings->setValue(QLatin1String("BetterGM/LoadPrevious"), mLoadPrevious);
}

void Preferences::setPreviousPath(QString path) {
    mPreviousPath = path;
    mSettings->setValue(QLatin1String("BetterGM/PreviousPath"), mPreviousPath);
}

void Preferences::addPreviousItem(QString item) {
    mPreviousItems << item;
    mSettings->setValue(QLatin1String("BetterGM/PreviousItems"), mPreviousItems);
}
