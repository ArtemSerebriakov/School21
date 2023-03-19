#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


s21_bcd_ArithmeticStatus s21_bcd_Div(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    s21_bcd_FillWithZeros(result);

    if (s21_bcd_IsZero(&value_2)) {
        return BCD_ARITHMETIC_NAN;
    }

    if (s21_bcd_IsZero(&value_1)) {
        return BCD_ARITHMETIC_OK;
    }

    s21_bcd_AlignByScale(&value_1, &value_2);

    const s21_bcd_Sign sign = (s21_bcd_GetSign(&value_1) == s21_bcd_GetSign(&value_2)) ? BCD_SIGN_PLUS : BCD_SIGN_MINUS;

    s21_bcd remain = s21_bcd_DivAlgorithm(value_1, value_2, result);
    s21_bcd_FastMulByTenPow(&remain, BCD_MAX_VALID_EXP+2);  // max value +2 to check rounding digit and digit after it

    s21_bcd_FillWithZeros(&value_1);  // reset to store fractional part in it
    s21_bcd_DivAlgorithm(remain, value_2, &value_1);
    s21_bcd_SetExp(&value_1, BCD_MAX_VALID_EXP+2);

    s21_bcd_ArithmeticStatus ret_status = s21_bcd_Add(*result, value_1, result);  // example: 2 + 0.4235235252......

    s21_bcd_SetSign(result, sign);

    if (ret_status == BCD_ARITHMETIC_INF && sign == BCD_SIGN_MINUS) {
        ret_status = BCD_ARITHMETIC_NINF;
    }

    return ret_status;
}

