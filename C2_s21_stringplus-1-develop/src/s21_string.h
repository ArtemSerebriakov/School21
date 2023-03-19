#ifndef S21_STRING_H_
#define S21_STRING_H_

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

s21_size_t s21_strlen(const char *str);  // particia
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);  // alysonsm
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);

void *s21_memchr(const void *str, int c, s21_size_t n);  // erenford
void *s21_insert(const char *src, const char *str, size_t start_index);
char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);

char *s21_strchr(const char *str, int c);  // lemonmin
char *s21_strncpy(char *dest, const char *src, size_t n);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcat(char *dest, const char *src);

char *s21_strrchr(const char *str, int c);  // hellylet
int s21_strcmp(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);

typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int accuracy_length;
  int accuracy;
  int length_h;
  int length_l;
  int specifier;
  int zero;
} struct_format;

int check_specificator(char *str, int *n, struct_format form, va_list arg);
void write_c(char *str, int *n, struct_format form, va_list arg);
void write_char(char *str, int *n, struct_format form, char arg);
void write_d(char *str, int *n, struct_format form, va_list arg);
void write_i(char *str, int *n, struct_format form, va_list arg);
void write_unsigned_i(char *str, int *n, struct_format form,
                      unsigned long long arg);
void write_u(char *str, int *n, struct_format form, va_list arg);
void write_f(char *str, int *n, struct_format form, va_list arg);
void write_str(char *str, int *n, struct_format form, char *arg_s);
void write_str_l(char *str, int *n, struct_format form, wchar_t *arg_s_l);
void write_s(char *str, int *n, struct_format form, va_list arg);
void write_fl(char *str, int *n, char *mem_bef_dot, char *mem_aft_dot,
              struct_format form, double arg);
void write_zero(char *str, int *n, int len, struct_format form);
void write_sign(char *str, int *n, struct_format form, long long arg);
void write_space(char *str, int *n, int length, struct_format form);
void write_int(char *str, int *n, struct_format form, long long arg);
void write_wide_char(char *str, int *n, struct_format form, wchar_t arg);
int length_of_arg(long long num);
int length_of_accuracy_or_width(const char *format, int *i);
int count_sign_len(struct_format form, long long arg);
int len_of_wchar(wchar_t *arg_s_l);
void write_sign_float(char *str, int *n, struct_format form, long double arg);
void number_of_int(char *memory_str, long long arg);
void unsigned_num(char *memory_str, unsigned long long arg);
double round_arg(struct_format form, double number);
#endif  // S21_STRING_H_
