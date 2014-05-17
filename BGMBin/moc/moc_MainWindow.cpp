/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BetterGM/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      34,   26,   11,   11, 0x0a,
      61,   55,   11,   11, 0x0a,
     102,   92,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     141,   11,   11,   11, 0x0a,
     155,   11,   11,   11, 0x0a,
     166,   11,   11,   11, 0x0a,
     179,   11,   11,   11, 0x0a,
     189,   11,   11,   11, 0x0a,
     212,  203,   11,   11, 0x0a,
     255,  244,   11,   11, 0x0a,
     291,  286,   11,   11, 0x0a,
     308,   11,   11,   11, 0x0a,
     319,  316,   11,   11, 0x0a,
     339,  334,   11,   11, 0x0a,
     356,   11,   11,   11, 0x0a,
     367,   11,   11,   11, 0x0a,
     380,   11,   11,   11, 0x0a,
     391,   11,   11,   11, 0x0a,
     409,   11,   11,   11, 0x0a,
     434,   11,   11,   11, 0x0a,
     462,  458,   11,   11, 0x0a,
     485,   11,   11,   11, 0x0a,
     499,   11,   11,   11, 0x0a,
     514,  510,   11,   11, 0x0a,
     545,  534,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openProject()\0project\0"
    "openProject(QString)\0item,\0"
    "openItem(QTreeWidgetItem*,int)\0path,name\0"
    "openItem(QString,QString)\0showAssets()\0"
    "showToolbar()\0showChat()\0showEvents()\0"
    "setName()\0sendMessage()\0from,msg\0"
    "recieveMessage(QString,QString)\0"
    "client,pos\0clientCursorMoved(QString,int)\0"
    "user\0addUser(QString)\0getIP()\0ip\0"
    "newIP(QString)\0port\0newPort(QString)\0"
    "makeHost()\0makeClient()\0saveFile()\0"
    "setLoadPrevious()\0setCanSendFalse(QString)\0"
    "setCanSendTrue(QString)\0pos\0"
    "getCursorPosition(int)\0readGameOut()\0"
    "playGame()\0key\0keyPressed(QString)\0"
    "client,key\0clientKeyPressed(QString,QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openProject(); break;
        case 1: _t->openProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->openItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->openItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->showAssets(); break;
        case 5: _t->showToolbar(); break;
        case 6: _t->showChat(); break;
        case 7: _t->showEvents(); break;
        case 8: _t->setName(); break;
        case 9: _t->sendMessage(); break;
        case 10: _t->recieveMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->clientCursorMoved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->addUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->getIP(); break;
        case 14: _t->newIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->newPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->makeHost(); break;
        case 17: _t->makeClient(); break;
        case 18: _t->saveFile(); break;
        case 19: _t->setLoadPrevious(); break;
        case 20: _t->setCanSendFalse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->setCanSendTrue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->getCursorPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->readGameOut(); break;
        case 24: _t->playGame(); break;
        case 25: _t->keyPressed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->clientKeyPressed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
