#include "test_decimal.h"

START_TEST(s21_mul_1) {
    // 1234.34
    s21_decimal num1 = { {0x0001E22A, 0x00000000, 0x00000000, 0x00020000} };
    // 5366.228
    s21_decimal num2 = { {0x0051E1D4, 0x00000000, 0x00000000, 0x00030000} };
    // 6623749.86952
    s21_decimal orig = { {0x38A034C8, 0x0000009A, 0x00000000, 0x00050000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_mul(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_mul(void) {
    Suite *s = suite_create(color_text("S21_MUL"));
    TCase *tc = tcase_create("s21_mul_tc");

    tcase_add_test(tc, s21_mul_1);

    suite_add_tcase(s, tc);
    return s;
}

