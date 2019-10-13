#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct posicao {
  int x, y;
} Posicao;

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

LInt newLInt (int v, LInt t)
{
  LInt new = malloc(sizeof(LInt));
  if (new!=NULL) {
      new->valor = v;
      new->prox  = t;
  }
  return new;
}

void pint(LInt l)
{
  while(l) {
    printf("%d ",l->valor);
    l = l->prox;
  }
}

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

//PARTE A

//1
char *mystrstr(char s1[], char s2[])
{
  int pos=-1; int j=0;
  for(int i = 0; s1[i]; i++)
  {
    if(s1[i] == s2[j]) {
      if(j==0) pos = i;
      j++;
    }
    else j=0;
  }
  printf("%d\n",pos);
  if(pos != (-1)) return s2;
  else return NULL;
}

//2
void truncW(char t[], int n)
{
  int i=0, r=0, w=0;
  for(i=0;t[i];i++)
  {
    if(t[i] == ' ') {
      r = 0;
      t[w] = t[i];
      w++;
    }
    else if(r<n) {
      t[w] = t[i];
      r++;w++;
    }
  }
  t[w] = '\0';
  printf("%s\n",t);
}

//3
// int maisCentral(Posicao pos[], int N)
// {
//
// }

//4
LInt somasAcL(LInt l)
{
  LInt new = malloc(sizeof(LInt));
  int val=0;

  while(l != NULL)
  {
    new->valor = (l->valor) + val;
    val = new->valor;
    new = new->prox;
    l = l->prox;
  }
  new = NULL;
  return new;
}

//5
int addOrd(ABin *a, int x)
{
  while (*a)
  {
    if((*a)->valor == x) return 1;
    else if((*a)->valor < x) (*a) = (*a)->dir;
    else if((*a)->valor > x) (*a) = (*a)->esq;
    if((*a)->prox == NULL) break;
  }
  ABin new = malloc(sizeof(ABin));
  new->valor = x;
  new->prox = NULL;
  (*a)->prox = new;
  return 0;
}

//PARTE B

//1
int daPalavra(char *s, int *e)
{

}

int main()
{
  char frase[256] = "liberdade, igualdade e fraternidade";
  char aux[32] ="la";
  printf("%s\n",mystrstr(frase,aux));

  truncW(frase,4);

  LInt l = malloc(sizeof(LInt));
  LInt i = malloc(sizeof(LInt));
  LInt j = malloc(sizeof(LInt));
  l = newLInt(3,NULL); i = newLInt(2,l); j = newLInt(1,i);
  LInt x = somasAcL(j);
  pint(l);
  return 0;
}
