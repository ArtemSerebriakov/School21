#include "test_decimal.h"

START_TEST(s21_from_decimal_to_float_1) {
    s21_decimal num1 = { {0x00016C50, 0x00000000, 0x00000000, 0x00000000} };

    float orig = 93264.0f;

    float res = 0.0f;
    int error = s21_from_decimal_to_float(num1, &res);

    ck_assert_float_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
    Suite *s = suite_create(color_text("S21_FROM_DECIMAL_TO_FLOAT"));
    TCase *tc = tcase_create("s21_from_decimal_to_float_tc");

    tcase_add_test(tc, s21_from_decimal_to_float_1);

    suite_add_tcase(s, tc);
    return s;
}

