#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"

#define OVERFLOW_DIGIT (28)


void s21_bcd_AlignByScale(s21_bcd *value_1, s21_bcd *value_2) {
    const uint8_t exp_high = s21_bcd_GetExp(value_1);
    const uint8_t exp_low = s21_bcd_GetExp(value_2);

    if (s21_bcd_IsZero(value_1)) {
        s21_bcd_SetExp(value_1, s21_bcd_GetExp(value_2));
    } else if (s21_bcd_IsZero(value_2)) {
        s21_bcd_SetExp(value_2, s21_bcd_GetExp(value_1));
    }

    if (exp_high == exp_low) {
        return;
    }

    if (exp_high < exp_low) {  // exp_high should be bigger than exp_low
        s21_bcd_AlignByScale(value_2, value_1);
        return;
    }

    uint8_t exp_diff = exp_high - exp_low;
    for (uint8_t i = 1; i <= exp_diff; ++i) {
        s21_bcd_FastMulByTenPow(value_2, 1);

        if (value_2->bits[OVERFLOW_DIGIT]) {  // check overflow over some forward digits
            s21_bcd_FastDivByTenPow(value_1, exp_diff-i);  // clear useless digits
            exp_diff = i;
            break;
        }
    }

    s21_bcd_SetExp(value_1, exp_low+exp_diff);
    s21_bcd_SetExp(value_2, exp_low+exp_diff);
}

