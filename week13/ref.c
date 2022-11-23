#include <stdio.h>

int main() {
  int a[] = {0, 2, 4, 6, 8};
  int j;
  printf("Enter j  ");
  scanf("%d", &j);
  int &ref = a[j];
  ref = 44;
  printf("ref=%d\n", ref);
  printf("a[j]=%d\n", a[j]);
  
  return 0;
}
