/**
 * @file 3d_viewer.h
 * @author sigridva lauralep lezlieda
 * @date 2 August 2023
 * @brief File containing all C-functions for 3D Viewer project
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 */

#ifndef S21_3D_VIEWER_H
#define S21_3D_VIEWER_H
#define _PI 3.1415926535

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum axes { X = 0, Y = 1, Z = 2 };
enum projections { ORTHO = 0, PERSPECTIVE = 1 };
enum type_edge { DOTTED = 0, CONSTANT = 1 };
enum seting_verticle {
  NONE = 0,
  CIRCLE = 1,
  SQUARE = 2,
};

enum errors {
  open_fails = 0,
  fail_in_load_vertices = 1,
  incorrect_faces = 2,
  error_in_value_faces = 3,
  error_faces_in_line_less_two = 4
};

///@brief Структура для хранения координат
typedef struct {
  double x, y, z;
} Coords;

///@brief Общая структура для хранения 3D модели
///@param *vertices
// Матрица вершин (каждая строка - вершина, столбцы - x, y,z)
///@param *all_Faces Хранит в себе грани
///@param Pos_Faces Индекс конца all_Faces
///@param sumFaceVertices Общее количество точек сединений
///@param numVertices Количество вершин
///@param minCoords Минимальные значения координат (x, y, z)
///@param maxCoords Максимальные значения координат (x, y, z)
typedef struct {
  double* vertices;
  unsigned int* all_Faces;
  int Pos_vertices;
  int Pos_Faces;
  int sumFaceVertices;
  int numVertices;
  Coords minCoords;
  Coords maxCoords;
} Model;

int load_faces(char* line, Model* model);
int load_vertices(char* line, Model* model);
int loadObjModel(char* filePath, Model* model);
void Model_size(Model* model);
void freeModel(Model* model);

//////////////
void from_degrees_to_radians(double* degrees);
void move_model(Model* obj, double value, int axis);
void rotate_model(Model* obj, double angle, int axis);
void scale(Model* model, double odl_scale, double new_scale);
void Model_in_center(Model* model);

#endif  // 3D_VIEWER_H
