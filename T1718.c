#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;

LInt newNode(int x, LInt prox)
{
  LInt l = malloc(sizeof(LInt));
  if(l) {
    l->valor = x;
    l->prox = prox;
  }
  return l;
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

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}
//PARTE A

//1
int retiraNeg(int v[], int N)
{
  int i, j=0, n=0;
  int new[N];

  for(i=0; i<N; i++)
  {
    if(v[i] >= 0) {
      new[j++] = v[i];
      n++;
    }

  }
  new[j] = '\0';
  return n;
}

//2
int difConsecutivos(char s[]) //nao funciona ???
{
  char ant = ' ';
  int count=0, i, maior=0;
  for(i=0; s[i]; i++)
  {
    if(s[i]!=ant) {
      ant=s[i];
      count++;
      if(count > maior) maior = count;
    }
    else {count = 0; ant=s[i];}
  }
  return maior;
}

//3
int maximo(LInt l)
{
  int max = 0;
  while(l) {
    printf("%d\n",l->valor);
    if(l->valor > max) max = l->valor;
    l = l->prox;
  }
  return max;
}

//4
int removeAll(LInt *l, int x) //wrong
{
  int nr=0;

  while((*l)!=NULL)
  {
    if((*l)->valor == x)
    {
      LInt *aux = l; //aponta para l acho eu
      (*l) = (*l)->prox;
      free(*aux); //liberta celula
      nr++;
    }
    (*l) = (*l)->prox;
  }
  return nr;
}

//5
LInt arrayToList(int v[], int N)
{
  LInt l;

  for(int i = 0; i < N; i++)
  {
    l = malloc(sizeof(LInt));
    l->valor = v[i];
    l = l->prox;
  }
  return l;
}

//PARTE B

//1
int minheapOK(ABin a) //mal ???
{
  if(!a) return 1;
  else if(a->esq == NULL && a->dir == NULL) return 1;
  return (((a->valor) < minheapOK(a->esq)) && ((a->valor) < minheapOK(a->dir)));
}

//2
int max(int a, int b)
{
  if(a>b) return a;
  else return b;
}

int maxHeap(ABin a)
{
  if(a->esq == NULL && a->dir == NULL) return a->valor;
  else if(a->esq == NULL) return maxHeap(a->dir);
  else if(a->dir == NULL) return maxHeap(a->esq);
  else return (max(maxHeap(a->esq),maxHeap(a->dir)));
}

//3
void removeMin(ABin *a) //nao faço ideia
{
  // remover raiz
  // ver o menor(esq ou dir)
  // por o menor na raiz
  // apontar nova raiz para outro nodo
}

//4
void heapSort(int v[], int N) //nao sei
{

}

//5
int kmaior(int v[], int N, int k) //nao sei
{

}

int main()
{
  //1a
  int v[20] = {1,-1,2,-2,3,-3,4,-4,5,-5,10,11,-1};
  int a = retiraNeg(v,13);
  printf("elementos não retirados: %d\n",a);
  //2a
  char s[20] = "aabcccaac";
  int b = difConsecutivos(s);
  printf("comprimento maior: %d\n",b);
  //3a
  LInt l = malloc(sizeof(LInt)); LInt x = malloc(sizeof(LInt));
  l = newNode(10,NULL); x = newNode(5,l);
  int c = maximo(x);
  printf("elemento maior: %d\n",c);
  //4a
  // int d = removeAll(&x,10);
  // printf("celulas removidas: %d\n",d);
  //5a
  // LInt e = arrayToList(v,10);
  // pint(e);
  //1b
  ABin f = malloc(sizeof(ABin));
  ABin g = malloc(sizeof(ABin));
  ABin h = malloc(sizeof(ABin));
  f = newABin(800,NULL,NULL); g = newABin(93,NULL,NULL); h = (35,f,g);
  // h = newABin(19,NULL,NULL); g = newABin(25,NULL,NULL); h = (22,h,g);
  // g = newABin(20,f,h);
  int i = minheapOK(h);
  printf("é meanheap? %d\n",i);
  //2b
  int j = maxHeap(f);
  printf("maior el: %d\n",j);

  return 0;
}
