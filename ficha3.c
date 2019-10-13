#include <stdio.h>
#include <math.h>

void swapM(int *x, int *y) {
  int t=*y;
  *y = *x;
  *x = t;
}

int main1() {
  int x=3,y=5;
  swapM(&x,&y);
  printf("%d %d\n", x, y);
  return 0;
}

void swap(int v[], int i, int j) {
  int t = v[i];
  v[i] = v[j];
  v[j] = t;
}

int main2() {
  int v[] = {1,2,3,4,5,6};
  swap(v,2,0);
  printf("%d\n", *v);
  return 0;
}

int soma(int v[], int N) {
  int sum=0,i;
  for(i=0;i<N;i++)
    sum += v[i];
  return sum;
}

int main3() {
  int sum;
  int v[] = {1,2,3,4};
  sum = soma(v,4);
  printf("%d\n", sum);
  return 0;
}

int maximum(int v[], int N, int *m) {
  int max=v[0];
  if(N<=0) return 1;
  for(int i=1; i<N; i++)
    if (v[i] > *m)
      *m = v[i];
  *m=max;
  return 0;
}

int main4() {
  int v[] = {1,2,4,1};
  int m=v[0],max;
  if(maximum(v,4,&m)==0) printf("%d\n", max);
  return 0;
}

void quadrados(int q[], int N) {
  for(int i=0;i<N;i++)
    for(int x=1;x<=N;x++) {
      q[i] = x*x;
      printf("%d\n", q[i]);
    }
}

int main5() {
  int q[10];
  quadrados(q,5);
  return 0;
}

void pascal(int v[], int N) {
  v[0] = 1;
  for(int i=1;i<(N/2);i++) {
    v[i] = N - v[i-1];
    printf("%d ", v[i]);
  }
}

int main() {
  int s;
  int v[5];
  scanf("%d", &s);
  pascal(v,s);
  return 0;
}
