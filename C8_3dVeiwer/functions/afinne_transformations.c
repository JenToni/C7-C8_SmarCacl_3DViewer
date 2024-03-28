/**
 * @file afinne_transformations.c
 * @author sigridva lauralep lezlieda
 * @date 10 August 2023
 * @brief Все афинные преобразования модели
 *
 * Поворот, увеличение, перемещение модели в центр и др.
 */

#include "3d_viewer.h"

///@brief Помещаем фигуру в центр
///@param Model*model
void Model_in_center(Model* model) {
  double center_x, center_y, center_z;

  center_x = model->minCoords.x + (model->maxCoords.x - model->minCoords.x) / 2;
  center_y = model->minCoords.y + (model->maxCoords.y - model->minCoords.y) / 2;
  center_z = model->minCoords.z + (model->maxCoords.z - model->minCoords.z) / 2;

  for (int i = 0; i < model->numVertices * 3; i += 3) {
    model->vertices[i + X] -= center_x;
    model->vertices[i + Y] -= center_y;
    model->vertices[i + Z] -= center_z;
  }
}

// Изначайное положение фигуры размером 0.5 от всего маштаба
// после этого old_scale = 0.5
void Model_size(Model* model) {
  double x, y, z;

  x = model->maxCoords.x - model->minCoords.x;
  y = model->maxCoords.y - model->minCoords.y;
  z = model->maxCoords.z - model->minCoords.z;

  // Находим максимальное значение
  double max = 0;
  if (x >= y && x >= z) max = x;
  if (y >= x && y >= z) max = y;
  if (z >= x && z >= y) max = z;

  double scal = (0.5 - (0.5 * (-1))) / max;

  for (int i = 0; i < model->numVertices * 3; i += 3) {
    model->vertices[i + X] *= scal;
    model->vertices[i + Y] *= scal;
    model->vertices[i + Z] *= scal;
  }
}

/////@brief Изменение размера фигуры
/////@param Model* model
/////@param new_scale размер фигуры который хотим получить
/////@param odl_scale строе значение
void scale(Model* model, double old_scale, double new_scale) {
  for (int i = 0; i < model->numVertices * 3; i += 3) {
    model->vertices[i + X] *= new_scale / old_scale;
    model->vertices[i + Y] *= new_scale / old_scale;
    model->vertices[i + Z] *= new_scale / old_scale;
  }
}

/////@brief Передвижение фигуры
/////@param Model* model
/////@param vertex  номер точки x = 0, y = 1, z = 2
/////@param old_mean  старое значение перемещения
/////@param new_mean  новое значение перемещения относильтельно старого
// void Move(Model* model, int vertex, double old_mean, double new_mean) {
//   for (int i = 0; i < model->numVertices; i++) {
//     model->vertices[i][vertex] += new_mean - old_mean;
//   }
// }
/////@brief Вращение
/////@param obj Струтура модели
/////@param angle  Угол в градусах
/////@param axis enum: X = 0, Y = 1, Z = 2
void rotate_model(Model* obj, double angle, int axis) {
  from_degrees_to_radians(&angle);

  if (axis == X) {
    for (int r = 0; r < obj->numVertices * 3; r += 3) {
      double temp_y = obj->vertices[r + Y];
      double temp_z = obj->vertices[r + Z];
      obj->vertices[r + Y] = cos(angle) * temp_y + sin(angle) * temp_z;
      obj->vertices[r + Z] = -sin(angle) * temp_y + cos(angle) * temp_z;
    }
  } else if (axis == Y) {
    for (int r = 0; r < obj->numVertices * 3; r += 3) {
      double temp_x = obj->vertices[r + X];
      double temp_z = obj->vertices[r + Z];
      obj->vertices[r + X] = cos(angle) * temp_x - sin(angle) * temp_z;
      obj->vertices[r + Z] = sin(angle) * temp_x + cos(angle) * temp_z;
    }
  } else if (axis == Z) {
    for (int r = 0; r < obj->numVertices * 3; r += 3) {
      double temp_y = obj->vertices[r + Y];
      double temp_x = obj->vertices[r + X];
      obj->vertices[r + X] = cos(angle) * temp_x + sin(angle) * temp_y;
      obj->vertices[r + Y] = -sin(angle) * temp_x + cos(angle) * temp_y;
      // printf("\n");
    }
  }
}

/////@brief Передвижение фигуры
/////@param Model* obj
/////@param axis enum: 0 = X, 1 = Y, 2 = Z
/////@param value  значение перемещения
void move_model(Model* obj, double value, int axis) {
  for (int r = 0; r < obj->numVertices * 3; r += 3) {
    obj->vertices[r + axis] += value;
  }
}

/////@brief Градусы в радианы
/////@param degrees Угол в градусах
void from_degrees_to_radians(double* degrees) {
  *degrees = *degrees * (_PI / 180.);
}
