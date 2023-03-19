#include "test_decimal.h"

START_TEST(s21_from_decimal_to_int_1) {
    s21_decimal num1 = { {0x00016C50, 0x00000000, 0x00000000, 0x00000000} };

    int orig = 93264;

    int res = 0;
    int error = s21_from_decimal_to_int(num1, &res);

    ck_assert_int_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_decimal_to_int(void) {
    Suite *s = suite_create(color_text("S21_FROM_DECIMAL_TO_INT"));
    TCase *tc = tcase_create("s21_from_decimal_to_int_tc");

    tcase_add_test(tc, s21_from_decimal_to_int_1);

    suite_add_tcase(s, tc);
    return s;
}

