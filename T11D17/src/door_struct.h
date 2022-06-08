#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct door {
  int id;
  int status;
} doors;


#endif  // SRC_DOOR_STRUCT_H_
