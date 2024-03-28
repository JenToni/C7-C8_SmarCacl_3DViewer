#include "test_3d_viewer.h"

// Тест на открытие полнотью валидного файла
START_TEST(load_model_1) {
  Model test;
  test.all_Faces = NULL;
  test.vertices = NULL;
  test.Pos_vertices = 0;
  test.Pos_Faces = 0;
  test.numVertices = 0;
  test.sumFaceVertices = 0;

  int status = loadObjModel("./obj/Glass.obj", &test);
  //  ck_assert_int_eq(test.numVertices - 1136 < 1e-5, 1);
  ck_assert_int_eq(status, -1);
  freeModel(&test);
}
END_TEST
// Тест на отрицательные faces
START_TEST(load_model_2) {
  Model test;
  test.all_Faces = NULL;
  test.vertices = NULL;
  test.Pos_vertices = 0;
  test.Pos_Faces = 0;
  test.numVertices = 0;
  test.sumFaceVertices = 0;

  int status = loadObjModel("./obj/skull.obj", &test);
  // ck_assert_int_eq(test.numVertices - 363695 < 1e-5, 1);
  ck_assert_int_eq(status, -1);
  freeModel(&test);
}
END_TEST

//  Тест на отрицательный faces который больше возможного
START_TEST(load_model_3) {
  Model test;
  test.all_Faces = NULL;
  test.vertices = NULL;
  test.Pos_vertices = 0;
  test.Pos_Faces = 0;
  test.numVertices = 0;
  test.sumFaceVertices = 0;

  int status = loadObjModel("./obj/ball.obj", &test);
  //  ck_assert_int_eq(test.numVertices - 772 < 1e-5, 1);
  ck_assert_int_eq(status, 3);
  freeModel(&test);
}
END_TEST

// Тест на открытие не сущ. файла
START_TEST(load_model_4) {
  Model test;
  test.all_Faces = NULL;
  test.vertices = NULL;
  test.Pos_vertices = 0;
  test.Pos_Faces = 0;
  test.numVertices = 0;
  test.sumFaceVertices = 0;
  int status = loadObjModel("./obj/EEEE.obj", &test);
  ck_assert_int_eq(status, 0);
  freeModel(&test);
}
END_TEST

//  Тест на  faces < 2
START_TEST(load_model_5) {
  Model test;
  test.all_Faces = NULL;
  test.vertices = NULL;
  test.Pos_vertices = 0;
  test.Pos_Faces = 0;
  test.numVertices = 0;
  test.sumFaceVertices = 0;
  // Сюда засунуть относительный путь до файла .obj
  int status = loadObjModel("./obj/pyramid.obj", &test);
  //  ck_assert_int_eq(test.numVertices - 772 < 1e-5, 1);
  ck_assert_int_eq(status, 4);
  freeModel(&test);
}
END_TEST

END_TEST

Suite *test_load_model() {
  Suite *s = suite_create("\033[43mTEST_LOAD_MODEL\033[0m");
  TCase *tc = tcase_create("TEST_LOAD_MODEL");

  tcase_add_test(tc, load_model_1);
  tcase_add_test(tc, load_model_2);
  tcase_add_test(tc, load_model_3);
  tcase_add_test(tc, load_model_4);
  tcase_add_test(tc, load_model_5);
  suite_add_tcase(s, tc);
  return s;
}