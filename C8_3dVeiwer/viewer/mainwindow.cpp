/**
 * @file mainwindow.cpp
 * @author sigridva lauralep lezlieda
 * @date 10 August 2023
 * @brief формирование интерфейса программы
 *
 */

#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  glInterface = ui->viewport;

  // убираем стрелки у спинБоксов и делаем десятичную точку вместо запятой
  ui->rotateXInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->rotateXInput->setLocale(QLocale::C);
  ui->rotateYInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->rotateYInput->setLocale(QLocale::C);
  ui->rotateZInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->rotateZInput->setLocale(QLocale::C);
  ui->scaleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->edgeWidth_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->edgeWidth_spinbox->setLocale(QLocale::C);
  ui->verticeSize_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->verticeSize_spinbox->setLocale(QLocale::C);
  ui->moveXInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->moveXInput->setLocale(QLocale::C);
  ui->moveYInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->moveYInput->setLocale(QLocale::C);
  ui->moveZInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->moveZInput->setLocale(QLocale::C);

  // добавляем радиобаттоны в группы и включаем по умолчанию
  // тип проекции
  QButtonGroup *groupProjection = new QButtonGroup(this);
  groupProjection->addButton(ui->radioButton_orthogonal);
  groupProjection->addButton(ui->radioButton_perspective);
  ui->radioButton_perspective->toggle();

  // тип линий
  QButtonGroup *groupEdges = new QButtonGroup(this);
  groupEdges->addButton(ui->radioButton_constant);
  groupEdges->addButton(ui->radioButton_dotted);
  ui->radioButton_constant->toggle();

  // тип отображения вершин
  QButtonGroup *groupVertices = new QButtonGroup(this);
  groupVertices->addButton(ui->radioButton_noneVertice);
  groupVertices->addButton(ui->radioButton_circleVertice);
  groupVertices->addButton(ui->radioButton_squareVertice);
  ui->radioButton_noneVertice->toggle();

  // формат для сожранения изображения
  QButtonGroup *saveFormat = new QButtonGroup(this);
  saveFormat->addButton(ui->radioButton_jpgFormat);
  saveFormat->addButton(ui->radioButton_bmpFormat);
  ui->radioButton_jpgFormat->toggle();

  applySettings();
  setColors();
}

MainWindow::~MainWindow() {
  saveSettings();
  if (glInterface->object.vertices || glInterface->object.all_Faces) {
    freeModel(&glInterface->object);
  }
  delete glInterface;
  delete ui;
}

void MainWindow::on_open_file_clicked() {
  QString filename =
      QFileDialog::getOpenFileName(this, "Choose a file", "/", "*.obj");

  ui->label_filepathInfo->setText("");
  ui->label_verticesInfo->setText("");
  ui->label_edgesNumber->setText("");

  QByteArray ba = filename.toLocal8Bit();
  char *fname = ba.data();

  if (glInterface->object.vertices || glInterface->object.all_Faces) {
    freeModel(&glInterface->object);
  }

  int status = loadObjModel(fname, &(glInterface->object));
  if (status != -1) {
    freeModel(&(glInterface->object));
    if (status == 0) throwError("Ошибка: не удалось открыть файл");
    if (status == 1)
      throwError("Ошибка: Некорректные данные для вершин в файле .obj");
    if (status == 2)
      throwError("Ошибка: Некорректные данные для грани в файле .obj");
    if (status == 3) throwError("Ошибка: Некорректное значениe faces ");
    if (status == 4) throwError("Ошибка: Количество faces в строке меньше 2 ");
  } else {
    Model_in_center(&glInterface->object);
    Model_size(&glInterface->object);
    filename.chop(4);
    ui->label_filepathInfo->setText(
        filename.sliced(filename.lastIndexOf("/") + 1));
    ui->label_verticesInfo->setText(
        QString::number(glInterface->object.numVertices));
    ui->label_edgesNumber->setText(
        QString::number(glInterface->object.sumFaceVertices / 2));
    resetMovement();
    glInterface->update();
  }
}

///@brief Сброс поворотов, движения, масштаба модели
void MainWindow::resetMovement() {
  ui->viewport->currentX_angle = 0;
  ui->viewport->angle_x = 0;
  ui->rotateXInput->setValue(0);

  ui->viewport->currentY_angle = 0;
  ui->viewport->angle_y = 0;
  ui->rotateYInput->setValue(0);

  ui->viewport->currentZ_angle = 0;
  ui->rotateZInput->setValue(0);

  ui->viewport->scaleM = 1;
  ui->scaleSpinBox->setValue(100);

  ui->moveXInput->setValue(0);
  moveX = 0;
  ui->moveYInput->setValue(0);
  moveY = 0;
  ui->moveZInput->setValue(0);
  moveZ = 0;
}

///@brief Очищение динамической памяти, выделенной для модели
void MainWindow::on_MainWindow_destroyed() { freeModel(&glInterface->object); }

///@brief Вращение вокруг оси X слайдером
void MainWindow::on_rotateXInput_valueChanged(double arg1) {
  ui->rotationX_slider->setValue(ui->rotateXInput->value() / 2);
  rotateModel(X, arg1);
}

///@brief Вращение вокруг оси X спинбоксом
void MainWindow::on_rotationX_slider_valueChanged(int value) {
  ui->rotateXInput->setValue((double)value * 2);
  rotateModel(X, (double)value * 2);
}

///@brief Вращение вокруг оси Y слайдером
void MainWindow::on_rotateYInput_valueChanged(double arg1) {
  ui->rotationY_slider->setValue(ui->rotateYInput->value() / 2);
  rotateModel(Y, arg1);
}

///@brief Вращение вокруг оси Y спинбоксом
void MainWindow::on_rotationY_slider_valueChanged(int value) {
  ui->rotateYInput->setValue((double)value * 2);
  rotateModel(Y, (double)value * 2);
}

///@brief Вращение вокруг оси Z слайдером
void MainWindow::on_rotateZInput_valueChanged(double arg1) {
  ui->rotationZ_slider->setValue(ui->rotateZInput->value() / 2);
  rotateModel(Z, arg1);
}

///@brief Вращение вокруг оси Z спинбоксом
void MainWindow::on_rotationZ_slider_valueChanged(int value) {
  ui->rotateZInput->setValue((double)value * 2);
  rotateModel(Z, (double)value * 2);
}

void MainWindow::on_moveXInput_valueChanged(double arg1) {
  if (glInterface->object.vertices) {
    move_model(&glInterface->object, (arg1 - moveX) / 100, X);
    glInterface->update();
  }
  moveX = arg1;
}

void MainWindow::on_moveYInput_valueChanged(double arg1) {
  if (glInterface->object.vertices) {
    move_model(&glInterface->object, (arg1 - moveY) / 100, Y);
    glInterface->update();
  }
  moveY = arg1;
}

void MainWindow::on_moveZInput_valueChanged(double arg1) {
  if (glInterface->object.vertices) {
    move_model(&glInterface->object, (arg1 - moveZ) / 100, Z);
    glInterface->update();
  }
  moveZ = arg1;
}

void MainWindow::throwError(QString log) {
  QMessageBox messageBox;
  messageBox.critical(0, "Error", log);
  messageBox.setFixedSize(500, 200);
}

///@brief Закрашивает квадратики в главном окне в соответствующие выбранные
// цвета
void MainWindow::setColors() {
  QString colorLines = QString("background: rgb(%1, %2, %3);")
                           .arg(glInterface->rLine * 255)
                           .arg(glInterface->gLine * 255)
                           .arg(glInterface->bLine * 255);
  ui->label_colorEdges->setStyleSheet(colorLines);
  QString colorVertices = QString("background: rgb(%1, %2, %3);")
                              .arg(glInterface->rDot * 255)
                              .arg(glInterface->gDot * 255)
                              .arg(glInterface->bDot * 255);
  ui->label_colorVertice->setStyleSheet(colorVertices);
  QString colorBackg = QString("background: rgb(%1, %2, %3);")
                           .arg(glInterface->rBack * 255)
                           .arg(glInterface->gBack * 255)
                           .arg(glInterface->bBack * 255);
  ui->label_colorBackg->setStyleSheet(colorBackg);
}

///@brief Выбор цвета граней
void MainWindow::on_pushButton_colorEdge_clicked() {
  QColor lineColor = QColorDialog::getColor(Qt::white, this);
  lineColor.getRgbF(&glInterface->rLine, &glInterface->gLine,
                    &glInterface->bLine);
  setColors();
}

///@brief Выбор цвета вершин
void MainWindow::on_pushButton_colorVertice_clicked() {
  QColor verticeColor = QColorDialog::getColor(Qt::white, this);
  verticeColor.getRgbF(&glInterface->rDot, &glInterface->gDot,
                       &glInterface->bDot);
  setColors();
}

///@brief Выбор цвета фона
void MainWindow::on_pushButton_colorBackg_clicked() {
  QColor backgColor = QColorDialog::getColor(Qt::white, this);
  backgColor.getRgbF(&glInterface->rBack, &glInterface->gBack,
                     &glInterface->bBack);
  setColors();
}

///@brief Сохранение изображения выбранного формата
void MainWindow::on_pushButton_downloadImage_clicked() {
  QImage screenShot = ui->viewport->grabFramebuffer();
  QString format = (ui->radioButton_jpgFormat->isChecked()) ? "*.jpg" : "*.bmp";
  QString str =
      QFileDialog::getSaveFileName(0, "Сохранить файл как", "", format);
  screenShot.save(str, format.remove(0, 2).toUpper().toLocal8Bit());
}

///@brief Запускает таймер и включает режим сохранения .gif 640х480
void MainWindow::on_pushButton_Gif_mode_1_clicked() {
  frameCount = 0;
  gifMode = 1;
  tmr = new QTimer();
  connect(tmr, SIGNAL(timeout()), this, SLOT(makeGif()));
  tmr->start(100);
}

///@brief Запускает таймер и включает режим сохранения .gif в максимальном
// разрешении
void MainWindow::on_pushButton_Gif_mode_2_clicked() {
  frameCount = 0;
  gifMode = 2;
  tmr = new QTimer();
  connect(tmr, SIGNAL(timeout()), this, SLOT(makeGif()));
  tmr->start(100);
}

///@brief Сохранение .gif в заданном разрешении
void MainWindow::makeGif() {
  QGifImage gif;
  if (frameCount == 50) {
    tmr->stop();
    disconnect(tmr);
    delete (tmr);
    frameCount = 0;
    for (int i = 0; i < 50; gif.addFrame(images[i++], 100)) {
    }
    QString str =
        QFileDialog::getSaveFileName(0, "Сохранить файл как", "", "*.gif");
    gif.save(str);
  } else {
    if (gifMode == 1) {
      images[frameCount++] = ui->viewport->grabFramebuffer().scaled(
          640, 480, Qt::IgnoreAspectRatio);
    } else if (gifMode == 2) {
      images[frameCount++] = ui->viewport->grabFramebuffer();
    }
  }
}

///@brief Функция для вращения модели после изменения ползунков вращения
void MainWindow::rotateModel(int axis, double angle) {
  double rotation = 0;
  switch (axis) {
    case X:
      rotation = angle > glInterface->currentX_angle
                     ? angle - glInterface->currentX_angle
                     : -(glInterface->currentX_angle - angle);
      if (glInterface->object.vertices) {
        rotate_model(&(glInterface->object), rotation, X);
        glInterface->currentX_angle = angle;
      }
      break;
    case Y:
      rotation = angle > glInterface->currentY_angle
                     ? angle - glInterface->currentY_angle
                     : -(glInterface->currentY_angle - angle);
      if (glInterface->object.vertices) {
        rotate_model(&(glInterface->object), rotation, Y);
        glInterface->currentY_angle = angle;
      }
      break;
    case Z:
      rotation = angle > glInterface->currentZ_angle
                     ? angle - glInterface->currentZ_angle
                     : -(glInterface->currentZ_angle - angle);
      if (glInterface->object.vertices) {
        rotate_model(&(glInterface->object), rotation, Z);
        glInterface->currentZ_angle = angle;
      }
      break;
    default:
      break;
  }
  glInterface->update();
}

/// @brief Применяет настройки с предыдущего запуска
void MainWindow::applySettings() {
  QSettings settings("s21", "viewer");
  if (settings.contains("viewerSettings/edgeDotted")) {
    // загрузка типа проекции
    ui->radioButton_orthogonal->setChecked(
        settings.value("viewerSettings/projection_orthogonal").toBool());

    // загрузка типа рёбер
    if (settings.value("viewerSettings/edgeDotted").toBool()) {
      ui->radioButton_dotted->toggle();
    } else {
      ui->radioButton_constant->toggle();
    }
    // загрузка цвета ребер
    glInterface->rLine = settings.value("viewerSettings/edgeColor/r").toFloat();
    glInterface->gLine = settings.value("viewerSettings/edgeColor/g").toFloat();
    glInterface->bLine = settings.value("viewerSettings/edgeColor/b").toFloat();

    // загрузка толщины рёбер
    glInterface->width_lines =
        settings.value("viewerSettings/edgeWidth").toFloat();
    ui->edgeWidth_spinbox->setValue(
        settings.value("viewerSettings/edgeWidth").toFloat());

    // загрузка размера вершин
    glInterface->width_dots =
        settings.value("viewerSettings/verticeSize").toFloat();
    ui->verticeSize_spinbox->setValue(
        settings.value("viewerSettings/verticeSize").toFloat());

    // загрузка типа вершин
    if (settings.value("viewerSettings/noneVertice").toBool()) {
      ui->radioButton_noneVertice->toggle();
      glInterface->paint_dot = 0;
    } else if (settings.value("viewerSettings/circleVertice").toBool()) {
      ui->radioButton_circleVertice->toggle();
      glInterface->paint_dot = 1;
    } else {
      ui->radioButton_squareVertice->toggle();
      glInterface->paint_dot = 2;
    }

    // загрузка цвета вершин
    glInterface->rDot =
        settings.value("viewerSettings/verticeColor/r").toFloat();
    glInterface->gDot =
        settings.value("viewerSettings/verticeColor/g").toFloat();
    glInterface->bDot =
        settings.value("viewerSettings/verticeColor/b").toFloat();

    // загрузка цвета фона
    glInterface->rBack =
        settings.value("viewerSettings/backgroundColor/r").toFloat();
    glInterface->gBack =
        settings.value("viewerSettings/backgroundColor/g").toFloat();
    glInterface->bBack =
        settings.value("viewerSettings/backgroundColor/b").toFloat();

    glInterface->update();
  }
}

///@brief Сохранение настроек перед закрытием программы
void MainWindow::saveSettings() {
  QSettings settings("s21", "viewer");
  // тип проекции
  settings.setValue("viewerSettings/projection_orthogonal",
                    ui->radioButton_orthogonal->isChecked());
  // тип ребер
  settings.setValue("viewerSettings/edgeDotted",
                    ui->radioButton_dotted->isChecked());
  // цвет ребер
  settings.setValue("viewerSettings/edgeColor/r", glInterface->rLine);
  settings.setValue("viewerSettings/edgeColor/g", glInterface->gLine);
  settings.setValue("viewerSettings/edgeColor/b", glInterface->bLine);

  // толщина рёбер
  settings.setValue("viewerSettings/edgeWidth", glInterface->width_lines);

  // тип вершин
  settings.setValue("viewerSettings/noneVertice",
                    ui->radioButton_noneVertice->isChecked());
  settings.setValue("viewerSettings/circleVertice",
                    ui->radioButton_circleVertice->isChecked());
  // размер вершин
  settings.setValue("viewerSettings/verticeSize",
                    ui->verticeSize_spinbox->value());
  // цвет вершин
  settings.setValue("viewerSettings/verticeColor/r", glInterface->rDot);
  settings.setValue("viewerSettings/verticeColor/g", glInterface->gDot);
  settings.setValue("viewerSettings/verticeColor/b", glInterface->bDot);

  // цвет фона
  settings.setValue("viewerSettings/backgroundColor/r", glInterface->rBack);
  settings.setValue("viewerSettings/backgroundColor/g", glInterface->gBack);
  settings.setValue("viewerSettings/backgroundColor/b", glInterface->bBack);

  settings.sync();
}

///@brief Изменение масштаба спинбоксом
void MainWindow::on_scaleSpinBox_valueChanged(int arg1) {
  ui->scaleSlider->setValue(arg1);
  scaleModel();
}

///@brief Изменение масштаба слайдером
void MainWindow::on_scaleSlider_valueChanged(int value) {
  ui->scaleSpinBox->setValue(value);
  scaleModel();
}

///@brief Изменение масштаба модели
void MainWindow::scaleModel() {
  double scaleValue = (double)ui->scaleSlider->value() / 100;
  scale(&(glInterface->object), glInterface->scaleM, scaleValue);
  glInterface->scaleM = scaleValue;
  glInterface->update();
}

///@brief Сброс масштаба в 100%
void MainWindow::on_scaleToDefault_clicked() { ui->scaleSlider->setValue(100); }

// фуекции для толщины рёбер
void MainWindow::on_edgeWidth_slider_valueChanged(int value) {
  ui->edgeWidth_spinbox->setValue(value);
  glInterface->width_lines = value;
  glInterface->update();
}

void MainWindow::on_edgeWidth_spinbox_valueChanged(int arg1) {
  ui->edgeWidth_slider->setValue(arg1);
  glInterface->width_lines = arg1;
  glInterface->update();
}

// функции для размера вершин
void MainWindow::on_verticeSize_slider_valueChanged(int value) {
  ui->verticeSize_spinbox->setValue((double)value / 100);
  glInterface->width_dots = (double)value / 100;
  glInterface->update();
}

void MainWindow::on_radioButton_orthogonal_toggled(bool checked) {
  (void)checked;
  glInterface->projectionType = ORTHO;
  glInterface->update();
}

void MainWindow::on_verticeSize_spinbox_valueChanged(double arg1) {
  ui->verticeSize_slider->setValue(arg1 * 100);
  glInterface->width_dots = arg1;
  glInterface->update();
}

void MainWindow::on_radioButton_perspective_toggled(bool checked) {
  (void)checked;
  glInterface->projectionType = PERSPECTIVE;
  glInterface->update();
}

void MainWindow::on_radioButton_dotted_toggled(bool checked) {
  (void)checked;
  glInterface->type_lines = DOTTED;
  glInterface->update();
}

void MainWindow::on_radioButton_constant_toggled(bool checked) {
  (void)checked;
  glInterface->type_lines = CONSTANT;
  glInterface->update();
}

void MainWindow::on_radioButton_noneVertice_toggled(bool checked) {
  (void)checked;
  glInterface->paint_dot = 0;
  glInterface->update();
}

void MainWindow::on_radioButton_circleVertice_toggled(bool checked) {
  (void)checked;
  glInterface->paint_dot = 1;
  glInterface->update();
}

void MainWindow::on_radioButton_squareVertice_toggled(bool checked) {
  (void)checked;
  glInterface->paint_dot = 2;
  glInterface->update();
}
