#include "test_3d_viewer.h"

START_TEST(rotate_model_1) {
  Model test;
  test.numVertices = 8;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[24] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                    0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double rotated[] = {
      0,       0,    0, 0,   0.5,     0.86602, 0,       0.86602,
      -0.5,    1,    0, 0,   0,       1.36602, 0.36602, 1,
      0.86602, -0.5, 1, 0.5, 0.86602, 1,       1.36602, 0.36602,
  };

  rotate_model(&test, 30., X);
  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - rotated[r] < 1e-5, 1);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(rotate_model_2) {
  Model test;
  test.numVertices = 8;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double rotated[] = {0,       0, 0,       -0.5,    0, 0.86602, 0,       1, 0,
                      0.86602, 0, 0.5,     -0.5,    1, 0.86602, 0.86602, 1, 0.5,
                      0.36602, 0, 1.36602, 0.36602, 1, 1.36602};

  rotate_model(&test, 30., Y);
  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - rotated[r] < 1e-5, 1);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(rotate_model_3) {
  Model test;
  test.numVertices = 8;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double rotated[] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000,
                      1.000000, 0.707107, 0.707107, 0.000000, 0.707107,
                      -0.70710, 0.000000, 0.707107, 0.707107, 1.000000,
                      1.414214, 0.000000, 0.000000, 0.707107, -0.70710,
                      1.000000, 1.414214, 0.000000, 1.000000};

  rotate_model(&test, 45., Z);
  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - rotated[r] < 1e-5, 1);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(move_model_x) {
  Model test;
  test.numVertices = 8;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double moved[] = {4, 0, 0, 4, 0, 1, 4, 1, 0, 5, 0, 0,
                    4, 1, 1, 5, 1, 0, 5, 0, 1, 5, 1, 1};

  move_model(&test, 4., X);
  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - moved[r] < 1e-5, 1);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(move_model_y) {
  Model test;
  test.numVertices = 8;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double moved[] = {0, 3.5, 0, 0, 3.5, 1, 0, 4.5, 0, 1, 3.5, 0,
                    0, 4.5, 1, 1, 4.5, 0, 1, 3.5, 1, 1, 4.5, 1};

  move_model(&test, 3.5, Y);
  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - moved[r] < 1e-5, 1);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(move_model_z) {
  Model test;
  test.numVertices = 8;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double moved[] = {0, 0, -6, 0, 0, -5, 0, 1, -6, 1, 0, -6,
                    0, 1, -5, 1, 1, -6, 1, 0, -5, 1, 1, -5};

  move_model(&test, -6., Z);
  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - moved[r] < 1e-5, 1);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(model_in_center) {
  Model test;
  test.numVertices = 8;
  test.minCoords.x = 0;
  test.minCoords.y = 0;
  test.minCoords.z = 0;
  test.maxCoords.x = 1;
  test.maxCoords.y = 1;
  test.maxCoords.z = 1;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[24] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                    0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};

  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }

  double center[24] = {-0.5, -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, 0.5,
                       -0.5, 0.5,  -0.5, -0.5, -0.5, 0.5, 0.5,  0.5,
                       0.5,  -0.5, 0.5,  -0.5, 0.5,  0.5, 0.5,  0.5};

  Model_in_center(&test);

  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - center[r], 0);
  }
  if (test.vertices != NULL) {
    free(test.vertices);
  }
}
END_TEST

START_TEST(model_size) {
  Model test;
  test.numVertices = 8;
  test.minCoords.x = 0;
  test.minCoords.y = 0;
  test.minCoords.z = 0;
  test.maxCoords.x = 1;
  test.maxCoords.y = 1;
  test.maxCoords.z = 1;
  test.vertices = (double *)malloc((24) * sizeof(double));
  double arr[24] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                    0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};

  for (int r = 0; r < 24; r++) {
    test.vertices[r] = arr[r];
  }

  double size[24] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                     0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};

  Model_size(&test);

  for (int r = 0; r < 24; r++) {
    ck_assert_int_eq(test.vertices[r] - size[r], 0);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

START_TEST(mode_scale) {
  Model test;
  test.numVertices = 8;
  test.minCoords.x = 0;
  test.minCoords.y = 0;
  test.minCoords.z = 0;
  test.maxCoords.x = 1;
  test.maxCoords.y = 1;
  test.maxCoords.z = 1;
  test.vertices = (double *)malloc((test.numVertices * 3) * sizeof(double));
  double arr[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
                  0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};

  for (int r = 0; r < test.numVertices * 3; r++) {
    test.vertices[r] = arr[r];
  }
  scale(&test, 1, 2);

  double Scale[] = {0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0,
                    0, 2, 2, 2, 2, 0, 2, 0, 2, 2, 2, 2};

  Model_size(&test);

  for (int r = 0; r < test.numVertices * 3; r++) {
    ck_assert_int_eq(test.vertices[r] - Scale[r], 0);
  }
  if (test.vertices != NULL) free(test.vertices);
}
END_TEST

Suite *test_rotate_model() {
  Suite *s = suite_create("\033[43mTEST_ROTATE_MODEL\033[0m");
  TCase *tc = tcase_create("TEST_ROTATE_MODEL");

  tcase_add_test(tc, rotate_model_1);
  tcase_add_test(tc, rotate_model_2);
  tcase_add_test(tc, rotate_model_3);
  tcase_add_test(tc, move_model_x);
  tcase_add_test(tc, move_model_y);
  tcase_add_test(tc, move_model_z);
  tcase_add_test(tc, model_in_center);
  tcase_add_test(tc, model_size);
  tcase_add_test(tc, mode_scale);
  suite_add_tcase(s, tc);
  return s;
}
