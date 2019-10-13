#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PARTE A

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

//1
char *mystrcpy(char *dest, char source[])
{
  int i;
  dest = malloc(sizeof(char*));
  for(i=0; source[i]; i++)
  {
    dest[i] = source[i];
  }
  dest[i] = '\0';
  return dest;
}

//2
int isVowel(char s)
{
  s = toupper(s);
  if(s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') return 0;
  return 1;
}

void strnoV(char s[])
{
  int i,j=0;
  char* new = malloc(sizeof(char*));

  for(i=0; s[i]; i++)
  {
    if(isVowel(s[i]) == 1)
    {
      new[j] = s[i];
      j++;
    }
  }
  new[i] = '\0';
  strcpy(s,new);
}

ABin newABin (int no, ABin e, ABin d)
{
	ABin new = malloc (sizeof (struct nodo));

	if (new!=NULL){
    new->valor = no;
		new->esq  = e;
		new->dir  = d;
	}
	return new;
}

void pint(ABin a)
{
  if(!a) return ;
  printf("%d\n",a->valor);
  pint(a->esq);
  pint(a->dir);
}

//3
int dumpAbin(ABin a, int v[], int N)
{
  int i; int r=0;
  ABin aux = a;

  for(i=0; i<N; i++)
  {
    if(!a) break;
    if(a->esq == NULL) { v[i] = a->valor; r++; a = a->dir; }
    else a = a->esq;
  }
  return r;
}

//4
int lookupAB(ABin a, int x)
{/*
  if(!a) return 1;
  if(x < a->valor) lookupAB(a->esq,x);
  else if(x > a->valor) lookupAB(a->dir,x);
  else return 0;*/

  while(a != NULL)
  {
    if(x < a->valor) a = a->esq;
    else if(x > a->valor) a = a->dir;
    else return 0;
  }
  return 1;
}

//PARTE B

typedef struct listaP {
  char *pal;
  int cont;
  struct listaP *prox;
} Nodo, *Hist;

//1
int inc(Hist *h, char *pal)
{
  while(*h)
  {
    if(strcmp((*h)->pal,pal)==0) {
      ++((*h)->cont);
      return (*h)->cont;
    }
    else if(strcmp((*h)->pal,pal)>0) {
      Hist new = malloc(sizeof(struct listaP));
      Hist aux = malloc(sizeof(struct listaP));
      aux = (*h)->prox;
      strcpy(new->pal, pal);
      new->cont = 1;
      new->prox = aux;
      (*h) = new;
    }
    (*h) = (*h)->prox;
  }
  return ;
}

//2
//

//3


int main()
{
  /*
  char *f;
  f = mystrcpy(f,"abcda");
  for(int i=0;f[i];i++) printf("%c ",f[i]);
  printf("\n");

  strnoV(f);
  for(int i=0;f[i];i++) printf("%c ",f[i]);
  printf("\n");
  */
  ABin a = malloc(sizeof(ABin));
  a = newABin(3,NULL,NULL); a = newABin(5,a,NULL); a = newABin(2,NULL,a);
  pint(a);
  int b = lookupAB(a,5);
  int *v;
  int c = dumpAbin(a,v,3);
  printf("%d\n",c);

  return 0;
}
