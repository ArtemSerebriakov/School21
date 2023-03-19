#include <math.h>

#include "s21_math.h"

long double s21_sin(double x) {
  long double sin = x;
  if ((x == S21_INF) || (x == -S21_INF) || (x == S21_NAN)) {
    sin = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    int i = 1;
    long double res = x;
    sin = x;
    while ((res > S21_EPS) || (res < -S21_EPS)) {
      res = (-res) * (x * x) / ((2 * i + 1) * (2 * i));
      sin += res;
      i++;
    }
  }
  return sin;
}