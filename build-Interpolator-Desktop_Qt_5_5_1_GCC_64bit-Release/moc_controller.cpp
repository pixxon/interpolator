/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller__Controller_t {
    QByteArrayData data[23];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller__Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller__Controller_t qt_meta_stringdata_Controller__Controller = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Controller::Controller"
QT_MOC_LITERAL(1, 23, 11), // "modelRender"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "modelInit"
QT_MOC_LITERAL(4, 46, 10), // "modelClear"
QT_MOC_LITERAL(5, 57, 14), // "modelFuncPoint"
QT_MOC_LITERAL(6, 72, 15), // "modelInterPoint"
QT_MOC_LITERAL(7, 88, 14), // "modelDiffPoint"
QT_MOC_LITERAL(8, 103, 3), // "pos"
QT_MOC_LITERAL(9, 107, 3), // "col"
QT_MOC_LITERAL(10, 111, 16), // "modelCommonPoint"
QT_MOC_LITERAL(11, 128, 16), // "modelPartChanged"
QT_MOC_LITERAL(12, 145, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 161, 12), // "modelMessage"
QT_MOC_LITERAL(14, 174, 10), // "modelError"
QT_MOC_LITERAL(15, 185, 7), // "message"
QT_MOC_LITERAL(16, 193, 9), // "viewInput"
QT_MOC_LITERAL(17, 203, 25), // "QVector<QVector<double> >"
QT_MOC_LITERAL(18, 229, 8), // "viewPart"
QT_MOC_LITERAL(19, 238, 20), // "viewDimensionChanged"
QT_MOC_LITERAL(20, 259, 7), // "enabled"
QT_MOC_LITERAL(21, 267, 12), // "viewContinue"
QT_MOC_LITERAL(22, 280, 10) // "viewClosed"

    },
    "Controller::Controller\0modelRender\0\0"
    "modelInit\0modelClear\0modelFuncPoint\0"
    "modelInterPoint\0modelDiffPoint\0pos\0"
    "col\0modelCommonPoint\0modelPartChanged\0"
    "QVector<double>\0modelMessage\0modelError\0"
    "message\0viewInput\0QVector<QVector<double> >\0"
    "viewPart\0viewDimensionChanged\0enabled\0"
    "viewContinue\0viewClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller__Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    2,  102,    2, 0x08 /* Private */,
       6,    2,  107,    2, 0x08 /* Private */,
       7,    2,  112,    2, 0x08 /* Private */,
      10,    1,  117,    2, 0x08 /* Private */,
      11,    2,  120,    2, 0x08 /* Private */,
      13,    1,  125,    2, 0x08 /* Private */,
      14,    1,  128,    2, 0x08 /* Private */,
      16,    1,  131,    2, 0x08 /* Private */,
      16,    1,  134,    2, 0x08 /* Private */,
      18,    5,  137,    2, 0x08 /* Private */,
      18,    2,  148,    2, 0x08 /* Private */,
      19,    1,  153,    2, 0x08 /* Private */,
      21,    0,  156,    2, 0x08 /* Private */,
      22,    0,  157,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    8,    9,
    QMetaType::Void, QMetaType::QVector3D,    2,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, QMetaType::Char, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Char, 0x80000000 | 12,    2,    2,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controller::Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modelRender(); break;
        case 1: _t->modelInit(); break;
        case 2: _t->modelClear(); break;
        case 3: _t->modelFuncPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 4: _t->modelInterPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 5: _t->modelDiffPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 6: _t->modelCommonPoint((*reinterpret_cast< QVector3D(*)>(_a[1]))); break;
        case 7: _t->modelPartChanged((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 8: _t->modelMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->modelError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->viewInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->viewInput((*reinterpret_cast< QVector<QVector<double> >(*)>(_a[1]))); break;
        case 12: _t->viewPart((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 13: _t->viewPart((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 14: _t->viewDimensionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->viewContinue(); break;
        case 16: _t->viewClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<double> > >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject Controller::Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller__Controller.data,
      qt_meta_data_Controller__Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controller::Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controller__Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
