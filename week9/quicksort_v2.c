#include <stdio.h>
#include <stdlib.h>

// Swap two integers.
void swap(int* x, int* y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

// Choosing a random element among list[low], list[low+1], ...
// list[high] as pivot element, and rearrange
// list[low], list[low+1], ..., list[high] such that all
// elements smaller than or equal to the pivot is on the left.
// Returns the index of the pivot element.
int partition(int* list, int low, int high) {
  int mid = low + rand() % (high - low + 1);
  swap(&list[high], &list[mid]);
  int pivot = list[high];
  int i = low - 1;
  for (int j = low; j < high; j ++) {
  	if (list[j] <= pivot) {
  	  i ++;
  	  swap(&list[i], &list[j]);
  	}
  }
  swap(&list[i+1], &list[high]);
  return i + 1;
}

// Sort the elements list[low], list[low+1], ..., list[high] in
// increasing order.
void quicksort(int* list, int low, int high) {
  if (low < high) {
  	int mid = partition(list, low, high);
  	quicksort(list, low, mid - 1);
    quicksort(list, mid + 1, high);
  }
}

int main() {
  int list[] = {2, 0, 9, 5, 11, 29, 1};
  quicksort(list, 0, 6);
  for (int i = 0; i < 7; i ++) {
  	printf("%d ", list[i]);
  }
  printf("\n");
  return 0;
}