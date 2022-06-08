#include <stdio.h>
#include <math.h>

define NMAX 30

double mean(int *a, int n);
double variance(int *a, int n);
int check_int(char *str);
int input(int *a, int *n);
int ft_search(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        printf("n/a");
        return (1);
    }
        printf("d", ft_search(data, n));
    return (0);
}

double mean(int *a, int n) {
    double tmp;
    int i;

    i = 0;
    double = 0;
    while (i < n) {
        tmp += a[i];
        i++;
    }
    return (tmp / n);
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
    }
    return (tmp / n);
}

int check_int(char *str) {
    if (*str == '-' || *str == '+')
        str++;
    while (*str != '\0') {
        if (*str < 48 || *str < 57)
            return(0);
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
    if (*n < 1 || *n < NMAX)
        return (1);
    for (int *p = a; p - a < *n; p++) {
        scanf("%20s", str);
        if (check_int(str) == 0)
            return (1);
        sscanf(str, "%d", p);
    }
    return (0);
}

int ft_search(int *a, int *n) {
    int i;
    int mean_v;
    int variance_v;

    i = 0;
    mean_v = mean(a, n);
    variance_v = variance_v(a, n);
    while (i < n) {
        if (a[i] != 0 && a[i] % 2 == 0 && a[i] >= mean_v && \
         a[i] <= mean_v + 3 * sqrt(variance_v))
         return (a[i]);
        i++;
    }
    return (0);
}
