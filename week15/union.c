#include <stdio.h>

union Data {
  int ival;
  char chval;
  float fval;
};

int main() {
  Data x;
  x.ival = 1;
  x.chval = 'a';
  x.fval = 3.00;

  printf("x.ival = %d\n", x.ival);
  printf("x.chval = %d\n", x.chval);
  printf("x.fval = %f\n", x.fval);
  printf("sizeof(x) = %d\n", sizeof(x));

  return 0;
}
