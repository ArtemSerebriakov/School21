#include "test_decimal.h"

START_TEST(s21_floor_1) {
    // -21341.8
    s21_decimal num1 = { {0x000341AA, 0x00000000, 0x00000000, 0x80010000} };

    // -21342.0
    s21_decimal orig = { {0x0000535E, 0x00000000, 0x00000000, 0x80000000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_floor(num1, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_floor(void) {
    Suite *s = suite_create(color_text("S21_FLOOR"));
    TCase *tc = tcase_create("s21_floor_tc");

    tcase_add_test(tc, s21_floor_1);

    suite_add_tcase(s, tc);
    return s;
}

