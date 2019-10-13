#include <stdio.h>

int main1() {
  int x, y;
  x = 3;
  y = 5;
  if (x>y)
    y = 6;
  printf("%d %d\n", x, y);

  int a, b;
  a = b = 0;
  while (a != 11) {
    a = a+1;
    b += a;
  }
  printf("%d %d\n", a, b);

  int i;
  for (i=0; (i<20); i++) // i initiates with 0, and adds 1 for each round, while <20
    if (i%2 == 0)
      putchar('_');
    else
      putchar('#');

  char j, h;
  for (j='a'; j!='h'; j++) {
    for (h=j; h!='h'; h++)
      putchar(h);
    putchar('\n');
  }

  return 0;
}

void f (int n) {
  while (n>0) {
    if (n%2 == 0)
      putchar('0');
    else putchar('1');
    n = n/2;
  }
  putchar('\n');
}

int main() {
  int w;
  for (w=0; w<16; w++)
    f(w);
  return 0;
}
