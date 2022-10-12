#include <stdio.h>

// Given an array of size n, sort the array in increasing
// order using selection sort.
void selection_sort(int* list, int n) {
  int i, j;
  int tmp;
  for (i = 0; i < n; i ++) {
  	for (j = i + 1; j < n; j ++) {
  	  if (list[i] > list[j]) {
  	  	tmp = list[i];
  	  	list[i] = list[j];
  	  	list[j] = tmp;
  	  }
  	}
  }
}

int main() {
  int list[] = {3, 0, 1, 0, 8, 11, 9, 4};
  selection_sort(list, 8);

  int i;
  for (i = 0; i < 8; i ++) {
  	printf("list[%d] = %d\n", i, list[i]);
  }
  return 1;
}