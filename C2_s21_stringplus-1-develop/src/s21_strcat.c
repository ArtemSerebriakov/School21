#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = 0;
  while (*(dest + i)) {
    i++;
  }
  while ((*(dest + i) = *src) != '\0') {
    i++;
    src++;
  }
  *(dest + i) = '\0';
  return (char *)dest;
}
