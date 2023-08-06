#include "polish.h"
int change_string(const char *string, char *res, int len) {
  int new_len = 0;
  for (int i = 0; i < len; i++) {
    if (string[i] == 'c' && string[i + 1] == 'o' && string[i + 2] == 's') {
      res[new_len] = 'c';
      i += 2;
    } else if (string[i] == 's' && string[i + 1] == 'i' &&
               string[i + 2] == 'n') {
      res[new_len] = 's';
      i += 2;
    } else if (string[i] == 't' && string[i + 1] == 'a' &&
               string[i + 2] == 'n') {
      res[new_len] = 't';
      i += 2;
    } else if (string[i] == 'c' && string[i + 1] == 't' &&
               string[i + 2] == 'g') {
      res[new_len] = 'g';
      i += 2;
    } else if (string[i] == 'l' && string[i + 1] == 'o' &&
               string[i + 2] == 'g') {
      res[new_len] = 'L';
      i += 2;
    } else if (string[i] == 's' && string[i + 1] == 'q' &&
               string[i + 2] == 'r' && string[i + 3] == 't') {
      res[new_len] = 'q';
      i += 3;
    } else if (string[i] == 'l' && string[i + 1] == 'n') {
      res[new_len] = 'l';
      i++;
    } else if (string[i] == 'a' && string[i + 1] == 's' &&
               string[i + 2] == 'i' && string[i + 3] == 'n') {
      res[new_len] = 'S';
      i += 3;
    } else if (string[i] == 'a' && string[i + 1] == 'c' &&
               string[i + 2] == 'o' && string[i + 3] == 's') {
      res[new_len] = 'C';
      i += 3;
    } else if (string[i] == 'a' && string[i + 1] == 't' &&
               string[i + 2] == 'a' && string[i + 3] == 'n') {
      res[new_len] = 'T';
      i += 3;
    } else if (i == 0 && (string[i] == '-')) {
      res[new_len] = '~';
    } else if (i == 0 && (string[i] == '+')) {
      res[new_len] = 'p';
    } else if (string[i] == '(' &&
               (string[i + 1] == '-' || string[i + 1] == '+')) {
      res[new_len] = '(';
      res[new_len + 1] = '~';
      if (string[i + 1] == '+') res[new_len + 1] = 'p';
      new_len += 2;
      i++;
      continue;
    } else if (strchr("+-%^/*x()0123456789.", string[i])) {
      res[new_len] = string[i];
    }
    new_len++;
  }
  int brackets = check_bracket(res);
  return (brackets) ? -1 : new_len;
}

int check_bracket(const char *res) {
  int count = 0;
  for (int i = 0; res[i]; i++) {
    if (res[i] == '(') {
      count++;
    } else if (res[i] == ')')
      count--;
  }
  return count;
}
/*
int check_validate(const char *res, int new_len) {
    // printf("len: %d ",new_len);
    const char oper[11] = {'+', '-', '*', '/', '~', 's', 'c', 't', 'g', 'q',
'l'};  // sin cos tan ctg sqrt ln int flag = 0; for (int i = 0; i < new_len;
i++) {
        // printf("\n!%c!",res[i]);
        // if (flag) break;
        for (int j = 0; j < 11; j++) {
            // printf("?%c?",oper[j]);
            if (res[i] != oper[j]) {
                flag = 1;
            } else {
                break;
            }
        }
    }
    // printf("len: %d ",flag);
    return flag;
}
 */