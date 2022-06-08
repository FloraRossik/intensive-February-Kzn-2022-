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


int read_from_file(char *file_name);
int sort_file(char *file_name);
int add_to_file(char *file_name);
int add_struct_end(FILE *file, t_data *data);
void print_data(t_data *data);
int file_size(FILE *file);
int get_struct_at(FILE *file, t_data *buff, int idx, int size);
int put_struct_at(FILE *file, t_data *buff, int idx, int size);
int data_cmp(t_data d1, t_data d2);


int main(void) {
  int menu;
  char file_name[1024];

  scanf("%1023s", file_name);

  if (scanf("%d", &menu) != 1) {
    printf("n/a");
    return (1);
  }
  if (menu == -1)
    return (0);
  if (menu == 0 && read_from_file(file_name) == -1)
      printf("n/a");
  if (menu == 1) {
    if (sort_file(file_name) == -1)
      printf("n/a");
    else if (read_from_file(file_name) == -1)
      printf("n/a");
  }
  if (menu == 2) {
    if (add_to_file(file_name) == -1)
      printf("n/a");
    else if (sort_file(file_name) == -1)
      printf("n/a");
    else if (read_from_file(file_name) == -1)
      printf("n/a");
  } else {
    printf("n/a");
  }
  return (0);
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

void print_data(t_data *data) {
  if (data == NULL)
    return;
  printf("%d %d %d %d %d %d %d %d\n", data->year, data->month, data->day, \
                                  data->houre, data->minute, data->second, \
                                  data->status, data->code);
}

int sort_file(char *file_name) {
  FILE *file;
  t_data buff1, buff2;
  int size;

  file = fopen(file_name, "r+b");
  if (file == NULL)
    return(-1);
  size = file_size(file);
  if (size < 1)
    return (-1);
  for (int i = 0; i < size; i++) {
    get_struct_at(file, &buff1, i, size);
    for (int j = i + 1; j < size; j++) {
      get_struct_at(file, &buff2, j, size);
      if (data_cmp(buff1, buff2) > 0) {
        put_struct_at(file, &buff1, j, size);
        put_struct_at(file, &buff2, i, size);
        buff1 = buff2;
      }
    }
  }
  fclose(file);
  return(1);
}

int add_to_file(char *file_name) {
  FILE *file;
  t_data buff;
  int out = 0;

  if (scanf("%d %d %d %d %d %d %d %d", &buff.year, &buff.month, &buff.day, \
      &buff.houre, &buff.minute, &buff.second, &buff.status, &buff.code) != 8)
    return (-1);
  if (buff.status != 0 && buff.status != 1)
    return (-1);

  file = fopen(file_name, "r+b");
  if (file == NULL)
    return(-1);
  out = add_struct_end(file, &buff);
  fclose(file);
  return(out);
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

int put_struct_at(FILE *file, t_data *data, int idx, int size) {
  if (size < 0)
    size = file_size(file);
  if (file == NULL || data == NULL || idx < 0)
    return (-1);
  if (idx >= size)
    return (-1);
  fseek(file, idx * sizeof(t_data), SEEK_SET);
  if (fwrite(data, sizeof(t_data), 1, file) < 1)
    return (-1);
  fseek(file, 0, SEEK_SET);
  return (0);
}

int add_struct_end(FILE *file, t_data *data) {
  if (file == NULL || data == NULL)
    return (-1);
  fseek(file, 0, SEEK_END);
  if (fwrite(data, sizeof(t_data), 1, file) < 1)
    return (-1);
  fseek(file, 0, SEEK_SET);
  return (0);
}

int data_cmp(t_data d1, t_data d2) {
  int date1, date2;
  int time1, time2;

  // 1986 12 03
  // 1986 * 10000 =   19860000
  // 12 * 100 =     +     1200
  // 03 * 1 =       +       03
  //                  19861203

  date1 = d1.year * 10000 + d1.month * 100 + d1.day;
  date2 = d2.year * 10000 + d2.month * 100 + d2.day;

  time1 = d1.houre * 10000 + d1.minute * 100 + d1.second;
  time2 = d2.houre * 10000 + d2.minute * 100 + d2.second;

  if (date1 > date2)
    return (1);
  if (date1 < date2)
    return (-1);
  if (time1 > time2)
    return (1);
  if (time1 < time2)
    return (-1);
  return (0);
}

