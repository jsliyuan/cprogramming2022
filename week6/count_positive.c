#include <stdio.h>

// Given an array of length len, count the number of
// positive, negative numbers, and zeros.
void count_positive(int* list, int len, int* positive, int* negative, int* zero) {
  *positive = 0;
  *negative = 0;
  *zero = 0;

  int i = 0;
  for (i = 0; i < len; i ++) {
    if (list[i] > 0) {
      (*positive) ++;
    }
    if (list[i] < 0) {
      (*negative) ++;
    }
    if (list[i] == 0) {
      (*zero) ++;
    }
  }
}

int main() {
  // Full initialization using {}
  int test_array[] = {0, 2, -1, 3, 5, 0};
  int pos, neg, zero;
  count_positive(test_array, 6, &pos, &neg, &zero);

  printf("positive = %d\n", pos);
  printf("negative = %d\n", neg);
  printf("zero = %d\n", zero);

  return 0;
}