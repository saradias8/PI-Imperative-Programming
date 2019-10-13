#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} *LInt;

// 1
int length (LInt l)
{
  int len = 0;

  while(l) {
    len++;
    l = l->prox;
  }
  return len;
}

// 2
// ?
void freeL (LInt l)
{
  free(l);
}

// 3
// why not?
void imprimeL (LInt l)
{
  int c;
  while (l) {
    c = l->valor;
    printf("%d\n",c);
    l = l->prox;
  }
}
/*
int main()
{
  LInt l;

  l->valor = 1;
  l->prox = NULL;

  imprimeL(l);

  return 0;
}
*/

// 4
// why not?
LInt reverseL (LInt l){
    int i;
    int array[100];

    while(l) {
        for(i=0;i<length(l);i++) {
            array[i] = l->valor;
            l = l->prox;
        }
    }
    i = length(l)-1;
    while(l) {
        l->valor = array[i--];
        l = l->prox;
    }
    return l;
}

// 5
// why not?
void insertOrd (LInt *l, int x)
{
    if(*l) {
        if((*l)->valor > x) insertOrd(&((*l)->prox),x);
        else {
            l = malloc(sizeof(struct lligada));
            while(*l) (*l)->prox = (*l)->valor;
            (*l)->valor = x;
        }
    }
    else {
    l = malloc(sizeof(struct lligada));
    (*l)->valor = x;
    }
}

// 6
// why?
int removeOneOrd (LInt *l, int x){
    while(*l) {
        if((*l)->valor == x) { (*l)->valor = (*l)->prox; return 0;}
        else removeOneOrd(&((*l)->prox),x);
    }
    return 1;
}


// 25
void remreps (LInt l){
    LInt aux;
    if (l==NULL) return ;
    while(l->prox){
        if (l->valor == l->prox->valor) {
            aux = l->prox;
            l->prox = aux->prox;
            free(aux);
        }
        else l = l->prox;
    }
}

// 26

LInt rotateL (LInt l)
{
  LInt x;
  LInt *r;

  if (!l || !(l->prox)) return l;
  r = &l;
  x = l;
  l = l->prox;
  x->prox = NULL;
  while((*r)->prox) r = &((*r)->prox);
  (*r)->prox = x;
  
  return l;
}
