#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);
int check_int(char *str);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return (1);
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    char str[20];

     if (n == NULL || a == NULL)
        return (1);
    scanf("%20s", str);
    if (check_int(str) == 0)
        return (1);
    sscanf(str, "%d", n);
    if (*n < 1 || *n > NMAX)
        return (1);
    for (int *p = a; p - a < *n;  p++) {
        scanf("%20s", str);
        if (check_int(str) == 0)
            return (1);
        sscanf(str, "%d", p);
    }
    return (0);
}

void output(int *a, int n) {
    int i;

    i = 0;
    while (i < n - 1) {
        printf("%d ", a[i]);
            i++;
    }
    printf("%d", a[i]);
}

void squaring(int *a, int n) {
    int i;

    i = 0;
    while (i < n) {
        a[i] = a[i] * a[i];
            i++;
    }
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
