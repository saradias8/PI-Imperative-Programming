#include <stdio.h>

void add(int n) {
  int dim, lines;
  for (lines = 0; lines <n; lines++) {
    for(dim=0; dim<n; dim++)
      putchar('#');
    putchar('\n');
  }
}

int main() {
  int n;
  scanf("%d", &n);
  add(n);
  return 0;
}
