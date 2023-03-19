#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_Sign s21_bcd_SetSign(s21_bcd *num, const s21_bcd_Sign sign) {
    num->sign = sign;
    return sign;
}

