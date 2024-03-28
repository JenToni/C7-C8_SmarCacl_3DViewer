#include <check.h>

#include "test_3d_viewer.h"

static void run_test(Suite *s, int *failed) {
  SRunner *sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  *failed += srunner_ntests_failed(sr);
  srunner_free(sr);
}

int main() {
  int failed = 0;
  Suite *s21_matrix_test[] = {test_load_model(), test_rotate_model(), NULL};

  printf("\n ====== TESTING ======\n\n");

  for (Suite **s = s21_matrix_test; *s != NULL; s++) {
    run_test(*s, &failed);
  }

  printf("\n====== FAILED: %d ======\n", failed);

  return (failed) ? 1 : 0;
}