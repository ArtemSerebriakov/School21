#include "s21_math.h"

long double s21_fmax(double num_1, double num_2);

long double s21_sqrt(double x) {
  long double mid;
  if (is_nan(x)) {
    mid = S21_NAN;
  }
  long double left = 0;
  long double right = s21_fmax(1, x);
  mid = (left + right) / 2;
  if (x < 0) {
    mid = S21_NAN;
  } else {
    while ((mid - left) > S21_EPS) {
      if (mid * mid > x)
        right = mid;
      else
        left = mid;
      mid = (left + right) / 2;
    }
  }
  return mid;
}

long double s21_fmax(double num_1, double num_2) {
  long double res = 1;
  if (num_1 >= num_2) {
    res = num_1;
  } else {
    res = num_2;
  }
  return res;
}
