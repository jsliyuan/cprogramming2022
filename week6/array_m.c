#include <stdio.h>

int main() {
  int m;
  scanf("%d", &m);

  int int_array[m];
  int i;
  for (i = 0; i < m; i ++) {
    int_array[i] = i;
    printf("int_array[%d] = %d\n", i, int_array[i]);
  }

  return 0;
}