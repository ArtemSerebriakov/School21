#include "test.h"
#include "../../s21_decimal/s21_decimal_headers/s21_decimal_util.h"

/*-----SIMPE div TEST-----*/

START_TEST(simple_div_test_1) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0x80000000}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {
      {0b00011010101010101010101010101011, 0b01100111100100110000001111110111,
       0b110101110110100101011111110010, 0x80000000 | 28 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(simple_div_test_2) {
  s21_decimal value_1 = {{~0, ~0, ~0, 4 << 16}};
  s21_decimal value_2 = {{0b00011010110100001010000000110101,
                          0b00101001111010001110011111100111,
                          0b10000000001100011010001011111101, 0}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0b111100111100010101111, 0, 0, 10 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(simple_div_test_3) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{3334, 5, 1, 0}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0b100000010011111100111001011110, 0, 0, 28 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(simple_div_test_4) {
  s21_decimal value_1 = {{0b10000010111000100101101011101101,
                          0b11111001111010000010010110101101,
                          0b10110000001111101111000010010100, 14 << 16}};
  s21_decimal value_2 = {{0b01001000000110110001111110011000,
                          0b11111011111111011000100101101101,
                          0b00000000000001000110110101110111, 24 << 16}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0b10100100111010110100001011011000,
                       0b10100011110001111010011110110101,
                       0b10101000100101011101010, 12 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(simple_div_test_5) {
  s21_decimal value_1 = {{0b10101110111110000100110000, 0, 0, 2 << 16}};
  s21_decimal value_2 = {{0b10100010001111010011101, 0, 0, 4 << 16}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0b11001001111001101010110101111111,
                       0b11011001000111111110101011110001,
                       0b10110010011010101111000000, 24 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(simple_div_test_6) {
  s21_decimal value_1 = {{0b01010000000000000000000000000000,
                          0b00110110101110010000101111100101,
                          0b10100001100011110000011111010111, 0}};
  s21_decimal value_2 = {{5, 0, 0, 1 << 16}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(simple_div_test_7) {
  s21_decimal value_1 = {{1733885920, 2071111510, 2144231041, 0}};
  s21_decimal value_2 = {{2561081375, 2223855785, 2150736254, 28 << 16}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0b01100011010101101011010100001111,
                       0b00001111010011011010010101111001,
                       0b100000001101101100100101101111, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(simple_div_test_8) {
  s21_decimal value_1 = {{~0, ~0, ~0, 0}};
  s21_decimal value_2 = {{3587, 0, 0, 16 << 16}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(simple_div_test_9) {
  s21_decimal value_1 = {{694, 0, 0, 0}};
  s21_decimal value_2 = {{497, 0, 0, 0x80000000}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {
      {0b00011111100111010001101001000101, 0b11000011111110011111110100100100,
       0b101101000111101001001000000000, 0x80000000 | 28 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(div_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_5) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{70, 0, 0, 0}};
  s21_decimal_SetExp(&value_1, 1);
  s21_decimal_SetExp(&value_2, 2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_6) {
  s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
  s21_decimal value_2 = {{0x2, 0, 0, 0}};
  s21_decimal_SetSign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
  s21_decimal_SetSign(&check, 1);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_7) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal_SetSign(&value_1, 1);
  s21_decimal value_2 = {{8, 0, 0, 0}};
  s21_decimal_SetSign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{125, 0, 0, 0}};
  s21_decimal_SetExp(&check, 2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_8) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal_SetSign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(div_9) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal_SetExp(&value_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1000u, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(short_div) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 65536;
  dec2.bits[0] = 2;
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 32768;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 9;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 6;
  dec2.bits[3] = 65536;
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 15;
  true_ans.bits[3] = 65536;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div_2) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 14;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 9;
  dec2.bits[3] = 65536;
  // 14/9 = 1.5555555555 5555555555 55555556
  // 00110010 01000011 01000001 00000100
  // 01100000 10101011 01011001 00001000
  // 11000011 10001110 00111000 11100100
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 3280877796;
  true_ans.bits[1] = 1621842184;
  true_ans.bits[2] = 843268356;
  true_ans.bits[3] = 1835008;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div_3) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 14;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 9;
  dec2.bits[3] = 65536 + 2147483648;
  // 14/(-9) = -1.5555555555 5555555555 55555556
  // 00110010 01000011 01000001 00000100
  // 01100000 10101011 01011001 00001000
  // 11000011 10001110 00111000 11100100
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 3280877796;
  true_ans.bits[1] = 1621842184;
  true_ans.bits[2] = 843268356;
  true_ans.bits[3] = 1835008 + 2147483648;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(div_by_zero) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 2814903;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 0;
  dec2.bits[3] = 65536 + 2147483648;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 3;  // не надо делить на ноль
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(div_zero) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 0;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 4578783;
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 0;
  true_ans.bits[1] = 0;
  true_ans.bits[2] = 0;
  true_ans.bits[3] = 0;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(result_too_big) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 4294967294;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 1;
  dec2.bits[3] = 1179648;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = 1;
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(result_too_small) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec2.bits[0] = 4294967294;
  dec2.bits[1] = 4294967295;
  dec2.bits[2] = 4294967295;
  dec1.bits[0] = 1;
  dec1.bits[3] = 1179648;
  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec1.bits[3] = 1179648;
  dec2.bits[0] = 1;
  dec2.bits[3] = 1179648;

  int status = s21_div(dec1, dec2, &ans);
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 4294967295;
  true_ans.bits[1] = 4294967295;
  true_ans.bits[2] = 4294967295;
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_2) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 4294967295;
  dec2.bits[1] = 4294967295;
  dec2.bits[2] = 4294967295;

  int status = s21_div(dec1, dec2, &ans);
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 1;
  true_ans.bits[1] = 0;
  true_ans.bits[2] = 0;
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_3) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  s21_decimal_FillWithZeros(&ans);
  // -278576982813512.8359044835908 / 7123984713482.41253 =
  // -39.104096094745301845239149102

  // -278576982813512.8359044835908
  // 00001001 00000000 01010101 10110100
  // 11111100 01000101 01100100 00011110
  // 01110111 00000010 11101010 01000100
  // 10000000 00001101 00000000 00000000
  dec1.bits[0] = 1996679748;
  dec1.bits[1] = 4232406046;
  dec1.bits[2] = 151016884;
  dec1.bits[3] = 2148335616;

  // 7123984713482.41253
  // 00000000 00000000 00000000 00000000
  // 00001001 11100010 11110010 10100010
  // 10011111 00111110 01000011 01100101
  // 00000000 00000101 00000000 00000000
  dec2.bits[0] = 2671657829;
  dec2.bits[1] = 165868194;
  dec2.bits[2] = 0;
  dec2.bits[3] = 327680;

  // -39.104096094745301845239149102
  // 01111110 01011010 00100110 01110000
  // 11110011 01000010 11100010 00010000
  // 00001010 10100100 00110010 00101110
  // 10000000 00011011 00000000 00000000
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 178532910;
  true_ans.bits[1] = 4081246736;
  true_ans.bits[2] = 2119837296;
  true_ans.bits[3] = 2149253120;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}

START_TEST(big_values_div_4) {
  s21_decimal dec1;
  s21_decimal dec2;
  s21_decimal ans;
  s21_decimal_FillWithZeros(&dec1);
  s21_decimal_FillWithZeros(&dec2);
  s21_decimal_FillWithZeros(&ans);
  // 7813912341.293481290382 / 1236128761234.217489792347 =
  // 0.0063212770273961190138049477

  // 7813912341.293481290382
  // 00000000 00000000 00000001 10100111
  // 10010111 11010001 01000010 10000110
  // 01000110 11010011 01101010 10001110
  // 00000000 00001100 00000000 00000000
  dec1.bits[0] = 1188260494;
  dec1.bits[1] = 2547073670;
  dec1.bits[2] = 423;
  dec1.bits[3] = 786432;

  // 1236128761234.217489792347
  // 00000000 00000001 00000101 11000010
  // 10101100 10100110 11001011 10100111
  // 01100010 11011001 11111101 01011011
  // 00000000 00001100 00000000 00000000
  dec2.bits[0] = 1658453339;
  dec2.bits[1] = 2896612263;
  dec2.bits[2] = 67010;
  dec2.bits[3] = 786432;

  // 0.0063212770273961190138049477
  // 00000000 00110100 01001001 11010011
  // 00100100 10011011 00101100 11110100
  // 10110010 10110011 11110011 11000101
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans;
  s21_decimal_FillWithZeros(&true_ans);
  true_ans.bits[0] = 2998137797;
  true_ans.bits[1] = 614149364;
  true_ans.bits[2] = 3426771;
  true_ans.bits[3] = 1835008;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}

START_TEST(simple_zero_test_1) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(hard_zero_test_1) {
  s21_decimal value_1 = {{5, 0, 0, 0x80000000 | 16 << 16}};
  s21_decimal value_2 = {
      {0b00100101000000100101101011110000, 0b100011101110, 0, 0}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(div_full_test_1) {
  s21_decimal value_1 = {{1, 1, 1, 655360}};
  s21_decimal value_2 = {{1, 1, 1, 655360}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{1, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(div_full_test_2) {
  s21_decimal value_1 = {{1, 1, 1, 655360}};
  s21_decimal value_2 = {{1, 1, 1, 983040}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{100000, 0, 0, 0}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(div_full_test_3) {
  s21_decimal value_1 = {{1, 1, 1, 655360}};
  s21_decimal value_2 = {{1, 10, 1, -2146500608}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {
      {0b00111100110000010111011101001000, 0b00011011010101101100000100011100,
       0b100000010011111100111001011101, 0x80000000 | 23 << 16}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

START_TEST(div_full_test_4) {
  s21_decimal value_1 = {{1, 1, 1, 983040}};
  s21_decimal value_2 = {{1, 1, 1, -2146500608}};
  s21_decimal result;
  int res = s21_div(value_1, value_2, &result);

  s21_decimal must = {{1, 0, 0, 0x80000000}};
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], must.bits[0]);
  ck_assert_int_eq(result.bits[1], must.bits[1]);
  ck_assert_int_eq(result.bits[2], must.bits[2]);
  ck_assert_int_eq(result.bits[3], must.bits[3]);
}
END_TEST

Suite* test_div_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("div_test");
  /* Core test case */
  tc = tcase_create("div_tc");

  // div
  tcase_add_test(tc, simple_div_test_1);
  tcase_add_test(tc, simple_div_test_2);
  tcase_add_test(tc, simple_div_test_3);
  tcase_add_test(tc, simple_div_test_4);
  tcase_add_test(tc, simple_div_test_5);
  tcase_add_test(tc, simple_div_test_6);
  tcase_add_test(tc, simple_div_test_7);
  tcase_add_test(tc, simple_div_test_8);
  tcase_add_test(tc, simple_div_test_9);

  tcase_add_test(tc, div_0);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);

  tcase_add_test(tc, short_div);
  tcase_add_test(tc, basic_div);
  tcase_add_test(tc, basic_div_2);
  tcase_add_test(tc, basic_div_3);
  tcase_add_test(tc, div_by_zero);
  tcase_add_test(tc, div_zero);
  tcase_add_test(tc, result_too_small);
  tcase_add_test(tc, result_too_big);
  tcase_add_test(tc, big_values_div);
  tcase_add_test(tc, big_values_div_2);
  tcase_add_test(tc, big_values_div_3);
  tcase_add_test(tc, big_values_div_4);
  tcase_add_test(tc, simple_zero_test_1);
  tcase_add_test(tc, hard_zero_test_1);

  tcase_add_test(tc, div_full_test_1);
  tcase_add_test(tc, div_full_test_2);
  tcase_add_test(tc, div_full_test_3);
  tcase_add_test(tc, div_full_test_4);

  suite_add_tcase(s, tc);

  return s;
}
