#include "s21_math.h"

long double s21_exp(double x) {
  long int i = 1;
  long double result = 1.0;
  long double term = 1.0;
  long double y = x;
  if (x != x) {
    result = S21_NAN;
  } else if (!finite(x)) {
    if (x < 0) {
      result = 0.0;
    } else {
      result = x;
    }
  } else if (x >= 709.8) {
    result = S21_INF;
  } else if (x < -20.) {
    result = 0.;
  } else {
    do {
      term *= y / (1.0 * i);
      result += term;
      i++;
    } while (s21_fabs(term) > S21_EPS);
  }
  return result;
}