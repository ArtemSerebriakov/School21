#include "../s21_bcd_headers/s21_bcd_util.h"


void s21_bcd_FastDivByTenPow(s21_bcd *num, const int count) {
    s21_bcd_BitShiftRight(num, 4*count);
}

