#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int mult(int a, int b);
int div(int a, int b);
int check_str(char *str);

int main() {
    int num1;
    int num2;
    char str1[20];
    char str2[20];

    scanf("%20s %20s", str1, str2);
    if (check_str(str1) == 0 || check_str(str2) == 0) {
        printf("n/a");
        return (1);
    }
    sscanf(str1, "%d", &num1);
    sscanf(str2, "%d", &num2);
    if (num2 == 0)
        printf("%d %d %d n/a", sum(num1, num2), diff(num1, num2), \
        mult(num1, num2));
    else
        printf("%d %d %d %d", sum(num1, num2), diff(num1, num2), \
        mult(num1, num2), div(num1, num2));
    return (0);
}

int sum(int a, int b) {
    return (a + b);
}
int diff(int a, int b) {
    return (a + b);
}
int mult(int a, int b) {
    return (a * b);
}
int div(int a, int b) {
    return (a / b);
}

int check_str(char *str) {
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            i++;
        else
            return (0);
    }
    return (1);
}
