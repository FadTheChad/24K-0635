#include <stdio.h>

int main()
{
	float t_cal, f_gm;
	
	printf("Enter total calories, fat gram: ");
	scanf("%f %f", &t_cal, &f_gm);
	
	if (t_cal <= 0 || f_gm <= 0)
	{
		printf("Values should be positive");
		return 0;
	}	

	float cal_from_fat = f_gm * 9;
	
	if (cal_from_fat > t_cal)
	{
		printf("Calories from fat cannot be greater from total calories");
		return 0;
	}
	
	float prcnt_cal = cal_from_fat / t_cal;
	
	printf("Percentage: %.2f\%", prcnt_cal * 100);

	return 0;
}
