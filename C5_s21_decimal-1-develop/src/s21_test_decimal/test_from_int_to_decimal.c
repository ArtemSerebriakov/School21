#include "test_decimal.h"

START_TEST(s21_from_int_to_decimal_1) {
    int num1 = 93264;

    s21_decimal orig = { {0x00016C50, 0x00000000, 0x00000000, 0x00000000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_from_int_to_decimal(num1, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
    Suite *s = suite_create(color_text("S21_FROM_INT_TO_DECIMAL"));
    TCase *tc = tcase_create("s21_from_int_to_decimal_tc");

    tcase_add_test(tc, s21_from_int_to_decimal_1);

    suite_add_tcase(s, tc);
    return s;
}

