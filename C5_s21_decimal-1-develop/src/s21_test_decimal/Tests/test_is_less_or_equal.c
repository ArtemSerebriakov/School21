#include "test.h"

/*-----is_less_or_equal_WITHOUT_SCALE-----*/
START_TEST(is_less_or_equal_zero_test) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_zero_negative_test) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_zero_diff_signs_test) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_max_test) {
  s21_decimal value_1 = {{~0, ~0, ~0, 0}};
  s21_decimal value_2 = {{~0, ~0, ~0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_different_simple_test) {
  s21_decimal value_1 = {{12, 0, 0, 0}};
  s21_decimal value_2 = {{125, 0, 0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_first_bit_equal_test) {
  s21_decimal value_1 = {{3216, 1, 0, 0}};
  s21_decimal value_2 = {{3216, 0, 0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 0;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_dif_sign_val_test) {
  s21_decimal value_1 = {{3216, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{3216, 0, 0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_last_bit_test) {
  s21_decimal value_1 = {{0, 0, 9, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 0;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_last_bit_equal_test) {
  s21_decimal value_1 = {{0, 0, 9340, 0}};
  s21_decimal value_2 = {{0, 0, 9340, 0}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_last_bit_equal_neg_test) {
  s21_decimal value_1 = {{0, 0, 9340, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 9341, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 0;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_neg_test_1) {
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_neg_test_2) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{1, 0, 0, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 0;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_neg_test_3) {
  s21_decimal value_1 = {{16156, 56891, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 0;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_neg_test_4) {
  s21_decimal value_1 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_2 = {{16156, ~0, 0, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

START_TEST(is_less_or_equal_neg_test_5) {
  s21_decimal value_1 = {{1, 0, ~0, 0x80000000}};
  s21_decimal value_2 = {{1, 0, ~0, 0x80000000}};
  int got = s21_is_less_or_equal(value_1, value_2);
  int must = 1;

  ck_assert_int_eq(got, must);
}
END_TEST

Suite *test_is_less_or_equal_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("is_less_or_equal_test");
  /* Core test case */
  tc = tcase_create("is_less_or_equal_tc");

  // abs
  tcase_add_test(tc, is_less_or_equal_zero_test);
  tcase_add_test(tc, is_less_or_equal_zero_negative_test);
  tcase_add_test(tc, is_less_or_equal_zero_diff_signs_test);
  tcase_add_test(tc, is_less_or_equal_max_test);
  tcase_add_test(tc, is_less_or_equal_different_simple_test);
  tcase_add_test(tc, is_less_or_equal_first_bit_equal_test);
  tcase_add_test(tc, is_less_or_equal_dif_sign_val_test);
  tcase_add_test(tc, is_less_or_equal_last_bit_test);
  tcase_add_test(tc, is_less_or_equal_last_bit_equal_test);
  tcase_add_test(tc, is_less_or_equal_last_bit_equal_neg_test);
  tcase_add_test(tc, is_less_or_equal_neg_test_1);
  tcase_add_test(tc, is_less_or_equal_neg_test_2);
  tcase_add_test(tc, is_less_or_equal_neg_test_3);
  tcase_add_test(tc, is_less_or_equal_neg_test_4);
  tcase_add_test(tc, is_less_or_equal_neg_test_5);

  suite_add_tcase(s, tc);

  return s;
}
