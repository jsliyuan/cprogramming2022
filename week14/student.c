#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ADDR_LEN 40

struct Date {        /* 说明一个日期 */
  int  day;          /* 日 */
  int  month;        /* 月 */
  int  year;         /* 年 */
};

struct  student {
  int  number;
  char name[MAX_NAME_LEN];
  char gender;
  char address[MAX_ADDR_LEN];
  struct Date birthday;
};

int main() {
  struct student alice;
  alice.number = 123;
  strncpy(alice.name, "Alice Drucker", MAX_NAME_LEN);
  alice.gender = 'm';
  alice.birthday.day = 1;
  alice.birthday.month = 1;
  alice.birthday.year = 2000;

  // C++ style
  struct student Bob;
  Bob = {1005, "Bob Li", 'm', "Handan Road", {2, 1, 2001}};

  return 0;
}