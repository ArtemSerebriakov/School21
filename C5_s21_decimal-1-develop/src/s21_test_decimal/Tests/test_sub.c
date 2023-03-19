#include "test.h"
#include "../../s21_decimal/s21_decimal_headers/s21_decimal_util.h"

/*-----SIMPE sub TEST-----*/
START_TEST(sub_loop_pos_test_1bit) {
  for (int i = 0; i < 55; i++) {
    s21_decimal value_1 = {{i, 0, 0, 0}};
    s21_decimal value_2 = {{i, 0, 0, 0}};
    s21_decimal result;
    s21_sub(value_1, value_2, &result);
    int got = result.bits[0];
    int must = i - i;
    ck_assert_int_eq(got, must);
  }
}
END_TEST

START_TEST(sub_loop_neg_test_1bit) {
  for (int i = 55; i >= 0; i--) {
    s21_decimal value_1 = {{i, 0, 0, 0x80000000}};
    s21_decimal value_2 = {{i, 0, 0, 0x80000000}};
    s21_decimal result;
    s21_sub(value_1, value_2, &result);
    int got = result.bits[0];
    if (s21_decimal_GetSign(&result) == 1) {
      got *= -1;
    }
    int must = -i - -i;
    ck_assert_int_eq(got, must);
  }
}
END_TEST

START_TEST(sub_loop_cross_sign_test_1bit) {
  int j = -55 * 2;
  for (int i = 55; i >= -55; i--) {
    int sign1 = 0;
    int sign2 = 0;
    if (i < 0) {
      sign1 = 0x80000000;
    }
    if (j < 0) {
      sign2 = 0x80000000;
    }
    s21_decimal value_1 = {{abs(i), 0, 0, sign1}};
    s21_decimal value_2 = {{abs(j), 0, 0, sign2}};
    s21_decimal result;
    s21_sub(value_1, value_2, &result);
    int got = result.bits[0];
    if (s21_decimal_GetSign(&result) == 1) {
      got *= -1;
    }
    int must = i - j;

    ck_assert_int_eq(got, must);
    if (i % 2 == 0) {
      j++;
    } else {
      j += 3;
    }
  }
}
END_TEST

START_TEST(sub_zero_test_1) {
  s21_decimal value_1 = {{916000, 0, 0, 0x80000000 | 3 << 16}};
  s21_decimal value_2 = {{916, 0, 0, 0x80000000}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(basic_sub_test) {
  s21_decimal value_1 = {{532167, 0, 0, 0}};
  s21_decimal value_2 = {{123456, 0, 0, 0}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{408711, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

// два положительных числа, второе больше первого
START_TEST(basic_sub_test_2) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_decimal value_2 = {{532167, 0, 0, 0}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{408711, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

// два отрицательных числа, первое по модулю больше второго
START_TEST(basic_sub_test_3) {
  s21_decimal value_1 = {{532167, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{123456, 0, 0, 0x80000000}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{408711, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

// два отрицательных числа, второе по модулю больше первого
START_TEST(basic_sub_test_4) {
  s21_decimal value_1 = {{61287, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{234787, 0, 0, 0x80000000}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{173500, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(sub_float_test) {
  s21_decimal value_1 = {{532167, 0, 0, 196608}};
  s21_decimal value_2 = {{1236, 0, 0, 983040}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{607087404, 123904785, 0, 983040}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(sub_float_test_2) {
  s21_decimal value_1 = {{532167, 0, 0, 196608}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{532167, 0, 0, 196608}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(big_values_sub) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{6, 0, 0, 65536}};
  s21_decimal result;
  int res = s21_sub(value_1, value_2, &result);

  s21_decimal must = {{4294967294, 4294967295, 4294967295, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

Suite* test_sub_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("sub_test");
  /* Core test case */
  tc = tcase_create("sub_tc");

  // abs
  tcase_add_test(tc, sub_loop_pos_test_1bit);
  tcase_add_test(tc, sub_loop_neg_test_1bit);
  tcase_add_test(tc, sub_loop_cross_sign_test_1bit);
  tcase_add_test(tc, sub_zero_test_1);

  tcase_add_test(tc, basic_sub_test);
  tcase_add_test(tc, basic_sub_test_2);
  tcase_add_test(tc, basic_sub_test_3);
  tcase_add_test(tc, basic_sub_test_4);
  tcase_add_test(tc, sub_float_test);
  tcase_add_test(tc, sub_float_test_2);
  tcase_add_test(tc, big_values_sub);

  suite_add_tcase(s, tc);

  return s;
}
