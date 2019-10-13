#include <stdio.h>

void tabuleiro(int n) {
  int count=0, lines=0;
  while (lines<n) {
    if (count%2 == 0) {
      putchar('#');
      count++; }
    else {
      putchar('_');
      count++; }
    if (count%n == 0) {
      putchar('\n');
      lines++; }
  }
}

int main() {
  int dim;
  scanf("%d", &dim);
  tabuleiro(dim);
  return 0;
}

/*
void xad(int n) {
  int dim, lines;
  for (lines=0; lines<n; lines++) {
    for (dim=0; dim<n; dim++) {
      if (dim%2 == 0) putchar('#');
      else putchar('_');
    }
  putchar('\n');
  }
}

int main() {
  int n;
  scanf("%d", &n);
  xad(n);
  return 0;
}
*/
