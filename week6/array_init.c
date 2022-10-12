#include <stdio.h>

int main() {
  // Full initialization using {}
  int fib[6] = {0, 1, 1, 2, 3, 5};
  int i;
  for (i = 0; i < 6; i ++) {
    printf("fib[%d] = %d\n", i, fib[i]);
  }

  // Partial initialization using {}
  int even[6] = {0, 2, 4};
  for (i = 0; i < 6; i ++) {
    printf("even[%d] = %d\n", i, even[i]);
  }

  // Array length is unspecified.
  int odd[] = {1, 3, 5, 7, 9};
  for (i = 0; i < 5; i ++) {
    printf("odd[%d] = %d\n", i, odd[i]);
  }

  return 0;
}