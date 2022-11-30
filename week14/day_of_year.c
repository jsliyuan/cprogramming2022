#include  <stdio.h>

int dayTable[ ][12]={
  {31,28,31,30,31,30,31,31,30,31,30,31}, /* 平年 */
  {31,29,31,30,31,30,31,31,30,31,30,31}};/* 闰年 */

struct Date	{
  int  day;
  int  month;
  int  year;
  int  yearDay;
} date; /* 定义一个Date结构类型的结构变量 */ 

/* 计算年中第几天函数 */
void dayofYear(struct Date* date) {
  int i, leap;
  date->yearDay = date->day;
  leap = (date->year%4 == 0 && date->year%100) || date->year%400 == 0; /* 是否闰年 */
  for (i = 0; i < date->month - 1; i++)
     date->yearDay += dayTable[leap][i];
}

int main() {
  int leap, days;
  printf("\tDate Conversion Program\n");
  printf("Year = ");
  scanf("%d", &date.year); /* 输入年份 */
  for (; ;)  {
    printf("Month = ");   scanf("%d", &date.month);
    if (date.month >= 1 && date.month <= 12)
      break;
    printf("输入的月份必须在 1 到 12 之间\n" );
  }

  /* leap=1是闰年，leap=0 不是闰年 */
  leap = (date.year%4 == 0&&date.year%100)||date.year%400==0;
  days = dayTable[leap][date.month-1];
   /* 输入日期，并检查是否输入正确 */
  for (; ;) {
    printf("Day = ");
    scanf("%d", &date.day);
    if (date.day >= 1 && date.day <= days)
      break; 
    printf("输入的天必须在 1 到 %d 之间\n",days);
  }

  /* 调用dateofYear函数，实参为结构date的3个成员 */
  dayofYear(&date);
  printf("The days of the year are: %d\n",date.yearDay);

  return 0;
}
