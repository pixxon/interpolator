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
struct qt_meta_stringdata_Model__Model_t {
    QByteArrayData data[14];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Model__Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Model__Model_t qt_meta_stringdata_Model__Model = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Model::Model"
QT_MOC_LITERAL(1, 13, 6), // "render"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "init"
QT_MOC_LITERAL(4, 26, 5), // "clear"
QT_MOC_LITERAL(5, 32, 12), // "addFuncPoint"
QT_MOC_LITERAL(6, 45, 13), // "addInterPoint"
QT_MOC_LITERAL(7, 59, 12), // "addDiffPoint"
QT_MOC_LITERAL(8, 72, 14), // "addCommonPoint"
QT_MOC_LITERAL(9, 87, 7), // "message"
QT_MOC_LITERAL(10, 95, 5), // "error"
QT_MOC_LITERAL(11, 101, 11), // "partChanged"
QT_MOC_LITERAL(12, 113, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 129, 9) // "timerTick"

    },
    "Model::Model\0render\0\0init\0clear\0"
    "addFuncPoint\0addInterPoint\0addDiffPoint\0"
    "addCommonPoint\0message\0error\0partChanged\0"
    "QVector<double>\0timerTick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model__Model[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    2,   72,    2, 0x06 /* Public */,
       6,    2,   77,    2, 0x06 /* Public */,
       7,    2,   82,    2, 0x06 /* Public */,
       8,    1,   87,    2, 0x06 /* Public */,
       9,    1,   90,    2, 0x06 /* Public */,
      10,    1,   93,    2, 0x06 /* Public */,
      11,    2,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, QMetaType::QVector3D,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12,    2,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Model::Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Model *_t = static_cast<Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->render(); break;
        case 1: _t->init(); break;
        case 2: _t->clear(); break;
        case 3: _t->addFuncPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 4: _t->addInterPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 5: _t->addDiffPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 6: _t->addCommonPoint((*reinterpret_cast< QVector3D(*)>(_a[1]))); break;
        case 7: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->partChanged((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 10: _t->timerTick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::addFuncPoint)) {
                *result = 3;
            }
        }
        {
            typedef void (Model::*_t)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::addInterPoint)) {
                *result = 4;
            }
        }
        {
            typedef void (Model::*_t)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::addDiffPoint)) {
                *result = 5;
            }
        }
        {
            typedef void (Model::*_t)(QVector3D );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::addCommonPoint)) {
                *result = 6;
            }
        }
        {
            typedef void (Model::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::message)) {
                *result = 7;
            }
        }
        {
            typedef void (Model::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::error)) {
                *result = 8;
            }
        }
        {
            typedef void (Model::*_t)(QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::partChanged)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject Model::Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Model__Model.data,
      qt_meta_data_Model__Model,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Model::Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::Model::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Model__Model.stringdata0))
        return static_cast<void*>(const_cast< Model*>(this));
    return QObject::qt_metacast(_clname);
}

int Model::Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Model::Model::render()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Model::Model::init()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Model::Model::clear()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Model::Model::addFuncPoint(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::Model::addInterPoint(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Model::Model::addDiffPoint(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Model::Model::addCommonPoint(QVector3D _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Model::Model::message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Model::Model::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Model::Model::partChanged(QVector<double> _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
