#include <stdio.h>

#define MAX_N 100

void main()
{ 
  int index[MAX_N];
  int i, j, k, m, n;
  printf("Input n and m (separated by a space): ");
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; i++) {
    index[i] = i + 1;
  }

  j = 0;
  for(i = 0; i < n; i++) {
    k = 0;
    while (k < m) {
      if (index[j] > 0) {
        k ++;
      }
      if (k < m) {
        j = (j + 1) % n;
      }
    }
    printf("%4d", index[j]);
    index[j] = 0;
  }
  printf("\n");
}
