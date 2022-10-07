#include <stdio.h>

void copy_str(char* src, char* dst) {
  while ((*dst ++ = *src++))
  	;
  /*
  int i = 0;
  while (src[i] != 0) {
  	dst[i] = src[i];
  	i ++;
  }
  */
}

void copy_str_maxlen(char* src, char* dst, int max_len) {
  int i = 0;
  for (i = 0; i < max_len; i ++) {
  	dst[i] = src[i];
  	if (src[i] == 0) {
  	  break;
  	}
  }
}

int main() {
  char src[100], dst[100];
  scanf("%s", src);
  // copy_str(src, dst);
  copy_str_maxlen(src, dst, 100);

  printf("dst=%s\n", dst);

  return 0;
}