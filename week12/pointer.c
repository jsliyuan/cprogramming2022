#include <stdio.h>
int main() {
  int k;
  int *kPtr;
  k = 7;
  kPtr = &k;

  printf("address of k is %x\n", &k);
  printf("kPtr = %x\n", kPtr);

  printf("k = %d\n", k);
  printf("*kPtr = %d\n", *kPtr);

  printf("&*kPtr=%x\n", &*kPtr);
  printf("*&kPtr =%x\n", *&kPtr);
  return 0;
}
