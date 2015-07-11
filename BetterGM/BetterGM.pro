#-------------------------------------------------
#
# Project created by QtCreator 2014-04-19T16:44:27
#
#-------------------------------------------------

QT       += core gui network widgets multimedia

TARGET = BetterGM
TEMPLATE = app

DESTDIR = ../BGMBin
MOC_DIR = ../BGMBin/moc
UI_DIR = ../BGMBin/uic
RCC_DIR = ../BGMBin/rcc
OBJECTS_DIR = ../BGMBin/obj



SOURCES += main.cpp\
        MainWindow.cpp \
    codeEditor/addRemoveText.cpp \
    codeEditor/backtraceWidget.cpp \
    codeEditor/bookMark.cpp \
    codeEditor/codeEditor.cpp \
    codeEditor/haxeLexer.cpp \
    codeEditor/highlighter.cpp \
    codeEditor/locaterWidget.cpp \
    codeEditor/miniMapC.cpp \
    #codeEditor/newscriptdialog.cpp \
    codeEditor/searchWidget.cpp \
    projectItem.cpp \
    GetIPDialog.cpp \
    Server.cpp \
    GetNameDialog.cpp \
    Client.cpp \
    JoinDialog.cpp \
    preferences.cpp \
    CentralWidget.cpp

HEADERS  += MainWindow.h \
    codeEditor/addRemoveText.h \
    codeEditor/backtraceWidget.h \
    codeEditor/bookMark.h \
    codeEditor/codeEditor.h \
    codeEditor/haxeLexer.h \
    codeEditor/highlighter.h \
    codeEditor/locaterWidget.h \
    codeEditor/miniMapC.h \
    #codeEditor/newscriptdialog.h \
    codeEditor/searchWidget.h \
    projectItem.h \
    GetIPDialog.h \
    Server.h \
    GetNameDialog.h \
    Client.h \
    JoinDialog.h \
    preferences.h \
    CentralWidget.h

FORMS    += MainWindow.ui \
    GetIPDialog.ui \
    GetNameDialog.ui \
    JoinDialog.ui

RESOURCES += \
    res.qrc

win32 {
    RC_FILE = BetterGM.rc
}
