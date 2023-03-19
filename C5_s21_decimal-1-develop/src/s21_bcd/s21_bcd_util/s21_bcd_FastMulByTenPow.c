#include "../s21_bcd_headers/s21_bcd_util.h"


void s21_bcd_FastMulByTenPow(s21_bcd *num, const int count) {
    s21_bcd_BitShiftLeft(num, 4*count);
}

