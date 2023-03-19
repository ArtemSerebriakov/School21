#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = NULL;
  if (!trim_chars && src) {
    res = (char *)malloc((s21_strlen(src) + 1) * sizeof(char));
    for (size_t i = 0; i < s21_strlen(src); i++) {
      res[i] = src[i];
    }
    res[s21_strlen(src)] = '\0';
  } else {
    if (src && trim_chars) {
      char *ptr_str = (char *)src;
      char *end_str = (char *)src + s21_strlen(src);
      for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++) {
      }
      for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
           end_str--) {
      }
      res = (char *)malloc((end_str - ptr_str + 1) * sizeof(char));
      if (res) {
        s21_strncpy(res, ptr_str, end_str - ptr_str);
        *(res + (end_str - ptr_str)) = '\0';
      }
    }
  }
  return res;
}
