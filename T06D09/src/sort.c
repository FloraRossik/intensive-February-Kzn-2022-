#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
int check_str(char *str);
void ft_sort(int *a, int n);

int main() {
    int n, data[NMAX];

    n = 10;
    if (input(data, n) == 1) {
        printf("n/a");
        return (1);
    }
    ft_sort(data, n);
    output(data, n);

    return (0);
}

int input(int *a, int n) {
    char str[30];
    if (a == NULL)
    return (1);
    for (int i = 0; i < n; i++) {
        scanf("%30s", str);
        if (check_str(str) == 0)
            return (1);
        sscanf(str, "%d", &a[i]);
    }
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

void output(int *a, int n) {
    int i;

    i = 0;
     while (i < n) {
        printf("%d ", a[i]);
            i++;
    }
}

void ft_sort(int *a, int n) {
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < n) {
        j = i + 1;
        while (j < n) {
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
