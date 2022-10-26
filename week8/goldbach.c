#include <stdio.h>

// Returns 1 if n is a prime, 0 otherwise.
int is_prime(int n) {
  int k;
  if (n == 1) return 0;
  if (n == 2) return 1; 
  if (n % 2 == 0) return 0;

  for(k = 3; k*k <= n; k += 2) {
    if (n % k == 0)
      return 0;
  }
  return 1;
}


int main() {
  int n, x, y, m, count=0;
  printf("Enter an even number (>= 6):");
  scanf("%d", &m);

  for (n = 6; n <= m; n += 2) {
    for (x = 3; x <= n/2; x +=2) {
      if (is_prime(x) && is_prime(y = n - x)) {
         printf("%d = %d + %d\n", n, x, y);
         break;
      }
    }
  }
  return 0;
}
