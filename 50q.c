#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// EX 1
int maior(int array[], int size) {
  int max=array[0];

  for(int i=1;i<size;i++)
    if(array[i] > max) max = array[i];

  return max;
}

//EX 2
int sum(int array[], int size) {
  int soma=0;
  for(int i=0;i<size;i++)
    soma += array[i];
  return soma;
}

float media(int sum, int size) {
  return sum/(float) size;
}

//EX 3
int maior2(int array[], int size) {
  int i,maior1=array[0],maior2=array[0];

  for(i=0;i<size;i++)
    if(array[i]>maior1) {maior2 = maior1; maior1=array[i];}
    else if(array[i]>maior2) maior2 = array[i];

  return maior2;
}

//EX 4
//EX 5
//EX 6
//EX 7
char *mystrcat(char s1[], char s2[])
{
    int a = strlen(s1);
    int i,j=a;

    for(i=0;s2[i];j++,i++)
        s1[j] = s2[i];

    s1[j] = '\0';

    return s1;
}

//EX 8
char *mystrcpy(char s1[], const char s2[])
{
    int i;

    for(i=0;s2[i];i++)
        s1[i] = s2[i];

    s1[i] = '\0';

    return s1;
}

//EX 9
int mystrcmp(char s1[], char s2[])
{
    int i;

    for(i=0;s1[i] || s2[i];i++) {
        if(s1[i]<s2[i]) return -1;
        else if(s1[i]>s2[i]) return 1;
    }

    return 0;
}

//EX 10
//why?
char *mystrstr (char s1[], char s2[])
{
    int i,j=0; int len = strlen(s2); int count = 0; int pos=-1;

    for(i=0;s1[i];i++)
        if(s1[i] == s2[j]) {
            count++; j++;
            if(pos==-1) pos = i;
        }
        else if(count != len) {count = 0; pos=-1;}
        else break;

    if(count == len) return &s1[pos];

    return NULL;
}

//EX 11
void strrev (char s[]) {
    int i,j=0;
    int len = strlen(s);
    char new[len];

    i = len-1;

    while(i>=0) {
        new[j] = s[i];
        i--;j++;
    }

    new[j] = '\0';
}

//EX 12
int isVowel(char c)
{
    int i;
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

void strnoV (char t[])
{
  int i,x;

  for(i=0;t[i];i++)
    if(isVowel(t[i]) == 1) {
      x = i;
      while(t[x]) {
        t[x] = t[x+1];
        x++; }
    }
}


//EX 47
typedef enum movimento {Norte,Sul,Este,Oeste} Movimento;
typedef struct posicao {
  int x,y;
} Posicao;
