#include "test_decimal.h"

START_TEST(s21_add_1) {
    // 1234.34
    s21_decimal num1 = { {0x0001E22A, 0x00000000, 0x00000000, 0x00020000} };
    // 5366.228
    s21_decimal num2 = { {0x0051E1D4, 0x00000000, 0x00000000, 0x00030000} };
    // 6600.568
    s21_decimal orig = { {0x0064B778, 0x00000000, 0x00000000, 0x00030000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_add(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_add(void) {
    Suite *s = suite_create(color_text("S21_ADD"));
    TCase *tc = tcase_create("s21_add_tc");

    tcase_add_test(tc, s21_add_1);

    suite_add_tcase(s, tc);
    return s;
}

