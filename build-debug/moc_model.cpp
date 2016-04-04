/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/model/model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Model_t {
    QByteArrayData data[13];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Model"
QT_MOC_LITERAL(1, 6, 6), // "render"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 4), // "init"
QT_MOC_LITERAL(4, 19, 5), // "clear"
QT_MOC_LITERAL(5, 25, 7), // "addData"
QT_MOC_LITERAL(6, 33, 8), // "addData2"
QT_MOC_LITERAL(7, 42, 12), // "part_changed"
QT_MOC_LITERAL(8, 55, 15), // "QVector<double>"
QT_MOC_LITERAL(9, 71, 8), // "setInput"
QT_MOC_LITERAL(10, 80, 8), // "setPartX"
QT_MOC_LITERAL(11, 89, 8), // "setPartY"
QT_MOC_LITERAL(12, 98, 9) // "timerTick"

    },
    "Model\0render\0\0init\0clear\0addData\0"
    "addData2\0part_changed\0QVector<double>\0"
    "setInput\0setPartX\0setPartY\0timerTick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    2,   67,    2, 0x06 /* Public */,
       6,    2,   72,    2, 0x06 /* Public */,
       7,    2,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   82,    2, 0x0a /* Public */,
      10,    4,   85,    2, 0x0a /* Public */,
      11,    4,   94,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Model *_t = static_cast<Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->render(); break;
        case 1: _t->init(); break;
        case 2: _t->clear(); break;
        case 3: _t->addData((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 4: _t->addData2((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 5: _t->part_changed((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 6: _t->setInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setPartX((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 8: _t->setPartY((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->timerTick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Model::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::render)) {
                *result = 0;
            }
        }
        {
            typedef void (Model::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::init)) {
                *result = 1;
            }
        }
        {
            typedef void (Model::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::clear)) {
                *result = 2;
            }
        }
        {
            typedef void (Model::*_t)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::addData)) {
                *result = 3;
            }
        }
        {
            typedef void (Model::*_t)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::addData2)) {
                *result = 4;
            }
        }
        {
            typedef void (Model::*_t)(QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::part_changed)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Model.data,
      qt_meta_data_Model,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(const_cast< Model*>(this));
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Model::render()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Model::init()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Model::clear()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Model::addData(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::addData2(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Model::part_changed(QVector<double> _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
