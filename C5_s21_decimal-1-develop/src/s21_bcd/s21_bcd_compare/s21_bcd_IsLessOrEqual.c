#include "../s21_bcd_headers/s21_bcd.h"


s21_bcd_CompareStatus s21_bcd_IsLessOrEqual(s21_bcd value_1, s21_bcd value_2) {
    return s21_bcd_IsLess(value_1, value_2) || s21_bcd_IsEqual(value_1, value_2);
}

