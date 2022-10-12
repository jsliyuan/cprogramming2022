#include <stdio.h>

int main() {
  int i = 0, k;
  int n = 10;
  int num[n];

  while (i < n) {  
    printf("Enter a[%d]: ", i);
    scanf("%d", &num[i]);

    for(k = 0; num[k] != num[i]; k++)
      ;
    if (k < i) {
      printf("This number has appeared.\n");
    } else {
      i++;
    }
  }

  for(i = 0; i < n; i++) {
    if (i % 5 == 0)
      printf("\n");
    printf("%4d", num[i]);
  }

  return 1;
}