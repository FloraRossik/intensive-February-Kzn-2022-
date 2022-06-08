#include <stdio.h>

int check_str(char *str);
int max_int(int a, int b);

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
    printf("%d", max_int(num1, num2));
    return (0);
}

int max_int(int a, int b) {
    if (a > b)
        return (a);
    else
        return (b);
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
