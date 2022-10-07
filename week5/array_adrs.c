#include <stdio.h>
int main() {
   char x[4];
   // int x[4];
   int i;

   for(i = 0; i < 4; ++i) {
      printf("&x[%d] = %p\n", i, &x[i]);
   }

   printf("Address of array x: %p\n", x);

   return 0;
}
