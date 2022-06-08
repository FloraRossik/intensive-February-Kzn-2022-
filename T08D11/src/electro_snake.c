#include <stdio.h>
#include <stdlib.h>
void sort_vertical(int **matrix, int n, int m, int ***result_matrix);
void sort_horizontal(int **matrix, int n, int m, int ***result_matrix);
int check_int(char *str);
void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void ft_sort(int *tmp, int count);


int main(void) {
  int **matrix, **result;
  int n, m;

  matrix = NULL;
  input(&matrix, &n, &m);
  if (n < 0) {
    printf("n/a");
    return (1);
  }
  result = NULL;
  sort_vertical(matrix, n, m, &result);
  output(result, n, m);
  printf("\n");
  sort_horizontal(matrix, n, m, &result);
  output(result, n, m);
}

void input(int ***matrix, int *n, int *m) {
  char str[20];

  scanf("%19s", str);
  if (check_int(str) == 0)
    return;
  sscanf(str, "%d", n);
  if (*n < 1) {
    *n = -1;
    return;
  }
  scanf("%19s", str);
  if (check_int(str) == 0)
    return;
  sscanf(str, "%d", m);
  if (*m < 1) {
    *n = -1;
    return;
  }
  *matrix = malloc(*n * sizeof(int*));
  for (int i = 0; i < *n; i++)
    matrix[0][i] = malloc(*m * sizeof(int));
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      scanf("%19s", str);
      if (check_int(str) == 0) {
      *n = -1;
        return;
      }
      sscanf(str, "%d", &matrix[0][i][j]);
    }
  }
}

void output(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", matrix[i][j]);
    if (j != m - 1)
       printf(" ");
  }
  if (i != n - 1)
  printf("\n");
  }
}

int check_int(char *str) {
  if (*str == '-' || *str == '+')
    str++;
  while (*str != '\0') {
    if (*str < 48 || *str > 57)
      return(0);
    str++;
  }
  return (1);
}

void sort_horizontal(int **matrix, int n, int m, int ***result_matrix) {
  int count;
  int *tmp;

  *result_matrix = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++)
    (*result_matrix)[i] = malloc(m * sizeof(int));

  tmp = malloc(n * m * sizeof(int));
  count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[count++] = matrix[i][j];
    }
  }
  ft_sort(tmp, count);
  count = 0;
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
    result_matrix[0][i][j] = tmp[count++];
    }
    i++;
    for (int j = m - 1; j >= 0; j--) {
        result_matrix[0][i][j] = tmp[count++];
       }
    }
    free(tmp);
}

void sort_vertical(int **matrix, int n, int m, int ***result_matrix) {
    int count;
    int *tmp;
    *result_matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
         (*result_matrix)[i] = malloc(m * sizeof(int));
    tmp = malloc(n * m * sizeof(int));
    count = 0;
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[count++] = matrix[i][j];
    }
  }
    ft_sort(tmp, count);
  count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      result_matrix[0][j][i] = tmp[count++];
    }
    i++;
    for (int j = n - 1; j >= 0; j--) {
      result_matrix[0][j][i] = tmp[count++];
    }
  }
  free(tmp);
}

void ft_sort(int *tmp, int count) {
  int tmp2;
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      if (tmp[i] > tmp[j]) {
        tmp2 = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = tmp2;
      }
    }
  }
}
