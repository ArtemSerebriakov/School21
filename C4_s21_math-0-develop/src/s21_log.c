#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  long double iteration = 0;
  if (x != x || x < 0.) {
    result = S21_NAN;
  } else if (!finite(x)) {
    result = S21_INF;
  } else if (x == 0) {
    result = -S21_INF;
  } else {
    for (int i = 0; i < 200; i++) {
      iteration = result;
      result =
          iteration + 2 * (x - s21_exp(iteration)) / (x + s21_exp(iteration));
    }
  }
  return result;
}