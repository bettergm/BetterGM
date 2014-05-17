/****************************************************************************
** Meta object code from reading C++ file 'codeEditor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BetterGM/codeEditor/codeEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CodeEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      50,   44,   11,   11, 0x05,
      79,   11,   11,   11, 0x05,
     101,   11,   11,   11, 0x05,
     121,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     138,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     169,   11,   11,   11, 0x0a,
     196,   11,   11,   11, 0x0a,
     216,  210,   11,   11, 0x0a,
     245,  240,   11,   11, 0x0a,
     270,  265,   11,   11, 0x0a,
     298,  287,   11,   11, 0x0a,
     327,  322,   11,   11, 0x0a,
     348,   11,   11,   11, 0x0a,
     363,   11,   11,   11, 0x0a,
     393,  379,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     451,  447,   11,   11, 0x08,
     482,   11,   11,   11, 0x28,
     514,  506,   11,   11, 0x08,
     546,   11,   11,   11, 0x08,
     582,  571,   11,   11, 0x08,
     608,   11,   11,   11, 0x08,
     646,  631,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeEditor[] = {
    "CodeEditor\0\0info\0statusInfoChanged(QString)\0"
    "text,\0locateFunction(QString,bool)\0"
    "modifiedChanged(bool)\0cursorPosition(int)\0"
    "pressed(QString)\0findText()\0"
    "updateMiniMapText()\0updateMiniMapVisibleArea()\0"
    "setModified()\0state\0cleanStateChanged(bool)\0"
    "mini\0setUseMiniMap(bool)\0tabs\0"
    "setUseTabs(bool)\0tabsSpaces\0"
    "setShowTabsSpaces(bool)\0wrap\0"
    "setUseWordWrap(bool)\0updateCorner()\0"
    "cursorChanged()\0newBlockCount\0"
    "updateLineNumberAreaWidth(int)\0"
    "highlightCurrentLine()\0txt\0"
    "highlightSelectedWord(QString)\0"
    "highlightSelectedWord()\0rect,dy\0"
    "updateLineNumberArea(QRect,int)\0"
    "updateMiniMapScrollPos()\0completion\0"
    "insertCompletion(QString)\0"
    "blockOrColumnChanged()\0cursor,pressed\0"
    "highlightJumpToDefinition(QTextCursor&,bool)\0"
};

void CodeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CodeEditor *_t = static_cast<CodeEditor *>(_o);
        switch (_id) {
        case 0: _t->statusInfoChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->locateFunction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->modifiedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->cursorPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pressed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->findText(); break;
        case 6: _t->updateMiniMapText(); break;
        case 7: _t->updateMiniMapVisibleArea(); break;
        case 8: _t->setModified(); break;
        case 9: _t->cleanStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setUseMiniMap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setUseTabs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setShowTabsSpaces((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setUseWordWrap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->updateCorner(); break;
        case 15: _t->cursorChanged(); break;
        case 16: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->highlightCurrentLine(); break;
        case 18: _t->highlightSelectedWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->highlightSelectedWord(); break;
        case 20: _t->updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->updateMiniMapScrollPos(); break;
        case 22: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->blockOrColumnChanged(); break;
        case 24: _t->highlightJumpToDefinition((*reinterpret_cast< QTextCursor(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CodeEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CodeEditor::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_CodeEditor,
      qt_meta_data_CodeEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeEditor))
        return static_cast<void*>(const_cast< CodeEditor*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int CodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void CodeEditor::statusInfoChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CodeEditor::locateFunction(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CodeEditor::modifiedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CodeEditor::cursorPosition(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CodeEditor::pressed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
