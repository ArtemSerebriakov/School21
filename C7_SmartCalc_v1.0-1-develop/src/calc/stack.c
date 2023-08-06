#include "stack.h"

char pop(struct stack** tail) {
  char data = '\0';
  if ((*tail != NULL)) {
    struct stack* new_tail = *tail;
    data = new_tail->data;
    // if (new_tail->next != NULL){
    *tail = new_tail->next;
    free(new_tail);  //}
                     // else {free(*tail);}

  }  // else{printf("NULL");}
  return data;
}

struct stack* push(struct stack* tail, char data) {
  if ((tail != NULL)) {
    struct stack* new_tail = calloc(1, sizeof(struct stack));
    new_tail->data = data;
    new_tail->priority = -1;
    new_tail->next = tail;
    return new_tail;
  }
  return NULL;
}

struct stack* init(char data) {
  struct stack* tail = calloc(1, sizeof(struct stack));
  tail->next = NULL;
  tail->data = data;
  tail->priority = -1;
  return tail;
}

void destroy(struct stack* root) {
  while (root != NULL) {
    struct stack* node1 = root;
    root = node1->next;
    free(node1);
    node1 = NULL;
  }
}
