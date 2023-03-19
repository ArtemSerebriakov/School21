#ifndef __S21_BCD_UTIL_H__
#define __S21_BCD_UTIL_H__

#include "s21_bcd.h"
#include "s21_bcd_binary_api.h"


extern void s21_bcd_AlignByScale(s21_bcd *value_1, s21_bcd *value_2);


typedef enum {
    BCD_ROUND_MATH = 0,
    BCD_ROUND_BANK = 1
} s21_bcd_RoundType;

extern s21_bcd_ArithmeticStatus s21_bcd_Normalize(s21_bcd *num, const s21_bcd_RoundType round_type);
extern s21_bcd_ArithmeticStatus s21_bcd_IsNormal(s21_bcd *num);

extern void s21_bcd_FillWithZeros(s21_bcd *num);  // fills the whole struct with zeros
extern void s21_bcd_Copy(const s21_bcd *src, s21_bcd *dst);  // copies whole src to dst

extern s21_bcd_CompareStatus s21_bcd_IsZero(const s21_bcd *num);
extern void s21_bcd_SetDecimalMaxValue(s21_bcd *num);  // sign and exp are zeros, value=2^96-1

extern void s21_bcd_FastMulByTenPow(s21_bcd *num, const int count);
extern void s21_bcd_FastDivByTenPow(s21_bcd *num, const int count);

extern uint8_t s21_bcd_GetExp(const s21_bcd *num);
extern void s21_bcd_SetExp(s21_bcd *num, const uint8_t exp);


typedef enum {
    BCD_SIGN_PLUS = 0,
    BCD_SIGN_MINUS = 1
} s21_bcd_Sign;

extern s21_bcd_Sign s21_bcd_GetSign(const s21_bcd *num);
extern s21_bcd_Sign s21_bcd_SetSign(s21_bcd *num, const s21_bcd_Sign sign);

#endif  // __S21_BCD_UTIL_H__

