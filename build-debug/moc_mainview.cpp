/****************************************************************************
** Meta object code from reading C++ file 'mainview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/view/mainview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainView_t {
    QByteArrayData data[10];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainView_t qt_meta_stringdata_MainView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainView"
QT_MOC_LITERAL(1, 9, 8), // "inputSet"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "partXSet"
QT_MOC_LITERAL(4, 28, 8), // "partYSet"
QT_MOC_LITERAL(5, 37, 11), // "buttonClick"
QT_MOC_LITERAL(6, 49, 15), // "count_x_changed"
QT_MOC_LITERAL(7, 65, 15), // "count_y_changed"
QT_MOC_LITERAL(8, 81, 12), // "part_changed"
QT_MOC_LITERAL(9, 94, 15) // "QVector<double>"

    },
    "MainView\0inputSet\0\0partXSet\0partYSet\0"
    "buttonClick\0count_x_changed\0count_y_changed\0"
    "part_changed\0QVector<double>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    4,   52,    2, 0x06 /* Public */,
       4,    4,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   70,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    2,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,    2,    2,

       0        // eod
};

void MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainView *_t = static_cast<MainView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputSet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->partXSet((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->partYSet((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->buttonClick(); break;
        case 4: _t->count_x_changed(); break;
        case 5: _t->count_y_changed(); break;
        case 6: _t->part_changed((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            typedef void (MainView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::inputSet)) {
                *result = 0;
            }
        }
        {
            typedef void (MainView::*_t)(double , double , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::partXSet)) {
                *result = 1;
            }
        }
        {
            typedef void (MainView::*_t)(double , double , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::partYSet)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MainView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainView.data,
      qt_meta_data_MainView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainView.stringdata0))
        return static_cast<void*>(const_cast< MainView*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainView::inputSet(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainView::partXSet(double _t1, double _t2, int _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainView::partYSet(double _t1, double _t2, int _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
