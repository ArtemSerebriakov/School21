#include "test_decimal.h"

START_TEST(s21_sub_1) {
    // 1234.34
    s21_decimal num1 = { {0x0001E22A, 0x00000000, 0x00000000, 0x00020000} };
    // 5366.228
    s21_decimal num2 = { {0x0051E1D4, 0x00000000, 0x00000000, 0x00030000} };
    // -4131.888
    s21_decimal orig = { {0x003F0C30, 0x00000000, 0x00000000, 0x80030000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_sub(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_sub(void) {
    Suite *s = suite_create(color_text("S21_SUB"));
    TCase *tc = tcase_create("s21_sub_tc");

    tcase_add_test(tc, s21_sub_1);

    suite_add_tcase(s, tc);
    return s;
}


