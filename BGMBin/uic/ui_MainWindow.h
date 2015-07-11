/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(919, 607);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setDockNestingEnabled(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionLoadPrevious = new QAction(MainWindow);
        actionLoadPrevious->setObjectName(QStringLiteral("actionLoadPrevious"));
        actionLoadPrevious->setCheckable(true);
        actionLoadPrevious->setChecked(true);
        actionCommit_Changes = new QAction(MainWindow);
        actionCommit_Changes->setObjectName(QStringLiteral("actionCommit_Changes"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCommit_Changes->setIcon(icon);
        actionCreate_Server = new QAction(MainWindow);
        actionCreate_Server->setObjectName(QStringLiteral("actionCreate_Server"));
        actionJoin = new QAction(MainWindow);
        actionJoin->setObjectName(QStringLiteral("actionJoin"));
        actionView_IP = new QAction(MainWindow);
        actionView_IP->setObjectName(QStringLiteral("actionView_IP"));
        actionRevert_Changes = new QAction(MainWindow);
        actionRevert_Changes->setObjectName(QStringLiteral("actionRevert_Changes"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRevert_Changes->setIcon(icon1);
        actionAssets = new QAction(MainWindow);
        actionAssets->setObjectName(QStringLiteral("actionAssets"));
        actionAssets->setCheckable(true);
        actionAssets->setChecked(true);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName(QStringLiteral("actionToolbar"));
        actionToolbar->setCheckable(true);
        actionToolbar->setChecked(true);
        actionSet_Name = new QAction(MainWindow);
        actionSet_Name->setObjectName(QStringLiteral("actionSet_Name"));
        actionChat = new QAction(MainWindow);
        actionChat->setObjectName(QStringLiteral("actionChat"));
        actionChat->setCheckable(true);
        actionChat->setChecked(true);
        actionEvents = new QAction(MainWindow);
        actionEvents->setObjectName(QStringLiteral("actionEvents"));
        actionEvents->setCheckable(true);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuNetwork = new QMenu(menuBar);
        menuNetwork->setObjectName(QStringLiteral("menuNetwork"));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(48, 32));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(224, 256));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        eventsDock = new QDockWidget(MainWindow);
        eventsDock->setObjectName(QStringLiteral("eventsDock"));
        eventsDockContents = new QWidget();
        eventsDockContents->setObjectName(QStringLiteral("eventsDockContents"));
        verticalLayout_3 = new QVBoxLayout(eventsDockContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        eventsList = new QListWidget(eventsDockContents);
        eventsList->setObjectName(QStringLiteral("eventsList"));

        verticalLayout_3->addWidget(eventsList);

        eventsDock->setWidget(eventsDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), eventsDock);
        chatDock = new QDockWidget(MainWindow);
        chatDock->setObjectName(QStringLiteral("chatDock"));
        chatDockContents = new QWidget();
        chatDockContents->setObjectName(QStringLiteral("chatDockContents"));
        verticalLayout_2 = new QVBoxLayout(chatDockContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        chatText = new QTextEdit(chatDockContents);
        chatText->setObjectName(QStringLiteral("chatText"));
        chatText->setLineWrapMode(QTextEdit::NoWrap);
        chatText->setReadOnly(true);

        verticalLayout_2->addWidget(chatText);

        chatLine = new QLineEdit(chatDockContents);
        chatLine->setObjectName(QStringLiteral("chatLine"));

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BetterGM", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionLoadPrevious->setText(QApplication::translate("MainWindow", "Load Previous", 0));
        actionCommit_Changes->setText(QApplication::translate("MainWindow", "Commit Changes", 0));
        actionCommit_Changes->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", 0));
        actionCreate_Server->setText(QApplication::translate("MainWindow", "Host", 0));
        actionJoin->setText(QApplication::translate("MainWindow", "Join", 0));
        actionView_IP->setText(QApplication::translate("MainWindow", "View IP", 0));
        actionView_IP->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionRevert_Changes->setText(QApplication::translate("MainWindow", "Revert Changes", 0));
        actionRevert_Changes->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        actionAssets->setText(QApplication::translate("MainWindow", "Resources", 0));
#ifndef QT_NO_TOOLTIP
        actionAssets->setToolTip(QApplication::translate("MainWindow", "Show/Hide Resources", 0));
#endif // QT_NO_TOOLTIP
        actionAssets->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", 0));
        actionToolbar->setText(QApplication::translate("MainWindow", "Toolbar", 0));
#ifndef QT_NO_TOOLTIP
        actionToolbar->setToolTip(QApplication::translate("MainWindow", "Show/Hide the Toolbar", 0));
#endif // QT_NO_TOOLTIP
        actionToolbar->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", 0));
        actionSet_Name->setText(QApplication::translate("MainWindow", "Set Name", 0));
        actionSet_Name->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0));
        actionChat->setText(QApplication::translate("MainWindow", "Chat", 0));
        actionChat->setShortcut(QApplication::translate("MainWindow", "Ctrl+3", 0));
        actionEvents->setText(QApplication::translate("MainWindow", "Events", 0));
        actionEvents->setShortcut(QApplication::translate("MainWindow", "Ctrl+4", 0));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0));
        actionPlay->setShortcut(QApplication::translate("MainWindow", "F5, Ctrl+R", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuNetwork->setTitle(QApplication::translate("MainWindow", "Network", 0));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Toolbar", 0));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Resources", 0));
        eventsDock->setWindowTitle(QApplication::translate("MainWindow", "Events", 0));
        chatDock->setWindowTitle(QApplication::translate("MainWindow", "Chat", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
