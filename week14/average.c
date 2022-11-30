#include <stdio.h>

struct student_score {
  char name[20];
  int chinese;
  int math;
  double average;
};

void input_score(struct student_score* p) {
  scanf("%s%d%d", p->name, &p->chinese, &p->math);
  p->average = (p->chinese + p->math) / 2.0;
}

int main() {
  struct student_score students[3];
  for (int i = 0; i < 3; i ++) {
  	input_score(&students[i]);
  }

  printf("Name\tChinese\tMath\tAverage\n"); 
  for (int i = 0; i < 3; i ++) {
    printf("%s\t%4d\t%4d\t%6.2f\n",
      students[i].name, students[i].chinese,
      students[i].math, students[i].average); 
  }

  return 0;
}
