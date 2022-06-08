#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int check_int(char *str);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        printf("n/a");
        return (1);
    }
    output(data, n);
        printf("\n");
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}

int check_int(char *str) {
    if (*str == '-' || *str == '+')
        str++;
    while (*str != '\0') {
        if (*str < 48 || *str > 57)
            return (0);
        str++;
    }
    return (1);
}

int input(int *a, int *n) {
    char str[20];
    if (a == NULL || n == NULL)
        return (1);
    scanf("%20s", str);
    if (check_int(str) == 0)
        return (1);
    sscanf(str, "%d", n);
    if (*n < 1 || *n > NMAX)
        return (1);
    for (int *p = a; p - a < *n; p++) {
        scanf("%20s", str);
        if (check_int(str) == 0)
            return (1);
        sscanf(str, "%d", p);
    }
    return (0);
}

int max(int *a, int n) {
    int i;
    int tmp;

    tmp = a[0];
    i = 0;
    while (i < n) {
        if (tmp < a[i])
        tmp = a[i];
        i++;
    }
    return (tmp);
}

int min(int *a, int n) {
    int i;
    int tmp;

    i = 0;
    tmp = a[0];
    while (i < n) {
        if (tmp > a[i])
            tmp  = a[i];
        i++;
    }
    return (tmp);
}

void output(int *a, int n) {
    int i;

    i = 0;
    while (i < n - 1) {
        printf("%d", a[i]);
            i++;
    }
    printf("%d", a[i]);
}

double variance(int *a, int n) {
    int i;
    double tmp;
    double save_mean;

    i = 0;
    tmp = 0;
    save_mean = mean(a, n);
    while (i < n) {
        tmp += (a[i] - save_mean) * (a[i] - save_mean);
        i++;
    }
    return (tmp / n);
}

double mean(int *a, int n) {
    int i;
    double tmp;

    i = 0;
    tmp = 0;
    while (i < n) {
        tmp += a[i];
            i++;
    }
    return (tmp / n);
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
                       printf("%d %d %f %f", max_v, min_v, mean_v, variance_v);
                   }
