#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil = 0.0;
  if ((x == S21_INF) || (x == -S21_INF) || (x != x) || (x == DBL_MAX) ||
      (x == -DBL_MAX)) {
    ceil = x;
  } else {
    ceil = (long long int)x;
    if ((x > 0) && (x != ceil)) {
      ceil += 1;
    }
  }
  return ceil;
}
