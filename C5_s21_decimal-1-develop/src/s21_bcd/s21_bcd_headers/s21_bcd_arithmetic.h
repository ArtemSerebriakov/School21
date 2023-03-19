#ifndef __S21_ARITHMETIC_H__
#define __S21_ARITHMETIC_H__

#include "s21_bcd.h"
#include "s21_bcd_binary_api.h"


/*******
 *
 * These are primitive algorithms.
 *
 * They dont take into account exp and sign.
 * They dont check or return errors.
 * They just do calculations between bits.
 *
 *******/


extern void s21_bcd_AddAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern void s21_bcd_SubAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern void s21_bcd_MulAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern s21_bcd s21_bcd_DivAlgorithm(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);  // returns remainder

#endif  // __S21_ARITHMETIC_H__

