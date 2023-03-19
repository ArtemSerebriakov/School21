#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *res = s21_NULL;
  const char *copy_str2 = s21_NULL;
  copy_str2 = str2;
  int flag = 1;
  if (str1 != s21_NULL && str2 != s21_NULL)
    while (*str1 && flag) {
      while (*str2 && flag)
        if (*str1 == *str2 && flag) {
          res = str1;
          flag = 0;
        } else {
          str2++;
        }
      str2 = copy_str2;
      str1++;
    }
  return (char *)res;
}
