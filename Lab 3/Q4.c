#include<stdio.h>

int main()
{
  float distance, fuel_price_a, fuel_price_b, fuel_avg;

  printf("Enter distance (one trip), fuel price from a to b, fuel price from b to a, fuel avg:");
  scanf("%f %f %f %f", &distance, &fuel_price_a, &fuel_price_b, &fuel_avg);

  if (distance < 0 || fuel_price_a < 0 || fuel_price_b < 0 || fuel_avg < 0)
  {
    // values toh positive daalo, bhai
    printf("Values must be positive");
    return 1;
  }
  
  float number_of_litres = distance/fuel_avg; // one trip
  float total_price_a = fuel_price_a * (number_of_litres);
  float total_price_b = fuel_price_b * (number_of_litres);
  
  float total_price = total_price_a + total_price_b;
  float total_fuel = 2 * number_of_litres;

  printf("Total Price: %f\nTotal Fuel: %f", total_price, total_fuel);

  return 0;
}
