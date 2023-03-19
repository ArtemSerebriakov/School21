#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_RoundingStatus s21_bcd_Round(s21_bcd value, s21_bcd *result) {  // need to implement compare functions
    s21_bcd_Truncate(value, result);  // also init result

    if (!s21_bcd_IsEqual(value, *result)) {
        s21_bcd half_one;  // 0.5
        s21_bcd_FillWithZeros(&half_one);
        half_one.bits[0] = 5;
        s21_bcd_SetExp(&half_one, 1);

        if (s21_bcd_GetSign(&value) == BCD_SIGN_PLUS) {
            s21_bcd_Add(value, half_one, result);
        } else {
            s21_bcd_Sub(value, half_one, result);
        }

        s21_bcd_Truncate(*result, result);
    }

    return BCD_ROUNDING_OK;
}

