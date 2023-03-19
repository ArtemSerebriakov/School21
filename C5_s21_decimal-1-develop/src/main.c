#include "s21_bcd/s21_bcd_headers/s21_bcd.h"
#include "s21_bcd/s21_bcd_headers/s21_bcd_util.h"
#include "s21_bcd/s21_bcd_headers/s21_bcd_binary_api.h"
#include "s21_bcd/s21_bcd_headers/s21_bcd_arithmetic.h"

#include "s21_decimal/s21_decimal_headers/s21_decimal.h"
#include "s21_decimal/s21_decimal_headers/s21_decimal_util.h"
#include "s21_decimal/s21_decimal_headers/s21_decimal_binary_api.h"

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

void print_bcd_binary(const s21_bcd *num) {
    printf("sign: %d, exp: %d\n", s21_bcd_GetSign(num), s21_bcd_GetExp(num));
    putchar('|');
    for (int i = BCD_BITS-1; i >= 0; --i) {
        putchar(s21_bcd_IsBitSet(num, i) == BCD_BIT_SET ? '1' : '0');
        if (i % 8 == 0) {
            putchar('|');
        }
    }
    putchar('\n');
}

void print_bcd_num(const s21_bcd *num) {
    printf("sign: %d, exp: %d\n", s21_bcd_GetSign(num), s21_bcd_GetExp(num));
    for (int i = BCD_BYTES-1; i >= 0; --i) {
        printf("%d", (num->bits[i] >> 4));
        printf("%d", (num->bits[i] & 15));
    }
    putchar('\n');
}

void print_decimal_binary(const s21_decimal *num) {
    printf("sign: %d, exp: %d\n", s21_decimal_GetSign(num), s21_decimal_GetExp(num));
    putchar('|');
    for (int i = DECIMAL_ALL_BITS-1; i >= 0; --i) {
        putchar(s21_decimal_IsBitSet(num, i) == BCD_BIT_SET ? '1' : '0');
        if (i % 32 == 0) {
            putchar('|');
        }
    }
    putchar('\n');
}

void print_decimal_num(const s21_decimal *num) {
    printf("sign: %d, exp: %d\n", s21_decimal_GetSign(num), s21_decimal_GetExp(num));
    uint64_t res = 0;
    for (int i = DECIMAL_NUM_BITS-1; i >= 0; --i) {
        if (s21_decimal_IsBitSet(num, i)) {
            res += (uint64_t)pow(2, i);
        }
    }
    printf("%lu", res);
    putchar('\n');
}

int compare_num_and_bcd(int num1, s21_bcd num2) {
    char buf1[1024];
    sprintf(buf1, "%d", num1);

    char buf2[1024];
    char *pbuf2 = buf2;
    if (s21_bcd_GetSign(&num2) == BCD_SIGN_MINUS) {
        *pbuf2++ = '-';
    }

    for (int i = BCD_BYTES-1; i >= 0; --i) {
        sprintf(pbuf2++, "%d", (num2.bits[i] >> 4));
        sprintf(pbuf2++, "%d", (num2.bits[i] & 15));
    }
    *pbuf2 = '\0';

    pbuf2 = buf2;
    while (*pbuf2++ == '0') { ; }
    --pbuf2;

    return strcmp(buf1, pbuf2);
}

void print_bcd_num_str(const s21_bcd *num2) {
    printf("sign: %d, exp: %d\n", s21_bcd_GetSign(num2), s21_bcd_GetExp(num2));

    char buf2[1024];
    char *pbuf2 = buf2;
    if (s21_bcd_GetSign(num2) == BCD_SIGN_MINUS) {
        *pbuf2++ = '-';
    }

    for (int i = BCD_BYTES-1; i >= 0; --i) {
        sprintf(pbuf2++, "%d", (num2->bits[i] >> 4));
        sprintf(pbuf2++, "%d", (num2->bits[i] & 15));
    }
    *pbuf2 = '\0';

    pbuf2 = buf2;
    while (*pbuf2++ == '0') { ; }
    --pbuf2;

    puts(pbuf2);
}


int mai(void) {
    srand(time(NULL));

    s21_decimal dec1, dec2, dec3;
    s21_bcd bcd1, bcd2, bcd3;
    int num1, num2, num3;

            num1 = 3, num2 = 2;
            s21_from_int_to_decimal(num1, &dec1);
            s21_from_int_to_decimal(num2, &dec2);

            s21_from_decimal_to_bcd(dec1, &bcd1);
            s21_from_decimal_to_bcd(dec2, &bcd2);

    //scanf("%d %d", &num1, &num2);
    for (int i = 1; i < 990; ++i) {
    //int i = 1200000;
    //int j = 12;
        for (int j = 1; j <= 990; ++j) {
            num1 = i, num2 = j;
            s21_from_int_to_decimal(num1, &dec1);
            s21_from_int_to_decimal(num2, &dec2);

            s21_from_decimal_to_bcd(dec1, &bcd1);
            s21_from_decimal_to_bcd(dec2, &bcd2);

            num3 = num1 * num2;
            s21_bcd_FillWithZeros(&bcd3);
            s21_bcd_MulAlgorithm(bcd1, bcd2, &bcd3);

            //printf("%d + %d = %d\n", num1, num2, num3);
            //print_bcd_num(&bcd1);
            //putchar('\n');
            //print_bcd_num(&bcd2);
            //putchar('\n');
            if (compare_num_and_bcd(num3, bcd3) != 0) {
                printf("%d * %d = %d\n", num1, num2, num3);
                print_bcd_num(&bcd3);
                putchar('\n');
                putchar('\n');
            }
        }
    }

    return 0;
}

int umain(void) {
    //unsigned i;
    //float 0.
//    double num = pow(2, 96) + 100000000000000.0;
//    for (int i = 0; i < 100; ++i)
//    printf("%u\n", (unsigned)S21_DECIMAL_MAX);

    //if (num == S21_DECIMAL_MAX) {
        //printf("%f", S21_DECIMAL_MIN);
    //}

    int num1 = -9999999;
    s21_decimal dec1 = { .bits[3] = 0, .bits[2] = UINT32_MAX, .bits[1] = UINT32_MAX, .bits[0] = UINT32_MAX};
    s21_decimal dec2 = { .bits[3] = 0, .bits[2] = 0, .bits[1] = 0, .bits[0] = 10000 };
    s21_decimal dec3 = { .bits[3] = 0, .bits[2] = 0, .bits[1] = 0, .bits[0] = 10001 };
    int exp = 5;
    s21_bcd bcd1, bcd2, bcd3;

    //s21_from_int_to_decimal(num1, &dec1);
    s21_from_decimal_to_bcd(dec1, &bcd1);
    s21_from_decimal_to_bcd(dec2, &bcd2);
    s21_from_decimal_to_bcd(dec3, &bcd3);
    //s21_decimal_SetExp(&dec1, exp);
    //print_decimal_num(&dec1);
    s21_bcd_SetExp(&bcd2, 4);
    s21_bcd_SetExp(&bcd3, 3);

    s21_bcd_SetSign(&bcd2, BCD_SIGN_MINUS);
    s21_bcd_SetSign(&bcd3, BCD_SIGN_MINUS);
    //s21_truncate(dec1, &dec1);

    //printf("orig: %d\n", num1/(int)pow(10, 5));
    //print_decimal_num(&dec1);
    //s21_bcd_AlignByScale(&bcd1, &bcd2);

    print_decimal_binary(&dec2);
    print_bcd_binary(&bcd2);
    print_bcd_num(&bcd2);
    puts("==========================");
    print_decimal_binary(&dec3);
    print_bcd_binary(&bcd3);
    print_bcd_num(&bcd3);
    puts("==========================");

    if (s21_bcd_IsGreater(bcd2, bcd3)) {
        puts("is greater");
    }

    return 0;
}

int main(void) {
  s21_decimal value_1 = {{1, 1, 1, -2147418112}};
  s21_decimal value_2 = {{1, 1, 1, -2146828288}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0x80000000}};

    /*s21_decimal res = { {0x1, 0x1, 0x1, 0x1} };
    int error = s21_div(num1, num2, &res);*/

  s21_bcd src1_bcd, src2_bcd, origin_bcd, result_bcd;

  s21_from_decimal_to_bcd(value_1, &src1_bcd);
  s21_from_decimal_to_bcd(value_2, &src2_bcd);
  s21_from_decimal_to_bcd(result, &result_bcd);
  s21_from_decimal_to_bcd(must, &origin_bcd);

  puts("src1");
  print_bcd_num(&src1_bcd);
  puts("src2");
  print_bcd_num(&src2_bcd);
  puts("result_bcd");
  print_bcd_num(&result_bcd);
  puts("orig");
  print_bcd_num(&origin_bcd);
  /*puts("ret");
  printf("%d", res);*/
  //printf("or = %d, res = %d\n", value_type_origin, value_type_result);
}








