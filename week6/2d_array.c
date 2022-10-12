#include <stdio.h>

int main() {
  int m, n;
  printf("Input m and n: ");
  scanf("%d%d", &m, &n);

  int matrix[m][n], i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++) {
      printf("Enter matrix[%d][%d] ", i, j); 
      scanf("%d", &matrix[i][j]);
    }

  // Print the 2D array line by line.
  for(i = 0; i < m; i++) { 
    for(j = 0; j < n; j++)
      printf("%d\t", matrix[i][j]);
    printf("\n");
  }

  return 0;
}
