#include  <stdio.h>

void main()
{
  int sum, count, score;
  sum = 0;
  count = 0;
  while (1) {
    printf("Input a score (if negative, exit)\n");
    scanf("%d", &score);
    if (score < 0)
      break;
    sum += score;
    count++; 
  }
  if(count)
    printf("Average score is %.2f\n", ((float) sum) / count);
  else
    printf("No data.\n");
}
