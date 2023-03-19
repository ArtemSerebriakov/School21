#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"
#include "../s21_bcd_headers/s21_bcd_arithmetic.h"


/*******
 *
 * Division, using shift and substract method.
 * See https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnxjc3Ryb2phbnN8Z3g6ODM1ZGQxZmJjMWY1ZjJl as example.
 *
 * Example: we need 1007/5 = ?, remainder = ?
 * Basic rule:
 * 1) Select leftmost quotient digit to set.
 *    Align divisor with leftmost digits of divident.
 *
 *    1007 = |0001 0000|0000 0111|
 *    5 = |0000 0101|
 *    We need: |0001 0000|0000 0111|
 *             |0101|
 *
 * 2) Compare divisor with divident digits above it.
 *    (divisor > divident digits) ?
 *    1. If No -> substract the divisor from the divident digits.
 *       Replace divident digits with the result.
 *       Increment quotient digit.
 *    2. If Yes -> (divisor > divident) ?
 *       1. If Yes -> done.
 *       2. If No -> shift divisor to the right one digit.
 *          Move right in quotient one digit.
 * 3) Go to 2) again until done.
 *
 * (0101 > 0001) -> Yes, (0101 > |0001 0000|0000 0111|) -> No.
 * Current result was |0000 0000|0000 0000|
 * Move to this quotient ~~~^
 * Shift divisor one digit right
 * |0001 0000|0000 0111|
 * |0000 0101|
 *
 * (0101 > |0001 0000|) -> No
 * Increment quotient digit -> |0000 0001|0000 0000|
 * Substract and replace from divident digits
 * Now we have:
 * |0000 0101|0000 0111|
 * |0000 0101|
 *
 * Continue until done.
 *
 *******/


static int s21_bcd_CountLeadingZeros(const s21_bcd *num);
static void s21_bcd_ExtractRemain(s21_bcd *num, const int digit, s21_bcd *remain);
static s21_bcd_CompareStatus s21_bcd_IsGreater_Num(const s21_bcd *value_1, const s21_bcd *value_2);


s21_bcd s21_bcd_DivAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result) {
    if (s21_bcd_IsGreater_Num(&value_2, &value_1)) {
        result->bits[0] = 0;
        return value_1;
    }

    s21_bcd remain;
    s21_bcd_FillWithZeros(&remain);

    int leading_zeros_diff = s21_bcd_CountLeadingZeros(&value_2) - s21_bcd_CountLeadingZeros(&value_1);

    s21_bcd_FastMulByTenPow(&value_2, leading_zeros_diff);  // align divisor to divident
    s21_bcd_ExtractRemain(&value_1, leading_zeros_diff, &remain);  // need to work only with some digits, not with whole num

    int index = BCD_BYTES*2-1;  // index we need to store result
    while (1) {
        if (!s21_bcd_IsGreater_Num(&value_2, &value_1)) {  // compare only needed digits
            s21_bcd_SubAlgorithm(value_1, value_2, &value_1);

            result->bits[index/2] += (1 << ((index % 2) ? 4 : 0));  // if low num += 1, if high num += 1 << 4

            continue;
        }

        s21_bcd_AddAlgorithm(value_1, remain, &value_1);  // add remain to compare whole number with divisor
        s21_bcd_FastDivByTenPow(&value_2, leading_zeros_diff);  // reset alignment to compare with divident

        if (!s21_bcd_IsGreater_Num(&value_2, &value_1)) {  // compare whole numbers
            --index;  // move right result digit
            --leading_zeros_diff;  // move to the next digit

            s21_bcd_FastMulByTenPow(&value_2, leading_zeros_diff);  // move divisor right

            s21_bcd_FillWithZeros(&remain);  // reset remain
            s21_bcd_ExtractRemain(&value_1, leading_zeros_diff, &remain);

            continue;
        }

        break;
    }

    // substract leading_zeros_diff from index, to prevent situation like this: 12000/12 = 1, as 12000-12000 = 0 and we escape from while
    s21_bcd_FastDivByTenPow(result, index-leading_zeros_diff);  // move result to right, as we started indexing from left

    return value_1;  // remainder
}

int s21_bcd_CountLeadingZeros(const s21_bcd *num) {
    int zeros_counter = 0;

    for (int i = BCD_BYTES-1; i >= 0; --i) {
        if (!num->bits[i]) {  // checks for whole byte == 0
            zeros_counter += 2;  // if whole byte == 0, |0000 0000| we have 2 zeros
        } else {
            if (!(num->bits[i] >> 4)) {  // check for high num only, example: |0000 1001| != 0, but has leading zero
                zeros_counter += 1;
            }
            break;  // iterate until first non-null num
        }
    }

    return zeros_counter;
}

s21_bcd_CompareStatus s21_bcd_IsGreater_Num(const s21_bcd *value_1, const s21_bcd *value_2) {
    for (int i = BCD_BYTES-1; i >= 0; --i) {
        if (value_1->bits[i] != value_2->bits[i]) {
            if (value_1->bits[i] > value_2->bits[i]) {
                return BCD_COMPARE_TRUE;
            } else {
                return BCD_COMPARE_FALSE;
            }
        }
    }

    return BCD_COMPARE_FALSE;  // nums are equal, which is not in condition
}

/*******
 *
 * In this function we extract remain number.
 *
 * Example:
 * We have: num = 12345678, digit = 3.
 * We get: num = 12345000, remain = 678.
 *
 *******/
void s21_bcd_ExtractRemain(s21_bcd *num, const int digit, s21_bcd *remain) {
    if (digit > 0) {
        for (int i = 0; i < digit/2; ++i) {
            remain->bits[i] = num->bits[i];
            num->bits[i] = 0;
        }
        if (digit % 2) { // if we have odd digit, we need to extract from low num
            remain->bits[digit/2] = (num->bits[digit/2] & 15);
            num->bits[digit/2] &= (~15);
        }
    }
}

