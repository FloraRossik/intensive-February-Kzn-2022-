#include "door_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void ft_sort(struct door *doors);
void output(struct door *doors);
void ft_calloc(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    ft_sort(doors);
    ft_calloc(doors);
    output(doors);
    return 0;
}

void initialize_doors(struct door *doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void ft_sort(struct door *doors) {
    int tmp;
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = i + 1; j < DOORS_COUNT; j++) {
            if (doors[i].id > doors[j].id) {
                tmp = doors[i].id;
                doors[i].id = doors[j].id;
                doors[j].id = tmp;
            }
        }
    }
}

void output(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, ", doors[i].id);
        printf("%d\n", doors[i].status);
    }
}

void ft_calloc(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}
