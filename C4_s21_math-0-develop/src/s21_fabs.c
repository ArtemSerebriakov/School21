#include "s21_math.h"

long double s21_fabs(double x) {
  long double result;
  if (x != x) {
    result = S21_NAN;
  } else if (!finite(x)) {
    if (x >= 0.) {
      result = x;
    } else {
      result = -x;
    }
  } else {
    if (x >= 0.) {
      result = x;
    } else {
      result = -x;
    }
  }
  return result;
}
