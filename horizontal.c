#include <stdio.h>

void triangulo(int n) {
  int i,lines,nr=1;
  for(lines=1; lines<=n; lines++) {
    for(i=0;i<n-lines;i++)
      putchar(' ');
    for(nr=1;nr<2*lines;nr++)
      putchar('#');
  putchar('\n');
  }
}

int main2() {
  int n;
  scanf("%d", &n);
  triangulo(n);
  return 0;
}
