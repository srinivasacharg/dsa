#include <stdio.h>

void reverse(char str[])
{
  char rev[10];
  int k;

  // length k
  for(int i=0; str[i] != '\0'; i++)
  {
    k = i;
  }

  for(int i=0, j=k; j >= 0; j--)
    {
      rev[i++] = str[j];
      rev[i] ='\0';
    }
  printf("The reverse string is %s\n", rev);
}

void concat(char p[], char q[])
{
  char s[10];
  int k;

  // length k
  for(int i=0; p[i] != '\0'; i++)
  {
    k = i;
    s[i] = p[i];
  }

  printf("p=%s, q=%s, k=%d", p, q, k);
  k++;
  for(int i=0; q[i] != '\0'; i++)
    {
      s[k++] = q[i];
      s[k] ='\0';
    }
  printf("The concated string is %s\n", s);
}

int main()
{
  reverse("1234");
  concat("abc", "123");
}
