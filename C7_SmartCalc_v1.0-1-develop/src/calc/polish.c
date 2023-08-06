#include "polish.h"

double s21_calculate(char* str, double x) {
  struct polish polish_struct[200];

  for (int i = 0; i < 200; i++) {
    polish_struct[i].value = 0;
    polish_struct[i].operation = '\0';
  }

  int len_pol = polish_convert(str, polish_struct);

  return polish_calc(x, polish_struct, len_pol);
}

double polish_calc(double x, struct polish* polish_struct, int lenght) {
  struct polish_stack* polish_stack = NULL;
  int err = 0;

  double result = NAN;
  for (int i = 0; i < lenght; i++) {
    if ((polish_struct[i].operation == '\0') ||
        (polish_struct[i].operation == 'x')) {
      double temp = 0.0;
      if (polish_struct[i].operation == 'x') {
        temp = x;
      } else {
        temp = polish_struct[i].value;
      }
      if (polish_stack == NULL) {
        polish_stack = init_p(temp);
      } else {
        polish_stack = push_p(&polish_stack, temp);
      }

    } else {
      if (strchr("+-*/%^", polish_struct[i].operation))
        if (polish_stack != NULL && polish_stack->next != NULL) {
          double a = pop_p(&polish_stack);
          double b = pop_p(&polish_stack);
          switch (polish_struct[i].operation) {
            case '+':
              polish_stack = push_p(&polish_stack, a + b);
              break;
            case '-':
              polish_stack = push_p(&polish_stack, b - a);
              break;
            case '*':
              polish_stack = push_p(&polish_stack, a * b);
              break;
            case '/':
              polish_stack = push_p(&polish_stack, b / a);
              break;
            case '%':
              polish_stack = push_p(&polish_stack, fmod(b, a));
              break;
            case '^':
              polish_stack = push_p(&polish_stack, pow(b, a));
              break;
          }
        } else
          err = 1;
      else if (strchr("sctgCSTqlL~p", polish_struct[i].operation)) {
        if (polish_stack != NULL) {
          double a = pop_p(&polish_stack);
          switch (polish_struct[i].operation) {
            case 's':
              polish_stack = push_p(&polish_stack, sin(a));
              break;
            case 'c':
              polish_stack = push_p(&polish_stack, cos(a));
              break;
            case 't':
              polish_stack = push_p(&polish_stack, tan(a));
              break;
            case 'g':
              polish_stack = push_p(&polish_stack, 1.0 / (tan(a)));
              break;

            case 'C':
              polish_stack = push_p(&polish_stack, (acos(a)));
              break;
            case 'S':
              polish_stack = push_p(&polish_stack, (asin(a)));
              break;
            case 'T':
              polish_stack = push_p(&polish_stack, (atan(a)));
              break;
            case 'q':
              polish_stack = push_p(&polish_stack, sqrt(a));
              break;
            case 'l':
              polish_stack = push_p(&polish_stack, log(a));
              break;
            case 'L':
              polish_stack = push_p(&polish_stack, log10(a));
              break;
            case '~':
              polish_stack = push_p(&polish_stack, 0.0 - (a));
              break;
            case 'p':
              polish_stack = push_p(&polish_stack, (a));
              break;
          }
        } else
          err = 1;
      }
    }
  }
  if (!err) {
    if ((polish_stack != NULL))
      if (polish_stack->next == NULL) {
        { result = polish_stack->value; }
      }
  } else
    result = NAN;
  destroy_p(polish_stack);
  return result;
}

int polish_convert(char* input, struct polish* polish_struct) {
  char* operations = "-+*/%^(sctgql~pSCTL";

  struct stack* head = init('y');
  int l = 0;
  for (int i = 0; input[i]; i++) {
    int cont = 0;

    if (input[i] &&
        (((input[i] >= '0') && (input[i] <= '9')) || input[i] == '.')) {
      double temp = 0.0;
      if (sscanf(&input[i], "%lf", &temp))
        polish_struct[l].value = temp;
      else
        printf("Error scanf\n");
      l++;
      while (input[i + 1] &&
             (((input[i + 1] >= '0') && (input[i + 1] <= '9')) ||
              input[i + 1] == '.'))
        i++;
      continue;
    }

    if (input[i] == 'x') {
      polish_struct[l].operation = input[i];
      l++;
      continue;
    }

    if (input[i] == '(') {
      head = push(head, input[i]);
      continue;
    }

    for (int k = 0; operations[k]; k++) {
      if (input[i] == operations[k]) {
        while ((head->data != 'y') && (head->priority > 0) &&
               ((get_proirity(input[i]) <= head->priority)) &&
               (head->data != '(')) {
          polish_struct[l].operation = pop(&head);
          l++;
        }

        if (get_proirity(input[i]) > head->priority) {
          head = push(head, input[i]);
          head->priority = get_proirity(head->data);
        }
        cont = 1;
        break;
      }
    }
    if (cont == 1) {
      continue;
    }

    if (input[i] == ')') {
      while (head->data != '(') {
        polish_struct[l].operation = pop(&head);
        l++;
      }
      pop(&head);
    }
  }
  while (head->data != 'y') {
    polish_struct[l].operation = pop(&head);
    l++;
  }

  destroy(head);
  return l;
}

int get_proirity(char operation) {
  int priority = -1;
  switch (operation) {
    case '+':
    case '-':
      priority = 1;
      break;
    case '*':
    case '/':
    case '%':
      priority = 2;
      break;
    case '^':
      priority = 3;
      break;
    case 's':
    case 'c':
    case 't':
    case 'g':
    case 'q':
    case 'l':
    case 'L':
    case 'C':
    case 'T':
    case 'S':

      priority = 4;
      break;
    case '~':
    case 'p':
      priority = 3;
      break;
  }

  return priority;
}

double pop_p(struct polish_stack** tail) {
  double value = 0.0;
  if ((*tail != NULL)) {
    value = (*tail)->value;
    struct polish_stack* free_tail = *tail;

    // if (new_tail->next != NULL){
    *tail = (*tail)->next;
    free(free_tail);  //}
                      // else {free(*tail);}

  }  // else{printf("NULL");}
  return value;
}

struct polish_stack* push_p(struct polish_stack** tail, double value) {
  struct polish_stack* new_tail = NULL;
  if ((*tail != NULL)) {
    new_tail = calloc(1, sizeof(struct polish_stack));
    new_tail->value = value;
    new_tail->next = *tail;

  } else
    new_tail = init_p(value);
  return new_tail;
}

struct polish_stack* init_p(double value) {
  struct polish_stack* tail = calloc(1, sizeof(struct polish_stack));
  tail->next = NULL;
  tail->value = value;
  return tail;
}

void destroy_p(struct polish_stack* tail) {
  while (tail != NULL) {
    struct polish_stack* node1 = tail;
    tail = node1->next;
    free(node1);
  }
}
