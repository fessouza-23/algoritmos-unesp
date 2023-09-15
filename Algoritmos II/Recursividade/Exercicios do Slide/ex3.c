#include <stdio.h>

int potencia(int x, int n) {
  if (n == 0)
    return 1;
  return x * potencia(x, n - 1);
}

int main() {
  printf("%d\n", potencia(5, 3));
  return 0;
}