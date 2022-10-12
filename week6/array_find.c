#include <stdio.h>

// Find the key in the array list[] of length n.
// If not found, return -1.
int array_find(int* list, int n, int key) {
  int i;
  for (i = 0; i < n; i ++) {
    if (list[i] == key) {
      return i;
    }
  }

  return -1;
}

// Using binary search to find the key in the array
// list[] of length n.
// If not found, return -1.
int binary_search(int* list, int n, int key) {
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (list[mid] == key) {
      return mid;
    }
    if (list[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int prime[] = {2, 3, 5, 7, 11, 13, 17};
  printf("find(%d) = %d\n", 3, array_find(prime, 7, 3));
  printf("find(%d) = %d\n", 2, array_find(prime, 7, 2));
  printf("find(%d) = %d\n", 17, array_find(prime, 7, 17));
  printf("find(%d) = %d\n", 6, array_find(prime, 7, 6));

  printf("binary_search(%d) = %d\n", 3, binary_search(prime, 7, 3));
  printf("binary_search(%d) = %d\n", 2, binary_search(prime, 7, 2));
  printf("binary_search(%d) = %d\n", 17, binary_search(prime, 7, 17));
  printf("binary_search(%d) = %d\n", 6, binary_search(prime, 7, 6));
  return 0;
}