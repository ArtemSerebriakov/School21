#include <stdio.h>
#include <stdlib.h>

#include "s21_cat.h"

int main(int argc, char *argv[]) {
  info inf;
  if (argc > 1) {
    init_info(&inf);
    parse_flags(argc, argv, &inf);
    res_print(&inf);
    delete_info(&inf);
  }
  return 0;
}