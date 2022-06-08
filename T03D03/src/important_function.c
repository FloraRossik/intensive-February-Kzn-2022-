#include <stdio.h>
#include <math.h>

int check_str(char *str);
double  ft_calc(float a);

int main() {
    float num1;
    char str[20];

    scanf("%20s", str);
    if (check_str(str) == 0) {
        printf("n/a");
        return (1);
    }
    sscanf(str, "%f", &num1);
    printf("%.1f", ft_calc(num1));
    return (1);
}

double  ft_calc(float x) {
    double y;

    y = 7e-3 * pow(x, 4) + \
    ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - \
    x * pow((10 + x), (2/x)) - 1.01;
    return (y);
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
