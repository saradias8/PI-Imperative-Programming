#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct stack {
  int size; //tamanho do array
  int sp;
  int *valores;
} STACK;

void initStack(STACK *s)
{
  s->sp = 0;
  s->size = 3;
  s->valores = (int*) malloc(sizeof(int)*s->size);
}

int isEmptyS(STACK *s)
{
  return (s->sp == 0);
}

void push(STACK *s, int x)
{
  STACK newStack;

  if(s->sp >= s->size){
    int *newStack = (int*) malloc(sizeof(int)*2*s->size);
    for(int i = 0;i< s->sp; i++)
      newStack[i] = s->valores[i];
    newStack[s->sp++] = x;
    free(s->valores);
    s->valores = newStack;
    s->size *= 2;
    }
  else {s->valores[s->sp++] = x;}
}

void printStack(STACK *s)
{
  for(int i = (s->sp)-1; i>=0; i--)
    printf("%d\n", s->valores[i]);
}


int main()
{
  STACK st;

  int x,y,z;

  initStack(&st);
  printf("Empty?%s\n", isEmptyS(&st) ? "true" : "false");
  scanf("%d",&x);
  scanf("%d",&y);
  scanf("%d",&z);
  push(&st,x);
  push(&st,y);
  push(&st,z);
  printf("Empty? %s\n", isEmptyS(&st) ? "true" : "false");
  printStack(&st);

  return 0;
}
