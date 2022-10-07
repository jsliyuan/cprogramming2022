#include <stdio.h>

int main() {
  int i, x[5], sum = 0;

  printf("Enter 5 numbers: ");
  for(i = 0; i < 5; ++i) {
      // Equivalent to scanf("%d", &x[i]);
      scanf("%d", x + i);
      // Equivalent to sum += x[i]
      sum += * (x + i);
  }

  printf("sum = %d\n", sum);

  return 0;
}