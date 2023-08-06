#ifndef S21_POLISH_H
#define S21_POLISH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#ifdef __cplusplus
extern "C" {
#endif

struct polish {
  double value;
  char operation;
};

struct polish_stack {
  double value;
  struct polish_stack* next;
};

int change_string(const char* string, char* res, int len);
int check_bracket(const char* res);
struct polish_stack* init_p(double value);
struct polish_stack* push_p(struct polish_stack** tail, double value);
double pop_p(struct polish_stack** tail);
void destroy_p(struct polish_stack* tail);
double s21_calculate(char* str, double x);
double polish_calc(double x, struct polish* polish_struct, int lenght);
int polish_convert(char* input, struct polish* polish_struct);
int get_proirity(char operation);

#ifdef __cplusplus
}
#endif

#endif
