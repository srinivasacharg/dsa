#include <stdio.h>

typedef struct
{
  int date;
  int month;
  int year;
} DOJ;

typedef struct
{
  int basic;
  int da;
  int hra;
} Sal;

typedef struct
{
  int empid;
  DOJ doj;
  Sal sal;
}Employee;

int main()
{
  Employee emp[5];

  for (int i= 0; i < 5; i++)
    {
      printf("Enter Empid:");
      scanf("%d", &emp[i].empid);

      printf("DOJ:");
      scanf("%d,%d,%d", &emp[i].doj.date, &emp[i].doj.month, &emp[i].doj.year);

      printf("Salary:");
      scanf("%d,%d,%d", &emp[i].sal.basic, &emp[i].sal.da, &emp[i].sal.hra);
    }

  for (int i= 0; i < 5; i++)
    {
      printf("%d\n", emp[i].empid);
      printf("DOJ: %d,%d,%d\n", emp[i].doj.date, emp[i].doj.month, emp[i].doj.year);

      printf("Salary:");
      printf("Salary: %d,%d,%d\n", emp[i].sal.basic, emp[i].sal.da, emp[i].sal.hra);
    }
}

