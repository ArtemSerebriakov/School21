#include "s21_cat.h"

void init_info(info *inf) {
  inf->b_flag = 0;
  inf->n_flag = 0;
  inf->s_flag = 0;
  inf->E_flag = 0;
  inf->T_flag = 0;
  inf->v_flag = 0;
  inf->files = NULL;
  inf->count_files = 0;
}

int flag_check(char *s) {
  return (!strcmp(s, "-b")) || (!strcmp(s, "-n")) ||
         (!strcmp(s, "--number-nonblank")) || (!strcmp(s, "--number")) ||
         (!strcmp(s, "-s")) || (!strcmp(s, "-e")) || (!strcmp(s, "-E")) ||
         (!strcmp(s, "-T")) || (!strcmp(s, "-t")) || (!strcmp(s, "-v")) ||
         (!strcmp(s, "--squeeze-blank"));
}

void parse_flags(int argc, char *argv[], info *inf) {
  for (int i = 1; i < argc; i++) {
    if ((!strcmp(argv[i], "-b")) || (!strcmp(argv[i], "--number-nonblank"))) {
      inf->b_flag = 1;
    } else if (((!strcmp(argv[i], "-n")) || (!strcmp(argv[i], "--number")))) {
      inf->n_flag = 1;
    } else if ((!strcmp(argv[i], "-s")) ||
               (!strcmp(argv[i], "--squeeze-blank"))) {
      inf->s_flag = 1;
    } else if (!strcmp(argv[i], "-e")) {
      inf->E_flag = 1;
      inf->v_flag = 1;
    } else if (!strcmp(argv[i], "-E")) {
      inf->E_flag = 1;
    } else if (!strcmp(argv[i], "-t")) {
      inf->T_flag = 1;
      inf->v_flag = 1;
    } else if (!strcmp(argv[i], "-T")) {
      inf->T_flag = 1;
    } else if (!strcmp(argv[i], "-v")) {
      inf->v_flag = 1;
    } else {
      inf->count_files++;
    }
  }
  inf->files = malloc(sizeof(char *) * inf->count_files);
  inf->count_files = 0;
  for (int j = 1; j < argc; j++) {
    if (!flag_check(argv[j])) {
      inf->files[inf->count_files] =
          malloc(sizeof(char) * (strlen(argv[j]) + 1));
      strcpy(inf->files[inf->count_files], argv[j]);
      inf->count_files++;
    }
  }
  if ((inf->n_flag == 1) && (inf->b_flag == 1)) {
    inf->n_flag = 0;
  }
}

void res_print(info *inf) {
  for (int i = 0; i < inf->count_files; i++) {
    int line_count = 1;
    FILE *file = fopen(inf->files[i], "r");
    if (file == NULL) {
      fprintf(stderr, "s21_cat: %s: No such file or directory\n",
              inf->files[i]);
      continue;
    }
    char old_char = '\n';  //текущий символ первый на строке
    int empty_str = 0;
    char ch = 0;
    while ((ch = fgetc(file)) != EOF) {
      if ((inf->s_flag) && (old_char == '\n')) {
        if (ch == '\n') {
          empty_str++;
          if (empty_str > 1) continue;
        }
      } else {
        empty_str = 0;
      }

      if ((inf->n_flag) && (old_char == '\n')) {
        printf("%6d\t", line_count);
        line_count++;
      }

      if ((inf->b_flag) && (old_char == '\n')) {
        if (ch != '\n') {
          printf("%6d\t", line_count);
          line_count++;
        }
      }

      if ((inf->E_flag) && (ch == '\n')) {
        printf("$");
      }

      if ((inf->T_flag) && (ch == '\t')) {
        ch = 'I';
        printf("^");
      }

      if (inf->v_flag) {
        if ((ch < 32) && (ch != 10) && (ch != 9)) {
          printf("^");
          ch += 64;
        } else if (ch == 127) {
          printf("^");
          ch = '?';
        }
      }
      if (ch != '\0') {
        old_char = ch;
      } else {
        old_char = '\0';
      }
      printf("%c", ch);
    }
    fclose(file);
  }
}

void delete_info(info *inf) {
  for (int i = 0; i < inf->count_files; i++) {
    free(inf->files[i]);
  }
  free(inf->files);
}