/****************************************************************************
** Meta object code from reading C++ file 'Board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QBoggle/Board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Board_t {
    QByteArrayData data[13];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Board_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Board_t qt_meta_stringdata_Board = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Board"
QT_MOC_LITERAL(1, 6, 12), // "addScoreOfMe"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "score"
QT_MOC_LITERAL(4, 26, 11), // "addWordToMe"
QT_MOC_LITERAL(5, 38, 4), // "word"
QT_MOC_LITERAL(6, 43, 18), // "addScoreOfComputer"
QT_MOC_LITERAL(7, 62, 17), // "addWordToComputer"
QT_MOC_LITERAL(8, 80, 12), // "receiveInput"
QT_MOC_LITERAL(9, 93, 3), // "str"
QT_MOC_LITERAL(10, 97, 22), // "extinguishSeletedWords"
QT_MOC_LITERAL(11, 120, 12), // "receiveClick"
QT_MOC_LITERAL(12, 133, 4) // "size"

    },
    "Board\0addScoreOfMe\0\0score\0addWordToMe\0"
    "word\0addScoreOfComputer\0addWordToComputer\0"
    "receiveInput\0str\0extinguishSeletedWords\0"
    "receiveClick\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   61,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Board *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addScoreOfMe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addWordToMe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addScoreOfComputer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addWordToComputer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->receiveInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->extinguishSeletedWords(); break;
        case 6: _t->receiveClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Board::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::addScoreOfMe)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Board::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::addWordToMe)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Board::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::addScoreOfComputer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Board::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::addWordToComputer)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Board::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Board.data,
      qt_meta_data_Board,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Board.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Board::addScoreOfMe(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board::addWordToMe(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board::addScoreOfComputer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Board::addWordToComputer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
