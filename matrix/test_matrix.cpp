#include <iostream>
#include <assert.h>
#include <time.h>

#include "matrix.h"

//#define DEBUG

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void TestCreateMatrix1by1() {
  int entries[] = {2};
  matrix_type A = create_matrix(1, 1, entries);
  assert(A.m == 1);
  assert(A.n == 1);
  assert(A.mat[0][0] == 2);
  cout << __func__ << " test passed\n";
}

void TestCreateMatrix2by3() {
  int entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, entries);
  assert(A.m == 2);
  assert(A.n == 3);
  for (int i = 0; i < 2; i ++) {
  	for (int j = 0; j < 3; j ++) {
  	  assert(A.mat[i][j] == i*3 + j + 1);
	}
  }
  cout << __func__ << " test passed\n";
}

void TestCreateMatrix2by3Null() {
  matrix_type A = create_matrix(2, 3, NULL);
  assert(A.m == 2);
  assert(A.n == 3);
  for (int i = 0; i < 2; i ++) {
  	for (int j = 0; j < 3; j ++) {
  	  assert(A.mat[i][j] == 0);
	}
  }
  cout << __func__ << " test passed\n";
}

void TestCreateMatrixSizeExceeded() {
  // Expect to see an error message.
  cout << "Expect to see an error message." << endl;
  matrix_type A = create_matrix(MAX_MATRIX_SIZE+1, MAX_MATRIX_SIZE, NULL);
  assert(A.m == 0);
  assert(A.n == 0);
  assert(A.mat == NULL);
  cout << __func__ << " test passed\n";
}

void TestCreateMatrixLargeDimension() {
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  matrix_type A = create_matrix(MAX_MATRIX_SIZE, MAX_MATRIX_SIZE, NULL);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("time used (sec): %.2lf\n", cpu_time_used);
  assert(A.m == MAX_MATRIX_SIZE);
  assert(A.n == MAX_MATRIX_SIZE);
  for (int i = 0; i < MAX_MATRIX_SIZE; i ++) {
  	for (int j = 0; j < MAX_MATRIX_SIZE; j ++) {
  	  assert(A.mat[i][j] == 0);
	  }
  }
  cout << __func__ << " test passed\n";
}

void TestDetertminant() {
  int entries[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matrix_type A = create_matrix(3, 3, entries);
  double det = determinant(A);
  assert(det == 0);
  int entries2[] = {1, 3, 4, 5, 2, 9, 1, 1, 4};
  matrix_type B = create_matrix(3, 3, entries2);
  det = determinant(B);
  assert(det == -22);
  cout << __func__ << " test passed\n";
}

int main(int argc, char** argv) {
	TestCreateMatrix1by1();
	TestCreateMatrix2by3();
	TestCreateMatrix2by3Null();
	TestCreateMatrixSizeExceeded();
	TestCreateMatrixLargeDimension();
  TestDetertminant();

	return 0;
}
