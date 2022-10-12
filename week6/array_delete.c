#include <stdio.h>

// Delete the element at index idx in the array list[].
// Decrease the length *len by one.
void array_delete(int* list, int* len, int idx) {
  int i;
  for (i = idx+1; i < *len; i++) {
    list[i-1] = list[i];
  }
  (*len) --;
}

int main() {
  int number[] = {1, 6, 3, 4, 9};
  int len = 5;
  array_delete(number, &len, 2);

  int i = 0;
  for (i = 0; i < len; i ++) {
    printf("number[%d] = %d\n", i, number[i]);
  }

  return 0;
}