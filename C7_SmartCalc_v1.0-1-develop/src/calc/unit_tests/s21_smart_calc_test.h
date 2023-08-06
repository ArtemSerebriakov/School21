#ifndef SRC_UNIT_TESTS_S21_SMART_CALC_TEST_H_
#define SRC_UNIT_TESTS_S21_SMART_CALC_TEST_H_
#include <check.h>
#include <unistd.h>

#include "../polish.h"
#include "../stack.h"
#include "../validator.h"

Suite *suite_smart_calc(void);

void run_test(void);
void run_testcase(Suite *testcase);
// double get_rand(double min, double max);
#endif
