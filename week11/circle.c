#include <stdio.h>
#define  PI  3.141592653
#define  AREA(R)  PI * (R) * (R)
#define  PERI(R)  2 * PI * (R)

int main() {
  int r;
  for(r = 2; r <= 10; r += 2)
  { printf("Diameter = %2d，area = %f\t", r, AREA(r));
    printf("Perimeter = %f\n", PERI(r));
  }
}
