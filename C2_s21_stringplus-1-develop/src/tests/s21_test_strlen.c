#include "s21_test_string.h"

START_TEST(test_1) {
  char str_1[10] = "\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(test_2) {
  char str_2[50] = "Per aspera ad astra";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(test_3) {
  char str_3[50] = "i am\nproger";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(test_4) {
  char str_4[12] = "i am\nproger";
  ck_assert_int_eq(strlen(str_4), s21_strlen(str_4));
}
END_TEST

START_TEST(test_5) {
  char str_5[50] = " schhol21\0";
  ck_assert_int_eq(strlen(str_5), s21_strlen(str_5));
}
END_TEST

START_TEST(test_6) {
  char str_6[50] = " \n\0\0";
  ck_assert_int_eq(strlen(str_6), s21_strlen(str_6));
}
END_TEST

START_TEST(test_7) {
  char str_7[10] = " a\n\0";
  ck_assert_int_eq(strlen(str_7), s21_strlen(str_7));
}
END_TEST

START_TEST(test_8) {
  char str_8[] = "helo world";
  ck_assert_int_eq(strlen(str_8), s21_strlen(str_8));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *suite = suite_create("s21_strlen");
  TCase *tcase_core = tcase_create("core");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);

  suite_add_tcase(suite, tcase_core);

  return suite;
}