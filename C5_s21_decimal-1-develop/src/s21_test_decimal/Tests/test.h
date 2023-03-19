#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_decimal/s21_decimal_headers/s21_decimal.h"

Suite *test_is_equal_suite(void);
Suite *test_is_not_equal_suite(void);
Suite *test_is_less_suite(void);
Suite *test_is_less_or_equal_suite(void);
Suite *test_is_greater_or_equal_suite(void);
Suite *test_is_greater_suite(void);
Suite *test_add_suite(void);
Suite *test_sub_suite(void);
Suite *test_div_suite(void);
Suite *test_mod_suite(void);
Suite *test_mul_suite(void);
Suite *test_round_suite(void);
Suite *test_negate_suite(void);
Suite *test_truncate_suite(void);
Suite *test_floor_suite(void);
Suite *test_dec_to_float_suite(void);
Suite *test_dec_to_int_suite(void);
Suite *test_int_to_dec_suite(void);
Suite *test_float_to_dec_suite(void);

#endif  // SRC_TESTS_TEST_H_
