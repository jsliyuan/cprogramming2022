#include <stdio.h>

// Given a score in [0, 100], returns a grade in
// {'A', 'B', 'C', 'D', 'F'}.
// A: 90 - 100
// B: 80 - 89
// C: 70 - 79
// D: 60 - 69
// F: 0 - 59
char get_grade(int score) {
  if (score >= 90)
  	return 'A';
  if (score >= 80)
  	return 'B';
  if (score >= 70)
  	return 'C';
  if (score >= 60)
  	return 'D';
  return 'F';
}

int main() {
  printf("the grade of 95 is %c\n", get_grade(95));
  printf("the grade of 0 is %c\n", get_grade(0));

  return 0;
}