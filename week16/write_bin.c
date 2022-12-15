#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  FILE *fptr;

  if ((fptr = fopen("data.bin","wb")) == NULL){
    printf("Error! opening file");

    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  int num = 314;
  fwrite(&num, sizeof(int), 1, fptr);
  fclose(fptr); 
  
  return 0;
}