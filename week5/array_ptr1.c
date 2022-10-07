#include <stdio.h>

void print_array(int* p, int len) {
  int i = 0;
  for (i = 0; i < len; i ++) {
  	printf("%d ", p[i]);
  }
  printf("\n");
}

int main() {
  int int_array[100];
  int i = 0;
  for (i = 0; i < 100; i ++) {
    int_array[i] = i;
  }

  int* p;
  p = int_array;
  printf("*p = %d\n", *p);
  p ++;
  printf("*p = %d\n", *p);
  printf("p[0] = %d\n", p[0]);
  printf("p[1] = %d\n", p[1]);

  // error: array type 'int [100]' is not assignable
  // int_array = p;

  print_array(int_array, 10);

  /*
  for (i = 0; i < 100; i ++) {
  	p ++;
  	printf("*p = %d\n", *p);
  }
  */

  return 0;
}