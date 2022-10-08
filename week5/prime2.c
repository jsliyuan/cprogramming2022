#include  <stdio.h>

// Return 1 if p is a prime, return 0 otherwise.
int is_prime(int p) {
  int k;
  for (k = 2; k*k <= p; k += 1) {
    if (p % k == 0) {
      break;
    }
  }

  if (k*k > p)
    return 1;
  else
    return 0;
}

int main() {
  int n;
  printf("Input n: ");
  scanf("%d", &n);

  for (int i = 2; i <= n; i ++) {
    if (is_prime(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}
