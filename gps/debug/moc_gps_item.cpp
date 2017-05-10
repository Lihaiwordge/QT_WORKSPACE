/****************************************************************************
** Meta object code from reading C++ file 'gps_item.h'
**
** Created: Sun May 16 22:34:26 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gps_item.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gps_item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gps_item[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      18,    9,    9,    9, 0x0a,
      29,    9,    9,    9, 0x0a,
      38,    9,    9,    9, 0x0a,
      46,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      66,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gps_item[] = {
    "gps_item\0\0mypos()\0myreturn()\0mystar()\0"
    "mapup()\0mapdown()\0mapleft()\0mapright()\0"
};

const QMetaObject gps_item::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gps_item,
      qt_meta_data_gps_item, 0 }
};

const QMetaObject *gps_item::metaObject() const
{
    return &staticMetaObject;
}

void *gps_item::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gps_item))
        return static_cast<void*>(const_cast< gps_item*>(this));
    return QWidget::qt_metacast(_clname);
}

int gps_item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mypos(); break;
        case 1: myreturn(); break;
        case 2: mystar(); break;
        case 3: mapup(); break;
        case 4: mapdown(); break;
        case 5: mapleft(); break;
        case 6: mapright(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
