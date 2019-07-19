#include <stdio.h>
#include <string.h>

typedef struct
{
  int n;
  char *s;
  char a[10];
} Data;

int main()
{
  Data a[10];
  
  a[0].n = 1;
  a[0].s = "a";
  strcpy((char *)a[0].a, "a");
  
  a[1].n = 2;
  a[1].s = "ab";
  strcpy((char *)a[1].a, "ab");
  
  a[2].n = 3;
  a[2].s = "abc";
  strcpy((char *)a[2].a, "abc");
  
  for (int i=0; i < 3; i++)
    {
      printf("a[%d].s = %s, a[%d].a = %s\n", a[i].n, a[i].s, a[i].n, a[i].a);
    }
}
