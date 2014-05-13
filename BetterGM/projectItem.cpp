#include "projectItem.h"

ProjectItem::ProjectItem(QTreeWidget *parent) :
    QTreeWidgetItem(parent),
    mIsRoot(false),
    mIsGroup(false),
    mDocumentIndex(-1)
{
    
}

void ProjectItem::setType(Type type) {
    mType = type;
}

void ProjectItem::setPath(const QString &path) {
    mPath = path;
}

void ProjectItem::setText(const QString &txt) {
    QTreeWidgetItem::setText(0, txt);
}

void ProjectItem::setIcon(const QIcon &icon) {
    QTreeWidgetItem::setIcon(0, icon);
}

void ProjectItem::setIsRoot(bool isRoot) {
    mIsRoot = isRoot;
}

void ProjectItem::setIsGroup(bool isGroup) {
    mIsGroup = isGroup;
}

void ProjectItem::setDocumentIndex(int index) {
    mDocumentIndex = index;
}
