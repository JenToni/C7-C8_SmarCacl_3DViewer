/**
 * @file mainwindow.h
 * @author sigridva lauralep lezlieda
 * @date 10 August 2023
 * @brief описание класса mainwindow
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qgifimage.h>

#include <QBuffer>
#include <QButtonGroup>
#include <QColorDialog>
#include <QFileDialog>
#include <QImageWriter>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QStandardPaths>
#include <QSystemTrayIcon>
#include <QTimer>

#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#ifdef __cplusplus
extern "C" {
#endif

#include "../functions/3d_viewer.h"

#ifdef __cplusplus
};
#endif

//!  Основной класс приложения
/*!
  Методы класса позволяют менять настройки модели, саму модель и реализовывать
  другие действия.
*/

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  GLWidget *view;
  ~MainWindow();

  void setColors();  //!< установка базового цвета

 private slots:
  void on_open_file_clicked();  //!< метод загрузки данных из файла
  void on_MainWindow_destroyed();

  // Цвета
  void on_pushButton_colorEdge_clicked();
  void on_pushButton_colorVertice_clicked();
  void on_pushButton_colorBackg_clicked();

  // движение модели
  void on_moveXInput_valueChanged(double arg1);
  void on_moveYInput_valueChanged(double arg1);
  void on_moveZInput_valueChanged(double arg1);

  // вращение модели + изменение значение угла поворота с помощью слайдера
  void rotateModel(int axis, double angle);
  void on_rotateXInput_valueChanged(double arg1);
  void on_rotateYInput_valueChanged(double arg1);
  void on_rotateZInput_valueChanged(double arg1);
  void on_rotationX_slider_valueChanged(int value);
  void on_rotationY_slider_valueChanged(int value);
  void on_rotationZ_slider_valueChanged(int value);

  // gif
  void on_pushButton_Gif_mode_1_clicked();
  void on_pushButton_Gif_mode_2_clicked();
  void makeGif();

  void
  on_pushButton_downloadImage_clicked();  //!< рендеринг и скачивание фотографии

  // масштаб
  void on_scaleSpinBox_valueChanged(int arg1);
  void on_scaleSlider_valueChanged(int value);
  void scaleModel();
  void on_scaleToDefault_clicked();

  // толщина рёбер
  void on_edgeWidth_slider_valueChanged(int value);
  void on_edgeWidth_spinbox_valueChanged(int arg1);

  // размер вершин
  void on_verticeSize_spinbox_valueChanged(double arg1);
  void on_verticeSize_slider_valueChanged(int value);

  // радиобаттоны
  void on_radioButton_orthogonal_toggled(bool checked);
  void on_radioButton_perspective_toggled(bool checked);
  void on_radioButton_dotted_toggled(bool checked);
  void on_radioButton_constant_toggled(bool checked);
  void on_radioButton_noneVertice_toggled(bool checked);
  void on_radioButton_circleVertice_toggled(bool checked);
  void on_radioButton_squareVertice_toggled(bool checked);

 private:
  Ui::MainWindow *ui;
  GLWidget *glInterface;
  QTimer *tmr;
  QImage images[50];
  int frameCount;
  int gifMode = 0;
  void throwError(QString log);  //!< создание уведомления об ошибке
  void resetMovement();  //!< сброс настроек перемещения модели
  void saveSettings();  //!< сохранение настроек (применяется после закрытия
                        //!< программы)
  void applySettings();  //!< применение настроек (вызывается после открытия
                         //!< программы)
  double moveX = 0;
  double moveY = 0;
  double moveZ = 0;
};
#endif  // MAINWINDOW_H
