#include "s21_math.h"

long double s21_pow(double b, double x) {
  long double fin;
  double ost;
  long int whole;
  whole = (int)x;
  ost = x - whole;
  fin = 2.;
  if (b != b || x != x) {
    fin = S21_NAN;
  }
  if (b == -0. && x < 0. && ost == 0 && whole % 2 != 0) {
    fin = S21_NEG_INF;
  }
  if (b == +0. && x < 0. && ost == 0 && whole % 2 != 0) {
    fin = S21_INF;
  }
  if ((b == -0. || b == +0.) && x < 0. && !(ost == 0 && whole % 2 != 0)) {
    fin = S21_NEG_INF;
  }
  if (b == -0. && x > 0. && ost == 0 && whole % 2 != 0) {
    fin = -0.;
  }
  if (b == +0. && x > 0. && ost == 0 && whole % 2 != 0) {
    fin = +0.;
  }
  if ((b == -0. || b == +0.) && x > 0. && !(ost == 0 && whole % 2 != 0)) {
    fin = +0.;
  }
  if (b == -1. && (x == S21_NEG_INF || x == S21_INF)) {
    fin = 1.;
  }
  if (b == 1.) {
    fin = 1.;
  }
  if ((x == -0. || x == +0.)) {
    fin = 1.;
  }
  if (!(b == S21_NEG_INF || b == S21_INF) &&
      !(x == S21_NEG_INF || x == S21_INF) && b < 0. && ost != 0) {
    fin = S21_NAN;
  }
  if (s21_fabs(b) < 1. && x == S21_NEG_INF) {
    fin = S21_INF;
  }
  if (s21_fabs(b) > 1. && x == S21_NEG_INF) {
    fin = +0.;
  }
  if (s21_fabs(b) < 1. && x == S21_INF) {
    fin = +0.;
  }
  if (s21_fabs(b) > 1. && x == S21_INF) {
    fin = S21_INF;
  }
  if (b == S21_NEG_INF && x < 0. && ost == 0 && whole % 2 != 0) {
    fin = -0.;
  }
  if (b == S21_NEG_INF && x < 0. && !(ost == 0 && whole % 2 != 0)) {
    fin = +0.;
  }
  if (b == S21_NEG_INF && x > 0. && ost == 0 && whole % 2 != 0) {
    fin = S21_NEG_INF;
  }
  if (b == S21_NEG_INF && x > 0. && !(ost == 0 && whole % 2 != 0)) {
    fin = S21_INF;
  }
  if (b == S21_INF && x < 0.) {
    fin = +0.;
  }
  if (b == S21_INF && x > 0.) {
    fin = S21_INF;
  }
  // the exact function
  if (fin == 2.) {
    fin = b;
    if (x > 0) {
      if (ost == 0) {
        while (x != 1) {
          fin *= b;
          x -= 1;
        }
      } else {
        while (x > ost + 1) {
          fin *= b;
          x -= 1;
        }
        x -= 1;
        fin *= s21_exp(x * s21_log(b));
      }
    } else if (x < 0) {
      if (ost == 0) {
        while (x != -1) {
          fin *= b;
          x += 1;
        }
        fin = 1.0 / fin;
      } else {
        while (x < ost - 1) {
          fin *= b;
          x += 1;
        }
        x += 1;
        x *= -1;
        fin *= s21_exp(x * s21_log(b));
        fin = 1.0 / fin;
      }
    }
  }
  return fin;
}