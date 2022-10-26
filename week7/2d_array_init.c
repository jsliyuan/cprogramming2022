#include <stdio.h>

// Print a 2D array of dimension m * n in m lines.
void print_array(int* array, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) { 
    for (j = 0; j < n; j++)
      printf("%d\t", *(array + i*n + j));
    printf("\n");
  }
}

int main() {
  int a1[3][2] = {{1, 3}, {2, 4}, {7, 9}};
  print_array((int*) a1, 3, 2);
  printf("\n");

  int a2[3][2] = {6, 5, 4, 3, 2, 1};
  print_array((int*) a2, 3, 2);
  printf("\n");

  int a3[3][2] = {{1}, {5}};
  print_array((int*) a3, 3, 2);
  printf("\n");

  return 0;
}
