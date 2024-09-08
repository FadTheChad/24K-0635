#include <stdio.h>

int main()
{
  float x1 = 5, y1 = 4, x2 = 3, y2 = 2;
  float m = (y2 - y1) / (x2 - x1); // 'm' is used for slopes

  printf("Slope: %.3f", m);
  return 0;
}
