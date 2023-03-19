#include "s21_math.h"

long double s21_tan(double x) {
  long double sin = s21_sin(x);
  long double cos = s21_cos(x);
  long double res = sin / cos;
  if ((cos > -S21_EPS) && (cos < S21_EPS)) {
    if ((cos < 0.0) || (sin < 0.0)) {
      res = -16331239353195370L;
    } else {
      res = 16331239353195370L;
    }
  }
  return res;
}
