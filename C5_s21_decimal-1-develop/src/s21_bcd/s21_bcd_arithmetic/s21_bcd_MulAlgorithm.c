#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


/*******
 *
 * Multiplication of decimal numbers can be done by performing a series of additions and shifts.
 * See https://www.renesas.com/us/en/document/apn/multiplication-4-digit-bcd-numbers-muld as example.
 *
 * This algorithm implements column multiplication.
 * For better performance value_2 should be less than value_1.
 *
 * Simple example:
 * 5678 * 1234
 * 5678 * 1 = 0000 5678 (on these steps, we use s21_bcd_MulAlgorithm_ByOneDigit function)
 * 0000 5678 * 10 = 0005 6780
 * 5678 * 2 + prev = 0006 8136
 * 0006 8136 * 10 = 0068 1360
 * 5678 * 3 + prev = 0069 8394
 * 0069 8394 * 10 = 0698 3940
 * 5678 * 4 + prev = 0700 6652
 * done.
 *
 ********/


static void s21_bcd_MulAlgorithm_ByOneDigit(const s21_bcd *num, const uint8_t digit, s21_bcd *result);


void s21_bcd_MulAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    s21_bcd mul_result;  // result of mul by one digit
    s21_bcd_FillWithZeros(&mul_result);

    int leading_zero_counter = 0;
    for (int i = BCD_BYTES-1; i >= 0; --i) {  // skipping leading zeros to reduce useless iterations
        if (!value_2.bits[i]) {
            ++leading_zero_counter;
        } else {
            break;
        }
    }

    for (int i = BCD_BYTES-leading_zero_counter-1; i >= 0; --i) {  // mul from highest digit to lowest
        s21_bcd_FillWithZeros(&mul_result);  // reset num

        // calculate mul by high num
        s21_bcd_MulAlgorithm_ByOneDigit(&value_1, (value_2.bits[i] >> 4), &mul_result);
        s21_bcd_AddAlgorithm(*result, mul_result, result);
        s21_bcd_FastMulByTenPow(result, 1);

        s21_bcd_FillWithZeros(&mul_result);

        // calculate mul by low num
        s21_bcd_MulAlgorithm_ByOneDigit(&value_1, (value_2.bits[i] & 15), &mul_result);
        s21_bcd_AddAlgorithm(*result, mul_result, result);
        s21_bcd_FastMulByTenPow(result, 1);
    }

    s21_bcd_FastDivByTenPow(result, 1);  // div by 10, to undo extra step in the last iteration
}

void s21_bcd_MulAlgorithm_ByOneDigit(const s21_bcd *num, const uint8_t digit, s21_bcd *result) {
    if (digit == 0) {  // check for 0 and 1, not to do extra steps
        s21_bcd_FillWithZeros(result);
        return;
    }

    if (digit == 1) {
        s21_bcd_Copy(num, result);
        return;
    }

    uint8_t carry, mul_result;
    carry = mul_result = 0;

    for (int i = 0; i < BCD_BYTES; ++i) {
        mul_result = (num->bits[i] & 15) * digit + carry;  // result of mul low num
        result->bits[i] |= (mul_result % 10);  // mod 10, to avoid overflows
        carry = mul_result / 10;  // div 10, to find carry digit

        mul_result = (num->bits[i] >> 4) * digit + carry;  // same but with high num
        result->bits[i] |= ((mul_result % 10) << 4);
        carry = mul_result / 10;
    }
}

