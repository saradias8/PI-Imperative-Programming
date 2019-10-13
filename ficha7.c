#include <stdio.h>
#include <stdlib.h>

typedef struct slist *LInt; // apontador para struct slist(próxima "posicao")

typedef struct slist
{
  int valor;
  LInt prox;
} Nodo;

LInt list()
{
  LInt n1 = (LInt)malloc(sizeof(Nodo));
  n1->valor = 10;
  LInt n2 = (LInt)malloc(sizeof(Nodo));
  n2->valor = 5;
  n1->prox = n2;
  LInt n3 = (LInt)malloc(sizeof(Nodo));
  n3->valor = 15;
  n2->prox = n3;
  n3->prox = NULL;

  return n1;
}

int isEmpty(LInt l)
{
  return (l==NULL);
}

int head(LInt l)
{
  if(!isEmpty(l))
    return l->valor;
}

LInt tail(LInt l)
{
  if(!isEmpty(l))
  {
    LInt old = l;
    l = l->prox;
    free(old);
    return l;
  }
}

LInt cons(LInt l,int x)
{
  LInt h = (LInt)malloc(sizeof(Nodo));
  h->valor = x;
  h->prox = l;
  return l;
}

int length(LInt l)
{
  int i;
  for(i=0;l=NULL;i++)
    l = l->prox;
  return i;
}

void printlist(LInt l)
{
  printf("[");
  while(l!=NULL)
  {
    printf("%d", l->valor);
    l = l->prox;
  }
  printf("]\n");
}

int last(LInt l)
{
  if(!isEmpty(l))
  {
    while(l->prox != NULL)
      l = l->prox;
    return l->valor;
  }
}

LInt take(LInt l,int n)
{
  LInt h = l;
  while(n>1 && h != NULL)
  {h = h->prox; n--;}
  if(n==1)
    h->prox = NULL;
  return l;
}

void freeList(LInt l)
{
  while(l!=NULL)
  {
    LInt aux = l;
    l = l->prox;
    free(aux);
  }
}

LInt reverse(LInt l) //ineficiente
{
  LInt nl = NULL;
  while(l!=NULL)
    {nl = cons(nl,l->valor);
     l = l->prox;}
  freeList(l);
  return nl;
}

LInt reverseE(LInt l) //eficiente
{
  LInt ant, tpm;;
  if(isEmpty(l)) return l;
  ant = l;
  l = l->prox;
  ant->prox = NULL;
  while(l!=NULL)
  {
    tpm = l;
    l = l->prox;
    tpm->prox = ant;
    ant = tpm;
  }
  return ant;
}
/*
LInt addAll(LInt l, int a[], int n)
{

}*/

LInt isOrd(LInt l,int x)
{
  LInt ant,act;
  if(isEmpty(l) || x < l->valor)
    return cons(l,x);
  ant = l;
  act = l->prox;

  while(act != NULL && act->valor < x) {
    ant = act;
    act = act->prox;
  }
  ant->prox = cons(act,x);
  return l;
}

int main()
{
  LInt slist;
  int x;

  //printf("Empty? %s\n", isEmpty(slist) ? "true" : "false");
  printf("AD");
  list();
  printf("OLa");
  head(slist);
  printf("OLA");
  tail(slist);
  printf("ola");
  last(slist);
  printf("olA");
  scanf("%d",&x);
  cons(slist,x);
  printf("Adio");
  take(slist,x);
  return 0;
}
