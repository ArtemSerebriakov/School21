#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


s21_bcd_ArithmeticStatus s21_bcd_Mul(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    s21_bcd_FillWithZeros(result);

    if (s21_bcd_IsZero(&value_1) || s21_bcd_IsZero(&value_2)) {
        return BCD_ARITHMETIC_OK;  // number is already zero
    }

    if (s21_bcd_GetSign(&value_1) == s21_bcd_GetSign(&value_2)) {
        s21_bcd_SetSign(result, BCD_SIGN_PLUS);
    } else {
        s21_bcd_SetSign(result, BCD_SIGN_MINUS);
    }

    const uint8_t value_1_exp = s21_bcd_GetExp(&value_1);
    const uint8_t value_2_exp = s21_bcd_GetExp(&value_2);

    s21_bcd_SetExp(&value_1, 0);  // to compare plain numbers
    s21_bcd_SetExp(&value_2, 0);
    if (s21_bcd_IsGreater(value_1, value_2)) {  // replace numbers for better performance
        s21_bcd_MulAlgorithm(value_1, value_2, result);
    } else {
        s21_bcd_MulAlgorithm(value_2, value_1, result);
    }
    s21_bcd_SetExp(result, value_1_exp+value_2_exp);

    return s21_bcd_Normalize(result, BCD_ROUND_BANK);
}

