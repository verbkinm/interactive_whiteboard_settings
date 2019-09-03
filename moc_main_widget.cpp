/****************************************************************************
** Meta object code from reading C++ file 'main_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_widget/main_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Main_Widget_t {
    QByteArrayData data[12];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_Widget_t qt_meta_stringdata_Main_Widget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Main_Widget"
QT_MOC_LITERAL(1, 12, 14), // "slotFileChange"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "slotSaveSettings"
QT_MOC_LITERAL(4, 45, 19), // "settingsMiniWidget&"
QT_MOC_LITERAL(5, 65, 14), // "settingsWindow"
QT_MOC_LITERAL(6, 80, 16), // "slotDeleteWidget"
QT_MOC_LITERAL(7, 97, 19), // "slotCreateNewWidget"
QT_MOC_LITERAL(8, 117, 19), // "slotShowContextMenu"
QT_MOC_LITERAL(9, 137, 19), // "slotGeneralSettings"
QT_MOC_LITERAL(10, 157, 21), // "slotBackgroundChanged"
QT_MOC_LITERAL(11, 179, 10) // "background"

    },
    "Main_Widget\0slotFileChange\0\0"
    "slotSaveSettings\0settingsMiniWidget&\0"
    "settingsWindow\0slotDeleteWidget\0"
    "slotCreateNewWidget\0slotShowContextMenu\0"
    "slotGeneralSettings\0slotBackgroundChanged\0"
    "background"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void Main_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Main_Widget *_t = static_cast<Main_Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotFileChange(); break;
        case 1: _t->slotSaveSettings((*reinterpret_cast< settingsMiniWidget(*)>(_a[1]))); break;
        case 2: _t->slotDeleteWidget(); break;
        case 3: _t->slotCreateNewWidget(); break;
        case 4: _t->slotShowContextMenu(); break;
        case 5: _t->slotGeneralSettings(); break;
        case 6: _t->slotBackgroundChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Main_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Main_Widget.data,
      qt_meta_data_Main_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Main_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Main_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
