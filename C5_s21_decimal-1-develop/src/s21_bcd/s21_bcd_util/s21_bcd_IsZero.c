#include "../s21_bcd_headers/s21_bcd.h"
#include "../s21_bcd_headers/s21_bcd_util.h"


s21_bcd_CompareStatus s21_bcd_IsZero(const s21_bcd *num) {
    for (int i = 0; i < BCD_BYTES; ++i) {
        if (num->bits[i]) {
            return BCD_COMPARE_FALSE;
        }
    }

    return BCD_COMPARE_TRUE;
}

