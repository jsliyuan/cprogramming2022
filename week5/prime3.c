#include  <stdio.h>

int main() {
  int n;
  printf("Input n: ");
  scanf("%d", &n);

  int is_prime[n + 1];
  for (int i = 2; i <= n; i ++) {
    is_prime[i] = 1;
  }

  for (int i = 2; i <= n; i ++) {
    if (is_prime[i]) {
      printf("%d\n", i);

      int j = i + i;
      while (j <= n) {
        is_prime[j] = 0;
        j += i;
      }
    }
  }

  return 0;
}
