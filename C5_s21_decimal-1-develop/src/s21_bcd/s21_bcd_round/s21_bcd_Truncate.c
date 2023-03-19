#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


// removes digits after decimal point
s21_bcd_RoundingStatus s21_bcd_Truncate(s21_bcd value, s21_bcd *result) {
    s21_bcd_FastDivByTenPow(&value, s21_bcd_GetExp(&value));
    s21_bcd_SetExp(&value, 0);

    s21_bcd_Copy(&value, result);

    return BCD_ROUNDING_OK;
}

