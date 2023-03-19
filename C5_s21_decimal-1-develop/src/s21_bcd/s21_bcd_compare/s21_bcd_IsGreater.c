#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_CompareStatus s21_bcd_IsGreater(s21_bcd value_1, s21_bcd value_2) {
    if (s21_bcd_IsZero(&value_1) && s21_bcd_IsZero(&value_2)) {  // because -0 == +0
        return BCD_COMPARE_FALSE;
    }

    const s21_bcd_Sign value_1_sign = s21_bcd_GetSign(&value_1);
    const s21_bcd_Sign value_2_sign = s21_bcd_GetSign(&value_2);

    if (value_1_sign != value_2_sign) {
        return (value_1_sign == BCD_SIGN_PLUS) ? BCD_COMPARE_TRUE : BCD_COMPARE_FALSE;
    }

    s21_bcd_AlignByScale(&value_1, &value_2);

    for (int i = BCD_BYTES-1; i >= 0; --i) {
        if (value_1.bits[i] != value_2.bits[i]) {
            if (value_1.bits[i] > value_2.bits[i]) {  // if sign is minus reverse result
                return (value_1_sign == BCD_SIGN_PLUS) ? BCD_COMPARE_TRUE : BCD_COMPARE_FALSE;
            } else {
                return (value_1_sign == BCD_SIGN_MINUS) ? BCD_COMPARE_TRUE : BCD_COMPARE_FALSE;
            }
        }
    }

    return BCD_COMPARE_FALSE;  // values are equal;
}

