#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"

#include "../../s21_decimal/s21_decimal_headers/s21_decimal.h"
#include "../../s21_decimal/s21_decimal_headers/s21_decimal_util.h"


void s21_from_bcd_to_decimal(s21_bcd src, s21_decimal *dst) {
    s21_decimal_FillWithZeros(dst);

    s21_decimal_SetSign(dst, (int)s21_bcd_GetSign(&src));
    s21_decimal_SetExp(dst, s21_bcd_GetExp(&src));

    for (int i = 0; i < DECIMAL_NUM_BITS; ++i) {
        s21_decimal_BitShiftRight(dst, 1);
        if (s21_bcd_IsBitSet(&src, 0)) {
            s21_decimal_BitSet(dst, DECIMAL_NUM_BITS-1);
        }
        s21_bcd_BitShiftRight(&src, 1);

        for (int j = 0; j < BCD_BYTES; ++j) {
            if ((src.bits[j] >> 4) >= 8) {
                src.bits[j] -= (3 << 4);
            }
            if ((src.bits[j] & 15) >= 8) {
                src.bits[j] -= 3;
            }
        }
    }
}

