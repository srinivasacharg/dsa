#include <stdio.h>
#include <stdlib.h>

int main() {

  int row = 4;
  int (*p)[] = (int(*)[])malloc(row*sizeof(int));

  printf("1d Array\n");

  for (int i=0; i < row; i++)
    {
      (*p)[i] = i;
      printf("*p[%d] = %d, %x\n", i, (*p)[i], &(*p)[i]);
    }

  printf("2d Array\n");

  int col=3;
  int (*pb)[][col] = (int(*)[][1])malloc(row*col*sizeof(int));

  for (int i=0; i < row; i++)
    {
      for (int j=0; j < col; j++)
	{
	  (*pb)[i][j] = i+j;
	  printf("(*pb)[%d][%d] = %d, %x\n", i, j, (*pb)[i][j], &(*pb)[i][j]);
	}
    }
}
