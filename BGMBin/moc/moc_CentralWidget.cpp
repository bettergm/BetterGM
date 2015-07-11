/****************************************************************************
** Meta object code from reading C++ file 'CentralWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BetterGM/CentralWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CentralWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Titlebar_t {
    QByteArrayData data[4];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Titlebar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Titlebar_t qt_meta_stringdata_Titlebar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Titlebar"
QT_MOC_LITERAL(1, 9, 21), // "closeCurrentDockument"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 27) // "closeCurrentDocumentClicked"

    },
    "Titlebar\0closeCurrentDockument\0\0"
    "closeCurrentDocumentClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Titlebar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Titlebar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Titlebar *_t = static_cast<Titlebar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeCurrentDockument(); break;
        case 1: _t->closeCurrentDocumentClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Titlebar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Titlebar::closeCurrentDockument)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Titlebar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Titlebar.data,
      qt_meta_data_Titlebar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Titlebar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Titlebar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Titlebar.stringdata0))
        return static_cast<void*>(const_cast< Titlebar*>(this));
    return QWidget::qt_metacast(_clname);
}

int Titlebar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Titlebar::closeCurrentDockument()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_CentralWidget_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CentralWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CentralWidget_t qt_meta_stringdata_CentralWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CentralWidget"
QT_MOC_LITERAL(1, 14, 14), // "currentChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 20), // "closeCurrentDocument"
QT_MOC_LITERAL(4, 51, 12), // "indexChanged"
QT_MOC_LITERAL(5, 64, 5), // "index"
QT_MOC_LITERAL(6, 70, 27) // "closeCurrentDocumentClicked"

    },
    "CentralWidget\0currentChanged\0\0"
    "closeCurrentDocument\0indexChanged\0"
    "index\0closeCurrentDocumentClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CentralWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   40,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void CentralWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CentralWidget *_t = static_cast<CentralWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->closeCurrentDocument((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->closeCurrentDocumentClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CentralWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CentralWidget::currentChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CentralWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CentralWidget::closeCurrentDocument)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CentralWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CentralWidget.data,
      qt_meta_data_CentralWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CentralWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CentralWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CentralWidget.stringdata0))
        return static_cast<void*>(const_cast< CentralWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CentralWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CentralWidget::currentChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CentralWidget::closeCurrentDocument(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
