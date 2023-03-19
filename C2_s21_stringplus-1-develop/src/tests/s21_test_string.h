#ifndef S21_TEST_STRING_H_
#define S21_TEST_STRING_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../s21_string.h"

Suite *suite_strlen(void);
Suite *suite_strncat(void);
Suite *suite_strspn(void);
Suite *suite_strcspn(void);
Suite *suite_strtok(void);
Suite *test_sprintf_c(void);
Suite *test_sprintf_d(void);
Suite *test_sprintf_i(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_s(void);
Suite *test_sprintf_u(void);
Suite *test_sprintf_percent(void);
Suite *test_insert(void);
Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memmove(void);
Suite *test_memset(void);
Suite *test_strcpy(void);
Suite *test_strcat(void);
Suite *test_strchr(void);
Suite *test_strcmp(void);
Suite *test_strerror(void);
Suite *test_strncmp(void);
Suite *test_strncpy(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strstr(void);
Suite *test_to_lower(void);
Suite *test_to_upper(void);
Suite *test_trim(void);

#endif  // S21_TEST_STRING_H_