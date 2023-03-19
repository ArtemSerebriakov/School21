#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_ArithmeticStatus s21_bcd_IsNormal(s21_bcd *num) {
    s21_bcd dec_max_val;
    s21_bcd_SetDecimalMaxValue(&dec_max_val);

    s21_bcd_ArithmeticStatus ret_status = BCD_ARITHMETIC_OK;

    const uint8_t exp = s21_bcd_GetExp(num);
    const s21_bcd_Sign sign = s21_bcd_GetSign(num);

    s21_bcd_SetExp(num, 0);  // reset to compare only plain numbers
    s21_bcd_SetSign(num, BCD_SIGN_PLUS);
    if (s21_bcd_IsGreater(*num, dec_max_val)) {
        ret_status = (sign == BCD_SIGN_MINUS) ? BCD_ARITHMETIC_NINF : BCD_ARITHMETIC_INF;
    }
    s21_bcd_SetExp(num, exp);
    s21_bcd_SetSign(num, sign);

    return ret_status;
}

