#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mystrcat(char s1[], char s2[])
{
  int i,j,x,y;
  for(x=0;s1[x];x++) ; //x tem a length de s1
  for(y=0;s2[y];y++) ; //y tem a length de s2

  for(i=x; i<y; i++) {
    s1[i] = s2[j++];
  }
  s1[i] = '\0';
  return (s1);
}

int main() {
  char s1[20] = "ola ";
  char s2[20] = "adeus";
  *s1 = mystrcat(s1,s2);
  for(int i=0;s1[i];i++) printf("%c",s1[i]);
  printf("\n");
  return 0;
}
