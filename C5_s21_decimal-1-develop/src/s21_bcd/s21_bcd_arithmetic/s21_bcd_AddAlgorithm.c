#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


/*******
 *
 * Basic rule for adding two packed bcd numbers.
 *
 * We have packed bcd, two numbers stored in one byte,
 * |1001 0110|
 *   ^    ^
 *   |    low number
 *   ~~~~high number
 *
 *  We sum two bytes as usual.
 *  After adding two numbers, check the result.
 *  1) If low/high number > 9, then add 6/(6<<4) to it.
 *  2) If low/high number < 9 and we have carry bit, then add 6/(6<<4) to it.
 *  3) Else do nothing, the number is valid.
 *
 *  Before that, need to check all condtions for carry bits for these rules.
 *
 *******/


void s21_bcd_AddAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    uint8_t carry_low, carry_high, sum_low, sum_high, sum;
    carry_low = carry_high = sum_low = sum_high = sum = 0;

    for (int i = 0; i < BCD_BYTES; ++i) {
        sum = value_1.bits[i] + value_2.bits[i] + carry_high;  // carry bit from previous high num

        sum_low = (value_1.bits[i] & 15) + (value_2.bits[i] & 15) + carry_high;  // sum of two low num
        if (sum_low & (1 << 4)) {  // check low carry bit
            carry_low = 1;
        }

        carry_high = 0;  // reset high carry bit, as we already used it

        sum_high = (value_1.bits[i] >> 4) + (value_2.bits[i] >> 4);  // sum of two high
        if (sum_high & (1 << 4)) {  // check high carry bit
            carry_high = 1;
        }

        if ((sum & 15) > 9 || (((sum & 15) < 9 && carry_low))) {  // first/second rule for low number, as we sum from right to left
            sum += 6;
            if ((sum >> 4) == 0) {  // if we overflowed, set high carry bit for the fisrt rule
                carry_high = 1;
            }
        }
        if ((sum >> 4) > 9 || ((sum >> 4) < 9 && carry_high)) {  // first/second rule for high number
            sum += (6 << 4);
            carry_high = 1;
        }

        carry_low = 0;  // reset low carry bit

        result->bits[i] = sum;  // now the number is valid
    }
}

