#include <stdio.h>

int a[6][6] = {
  {15, 0, 0, 22, 0, -15},
  {0, 11, 3, 0, 0, 0},
  {0, 0, 0, -6, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {91, 0, 0, 0, 0, 0},
  {0, 0, 28, -6, 0, 0}
};

int b[10][3], k=0, n = 0;

int main()
{
  for (int i=0; i < 6; i++)
    {
      for (int j=0; j < 6; j++)
	{
	  if (a[i][j] != 0)
	    {
	      n++;
	      k++;
	      b[k][0] = i;
	      b[k][1] = j;
	      b[k][2] = a[i][j];
	    }
	}
    }

  b[0][0] = 6;
  b[0][1] = 6;
  b[0][2] = n-1;

  for (int i=0; i < k; i++)
    {
      printf("%2d %2d %2d\n", b[i][0], b[i][1], b[i][2]);
    }

  printf("\n");

  /* Transpose */
  printf("Transpose.\n");
  int c[n][3];

  c[0][0] = b[0][0];
  c[0][1] = b[0][1];
  c[0][2] = b[0][2];

  int m = 0;
  for (int j=0; j < 6; j++)
    {
      for (int i=1; i <= b[0][2]; i++)
	{
	  if (b[i][1] == j)
	    {
	      printf("i=%d, j=%d, b[i][1]=%d\n", i, j, b[i][1]);
	      m++;
	      c[m][0] = b[i][1];
	      c[m][1] = b[i][0];
	      c[m][2] = b[i][2];
	    }
	}
    }

  for (int i=0; i < n; i++)
    {
      printf("%2d %2d %2d\n", b[i][0], b[i][1], b[i][2]);
    }
}
