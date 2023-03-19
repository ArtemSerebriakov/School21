#ifndef __S21_BCD_H__
#define __S21_BCD_H__

#include "../../s21_decimal/s21_decimal_headers/s21_decimal.h"

#define BCD_BYTES (31)  // to avoid overflows
#define BCD_BITS_IN_BIT (8)
#define BCD_BITS (BCD_BYTES*BCD_BITS_IN_BIT)
#define BCD_MAX_VALID_EXP (28)


//  main bcd struct
typedef struct {
    uint8_t bits[BCD_BYTES];
    uint8_t sign : 1;
    uint8_t exp : 7;
} s21_bcd;


/*******
 *
 * Whole decimal type works through this functions
 *
 *******/


//  convertation functions (aka double dabble algorithm)
extern void s21_from_decimal_to_bcd(s21_decimal src, s21_bcd *dst);
extern void s21_from_bcd_to_decimal(s21_bcd src, s21_decimal *dst);
//

// arithmetic functions
typedef enum {
 BCD_ARITHMETIC_OK = 0,
 BCD_ARITHMETIC_INF = 1,
 BCD_ARITHMETIC_NINF = 2,
 BCD_ARITHMETIC_NAN = 3
} s21_bcd_ArithmeticStatus;

extern s21_bcd_ArithmeticStatus s21_bcd_Add(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern s21_bcd_ArithmeticStatus s21_bcd_Sub(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern s21_bcd_ArithmeticStatus s21_bcd_Mul(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern s21_bcd_ArithmeticStatus s21_bcd_Div(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
extern s21_bcd_ArithmeticStatus s21_bcd_Mod(s21_bcd value_1, s21_bcd value_2, s21_bcd *result);
//

//  rounding functions
typedef enum {
   BCD_ROUNDING_OK = 0,
   BCD_ROUNDING_ERROR = 1
} s21_bcd_RoundingStatus;

extern s21_bcd_RoundingStatus s21_bcd_Floor(s21_bcd value, s21_bcd *result);
extern s21_bcd_RoundingStatus s21_bcd_Round(s21_bcd value, s21_bcd *result);
extern s21_bcd_RoundingStatus s21_bcd_Truncate(s21_bcd value, s21_bcd *result);
//

//  compare functions
typedef enum {
   BCD_COMPARE_FALSE = 0,
   BCD_COMPARE_TRUE = 1
} s21_bcd_CompareStatus;

extern s21_bcd_CompareStatus s21_bcd_IsLess(s21_bcd value_1, s21_bcd value_2);
extern s21_bcd_CompareStatus s21_bcd_IsLessOrEqual(s21_bcd value_1, s21_bcd value_2);
extern s21_bcd_CompareStatus s21_bcd_IsGreater(s21_bcd value_1, s21_bcd value_2);
extern s21_bcd_CompareStatus s21_bcd_IsGreaterOrEqual(s21_bcd value_1, s21_bcd value_2);
extern s21_bcd_CompareStatus s21_bcd_IsEqual(s21_bcd value_1, s21_bcd value_2);
extern s21_bcd_CompareStatus s21_bcd_IsNotEqual(s21_bcd value_1, s21_bcd value_2);
//

#endif  // __S21_BCD_H__

