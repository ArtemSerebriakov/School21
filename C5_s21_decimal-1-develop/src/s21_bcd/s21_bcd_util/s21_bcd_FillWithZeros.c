#include "../s21_bcd_headers/s21_bcd_util.h"


void s21_bcd_FillWithZeros(s21_bcd *num) {
    memset(num, 0, sizeof(s21_bcd));
}

