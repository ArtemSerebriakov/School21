#include "../s21_bcd_headers/s21_bcd.h"


s21_bcd_CompareStatus s21_bcd_IsLess(s21_bcd value_1, s21_bcd value_2) {
    return s21_bcd_IsGreater(value_2, value_1);
}

