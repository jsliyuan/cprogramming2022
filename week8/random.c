#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int k;
  long long now;
  srand(time(&now));

  // Generate 10 numbers in [0, 99]
  for(k = 0; k < 10; k++) {
    printf("%d\n", rand() % 100);
  }

  return 0;
}
