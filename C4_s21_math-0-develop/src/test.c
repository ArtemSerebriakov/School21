#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(+0), abs(+0));
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_double_eq_tol(s21_exp(-1.0), exp(-1.0), 1e-06);
  ck_assert_double_eq_tol(s21_exp(0.0), exp(0.0), 1e-06);
  ck_assert_double_eq(s21_exp(100.0 / 0.0), exp(100.0 / 0.0));
  ck_assert_double_eq(s21_exp(720), exp(720));
  ck_assert_double_eq_tol(s21_exp(-100 / 0.0), exp(-100 / 0.0), 1e-06);
  int i = 20;
  while (i != 0) {
    double rand_num = (double)(rand() % 511111433 + (-43437 + i));
    ck_assert_double_eq(s21_exp(rand_num), exp(rand_num));
    i--;
  }
}
END_TEST

START_TEST(test_s21_fabs) {
  double initialNumber = 0.0 / 0.0;
  ck_assert_ldouble_nan(s21_fabs(initialNumber));
  ck_assert_double_nan(fabs(initialNumber));
  ck_assert_double_eq(s21_fabs(100.0 / 0.0), fabs(100.0 / 0.0));
  ck_assert_double_eq(s21_fabs(-100.0 / 0.0), fabs(-100.0 / 0.0));
  ck_assert_double_eq(s21_fabs(-10.0000002), fabs(-10.0000002));
  ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
  ck_assert_ldouble_eq(s21_fabs(-2147483600.4857), fabs(-2147483600.4857));
}
END_TEST

START_TEST(test_s21_floor) {
  ck_assert_ldouble_nan(s21_floor(0.0 / 0.0));
  ck_assert_double_nan(floor(0.0 / 0.0));
  ck_assert_double_eq(s21_floor(100.001 / 0.00), floor(100.001 / 0.00));
  ck_assert_ldouble_infinite(s21_floor(-S21_INF));
  ck_assert_ldouble_infinite(s21_floor(S21_INF));
  ck_assert_double_eq(s21_floor(0.1), floor(0.1));
  ck_assert_double_eq(s21_floor(-0.1), floor(-0.1));
  int i = 20;
  while (i != 0) {
    double rand_num = (double)(rand() % 53437 + (-53437));
    ck_assert_double_eq(s21_floor(rand_num), floor(rand_num));
    i--;
  }
}
END_TEST

START_TEST(test_s21_fmod) {
  double x = 0.0;
  double y = 2.4;
  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
  ck_assert_double_eq(s21_fmod(100, 5 / 0.0), fmod(100, 5 / 0.0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 0.0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 3.5));
  int i = 40;
  while (i != 0) {
    x = x - 1.3;
    y = y + 2.55;
    ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
    i--;
  }
}
END_TEST

START_TEST(test_s21_log) {
  double x = -1.0;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_double_nan(log(x));
  ck_assert_ldouble_eq_tol(log(1.3), s21_log(1.3), 1e-06);
  ck_assert_ldouble_eq_tol(log(1.0), s21_log(1.0), 1e-06);
  ck_assert_ldouble_eq_tol(log(2.0), s21_log(2.0), 1e-06);
  ck_assert_ldouble_eq_tol(log(8.0), s21_log(8.0), 1e-06);
  ck_assert_ldouble_eq_tol(log(123456789.1), s21_log(123456789.1), 1e-06);
  ck_assert_ldouble_eq_tol(log(365.123), s21_log(365.123), 1e-06);
  ck_assert_ldouble_eq_tol(log(84.56), s21_log(84.56), 1e-06);
  ck_assert_ldouble_eq_tol(log(0.999999), s21_log(0.999999), 1e-06);
  ck_assert_ldouble_infinite(s21_log(S21_INF));
  ck_assert_ldouble_infinite(s21_log(0.0));
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_eq_tol(sqrtl(0.0), s21_sqrt(0.0), 1e-06);
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-49.0));
  ck_assert_ldouble_nan(s21_sqrt(-1.0));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_eq_tol(sqrt(64.0), s21_sqrt(64.0), 1e-06);
  ck_assert_ldouble_eq_tol(sqrt(365.0), s21_sqrt(365.0), 1e-06);
  ck_assert_ldouble_eq_tol(sqrt(0.000001), s21_sqrt(0.000001), 1e-06);
  ck_assert_ldouble_eq_tol(sqrt(0.999999), s21_sqrt(0.999999), 1e-06);
  ck_assert_ldouble_eq_tol(sqrt(123.456), s21_sqrt(123.456), 1e-06);
  ck_assert_ldouble_eq_tol(sqrt(0.123456), s21_sqrt(0.123456), 1e-06);
  ck_assert_ldouble_eq_tol(sqrt(1.44), s21_sqrt(1.44), 1e-06);
}
END_TEST

START_TEST(test_s21_atan) {
  double x = 0.0 / 0.0;
  ck_assert_ldouble_nan(s21_atan(x));
  ck_assert_double_nan(atan(x));
  x = 0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-06);
  x = 1.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-06);
  x = -10.0 / 0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-06);
  x = -1.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-06);
  x = 5;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-06);
}
END_TEST

START_TEST(test_s21_asin) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
  ck_assert_ldouble_nan(s21_asin(1.3));
  ck_assert_ldouble_nan(s21_asin(10.1));
  ck_assert_ldouble_nan(s21_asin(-21.2));
  ck_assert_ldouble_nan(s21_asin(-1.5));
  ck_assert_ldouble_eq_tol(asin(0.123456), s21_asin(0.123456), 1e-06);
  ck_assert_ldouble_eq_tol(asin(-0.126456), s21_asin(-0.126456), 1e-06);
  ck_assert_ldouble_eq_tol(asin(1.0), s21_asin(1.0), 1e-06);
  ck_assert_ldouble_eq_tol(asin(0.0), s21_asin(0.0), 1e-06);
  ck_assert_ldouble_eq_tol(asin(0.000006), s21_asin(0.000006), 1e-06);
  ck_assert_ldouble_eq_tol(asin(-0.000006), s21_asin(-0.000006), 1e-06);
  ck_assert_ldouble_eq_tol(asin(0.289), s21_asin(0.289), 1e-06);
  ck_assert_ldouble_eq_tol(s21_asin(-sqrt(3) / 2), asin(-sqrt(3) / 2), 1e-06);
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(1.2));
  ck_assert_ldouble_nan(s21_acos(10.0));
  ck_assert_ldouble_nan(s21_acos(-11.1));
  ck_assert_ldouble_nan(s21_acos(-1.1));
  ck_assert_ldouble_eq_tol(acos(1.0), s21_acos(1.0), 1e-06);
  ck_assert_ldouble_eq_tol(acos(-1.0), s21_acos(-1.0), 1e-06);
  ck_assert_ldouble_eq_tol(acos(0.0), s21_acos(0.0), 1e-06);
  ck_assert_ldouble_eq_tol(acos(0.000001), s21_acos(0.000001), 1e-06);
  ck_assert_ldouble_eq_tol(acos(-0.000001), s21_acos(-0.000001), 1e-06);
  ck_assert_ldouble_eq_tol(acos(0.1234567), s21_acos(0.1234567), 1e-06);
  ck_assert_ldouble_eq_tol(acos(-0.1234567), s21_acos(-0.1234567), 1e-06);
  ck_assert_ldouble_eq_tol(acos(0.866025), s21_acos(0.866025), 1e-06);
  ck_assert_ldouble_eq_tol(acos(-0.866025), s21_acos(-0.866025), 1e-06);
  ck_assert_ldouble_eq_tol(acos(0.5), s21_acos(0.5), 1e-06);
  ck_assert_ldouble_eq_tol(acos(-0.5), s21_acos(-0.5), 1e-06);
  //  ck_assert_ldouble_eq_tol(acos(-0.99), s21_acos(-0.99), 1e-06);
}
END_TEST

START_TEST(test_s21_pow) {
  ck_assert_ldouble_nan(s21_pow(-3.5, 56.8));
  ck_assert_ldouble_nan(s21_pow(-3.5, -56.8));
  ck_assert_double_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));
  ck_assert_double_eq(s21_pow(-S21_INF, S21_INF), pow(-S21_INF, S21_INF));
  ck_assert_double_eq(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF));
  ck_assert_double_eq(s21_pow(S21_NEG_INF, S21_NEG_INF),
                      pow(S21_NEG_INF, S21_NEG_INF));

  ck_assert_double_nan(s21_pow(NAN, S21_INF));
  ck_assert_double_nan(pow(NAN, S21_INF));
  ck_assert_ldouble_infinite(s21_pow(0.0, -3.5));
  ck_assert_ldouble_infinite(s21_pow(0.0, S21_NEG_INF));
  ck_assert_ldouble_infinite(s21_pow(3.5, S21_INF));
  ck_assert_ldouble_eq_tol(pow(456.789, 1.1), s21_pow(456.789, 1.1), 1e-06);
  ck_assert_ldouble_eq_tol(pow(1.0000001, -1.0), s21_pow(1.0000001, -1.0),
                           1e-06);
  ck_assert_ldouble_eq_tol(pow(S21_INF, -1.0), s21_pow(S21_INF, -1.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(-S21_INF, -1.0), s21_pow(-S21_INF, -1.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(S21_INF, 0.0), s21_pow(S21_INF, 0.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(-S21_INF, 0.0), s21_pow(-S21_INF, 0.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(0.0, S21_INF), s21_pow(0.0, S21_INF), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.5, 0.4), s21_pow(3.5, 0.4), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.5, -0.4), s21_pow(3.5, -0.4), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.5, -4.0), s21_pow(3.5, -4.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.5, 4.0), s21_pow(3.5, 4.0), 1e-06);
  ck_assert_double_eq(s21_pow(16894.2629, 1545), pow(16894.2629, 1545));
  ck_assert_double_eq(s21_pow(16894.2629, -1545), pow(16894.2629, -1545));
  ck_assert_ldouble_eq_tol(pow(3.5, 7.8), s21_pow(3.5, 7.8), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.5, -7.8), s21_pow(3.5, -7.8), 1e-06);
  ck_assert_ldouble_eq_tol(pow(1.0, S21_PI), s21_pow(1.0, S21_PI), 1e-06);
  ck_assert_ldouble_eq_tol(pow(S21_PI, -1.1), s21_pow(S21_PI, -1.1), 1e-06);
  ck_assert_ldouble_eq_tol(pow(S21_PI, -1.2), s21_pow(S21_PI, -1.2), 1e-06);
  ck_assert_ldouble_eq_tol(pow(7.0, 0.4), s21_pow(7.0, 0.4), 1e-06);
  ck_assert_ldouble_eq_tol(pow(7.0, -2.0), s21_pow(7.0, -2.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(7.0, 2.0), s21_pow(7.0, 2.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(-7.0, -3.0), s21_pow(-7.0, -3.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(-7.0, 3.0), s21_pow(-7.0, 3.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(S21_PI, 3.6), s21_pow(S21_PI, 3.6), 1e-06);
  ck_assert_ldouble_eq_tol(pow(S21_PI, 5.0), s21_pow(S21_PI, 5.0), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.5, -7.8), s21_pow(3.5, -7.8), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.6, 3.6), s21_pow(3.6, 3.6), 1e-06);
  ck_assert_ldouble_eq_tol(pow(3.6, 5.0), s21_pow(3.6, 5.0), 1e-06);
  ck_assert_ldouble_nan(s21_pow(-10.1261, -0.72));
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_ldouble_eq_tol(tan(0.999999), s21_tan(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-0.999999), s21_tan(-0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(tan(0.000001), s21_tan(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-0.000001), s21_tan(-0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(tan(0.785), s21_tan(0.785), 1e-6);
  ck_assert_double_eq_tol(s21_tan(6987000), tan(6987000), 0.000001);
  ck_assert_double_eq_tol(s21_tan(-14.96), tan(-14.96), 0.000001);
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 0.000001);
  ck_assert_float_eq(tan(-13.54), s21_tan(-13.54));
  ck_assert_float_eq(tan(13.54), s21_tan(13.54));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(115), s21_tan(115));
  ck_assert_float_eq(tan(2.5), s21_tan(2.5));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
  ck_assert_ldouble_eq_tol(tan(S21_PI / 2), s21_tan(S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(tan(-S21_PI / 2), s21_tan(-S21_PI / 2), 1e-6);
  for (double i = -100; i < 100; i += 2) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_float_eq(ceil(-13.54), s21_ceil(-13.54));
  ck_assert_float_eq(ceil(13.54), s21_ceil(13.54));
  ck_assert_float_eq(ceil(1000), s21_ceil(1000));
  ck_assert_float_eq(ceil(102.0000002), s21_ceil(102.0000002));
  ck_assert_double_eq(s21_ceil(S21_INF), ceil(S21_INF));
}
END_TEST

int main() {
  Suite *s = suite_create("S21_MATH");
  TCase *test_case = tcase_create("S21_MATH");
  SRunner *s_run = srunner_create(s);
  int num_failed = 0;
  suite_add_tcase(s, test_case);
  tcase_add_test(test_case, test_s21_abs);
  tcase_add_test(test_case, test_s21_fabs);
  tcase_add_test(test_case, test_s21_floor);
  tcase_add_test(test_case, test_s21_exp);
  tcase_add_test(test_case, test_s21_sqrt);
  tcase_add_test(test_case, test_s21_fmod);
  tcase_add_test(test_case, test_s21_log);
  tcase_add_test(test_case, test_s21_atan);
  tcase_add_test(test_case, test_s21_asin);
  tcase_add_test(test_case, test_s21_acos);
  tcase_add_test(test_case, test_s21_pow);
  tcase_add_test(test_case, test_s21_tan);
  tcase_add_test(test_case, test_s21_ceil);
  srunner_run_all(s_run, CK_VERBOSE);
  num_failed = srunner_ntests_failed(s_run);
  srunner_free(s_run);
  return num_failed == 0 ? 0 : 1;
}