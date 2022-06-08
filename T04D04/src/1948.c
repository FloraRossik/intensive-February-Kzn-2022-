#include <stdio.h>
#include <math.h>

int ft_divide(int a, int b, int *div, int *mood);
int check_int(char *str);
int is_prime(int a);
int pg_divider(int n);

int main() {
    char n_str[20];
    int n;

    scanf("%20s", n_str);
    if (check_int(n_str) == 0) {
        printf("n/a");
        return (1);
    }
    sscanf(n_str, "%d", &n);
    if (n == 0) {
        printf("n/a");
        return (1);
    }
    if (n < 0)
     n *= -1;
    printf("%d", pg_divider(n));
    return (0);
}

int ft_divide(int a, int b, int *div, int *mood) {
    int tmp_a;
    int tmp_b;
    int sign;

    if (b == 0)
        return (0);
    tmp_a = a;
    tmp_b = b;
    *div = 0;
    sign = 1;
    if (tmp_a < 0) {
        tmp_a *= -1;
        sign *= -1;
    }
    if (tmp_b < 0) {
        tmp_b *= 0;
        sign *= -1;
    }
    while (tmp_a >= tmp_b) {
        tmp_a -= tmp_b;
        (*div)++;
    }
    *div = *div * sign;
    *mood = a - b * (*div);
    return (1);
}

int check_int(char *str) {
    if (*str == '-' || *str == '+')
    str++;
    while (*str) {
        if (*str < '0' || *str > '9')
        return (0);
    str++;
    }
    return (1);
}

int is_prime(int a) {
    int i;
    int d;
    int m;

     if (a < 0)
        a *= -1;
     if  (a == 0)
     return (0);
     i = 2;
     while (i <= sqrt(a)) {
         ft_divide(a, i, &d, &m);
         if (m == 0)
            return (0);
        i++;
     }
     return (1);
}

int pg_divider(int n) {
    int i;
    int out;
    int m;
    int d;

    i = 2;
    out = 1;
    while (i < sqrt(n)) {
        ft_divide(n, i, &d, &m);
     if (m == 0 && is_prime(i))
     out = i;
     i++;
    }
    return (out);
}