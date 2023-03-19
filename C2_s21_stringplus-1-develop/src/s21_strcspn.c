#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t f = 0;
  s21_size_t i = 0;
  for (; str1[i] != '\0'; i++) {
    f = 0;
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        f = 1;
      }
    }
    if (f == 1) {
      break;
    }
  }
  return i;
}
