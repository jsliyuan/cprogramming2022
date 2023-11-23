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

void TestMatricesEqual2by3() {
  int A_entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, A_entries);
  int B_entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type B = create_matrix(2, 3, B_entries);
  assert(matrices_equal(A, B));
  cout << __func__ << " test passed\n";
}

void TestMatricesEqualDimensionNotMatch() {
  int A_entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, A_entries);
  int B_entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type B = create_matrix(3, 2, B_entries);
  assert(!matrices_equal(A, B));
}

void TestMultiplyMatrixByScalar() {
  int entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, entries);
  matrix_type B = multiply_matrix_by_scalar(A, 2);
  assert(B.m == 2);
  assert(B.n == 3);
  for (int i = 0; i < 2; i ++) {
  	for (int j = 0; j < 3; j ++) {
  	  assert(B.mat[i][j] == (i*3 + j + 1)*2);
    }
  }
  cout << __func__ << " test passed\n";
}

void TestTransposeMatrix() {
  int entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, entries);
  matrix_type B = transpose_matrix(A);
  assert(B.m == 3);
  assert(B.n == 2);
  for (int i = 0; i < 3; i ++) {
  	for (int j = 0; j < 2; j ++) {
  	  assert(B.mat[i][j] == entries[j*3 + i]);
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

void TestAddMatrices2by3() {
  int A_entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, A_entries);
  int B_entries[] = {1, 0, 1, 0, 2, 2};
  matrix_type B = create_matrix(2, 3, B_entries);
  matrix_type C = add_matrices(A, B);
  assert(C.m == 2);
  assert(C.n == 3);
  assert(C.mat[0][0] == 2);
  assert(C.mat[0][1] == 2);
  assert(C.mat[0][2] == 4);
  assert(C.mat[1][0] == 4);
  assert(C.mat[1][1] == 7);
  assert(C.mat[1][2] == 8);
  cout << __func__ << " test passed\n";
}

void TestMultiplyMatrices2by3And3by2() {
  int A_entries[] = {1, 2, 3, 4, 5, 6};
  matrix_type A = create_matrix(2, 3, A_entries);
  int B_entries[] = {1, 2, 3, 3, 2, 1};
  matrix_type B = create_matrix(3, 2, B_entries);
  matrix_type C = multiply_matrices(A, B);
  assert(C.m == 2);
  assert(C.n == 2);
  assert(C.mat[0][0] == 13);
  assert(C.mat[0][1] == 11);
  assert(C.mat[1][0] == 31);
  assert(C.mat[1][1] == 29);
  cout << __func__ << " test passed\n";
}

// (A+B)*C = A*C + B*C
void TestMultiplyMatricesAddThenMultiply() {
  clock_t start, end;
  double cpu_time_used;
  start = clock();

  matrix_type A = create_random_matrix(MAX_MATRIX_SIZE, MAX_MATRIX_SIZE, -1, 1);
  matrix_type B = create_random_matrix(MAX_MATRIX_SIZE, MAX_MATRIX_SIZE, -1, 1);
  matrix_type C = create_random_matrix(MAX_MATRIX_SIZE, MAX_MATRIX_SIZE, -1, 1);
  matrix_type A_plus_B = add_matrices(A, B);
  matrix_type result1 = multiply_matrices(A_plus_B, C);

  matrix_type AC = multiply_matrices(A, C);
  matrix_type BC = multiply_matrices(B, C);
  matrix_type result2 = add_matrices(AC, BC);

  assert(matrices_equal(result1, result2));
  cout << __func__ << " test passed\n";
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("time used (sec): %.2lf\n", cpu_time_used);
}

int main(int argc, char** argv) {
	TestCreateMatrix1by1();
	TestCreateMatrix2by3();
	TestCreateMatrix2by3Null();
	TestCreateMatrixSizeExceeded();
	TestCreateMatrixLargeDimension();

  TestMatricesEqual2by3();
  TestMatricesEqualDimensionNotMatch();

  TestMultiplyMatrixByScalar();
  TestTransposeMatrix();
  TestDetertminant();
  TestAddMatrices2by3();

  TestMultiplyMatrices2by3And3by2();
  TestMultiplyMatricesAddThenMultiply();

	return 0;
}
