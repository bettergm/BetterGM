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
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      50,   44,   11,   11, 0x05,
      79,   11,   11,   11, 0x05,
     101,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     152,   11,   11,   11, 0x0a,
     179,   11,   11,   11, 0x0a,
     199,  193,   11,   11, 0x0a,
     228,  223,   11,   11, 0x0a,
     253,  248,   11,   11, 0x0a,
     281,  270,   11,   11, 0x0a,
     310,  305,   11,   11, 0x0a,
     331,   11,   11,   11, 0x0a,
     346,   11,   11,   11, 0x0a,
     376,  362,   11,   11, 0x08,
     407,   11,   11,   11, 0x08,
     434,  430,   11,   11, 0x08,
     465,   11,   11,   11, 0x28,
     497,  489,   11,   11, 0x08,
     529,   11,   11,   11, 0x08,
     565,  554,   11,   11, 0x08,
     591,   11,   11,   11, 0x08,
     629,  614,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeEditor[] = {
    "CodeEditor\0\0info\0statusInfoChanged(QString)\0"
    "text,\0locateFunction(QString,bool)\0"
    "modifiedChanged(bool)\0cursorPosition(int)\0"
    "findText()\0updateMiniMapText()\0"
    "updateMiniMapVisibleArea()\0setModified()\0"
    "state\0cleanStateChanged(bool)\0mini\0"
    "setUseMiniMap(bool)\0tabs\0setUseTabs(bool)\0"
    "tabsSpaces\0setShowTabsSpaces(bool)\0"
    "wrap\0setUseWordWrap(bool)\0updateCorner()\0"
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
        case 4: _t->findText(); break;
        case 5: _t->updateMiniMapText(); break;
        case 6: _t->updateMiniMapVisibleArea(); break;
        case 7: _t->setModified(); break;
        case 8: _t->cleanStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setUseMiniMap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setUseTabs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setShowTabsSpaces((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setUseWordWrap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->updateCorner(); break;
        case 14: _t->cursorChanged(); break;
        case 15: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->highlightCurrentLine(); break;
        case 17: _t->highlightSelectedWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->highlightSelectedWord(); break;
        case 19: _t->updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->updateMiniMapScrollPos(); break;
        case 21: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->blockOrColumnChanged(); break;
        case 23: _t->highlightJumpToDefinition((*reinterpret_cast< QTextCursor(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
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
QT_END_MOC_NAMESPACE
