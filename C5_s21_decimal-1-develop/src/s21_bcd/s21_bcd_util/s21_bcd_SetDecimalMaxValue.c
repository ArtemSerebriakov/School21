#include "../s21_bcd_headers/s21_bcd_util.h"


extern void s21_bcd_SetDecimalMaxValue(s21_bcd *num) {
    s21_bcd_FillWithZeros(num);

    num->bits[0] = 0x35;
    num->bits[1] = 0x03;
    num->bits[2] = 0x95;
    num->bits[3] = 0x43;
    num->bits[4] = 0x35;
    num->bits[5] = 0x59;
    num->bits[6] = 0x37;
    num->bits[7] = 0x43;
    num->bits[8] = 0x26;
    num->bits[9] = 0x14;
    num->bits[10] = 0x25;
    num->bits[11] = 0x16;
    num->bits[12] = 0x28;
    num->bits[13] = 0x92;
    num->bits[14] = 0x07;
}

