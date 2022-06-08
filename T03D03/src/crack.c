#include <stdio.h>

int check_str(char *str);
int point_int_circle(float a, float b);

int main() {
    float num1;
    float num2;
    char str1[30];
    char str2[30];

    scanf("%30s %30s", str1, str2);
    if (check_str(str1) == 0 || check_str(str2) == 0) {
        printf("n/a");
        return (1);
    }
    sscanf(str1, "%f", &num1);
    sscanf(str2, "%f", &num2);
    if (point_int_circle(num1, num2) == 1)
        printf("GOTCHA");
    else
        printf("MISS");
    return (0);
}

int check_str(char *str) {
    int i;
    int count;

    i = 0;
    count = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i] != '\0') {
        if (str[i] == '.') {
            if (count == 0) {
                count++;
                i++;
            } else {
                return (0);}
        } else if (str[i] >= 48 && str[i] <= 57) {
            i++;}
        else
            return (0);
    }
    return (1);
}

int point_int_circle(float a, float b) {
    double y;

    y = a * a + b * b;
    return (y <= 25);
}
