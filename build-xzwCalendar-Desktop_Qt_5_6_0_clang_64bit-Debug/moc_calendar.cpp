/****************************************************************************
** Meta object code from reading C++ file 'calendar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xzwCalendar/calendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_calendar_t {
    QByteArrayData data[12];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calendar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calendar_t qt_meta_stringdata_calendar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "calendar"
QT_MOC_LITERAL(1, 9, 11), // "dateChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 31), // "on_clicked_find_privious_button"
QT_MOC_LITERAL(4, 54, 27), // "on_clicked_find_next_button"
QT_MOC_LITERAL(5, 82, 32), // "on_valueChanged_the_year_spinbox"
QT_MOC_LITERAL(6, 115, 33), // "on_valueChanged_the_month_spi..."
QT_MOC_LITERAL(7, 149, 19), // "on_datecell_clicked"
QT_MOC_LITERAL(8, 169, 26), // "on_datecell_double_clicked"
QT_MOC_LITERAL(9, 196, 15), // "change_calendar"
QT_MOC_LITERAL(10, 212, 14), // "change_spinbox"
QT_MOC_LITERAL(11, 227, 12) // "change_label"

    },
    "calendar\0dateChanged\0\0"
    "on_clicked_find_privious_button\0"
    "on_clicked_find_next_button\0"
    "on_valueChanged_the_year_spinbox\0"
    "on_valueChanged_the_month_spinbox\0"
    "on_datecell_clicked\0on_datecell_double_clicked\0"
    "change_calendar\0change_spinbox\0"
    "change_label"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    1,   67,    2, 0x0a /* Public */,
       6,    1,   70,    2, 0x0a /* Public */,
       7,    1,   73,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendar *_t = static_cast<calendar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateChanged(); break;
        case 1: _t->on_clicked_find_privious_button(); break;
        case 2: _t->on_clicked_find_next_button(); break;
        case 3: _t->on_valueChanged_the_year_spinbox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_valueChanged_the_month_spinbox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_datecell_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_datecell_double_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->change_calendar(); break;
        case 8: _t->change_spinbox(); break;
        case 9: _t->change_label(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calendar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendar::dateChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject calendar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_calendar.data,
      qt_meta_data_calendar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calendar.stringdata0))
        return static_cast<void*>(const_cast< calendar*>(this));
    return QWidget::qt_metacast(_clname);
}

int calendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void calendar::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
