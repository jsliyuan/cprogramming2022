#include <stdio.h>

// Insert a new element val at position idx, and increase *len by one.
// Assume array list[] has length at least len + 1.
void insert_array(int* list, int* len, int idx, int val) {
  int i;
  for (i = (*len) - 1; i >= idx; i--) { 
    list[i+1] = list[i];
  }

  list[idx] = val;
  (*len) ++;
}

int main() {
  int prime[] = {2, 5, 7, 11, 0, 0};
  int len = 4;
  insert_array(prime, &len, 1, 3);

  int i = 0;
  for (i = 0; i < len; i ++) {
    printf("prime[%d] = %d\n", i, prime[i]);
  }

  return 0;
}