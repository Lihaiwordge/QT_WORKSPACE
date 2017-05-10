/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MDSP_ADC_LAB/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[14];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 30), // "on_button_start_device_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "on_button_start_a_clicked"
QT_MOC_LITERAL(4, 65, 24), // "on_button_stop_a_clicked"
QT_MOC_LITERAL(5, 90, 25), // "on_button_clear_a_clicked"
QT_MOC_LITERAL(6, 116, 24), // "on_button_save_a_clicked"
QT_MOC_LITERAL(7, 141, 25), // "on_button_start_b_clicked"
QT_MOC_LITERAL(8, 167, 24), // "on_button_stop_b_clicked"
QT_MOC_LITERAL(9, 192, 25), // "on_button_clear_b_clicked"
QT_MOC_LITERAL(10, 218, 30), // "on_button_close_device_clicked"
QT_MOC_LITERAL(11, 249, 22), // "on_button_exit_clicked"
QT_MOC_LITERAL(12, 272, 6), // "RxData"
QT_MOC_LITERAL(13, 279, 29) // "on_button_link_serial_clicked"

    },
    "Dialog\0on_button_start_device_clicked\0"
    "\0on_button_start_a_clicked\0"
    "on_button_stop_a_clicked\0"
    "on_button_clear_a_clicked\0"
    "on_button_save_a_clicked\0"
    "on_button_start_b_clicked\0"
    "on_button_stop_b_clicked\0"
    "on_button_clear_b_clicked\0"
    "on_button_close_device_clicked\0"
    "on_button_exit_clicked\0RxData\0"
    "on_button_link_serial_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_button_start_device_clicked(); break;
        case 1: _t->on_button_start_a_clicked(); break;
        case 2: _t->on_button_stop_a_clicked(); break;
        case 3: _t->on_button_clear_a_clicked(); break;
        case 4: _t->on_button_save_a_clicked(); break;
        case 5: _t->on_button_start_b_clicked(); break;
        case 6: _t->on_button_stop_b_clicked(); break;
        case 7: _t->on_button_clear_b_clicked(); break;
        case 8: _t->on_button_close_device_clicked(); break;
        case 9: _t->on_button_exit_clicked(); break;
        case 10: _t->RxData(); break;
        case 11: _t->on_button_link_serial_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
