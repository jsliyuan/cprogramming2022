#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n][n];
  int i, j, k, d;

  for(k = d = 1; d <= 2*n-1; d++)  { 
    if (d <= n-1) {
      if (d % 2) {
        for (i = n-d, j = 0; i < n; i++, j++) {
          a[i][j] = k++;
        }
      } else {
        for (i = n-1, j = d-1; i >= n-d; i--, j--)
          a[i][j] = k++;
      }
    } else { // d >= n
      if (d % 2) {
        for (i = 0, j = d-n; i <= 2*n-1-d; i++, j++) {
          a[i][j] = k++;
        }
      } else {
        for (i = 2*n-1-d, j = n-1; i >= 0; i--, j--) {
          a[i][j] = k++;
        }
      }
    }
 }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%4d", a[i][j]);
     printf("\n");
  }

  return 0;
}