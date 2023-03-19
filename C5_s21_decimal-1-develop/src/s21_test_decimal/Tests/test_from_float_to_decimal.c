#include "test.h"

START_TEST(s21_from_float_to_dec_1) {
  s21_decimal val;
  s21_from_float_to_decimal(0.03F, &val);
  ck_assert_int_eq(val.bits[0], 3);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 131072);
}
END_TEST

START_TEST(s21_from_float_to_dec_2) {
  s21_decimal val;
  s21_from_float_to_decimal(22.14836E+03F, &val);
  ck_assert_int_eq(val.bits[0], 2214836);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 131072);
}
END_TEST

START_TEST(s21_from_float_to_dec_3) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09F, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_4) {
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_5) {
  s21_decimal val;
  float a = -1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_from_float_to_dec_6) {
  s21_decimal val;
  float a = NAN;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_7) {
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_8) {
  s21_decimal val;
  s21_from_float_to_decimal(127.1234F, &val);
  ck_assert_int_eq(val.bits[0], 1271234);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(s21_from_float_to_dec_9) {
  float inp = 1. / 0.;
  s21_decimal out;
  int error = s21_from_float_to_decimal(inp, &out);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(s21_from_float_to_dec_10) {
  float inp = 2;
  s21_decimal *out = NULL;
  int error = s21_from_float_to_decimal(inp, out);
  ck_assert_ptr_eq(out, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(s21_from_float_to_dec_11) {
  float inp = 2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_12) {
  float inp = -321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 0x80010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_13) {
  float inp = 321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_14) {
  float inp = 321213143.8323;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x13255310, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_15) {
  float inp = 73.329959999;
  s21_decimal out = {{3211, 123145, 231, 312441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x006FE484, 0, 0, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_16) {
  float inp = 0.003;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000003, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_17) {
  float inp = 0.00312345;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0004C419, 0, 0, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_18) {
  float inp = 0.00000003123959295945;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002FAAF7, 0, 0, 0x000E0000}};  // testi kaif
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_19) {
  float inp = 0.0000000000000000093929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x008F532A, 0, 0, 0x00180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_20) {  // check eto
  float inp = 0.00000000000000000000000000013929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000001, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_21) {  // check eto
  float inp = 0.00000000000000000000000000016929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_22) {
  float inp = .00000000000000000000000000000000193929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_from_float_to_dec_23) {
  float inp = 7015000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xC7000000, 0xFFD18396, 0x16AAAC07, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_24) {
  float inp = 0.00000000000000000000000005646473736464;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000235, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_25) {
  float inp = 0.00000000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_26) {
  float inp = 0.00000000000000000000000858598287381972;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000218A, 0, 0, 0x001B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_from_float_to_dec_27) {
  float inp = 0.000000000000000000000099999999999;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000001, 0, 0, 0x00160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_from_float_to_dec_28) {
  float inp = 0.00000000000000000000073766666662636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00708F1B, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_29) {
  float inp = 0.00000000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_30) {
  float inp = -1.307818E+07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_31) {
  float inp = -30914.76;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002F2C14, 0x00000000, 0x00000000, 0x80020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_32) {
  float inp = 1.965111E-26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000000C5, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_33) {
  float inp = 72932.2;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000B20EA, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_34) {
  float inp = -1.391184E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x9DB88000, 0x01EE3F72, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_35) {
  float inp = 3.693497E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00385BB9, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_36) {
  float inp = 351871.4;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0035B0FA, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_37) {
  float inp = 0.1175977;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0011F1A9, 0x00000000, 0x00000000, 0x00070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_38) {
  float inp = -2.013319E-14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001EB887, 0x00000000, 0x00000000, 0x80140000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_39) {
  float inp = -280.7036;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002AD4FC, 0x00000000, 0x00000000, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_40) {
  float inp = -3.196059E+18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x2030B000, 0x2C5AAEBA, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_41) {
  float inp = -1.38892E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x50527800, 0x00007E52, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_42) {
  float inp = 6.068951E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x69BCD7D8, 0x00000001, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_43) {
  float inp = -1.190043E+24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF98C0000, 0x5C3C75F5, 0x0000FC00, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_44) {
  float inp = 4.511203E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000002D, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_45) {
  float inp = -7.442655E+23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x1B360000, 0xB6AE8261, 0x00009D9A, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_46) {
  float inp = -5.447201E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_47) {
  float inp = 1.333345E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x6F8D0680, 0x00000C20, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_48) {
  float inp = -3.85058E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0005E022, 0x00000000, 0x00000000, 0x800B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_49) {
  float inp = 1.325723E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00143A9B, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_50) {
  float inp = -1.337444E-22;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00146864, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_51) {
  float inp = 1.230342E+28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xAD800000, 0xA66BA8BD, 0x27C12686, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_52) {
  float inp = 9.196544E-25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000023ED, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_53) {
  float inp = 2.922531E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x9AB80000, 0x3ACC2F60, 0x00182CB3, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_54) {
  float inp = 1.581408E+19;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x319C0000, 0xDB76E5F9, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_55) {
  float inp = -3.22218E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000020, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_56) {
  float inp = 1.290434E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0013B0C2, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_57) {
  float inp = -1.162378E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0011BC8A, 0x00000000, 0x00000000, 0x801A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_58) {
  float inp = -1.609435E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x78FAEAE0, 0x00000025, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_59) {
  float inp = -2.747507E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0029EC73, 0x00000000, 0x00000000, 0x800C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_60) {
  float inp = -2.233666E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_61) {
  float inp = -9.564972E-05;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0091F32C, 0x00000000, 0x00000000, 0x800B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_62) {
  float inp = 6.76729E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000A5379, 0x00000000, 0x00000000, 0x00100000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_63) {
  float inp = -1.56421E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0952CB88, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_64) {
  float inp = 1.248784E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00130E10, 0x00000000, 0x00000000, 0x00110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_65) {
  float inp = 3.830389E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000004, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_66) {
  float inp = -7.518575E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8BEBC180, 0x00004461, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_67) {
  float inp = 1.759471E+20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0821C000, 0x89C1AB3E, 0x00000009, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_68) {
  float inp = -1.730171E+16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x468E8C00, 0x003D77D0, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_69) {
  float inp = -0.005833615;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0059038F, 0x00000000, 0x00000000, 0x80090000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_70) {
  float inp = -1.083782E+27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x27C00000, 0xF1EDC3B6, 0x03807BC3, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_71) {
  float inp = -2.543952E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x3B22B200, 0x0000003B, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_72) {
  float inp = 8.122079E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE41D1718, 0x00000001, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_73) {
  float inp = -1.381688E-13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00151538, 0x00000000, 0x00000000, 0x80130000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_74) {
  float inp = 5.3419E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8890E000, 0x0769D2F9, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_75) {
  float inp = -1.899235E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xD8B80000, 0x5B459112, 0x000FB5C9, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_76) {
  float inp = 0.01434358;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0015E2F6, 0x00000000, 0x00000000, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_77) {
  float inp = -8.395913E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x320B2584, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_78) {
  float inp = 2.963941E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002D39E5, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_79) {
  float inp = -4.554593E-25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000011CB, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_80) {
  float inp = 1.511913E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001711E9, 0x00000000, 0x00000000, 0x001A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_81) {
  float inp = 12.18852;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00129924, 0x00000000, 0x00000000, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_82) {
  float inp = 49394.41;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x004B5EB1, 0x00000000, 0x00000000, 0x00020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_83) {
  float inp = 0.0002621874;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002801B2, 0x00000000, 0x00000000, 0x000A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_84) {
  float inp = 5.880856E+15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x7CDAF000, 0x0014E49B, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_85) {
  float inp = -7.048725E-24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00011357, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_86) {
  float inp = 1.661392E-16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001959D0, 0x00000000, 0x00000000, 0x00160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_87) {
  float inp = -1.078071E+10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x82949470, 0x00000002, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_88) {
  float inp = 3.478075E-10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0035123B, 0x00000000, 0x00000000, 0x00100000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_89) {
  float inp = -0.2220105;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0021E049, 0x00000000, 0x00000000, 0x80070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_90) {
  float inp = -4.057507E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003DE9A3, 0x00000000, 0x00000000, 0x80110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_91) {
  float inp = -7.703651E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x75D03380, 0x00004610, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_92) {
  float inp = 4.329224E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00420F08, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_93) {
  float inp = -3.238849E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00316BC1, 0x00000000, 0x00000000, 0x800C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_94) {
  float inp = -5.937755E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x005A9A5B, 0x00000000, 0x00000000, 0x80180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_95) {
  float inp = 9.214601E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x008C9A89, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_96) {
  float inp = -2.788572E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x80595C00, 0x0000FD9E, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_from_float_to_dec_97) {
  float inp = -0.2386963;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00246C13, 0x00000000, 0x00000000, 0x80070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_float_to_dec_suite(void) {
  Suite *s = suite_create("float_to_dec_test");
  TCase *tc = tcase_create("float_to_dec_tc");

  tcase_add_test(tc, s21_from_float_to_dec_1);
  tcase_add_test(tc, s21_from_float_to_dec_2);
  tcase_add_test(tc, s21_from_float_to_dec_3);
  tcase_add_test(tc, s21_from_float_to_dec_4);
  tcase_add_test(tc, s21_from_float_to_dec_5);
  tcase_add_test(tc, s21_from_float_to_dec_6);
  tcase_add_test(tc, s21_from_float_to_dec_7);
  tcase_add_test(tc, s21_from_float_to_dec_8);
  tcase_add_test(tc, s21_from_float_to_dec_9);
  tcase_add_test(tc, s21_from_float_to_dec_10);
  tcase_add_test(tc, s21_from_float_to_dec_11);
  tcase_add_test(tc, s21_from_float_to_dec_12);
  tcase_add_test(tc, s21_from_float_to_dec_13);
  tcase_add_test(tc, s21_from_float_to_dec_14);
  tcase_add_test(tc, s21_from_float_to_dec_15);
  tcase_add_test(tc, s21_from_float_to_dec_16);
  tcase_add_test(tc, s21_from_float_to_dec_17);
  tcase_add_test(tc, s21_from_float_to_dec_18);
  tcase_add_test(tc, s21_from_float_to_dec_19);
  tcase_add_test(tc, s21_from_float_to_dec_20);
  tcase_add_test(tc, s21_from_float_to_dec_21);
  tcase_add_test(tc, s21_from_float_to_dec_22);
  tcase_add_test(tc, s21_from_float_to_dec_23);
  tcase_add_test(tc, s21_from_float_to_dec_24);
  tcase_add_test(tc, s21_from_float_to_dec_25);
  tcase_add_test(tc, s21_from_float_to_dec_26);
  tcase_add_test(tc, s21_from_float_to_dec_27);
  tcase_add_test(tc, s21_from_float_to_dec_28);
  tcase_add_test(tc, s21_from_float_to_dec_29);
  tcase_add_test(tc, s21_from_float_to_dec_30);
  tcase_add_test(tc, s21_from_float_to_dec_31);
  tcase_add_test(tc, s21_from_float_to_dec_32);
  tcase_add_test(tc, s21_from_float_to_dec_33);
  tcase_add_test(tc, s21_from_float_to_dec_34);
  tcase_add_test(tc, s21_from_float_to_dec_35);
  tcase_add_test(tc, s21_from_float_to_dec_36);
  tcase_add_test(tc, s21_from_float_to_dec_37);
  tcase_add_test(tc, s21_from_float_to_dec_38);
  tcase_add_test(tc, s21_from_float_to_dec_39);
  tcase_add_test(tc, s21_from_float_to_dec_40);
  tcase_add_test(tc, s21_from_float_to_dec_41);
  tcase_add_test(tc, s21_from_float_to_dec_42);
  tcase_add_test(tc, s21_from_float_to_dec_43);
  tcase_add_test(tc, s21_from_float_to_dec_44);
  tcase_add_test(tc, s21_from_float_to_dec_45);
  tcase_add_test(tc, s21_from_float_to_dec_46);
  tcase_add_test(tc, s21_from_float_to_dec_47);
  tcase_add_test(tc, s21_from_float_to_dec_48);
  tcase_add_test(tc, s21_from_float_to_dec_49);
  tcase_add_test(tc, s21_from_float_to_dec_50);
  tcase_add_test(tc, s21_from_float_to_dec_51);
  tcase_add_test(tc, s21_from_float_to_dec_52);
  tcase_add_test(tc, s21_from_float_to_dec_53);
  tcase_add_test(tc, s21_from_float_to_dec_54);
  tcase_add_test(tc, s21_from_float_to_dec_55);
  tcase_add_test(tc, s21_from_float_to_dec_56);
  tcase_add_test(tc, s21_from_float_to_dec_57);
  tcase_add_test(tc, s21_from_float_to_dec_58);
  tcase_add_test(tc, s21_from_float_to_dec_59);
  tcase_add_test(tc, s21_from_float_to_dec_60);
  tcase_add_test(tc, s21_from_float_to_dec_61);
  tcase_add_test(tc, s21_from_float_to_dec_62);
  tcase_add_test(tc, s21_from_float_to_dec_63);
  tcase_add_test(tc, s21_from_float_to_dec_64);
  tcase_add_test(tc, s21_from_float_to_dec_65);
  tcase_add_test(tc, s21_from_float_to_dec_66);
  tcase_add_test(tc, s21_from_float_to_dec_67);
  tcase_add_test(tc, s21_from_float_to_dec_68);
  tcase_add_test(tc, s21_from_float_to_dec_69);
  tcase_add_test(tc, s21_from_float_to_dec_70);
  tcase_add_test(tc, s21_from_float_to_dec_71);
  tcase_add_test(tc, s21_from_float_to_dec_72);
  tcase_add_test(tc, s21_from_float_to_dec_73);
  tcase_add_test(tc, s21_from_float_to_dec_74);
  tcase_add_test(tc, s21_from_float_to_dec_75);
  tcase_add_test(tc, s21_from_float_to_dec_76);
  tcase_add_test(tc, s21_from_float_to_dec_77);
  tcase_add_test(tc, s21_from_float_to_dec_78);
  tcase_add_test(tc, s21_from_float_to_dec_79);
  tcase_add_test(tc, s21_from_float_to_dec_80);
  tcase_add_test(tc, s21_from_float_to_dec_81);
  tcase_add_test(tc, s21_from_float_to_dec_82);
  tcase_add_test(tc, s21_from_float_to_dec_83);
  tcase_add_test(tc, s21_from_float_to_dec_84);
  tcase_add_test(tc, s21_from_float_to_dec_85);
  tcase_add_test(tc, s21_from_float_to_dec_86);
  tcase_add_test(tc, s21_from_float_to_dec_87);
  tcase_add_test(tc, s21_from_float_to_dec_88);
  tcase_add_test(tc, s21_from_float_to_dec_89);
  tcase_add_test(tc, s21_from_float_to_dec_90);
  tcase_add_test(tc, s21_from_float_to_dec_91);
  tcase_add_test(tc, s21_from_float_to_dec_92);
  tcase_add_test(tc, s21_from_float_to_dec_93);
  tcase_add_test(tc, s21_from_float_to_dec_94);
  tcase_add_test(tc, s21_from_float_to_dec_95);
  tcase_add_test(tc, s21_from_float_to_dec_96);
  tcase_add_test(tc, s21_from_float_to_dec_97);

  suite_add_tcase(s, tc);

  return s;
}
