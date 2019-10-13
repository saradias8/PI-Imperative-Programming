#include <stdio.h>

void triangulo(int n) {
  int count=0, nr=1, num=1;
  while (count < n) {
    while (nr != 0) {
      putchar('#');
      nr-=1;
    }
    putchar('\n');
    num++; nr = num;
    count++;
  }
  if (num > n) {
    nr = num = n-1;
    while (count > 0) {
      while (nr != 0) {
        putchar('#');
        nr--;
      }
      putchar('\n');
      num--; nr = num;
      count--;
    }
  }
}

/*
void triangulo(int n) {
  int i = 1, j;
  while(i<n) {
    for(j=i;j>0;j--) printf("#");
    i++;
    printf("\n");
  }
  while(i>0) {
    for(j=i;j>0;j--) printf("#");
    i--;
    printf("\n");
  }
}
*/

int main1() {
  int dim;
  scanf("%d", &dim);
  triangulo(dim);
  return 0;
}
