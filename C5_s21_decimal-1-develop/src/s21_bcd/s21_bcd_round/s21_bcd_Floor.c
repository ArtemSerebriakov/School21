#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_RoundingStatus s21_bcd_Floor(s21_bcd value, s21_bcd *result) {  // need to implement compare functions
    s21_bcd_Truncate(value, result);  // also init result

    if (s21_bcd_GetSign(&value) == BCD_SIGN_MINUS && !s21_bcd_IsEqual(value, *result)) {
        s21_bcd one;
        s21_bcd_FillWithZeros(&one);
        one.bits[0] = 1;

        s21_bcd_Sub(*result, one, result);
    }

    return BCD_ROUNDING_OK;
}

