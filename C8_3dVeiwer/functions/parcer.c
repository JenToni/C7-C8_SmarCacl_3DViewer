/**
 * @file parcer.c
 * @author sigridva lauralep lezlieda
 * @date 10 August 2023
 * @brief Парсинг .obj файлов и заполнение структуры Model данными
 *
 */

#include "3d_viewer.h"

void freeModel(Model* model) {
  free(model->vertices);
  model->vertices = NULL;

  free(model->all_Faces);

  model->vertices = NULL;
  model->all_Faces = NULL;
  model->Pos_vertices = 0;
  model->Pos_Faces = 0;
  model->sumFaceVertices = 0;
  model->numVertices = 0;
  model->minCoords.x = 0;
  model->minCoords.y = 0;
  model->minCoords.z = 0;
  model->maxCoords.x = 0;
  model->maxCoords.y = 0;
  model->maxCoords.z = 0;
}

///@brief Функция для загрузки модели из файла .obj
int loadObjModel(char* filePath, Model* model) {
  int error = -1;
  FILE* file = fopen(filePath, "r");
  if (file == NULL) {
    // printf("Ошибка: не удалось открыть файл.\n");
    error = open_fails;
  } else {
    // Инициализируем минимальные и максимальные значения координат
    model->minCoords.x = DBL_MAX;
    model->minCoords.y = DBL_MAX;
    model->minCoords.z = DBL_MAX;
    model->maxCoords.x = DBL_MIN;
    model->maxCoords.y = DBL_MIN;
    model->maxCoords.z = DBL_MIN;
    // Считаем размер максимальной строки
    // SEEK_END – смещение отсчитывается от конца файла
    // fseek(file, 0, SEEK_END);
    // ftell определяет текущую позицию
    int size = 2024;
    // ftell(file);
    char line[size];
    /// rewind(file);  // Перемещаем указатель на начало файла
    while (fgets(line, sizeof(line), file) && error < 0) {
      if (line[0] == 'v' && line[1] == ' ') {
        error = load_vertices(line, model);
      } else if (line[0] == 'f' && line[1] == ' ') {
        error = load_faces(line, model);
      }
    }

    //  if (error == 0) fprintf(stderr, "%s", line);
    fclose(file);
  }
  return error;
}

int count_faces(char* line, Model* model, int* error, int* count) {
  for (int i = 2; line[i] != '\0';) {
    while (line[i] == ' ' && line[i] != '\0') i++;
    if (strchr("123456789", line[i]) != NULL ||
        (line[i] == '-' && strchr("123456789", line[i + 1]) != NULL))
      (*count)++;

    while (line[i] != ' ' && line[i] != '\0') i++;
  }
  if (*count < 2) {
    *error = error_faces_in_line_less_two;
  } else {
    if (*count == 2)
      model->sumFaceVertices += *count;
    else
      model->sumFaceVertices += *count * 2;
    model->all_Faces = (unsigned int*)realloc(
        model->all_Faces, sizeof(unsigned int) * model->sumFaceVertices);
  }
  return *error;
}

int load_faces(char* line, Model* model) {
  int error = -1, count = 0;
  error = count_faces(line, model, &error, &count);

  char* p_str = line;
  p_str++;
  int pos = 0, first = 0, i = 0, vertexIndex;
  for (; i < count && error < 0; i++) {
    if (sscanf(p_str, "%d", &vertexIndex) != 1) {
      free(model->all_Faces);
      error = incorrect_faces;
    } else {
      while (*p_str == ' ') {
        p_str++;
      }
      while (*p_str != ' ' && *p_str != '\0') {
        p_str++;
      }
      if (vertexIndex < 0) vertexIndex = model->numVertices + vertexIndex + 1;
      vertexIndex--;
      if (vertexIndex < 0) error = error_in_value_faces;
    }
    if (error < 0) {
      if (count == 2) {
        model->all_Faces[i + model->Pos_Faces + pos] =
            (unsigned int)vertexIndex;
      } else {
        if (i == 0) first = vertexIndex;
        model->all_Faces[i + model->Pos_Faces + pos] =
            (unsigned int)vertexIndex;
        if (i > 0) {
          pos++;
          model->all_Faces[i + model->Pos_Faces + pos] =
              (unsigned int)vertexIndex;
        }
      }
    }
  }
  if (error < 0) {
    if (count > 2) {
      model->all_Faces[i + model->Pos_Faces + pos] = (unsigned int)first;
      model->Pos_Faces += count + 1 + pos;
    } else
      model->Pos_Faces += count;
  }
  return error;
}

int load_vertices(char* line, Model* model) {
  int error = -1;
  double x = 0, y = 0, z = 0;
  if (sscanf(line, "v %lf %lf %lf", &x, &y, &z) != 3) {
    error = fail_in_load_vertices;
  } else {
    // Обновляем минимальные и максимальные значения координат
    // fmin/max по како-то причение не работает на wsl у меня, на маке ок

    model->minCoords.x = fmin(model->minCoords.x, x);
    model->minCoords.y = fmin(model->minCoords.y, y);
    model->minCoords.z = fmin(model->minCoords.z, z);
    model->maxCoords.x = fmax(model->maxCoords.x, x);
    model->maxCoords.y = fmax(model->maxCoords.y, y);
    model->maxCoords.z = fmax(model->maxCoords.z, z);

    // Увеличиваем массив вершин
    model->numVertices++;
    model->vertices = (double*)realloc(model->vertices,
                                       sizeof(double) * model->numVertices * 3);

    // Выделяем память для вершины (x, y, z) и сохраняем ее в матрицу

    model->vertices[model->Pos_vertices++] = x;
    model->vertices[model->Pos_vertices++] = y;
    model->vertices[model->Pos_vertices++] = z;
  }
  return error;
}
