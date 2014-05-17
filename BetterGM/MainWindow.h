#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define DO_NETWORK

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QProcess>

#include "codeEditor/codeEditor.h"
#include "projectItem.h"

#include "Server.h"
#include "Client.h"

#include "preferences.h"

#include "CentralWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QApplication *a, QWidget *parent = 0);
    ~MainWindow();
    
    void installMessageHandler();
    void debug(const char* msg);
    void warn(const char* msg);
    void crit(const char* msg);
    void fail(const char* msg);
    
    ProjectItem /*QTreeWidgetItem*/ *addRoot(QString name, ProjectItem::Type type);
    void addChild(ProjectItem /*QTreeWidgetItem*/ *parent, ProjectItem::Type type, QString path, QString name, QIcon &icon);
    void addChild(ProjectItem /*QTreeWidgetItem*/ *parent, ProjectItem /*QTreeWidgetItem*/ *child);
    
    void setStyle();
    void createCodeEditor();
    
    void setUpAssets();
    void setUpChat();
    void setUpEvents();
    
    QAbstractItemModel *modelFromFile(const QString &fileName);
    
public slots:
    void openProject();
    void openProject(QString project);
    void openItem(QTreeWidgetItem *item, int);
    void openItem(QString path, QString name);
    
    void showAssets();
    void showToolbar();
    void showChat();
    void showEvents();
    
    void setName();
    
    void sendMessage();
    void recieveMessage(QString from, QString msg);
    void clientCursorMoved(QString client, int pos);
    void addUser(QString user);
    
    void getIP();
    void newIP(QString ip);
    void newPort(QString port);
    
    void makeHost();
    void makeClient();
    
    void saveFile();
    
    void setLoadPrevious();
    void setCanSendFalse(QString);
    void setCanSendTrue(QString);
    
    void getCursorPosition(int pos);
    
    void readGameOut();
    void playGame();
    
    void keyPressed(QString key);
    void clientKeyPressed(QString client, QString key);
    
private:
    Ui::MainWindow *ui;
    
    CentralWidget *mCentralWidget;
    CodeEditor *mCodeEditor;
    QCompleter *mCompleter;
    
    ProjectItem *mObjs;
    ProjectItem *mScripts;
    
    QString mName; //project name
    QString mUsername;
    QString mJoinIP;
    
    QApplication *app;
    
    Server *mServer;
    Client *mLocalClient;
    
    QString mCurrentItemPath;
    
    Preferences *mPrefs;
    
    QString mVersion;
    
    QProcess *mGame;
    QString mGamePath;
};

void setMainWindow(MainWindow *mw);
void catchMessage(QtMsgType type, const char *msg);

#endif // MAINWINDOW_H
