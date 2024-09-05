#include<stdio.h>

int main()
{
  int temp, a, b;

  printf("Enter a, b:");
  scanf("%d %d", &a, &b);

  temp = b;
  b = a;
  a = temp;

  printf("a=%d\nb=%d", a. b");
  return 0;
}
