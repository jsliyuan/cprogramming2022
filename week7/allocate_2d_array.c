#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 5;
  double (*A)[n] = malloc(sizeof(double[n][n]));

  for (int i = 0; i < n; i ++) {
  	for (int j = 0; j < n; j ++)
  	  A[i][j] = i + j;
  }

  free(A);
  return 0;
}