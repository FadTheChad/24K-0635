#include <stdio.h>

int main()
{
  float principal, rate, time;

  printf("Enter principal (100 - 1,000,000), rate (in %, 5-10), time (yrs, 1-10): ");
  scanf("%f %f %f", &principal, &rate, &time);

  if (principal > 1000000 || principal < 100)
  {
    printf("Principal is out of range");
    return 1;
  }

  if (rate > 10 || rate < 5)
  {
    printf("Rate is out of range");
    return 1;
  }

  if (time > 10 || time < 1)
  {
    printf("Time is out of range");
    return 1;
  }

  // أستغفر اللّٰه
  float interest = principal * (rate / 100) * time;
  float total = principal + interest;

  printf("Interest: %f\nAmount after interest: %f", interest, total);
  return 0;
}
