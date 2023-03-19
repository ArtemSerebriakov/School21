#ifndef __S21_BINARY_API_H__
#define __S21_BINARY_API_H__

#include "s21_bcd.h"


typedef enum {
    BCD_BIT_RESET = 0,
    BCD_BIT_SET = 1
} s21_bcd_BitStatus;

// index from 0 to BCD_BITS-1
extern s21_bcd_BitStatus s21_bcd_IsBitSet(const s21_bcd *num, const int index);
extern s21_bcd_BitStatus s21_bcd_BitSet(s21_bcd *num, const int index);
extern s21_bcd_BitStatus s21_bcd_BitReset(s21_bcd *num, const int index);
extern s21_bcd_BitStatus s21_bcd_BitToggle(s21_bcd *num, const int index);

extern void s21_bcd_BitShiftLeft(s21_bcd *num, const int count);
extern void s21_bcd_BitShiftRight(s21_bcd *num, const int count);

#endif  // __S21_BINARY_API_H__

