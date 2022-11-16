#include <stdio.h>
#include "format.h"

int main( )
{
   float x, y, z;
   x = 1.2; y = 2.3; z = 3.4;
   PR(F1, x);       
   PR(F2, x, y);
   PR(F3,x, y, z);
   return 0;
}
