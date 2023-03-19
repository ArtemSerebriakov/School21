#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


s21_bcd_ArithmeticStatus s21_bcd_Add(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    s21_bcd_FillWithZeros(result);

    s21_bcd_AlignByScale(&value_1, &value_2);

    const s21_bcd_Sign value_1_sign = s21_bcd_GetSign(&value_1);
    const s21_bcd_Sign value_2_sign = s21_bcd_GetSign(&value_2);

    if (value_1_sign == value_2_sign) {
        s21_bcd_AddAlgorithm(value_1, value_2, result);
        s21_bcd_SetSign(result, value_1_sign);
    } else if (value_1_sign == BCD_SIGN_PLUS && value_2_sign == BCD_SIGN_MINUS) {
        s21_bcd_SetSign(&value_1, BCD_SIGN_PLUS);  // set sign to PLUS to compare plain numbers
        s21_bcd_SetSign(&value_2, BCD_SIGN_PLUS);

        if (s21_bcd_IsGreater(value_1, value_2)) {
            s21_bcd_SubAlgorithm(value_1, value_2, result);
            s21_bcd_SetSign(result, BCD_SIGN_PLUS);
        } else if (s21_bcd_IsGreater(value_2, value_1)) {
            s21_bcd_SubAlgorithm(value_2, value_1, result);
            s21_bcd_SetSign(result, BCD_SIGN_MINUS);
        } else {
            return BCD_ARITHMETIC_OK;
        }
    } else {
        return s21_bcd_Add(value_2, value_1, result);
    }

    s21_bcd_SetExp(result, s21_bcd_GetExp(&value_1));

    return s21_bcd_Normalize(result, BCD_ROUND_BANK);
}

