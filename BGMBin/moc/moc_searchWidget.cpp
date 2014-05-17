/****************************************************************************
** Meta object code from reading C++ file 'searchWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BetterGM/codeEditor/searchWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LineEditCount[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_LineEditCount[] = {
    "LineEditCount\0"
};

void LineEditCount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LineEditCount::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LineEditCount::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LineEditCount,
      qt_meta_data_LineEditCount, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LineEditCount::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LineEditCount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LineEditCount::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineEditCount))
        return static_cast<void*>(const_cast< LineEditCount*>(this));
    return QObject::qt_metacast(_clname);
}

int LineEditCount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_LineEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_LineEdit[] = {
    "LineEdit\0"
};

void LineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_LineEdit,
      qt_meta_data_LineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineEdit))
        return static_cast<void*>(const_cast< LineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int LineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SearchWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   13,   13,   13, 0x0a,
      50,   13,   13,   13, 0x0a,
      61,   13,   13,   13, 0x0a,
      76,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SearchWidget[] = {
    "SearchWidget\0\0closeButtonClicked()\0"
    "closeClicked()\0findNext()\0findPrevious()\0"
    "findMatches()\0"
};

void SearchWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SearchWidget *_t = static_cast<SearchWidget *>(_o);
        switch (_id) {
        case 0: _t->closeButtonClicked(); break;
        case 1: _t->closeClicked(); break;
        case 2: _t->findNext(); break;
        case 3: _t->findPrevious(); break;
        case 4: _t->findMatches(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SearchWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SearchWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SearchWidget,
      qt_meta_data_SearchWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SearchWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SearchWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SearchWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchWidget))
        return static_cast<void*>(const_cast< SearchWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SearchWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SearchWidget::closeButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
