#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Buble sort takes about 3.96 sec.
#define MAX_N 50000

// Given an array of size n, sort the array in increasing
// order using bubble sort.
void bubble_sort(int* list, int n) {
  int i, j;
  int tmp;
  for (i = 0; i < n-1; i ++) {
  	for (j = n-1; j > i; j --) {
  	  if (list[j] < list[j-1]) {
  	  	tmp = list[j];
  	  	list[j] = list[j-1];
  	  	list[j-1] = tmp;
  	  }
  	}
  }
}

// Given an array of size n, sort the array in increasing
// order using bubble sort.
void bubble_sort_optimized(int* list, int n) {
  int i, j;
  int tmp;
  for (i = 0; i < n-1; i ++) {
  	int flag = 0;
  	for (j = n-1; j > i; j --) {
  	  if (list[j] < list[j-1]) {
  	  	tmp = list[j];
  	  	list[j] = list[j-1];
  	  	list[j-1] = tmp;
  	  	flag = 1;
  	  }
  	}
  	if (flag == 0) {
  	  break;
  	}
  }
}

// Given an array of size n, sort the array in increasing
// order using bubble sort.
void bubble_sort_optimized_v2(int* list, int n) {
  int i, j, k;
  int tmp;
  i = 0;
  while (i < n) {
  	int flag = 0;
  	for (j = n-1; j > i; j --) {
  	  if (list[j] < list[j-1]) {
  	  	tmp = list[j];
  	  	list[j] = list[j-1];
  	  	list[j-1] = tmp;
  	  	k = j;
        flag = 1;
  	  }
  	}
  	i = k;
    if (flag == 0) {
      break;
    }
  }
}

int main() {
  /*
  int list[] = {3, 0, 1, 0, 8, 11, 9, 4};
  //bubble_sort(list, 8);
  //bubble_sort_optimized(list, 8);
  bubble_sort_optimized_v2(list, 8);
  */

  clock_t start, end;
  double cpu_time_used;

  int list1[MAX_N];
  int list2[MAX_N];
  int list3[MAX_N];
  for (int i = 0; i < MAX_N; i ++) {
    list1[i] = rand();
    list2[i] = list3[i] = rand();
  }

  start = clock();
  bubble_sort_optimized(list2, MAX_N);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("bubble_sort_optimized takes %.2lf seconds.\n", cpu_time_used);

  start = clock();
  bubble_sort(list1, MAX_N);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("bubble_sort takes %.2lf seconds.\n", cpu_time_used);

  start = clock();
  bubble_sort_optimized_v2(list3, MAX_N);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("bubble_sort_optimized_v2 takes %.2lf seconds.\n", cpu_time_used);

  /*
  int i;
  for (i = 0; i < 8; i ++) {
  	printf("list[%d] = %d\n", i, list[i]);
  }
  */
  return 1;
}