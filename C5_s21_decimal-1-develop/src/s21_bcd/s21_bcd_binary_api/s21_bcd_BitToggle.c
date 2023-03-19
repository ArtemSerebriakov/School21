#include "../s21_bcd_headers/s21_bcd_binary_api.h"


s21_bcd_BitStatus s21_bcd_BitToggle(s21_bcd *num, const int index) {
    num->bits[index/BCD_BITS_IN_BIT] ^= (1 << (index%BCD_BITS_IN_BIT));
    return s21_bcd_IsBitSet(num, index);
}

