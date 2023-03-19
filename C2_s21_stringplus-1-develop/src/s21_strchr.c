#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *res = s21_NULL;
  while (*str) {
    if (*str == c && res == s21_NULL) {
      res = str;
    }
    if (c == '\0') {
      res = "";
    }
    str++;
  }
  return (char *)res;
}
