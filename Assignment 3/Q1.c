#include <stdio.h>
#include <string.h>

typedef struct
{
  int d;
  int m;
  int y;
} Date;

typedef struct 
{
  int employeeCode;
  char employeeName[100];
  Date dateOfJoining;
} Employee;

void assignEmployee(Employee *e)
{
  printf("\nCode: ");
  scanf("%d", &e->employeeCode);
  
  printf("\nName: ");
  scanf("%s", e->employeeName);
  
  printf("\nDate: ");
  scanf("%d %d %d", &e->dateOfJoining.d, &e->dateOfJoining.m, &e->dateOfJoining.y);
}

int checkTenure(Date ed, Date cd, float *tenure)
{
  float eDays = (ed.y * 365.25) 
  + (ed.m * (365.25/12)) 
  + ed.d;
  
  float cDays = (cd.y * 365.25) 
  + (cd.m * (365.25/12)) 
  + cd.d;
  
  *tenure = (cDays - eDays) / 365.25;
  return *tenure >= 3;
}

void getDate(Employee employees[4])
{
  Date cd;
  int count = 0;
  printf("Enter date (d m y): ");
  scanf("%d %d %d", &cd.d, &cd.m, &cd.y);
  
  for (int i = 0; i < 4; i++)
  {
    float tenure;
    if (checkTenure(employees[i].dateOfJoining, cd, &tenure))
    {
      count++;
      printf("\n\nCode: %d\nName: %s\nDate Joined: %d/%d/%d\n",
        employees[i].employeeCode,
        employees[i].employeeName,
        employees[i].dateOfJoining.d,
        employees[i].dateOfJoining.m,
        employees[i].dateOfJoining.y
      );
      printf("Tenure: %f", tenure);
   }
  }
  printf("\n\nTotal: %d\n", count);
}

int main()
{
  Employee employees[4];
  
  for (int i = 0; i < 4; i++)
  {
    assignEmployee(&employees[i]);
  }
  
  getDate(employees);
}
