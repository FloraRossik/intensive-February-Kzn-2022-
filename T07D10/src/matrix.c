#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input(int *m, int *a, int *b);
void output(int **buff, int length, int length2);
int **ft_malloc(int length2, int length);
int check_str(char *str);
void matrix1(int n, int m);
void matrix2(int n, int m);
void matrix3(int n, int m);
void matrix4(int n, int m);

int main() {
    int n, m, method;

    if(input(&method, &n, &m) == 1) {
        printf("n/a");
        return (1);
    }
    if (method == 1)
        matrix1(n, m);
    else if (method == 2)
        matrix2(n, m);
    else if (method == 3)
        matrix3(n, m);
    else if (method == 4)
        matrix4(n, m);
}

int input(int *m, int *a, int *b) {
    char str[30];

    scanf("%29s", str);
    if (check_str(str) == 0)
        return (1);
    sscanf(str, "%d", m);
    if (*m  < 1 || *m > 4)
        return (1);
    scanf("%29s", str);
    if (check_str(str) == 0)
        return (1);
    sscanf(str, "%d", a);
    if (*a < 1 || *a > NMAX)
        return (1);
    scanf("%29s", str);
    if (check_str(str) == 0)
        return (1);
    sscanf(str, "%d", b);
    if (*b  < 1 || *b > NMAX)
        return (1);
    return (0);
}

int check_str(char *str) {
    if (*str == '-' || *str == '+')
        str++;
    while (*str != '\0') {
        if (*str < 48 || *str > 57)
            return (0);
        str++;
    }
    return (1);
}

void output(int **buff, int length, int length2) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length2; j++) {
            printf("%d", buff[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < length2; j++) {
        printf("%d", buff[length - 1][j]);
    }
}

int **ft_malloc(int m, int n) {
    int numbers;
    char str[30];
    int j;
    int i;
    int **matrix;

    matrix = malloc(m * sizeof(int*));
    if (matrix == NULL)
        return (NULL);
    i = 0;
    while (i < m)
    {
        matrix[i] = malloc(n * sizeof(int));
        if (matrix[i] == NULL)
            return (NULL);
        j = 0;
        while (j < n)
        {
            scanf("%29s", str);
            if (check_str(str) == 0) {
                printf("n/a");
                return (NULL);
            }
            sscanf(str, "%d", &numbers);
            matrix[i][j] = numbers;
            j++;
        }
        i++;
    }
    return (matrix);
}

void matrix1(int n, int m) {
    int new_buff[NMAX][NMAX];
    int i, j, number;
    char str[16];

    i = 0;
    while (i < n) {
        j = 0;
        while (j < m) {
            scanf("%15s", str);
            if (check_str(str) == 0)
            {
                printf ("n/a");
                return;
            }
            sscanf(str, "%d", &number);
            new_buff[i][j] = number;
            j++;
        }
        i++;
    }
    output((int **)new_buff, n, m);
}

void matrix3(int n, int m) {
    int **new_buff;

    new_buff = ft_malloc(n, m);
    if (new_buff == NULL)
    {
        printf("n/a");
        return;
    }
    output(new_buff, n, m);
    for (int i = 0; i < n; i++)
        free(new_buff[i]);
    free(new_buff);
}

void matrix2(int n, int m) {
    int **new_buff = malloc(m * sizeof(int *));
    int *values_buff = malloc(m * n * sizeof(int));

    char str[30];
    int numbers;
    for (int i = 0; i < m; i++)
        new_buff[i] = values_buff + n * i;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%29s", str);
            if (check_str(str) == 0)
               {
                   printf("n/a");
                   return;
               }
            sscanf(str, "%d", &numbers);
        new_buff[i][j] = numbers;
        }
    }
    output(new_buff, n, m);
    free(new_buff);
}

void matrix4(int n, int m) {
    int **matrix4 = malloc(m * n * sizeof(int) + m * sizeof(int*));
    int *ptr = (int*) (matrix4 + m);

    char str[30];
    int count;
    for (int i = 0; i < m; i++)
        matrix4[i] = ptr + n * i;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%29s", str);
        if (check_str(str) == 0)
        {
            printf("n/a");
            return;
        }
        sscanf(str, "%d", &count);
        matrix4[i][j] = count;
        }
    }
    output(matrix4, n, m);
    free(matrix4);
}