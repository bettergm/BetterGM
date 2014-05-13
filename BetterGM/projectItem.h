#ifndef PROJECTITEM_H
#define PROJECTITEM_H

#include <QString>
#include <QTreeWidgetItem>

class ProjectItem : public QTreeWidgetItem {
public:
    enum Type {
        NONE = 0,
        Sprite,
        Tileset,
        Font,
        Sound,
        Script,
        Object,
        ObjectSheet,
        Map,
        World,
        Particle,
        Behavior,
        Transition,
        Favorite,
        Idea,
        Extension,
        
        INVALID = -1
    };
    
    ProjectItem(QTreeWidget *parent = 0);
    
    void setType(Type type);
    
    Type getType() {
        return mType;
    }
    
    void setPath(const QString &path);
    
    QString getPath() const {
        return mPath;
    }
    
    void setText(const QString &txt);
    void setIcon(const QIcon &icon);
    
    bool isRoot() {
        return mIsRoot;
    }
    void setIsRoot(bool isRoot);
    
    bool isGroup() {
        return mIsGroup;
    }
    void setIsGroup(bool isGroup);
    
    int getDocumentIndex() {
        return mDocumentIndex;
    }
    void setDocumentIndex(int index);
    
private:
    Type mType;
    QString mPath;
    
    bool mIsRoot;
    bool mIsGroup;
    
    int mDocumentIndex;
};

#endif // PROJECTITEM_H
