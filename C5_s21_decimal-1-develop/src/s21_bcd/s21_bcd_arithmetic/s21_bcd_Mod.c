#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


s21_bcd_ArithmeticStatus s21_bcd_Mod(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    s21_bcd_FillWithZeros(result);

    if (s21_bcd_IsZero(&value_2)) {
        return BCD_ARITHMETIC_NAN;
    }

    if (s21_bcd_IsZero(&value_1)) {
        return BCD_ARITHMETIC_OK;
    }

    s21_bcd_AlignByScale(&value_1, &value_2);

    const s21_bcd_Sign sign = s21_bcd_GetSign(&value_1);
    const uint8_t exp = (s21_bcd_GetExp(&value_1) > s21_bcd_GetExp(&value_2)) ? s21_bcd_GetExp(&value_1) : s21_bcd_GetExp(&value_2);

    s21_bcd remain = s21_bcd_DivAlgorithm(value_1, value_2, result);
    s21_bcd_SetExp(&remain, exp);
    s21_bcd_SetSign(&remain, sign);

    s21_bcd_SetSign(result, (s21_bcd_GetSign(&value_1) == s21_bcd_GetSign(&value_2)) ? BCD_SIGN_PLUS : BCD_SIGN_MINUS);
    const s21_bcd_ArithmeticStatus ret_status = s21_bcd_IsNormal(result);  // check overflow

    s21_bcd_Copy(&remain, result);

    s21_bcd_Normalize(result, BCD_ROUND_BANK);

    return ret_status;
}

