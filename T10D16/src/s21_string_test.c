#include "s21_string.h"
#include <stdio.h>
#include <string.h>

void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);
void s21_strnlen_test(void);
void s21_strncmp_test(void);

int main(void) {
  s21_strlen_test();
  printf("\n");
  s21_strcmp_test();
  printf("\n");
  s21_strcpy_test();
  printf("\n");
  s21_strnlen_test();
  s21_strncmp_test();
  return (0);
}

void s21_strlen_test(void) {
  printf("s21_strlen_test\n");
  char *str1 = "hello world!";
  size_t result;
  size_t expected;

  result = s21_strlen(str1);
  expected = strlen(str1);
  printf("test1 : %-30s , result : %-5ld , %s\n", str1, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = "";
  result = s21_strlen(str1);
  expected = strlen(str1);
  printf("test2 : %-30s , result : %-5ld , %s\n", str1, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = NULL;
  result = s21_strlen(str1);
  expected = 0;
  printf("test3 : %-30s , result : %-5ld , %s\n", str1, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = ".";
  result = s21_strlen(str1);
  expected = strlen(str1);
  printf("test4 : %-30s , result : %-5ld , %s\n", str1, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = "\n\t  jfiasjf;ajdifjaij\b\b\b  q\t ,.\'\" \0  j;ijdfa;j \0 ijf";
  result = s21_strlen(str1);
  expected = strlen(str1);
  printf("test5 : %s , result : %-5ld , %s\n", str1, result, \
  result == expected ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test(void) {
  printf("s21_strcmp_test\n");
  char *str1 = "hello world my name";
  char *str2 = "hello world!";
  size_t result;
  size_t expected;

  result = s21_strcmp(str1, str2);
  expected = strcmp(str1, str2);
  printf("test1 : %-30s %-30s , result : %-5ld , %s\n", str1, str2, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = "";
  str2 = "Hello";
  result = s21_strlen(str1);
  expected = strlen(str1);
  printf("test2 : %-30s %-30s , result : %-5ld , %s\n", str1, str2, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = NULL;
  str2 = NULL;
  result = s21_strcmp(str1, str2);
  expected = 0;
  printf("test3 : %-30s %-30s , result : %-5ld , %s\n", str1, str2, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = "Hi my name is emmittan ahjelica";
  str2 = "Hello world ride";
  result = s21_strcmp(str1, str2);
  expected = strcmp(str1, str2);
  printf("test4 : %-30s %-30s , result : %-5ld , %s\n", str1, str2, result, \
  result == expected ? "SUCCESS" : "FAIL");

  str1 = "\n\t  jfiasjf;ajdifjaij\b\b\b  q\t ,.\'\" \0  j;ijdfa;j \0 ijf";
  str2 = " *+645/0-7&#@!";
  result = s21_strcmp(str1, str2);
  expected = strcmp(str1, str2);
  printf("test5 : %s %s , result : %-5ld , %s\n", str1, str2, result, \
  result == expected ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test(void) {
  printf("s21_strcpy_test\n");
  char a[100] = "Game_of_life";
  char b[100] = "Game_of_life";
  char *c = "Hello   .";

  char *result = s21_strcpy(a, c);
  char *expected = strcpy(b, c);
  printf("test1 : %-30s %-30s , result : %-5s , %s\n", a, c, result, \
    strcmp(result, expected) == 0 ? "SUCCESS" : "FAIL");

  char a2[100] = "intensive";
  char b2[100] = "intensive";
  char c2[] = "Hel         ";

  result = s21_strcpy(a2, c2);
  expected = strcpy(b2, c2);

  printf("test2 : %-30s %-30s , result : %-5s , %s\n", a2, c2, result, \
    strcmp(result, expected) == 0 ? "SUCCESS" : "FAIL");

  char *a3 = NULL;
  char *c3 = NULL;
  result = s21_strcpy(a3, c3);
  expected = NULL;
  printf("test4 : %-30s %-30s , result : %-5s , %s\n", a3, c3, result, \
    result == expected ? "SUCCESS" : "FAIL");

  char a4[100] = "jfiasjf;ajdifjaij,.\'\" \0 this will be lost";
  char b4[100] = "jfiasjf;ajdifjaij,.\'\" \0 this will be lost";
  char c4[] = " *+645/0-7&#@!                              ";
  result = s21_strcpy(a4, c4);
  expected = strcpy(b4, c4);

  printf("test5 : %-30s %-30s , result : %-5s , %s\n", a4, c4, result, \
  strcmp(result, expected) == 0 ? "SUCCESS" : "FAIL");

  char a5[100] = "something";
  char *c5 = NULL;
  result = s21_strcpy(a5, c5);
  expected = NULL;
  printf("test6 : %-30s %-30s , result : %-5s , %s\n", a5, c5, result, \
  result == NULL ? "SUCCESS" : "FAIL");
}

void  s21_strnlen_test(void) {
  printf("s21_strnlen_test\n");
  char *str1 = "hello world!";
  size_t max_size = 5;
  size_t result;
  size_t expected;

  result = s21_strnlen(str1, max_size);
  expected = strnlen(str1, max_size);
  printf("test1 : %-30s , result : %-5ld , %s\n", str1, result, result == expected ? "SUCCESS" : "FAIL");

  str1 = "";
  result = s21_strnlen(str1, max_size);
  expected = strnlen(str1, max_size);
  printf("test2 : %-30s , result : %-5ld , %s\n", str1, result, result == expected ? "SUCCESS" : "FAIL");

  str1 = NULL;
  result = s21_strnlen(str1, max_size);
  expected = 0;
  printf("test3 : %-30s , result : %-5ld , %s\n", str1, result, result == expected ? "SUCCESS" : "FAIL");

  str1 = "My name is";
  max_size = 0;
  result = s21_strnlen(str1, max_size);
  expected = 0;
  printf("test4 : %-30s , result : %-5ld , %s\n", str1, result, result == expected ? "SUCCESS" : "FAIL");

  max_size = 10;
  str1 = "\n\t  jfiasjf;ajdifjaij\b\b\b  q\t ,.\'\" \0  j;ijdfa;j \0 ijf";
  result = s21_strnlen(str1, max_size);
  expected = strnlen(str1, max_size);
  printf("test5 : %s , result : %-5ld , %s\n", str1, result, result == expected ? "SUCCESS" : "FAIL");
}

void s21_strncmp_test(void) {
  printf("s21_strncmp_test\n");
  size_t size_max = 7;
  char *str1 = "hello world my name";
  char *str2 = "hello world!";
  size_t result;
  size_t expected;

  result = s21_strncmp(str1, str2, size_max);
  expected = 0;
  printf("test1 : %-30s %-30s %ld, result : %-5ld , %s\n", str1, str2, size_max, \
    result, result == expected ? "SUCCESS" : "FAIL");

  str1 = "";
  str2 = "Hello";
  result = s21_strncmp(str1, str2, size_max);
  expected = strncmp(str1, str2, size_max);
  printf("test2 : %-30s %-30s %ld, result : %-5ld , %s\n", str1, str2, size_max, \
    result, result == expected ? "SUCCESS" : "FAIL");

  size_max = 11;
  str1 = "Hi my name is emmittan anjelica";
  str2 = "Hello world ride";
  result = s21_strncmp(str1, str2, size_max);
  expected = strncmp(str1, str2, size_max);
  printf("test3 : %-30s %-30s %ld, result : %-5ld , %s\n", str1, str2, size_max, \
    result, result == expected ? "SUCCESS" : "FAIL");

  size_max = -1;
  str1 = "Hello ride write good bush ex";
  str2 = "goole chrome";
  result = s21_strncmp(str1, str2, size_max);
  expected = strncmp(str1, str2, size_max);
  printf("test4 : %-30s %-30s %ld, result : %-5ld , %s\n", str1, str2, size_max, \
    result, result == expected ? "SUCCESS" : "FAIL");
}
