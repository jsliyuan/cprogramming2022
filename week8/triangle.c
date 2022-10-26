#include <stdio.h>
#include <math.h>

// Given the length of 3 sides, decide if they can
// form a triangle.
int is_triangle(float a, float b, float c) {
  if (a+b <= c || a+c <= b || b+c <= a)
    return 0;

  if (a <= 0 || b <= 0 || c <= 0)
    return 0;

  return 1;
}

// Given the length of 3 sides, returns the area of
// the triangle.
// Returns 0 if they cannot form a triangle.
float triangle_area(float a, float b, float c)
{
  float s, area; 	
  if (is_triangle(a, b, c) == 0)
    return 0;

  s = (a+b+c) / 2;
  area = sqrt(s*(s-a)*(s-b)*(s-c));
  return area;
}

int main() {
  float a, b, c, area;

  do {
    printf("Enter a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    area = triangle_area(a, b, c);
    if (area == 0)
      printf("Wrong data. They cannot form a triangle.\n");
  } while(area == 0);

  printf("The area of the triangle is: %f\n", area);
  return 0;
}
