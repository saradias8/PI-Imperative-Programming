#include <stdio.h>
#include <malloc.h>

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

//28
int max(int e,int d)
{
  if(e>d) return e;
  else return d;
}

int altura(ABin arv)
{
  int e,d,m;

  if(!arv) return 0;

  e = altura(arv->esq);
  d = altura(arv->dir);
  m = max(e,d);
  return m+1;
}

//44
int addOrd(ABin *a,int x)
{
  if(*a) {
    if((*a)->valor==x) return 1;
    else if((*a)->valor < x) {
      a = &((*a)->dir);
      addOrd(a,x);
    }
    else {
      a = &((*a)->esq);
      addOrd(a,x);
    }
  }
  else {
    *a = malloc(sizeof(struct nodo));
    (*a)->valor = x;
    (*a)->esq = NULL;
    (*a)->dir = NULL;
    return 0;
  }
}
