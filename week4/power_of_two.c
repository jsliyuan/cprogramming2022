#include <stdio.h>

// Given n, returns 2^n.
int power_of_two(int n) {
  int result = 1;
  int i;
  for (i = 0; i < n; i ++)
    result *= 2;
  return result;
}

int main() {
  printf("2^8 = %d\n", power_of_two(8));
  printf("2^0 = %d\n", power_of_two(0));
  printf("2^(2^4) = %d\n", power_of_two(power_of_two(4)));
  return 0;
}
