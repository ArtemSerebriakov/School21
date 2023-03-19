#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  size_t i = 0;
  if (n != 0) {
    if (n > s21_strlen(src)) {
      for (; src[i] != '\0'; i++) dest[i] = src[i];
      for (size_t j = i; j < n; j++) dest[j] = '\0';
    }
    if (n <= s21_strlen(src)) {
      for (; i < n; i++) dest[i] = src[i];
    }
  }
  return dest;
}
