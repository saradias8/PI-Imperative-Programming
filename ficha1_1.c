#include <stdio.h>

int main() {
  int x, y;
  x = 3;
  y = x+1;   // y = 4
  x = x*y;   // x = 3*4 = 12
  y = x+y;   // y = 12+4 = 16
  printf("%d %d\n", x, y);
  // output: "12 16"
  int aa, bb;
  aa = 0;
  printf("%d %d\n", aa, bb);
  // output: variable without value // output: "0 0" (0 predefined for integers)
  char a, b, c;
  a = 'A'; b = ' '; c = '0';
  printf("%c %d\n", a, a); // %c para caracter  %d para decimal
  a = a+1; c = c+2;  // a = 'B', c = '2'
  printf("%c %d %c %d\n", a, a, c, c);
  c = a+b; // c =
  printf("%c %d\n", c, c);
  // output: "A 65" "B 66 2 50" "97 0"
  int d, e;
  d = 200; e = 100;
  d = d+e; e = d-e; d = d-e;  // x = 300, y = 200, x = 100
  printf("%d %d\n", d, e);
  // output: "100 200"
  int f, g;
  f = 100; g = 28;
  f += g; g -= f;  // x = 128, y = -100
  printf("%d %d\n", f++, ++g);
  printf("%d %d\n", f, g);
  // output: "128 -99" "129 -99"
  return 0;
}
