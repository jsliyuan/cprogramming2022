#include <stdio.h>

int main() {
  int n, first, second;
  printf("Enter n (>=2): "); 
  scanf("%d", &n);
  if (n < 2) return 0;

  printf("Enter the first number: ");
  scanf("%d", &first);
  printf("Enter the second number：");
  scanf("%d", &second);

  int max1, max2, x, i;
  if (first < second) {
    max1 = second;
    max2 = first;
  } else {
    max1 = first;
    max2 = second;
  }

  for(i = 3; i <= n; i++) {  
    printf("Enter the %dth number: ", i);
    scanf("%d", &x);
    if (x > max1) {
      max2 = max1; max1 = x;
    } else if (x > max2) {
      max2 = x;
    }
  }
  printf("The second largest number is %d\n", max2);

  return 0;
}
