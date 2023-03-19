#include "test_decimal.h"

START_TEST(s21_div_1) {
    // 1
    s21_decimal num1 = { {0x00000001, 0x00000000, 0x00000000, 0x00000000} };
    // 3
    s21_decimal num2 = { {0x00000003, 0x00000000, 0x00000000, 0x00000000} };
    // 0.(3)
    s21_decimal orig = { {0x05555555, 0x14B700CB, 0x0AC544CA, 0x001C0000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_div_2) {
    // 1
    s21_decimal num1 = { {0x00000001, 0x00000000, 0x00000000, 0x00000000} };
    // 0
    s21_decimal num2 = { {0x00000000, 0x00000000, 0x00000000, 0x00000000} };
    // inf
    s21_decimal orig = { {0x1, 0x1, 0x1, 0x1} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    // assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_div_3) {
    // 0
    s21_decimal num1 = { {0x00000000, 0x00000000, 0x00000000, 0x00000000} };
    // 0
    s21_decimal num2 = { {0x00000000, 0x00000000, 0x00000000, 0x00000000} };
    // nan
    s21_decimal orig = { {0x1, 0x1, 0x1, 0x1} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    // assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 3);
}
END_TEST

START_TEST(s21_div_4) {
    // 79228162514264337593543950335
    s21_decimal num1 = { {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000} };
    // 1e-28
    s21_decimal num2 = { {0x00000000, 0x00000000, 0x00000000, 0x001C0000} };
    // inf
    s21_decimal orig = { {0x1, 0x1, 0x1, 0x1} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    // assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_div_5) {
    // -79228162514264337593543950335
    s21_decimal num1 = { {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000} };
    // 1e-28
    s21_decimal num2 = { {0x00000000, 0x00000000, 0x00000000, 0x001C0000} };
    // inf
    s21_decimal orig = { {0x1, 0x1, 0x1, 0x1} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    // assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_div_6) {
    // 1e-28
    s21_decimal num1 = { {0x00000000, 0x00000000, 0x00000000, 0x001C0000} };
    // 79228162514264337593543950335
    s21_decimal num2 = { {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000} };
    // 0
    s21_decimal orig = { {0x00000000, 0x00000000, 0x00000000, 0x00000000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST






START_TEST(s21_div_10) {
    // 7489321.1
    s21_decimal num1 = { {0x0476C79B, 0x00000000, 0x00000000, 0x00010000} };
    // 48193.2
    s21_decimal num2 = { {0x00075A8C, 0x00000000, 0x00000000, 0x00010000} };
    // 155.40202974693525227625474133
    s21_decimal orig = { {0xE01B6855, 0x4D29EBFE, 0x32368DFB, 0x001A0000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_div_11) {
    // 1234.228
    s21_decimal num1 = { {0x0012D534, 0x00000000, 0x00000000, 0x00030000} };
    // 5366.1337
    s21_decimal num2 = { {0x0332CE99, 0x00000000, 0x00000000, 0x00040000} };
    // 0.2300032144186045904894244435
    s21_decimal orig = { {0x41633653, 0x602A9C80, 0x076E8AC0, 0x001C0000} };

    s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);

    assert_decimal_eq(res, orig);
    ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_div(void) {
    Suite *s = suite_create(color_text("S21_DIV"));
    TCase *tc = tcase_create("s21_div_tc");

    tcase_add_test(tc, s21_div_1);
    tcase_add_test(tc, s21_div_2);
    tcase_add_test(tc, s21_div_3);
    tcase_add_test(tc, s21_div_4);
    tcase_add_test(tc, s21_div_5);
    tcase_add_test(tc, s21_div_6);

    suite_add_tcase(s, tc);
    return s;
}

