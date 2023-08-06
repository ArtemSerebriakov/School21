#include "s21_smart_calc_test.h"

/*START_TEST(s21_test_0) {
  double orig = 10;
  char* src = "5+5";
  char expr_short[10];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq(result, orig);
}
END_TEST*/

START_TEST(s21_test_1) {
  double orig = 162;
  char src[100] = "4*5*2*2*2+2";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_int_eq(result, orig);
}
END_TEST

START_TEST(s21_test_2) {
  double orig = 20;
  char src[100] = "150/10+5*2/2";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq(result, orig);
}
END_TEST

START_TEST(s21_test_3) {
  double orig = 9;
  char src[100] = "5+5-2*3/6";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq(result, orig);
}
END_TEST

START_TEST(s21_test_4) {
  char src[100] = "4^acos(x/4)/tan(2*x)";
  double x_text = 1.2;
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, x_text);
  double real_result = -6.31492;
  ck_assert_msg(fabs(result - real_result) <= 0.00001, "test-1 failed");
}
END_TEST

START_TEST(s21_test_5) {
  char src[10] = "2+2";
  double x_text = 2;
  char expr_short[11];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, x_text);
  int orig = 4;
  ck_assert_int_eq(result, orig);
}
END_TEST

START_TEST(s21_test_6) {
  char* src = "123+0.456";
  char expr_short[11];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  double orig = 123.456;
  ck_assert_double_eq(result, orig);
}
END_TEST

START_TEST(s21_test_7) {
  char* src = "log(x)";
  double x_text = -2;
  char expr_short[7];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, x_text);
  double real_result = NAN;
  ck_assert_msg(result != result && real_result != real_result,
                "test-4 failed");
}
END_TEST

START_TEST(s21_test_8) {
  char src[100] = "-(-1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  double real_result = 1;
  ck_assert_msg(result == real_result, "test-5 failed");
}
END_TEST

START_TEST(s21_test_9) {
  char src[100] = "cos(10%2.2)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  double real_result = 0.362358;
  ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-6 failed");
}
END_TEST

START_TEST(s21_test_10) {
  char src[100] = "sqrt(ln(10))";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  double real_result = 1.517427;
  ck_assert_msg(fabs(result - real_result) <= 0.00001, "test-7 failed");
}
END_TEST

START_TEST(s21_test_11) {
  char* src = "atan(10)+sin(10)";
  char expr_short[18];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  double real_result = 0.927107;
  ck_assert_msg(fabs(result - real_result) <= 0.00001, "test-8 failed");
}
END_TEST

START_TEST(s21_test_12) {
  char src[100] = "asin(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  double real_result = 1.570796;
  ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-9 failed");
}
END_TEST

START_TEST(s21_test_13) {
  double orig = 69;
  char src[100] = "2+(5*5*5+5+2*2)/(2)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq(result, orig);
}
END_TEST

/*START_TEST(s21_test_14) {
  double orig = 11.958851;
  char* src = "5+(3+sin(8/2-3.5))*2";
  char expr_short[22];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-7);
}
END_TEST*/

START_TEST(s21_test_15) {
  char src[100] = "24*4-3*2";
  double orig = 90;
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_int_eq(result, orig);
}
END_TEST

START_TEST(s21_test_16) {
  double orig = -0.41211848524;
  char src[100] = "-sin(9)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_int_eq(result, orig);
}
END_TEST

START_TEST(s21_test_17) {
  double orig = 2.41211848524;
  char src[100] = "sin(9)-(-2)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_int_eq(result, orig);
}
END_TEST

START_TEST(s21_test_18) {
  double orig = 0.91113026188;
  char src[100] = "-cos(9)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_int_eq(result, orig);
}
END_TEST

START_TEST(s21_test_19) {
  double orig = 0;
  char src[100] = "(-2)+2";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_float_eq(result, orig);
}
END_TEST

START_TEST(s21_test_20) {
  double orig = -4.4;
  char src[100] = "(-2.2)-2.2";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_float_eq(result, orig);
}
END_TEST

START_TEST(s21_test_21) {
  double orig = -1;
  char src[100] = "(-2.2)/2.2";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_float_eq(result, orig);
}
END_TEST

START_TEST(s21_test_22) {
  double orig = sin(2);
  char src[100] = "sin(+2)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_23) {
  double orig = cos(2);
  char src[100] = "cos(2)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_24) {
  double orig = tan(2);
  char src[100] = "tan(2)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_25) {
  double orig = asin(1);
  char src[100] = "asin(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_26) {
  double orig = acos(1);
  char src[100] = "acos(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_27) {
  double orig = atan(1);
  char src[100] = "atan(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_28) {
  double orig = log(1);
  char src[100] = "ln(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_29) {
  double orig = log10(1);
  char src[100] = "log(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_30) {
  double orig = sqrt(1);
  char src[100] = "sqrt(1)";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

START_TEST(s21_test_31) {
  double orig = 4;
  char src[100] = "4%8";
  char expr_short[101];
  change_string(src, expr_short, strlen(src));
  double result = s21_calculate(expr_short, 0);
  ck_assert_double_eq_tol(result, orig, 1e-6);
}
END_TEST

Suite* suite_smart_calc(void) {
  Suite* s = suite_create("suite_smart_calc");
  TCase* tc = tcase_create("suite_smart_calc");

  // tcase_add_test(tc, s21_test_0);
  tcase_add_test(tc, s21_test_1);
  tcase_add_test(tc, s21_test_2);
  tcase_add_test(tc, s21_test_3);
  tcase_add_test(tc, s21_test_4);
  tcase_add_test(tc, s21_test_5);
  tcase_add_test(tc, s21_test_6);
  tcase_add_test(tc, s21_test_7);
  tcase_add_test(tc, s21_test_8);
  tcase_add_test(tc, s21_test_9);
  tcase_add_test(tc, s21_test_10);
  tcase_add_test(tc, s21_test_11);
  tcase_add_test(tc, s21_test_12);
  tcase_add_test(tc, s21_test_13);
  // tcase_add_test(tc, s21_test_14);
  tcase_add_test(tc, s21_test_15);
  tcase_add_test(tc, s21_test_16);
  tcase_add_test(tc, s21_test_17);
  tcase_add_test(tc, s21_test_18);
  tcase_add_test(tc, s21_test_19);
  tcase_add_test(tc, s21_test_20);
  tcase_add_test(tc, s21_test_21);
  tcase_add_test(tc, s21_test_22);
  tcase_add_test(tc, s21_test_23);
  tcase_add_test(tc, s21_test_24);
  tcase_add_test(tc, s21_test_25);
  tcase_add_test(tc, s21_test_26);
  tcase_add_test(tc, s21_test_27);
  tcase_add_test(tc, s21_test_28);
  tcase_add_test(tc, s21_test_29);
  tcase_add_test(tc, s21_test_30);
  tcase_add_test(tc, s21_test_31);
  suite_add_tcase(s, tc);
  return s;
}