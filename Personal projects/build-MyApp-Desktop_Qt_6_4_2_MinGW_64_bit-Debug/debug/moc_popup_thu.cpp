/****************************************************************************
** Meta object code from reading C++ file 'popup_thu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyApp/popup_thu.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popup_thu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_popup_Thu_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[19];
    char stringdata5[18];
    char stringdata6[21];
    char stringdata7[29];
    char stringdata8[22];
    char stringdata9[18];
    char stringdata10[18];
    char stringdata11[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_popup_Thu_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_popup_Thu_t qt_meta_stringdata_popup_Thu = {
    {
        QT_MOC_LITERAL(0, 9),  // "popup_Thu"
        QT_MOC_LITERAL(10, 16),  // "dataAvaiable_Thu"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 16),  // "data_textday_thu"
        QT_MOC_LITERAL(45, 18),  // "data_textmoney_thu"
        QT_MOC_LITERAL(64, 17),  // "data_texttype_thu"
        QT_MOC_LITERAL(82, 20),  // "data_textcontent_thu"
        QT_MOC_LITERAL(103, 28),  // "on_pushButton_SetThu_clicked"
        QT_MOC_LITERAL(132, 21),  // "ShowCalendarSelection"
        QT_MOC_LITERAL(154, 17),  // "BackDayinCalendar"
        QT_MOC_LITERAL(172, 17),  // "NextDayinCalendar"
        QT_MOC_LITERAL(190, 15)   // "SetDateCalendar"
    },
    "popup_Thu",
    "dataAvaiable_Thu",
    "",
    "data_textday_thu",
    "data_textmoney_thu",
    "data_texttype_thu",
    "data_textcontent_thu",
    "on_pushButton_SetThu_clicked",
    "ShowCalendarSelection",
    "BackDayinCalendar",
    "NextDayinCalendar",
    "SetDateCalendar"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_popup_Thu[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   59,    2, 0x08,    6 /* Private */,
       8,    0,   60,    2, 0x0a,    7 /* Public */,
       9,    0,   61,    2, 0x0a,    8 /* Public */,
      10,    0,   62,    2, 0x0a,    9 /* Public */,
      11,    0,   63,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject popup_Thu::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_popup_Thu.offsetsAndSizes,
    qt_meta_data_popup_Thu,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_popup_Thu_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<popup_Thu, std::true_type>,
        // method 'dataAvaiable_Thu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_SetThu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowCalendarSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BackDayinCalendar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NextDayinCalendar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SetDateCalendar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void popup_Thu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<popup_Thu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataAvaiable_Thu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 1: _t->on_pushButton_SetThu_clicked(); break;
        case 2: _t->ShowCalendarSelection(); break;
        case 3: _t->BackDayinCalendar(); break;
        case 4: _t->NextDayinCalendar(); break;
        case 5: _t->SetDateCalendar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (popup_Thu::*)(const QString & , const QString & , const QString & , const QString & );
            if (_t _q_method = &popup_Thu::dataAvaiable_Thu; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *popup_Thu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *popup_Thu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_popup_Thu.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int popup_Thu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void popup_Thu::dataAvaiable_Thu(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
