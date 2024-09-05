#include<stdio.h>

int main()
{
  int salary, tax_rate;

  printf("Enter salary:");
  scanf("%d", &salary);

  printf("Enter tax rate (in % from)", &tax_rate);

  tax_rate = tax_rate / 100;

  int taxed_salary = salary * (1 - tax_rate);

  print("Total tax: %d", salary - taxed_salary);
  printf("Salary after taxes: %d", taxed_salary);

  return 0;
}
