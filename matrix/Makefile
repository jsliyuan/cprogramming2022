CC = g++
TO_TARGET = -c
CFLAGS = -Wall

matrix.o: matrix.cpp matrix.h
	$(CC) $(TO_TARGET) $(CFLAGS) matrix.cpp

test_matrix.out: test_matrix.cpp matrix.o
	$(CC) $(CFLAGS) test_matrix.cpp matrix.o -o test_matrix.out

clean:
	rm -f *.o *.a

all: matrix.o test_matrix.out

.PHONY: clean