#include <math.h>

#include "s21_math.h"

long double s21_cos(double x) {
  long double cos = 1;
  if ((x == S21_INF) || (x == -S21_INF) || (x == S21_NAN)) {
    cos = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    int i = 1;
    long double res = 1;
    while ((res > S21_EPS) || (res < -S21_EPS)) {
      res = (-res) * (x * x) / ((2 * i - 1) * (2 * i));
      cos += res;
      i++;
    }
  }
  return cos;
}