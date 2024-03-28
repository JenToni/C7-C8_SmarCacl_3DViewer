/**
 * @file glwidget.h
 * @author sigridva lauralep lezlieda
 * @date 10 August 2023
 * @brief описание класса openglwidget
 *
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QDebug>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QWidget>

#ifdef __cplusplus
extern "C" {
#endif

#include "../functions/3d_viewer.h"

#ifdef __cplusplus
};
#endif

namespace Ui {
class GLWidget;
}

//!  Основной класс, описывающий данные, необходимые для отрисовки модели
/*!
  Содержит данные, необходимые для: 1) хранения данных о модели \n 2) настройки
  отображения модели 3) координаты мыши относительно рабочего окна (для
  реализации вращения) и другие данные
*/
class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit GLWidget(QWidget *parent = nullptr);
  static Model object;
  void set_sumFaceVertices(int val);  //!< рассчет общего кол-ва граней
  ~GLWidget();
  double width_lines = 1; /*!< ширина линии */
  double width_dots = 1;  /*!< размер вершин */

  int type_lines = CONSTANT; /*!< тип линии */
  int paint_dot = NONE;      /*!< тип отрисовки вершин */
  int projectionType = PERSPECTIVE; /*!< тип проекции */

  float rLine = 0; /*!< r-значнение цвета ребра формации rgb */
  float gLine = 1; /*!< g-значнение цвета ребра формации rgb */
  float bLine = 0; /*!< b-значнение цвета ребра формации rgb */

  float rDot = 1; /*!< r-значнение цвета вершины формации rgb */
  float gDot = 0; /*!< g-значнение цвета вершины формации rgb */
  float bDot = 0; /*!< b-значнение цвета вершины формации rgb */

  float rBack = 0; /*!< r-значнение цвета фона формации rgb */
  float gBack = 0; /*!< g-значнение цвета фона формации rgb */
  float bBack = 1; /*!< b-значнение цвета фона формации rgb */

  double currentX_angle = 0;
  double currentY_angle = 0;
  double currentZ_angle = 0;
  double scaleM = 1; /*!< текущий масштаб */

  QPointF
      mousePosition; /*!< текущее положение мыши (фиксируется после нажатия) */

  int rotationInitializied =
      1; /*!< фиксирование момента нажатия левой кнопкой мыши */
  double angle_x = 0; /*!< значение поворота модели в радианах по оси Х */
  double angle_y = 0; /*!< значение поворота модели в радианах по оси Y */

 protected:
  void initializeGL() override;  //!< инициализация визуальной области
  void paintGL()
      override;  //!< создание видимой области и настройка матрицы координат

 private:
  void draw();  //!< отрисовка модели по заданным настройкам

  void mousePressEvent(
      QMouseEvent *event) override;  //!< фиксация координат по нажатию мыши
  void mouseMoveEvent(
      QMouseEvent *event) override;  //!< изменение координат по движению мыши
  double fixed_angle_x; /*!< фиксация угла поворота модели мышкой (фиксируется
                           после того, как мышка "отжата") */
  double fixed_angle_y; /*!< фиксация угла поворота модели мышкой (фиксируется
                           после того, как мышка "отжата") */
  Ui::GLWidget *ui;
};

#endif  // GLWIDGET_H
