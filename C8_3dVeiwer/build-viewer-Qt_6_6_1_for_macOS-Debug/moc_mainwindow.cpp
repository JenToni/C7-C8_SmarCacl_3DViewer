/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../viewer/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_open_file_clicked",
    "",
    "on_MainWindow_destroyed",
    "on_pushButton_colorEdge_clicked",
    "on_pushButton_colorVertice_clicked",
    "on_pushButton_colorBackg_clicked",
    "on_moveXInput_valueChanged",
    "arg1",
    "on_moveYInput_valueChanged",
    "on_moveZInput_valueChanged",
    "rotateModel",
    "axis",
    "angle",
    "on_rotateXInput_valueChanged",
    "on_rotateYInput_valueChanged",
    "on_rotateZInput_valueChanged",
    "on_rotationX_slider_valueChanged",
    "value",
    "on_rotationY_slider_valueChanged",
    "on_rotationZ_slider_valueChanged",
    "on_pushButton_Gif_mode_1_clicked",
    "on_pushButton_Gif_mode_2_clicked",
    "makeGif",
    "on_pushButton_downloadImage_clicked",
    "on_scaleSpinBox_valueChanged",
    "on_scaleSlider_valueChanged",
    "scaleModel",
    "on_scaleToDefault_clicked",
    "on_edgeWidth_slider_valueChanged",
    "on_edgeWidth_spinbox_valueChanged",
    "on_verticeSize_spinbox_valueChanged",
    "on_verticeSize_slider_valueChanged",
    "on_radioButton_orthogonal_toggled",
    "checked",
    "on_radioButton_perspective_toggled",
    "on_radioButton_dotted_toggled",
    "on_radioButton_constant_toggled",
    "on_radioButton_noneVertice_toggled",
    "on_radioButton_circleVertice_toggled",
    "on_radioButton_squareVertice_toggled"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[82];
    char stringdata0[11];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[32];
    char stringdata5[35];
    char stringdata6[33];
    char stringdata7[27];
    char stringdata8[5];
    char stringdata9[27];
    char stringdata10[27];
    char stringdata11[12];
    char stringdata12[5];
    char stringdata13[6];
    char stringdata14[29];
    char stringdata15[29];
    char stringdata16[29];
    char stringdata17[33];
    char stringdata18[6];
    char stringdata19[33];
    char stringdata20[33];
    char stringdata21[33];
    char stringdata22[33];
    char stringdata23[8];
    char stringdata24[36];
    char stringdata25[29];
    char stringdata26[28];
    char stringdata27[11];
    char stringdata28[26];
    char stringdata29[33];
    char stringdata30[34];
    char stringdata31[36];
    char stringdata32[35];
    char stringdata33[34];
    char stringdata34[8];
    char stringdata35[35];
    char stringdata36[30];
    char stringdata37[32];
    char stringdata38[35];
    char stringdata39[37];
    char stringdata40[37];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 20),  // "on_open_file_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 23),  // "on_MainWindow_destroyed"
        QT_MOC_LITERAL(57, 31),  // "on_pushButton_colorEdge_clicked"
        QT_MOC_LITERAL(89, 34),  // "on_pushButton_colorVertice_cl..."
        QT_MOC_LITERAL(124, 32),  // "on_pushButton_colorBackg_clicked"
        QT_MOC_LITERAL(157, 26),  // "on_moveXInput_valueChanged"
        QT_MOC_LITERAL(184, 4),  // "arg1"
        QT_MOC_LITERAL(189, 26),  // "on_moveYInput_valueChanged"
        QT_MOC_LITERAL(216, 26),  // "on_moveZInput_valueChanged"
        QT_MOC_LITERAL(243, 11),  // "rotateModel"
        QT_MOC_LITERAL(255, 4),  // "axis"
        QT_MOC_LITERAL(260, 5),  // "angle"
        QT_MOC_LITERAL(266, 28),  // "on_rotateXInput_valueChanged"
        QT_MOC_LITERAL(295, 28),  // "on_rotateYInput_valueChanged"
        QT_MOC_LITERAL(324, 28),  // "on_rotateZInput_valueChanged"
        QT_MOC_LITERAL(353, 32),  // "on_rotationX_slider_valueChanged"
        QT_MOC_LITERAL(386, 5),  // "value"
        QT_MOC_LITERAL(392, 32),  // "on_rotationY_slider_valueChanged"
        QT_MOC_LITERAL(425, 32),  // "on_rotationZ_slider_valueChanged"
        QT_MOC_LITERAL(458, 32),  // "on_pushButton_Gif_mode_1_clicked"
        QT_MOC_LITERAL(491, 32),  // "on_pushButton_Gif_mode_2_clicked"
        QT_MOC_LITERAL(524, 7),  // "makeGif"
        QT_MOC_LITERAL(532, 35),  // "on_pushButton_downloadImage_c..."
        QT_MOC_LITERAL(568, 28),  // "on_scaleSpinBox_valueChanged"
        QT_MOC_LITERAL(597, 27),  // "on_scaleSlider_valueChanged"
        QT_MOC_LITERAL(625, 10),  // "scaleModel"
        QT_MOC_LITERAL(636, 25),  // "on_scaleToDefault_clicked"
        QT_MOC_LITERAL(662, 32),  // "on_edgeWidth_slider_valueChanged"
        QT_MOC_LITERAL(695, 33),  // "on_edgeWidth_spinbox_valueCha..."
        QT_MOC_LITERAL(729, 35),  // "on_verticeSize_spinbox_valueC..."
        QT_MOC_LITERAL(765, 34),  // "on_verticeSize_slider_valueCh..."
        QT_MOC_LITERAL(800, 33),  // "on_radioButton_orthogonal_tog..."
        QT_MOC_LITERAL(834, 7),  // "checked"
        QT_MOC_LITERAL(842, 34),  // "on_radioButton_perspective_to..."
        QT_MOC_LITERAL(877, 29),  // "on_radioButton_dotted_toggled"
        QT_MOC_LITERAL(907, 31),  // "on_radioButton_constant_toggled"
        QT_MOC_LITERAL(939, 34),  // "on_radioButton_noneVertice_to..."
        QT_MOC_LITERAL(974, 36),  // "on_radioButton_circleVertice_..."
        QT_MOC_LITERAL(1011, 36)   // "on_radioButton_squareVertice_..."
    },
    "MainWindow",
    "on_open_file_clicked",
    "",
    "on_MainWindow_destroyed",
    "on_pushButton_colorEdge_clicked",
    "on_pushButton_colorVertice_clicked",
    "on_pushButton_colorBackg_clicked",
    "on_moveXInput_valueChanged",
    "arg1",
    "on_moveYInput_valueChanged",
    "on_moveZInput_valueChanged",
    "rotateModel",
    "axis",
    "angle",
    "on_rotateXInput_valueChanged",
    "on_rotateYInput_valueChanged",
    "on_rotateZInput_valueChanged",
    "on_rotationX_slider_valueChanged",
    "value",
    "on_rotationY_slider_valueChanged",
    "on_rotationZ_slider_valueChanged",
    "on_pushButton_Gif_mode_1_clicked",
    "on_pushButton_Gif_mode_2_clicked",
    "makeGif",
    "on_pushButton_downloadImage_clicked",
    "on_scaleSpinBox_valueChanged",
    "on_scaleSlider_valueChanged",
    "scaleModel",
    "on_scaleToDefault_clicked",
    "on_edgeWidth_slider_valueChanged",
    "on_edgeWidth_spinbox_valueChanged",
    "on_verticeSize_spinbox_valueChanged",
    "on_verticeSize_slider_valueChanged",
    "on_radioButton_orthogonal_toggled",
    "checked",
    "on_radioButton_perspective_toggled",
    "on_radioButton_dotted_toggled",
    "on_radioButton_constant_toggled",
    "on_radioButton_noneVertice_toggled",
    "on_radioButton_circleVertice_toggled",
    "on_radioButton_squareVertice_toggled"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  218,    2, 0x08,    1 /* Private */,
       3,    0,  219,    2, 0x08,    2 /* Private */,
       4,    0,  220,    2, 0x08,    3 /* Private */,
       5,    0,  221,    2, 0x08,    4 /* Private */,
       6,    0,  222,    2, 0x08,    5 /* Private */,
       7,    1,  223,    2, 0x08,    6 /* Private */,
       9,    1,  226,    2, 0x08,    8 /* Private */,
      10,    1,  229,    2, 0x08,   10 /* Private */,
      11,    2,  232,    2, 0x08,   12 /* Private */,
      14,    1,  237,    2, 0x08,   15 /* Private */,
      15,    1,  240,    2, 0x08,   17 /* Private */,
      16,    1,  243,    2, 0x08,   19 /* Private */,
      17,    1,  246,    2, 0x08,   21 /* Private */,
      19,    1,  249,    2, 0x08,   23 /* Private */,
      20,    1,  252,    2, 0x08,   25 /* Private */,
      21,    0,  255,    2, 0x08,   27 /* Private */,
      22,    0,  256,    2, 0x08,   28 /* Private */,
      23,    0,  257,    2, 0x08,   29 /* Private */,
      24,    0,  258,    2, 0x08,   30 /* Private */,
      25,    1,  259,    2, 0x08,   31 /* Private */,
      26,    1,  262,    2, 0x08,   33 /* Private */,
      27,    0,  265,    2, 0x08,   35 /* Private */,
      28,    0,  266,    2, 0x08,   36 /* Private */,
      29,    1,  267,    2, 0x08,   37 /* Private */,
      30,    1,  270,    2, 0x08,   39 /* Private */,
      31,    1,  273,    2, 0x08,   41 /* Private */,
      32,    1,  276,    2, 0x08,   43 /* Private */,
      33,    1,  279,    2, 0x08,   45 /* Private */,
      35,    1,  282,    2, 0x08,   47 /* Private */,
      36,    1,  285,    2, 0x08,   49 /* Private */,
      37,    1,  288,    2, 0x08,   51 /* Private */,
      38,    1,  291,    2, 0x08,   53 /* Private */,
      39,    1,  294,    2, 0x08,   55 /* Private */,
      40,    1,  297,    2, 0x08,   57 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   12,   13,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_open_file_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MainWindow_destroyed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_colorEdge_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_colorVertice_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_colorBackg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveXInput_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_moveYInput_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_moveZInput_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'rotateModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_rotateXInput_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_rotateYInput_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_rotateZInput_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_rotationX_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_rotationY_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_rotationZ_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_Gif_mode_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Gif_mode_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'makeGif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_downloadImage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scaleSpinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_scaleSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'scaleModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scaleToDefault_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_edgeWidth_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_edgeWidth_spinbox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_verticeSize_spinbox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_verticeSize_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_radioButton_orthogonal_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_perspective_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_dotted_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_constant_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_noneVertice_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_circleVertice_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButton_squareVertice_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_open_file_clicked(); break;
        case 1: _t->on_MainWindow_destroyed(); break;
        case 2: _t->on_pushButton_colorEdge_clicked(); break;
        case 3: _t->on_pushButton_colorVertice_clicked(); break;
        case 4: _t->on_pushButton_colorBackg_clicked(); break;
        case 5: _t->on_moveXInput_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->on_moveYInput_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->on_moveZInput_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->rotateModel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 9: _t->on_rotateXInput_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->on_rotateYInput_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 11: _t->on_rotateZInput_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 12: _t->on_rotationX_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_rotationY_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_rotationZ_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_pushButton_Gif_mode_1_clicked(); break;
        case 16: _t->on_pushButton_Gif_mode_2_clicked(); break;
        case 17: _t->makeGif(); break;
        case 18: _t->on_pushButton_downloadImage_clicked(); break;
        case 19: _t->on_scaleSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_scaleSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->scaleModel(); break;
        case 22: _t->on_scaleToDefault_clicked(); break;
        case 23: _t->on_edgeWidth_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_edgeWidth_spinbox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_verticeSize_spinbox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 26: _t->on_verticeSize_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_radioButton_orthogonal_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: _t->on_radioButton_perspective_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 29: _t->on_radioButton_dotted_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: _t->on_radioButton_constant_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 31: _t->on_radioButton_noneVertice_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 32: _t->on_radioButton_circleVertice_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 33: _t->on_radioButton_squareVertice_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 34;
    }
    return _id;
}
QT_WARNING_POP
