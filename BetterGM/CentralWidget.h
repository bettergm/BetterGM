#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QFrame>
#include <QStackedWidget>
#include <QToolBar>

class Titlebar : public QWidget {
    Q_OBJECT
    
public:
    Titlebar(QString title, QWidget *parent = 0);
    
    void setName(const QString &name);
    
public slots:
    void closeCurrentDocumentClicked();
    
signals:
    void closeCurrentDockument();
    
protected:
    void paintEvent(QPaintEvent *);
    
private:
    QString mTitle;
    QHBoxLayout *mLayout;
    QToolBar *mToolbar;
    QLabel *mLabel;
    QComboBox *mBox;
};

class CentralWidget : public QWidget {
    Q_OBJECT
    
public:
    CentralWidget(QWidget *parent = 0);
    
    void addWidget(QWidget *widget, QString name);
    void setCurrentIndex(int index);
    int getCurrentIndex();
    QWidget *getCurrentWidget();
    
    QString getCurrentWidgetName() const;
    
    QStackedWidget *getStack() {
        return mStack;
    }
    
    void setName(QString name);
    
public slots:
    void indexChanged(int index);
    void closeCurrentDocumentClicked();
    
signals:
    void currentChanged(int);
    void closeCurrentDocument(int);
    
private:
    Titlebar *mTitlebar;
    
    QStackedWidget *mStack;
    QStringList mNames;
    
    QVBoxLayout *mLayout;
    
    bool mTitlebarAdded;
    bool mTitlebarHidden;
};

#endif // CENTRALWIDGET_H
