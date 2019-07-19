#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char sym;
  int opd;
  int icp;
  int isp;
} Token;

Token *stack[10];
int top = 0;

void push(Token *tok) {
  stack[++top] = tok;
}

Token *pop() {
  return stack[top--];
}

char expr[] = "a*(b+c)*d.";
int n=-1;

Token *getToken() {
  Token *tok = (Token*)malloc(sizeof(Token));

  tok->opd = 0;
  tok->sym = expr[++n];

  switch (expr[n])
    {
    case '(' :
      tok->icp = 5;
      tok->isp = 0;
      break;

    case ')' :
      tok->icp = 0;
      tok->isp = 0;
      break;
      
    case '+' :
    case '-' :
      tok->icp = tok->isp = 1;
      break;
      
    case '/' :
    case '*' :
    case '%' :
      tok->icp = tok->isp = 2;
      break;
      
    case '^' :
      tok->icp = 4;
      tok->isp = 3;
      break;

    case '.' :
      tok->icp = -1;
      tok->isp = -1;
      break;

    default:
      tok->opd = 1;
      tok->icp = -1;
      tok->isp = -1;
    }

  return(tok);
}

void postfix() {
  Token *tok = (Token*)malloc(sizeof(Token));

  tok->sym = '.';
  tok->icp = tok->isp = -1;
  stack[top] = tok;

  for (tok = getToken(); tok->sym != '.'; tok = getToken())
    {
      if (tok->opd)
	{
	  printf("%c", tok->sym);
	  continue;
	}

      if (tok->sym == ')')
	{
	  while ((tok = pop())->sym != '(')
	    {
	      printf("%c", tok->sym);
	    }
	  pop();
	}
      else
	{
	  while(stack[top]->isp >= tok->icp)
	    {
	      printf("%c", pop()->sym);
	    }
	  push(tok);
	}
    }
  
  while((tok = pop())->sym != '.')
    {
      printf("%c", tok->sym);
    }
  
  printf("\n");
}

int main() {
  printf("%s\n", expr);
  postfix();
}
