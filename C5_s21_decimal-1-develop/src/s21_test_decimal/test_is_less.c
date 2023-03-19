#include "test_decimal.h"

START_TEST(s21_is_less_1) {
    // 1234.34
    s21_decimal num1 = { {0x0001E22A, 0x00000000, 0x00000000, 0x00020000} };
    // 5366.228
    s21_decimal num2 = { {0x0051E1D4, 0x00000000, 0x00000000, 0x00030000} };

    ck_assert_int_eq(s21_is_less(num1, num2), 1);
}
END_TEST

Suite *test_is_less(void) {
    Suite *s = suite_create(color_text("S21_IS_LESS"));
    TCase *tc = tcase_create("s21_is_less_tc");

    tcase_add_test(tc, s21_is_less_1);

    suite_add_tcase(s, tc);
    return s;
}

