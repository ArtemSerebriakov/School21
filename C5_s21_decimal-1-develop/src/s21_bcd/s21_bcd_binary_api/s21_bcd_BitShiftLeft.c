#include "../s21_bcd_headers/s21_bcd_binary_api.h"


static void s21_bcd_BitShiftLeft_One(s21_bcd *num) {
    for (int i = BCD_BYTES-1; i > 0; --i) {
        num->bits[i] <<= 1;
        int last_bit_in_right_neighbour = (i-1)*BCD_BITS_IN_BIT + (BCD_BITS_IN_BIT-1);
        if (s21_bcd_IsBitSet(num, last_bit_in_right_neighbour)) {
            s21_bcd_BitSet(num, last_bit_in_right_neighbour+1);
        }
    }
    num->bits[0] <<= 1;
}

void s21_bcd_BitShiftLeft(s21_bcd *num, const int count) {
    for (int i = 0; i < count; ++i) {
        s21_bcd_BitShiftLeft_One(num);
    }
}

