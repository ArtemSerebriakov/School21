#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_Sign s21_bcd_GetSign(const s21_bcd *num) {
    return !!(num->sign);
}

