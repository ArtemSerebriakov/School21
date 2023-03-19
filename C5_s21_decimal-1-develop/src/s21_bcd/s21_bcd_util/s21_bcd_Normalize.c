#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


static void s21_bcd_RemoveTrailingZeros(s21_bcd *num);
static void s21_bcd_NormalizeExp(s21_bcd *num, const s21_bcd_RoundType round_type);
static void s21_bcd_NormalizeValue(s21_bcd *num, const s21_bcd_RoundType round_type);


s21_bcd_ArithmeticStatus s21_bcd_Normalize(s21_bcd *num, const s21_bcd_RoundType round_type) {
    s21_bcd_RemoveTrailingZeros(num);

    s21_bcd_NormalizeExp(num, round_type);

    s21_bcd_RemoveTrailingZeros(num);

    s21_bcd_NormalizeValue(num, round_type);

    s21_bcd_RemoveTrailingZeros(num);

    if (s21_bcd_IsZero(num)) {
        s21_bcd_SetSign(num, BCD_SIGN_PLUS);
    }

    return s21_bcd_IsNormal(num);
}

void s21_bcd_RemoveTrailingZeros(s21_bcd *num) {
    uint8_t exp = s21_bcd_GetExp(num);
    while (exp) {  // also reduces exp, if num is zero
        if (!(num->bits[0] & 15)) {  // if last digit is zero
            s21_bcd_FastDivByTenPow(num, 1);
            --exp;
        } else {
            break;
        }
    }
    s21_bcd_SetExp(num, exp);
}

static void s21_bcd_UpRoundingOneDigit(s21_bcd *num) {
    s21_bcd bcd_one;
    s21_bcd_FillWithZeros(&bcd_one);
    bcd_one.bits[0] = 1;

    s21_bcd_FastDivByTenPow(num, 1);
    s21_bcd_AddAlgorithm(*num, bcd_one, num);
}

static void s21_bcd_NoRoundingOneDigit(s21_bcd *num) {
    s21_bcd_FastDivByTenPow(num, 1);
}

static void s21_bcd_BankRoundingOneDigit(s21_bcd *num, const s21_bcd_Sign sign) {
    const int8_t one = (sign == BCD_SIGN_MINUS) ? -1 : 1;  // if its neg value we need to substract
    if (!(((int8_t)(num->bits[0] >> 4) + one) % 2)) {
        s21_bcd_UpRoundingOneDigit(num);  // if next digit(+-1) is even -> round
    } else {  // else dont
        s21_bcd_NoRoundingOneDigit(num);
    }
}

static void s21_bcd_RoundingOneDigit(s21_bcd *num, const uint8_t last_digit, const uint8_t bank_rounding_suitable_flag, const s21_bcd_RoundType round_type) {
    if (last_digit >= 5) {
        if ((round_type == BCD_ROUND_BANK) && (last_digit == 5) && bank_rounding_suitable_flag) {
            s21_bcd_BankRoundingOneDigit(num, s21_bcd_GetSign(num));
        } else {
            s21_bcd_UpRoundingOneDigit(num);
        }
    } else {
        s21_bcd_NoRoundingOneDigit(num);
    }
}

void s21_bcd_NormalizeExp(s21_bcd *num, const s21_bcd_RoundType round_type) {
    uint8_t exp = s21_bcd_GetExp(num);

    uint8_t prev_last_digit = 0, bank_rounding_suitable_flag = 1;
    for (uint8_t is_toggled_flag = 0; exp > BCD_MAX_VALID_EXP; --exp) {
        if (!is_toggled_flag && prev_last_digit) {
            bank_rounding_suitable_flag = 0;  // if all digits before rounding digit are zeros, it can be bank-rounded
            is_toggled_flag = 1;
        }

        prev_last_digit = num->bits[0] & 15;  // check last digit
        s21_bcd_FastDivByTenPow(num, 1);
    }
    s21_bcd_SetExp(num, exp);

    s21_bcd_FastMulByTenPow(num, 1);  // multp because rounding function also divides by 10
    s21_bcd_RoundingOneDigit(num, prev_last_digit, bank_rounding_suitable_flag, round_type);
}

void s21_bcd_NormalizeValue(s21_bcd *num, const s21_bcd_RoundType round_type) {
    s21_bcd dec_max_val;
    s21_bcd_SetDecimalMaxValue(&dec_max_val);

    uint8_t exp = s21_bcd_GetExp(num);
    const s21_bcd_Sign sign = s21_bcd_GetSign(num);

    s21_bcd_SetExp(num, 0);
    s21_bcd_SetSign(num, BCD_SIGN_PLUS);

    uint8_t prev_last_digit = 0, bank_rounding_suitable_flag = 1;
    for (uint8_t is_toggled_flag = 0; exp && s21_bcd_IsGreater(*num, dec_max_val); --exp) {  // if its still denormal number, but we have exp reduce it
        if (!is_toggled_flag && prev_last_digit) {
            bank_rounding_suitable_flag = 0;
            is_toggled_flag = 1;
        }

        prev_last_digit = num->bits[0] & 15;
        s21_bcd_FastDivByTenPow(num, 1);
    }

    if (s21_bcd_IsEqual(*num, dec_max_val) && prev_last_digit >= 5) {
        prev_last_digit = num->bits[0] & 15;
        s21_bcd_FastDivByTenPow(num, 1);
    }
    s21_bcd_SetSign(num, sign);  // needed in rounding function
    s21_bcd_SetExp(num, exp);

    s21_bcd_FastMulByTenPow(num, 1);
    s21_bcd_RoundingOneDigit(num, prev_last_digit, bank_rounding_suitable_flag, round_type);
}

