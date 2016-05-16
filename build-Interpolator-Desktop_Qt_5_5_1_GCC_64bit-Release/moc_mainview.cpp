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
struct qt_meta_stringdata_View__MainView_t {
    QByteArrayData data[21];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View__MainView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View__MainView_t qt_meta_stringdata_View__MainView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "View::MainView"
QT_MOC_LITERAL(1, 15, 8), // "inputSet"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 25), // "QVector<QVector<double> >"
QT_MOC_LITERAL(4, 51, 7), // "partSet"
QT_MOC_LITERAL(5, 59, 15), // "QVector<double>"
QT_MOC_LITERAL(6, 75, 16), // "dimensionChanged"
QT_MOC_LITERAL(7, 92, 7), // "enabled"
QT_MOC_LITERAL(8, 100, 6), // "closed"
QT_MOC_LITERAL(9, 107, 7), // "advance"
QT_MOC_LITERAL(10, 115, 11), // "buttonClick"
QT_MOC_LITERAL(11, 127, 12), // "partChangedX"
QT_MOC_LITERAL(12, 140, 12), // "partChangedY"
QT_MOC_LITERAL(13, 153, 12), // "countChanged"
QT_MOC_LITERAL(14, 166, 11), // "helpClicked"
QT_MOC_LITERAL(15, 178, 9), // "showEvent"
QT_MOC_LITERAL(16, 188, 11), // "QShowEvent*"
QT_MOC_LITERAL(17, 200, 10), // "closeEvent"
QT_MOC_LITERAL(18, 211, 12), // "QCloseEvent*"
QT_MOC_LITERAL(19, 224, 12), // "loadFromFile"
QT_MOC_LITERAL(20, 237, 10) // "saveToFile"

    },
    "View::MainView\0inputSet\0\0"
    "QVector<QVector<double> >\0partSet\0"
    "QVector<double>\0dimensionChanged\0"
    "enabled\0closed\0advance\0buttonClick\0"
    "partChangedX\0partChangedY\0countChanged\0"
    "helpClicked\0showEvent\0QShowEvent*\0"
    "closeEvent\0QCloseEvent*\0loadFromFile\0"
    "saveToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__MainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       1,    1,  102,    2, 0x06 /* Public */,
       4,    5,  105,    2, 0x06 /* Public */,
       4,    2,  116,    2, 0x06 /* Public */,
       6,    1,  121,    2, 0x06 /* Public */,
       8,    0,  124,    2, 0x06 /* Public */,
       9,    0,  125,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  126,    2, 0x08 /* Private */,
      11,    0,  127,    2, 0x08 /* Private */,
      12,    0,  128,    2, 0x08 /* Private */,
      13,    0,  129,    2, 0x08 /* Private */,
       6,    0,  130,    2, 0x08 /* Private */,
      14,    0,  131,    2, 0x08 /* Private */,
      15,    1,  132,    2, 0x08 /* Private */,
      17,    1,  135,    2, 0x08 /* Private */,
      19,    0,  138,    2, 0x08 /* Private */,
      20,    0,  139,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Char, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Char, 0x80000000 | 5,    2,    2,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void View::MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainView *_t = static_cast<MainView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputSet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->inputSet((*reinterpret_cast< QVector<QVector<double> >(*)>(_a[1]))); break;
        case 2: _t->partSet((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 3: _t->partSet((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 4: _t->dimensionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->closed(); break;
        case 6: _t->advance(); break;
        case 7: _t->buttonClick(); break;
        case 8: _t->partChangedX(); break;
        case 9: _t->partChangedY(); break;
        case 10: _t->countChanged(); break;
        case 11: _t->dimensionChanged(); break;
        case 12: _t->helpClicked(); break;
        case 13: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 14: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 15: _t->loadFromFile(); break;
        case 16: _t->saveToFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<double> > >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
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
            typedef void (MainView::*_t)(QVector<QVector<double>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::inputSet)) {
                *result = 1;
            }
        }
        {
            typedef void (MainView::*_t)(char , double , double , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::partSet)) {
                *result = 2;
            }
        }
        {
            typedef void (MainView::*_t)(char , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::partSet)) {
                *result = 3;
            }
        }
        {
            typedef void (MainView::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::dimensionChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::closed)) {
                *result = 5;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::advance)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject View::MainView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_View__MainView.data,
      qt_meta_data_View__MainView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *View::MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_View__MainView.stringdata0))
        return static_cast<void*>(const_cast< MainView*>(this));
    return QWidget::qt_metacast(_clname);
}

int View::MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void View::MainView::inputSet(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void View::MainView::inputSet(QVector<QVector<double>> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void View::MainView::partSet(char _t1, double _t2, double _t3, int _t4, QString _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void View::MainView::partSet(char _t1, QVector<double> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void View::MainView::dimensionChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void View::MainView::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void View::MainView::advance()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
