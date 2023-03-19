#include "test_decimal.h"

START_TEST(s21_mod_1) {
  // 7.9228162514264337593543950335
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  // 79228162514264337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  // 7.9228162514264337593543950335
  s21_decimal orig = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_2) {
  // 1
  s21_decimal num1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  // 1e28
  s21_decimal num2 = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x00000000}};
  // 1
  s21_decimal orig = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_3) {
  // 547343
  s21_decimal num1 = {{0x00085A0F, 0x00000000, 0x00000000, 0x00000000}};
  // 123
  s21_decimal num2 = {{0x0000007B, 0x00000000, 0x00000000, 0x00000000}};
  // 116
  s21_decimal orig = {{0x00000074, 0x00000000, 0x00000000, 0x00000000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_4) {
  // 1234.56789
  s21_decimal num1 = {{0x075BCD15, 0x00000000, 0x00000000, 0x00050000}};
  // 0.987
  s21_decimal num2 = {{0x000003DB, 0x00000000, 0x00000000, 0x00030000}};
  // 0.81789
  s21_decimal orig = {{0x00013F7D, 0x00000000, 0x00000000, 0x00050000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_5) {
  // 0.987654321
  s21_decimal num1 = {{0x3ADE68B1, 0x00000000, 0x00000000, 0x00090000}};
  // 79228162514264337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  // 0.987654321
  s21_decimal orig = {{0x3ADE68B1, 0x00000000, 0x00000000, 0x00090000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_6) {
  // 0.1e-27
  s21_decimal num1 = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};
  // 79228162514264337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  // 0.1e-27
  s21_decimal orig = {{0x00000001, 0x00000000, 0x00000000, 0x001C0000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_7) {
  // 7.9228162514264337593543950335
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};
  // 79.228162514264337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001B0000}};
  // 7.9228162514264337593543950335
  s21_decimal orig = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001C0000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_8) {
  // 79.228162514264337593543950335
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x001B0000}};
  // 69.228162514264337593543950335
  s21_decimal num2 = {{0xEFFFFFFF, 0xC1DAFD9E, 0xDFB031A1, 0x001B0000}};
  // 10.000000000000000000000000000
  s21_decimal orig = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x001B0000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_9) {
  // 79.117548357403954375834574398
  s21_decimal num1 = {{0x7F099E3E, 0x8A8D21DC, 0xFFA4808A, 0x001B0000}};
  // 69.228162514264337593543950335
  s21_decimal num2 = {{0xEFFFFFFF, 0xC1DAFD9E, 0xDFB031A1, 0x001B0000}};
  // 9.889385843139616782290624063
  s21_decimal orig = {{0x8F099E3F, 0xC8B2243D, 0x1FF44EE8, 0x001B0000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_10) {
  // 111111111100
  s21_decimal num1 = {{0xDEBD01BC, 0x00000019, 0x00000000, 0x00000000}};
  // 1111.01
  s21_decimal num2 = {{0x0001B1FD, 0x00000000, 0x00000000, 0x00020000}};
  // 909.00
  s21_decimal orig = {{0x00016314, 0x00000000, 0x00000000, 0x00020000}};
  // s21_decimal orig = { {0x0000038D, 0x00000000, 0x00000000, 0x00000000} };

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_11) {
  // 534543.78543
  s21_decimal num1 = {{0x7221162F, 0x0000000C, 0x00000000, 0x00050000}};
  // 432.78423
  s21_decimal num2 = {{0x02946057, 0x00000000, 0x00000000, 0x00050000}};
  // 55.26138
  s21_decimal orig = {{0x0054527A, 0x00000000, 0x00000000, 0x00050000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_12) {
  // 3
  s21_decimal num1 = {{0x00000003, 0x00000000, 0x00000000, 0x00000000}};
  // 2
  s21_decimal num2 = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};
  // 1
  s21_decimal orig = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_13) {
  // 79228162514264337593543950335
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  // 1
  s21_decimal num2 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  // 0
  s21_decimal orig = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_14) {
  // 79228162514264337593543950335
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  // 79228162514264337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  // 0
  s21_decimal orig = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_mod_15) {
  // -79228162514264337593543950335
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 792
  s21_decimal num2 = {{0x00000318, 0x00000000, 0x00000000, 0x00000000}};
  // -318
  s21_decimal orig = {{0x0000003F, 0x00000000, 0x00000000, 0x80000000}};

  s21_decimal res = {{0x1, 0x1, 0x1, 0x1}};
  int error = s21_mod(num1, num2, &res);

  assert_decimal_eq(res, orig);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_mod(void) {
  Suite *s = suite_create(color_text("S21_MOD"));
  TCase *tc = tcase_create("s21_mod_tc");

  tcase_add_test(tc, s21_mod_1);
  tcase_add_test(tc, s21_mod_2);
  tcase_add_test(tc, s21_mod_3);
  tcase_add_test(tc, s21_mod_4);
  tcase_add_test(tc, s21_mod_5);
  tcase_add_test(tc, s21_mod_6);
  tcase_add_test(tc, s21_mod_7);
  tcase_add_test(tc, s21_mod_8);
  tcase_add_test(tc, s21_mod_9);
  tcase_add_test(tc, s21_mod_10);
  tcase_add_test(tc, s21_mod_12);
  tcase_add_test(tc, s21_mod_13);
  tcase_add_test(tc, s21_mod_14);
  tcase_add_test(tc, s21_mod_15);

  suite_add_tcase(s, tc);
  return s;
}

