#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"

#include "../../s21_decimal/s21_decimal_headers/s21_decimal.h"
#include "../../s21_decimal/s21_decimal_headers/s21_decimal_util.h"


void s21_from_decimal_to_bcd(s21_decimal src, s21_bcd *dst) {
    s21_bcd_FillWithZeros(dst);

    s21_bcd_SetSign(dst, (int)s21_decimal_GetSign(&src));
    s21_bcd_SetExp(dst, s21_decimal_GetExp(&src));

    for (int i = 0; i < DECIMAL_NUM_BITS; ++i) {
        for (int j = 0; j < BCD_BYTES; ++j) {
            if ((dst->bits[j] & 15) >= 5) {
                dst->bits[j] += 3;
            }
            if ((dst->bits[j] >> 4) >= 5) {
                dst->bits[j] += (3 << 4);
            }
        }

        s21_bcd_BitShiftLeft(dst, 1);
        if (s21_decimal_IsBitSet(&src, DECIMAL_NUM_BITS-1)) {
            s21_bcd_BitSet(dst, 0);
        }
        s21_decimal_BitShiftLeft(&src, 1);
    }
}

