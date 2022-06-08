#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
int check_int(char *str);

int main() {
    int buff[NMAX];
    int numbers[NMAX];
    int length;
    int sum;

    if (input(buff, &length) == 1) {
        printf("n/a");
        return (1);
    }
    sum = sum_numbers(buff, length);
    if (sum == 1) {
        printf("n/a");
        return (1);
    }
    printf("%d\n", sum);
    find_numbers(buff, length, sum, numbers);
    output(numbers, *buff);
    return (0);
}

int input(int *buffer, int *length) {
     char str[20];
     if (buffer == NULL || length == NULL)
        return (1);
     scanf("%20s", str);
     if (check_int(str) == 0)
        return (1);
     sscanf(str, "%d", length);
     if (*length < 1 || *length > NMAX)
        return (1);
    for (int *p = buffer; p - buffer < *length; p++) {
        scanf("%20s", str);
        if (check_int(str) == 0)
            return (1);
        sscanf(str, "%d", p);
    }
    return (0);
}

int sum_numbers(int *buffer, int length) {
    int sum = 1;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            if (sum == 1)
               sum = 0;
            sum = sum + buffer[i];
        }
    }
    return (sum);
}

int find_numbers(int* buffer, int length, int number, int *numbers) {
    int j;

    j = 0;
    for (int i = 0; i < length; i++) {
       if (buffer[i] != 0 && number % buffer[i] == 0) {
           numbers[j++] = buffer[i];
        }
        *buffer = j;
    }
    return (j);
}

int check_int(char *str) {
     if (*str == '+' || *str == '-')
        str++;
     while (*str != '\0') {
     if (*str < 48 || *str > 57)
            return (0);
        str++;
    }
    return (1);
}

void output(int *buffer, int length) {
    int i;

    i = 0;
    while (i < length) {
        printf("%d", buffer[i]);
             i++;
    }
}
