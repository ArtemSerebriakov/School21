#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stack {
  char data;
  int priority;
  double value;
  struct stack* next;
};
struct stack* init(char data);
struct stack* push(struct stack* tail, char data);
char pop(struct stack** tail);
void destroy(struct stack* tail);
void print_all(struct stack* tail);

#endif
