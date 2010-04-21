/****************************************************************************
** Meta object code from reading C++ file 'organizer.h'
**
** Created: Wed Apr 21 06:45:36 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "organizer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'organizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Organizer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      53,   27,   10,   10, 0x0a,
     117,   87,   10,   10, 0x0a,
     169,  159,   10,   10, 0x0a,
     198,  159,   10,   10, 0x0a,
     224,   10,   10,   10, 0x0a,
     240,   10,   10,   10, 0x0a,
     259,   10,   10,   10, 0x0a,
     278,   10,   10,   10, 0x0a,
     299,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Organizer[] = {
    "Organizer\0\0addNewKeyword()\0"
    "clickedItem,isDoubleClick\0"
    "startSearch(QTreeWidgetItem*,int)\0"
    "clickedFileItem,isDoubleClick\0"
    "openFileOrDirectory(QTreeWidgetItem*,int)\0"
    "menuPoint\0showKeywordsTreeMenu(QPoint)\0"
    "showFilesTreeMenu(QPoint)\0deleteKeyword()\0"
    "openSelectedFile()\0moveSelectedFile()\0"
    "deleteSelectedFile()\0newKeyword()\0"
};

const QMetaObject Organizer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Organizer,
      qt_meta_data_Organizer, 0 }
};

const QMetaObject *Organizer::metaObject() const
{
    return &staticMetaObject;
}

void *Organizer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Organizer))
        return static_cast<void*>(const_cast< Organizer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Organizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addNewKeyword(); break;
        case 1: startSearch((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: openFileOrDirectory((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: showKeywordsTreeMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: showFilesTreeMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: deleteKeyword(); break;
        case 6: openSelectedFile(); break;
        case 7: moveSelectedFile(); break;
        case 8: deleteSelectedFile(); break;
        case 9: newKeyword(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
