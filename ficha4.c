#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tolower(int argument);
//int isspace(int argument);

int minusculas(char s[]) {
  int qtd=0,i;

  for(i=0;s[i]!='\0';i++)
    if(s[i]>='A' && s[i]<='Z') {
      tolower(s[i]);
      qtd++; }

  return qtd;
}

int main1() {
  char s[7]="ABCdefG";
  printf("%d\n",minusculas(s));
  return 0;
}

int contalinhas(char s[]) {
  int linhas=0,i;

  for(i=0;s[i]!='\0';i++)
    if(s[i]=='\n') linhas++;

  return linhas;
}

int main2() {
  char s[10]="ABC\ndef\nG\n";
  printf("%d\n",contalinhas(s));
  return 0;
}

int contaPal(char s[]) {
  int pal=0,i;

  for(i=1;s[i]!='\0';i++)
    if(isspace(s[i])!=isspace(s[i+1])) pal++;

  return pal/2 +1;
}

int main3() {
  char s[100]="ab  ac def ";
  printf("%d\n",contaPal(s));
  return 0;
}

int procura(char *p, char *ps[], int N) {
  int found=0,i;

  for(i=0;i<N && found==0;i++)
    if(strcmp(p,ps[i])==0) found=1;

  return found;
}

int main() {
  char *ps[] = {"esd","abc","wqa"};
  printf("%d\n",procura("abc",*ps,3));
  return 0;
}
