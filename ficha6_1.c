#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack {
  int sp;
  int valores[MAX];
} STACK;

void initStack (STACK *s)
{
  s->sp = 0;
}

int isEmptyS (STACK *s)
{
  return (s->sp == 0);
}

int push (STACK *s, int x)
{
  if(s->sp == MAX-1)
    return 1;
  else {s->valores[s->sp++] = x;
       return 0;}
}

void printStack(STACK *s)
{
  for(int i = (s->sp)-1; i>=0; i--)
    printf("%d\n", s->valores[i]);
}

int pop (STACK *s, int *x)
{
  if(isEmptyS(s)) return 1;
  else {
    *x = s->valores[s->sp-1];
    s->sp--;
    return 0; }
}

int top (STACK *s, int *x)
{
  if(isEmptyS(s)) return 1;
  else {
    *x = s->valores[s->sp-1];
    return 0; }
}

int main()
{
  STACK st;
  int x;

  initStack(&st);
  printf("Empty?%s\n", isEmptyS(&st) ? "true" : "false");
  scanf("%d",&x);
  push(&st,x);
  printf("Empty?%s\n", isEmptyS(&st) ? "true" : "false");
  printStack(&st);


  return 0;
}
