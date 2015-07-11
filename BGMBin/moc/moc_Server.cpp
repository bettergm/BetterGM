/****************************************************************************
** Meta object code from reading C++ file 'Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BetterGM/Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[13];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 5), // "newIP"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 7), // "newPort"
QT_MOC_LITERAL(4, 22, 10), // "newMessage"
QT_MOC_LITERAL(5, 33, 17), // "serverCursorMoved"
QT_MOC_LITERAL(6, 51, 7), // "addUser"
QT_MOC_LITERAL(7, 59, 16), // "serverKeyPressed"
QT_MOC_LITERAL(8, 76, 13), // "newConnection"
QT_MOC_LITERAL(9, 90, 13), // "sessionOpened"
QT_MOC_LITERAL(10, 104, 9), // "clienRead"
QT_MOC_LITERAL(11, 114, 18), // "clientDisconnected"
QT_MOC_LITERAL(12, 133, 11) // "sendAddUser"

    },
    "Server\0newIP\0\0newPort\0newMessage\0"
    "serverCursorMoved\0addUser\0serverKeyPressed\0"
    "newConnection\0sessionOpened\0clienRead\0"
    "clientDisconnected\0sendAddUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    2,   75,    2, 0x06 /* Public */,
       5,    2,   80,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,
       7,    2,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   93,    2, 0x0a /* Public */,
       9,    0,   94,    2, 0x0a /* Public */,
      10,    0,   95,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->serverCursorMoved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->addUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->serverKeyPressed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->newConnection(); break;
        case 7: _t->sessionOpened(); break;
        case 8: _t->clienRead(); break;
        case 9: _t->clientDisconnected(); break;
        case 10: _t->sendAddUser(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::newIP)) {
                *result = 0;
            }
        }
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::newPort)) {
                *result = 1;
            }
        }
        {
            typedef void (Server::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::newMessage)) {
                *result = 2;
            }
        }
        {
            typedef void (Server::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::serverCursorMoved)) {
                *result = 3;
            }
        }
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::addUser)) {
                *result = 4;
            }
        }
        {
            typedef void (Server::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::serverKeyPressed)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Server::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Server.data,
      qt_meta_data_Server,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(const_cast< Server*>(this));
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Server::newIP(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::newPort(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::newMessage(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Server::serverCursorMoved(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Server::addUser(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Server::serverKeyPressed(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
