#include "glwidget.h"

Model GLWidget::object;

GLWidget::GLWidget(QWidget *parent) { parent->setVisible(true); }

void GLWidget::set_sumFaceVertices(int val) {
  this->object.sumFaceVertices = val;
}

GLWidget::~GLWidget() {
  if (object.vertices) {
    freeModel(&object);
  }
}

void GLWidget::initializeGL() { glClearColor(rBack, gBack, bBack, 1); }

void GLWidget::paintGL() {
  glClearColor(rBack, gBack, bBack, 1);  // background color

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Эти параметры задают ограничения для экрана, точки нормализуются
  // относительно этих границ
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // от Ильи: Дима удалил эти строки, пока не знаю зачем, закомментил их
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();

  //  float top = 1.0f;
  if (projectionType == PERSPECTIVE) {
    glFrustum(-1, 1, -1, 1, 1, 99999);
    glTranslatef(0, 0, -2.6);
  } else if (projectionType == ORTHO) {
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 1000);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(angle_x, 1, 0, 0);
  glRotatef(angle_y, 0, 1, 0);
  if (this->object.vertices !=
      NULL) {  // Если модель не задана, не рисуем ничего
    draw();
  }
}

void GLWidget::draw() {
  glEnableClientState(
      GL_VERTEX_ARRAY);  // разрешение использования массива вершин
  glVertexPointer(3, GL_DOUBLE, 0,
                  object.vertices);  // указатель на массив вершин

  if (type_lines == DOTTED) {
    glEnable(GL_LINE_STIPPLE);  // рисование пунктиром
    glLineStipple(1, 0x00F0);
  } else {
    glDisable(GL_LINE_STIPPLE);  // возврат линий
  }

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // установка режима рисования
  glLineWidth(width_lines);        // установка ширины линии
  glColor3f(rLine, gLine, bLine);  // установка цвета
  glDrawElements(GL_LINES, object.sumFaceVertices, GL_UNSIGNED_INT,
                 object.all_Faces);  // рисование линий

  if (paint_dot > 0) {  // Рисовать ли точки
    if (paint_dot == 1)
      glEnable(GL_POINT_SMOOTH);  // Круг
    else
      glDisable(GL_POINT_SMOOTH);  // Квадрат
    glPointSize(width_dots);
    glColor3d(rDot, gDot, bDot);
    glDrawArrays(GL_POINTS, 0, object.numVertices);
  }

  glDisable(GL_LINE_STIPPLE);
  glDisable(GL_POINT_SMOOTH);

  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
  fixed_angle_y = 0.;
  fixed_angle_x = 0.;

  if (event->buttons() & Qt::LeftButton) {
    this->rotationInitializied = 1;
    this->mousePosition =
        event->position();  // если зажата левая клавиша - вращаем относительно
                            // предыдущей ("повернутой") позиции
  } else if (event->buttons() & Qt::RightButton) {
    angle_x = 0.;
    angle_y = 0.;
    update();
  }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
  if (this->rotationInitializied) {
    fixed_angle_y = angle_y;
    fixed_angle_x = angle_x;
    this->rotationInitializied = 0;
  }
  angle_x =
      fixed_angle_x +
      1 / M_PI * (event->pos().y() - mousePosition.y());  // вывести на экран!
  angle_y = fixed_angle_y + 1 / M_PI * (event->pos().x() - mousePosition.x());

  update();
}
