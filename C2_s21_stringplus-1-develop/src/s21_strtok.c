#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *p = s21_NULL;
  s21_size_t f = 0;
  if (str != s21_NULL) {
    p = str;
  }
  if (p != s21_NULL) {
    str = p + s21_strspn(p, delim);
    p = str + s21_strcspn(str, delim);
    if (p == str) {
      p = s21_NULL;
      f = 1;
    } else {
      if ((*p) == '\0') {
        p = s21_NULL;
      } else {
        (*p) = '\0';
        p += 1;
      }
    }
  }
  char *res = s21_NULL;
  if (f == 1) {
    res = p;
  } else {
    res = str;
  }
  return res;
}
