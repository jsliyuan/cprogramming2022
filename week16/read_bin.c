#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  FILE *fptr;

  if ((fptr = fopen("a.exe","rb")) == NULL) {
    printf("Error! opening file");

    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  int num;
  fread(&num, sizeof(int), 1, fptr);
  printf("num = %x\n", num);
  fclose(fptr); 
  
  return 0;
}