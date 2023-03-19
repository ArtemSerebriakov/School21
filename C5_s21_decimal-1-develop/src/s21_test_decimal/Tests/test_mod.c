#include "test.h"
#include "../../s21_decimal/s21_decimal_headers/s21_decimal_util.h"

/*-----SIMPE mod TEST-----*/

static s21_decimal num1[] = {
    {{0x0012D687, 0x00000000, 0x00000000, 0x00020000}},  // 0: 12345.67
    {{0x0012D687, 0x00000000, 0x00000000, 0x00020000}},  // 1: 12345.67
    {{0x0012D687, 0x00000000, 0x00000000, 0x80020000}},  // 2: -12345.67
    {{0x0012D687, 0x00000000, 0x00000000, 0x80020000}},  // 3: -12345.67
    {{0x00000314, 0x00000000, 0x00000000, 0x00000000}},  // 4: 788
    {{0x0000300C, 0x00000000, 0x00000000, 0x00020000}},  // 5: 123.00
    {{0x0000007B, 0x00000000, 0x00000000, 0x00000000}},  // 6: 123
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 7: 10
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 8: 10
    {{0x000000B6, 0x00000000, 0x00000000, 0x00000000}},  // 9: 182
    {{0x0001F0F1, 0x00000000, 0x00000000, 0x00000000}},  // 10: 127217
    {{0x000000D4, 0x00000000, 0x00000000, 0x80000000}},  // 11: -212
    {{0x014CF9BF, 0x00000000, 0x00000000, 0x80020000}},  // 12: -218218.87
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 13: 0
    {{0x0001DC88, 0x00000000, 0x00000000, 0x00020000}},  // 14: 1219.92
    {{0x001D537F, 0x00000000, 0x00000000, 0x80020000}},  // 15: -19219.19
    {{0x7D17C946, 0x00000BA8, 0x00000000, 0x00040000}},  // 16: 1281828112.2118
    {{0x7D17C946, 0x00000BA8, 0x00000000, 0x00040000}},  // 17: 1281828112.2118
    {{0x00000369, 0x00000000, 0x00000000, 0x00000000}},  // 18: 873
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 19: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 20: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 21: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // 22: -79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // 23: -79228162514264337593543950335
    {{0x0001DD09, 0x00000000, 0x00000000,
      0x00110000}},  // 24: 0.00000000000122121
    {{0x00140263, 0x00000000, 0x00000000,
      0x00120000}},  // 25: 0.000000000001311331
    {{0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
      0x00000000}},  // 26: 79228162495817593524129366015
    {{0x000000B7, 0x00000000, 0x00000000, 0x00010000}},  // 27: 18.3
    {{0x000000B7, 0x00000000, 0x00000000, 0x00010000}},  // 28: 18.3
    {{0x000000B7, 0x00000000, 0x00000000, 0x80010000}},  // 29: -18.3
    {{0x000000B7, 0x00000000, 0x00000000, 0x80010000}},  // 30: -18.3
    {{0x076C92E0, 0x00000000, 0x00000000, 0x00050000}},  // 31: 1245.56000
    {{0x2D4DABD5, 0x0D46CEC3, 0x00000031,
      0x000E0000}},  // 32: 9048471.38920304847829
    {{0x000000F4, 0x00000000, 0x00000000, 0x00010000}},  // 33: 24.4
    {{0x000040D6, 0x00000000, 0x00000000, 0x00030000}},  // 34: 16.598
    {{0x00004A2B, 0x00000000, 0x00000000, 0x00020000}},  // 35: 189.87
    {{0x00003E15, 0x00000000, 0x00000000, 0x80010000}},  // 36: -1589.3
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00060000}},  // 37: 79228162514264337593543.950335
    {{0x000000C1, 0x00000000, 0x00000000, 0x00010000}},  // 38: 19.3
    {{0xC0801381, 0xED66FEAD, 0x00000032,
      0x00060000}},  // 39: 939443843942303.404929
    {{0xB08B6181, 0x0352ACE7, 0x00000000,
      0x00060000}},  // 40: 239443841303.404929
    {{0xE18D2981, 0xED66FE05, 0x00000032,
      0x00060000}},  // 41: 939443843221303.404929
    {{0x2F601381, 0xCD641270, 0x0000C501,
      0x00060000}},  // 42: 930339443843942303.404929
    {{0xE26BC501, 0x873C632E, 0x0007C559,
      0x000A0000}},  // 43: 939443843942303.1221404929
};

static s21_decimal num2[] = {
    {{0x0012D687, 0x00000000, 0x00000000, 0x00020000}},  // 0: 12345.67
    {{0x0012D687, 0x00000000, 0x00000000, 0x80020000}},  // 1: -12345.67
    {{0x0012D687, 0x00000000, 0x00000000, 0x00020000}},  // 2: 12345.67
    {{0x0012D687, 0x00000000, 0x00000000, 0x80020000}},  // 3: -12345.67
    {{0x000000B1, 0x00000000, 0x00000000, 0x00010000}},  // 4: 17.7
    {{0x0000007B, 0x00000000, 0x00000000, 0x00000000}},  // 5: 123
    {{0x0000300C, 0x00000000, 0x00000000, 0x00020000}},  // 6: 123.00
    {{0x00000005, 0x00000000, 0x00000000, 0x00000000}},  // 7: 5
    {{0x00004E2A, 0x00000000, 0x00000000, 0x00000000}},  // 8: 20010
    {{0x00000065, 0x00000000, 0x00000000, 0x00000000}},  // 9: 101
    {{0x04FDBA54, 0x00000000, 0x00000000, 0x00000000}},  // 10: 83737172
    {{0x00000011, 0x00000000, 0x00000000, 0x80000000}},  // 11: -17
    {{0x9336DD9D, 0x00000032, 0x00000000, 0x80020000}},  // 12: -2172182112.29
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 13: 10
    {{0x0116F341, 0x00000000, 0x00000000, 0x80030000}},  // 14: -18281.281
    {{0x00007208, 0x00000000, 0x00000000, 0x00000000}},  // 15: 29192
    {{0xCED1C28B, 0x00000032, 0x00000000, 0x00030000}},  // 16: 218218218.123
    {{0x7EE8E7D9, 0x00000000, 0x00000000, 0x00050000}},  // 17: 21291.92921
    {{0x000D9987, 0x00000000, 0x00000000, 0x00000000}},  // 18: 891271
    {{0x00001DD1, 0x00000000, 0x00000000, 0x00020000}},  // 19: 76.33
    {{0x00001DE5, 0x00000000, 0x00000000, 0x00010000}},  // 20: 765.3
    {{0x00001DE5, 0x00000000, 0x00000000, 0x80010000}},  // 21: -765.3
    {{0x00001DE5, 0x00000000, 0x00000000, 0x00010000}},  // 22: 765.3
    {{0x00001DE5, 0x00000000, 0x00000000, 0x80010000}},  // 23: -765.3
    {{0x000E1209, 0x00000000, 0x00000000,
      0x001B0000}},  // 24: 0.000000000000000000000922121
    {{0xEFB25CB0, 0x00000008, 0x00000000, 0x00060000}},  // 25: 38381.182128
    {{0x00000ADF, 0x00000000, 0x00000000, 0x00030000}},  // 26: 2.783
    {{0x000007FD, 0x00000000, 0x00000000, 0x00020000}},  // 27: 20.45
    {{0x000007FD, 0x00000000, 0x00000000, 0x80020000}},  // 28: -20.45
    {{0x000007FD, 0x00000000, 0x00000000, 0x00020000}},  // 29: 20.45
    {{0x000007FD, 0x00000000, 0x00000000, 0x80020000}},  // 30: -20.45
    {{0x0001E68C, 0x00000000, 0x00000000, 0x00020000}},  // 31: 1245.56
    {{0x151EF64E, 0x00000016, 0x00000000, 0x00070000}},  // 32: 9484.3631182
    {{0x0000007A, 0x00000000, 0x00000000, 0x00020000}},  // 33: 1.22
    {{0x0000007B, 0x00000000, 0x00000000, 0x00010000}},  // 34: 12.3
    {{0x0000DDD5, 0x00000000, 0x00000000, 0x00060000}},  // 35: 0.056789
    {{0x00001DE5, 0x00000000, 0x00000000, 0x00010000}},  // 36: 765.3
    {{0x40A98AC7, 0xFE8401E7, 0x19D971E4,
      0x00080000}},  // 37: 80000000000000000000.11111111
    {{0x00000285, 0x00000000, 0x00000000, 0x00020000}},  // 38: 6.45
    {{0x00004A2B, 0x00000000, 0x00000000, 0x00020000}},  // 39: 189.87
    {{0xCED1B1BB, 0x00000032, 0x00000000, 0x00040000}},  // 40: 21821821.3819
    {{0x00005534, 0x00000000, 0x00000000, 0x80090000}},  // 41: -0.000021812
    {{0x00000315, 0x00000000, 0x00000000, 0x00050000}},  // 42: 0.00789
    {{0xFAF08501, 0x00000002, 0x00000000, 0x00080000}},  // 43: 128.00001281
};

static s21_decimal result_arr[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0: 0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 1: 0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // 2: -0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // 3: -0.00
    {{0x0000005C, 0x00000000, 0x00000000, 0x00010000}},  // 4: 9.2
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 5: 0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 6: 0.00
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 7: 0
    {{0x0000000A, 0x00000000, 0x00000000, 0x00000000}},  // 8: 10
    {{0x00000051, 0x00000000, 0x00000000, 0x00000000}},  // 9: 81
    {{0x0001F0F1, 0x00000000, 0x00000000, 0x00000000}},  // 10: 127217
    {{0x00000008, 0x00000000, 0x00000000, 0x80000000}},  // 11: -8
    {{0x014CF9BF, 0x00000000, 0x00000000, 0x80020000}},  // 12: -218218.87
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 13: 0
    {{0x0001DC88, 0x00000000, 0x00000000, 0x00020000}},  // 14: 1219.92
    {{0x001D537F, 0x00000000, 0x00000000, 0x80020000}},  // 15: -19219.19
    {{0x181FCA20, 0x000001BC, 0x00000000, 0x00040000}},  // 16: 190737021.5968
    {{0x43E3A022, 0x00000000, 0x00000000, 0x00050000}},  // 17: 11389.91138
    {{0x00000369, 0x00000000, 0x00000000, 0x00000000}},  // 18: 873
    {{0x00000CE2, 0x00000000, 0x00000000, 0x00020000}},  // 19: 32.98
    {{0x00000405, 0x00000000, 0x00000000, 0x00010000}},  // 20: 103
    {{0x00000405, 0x00000000, 0x00000000, 0x00010000}},  // 21: 103
    {{0x00000405, 0x00000000, 0x00000000, 0x80010000}},  // 22: -103
    {{0x00000405, 0x00000000, 0x00000000, 0x80010000}},  // 23: -103
    {{0x000A326B, 0x00000000, 0x00000000,
      0x001B0000}},  // 24: 0.000000000000000000000668267
    {{0x00140263, 0x00000000, 0x00000000,
      0x00120000}},  // 25: 0.000000000001311331
    {{0x000004A8, 0x00000000, 0x00000000, 0x00030000}},  // 26: 1.192
    {{0x000000B7, 0x00000000, 0x00000000, 0x00010000}},  // 27: 18.3
    {{0x000000B7, 0x00000000, 0x00000000, 0x00010000}},  // 28: 18.3
    {{0x000000B7, 0x00000000, 0x00000000, 0x80010000}},  // 29: -18.3
    {{0x000000B7, 0x00000000, 0x00000000, 0x80010000}},  // 30: -18.3
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 31: 0.00000
    {{0xEDC58DD5, 0x008A3104, 0x00000000,
      0x000E0000}},  // 32: 388.97444024847829
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 33: 0.00
    {{0x000010CA, 0x00000000, 0x00000000, 0x00030000}},  // 34: 4.298
    {{0x00005F35, 0x00000000, 0x00000000, 0x00060000}},  // 35: 0.024373
    {{0x0000024B, 0x00000000, 0x00000000, 0x80010000}},  // 36: -58.7
    {{0xFE6F5501, 0x92F34391, 0x00E8F471,
      0x00070000}},  // 37: 28162514264337593433.9503361
    {{0x00000040, 0x00000000, 0x00000000, 0x00010000}},  // 38: 6.4
    {{0x07296B31, 0x00000000, 0x00000000, 0x00060000}},  // 39: 120.154929
    {{0xE00DB331, 0x00000D79, 0x00000000, 0x00060000}},  // 40: 14817101.198129
    {{0x0000047C, 0x00000000, 0x00000000, 0x00090000}},  // 41: 0.000001148
    {{0x00000969, 0x00000000, 0x00000000, 0x00060000}},  // 42: 0.002409
    {{0xEE33FCAD, 0x0000007D, 0x00000000, 0x000A0000}},  // 43: 54.0867296429
};

static s21_decimal err_num1[] = {
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 0: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 1: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // 2: -79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // 3: -79228162514264337593543950335
    {{0x0032157F, 0x00000000, 0x00000000, 0x00020000}},  // 4: 32823.03
    {{0x00000004, 0x00000000, 0x00000000, 0x00030000}},  // 5: 0.004
};

static s21_decimal err_num2[] = {
    {{0x00000003, 0x00000000, 0x00000000, 0x00030000}},  // 0: 0.003
    {{0x00000004, 0x00000000, 0x00000000, 0x80010000}},  // 1: -0.4
    {{0x00000009, 0x00000000, 0x00000000, 0x00010000}},  // 2: 0.9
    {{0x0000004E, 0x00000000, 0x00000000, 0x80020000}},  // 3: -0.78
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 4: 0
    {{0x00000000, 0x00000000, 0x00000000, 0x80020000}},  // 5: 0.00
};

static int err_result[] = {
    1, 2, 2, 1, 3, 3,
};

START_TEST(test) {
  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;

    int ret = s21_mod(num1[i], num2[i], &tmp);
    // printf("%zu\n", i);
    // if (i == 2) {
    //   showBinaryFull(tmp);
    //   showBinaryFull(result_arr[i]);
    // }

    ck_assert_int_eq(tmp.bits[0], result_arr[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], result_arr[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], result_arr[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], result_arr[i].bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(error_test) {
  for (size_t i = 0; i < sizeof(err_num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_mod(err_num1[i], err_num2[i], &tmp);

    if (tmp.bits[0] == 0) {
      tmp.bits[0] = 1;
    }
    ck_assert_int_eq(ret, err_result[i]);
  }
}
END_TEST

START_TEST(mod_loop_cross_sign_test_1bit) {
  int j = -497;
  for (int i = 694; i >= -165; i--) {
    int sign1 = 0;
    int sign2 = 0;
    if (i < 0) {
      sign1 = 0x80000000;
    }
    if (j < 0) {
      sign2 = 0x80000000;
    }
    if (j == 0) {
      j++;
    }
    s21_decimal value_1 = {{abs(i), 0, 0, sign1}};
    s21_decimal value_2 = {{abs(j), 0, 0, sign2}};
    s21_decimal result;
    s21_mod(value_1, value_2, &result);
    int got = result.bits[0];
    if (s21_decimal_GetSign(&result) == 1) {
      got *= -1;
    }
    int must = i % j;
    ck_assert_int_eq(got, must);
    if (i % 2 == 0) {
      j++;
    } else {
      j += 3;
    }
  }
}
END_TEST

START_TEST(mod_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(mod_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(mod_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(mod_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(mod_4) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_mod(val1, val2, &res));
}
END_TEST

START_TEST(mod_5) {
  s21_decimal value_1 = {{46, 0, 0, 0}};
  s21_decimal_SetExp(&value_1, 1);
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal_SetExp(&value_2, 2);
  s21_decimal check = {{91, 0, 0, 0}};
  s21_decimal_SetExp(&check, 2);
  s21_decimal res = {0};
  int return_value = s21_mod(value_1, value_2, &res);
  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mod_6) {
  s21_decimal value_1 = {{46, 0, 0, 0}};
  s21_decimal_SetExp(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal_SetExp(&value_2, 2);
  s21_decimal check = {{0, 0, 0, 0}};
  s21_decimal res = {0};
  int return_value = s21_mod(value_1, value_2, &res);
  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(mod_7) {
  s21_decimal value_1 = {{46, 0, 0, 0}};
  s21_decimal_SetExp(&value_1, 1);
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal_SetExp(&value_2, 2);
  s21_decimal_SetSign(&value_2, 1);
  s21_decimal check = {{91, 0, 0, 0}};
  s21_decimal_SetExp(&check, 2);
  s21_decimal res = {0};
  int return_value = s21_mod(value_1, value_2, &res);
  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mod_8) {
  s21_decimal value_1 = {{46, 0, 0, 0}};
  s21_decimal_SetExp(&value_1, 1);
  s21_decimal_SetSign(&value_1, 1);
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal_SetExp(&value_2, 2);
  s21_decimal check = {{91, 0, 0, 0}};
  s21_decimal_SetExp(&check, 2);
  s21_decimal_SetSign(&check, 1);
  s21_decimal res = {0};
  int return_value = s21_mod(value_1, value_2, &res);
  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mod_9) {
  s21_decimal value_1 = {{46, 0, 0, 0}};
  s21_decimal_SetExp(&value_1, 1);
  s21_decimal_SetSign(&value_1, 1);
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal_SetExp(&value_2, 2);
  s21_decimal_SetSign(&value_2, 1);
  s21_decimal check = {{91, 0, 0, 0}};
  s21_decimal_SetExp(&check, 2);
  s21_decimal_SetSign(&check, 1);
  s21_decimal res = {0};
  int return_value = s21_mod(value_1, value_2, &res);
  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(simple_zero_test_1) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(mod_full_test_1) {
  s21_decimal value_1 = {{1, 1, 1, 65536}};
  s21_decimal value_2 = {{1, 1, 1, -2147418112}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(mod_full_test_2) {
  s21_decimal value_1 = {{1, 1, 1, -2147418112}};
  s21_decimal value_2 = {{1, 1, 1, -2146828288}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(mod_full_test_3) {
  s21_decimal value_1 = {{1, 2, 3, -2147418112}};
  s21_decimal value_2 = {{3, 2, 1, -2146828288}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0b00100011001010011011000000000011,
                       0b10001100101001101100000000000, 0,
                       0x80000000 | 10 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(mod_full_test_4) {
  s21_decimal value_1 = {{1, 2, 3, 655360}};
  s21_decimal value_2 = {{3, 2, 1, -2146828288}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0b11111111111111111111111111111011,
                       0b11111111111111111111111111111101, 0, 10 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(basic_mod) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{4, 0, 0, 0}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{2, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(basic_mod_2) {
  s21_decimal value_1 = {{4036421147, 382, 0, 262144}};
  s21_decimal value_2 = {{2945631615, 658, 0, 2147876864}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{867247046, 90, 0, 393216}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(basic_mod_3) {
  s21_decimal value_1 = {{2891627761, 3474792174, 8, 2147811328}};
  s21_decimal value_2 = {{1870970698, 1989793225, 0, 720896}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{1717205652, 1236686312, 0, 720896 + 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(readme_mod) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{1, 0, 0, 196608}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0}};
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(division_on_zero) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{0, 0, 0, 196608}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(division_zero) {
  s21_decimal value_1 = {{0, 0, 0, 196608}};
  s21_decimal value_2 = {{217948, 0, 0, 196608}};
  s21_decimal result;
  int res = s21_mod(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

Suite* test_mod_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("mod_test");
  /* Core test case */
  tc = tcase_create("mod_tc");

  // abs
  tcase_add_test(tc, test);
  tcase_add_test(tc, error_test);
  tcase_add_test(tc, mod_loop_cross_sign_test_1bit);

  tcase_add_test(tc, mod_0);
  tcase_add_test(tc, mod_1);
  tcase_add_test(tc, mod_2);
  tcase_add_test(tc, mod_3);
  tcase_add_test(tc, mod_4);
  tcase_add_test(tc, mod_5);
  tcase_add_test(tc, mod_6);
  tcase_add_test(tc, mod_7);
  tcase_add_test(tc, mod_8);
  tcase_add_test(tc, mod_9);

  tcase_add_test(tc, simple_zero_test_1);
  tcase_add_test(tc, mod_full_test_1);
  tcase_add_test(tc, mod_full_test_2);
  tcase_add_test(tc, mod_full_test_3);
  tcase_add_test(tc, mod_full_test_4);

  tcase_add_test(tc, basic_mod);
  tcase_add_test(tc, basic_mod_2);
  tcase_add_test(tc, basic_mod_3);
  tcase_add_test(tc, readme_mod);
  tcase_add_test(tc, division_on_zero);
  tcase_add_test(tc, division_zero);

  suite_add_tcase(s, tc);

  return s;
}
