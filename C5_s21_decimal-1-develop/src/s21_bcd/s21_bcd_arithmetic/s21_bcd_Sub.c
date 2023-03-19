#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


s21_bcd_ArithmeticStatus s21_bcd_Sub(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    s21_bcd_FillWithZeros(result);

    s21_bcd_AlignByScale(&value_1, &value_2);

    if (s21_bcd_GetSign(&value_2) == BCD_SIGN_PLUS) {
        s21_bcd_SetSign(&value_2, BCD_SIGN_MINUS);
    } else {
        s21_bcd_SetSign(&value_2, BCD_SIGN_PLUS);
    }

    return s21_bcd_Add(value_1, value_2, result);
}

