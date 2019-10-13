#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct abin {
  char *pal;
  int ocorr;
  struct abin *esq, *dir;
} *Dicionario;

void initDic (Dicionario *d)
{
  (*d)->pal = "";
  (*d)->ocorr = 0;
}

int acrescenta(Dicionario *d, char *pal)
{
  while(*d) {
    if(strcmp(pal,(*d)->pal) == 0) return ((*d)->ocorr)+1;
    else if(strcmp(pal,(*d)->pal) < 0) {
      acrescenta(&((*d)->esq),pal);
    }
    else {
      acrescenta(&((*d)->dir),pal);
    }
  }
  *d = malloc(sizeof(struct abin));
  (*d)->pal = pal;
  (*d)->ocorr = 1;
  return 1;
}

int main()
{
  Dicionario *d;
  char *pal = "lola";

  (*d)->pal = "tot";
  (*d)->ocorr = 1;
  (*d)->esq = NULL;
  (*d)->dir = NULL;

  acrescenta(d,pal);
  return 0;
}
