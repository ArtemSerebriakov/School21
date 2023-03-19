#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


/*******
 *
 * Substraction, using 9s complement method.
 *
 * Example. We need to calculate 158-79. We have only three digits.
 * 1) Set max value for 3 digit -> 999.
 * 2) Substract 999-79 = 920 (easy, we dont need to calculate carry digits).
 * 3) Add 920 + 158 = 1078 (overflow, max 999) -> 78.
 * 4) Add this overflowed digit to result, 1 + 78 = 79, 158 - 79 = 79.
 *
 *******/


void s21_bcd_SubAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    for (int i = 0; i < BCD_BYTES; ++i) {  // filling bcd with 9 and then substract without carry bits
        result->bits[i] = 0x99 - value_2.bits[i];
    }

    s21_bcd_AddAlgorithm(value_1, *result, result);  // 9s complement method

    s21_bcd_FillWithZeros(&value_2);
    value_2.bits[0] = 1;  // now value_2 is 1

    s21_bcd_AddAlgorithm(value_2, *result, result);  // add 1, and done
}

