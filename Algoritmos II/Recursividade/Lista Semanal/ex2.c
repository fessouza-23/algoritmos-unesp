#include <stdio.h>

int pares_rec(int n) {
  if (n == 1) {
    printf("%d ", 0);
    return 0;
  }
  int par = pares_rec(n - 1) + 2;
  printf("%d ", par);
  return par;
}

int main() {
  pares_rec(5);
  printf("\n");
  return 0;
}
