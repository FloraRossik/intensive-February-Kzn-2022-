// "Copyright 2022 <emmittan>"
#include <stdio.h>
#include <string.h>
#include <stdalign.h>

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


void print_data(t_data *data);
int file_size(FILE *file);
int get_struct_at(FILE *file, t_data *buff, int idx, int size);
int data_date_cmp(t_data d1, t_data d2);
int search_data(char *file_name);
int read_data(t_data *data, char *str);


int main(void) {
  char file_name[1024];

  scanf("%1023s", file_name);
  if (search_data(file_name) == -1)
    printf("n/a");
  return (0);
}

int search_data(char *file_name) {
  FILE *file;
  t_data buff, buff2;
  char str[11];
  int size = 0;

  if (scanf("%10s", str) != 1)
    return (-1);
  str[10] = 0;
  if (read_data(&buff, str) == -1)
    return (-1);
  file = fopen(file_name, "r+b");
  if (file == NULL)
    return(-1);
  size = file_size(file);
  if (size < 1)
    return (-1);
  for (int i = 0; i < size; i++) {
    if (get_struct_at(file, &buff2, i, size) == -1) {
      fclose(file);
      return (-1);
    }
    if (data_date_cmp(buff, buff2) == 0) {
      printf("%d", buff2.code);
      fclose(file);
      return (0);
    }
  }
  fclose(file);
  return (-1);
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
