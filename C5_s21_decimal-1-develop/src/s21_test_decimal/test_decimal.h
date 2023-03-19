#ifndef __TEST_DECIMAL_H__
#define __TEST_DECIMAL_H__

#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_decimal/s21_decimal_headers/s21_decimal.h"

#define color_text(test_name) "\033[33;41m" #test_name "\033[0m"

#define assert_decimal_eq(res, orig) {for (int i = 0; i < 4; ++i) { ck_assert_int_eq(res.bits[i], orig.bits[i]); }}

extern Suite *test_add(void);
extern Suite *test_sub(void);
extern Suite *test_mul(void);
extern Suite *test_div(void);
extern Suite *test_mod(void);

extern Suite *test_is_less(void);
extern Suite *test_is_less_or_equal(void);
extern Suite *test_is_greater(void);
extern Suite *test_is_greater_or_equal(void);
extern Suite *test_is_equal(void);
extern Suite *test_is_not_equal(void);

extern Suite *test_from_int_to_decimal(void);
extern Suite *test_from_float_to_decimal(void);
extern Suite *test_from_decimal_to_int(void);
extern Suite *test_from_decimal_to_float(void);

extern Suite *test_floor(void);
extern Suite *test_round(void);
extern Suite *test_truncate(void);
extern Suite *test_negate(void);

#endif  // __TEST_DECIMAL_H__

