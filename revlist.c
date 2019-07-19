#include <stdio.h>
#include <stdlib.h>

struct node {
  int n;
  struct node *next;
};

typedef struct node *Node;

Node h = NULL;

void insert(int n)
{
  Node q = (Node)malloc(sizeof(struct node));

  q->n = n;
  q->next = NULL;
  
  if (h == NULL)
    {
      h = q;
      return;
    }
  
  q->next = h;
  h = q;
}

void display(Node h)
{
  Node q = h;
  while (q != NULL)
    {
      printf("q->n = %d\n", q->n);
      q = q->next;
    }
}

Node reverse(Node q){
    if(q->next == NULL){
        return q;
    }

    Node h = reverse(q->next);
    q->next->next = q;
    q->next = NULL;

    return h;
}

int main()
{
  insert(3);
  insert(2);
  insert(1);

  display(h);
  h = reverse(h);

  display(h);
}
     
