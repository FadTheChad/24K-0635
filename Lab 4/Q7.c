#include <stdio.h>

int main()
{
  int c_id;
  int unit;
  char name[50];

  printf("Customer ID: ");
  scanf("%d", &c_id);

  printf("Enter unit: ");
  scanf("%d", &unit);

  if (unit < 0)
  {
    print("How is negative units even possible...");
    return 0;
  }
  
  printf("Enter name: ");
  scanf("%s", &name);

  float charges, bill;

  // K-Electric mai apka khush amdeed
  if (unit < 200) charges = 16.20;
  else if (unit < 300) charges = 20.10;
  else if (unit < 500) charges = 27.10;
  else charges = 35.90;

  bill = charges * unit;

  if (unit > 18000)
    bill *= (1 + 0.15);

  printf("Your bill is: %f", &bill);

  return 0;
}
