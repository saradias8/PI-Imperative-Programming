#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PARTE A

typedef struct slist{
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

void printa(LInt l)
{
  while(l != NULL)
  {
    printf(".%d\n",l->valor);
    l = l->prox;
  }
}

//1
int bitsUm(unsigned int n)
{
  int nr=0;
  while (n != 0)
  {
    if(n%2==1) nr++;
    n /= 2;
  }
  return nr;
}

//2
int limpaEspacos(char t[])
{
  int i, j=0, h=-1;
  char* final = malloc(sizeof(char*));
  char* iter = malloc(sizeof(char*));
  iter = t;

  for(i=0; t[i]; i++)
  {
    if(t[i] == ' ')
    {
      if(iter[h] == ' ') { h++; }
      else
      {
        final[j] = t[i];
        j++; h++;
      }
    }
    else
    {
      final[j] = t[i];
      j++; h++;
    }
  }
  return j;
}

//3
int dumpL(LInt l, int v[], int N)
{
  int num = 0;
  int i = 0;

  while(l != NULL && i<N)
  {
    v[i] = l->valor;
    l = l->prox;
    i++; num++;
  }
  return num;
}

//4
LInt parte (LInt l)
{
	int i;
	LInt r = NULL, *auxl, *auxr;
	auxl = &l;
	auxr = &r;

	if (!l) return r;

	for(i=0;*auxl;i++)
  {
		if (i % 2 == 0) {
			auxl = &((*auxl)->prox);
		}
		else
    {
			(*auxr) = malloc(sizeof(LInt));
			(*auxr)->valor = (*auxl)->valor;
			(*auxr)->prox = NULL;
			auxr = &((*auxr)->prox);
			(*auxl) = (*auxl)->prox;
		}
	}
	return r;
}

int main1()
{
  int a = limpaEspacos("a       b     c");
  printf("length string: %d\n",a);

  LInt list = malloc(sizeof(LInt)); int v[100];
  list = newLInt(1,NULL); list = newLInt(2,list); list = newLInt(3,list); list = newLInt(4,list);
  list = newLInt(5,list); list = newLInt(6,list); list = newLInt(7,list); list = newLInt(8,list);
  list = newLInt(9,list); list = newLInt(10,list); list = newLInt(11,list);
  int b = dumpL(list,v,11);
  printf("elementos preenchidos: %d\n",b);

  LInt y = parte(list);
  printa(y);
  printf("\n\n");
  printa(list);
  return 0;
}

//PARTE B

typedef struct nodo {
  char nome[50];
  int numero;
  int nota;
  struct nodo *esq, *dir;
} *Alunos;

typedef struct strlist {
  char *string;
  struct strlist *prox;
} *StrList;

Alunos newABin (char r[50], int n, int no, Alunos e, Alunos d)
{
	Alunos new = malloc (sizeof (struct nodo));

	if (new!=NULL){
		//new->nome = r;
    new->numero = n;
    new->nota = no;
		new->esq  = e;
		new->dir  = d;
	}
	return new;
}

//1
int fnotas(Alunos a, int notas[21])
{
  int nr = 0,e,d, i = 0;
  if(a->nota == i && i>=0 && i<=20)
  {
      e = fnotas(a->esq,notas);
      d = fnotas(a->dir,notas);
  }
  notas[i] = 1 + e + d;
  nr++;

  return nr;
}

//2
/*
int rankNota(int nota, int fnotas[21])
{

}

int rankAluno(ALunos a, int numero, int fnotas[21])
{

}
*/
void pint(ABin a)
{
  printf("%d\n",a->numero);
  pint(a->esq);
  pint(a->dir);
}

//3
int main()
{
  printf("Ola\n");
  Alunos a = malloc(sizeof(Alunos));
  a = newABin("tres",3,10,NULL,NULL); a = newABin("dois",2,10,a,NULL); a = newABin("um",1,12,NULL,a);
  int notas[21];
  pint(a);
  printf("adeus\n");
  int b = fnotas(a,notas);
  return 0;
}
