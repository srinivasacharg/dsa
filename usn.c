#include <stdio.h>

typedef struct
{
  char *region;
  char *code;
  char *scheme;
  char *student;
}Components;

union USN {
  int isid; 
  char *id;
  Components components;
};

union USN usn;

int main()
{
  usn.isid = 1;
  usn.id = "1AT18CS100";

  printf("usn = %s\n", usn.id);
  printf("\n");
  
  usn.isid = 1;
  Components *p = &usn.components;

  p->region = "1";
  p->code = "AT";
  p->scheme = "18";
  p->student = "100";

  printf("region = %s\n", p->region);
  printf("code = %s\n", p->code);
  printf("scheme = %s\n", p->scheme);
  printf("student = %s\n", p->student);
  printf("\n");
  
  printf("usn = %s\n", usn.id);
}
