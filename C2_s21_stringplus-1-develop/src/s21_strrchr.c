#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int i = 0;
  const char *result = s21_NULL;
  while (str[i] != '\0') {
    if (str[i] == (char)c) result = str + i;
    i++;
  }
  if (c == '\0') result = str + i;
  return (char *)result;
}
