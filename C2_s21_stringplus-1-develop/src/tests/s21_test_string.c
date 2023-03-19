#include "s21_test_string.h"

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define WHITE "\x1B[0m"

int main() {
  Suite *suite[] = {suite_strlen(),   suite_strncat(),
                    suite_strspn(),   suite_strcspn(),
                    suite_strtok(),   test_sprintf_c(),
                    test_sprintf_d(), test_sprintf_i(),
                    test_sprintf_f(), test_sprintf_s(),
                    test_sprintf_u(), test_sprintf_percent(),
                    test_insert(),    test_memchr(),
                    test_memcmp(),    test_memcpy(),
                    test_memmove(),   test_memset(),
                    test_strcpy(),    test_strcat(),
                    test_strchr(),    test_strcmp(),
                    test_strerror(),  test_strncmp(),
                    test_strncpy(),   test_strpbrk(),
                    test_strrchr(),   test_strstr(),
                    test_to_lower(),  test_to_upper(),
                    test_trim(),      NULL};
  int failed_count = 0;

  for (Suite **count_suite = suite; *count_suite != suite[31]; count_suite++) {
    SRunner *suite_runner = srunner_create(*count_suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    if (failed_count != 0)
      printf(RED "Failed\n" WHITE);
    else
      printf(GREEN "Success\n" WHITE);
  }

  return 0;
}
