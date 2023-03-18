#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct inform {
  int b_flag, n_flag, s_flag, E_flag, T_flag, v_flag, count_files;
  char **files;
} info;

void init_info(info *inf);
int flag_check(char *s);
void parse_flags(int argc, char *argv[], info *inf);
void res_print(info *inf);
void delete_info(info *inf);

#endif  // SRC_CAT_S21_CAT_H_
