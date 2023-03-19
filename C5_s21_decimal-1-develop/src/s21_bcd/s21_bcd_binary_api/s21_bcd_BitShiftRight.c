#include "../s21_bcd_headers/s21_bcd_binary_api.h"


static void s21_bcd_BitShiftRight_One(s21_bcd *num) {
    for (int i = 0; i < BCD_BYTES-1; ++i) {
        num->bits[i] >>= 1;
        int first_bit_in_left_neighbour = (i+1)*BCD_BITS_IN_BIT;
        if (s21_bcd_IsBitSet(num, first_bit_in_left_neighbour)) {
            s21_bcd_BitSet(num, first_bit_in_left_neighbour-1);
        }
    }
    num->bits[BCD_BYTES-1] >>= 1;
}

void s21_bcd_BitShiftRight(s21_bcd *num, const int count) {
    for (int i = 0; i < count; ++i) {
        s21_bcd_BitShiftRight_One(num);
    }
}

