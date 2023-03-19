#include "s21_math.h"

long double s21_floor(double x) {
  long double result = 0;
  if (x != x) {
    result = S21_NAN;
  } else if (!finite(x) || s21_fabs(x) > LLONG_MAX) {
    if (x < 0) {
      result = -S21_INF;
    } else {
      result = S21_INF;
    }
  } else {
    result = (long long int)x;
    if ((s21_fabs(x - result) > 0.) && s21_fabs(x) > 0.) {
      if (x < 0.) {
        result -= 1;
      }
    }
  }
  return result;
}