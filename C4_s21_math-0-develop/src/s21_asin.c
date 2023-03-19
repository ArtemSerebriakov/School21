#include "s21_math.h"

long double s21_asin(double x) {
  long double term = x;
  long double res = S21_NAN;
  if (-1.0 < x && x < 1.0) {
    res = term;
    x *= x;
    for (int k = 1; s21_fabs(term) > S21_EPS; k += 2)
      res += (term *= x * k / (k + 1)) / (k + 2);
  } else if (x == 1.0) {
    res = S21_PI / 2.0;
  } else if (x == -1.0) {
    res = -S21_PI / 2.0;
  }
  return res;
}
