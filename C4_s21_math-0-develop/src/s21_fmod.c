#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int intNum = 0;
  long double result;
  if (x != x || y != y || (x == 0. && y == 0.) || s21_fabs(x) == S21_INF ||
      y == 0.) {
    result = S21_NAN;
  } else if (!finite(y)) {
    result = x;
  } else {
    intNum = x / y;
    result = x - intNum * y;
  }
  return result;
}