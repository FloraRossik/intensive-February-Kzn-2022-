// "Copyright 2022 <emmittan>"
#include <stdio.h>
#include <string.h>
#include <stdalign.h>
#include <stdlib.h>

typedef struct s_data {
  int year;
  int month;
  int day;
  int houre;
  int minute;
  int second;
  int status;
  int code;
}     t_data;


int data_date_cmp(t_data d1, t_data d2);
int read_data(t_data *data, char *str);
int read_from_file(char *file_name);
int add_to_file(char *file_name);
int add_struct_end(FILE *file, t_data *data);
void print_data(t_data *data);
int file_size(FILE *file);
int get_struct_at(FILE *file, t_data *buff, int idx, int size);
int put_struct_at(FILE *file, t_data *buff, int idx, int size);
int data_cmp(t_data d1, t_data d2);
int data_in_interval(t_data a, t_data b, t_data data);
int get_interval(t_data *a, t_data *b);
int clear_interval(char *file_name, t_data a, t_data b);
char  *ft_strjoin(char *s1, char *s2);


int main(void) {
  char file_name[1024];
  t_data a, b;

  if (scanf("%1023s", file_name) != 1)
    printf("n/a");
  else if (get_interval(&a, &b) == -1)
    printf("n/a");
  else if (clear_interval(file_name, a, b) == -1)
    printf("n/a");
  else if (read_from_file(file_name) == -1)
    printf("n/a");

  return (0);
}

int read_data(t_data *data, char *str) {
  if (data == NULL || str == NULL)
    return (-1);
  data->day = str[0] - '0';
  data->day = data->day * 10 + str[1] - '0';
  data->month = str[3] - '0';
  data->month = data->month * 10 + str[4] - '0';
  data->year = str[6] - '0';
  data->year = data->year * 10 + str[7] - '0';
  data->year = data->year * 10 + str[8] - '0';
  data->year = data->year * 10 + str[9] - '0';
  return (0);
}

void print_data(t_data *data) {
  if (data == NULL)
    return;
  printf("%d %d %d %d %d %d %d %d\n", data->year, data->month, data->day, \
                                  data->houre, data->minute, data->second, \
                                  data->status, data->code);
}

int file_size(FILE *file) {
  int out;
  int size;
  t_data buff;

  if (file == NULL)
    return (-1);
  out = 0;
  fseek(file, 0, SEEK_SET);
  while ((size = fread(&buff, sizeof(buff), 1, file)) > 0) {
    out++;
  }
  fseek(file, 0, SEEK_SET);
  return (out);
}

int get_struct_at(FILE *file, t_data *buff, int idx, int size) {
  if (size < 0)
    size = file_size(file);
  if (file == NULL || buff == NULL || idx < 0)
    return (-1);
  if (idx >= size)
    return (-1);
  fseek(file, idx * sizeof(t_data), SEEK_SET);
  if (fread(buff, sizeof(t_data), 1, file) < 1)
    return (-1);
  fseek(file, 0, SEEK_SET);
  return (0);
}

int data_date_cmp(t_data d1, t_data d2) {
  int date1, date2;

  // 1986 12 03
  // 1986 * 10000 =   19860000
  // 12 * 100 =     +     1200
  // 03 * 1 =       +       03
  //                  19861203

  date1 = d1.year * 10000 + d1.month * 100 + d1.day;
  date2 = d2.year * 10000 + d2.month * 100 + d2.day;

  if (date1 > date2)
    return (1);
  if (date1 < date2)
    return (-1);
  return (0);
}

int data_in_interval(t_data a, t_data b, t_data data) {
  if (data_date_cmp(data, a) > 0 && data_date_cmp(data, b) > 0)
    return (0);
  if (data_date_cmp(data, a) < 0 && data_date_cmp(data, b) < 0)
    return (0);
  return (1);
}

int get_interval(t_data *a, t_data *b) {
  char str[11];

  if (scanf("%10s", str) != 1)
    return (-1);
  str[10] = 0;
  if (read_data(a, str) == -1)
    return (-1);
  if (scanf("%10s", str) != 1)
    return (-1);
  str[10] = 0;
  if (read_data(b, str) == -1)
    return (-1);
  return (1);
}

int clear_interval(char *file_name, t_data a, t_data b) {
  FILE *file, *tmp_file;
  char *tmp_name;
  t_data buff;
  int size;

  file = fopen(file_name, "r+b");
  if (file == NULL)
    return(-1);
  size = file_size(file);
  if (size < 1)
    return (-1);
  tmp_name = ft_strjoin(file_name, "__tmp__");
  if (tmp_name == NULL) {
    fclose(file);
    return (-1);
  }
  tmp_file = fopen(tmp_name, "w+b");
  if (tmp_file == NULL) {
    fclose(file);
    free(tmp_name);
    return (-1);
  }
  for (int i = 0; i < size; i++) {
    get_struct_at(file, &buff, i, size);
    if (data_in_interval(a, b, buff) == 0)
      fwrite(&buff, sizeof(buff), 1, tmp_file);
  }
  fclose(file);
  fclose(tmp_file);
  remove(file_name);
  rename(tmp_name, file_name);
  free(tmp_name);
  return (0);
}

char  *ft_strjoin(char *s1, char *s2) {
  int i = 0;
  char *out;
  int size;

  if (s1 == NULL || s2 == NULL)
    return (NULL);
  size = strlen(s1) + strlen(s2);
  out = malloc(size + 1);
  if (out == NULL)
    return (NULL);
  while (*s1)
    out[i++] = *s1++;
  while (*s2)
    out[i++] = *s2++;
  out[i] = 0;
  return (out);
}

int read_from_file(char *file_name) {
  FILE *file;
  t_data buff;
  size_t size;

  file = fopen(file_name, "rb");
  if (file == NULL)
    return(-1);
  while ((size = fread(&buff, sizeof(buff), 1, file)) > 0) {
    print_data(&buff);
  }
  fclose(file);
  return(1);
}
