#include <stdio.h>
#include <stdlib.h>

// Why global array has a larger size than the local array?
// https://www.geeksforgeeks.org/why-global-array-has-a-larger-size-than-the-local-array/

// 5*10^5
// However, 6*10^5 does not work on my laptop
#define LOCAL_LENGTH 500000

// 4*10^8
// However, 5*10^8 does not work on my laptop.
#define GLOBAL_LENGTH 400000000

// 10^9
#define DYNAMIC_LENGTH 1000000000

int global_array[GLOBAL_LENGTH];

int main() {
  printf("global_array = %p\n", global_array);

  printf("Declaring a local array of size %d\n", LOCAL_LENGTH);
  int large_array[LOCAL_LENGTH];
  printf("Declaring local array succeed.\n");

  int* dynamic_array;
  dynamic_array = (int*) malloc(DYNAMIC_LENGTH * sizeof(int));
  printf("Malloc succeed.");
  free(dynamic_array);

  return 0;
}