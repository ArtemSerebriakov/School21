#include "s21_string.h"

void* s21_to_upper(const char* str) {
  char* res = NULL;
  if (str) {
    res = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
    if (res != NULL) {
      s21_strcpy(res, str);
      for (char* tmp_str = res; *tmp_str; tmp_str++) {
        if (*tmp_str >= 'a' && *tmp_str <= 'z') {
          *tmp_str -= 32;
        }
      }
    }
  }
  return res;
}
