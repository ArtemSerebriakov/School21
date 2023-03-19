#include "../s21_bcd_headers/s21_bcd_util.h"


void s21_bcd_Copy(const s21_bcd *src, s21_bcd *dst) {
    memcpy(dst, src, sizeof(s21_bcd));
}
