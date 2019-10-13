#include <stdio.h>

//1
float multInt1 (int n, float m) {
  float r=0,x;
  for(x=0;x<n;x++)
    r += m;
  return r;
}

//2
float multInt2 (int n, float m) {
  float soma=0;
  while (n > 0) {
    if (n%2 != 0) soma += m;
    n = n>>1; m *= 2; // n/=2;
  }
  return soma;
}

int main1() {
  int n;
  float m;
  scanf("%d %f", &n, &m);
  printf("%f\n", multInt2(n,m));
  return 0;
}

//3
int mdc1 (int a, int b) {
  int t=a,i,r=1;
  if (a>b) {a = b; b = t;}
  for (i=a;i>1 && r==1;i--)
  {
    if (a%i == 0)
      if (b%i == 0)
        r = i;
  }
  return r;
}

//4
int mdc2(int a, int b) {
  int r=0;
  while (a != 0 || b != 0) {
    if (a>b) {
      a -= b;
      r = b;
    }
    else { b -= a; r = a; }
  }
  return r;
}

int main2() {
  int a,b;
  scanf("%d %d", &a, &b);
  printf("%d\n", mdc2(a,b));
  return 0;
}

//6a
int fib1(int n) {
  if (n<2)
    return 1;
  else
    return fib(n-1) + fib(n-2);
}

//6b
int fib2(int n) {
  int a,b;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fib(n));
  return 0;
}
