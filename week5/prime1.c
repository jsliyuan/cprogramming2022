#include  <stdio.h>

int main() {
  int n;
  printf("Input n: ");
  scanf("%d", &n);

  for (int i = 2; i <= n; i ++) {
    int k;
    for (k = 2; k*k <= n; k += 1) {
      if (i % k == 0) {
        break;
      }
    }

    if (k*k > i) {
      printf("%d\n", i);
    }
  }

  return 0;
}
