#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QObject>
#include <QSettings>
#include <QStringList>

class Preferences : public QObject {
    Q_OBJECT
    
public:
    static Preferences *instance();
    static void deleteInstance();
    
    void setName(QString name);
    QString getName() {
        return mName;
    }
    
    void setIP(QString ip);
    QString getIP() {
        return mIP;
    }
    
    void setLoadPrevious(bool pre);
    bool getLoadPrevious() {
        return mLoadPrevious;
    }
    
    void setPreviousPath(QString path);
    QString getPreviousPath() {
        return mPreviousPath;
    }
    
    void addPreviousItem(QString item);
    QStringList getPreviousItems() {
        return mPreviousItems;
    }
    
    QSettings *settings() const {
        return mSettings;
    }
    
private:
    Preferences();
    ~Preferences();
    
    QSettings *mSettings;
    
    QString mName;
    QString mIP;
    bool mLoadPrevious;
    QString mPreviousPath;
    QStringList mPreviousItems;
    
    static Preferences *mInstance;
};

#endif // PREFERENCES_H
