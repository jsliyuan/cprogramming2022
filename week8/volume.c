#include <stdio.h>

// Given the radius and height of a cylinder, returns
// its volume.
double volume(double radius, double height) {
  const double PI = 3.1415926;
  double vol = PI * radius * radius * height;
  return vol;
}


int main() {
  double radius, height, vol;
  printf("Input the radius and height of the cylinder: ");
  scanf("%lf%lf", &radius, &height);

  vol = volume(radius, height);
  printf("The volume of the cylinder is %f\n", vol);
  return 0;
}
