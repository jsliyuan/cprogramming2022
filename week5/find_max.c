#include <stdio.h>

int main() {
  int n, i, max, x, index;
  printf("Input n.\n"); 
  scanf("%d", &n);

  for(i = 1; i <= n; i++) {
    printf("Input the %dth number ", i); 
    scanf("%d", &x);
    if (i == 1) { // The first number
      max = x;
      index = 1;
      continue; 
    }
    if (x > max) {
      max = x; 
      index = i;
    }
  }

  printf("The max is %d，which is the %dth number.\n", max, index);
  return 0;
}
