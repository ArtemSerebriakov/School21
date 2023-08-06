#include "validator.h"

#include <stdio.h>

int validator(char *str) {
  char *func4[] = {
      "acos",
      "asin",
      "atan",
  };
  char *functions = "cstal";
  int res = 0;
  int scobs = 0;
  int i = 0;
  char *tmp = str;
  char *chars = "sincotaqrlg1234567890x()^*md /+-.%";
  int length = strlen(str);
  if (length == 0) {
    res = 2;
  } else {
    while (*tmp != '\0') {
      if (scobs < 0) {
        res = 1;
        break;
      }
      if (strchr(chars, *tmp) == NULL) {
        res = 1;
        break;
      } else if (strchr(functions, *tmp)) {
        if (i + 4 < length) {
          if (*tmp == 's' && *(tmp + 1) == 'i' && *(tmp + 2) == 'n') {
            tmp += 2;
            i += 2;
          } else if (*tmp == 's' && *(tmp + 1) == 'q' && *(tmp + 2) == 'r' &&
                     *(tmp + 3) == 't') {
            tmp += 3;
            i += 3;
          } else if (*tmp == 'c' && *(tmp + 1) == 'o' && *(tmp + 2) == 's') {
            tmp += 2;
            i += 2;
          } else if (*tmp == 't' && *(tmp + 1) == 'a' && *(tmp + 2) == 'n') {
            tmp += 2;
            i += 2;
          } else if (*tmp == 'l' && *(tmp + 1) == 'n') {
            tmp += 1;
            i += 1;
          } else if (*tmp == 'l' && *(tmp + 1) == 'o' && *(tmp + 2) == 'g') {
            tmp += 2;
            i += 2;
          } else if (strncmp(tmp, func4[0], 4) == 0) {
            tmp += 3;
            i += 3;
          } else if (strncmp(tmp, func4[1], 4) == 0) {
            tmp += 3;
            i += 3;
          } else if (strncmp(tmp, func4[2], 4) == 0) {
            tmp += 3;
            i += 3;
          } else {
            res = 1;
          }
        } else {
          res = 1;
        }
      } else if (*tmp == '(' || *tmp == ')') {
        if (*tmp == '(') {
          scobs += 1;
        } else {
          scobs -= 1;
        }
      } else {
        if (*tmp == '.') {
          if (i != 0) {
            if (((*(tmp - 1) <= 57 && *(tmp - 1) >= 48) &&
                 (*(tmp + 1) <= 57 && *(tmp + 1) >= 48))) {
              res = 0;
            } else {
              res = 1;
              break;
            }
          } else if (i == 0) {
            res = 1;
            break;
          }
        }
      }
      i++;
      tmp += 1;
    }
  }
  if (scobs != 0) {
    res = 1;
  }
  return res;
}
