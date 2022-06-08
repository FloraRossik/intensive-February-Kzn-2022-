#ifndef S21_STRING_H
#define S21_STRING_H

#include <stddef.h>

size_t  s21_strlen(const char *str);
int     s21_strcmp(const char *s1, const char *s2);
char   *s21_strcpy(char *dest, const char *src);
char   *s21_strcat(char *restrict s1, const char *restrict s2);
char   *s21_strstr(const char *haystack, const char *needle);
size_t  s21_strnlen(const char *s, size_t maxlen);
int     s21_strncmp(const char *s1, const char *s2, size_t n);

#endif