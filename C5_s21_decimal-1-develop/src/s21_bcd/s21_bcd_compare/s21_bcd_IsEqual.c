#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_CompareStatus s21_bcd_IsEqual(s21_bcd value_1, s21_bcd value_2) {
    if (s21_bcd_IsZero(&value_1) && s21_bcd_IsZero(&value_2)) {  // firstly check for zero, as -0 == +0
        return BCD_COMPARE_TRUE;
    }

    if (s21_bcd_GetSign(&value_1) != s21_bcd_GetSign(&value_2)) {
        return BCD_COMPARE_FALSE;
    }

    s21_bcd_AlignByScale(&value_1, &value_2);

    for (int i = BCD_BYTES-1; i >= 0; --i) {
        if (value_1.bits[i] != value_2.bits[i]) {
            return BCD_COMPARE_FALSE;
        }
    }

    return BCD_COMPARE_TRUE;
}

