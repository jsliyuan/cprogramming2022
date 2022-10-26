#include <stdio.h>

void print_matrix(int n) {
  int a[n][n];
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = (n - i + j) % n  +  1;
      printf("%4d", a[i][j]);
    }
    printf("\n");
  }
}

int main() {
  print_matrix(5);

  return 0;
}