
#include "tests.h"

int main() {
  int failed = 0;
  int passed = 0;

  Suite *s21_string_test[] = {tests(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    passed += srunner_ntests_run(sr) - srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("========= PASSED: %d =========\n", passed);
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
