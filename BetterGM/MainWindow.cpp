#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTextStream>
#include <QCompleter>
#include <QStringList>
#include <QStringListModel>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QDockWidget>
#include <QLayout>
#include <QMessageBox>
#include <QSettings>
#include <QTextEdit>
#include <QTreeWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QTimer>
#include <QSound>
//#include <QNetworkConfigurationManager>
//#include <QNetworkSession>

#include "codeEditor/highlighter.h"
#include "GetIPDialog.h"
#include "GetNameDialog.h"
#include "JoinDialog.h"

#include "Version.h"

MainWindow *w;

void setMainWindow(MainWindow *mw) {
    w = mw;
}

void catchMessage(QtMsgType type, const QMessageLogContext &, const QString &msg) {
    switch (type) {
    case QtDebugMsg:
        w->debug(msg);
        break;
    case QtWarningMsg:
        w->warn(msg);
        break;
    case QtCriticalMsg:
        w->crit(msg);
        break;
    case QtFatalMsg:
        w->fail(msg);
        break;
    default:
        break;
    }
}

MainWindow::MainWindow(QApplication *a, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mCentralWidget(new CentralWidget(this)),
    mServer(0),
    mLocalClient(0)
{
    ui->setupUi(this);
    
    setCentralWidget(mCentralWidget);
    
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    
    setStyle();
    
    createCodeEditor();
    setUpAssets();
    setUpChat();
    setUpEvents();
    
    mPrefs = Preferences::instance();
    ui->actionLoadPrevious->setChecked(mPrefs->getLoadPrevious());
    
    mUsername = mPrefs->getName();
    mJoinIP = mPrefs->getIP();
    
    connect(ui->actionAssets, SIGNAL(triggered()), this, SLOT(showAssets()));
    connect(ui->actionToolbar, SIGNAL(triggered()), this, SLOT(showToolbar()));
    connect(ui->actionChat, SIGNAL(triggered()), this, SLOT(showChat()));
    connect(ui->actionEvents, SIGNAL(triggered()), this, SLOT(showEvents()));
    connect(ui->dockWidget, SIGNAL(visibilityChanged(bool)), ui->actionAssets, SLOT(setChecked(bool)));
    connect(ui->mainToolBar, SIGNAL(visibilityChanged(bool)), ui->actionToolbar, SLOT(setChecked(bool)));
    connect(ui->chatDock, SIGNAL(visibilityChanged(bool)), ui->actionChat, SLOT(setChecked(bool)));
    connect(ui->eventsDock, SIGNAL(visibilityChanged(bool)), ui->actionEvents, SLOT(setChecked(bool)));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openProject()));
    connect(ui->actionSet_Name, SIGNAL(triggered()), this, SLOT(setName()));
    connect(ui->actionView_IP, SIGNAL(triggered()), this, SLOT(getIP()));
    connect(ui->chatLine, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
    connect(ui->actionCreate_Server, SIGNAL(triggered()), this, SLOT(makeHost()));
    connect(ui->actionJoin, SIGNAL(triggered()), this, SLOT(makeClient()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionLoadPrevious, SIGNAL(triggered()), this, SLOT(setLoadPrevious()));
    connect(ui->actionPlay, SIGNAL(triggered()), this, SLOT(playGame()));
    
    app = a;
    
    showEvents();
    
    mVersion = QString::number(BUILD_NUMBER);
    setWindowTitle("BetterGM Build" + mVersion);
    
    if (mPrefs->getLoadPrevious()) {
        openProject(mPrefs->getPreviousPath());
        
        if (!mPrefs->getPreviousItems().isEmpty()) {
            QString itemPath = mPrefs->getPreviousItems().at(0);
            QString itemName;
            QString tmp;
            
            for (int i = itemPath.length() - 1; i > 0; i--) {
                if (itemPath[i] == '.') {
                    tmp.clear();
                    continue;
                }
                
                if (itemPath[i] != '/' && itemPath[i] != '\\') {
                    tmp += itemPath[i];
                } else {
                    break;
                }
            }
            
            for (int i = tmp.length() - 1; i > 0; i--) {
                itemName += tmp[i];
            }
            
            openItem(itemPath, itemName);
        }
    }
    
    //ro lock the dock in place
    //ui->chatDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    
    installMessageHandler();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::installMessageHandler() {
    qInstallMessageHandler(catchMessage);
}

void MainWindow::debug(const QString &msg) {
    ui->chatText->moveCursor(QTextCursor::End);
    ui->chatText->setTextColor(Qt::cyan);
    ui->chatText->insertPlainText("[debug] ");
    ui->chatText->setTextColor(Qt::white);
    ui->chatText->insertPlainText(QString(msg) + "\n");
}
void MainWindow::warn(const QString &msg) {
    ui->chatText->moveCursor(QTextCursor::End);
    ui->chatText->setTextColor(QColor(230, 219, 116));
    ui->chatText->insertPlainText("[warning] ");
    ui->chatText->setTextColor(Qt::white);
    ui->chatText->insertPlainText(QString(msg) + "\n");
}

void MainWindow::crit(const QString &msg) {
    ui->chatText->moveCursor(QTextCursor::End);
    ui->chatText->setTextColor(Qt::red);
    ui->chatText->insertPlainText("[critical] ");
    ui->chatText->setTextColor(Qt::white);
    ui->chatText->insertPlainText(QString(msg) + "\n");
}

void MainWindow::fail(const QString &msg) {
    ui->chatText->moveCursor(QTextCursor::End);
    ui->chatText->setTextColor(Qt::red);
    ui->chatText->insertPlainText("[fatal] ");
    ui->chatText->setTextColor(Qt::white);
    ui->chatText->insertPlainText(QString(msg) + "\n");
}

ProjectItem *MainWindow::addRoot(QString name, ProjectItem::Type type) {
    ProjectItem *itm = new ProjectItem(ui->treeWidget);
    itm->setText(name);
    itm->setType(type);
    itm->setIsRoot(true);

    return itm;
}

void MainWindow::addChild(ProjectItem *parent, ProjectItem::Type type, QString path, QString name, QIcon &icon) {
    ProjectItem *itm = new ProjectItem();
    itm->setText(name);
    itm->setIcon(icon);
    itm->setType(type);
    itm->setPath(path);
    //itm->setDocumentIndex(mCurrentProjectItmDocumentIndex);
    parent->addChild(itm);
    //TODO: check preferences
    parent->sortChildren(0, Qt::AscendingOrder);
    
    //mCurrentProjectItmDocumentIndex = -1;
}

void MainWindow::addChild(ProjectItem *parent, ProjectItem *child) {
    parent->addChild(child);
}

void MainWindow::setStyle() {
    QFile *style = new QFile(":/style/Dark.qss");
    QString str;
    
    if (style->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(style);
        str = in.readAll();
    }
    
    style->close();
    delete style;
    
    setStyleSheet(str);
}

void MainWindow::createCodeEditor() {
    mCodeEditor = new CodeEditor("Untitled.gml", this);
    mCodeEditor->setUndoRedoEnabled(true);
    mCodeEditor->setTabStopWidth(29);
    
#ifdef Q_OS_WIN
    int size = 10;
    QFont font("Consolas", size);
#endif
    
#ifdef Q_OS_MAC
    int size = 12;
    QFont font("Monaco", size);
#endif
    
    mCodeEditor->setFont(font);
    new Highlighter(mCodeEditor->document());
    mCompleter = new QCompleter();
    
    QDir dir = QDir::current();
#ifndef Q_OS_MAC
    QString path = dir.path() + "/autocompleteWords.txt";
#else
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    QString path = dir.path() + "/autocompleteWords.txt";
#endif
    mCompleter->setModel(modelFromFile(path));
    mCompleter->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    mCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    mCompleter->setWrapAround(false);
    mCompleter->popup()->setStyleSheet("color: #848484;"
                                       "background-color: #2E2E2E;"
                                       "selection-background-color: #424242;"
                                       "alternate-background-color: #292929;");
    mCompleter->popup()->setAlternatingRowColors(true);
    mCodeEditor->setCompleter(mCompleter);
    
    connect(mCodeEditor, SIGNAL(cursorPosition(int)), SLOT(getCursorPosition(int)));
    connect(mCodeEditor, SIGNAL(pressed(QString)), this, SLOT(keyPressed(QString)));
    
    mCentralWidget->addWidget(mCodeEditor, mCodeEditor->getName());
    mCodeEditor->setFocus();
    mCodeEditor->updateCorner();
}

void MainWindow::setUpAssets() {
    ui->treeWidget->setIconSize(QSize(18, 18));
    ui->dockWidgetContents->layout()->setContentsMargins(0, 0, 0, 0);
    
    mObjs = addRoot("  Objects", ProjectItem::Object);
    mScripts = addRoot("Scripts", ProjectItem::Script);
    
    mObjs->setIcon(QIcon(":/res/object.png"));
    mScripts->setIcon(QIcon(":/res/script_icon.png"));
    
    ui->treeWidget->setAttribute(Qt::WA_MacShowFocusRect, false);
    
    connect(ui->treeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(openItem(QTreeWidgetItem*,int)));
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(openItem(QTreeWidgetItem*,int)));
}

void MainWindow::setUpChat() {
    ui->chatText->setFrameStyle(QFrame::NoFrame);
    ui->chatDockContents->layout()->setContentsMargins(0, 0, 0, 0);
    ui->chatDockContents->layout()->setSpacing(0);
    ui->chatLine->setAttribute(Qt::WA_MacShowFocusRect, false);
    
    ui->chatText->setTabStopWidth(29);
    
#ifdef Q_OS_WIN
    int size = 10;
    QFont font("Consolas", size);
#endif
    
#ifdef Q_OS_MAC
    int size = 12;
    QFont font("Monaco", size);
#endif
    
    ui->chatText->setFont(font);
    
    new Highlighter(ui->chatText->document(), true);
}

void MainWindow::setUpEvents() {
    ui->eventsList->setFrameStyle(QFrame::NoFrame);
    ui->eventsDockContents->layout()->setContentsMargins(0, 0, 0, 0);
    ui->eventsList->setAttribute(Qt::WA_MacShowFocusRect, false);
}

QAbstractItemModel *MainWindow::modelFromFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "no open is a sad";
        return new QStringListModel(mCompleter);
    }

    QStringList words;
    
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty()) {
            words << line.trimmed();
        }
    }
    
    words.sort();
    
    return new QStringListModel(words, mCompleter);
}

void MainWindow::openProject() {
    QString dir = QDir::homePath() + "/Documents";
    QString fiel = QFileDialog::getOpenFileName(this, tr("Choose a project to open"), dir, tr("GM Studio Project files (*.project.gmx)"));
    mGamePath = fiel;
    openProject(mGamePath);
}

void MainWindow::openProject(QString project) {
    QString fiel = project;
    QString path = "";
    QString temp = "";
    mName = "";
    
    if (fiel.isEmpty()) {
        return;
    }
    
    mPrefs->setPreviousPath(fiel);
    
    for (int i = fiel.length() - 1; i >= 0; i--) {
        QChar c = fiel.at(i);
        if (c == '/' || c == '\'') {
            break;
        }
        
        temp += c;
    }
    
    for (int i = temp.length() - 1; i >= 0; i--) {
        mName += temp.at(i);
    }
    
    path = fiel;
    if (path.contains(mName)) {
        path.remove(mName);
    }
    
    QDir objDir(path + "objects");
    QDir scriptsDir(path + "scripts");
    
    QStringList objList = objDir.entryList();
    QStringList scriptsList = scriptsDir.entryList();
    
    QIcon objIcon = QIcon(":/res/object.png");
    QIcon scriptIcon = QIcon(":/res/script_icon.png");
    
    for (int i = 0; i < objList.count(); i++) {
        QString name = objList.at(i);
        if (name.contains(".object.gmx")) {
            QString treeName = "";
            
            for (int i = 0; i < name.length(); i++) {
                QChar c = name.at(i);
                
                if (c == '.') {
                    break;
                }
                
                treeName += c;
            }
            
            addChild(mObjs, ProjectItem::Object, objDir.path() + "/" + name, treeName, objIcon);
        }
    }
    
    for (int i = 0; i < scriptsList.count(); i++) {
        QString name = scriptsList.at(i);
        QString treeName;
        if (name.contains(".gml")) {
            for (int i = 0; i < name.length(); i++) {
                QChar c = name.at(i);
                
                if (c == '.') {
                    break;
                }
                
                treeName += c;
            }
            
            addChild(mScripts, ProjectItem::Script, scriptsDir.path() + "/" + name, treeName, scriptIcon);
        }
    }
    
    QString tmp = mName;
    mName = "";
    
    for (int i = 0; i < tmp.length(); i++) {
        QChar c = tmp.at(i);
        
        if (c == '.') {
            break;
        }
        
        mName += c;
    }
    
    mObjs->setExpanded(true);
    mScripts->setExpanded(true);
    
    setWindowTitle("BetterGM Build " + mVersion + ": " + mName);
}

void MainWindow::openItem(QTreeWidgetItem *item, int) {
    ProjectItem *itm = (ProjectItem*)item;
    
    if (itm->getType() == ProjectItem::Script) {
        openItem(itm->getPath(), itm->text(0));
    }
}

void MainWindow::openItem(QString path, QString name) {
    mCurrentItemPath = path;
    QFile file(mCurrentItemPath);
    
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        
        mPrefs->getPreviousItems().clear();
        mPrefs->addPreviousItem(path);
        
        mCodeEditor->setPlainText(in.readAll());
        mCodeEditor->setName(name + ".gml");
        mCentralWidget->setName(mCodeEditor->getName());
        mCodeEditor->updateCorner();
        
        if (mCodeEditor->cursorCount() == 0 && false) {
            QTextCursor cur(mCodeEditor->document());
            cur.setPosition(200);
            mCodeEditor->addCursor("bob", cur);
            cur = QTextCursor(mCodeEditor->document());
            cur.setPosition(400);
            mCodeEditor->addCursor("ted", cur);
        }
    }
}

void MainWindow::saveFile() {
    if (!mServer) {
        QMessageBox::information(this, tr("Save"), tr("You can only save if you are hosting!"));
        return;
    }
    
    QFile file(mCurrentItemPath);
    
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        
        out << mCodeEditor->getCode();
        
        file.flush();
        file.close();
    }
}

void MainWindow::makeHost() {
    mServer = new Server(this);
    mServer->setName(mUsername);
    connect(mServer, SIGNAL(newIP(QString)), this, SLOT(newIP(QString)));
    connect(mServer, SIGNAL(newPort(QString)), this, SLOT(newPort(QString)));
    connect(mServer, SIGNAL(newMessage(QString,QString)), this, SLOT(recieveMessage(QString,QString)));
    connect(mServer, SIGNAL(serverCursorMoved(QString,int)), this, SLOT(clientCursorMoved(QString,int)));
    connect(mServer, SIGNAL(addUser(QString)), this, SLOT(addUser(QString)));
    connect(mServer, SIGNAL(serverKeyPressed(QString,QString)), this, SLOT(clientKeyPressed(QString,QString)));
    mServer->start();
}

void MainWindow::makeClient() {
    JoinDialog *jd = new JoinDialog(mJoinIP ,this);
    QStringList ipAndPort = jd->getIPAndPort();
    
    if (ipAndPort.isEmpty()) {
        return;
    }
    
    mJoinIP = ipAndPort.at(0);
    mPrefs->setIP(mJoinIP);
    
    mLocalClient = new Client(ipAndPort.at(0), ipAndPort.at(1), this);
    connect(mLocalClient, SIGNAL(newMessage(QString,QString)), this, SLOT(recieveMessage(QString,QString)));
    connect(mLocalClient, SIGNAL(clientCursorMoved(QString,int)), this, SLOT(clientCursorMoved(QString,int)));
    connect(mLocalClient, SIGNAL(addUser(QString)), this, SLOT(addUser(QString)));
    connect(mLocalClient, SIGNAL(clientKeyPressed(QString,QString)), this, SLOT(clientKeyPressed(QString,QString)));
    
    mLocalClient->tryConnect();
}

void MainWindow::showAssets() {
    ui->dockWidget->setVisible(ui->actionAssets->isChecked());
}

void MainWindow::showToolbar() {
    ui->mainToolBar->setVisible(ui->actionToolbar->isChecked());
}

void MainWindow::showChat() {
    ui->chatDock->setVisible(ui->actionChat->isChecked());
}

void MainWindow::showEvents() {
    ui->eventsDock->setVisible(ui->actionEvents->isChecked());
}

void MainWindow::setName() {
    GetNameDialog *g = new GetNameDialog(mUsername, this);
    
    mUsername = g->getName();
    
    if (mUsername.isEmpty()) {
        mUsername = "NoName" + QString::number(qrand());
    }

    mPrefs->setName(mUsername);
}

void MainWindow::sendMessage() {
    if (mUsername.isEmpty()) {
        QMessageBox::information(this, tr("Username"), tr("You must set your username to do that!"), QMessageBox::Ok);
        setName();
        return;
    }
    
    if (ui->chatLine->text().isEmpty()) {
        return;
    }
    
    ui->chatText->moveCursor(QTextCursor::End);
    ui->chatText->setTextColor(Qt::cyan);
    ui->chatText->insertPlainText("[" + mUsername + "] ");
    ui->chatText->setTextColor(Qt::white);
    ui->chatText->insertPlainText(ui->chatLine->text() + "\n");
    
    if (mServer) {
        mServer->sendMessage("0 " + mUsername + "(Host)", ui->chatLine->text());
    }
    
    if (mLocalClient) {
        mLocalClient->sendMessage("0 " + mUsername, ui->chatLine->text());
    }
    
    ui->chatLine->clear();
}

void MainWindow::recieveMessage(QString from, QString msg) {
    if (from.isEmpty() || msg.isEmpty()) {
        qDebug() << "from" << from << "msg" << msg;
        return;
    }
    
    ui->chatText->moveCursor(QTextCursor::End);
    ui->chatText->setTextColor(Qt::cyan);
    ui->chatText->insertPlainText("[" + from + "] ");
    ui->chatText->setTextColor(Qt::white);
    ui->chatText->insertPlainText(msg + "\n");
    
    QSound::play(":/res/bloop.mp3");
}

void MainWindow::clientCursorMoved(QString client, int pos) {
    //qDebug() << "move" << client << pos;
    mCodeEditor->moveClientCursor(client, pos);
}

void MainWindow::clientKeyPressed(QString client, QString key) {
    mCodeEditor->clientKeyPressed(client, key);
}

void MainWindow::addUser(QString user) {
    //qDebug() << "add" << user;
    QTextCursor cursor(mCodeEditor->document());
    cursor.setPosition(0);
    mCodeEditor->addCursor(user, cursor);
}

void MainWindow::getIP() {
    GetIPDialog *ip = new GetIPDialog(this);
    ip->exec();
}

void MainWindow::newIP(QString ip) {
    qDebug() << "ip =" << ip;
}

void MainWindow::newPort(QString port) {
    qDebug() << "port =" << port;
}

void MainWindow::setLoadPrevious() {
    mPrefs->setLoadPrevious(ui->actionLoadPrevious->isChecked());
}

void MainWindow::setCanSendFalse(QString) {
    disconnect(ui->chatLine, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
}

void MainWindow::setCanSendTrue(QString) {
    connect(ui->chatLine, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
}

void MainWindow::getCursorPosition(int pos) {
    if (mServer) {
        mServer->sendMessage("1 " + mUsername, QString::number(pos));
    } else if (mLocalClient) {
        mLocalClient->sendMessage("1 " + mUsername, QString::number(pos));
    }
}

void MainWindow::keyPressed(QString key) {
    if (key.isEmpty()) {
        return;
    }
    
    if (mServer) {
        mServer->sendMessage("6 " + mUsername, key);
    } else if (mLocalClient) {
        mLocalClient->sendMessage("6 " + mUsername, key);
    }
}

void MainWindow::readGameOut() {
    QString r = mGame->readAll();
    qDebug() << r;
}

void MainWindow::playGame() {
    QString cmd = "C:/Users/Skyler/AppData/Roaming/GameMaker-Studio/Runner.exe";
    QStringList options;
    //options << "-game";
    //options << "C:\\Users\\Skyler\\AppData\\Local\\Temp\\gm_ttt_97780\\gm_ttt_39344\\Islands2.win";
    //options << mGamePath;
    
    
    cmd = "C:/Users/Skyler/AppData/Roaming/GameMaker-Studio/GMAssetCompiler.exe";
    //cmd = "C:/Users/Skyler/AppData/Roaming/GameMaker-Studio/GameMaker-Studio.exe";
    options << "/c";
    options << "/m=win";
    options << "/config=\"Default\"";
    options << "/tgt=64";
    options << "/tg=\"C:\\Users\\Skyler\\Documents\\GameMaker\\tmp\\gm_ttt_89439\\TextureGroups.txt\"";
    options << "/to=\"C:\\Users\\Skyler\\Documents\\GameMaker\\tmp\\gm_ttt_89439\\TextureOptions.txt\"";
    options << "/obob=True";
    options << "/obpp=False";
    options << "/obru=True";
    options << "/obes=False";
    options << "/i=2";
    options << "/cvm";
    options << "/tp=2048";
    options << "/mv=1";
    options << "/iv=0";
    options << "/rv=0";
    options << "/bv=1307";
    options << "/gn=\"Islands2\"";
    options << "/td=\"C:\\Users\\Skyler\\Documents\\GameMaker\\tmp\"";
    options << "/cd=\"C:\\Users\\Skyler\\Documents\\GameMaker\\Cache\"";
    options << "/sh=True";
    options << "/o=\"C:\\Users\\Skyler\\Documents\\GameMaker\\tmp\\gm_ttt_89439\\gm_ttt_99859\"";
    options << "C:\\Users\\Skyler\\Dropbox\\Humanity\\Islands2.gmx\\Islands2.project.gmx";
    
    qDebug() << "cmd" << cmd;
    qDebug() << "options //" << options;
    
    mGame = new QProcess(this);
    connect(mGame, SIGNAL(readyRead()), this, SLOT(readGameOut()));
    mGame->start(cmd, options);
}
