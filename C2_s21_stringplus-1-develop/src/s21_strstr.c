#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *copy_haystack = s21_NULL;
  const char *copy_needle = s21_NULL;
  const char *res = s21_NULL;
  int flag = 0;
  if (haystack != s21_NULL && needle != s21_NULL) {
    if (*needle == '\0')
      res = haystack;
    else
      while (*haystack) {
        if (*haystack == *needle && !flag) {
          flag = 1;
          copy_haystack = haystack;
          copy_needle = needle;
          while (*copy_haystack && *copy_needle) {
            if (*copy_haystack == *copy_needle && flag) {
              flag = 1;
            } else {
              flag = 0;
            }
            copy_haystack++;
            copy_needle++;
          }
          if (s21_strlen(copy_haystack) == 0 && s21_strlen(copy_needle) != 0)
            flag = 0;
          if (flag) res = haystack;
        }
        haystack++;
      }
  }
  return (char *)res;
}
