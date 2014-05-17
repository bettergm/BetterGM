/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionLoadPrevious;
    QAction *actionCommit_Changes;
    QAction *actionCreate_Server;
    QAction *actionJoin;
    QAction *actionView_IP;
    QAction *actionRevert_Changes;
    QAction *actionAssets;
    QAction *actionToolbar;
    QAction *actionSet_Name;
    QAction *actionChat;
    QAction *actionEvents;
    QAction *actionPlay;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuNetwork;
    QMenu *menuGame;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QDockWidget *eventsDock;
    QWidget *eventsDockContents;
    QVBoxLayout *verticalLayout_3;
    QListWidget *eventsList;
    QDockWidget *chatDock;
    QWidget *chatDockContents;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *chatText;
    QLineEdit *chatLine;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(919, 607);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setDockNestingEnabled(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionLoadPrevious = new QAction(MainWindow);
        actionLoadPrevious->setObjectName(QString::fromUtf8("actionLoadPrevious"));
        actionLoadPrevious->setCheckable(true);
        actionLoadPrevious->setChecked(true);
        actionCommit_Changes = new QAction(MainWindow);
        actionCommit_Changes->setObjectName(QString::fromUtf8("actionCommit_Changes"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCommit_Changes->setIcon(icon);
        actionCreate_Server = new QAction(MainWindow);
        actionCreate_Server->setObjectName(QString::fromUtf8("actionCreate_Server"));
        actionJoin = new QAction(MainWindow);
        actionJoin->setObjectName(QString::fromUtf8("actionJoin"));
        actionView_IP = new QAction(MainWindow);
        actionView_IP->setObjectName(QString::fromUtf8("actionView_IP"));
        actionRevert_Changes = new QAction(MainWindow);
        actionRevert_Changes->setObjectName(QString::fromUtf8("actionRevert_Changes"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRevert_Changes->setIcon(icon1);
        actionAssets = new QAction(MainWindow);
        actionAssets->setObjectName(QString::fromUtf8("actionAssets"));
        actionAssets->setCheckable(true);
        actionAssets->setChecked(true);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName(QString::fromUtf8("actionToolbar"));
        actionToolbar->setCheckable(true);
        actionToolbar->setChecked(true);
        actionSet_Name = new QAction(MainWindow);
        actionSet_Name->setObjectName(QString::fromUtf8("actionSet_Name"));
        actionChat = new QAction(MainWindow);
        actionChat->setObjectName(QString::fromUtf8("actionChat"));
        actionChat->setCheckable(true);
        actionChat->setChecked(true);
        actionEvents = new QAction(MainWindow);
        actionEvents->setObjectName(QString::fromUtf8("actionEvents"));
        actionEvents->setCheckable(true);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuNetwork = new QMenu(menuBar);
        menuNetwork->setObjectName(QString::fromUtf8("menuNetwork"));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(48, 32));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMinimumSize(QSize(224, 256));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        eventsDock = new QDockWidget(MainWindow);
        eventsDock->setObjectName(QString::fromUtf8("eventsDock"));
        eventsDockContents = new QWidget();
        eventsDockContents->setObjectName(QString::fromUtf8("eventsDockContents"));
        verticalLayout_3 = new QVBoxLayout(eventsDockContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        eventsList = new QListWidget(eventsDockContents);
        eventsList->setObjectName(QString::fromUtf8("eventsList"));

        verticalLayout_3->addWidget(eventsList);

        eventsDock->setWidget(eventsDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), eventsDock);
        chatDock = new QDockWidget(MainWindow);
        chatDock->setObjectName(QString::fromUtf8("chatDock"));
        chatDockContents = new QWidget();
        chatDockContents->setObjectName(QString::fromUtf8("chatDockContents"));
        verticalLayout_2 = new QVBoxLayout(chatDockContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chatText = new QTextEdit(chatDockContents);
        chatText->setObjectName(QString::fromUtf8("chatText"));
        chatText->setLineWrapMode(QTextEdit::NoWrap);
        chatText->setReadOnly(true);

        verticalLayout_2->addWidget(chatText);

        chatLine = new QLineEdit(chatDockContents);
        chatLine->setObjectName(QString::fromUtf8("chatLine"));

        verticalLayout_2->addWidget(chatLine);

        chatDock->setWidget(chatDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), chatDock);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuNetwork->menuAction());
        menuBar->addAction(menuGame->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionLoadPrevious);
        menuEdit->addAction(actionCommit_Changes);
        menuEdit->addAction(actionRevert_Changes);
        menuView->addAction(actionAssets);
        menuView->addAction(actionToolbar);
        menuView->addAction(actionChat);
        menuView->addAction(actionEvents);
        menuNetwork->addAction(actionCreate_Server);
        menuNetwork->addAction(actionJoin);
        menuNetwork->addSeparator();
        menuNetwork->addAction(actionView_IP);
        menuNetwork->addSeparator();
        menuNetwork->addAction(actionSet_Name);
        menuGame->addAction(actionPlay);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionCommit_Changes);
        mainToolBar->addAction(actionRevert_Changes);
        mainToolBar->addAction(actionCreate_Server);
        mainToolBar->addAction(actionJoin);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BetterGM", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionLoadPrevious->setText(QApplication::translate("MainWindow", "Load Previous", 0, QApplication::UnicodeUTF8));
        actionCommit_Changes->setText(QApplication::translate("MainWindow", "Commit Changes", 0, QApplication::UnicodeUTF8));
        actionCommit_Changes->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", 0, QApplication::UnicodeUTF8));
        actionCreate_Server->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        actionJoin->setText(QApplication::translate("MainWindow", "Join", 0, QApplication::UnicodeUTF8));
        actionView_IP->setText(QApplication::translate("MainWindow", "View IP", 0, QApplication::UnicodeUTF8));
        actionView_IP->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionRevert_Changes->setText(QApplication::translate("MainWindow", "Revert Changes", 0, QApplication::UnicodeUTF8));
        actionRevert_Changes->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionAssets->setText(QApplication::translate("MainWindow", "Resources", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAssets->setToolTip(QApplication::translate("MainWindow", "Show/Hide Resources", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAssets->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", 0, QApplication::UnicodeUTF8));
        actionToolbar->setText(QApplication::translate("MainWindow", "Toolbar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionToolbar->setToolTip(QApplication::translate("MainWindow", "Show/Hide the Toolbar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToolbar->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", 0, QApplication::UnicodeUTF8));
        actionSet_Name->setText(QApplication::translate("MainWindow", "Set Name", 0, QApplication::UnicodeUTF8));
        actionSet_Name->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0, QApplication::UnicodeUTF8));
        actionChat->setText(QApplication::translate("MainWindow", "Chat", 0, QApplication::UnicodeUTF8));
        actionChat->setShortcut(QApplication::translate("MainWindow", "Ctrl+3", 0, QApplication::UnicodeUTF8));
        actionEvents->setText(QApplication::translate("MainWindow", "Events", 0, QApplication::UnicodeUTF8));
        actionEvents->setShortcut(QApplication::translate("MainWindow", "Ctrl+4", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        actionPlay->setShortcut(QApplication::translate("MainWindow", "F5, Ctrl+R", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuNetwork->setTitle(QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Toolbar", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Resources", 0, QApplication::UnicodeUTF8));
        eventsDock->setWindowTitle(QApplication::translate("MainWindow", "Events", 0, QApplication::UnicodeUTF8));
        chatDock->setWindowTitle(QApplication::translate("MainWindow", "Chat", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
