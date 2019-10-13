#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrada {
  char *palavra;
  int ocorr;
  struct entrada *prox;
} *Palavra;

typedef Palavra Dicionario;

Dicionario cons(Dicionario d,char*p)
{
  Palavra ne = (Palavra) malloc(sizeof(struct entrada));
  ne->palavra = strdup(p);
  ne->ocorr = 1;
  ne->prox = d;
  return ne;
}

int acrescenta(Dicionario *d,char*p)
{
  Dicionario ant,act;
  if(*d == NULL || strcmp(p,(*d)->palavra)<0)
  {
    *d = cons(*d,p);
    return 1;
  }
  ant = *d;
  act = (*d)->prox;
  while(act!=NULL && strcmp(act->palavra,p)<0) {
    ant = act;
    act = act->prox;
  }
  if(act!=NULL && strcmp(p,act->palavra) == 0) {
    act->ocorr ++;
    return (act->ocorr);
  }
  if(strcmp(ant->palavra,p)==0){
    ant->ocorr++;
    return ant->ocorr;
  }
  ant->prox = cons(act,p);
  return 1;
}

char* maisFreq(Dicionario d, int *o)
{
  int r=-1;
  char*rp;
  while(d!=NULL)
  {
    if(d->ocorr >r){
      r = d->ocorr;
      rp = d->palavra;
    }
    d = d->prox;
  }
  *o = r;
  return rp;
}

int main()
{
  Dicionario d;
  acrescenta(&d,"Ana");
  acrescenta(&d,"To");
  acrescenta(&d,"Ana");
  maisFreq(d,[1,2,3]);

  return 0;
}
/*
int main(int argc, char *argv[])
{
  FILE *input;
  int r=0, count=0;
  char word[100];
  if(argc==1) input = stdin;
  else input=fopen(argv[1], "r");
  if(input==NULL) r=1;
  else {
    while(fscanf(input,"%s",word)==1)
      count++;
    fclose(input);
    printf("%d palavras\n", count);
  }
  return r;
}
*/
